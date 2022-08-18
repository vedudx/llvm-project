#ifndef MLIR_DIALECT_MMA_PASSES
#define MLIR_DIALECT_MMA_PASSES

include "mlir/Pass/PassBase.td"

def: Pat<(mma.load($ arg[$c $c])), mma.load($ arg)>;