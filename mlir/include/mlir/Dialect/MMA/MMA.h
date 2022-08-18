//===- MMADialect.h - MLIR Dialect for MMA ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the Target dialect for MMA in MLIR.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_MMA_MMADIALECT_H_
#define MLIR_DIALECT_MMA_MMADIALECT_H_

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#include "mlir/Dialect/MMA/MMADialect.h.inc"

#define GET_OP_CLASSES
#include "mlir/Dialect/MMA/MMA.h.inc"

#endif 
