#ifndef MLIR_DIALECT_MMA_MMADIALECT_H_
#define MLIR_DIALECT_MMA_MMADIALECT_H_

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#include "mlir/Dialect/MMA/MMADialect.h.inc"

#define GET_OP_CLASSES
#include "mlir/Dialect/MMA/MMA.h.inc"

#endif // MLIR_DIALECT_MMA_MMADIALECT_H_