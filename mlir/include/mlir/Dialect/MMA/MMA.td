//===-- MMA.td - MMA dialect operation definitions *- tablegen -*----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the basic operations for the MMA dialect.
//===----------------------------------------------------------------------===//



#ifndef MMA_DIALECT
#define MMA_DIALECT



include "mlir/Dialect/LLVMIR/LLVMOpBase.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
   

// Dialect definition.
def MMA_Dialect : Dialect {
    let name = "mma";
    let cppNamespace = "::mlir::mma";
    let summary = "Meant as a dialect for ibm Power 10 MMA unit";
    let description = [{
    This dialect serves as dialect to bridge vector and memref to mma supported size and to leverage the performance of MMA unit  }];
 }

 // Base class for MMA dialect ops that do not correspond to library calls.
class MMA_Op<string mnemonic, list<Trait> traits = []> :
    Op<MMA_Dialect, mnemonic, traits>;



// The "internal" intrinsics are meant for compiler usage.

class MMA_IntrOp<string mnemonic, int numResults, list<Trait> traits = []> :
  LLVM_IntrOpBase<MMA_Dialect, mnemonic,
                   !subst(".", "_", mnemonic),
                  [], [], traits, numResults>;   //To remove int_ from mnemonic



def LoadOp: MMA_Op<"load"> {
    let summary = "This operation load the valid value into MMA accumulators";
    let description = [{
        LoadOp

          Example:

    ```mlir
      %0 = mma.load %arg0[%c0, %c0] : memref<?x?xf16> into vector<4x4xf32>
    ```
    }];
    //check vector arguments and replace the below code to adjust that
    let arguments = (ins Arg<AnyMemRef, "load base", [MemRead]>:$base,
                   Variadic<Index>:$indices);
    let results = (outs VectorOfRankAndType<[2], [I32, I8]>:$res);

    let extraClassDeclaration = [{
    MemRefType getMemRefType() {
      return base().getType().cast<MemRefType>();
    }
    VectorType getVectorType() {
      return res().getType().cast<VectorType>();
    }
  }];
 let assemblyFormat = "$base `[` $indices `]` attr-dict `:` "
                       "type($base) `into` type($res)";

  let hasVerifier=1;
}


def outerProductFOp: MMA_Op<"outerF", [NoSideEffect, AllTypesMatch<["acc", "res"]>]>  {
  let summary = "this operation performs the outer product of two registers and stores a result back in to the result register";

  let description = [{
      outerProduct

      Example:
         ```mlir
      %0 = mma.outerF %a, %b, %c
        : vector<4x2xbf16>, vector<4x2xbf16>, vector<4x4xf32>
    ```

  }];

      let arguments = (ins VectorOfRankAndType<[2], [F16, BF16]>:$lhs,
                       VectorOfRankAndType<[2], [F16, BF16]>:$rhs,
                       VectorOfRankAndType<[2], [F32]>:$acc);

  let results = (outs VectorOfRankAndType<[2], [F32]>:$res);
  let extraClassDeclaration = [{
    VectorType getLhsVectorType() {
      return lhs().getType().cast<VectorType>();
    }
    VectorType getRhsVectorType() {
      return rhs().getType().cast<VectorType>();
    }
    VectorType getVectorType() {
      return res().getType().cast<VectorType>();
    }
  }];
  let assemblyFormat = "$lhs `,` $rhs `,` $acc attr-dict `:` "
                       "type($lhs) `,` type($rhs) `,` type($acc) ";
  let hasVerifier = 1;
}


def outerProductFHOp: MMA_Op<"outerFH", [NoSideEffect, AllTypesMatch<["acc", "res"]>]>  {
  let summary = "this operation performs the outer product of two registers and stores a result back in to the result register";

  let description = [{
      outerProduct

      Example:
         ```mlir
      %0 = mma.outerFH "pp" %a, %b, %c
        : vector<4xf32>, vector<4xf32>, vector<4x4xf32>
    ```

  }];

  let arguments = (ins VectorOfLengthAndType<[4], [F32, F64]>:$lhs,
                       VectorOfLengthAndType<[4, 2], [F32, F64]>:$rhs,
                       VectorOfRankAndType<[2], [F32, F64]>:$acc,
                        StrAttr: $st);

  let results = (outs VectorOfRankAndType<[2], [F32, F64]>:$res);

  let extraClassDeclaration = [{
    VectorType getLhsVectorType() {
      return lhs().getType().cast<VectorType>();
    }
    VectorType getRhsVectorType() {
      return rhs().getType().cast<VectorType>();
    }
    VectorType getVectorType() {
      return res().getType().cast<VectorType>();
    }
  }];
  let assemblyFormat = "$st `,` $lhs `,` $rhs `,` $acc attr-dict `:` "
                       "type($lhs) `,` type($rhs) `,` type($acc) ";
  let hasVerifier = 1;
}


def outerProductIOp: MMA_Op<"outerI", [NoSideEffect, AllTypesMatch<["acc", "res"]>]>  {
  let summary = "this operation performs the outer product of two registers and stores a result back in to the result register";

  let description = [{
      outerProduct

      Example:
         ```mlir
      %0 = mma.outerI %a, %b, %c
        : vector<4x2xI16>, vector<4x2xI16>, vector<4x4xI32>
    ```

  }];

  let arguments = (ins VectorOfRankAndType<[2], [I16, I8, UI8]>:$lhs,
                       VectorOfRankAndType<[2], [I16, I8, UI8]>:$rhs,
                       VectorOfRankAndType<[2], [I32]>:$acc);

  let results = (outs VectorOfRankAndType<[2], [I32]>:$res);
  let extraClassDeclaration = [{
    VectorType getLhsVectorType() {
      return lhs().getType().cast<VectorType>();
    }
    VectorType getRhsVectorType() {
      return rhs().getType().cast<VectorType>();
    }
    VectorType getVectorType() {
      return res().getType().cast<VectorType>();
    }
  }];
  let assemblyFormat = "$lhs `,` $rhs `,` $acc attr-dict `:` "
                       "type($lhs) `,` type($rhs) `,` type($acc) ";
  let hasVerifier = 1;
}



//===----------------------------------------------------------------------===//
// MMA IntrOp definitions (LLVM compiler facing).
//===----------------------------------------------------------------------===//

  def LLVM_ppc_mma_xxsetaccz : MMA_IntrOp<"xxsetaccz", 1>,
  Arguments<(ins AnyInteger, AnyInteger)>;


  def LLVM_ppc_mma_xvf32ger: MMA_IntrOp<"xvf32ger", 1>,
  Arguments<(ins AnyInteger,
                 AnyInteger,
		 AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type)>;
    

  def LLVM_ppc_mma_xvi16ger2: MMA_IntrOp<"xvi16ger2", 1>,
  Arguments<(ins AnyInteger,
                 AnyInteger,
		 AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type)>;

 
#endif
