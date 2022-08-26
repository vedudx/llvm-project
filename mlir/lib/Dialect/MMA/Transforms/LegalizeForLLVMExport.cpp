#include "mlir/Dialect/MMA/Transforms.h"

#include "mlir/Conversion/LLVMCommon/ConversionTarget.h"
#include "mlir/Conversion/LLVMCommon/Pattern.h"
//#include "mlir/Dialect/MMA/MMADialect.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/PatternMatch.h"

using namespace mlir;
using namespace mlir::mma;

namespace {
/// Maps the 2-dim vector shape to the two 16-bit tile sizes. The first
/// dimension directly translates into the number of rows of the tiles.
/// The second dimensions needs to be scaled by the number of bytes.
// copied from amx dialect
std::pair<Value, Value> getTileSizes(ConversionPatternRewriter &rewriter,
                                     LLVMTypeConverter &typeConverter,
                                     VectorType vType, Location loc) {
  Type llvmInt16Type = IntegerType::get(&typeConverter.getContext(), 16);
  unsigned width = vType.getElementType().getIntOrFloatBitWidth();
  assert(llvm::isPowerOf2_64(width) && width >= 8);
  unsigned bytes = width >> 3;
  auto mattr = rewriter.getI16IntegerAttr(vType.getDimSize(0));
  auto nattr = rewriter.getI16IntegerAttr(vType.getDimSize(1) * bytes);
  return std::make_pair(
      rewriter.create<LLVM::ConstantOp>(loc, llvmInt16Type, mattr),
      rewriter.create<LLVM::ConstantOp>(loc, llvmInt16Type, nattr));
}

/// Verifies if the stride matches proper tile access.
// these functions copied from amx dialect
LogicalResult verifyStride(MemRefType mType) {
  if (mType.getRank() < 2)
    return failure();
  int64_t last = mType.getRank() - 1;
  int64_t offset;
  SmallVector<int64_t, 4> strides;
  if (failed(getStridesAndOffset(mType, strides, offset)) || strides[last] != 1)
    return failure();
  return success();
}

/// Maps the 2-dim memref shape to the 64-bit stride. Note that the buffer
/// shape may "envelop" the actual tile shape, and may be dynamically sized.
// copied from amx dialect. Will be removed or modified later
Value getStride(ConversionPatternRewriter &rewriter,
                LLVMTypeConverter &typeConverter, MemRefType mType, Value base,
                Location loc) {
  assert(mType.getRank() >= 2);
  int64_t last = mType.getRank() - 1;
  Type llvmInt64Type = IntegerType::get(&typeConverter.getContext(), 64);
  unsigned width = mType.getElementType().getIntOrFloatBitWidth();
  assert(llvm::isPowerOf2_64(width) && width >= 8);
  unsigned bytes = width >> 3;
  if (mType.isDynamicDim(last)) {
    // Dynamic size needs code to compute the stride at runtime.
    MemRefDescriptor memrefDescriptor(base);
    auto attr = rewriter.getI64IntegerAttr(bytes);
    Value scale = rewriter.create<LLVM::ConstantOp>(loc, llvmInt64Type, attr);
    return rewriter.create<LLVM::MulOp>(
        loc, llvmInt64Type, scale, memrefDescriptor.size(rewriter, loc, last));
  }
  // Use direct constant for static size.
  auto attr = rewriter.getI64IntegerAttr(mType.getDimSize(last) * bytes);
  return rewriter.create<LLVM::ConstantOp>(loc, llvmInt64Type, attr);
}

/// Cast any pointer to the !llvm.ptr<i8> pointer type.
Value castPtr(ConversionPatternRewriter &rewriter, Location loc, Value ptr) {
  auto i8Ptr =
      LLVM::LLVMPointerType::get(IntegerType::get(ptr.getContext(), 8));
  return rewriter.create<LLVM::BitcastOp>(loc, i8Ptr, ptr);
}

struct outerFConversion : public ConvertOpToLLVMPattern<outerProductFOp> {
  using ConvertOpToLLVMPattern<outerProductFOp>::ConvertOpToLLVMPattern;
  LogicalResult
  matchAndRewrite(outerProductFOp op, OpAdaptor adaptor,
                  ConversionPatternRewriter &rewriter) const override {
    VectorType aType = op.getLhsVectorType();
    VectorType bType = op.getRhsVectorType();
    VectorType cType = op.getVectorType();
    // Determine m x n x k tile sizes.
    std::pair<Value, Value> tsza =
        getTileSizes(rewriter, *getTypeConverter(), aType, op.getLoc());
    std::pair<Value, Value> tszb =
        getTileSizes(rewriter, *getTypeConverter(), bType, op.getLoc());
    // Replace operation with intrinsic.
    Type resType = typeConverter->convertType(cType);
    rewriter.replaceOpWithNewOp<mma::ppc_mma_xvf32ger>(
        op, resType, tsza.first, tszb.second, tsza.second, adaptor.getAcc(),
        adaptor.getLhs(), adaptor.getRhs());
    return success();
  }
};


