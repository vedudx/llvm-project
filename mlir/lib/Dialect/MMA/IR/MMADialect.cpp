#include "mlir/Dialect/MMA/MMADialect.h"
#include "mlir/Dialect/LLVMIR/LLVMTypes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/TypeUtilities.h"

using namespace mlir;

#include "mlir/Dialect/MMA/MMADialect.cpp.inc"

void mma::MMADialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "mlir/Dialect/MMA/MMA.cpp.inc"
      >();
}

/// Verify that MMA supports the implied tile shape for .
static LogicalResult verifyTileSize(Operation *op, VectorType tp, int maxRows, int KbitsPR) {
  const unsigned kMaxRows = maxRows;
  const unsigned kBitsPerRow = KbitsPR;
  unsigned col = tp.getDimSize(1) * tp.getElementType().getIntOrFloatBitWidth();
  if (tp.getDimSize(0) > kMaxRows)
    return op->emitOpError("bad row height: ") << tp.getDimSize(0);
  if (col > kBitsPerRow)  //col & 0x1f
    return op->emitOpError("bad column width: ") << (col >> 3);
  return success();
}


/// Verify that MMA supports the outerProduct.
static LogicalResult verifyOuterShape(Operation *op, VectorType atp,
                                     VectorType btp, VectorType ctp,
                                     unsigned scale) {
  unsigned am = atp.getDimSize(0), ak = atp.getDimSize(1) >> scale;
  unsigned bk = btp.getDimSize(0), bn = btp.getDimSize(1) >> scale;
  unsigned cm = ctp.getDimSize(0), cn = ctp.getDimSize(1);
  if (cm != am || cn != bk || ak != bn)
    return op->emitOpError("bad outerProduct shape: ")
           << cm << " x " << cn << " x " << ak;
  return success();
}


LogicalResult mma::LoadOp::verify() {
  unsigned rank = getMemRefType().getRank();
  if (getIndices().size() != rank)
    return emitOpError("requires ") << rank << " indices";
  return verifyTileSize(*this, getVectorType(), 4, 128);
}


LogicalResult mma::outerProductFOp::verify() {
  VectorType aType = getLhsVectorType();
  VectorType bType = getRhsVectorType();
  VectorType cType = getVectorType();
  if (failed(verifyTileSize(*this, aType, 1, 32*4)) && failed(verifyTileSize(*this, aType, 4, 16*2)) ||
      failed(verifyTileSize(*this, bType, 1, 32*4)) && failed(verifyTileSize(*this, aType, 4, 16*2))||
      failed(verifyTileSize(*this, cType, 4, 32*4)) ||
      failed(verifyOuterShape(*this, aType, bType, cType, 1)))
    return failure();
  Type ta = aType.getElementType();
  Type tb = bType.getElementType();
  Type tc = cType.getElementType();
  if ((!(ta.isBF16() && tb.isBF16()) && !(ta.isF16() && tb.isF16())) || !tc.isF32())
  //ta and tb both are BF16 OR ta and tb both are F16
  //tc is F32
    return emitOpError("unsupported type combination");
  return success();
}


LogicalResult mma::outerProductIOp::verify() {
  VectorType aType = getLhsVectorType();
  VectorType bType = getRhsVectorType();
  VectorType cType = getVectorType();
  if (failed(verifyTileSize(*this, aType, 4, 16*2)) &&  failed(verifyTileSize(*this, aType, 4, 8*4))||
      failed(verifyTileSize(*this, bType, 4, 16*2)) && failed(verifyTileSize(*this, aType, 4, 8*4)) ||
      failed(verifyTileSize(*this, cType, 4, 32*4)) ||
      failed(verifyOuterShape(*this, aType, bType, cType, 1)))
    return failure();
  Type ta = aType.getElementType();
  Type tb = bType.getElementType();
  Type tc = cType.getElementType();
  if ((!(ta.isInteger(16) && tb.isInteger(16)) || !tc.isF32())) 
  //&& !(ta.isI8() && tb.isI8())) 
  //ta and tb both are I16 
  //have to add support for UI8
  //tc is I32
    return emitOpError("unsupported type combination");
  return success();
}



#define GET_OP_CLASSES
#include "mlir/Dialect/MMA/MMA.cpp.inc"


