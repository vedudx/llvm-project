// RUN: mlir-opt %s -split-input-file -verify-diagnostics

// -----

func.func @rowheight(%arg0: i32) {
  // expected-error@+1 {{'amx.tile_zero' op bad row height: 17}}
  %c0 = arith.constant 0 : index
  %0 = mma.load %arg0[%c0, %c0] : memref<?x?xf16> into vector<8x8xf32>
}

