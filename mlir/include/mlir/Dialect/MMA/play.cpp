------------- Classes -----------------
class 0DTensorOf<list<Type> 0DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type TensorRankOf
  Pred predicate = And<[TensorOf<0DTensorOf:allowedTypes>.predicate, anonymous_103]>;
  string summary = !strconcat("0D", !strconcat(" ", TensorOf<0DTensorOf:allowedTypes>.summary));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class 1DTensorOf<list<Type> 1DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type TensorRankOf
  Pred predicate = And<[TensorOf<1DTensorOf:allowedTypes>.predicate, anonymous_106]>;
  string summary = !strconcat("1D", !strconcat(" ", TensorOf<1DTensorOf:allowedTypes>.summary));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class 2DTensorOf<list<Type> 2DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type TensorRankOf
  Pred predicate = And<[TensorOf<2DTensorOf:allowedTypes>.predicate, anonymous_109]>;
  string summary = !strconcat("2D", !strconcat(" ", TensorOf<2DTensorOf:allowedTypes>.summary));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class 3DTensorOf<list<Type> 3DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type TensorRankOf
  Pred predicate = And<[TensorOf<3DTensorOf:allowedTypes>.predicate, anonymous_112]>;
  string summary = !strconcat("3D", !strconcat(" ", TensorOf<3DTensorOf:allowedTypes>.summary));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class 4DTensorOf<list<Type> 4DTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type TensorRankOf
  Pred predicate = And<[TensorOf<4DTensorOf:allowedTypes>.predicate, anonymous_115]>;
  string summary = !strconcat("4D", !strconcat(" ", TensorOf<4DTensorOf:allowedTypes>.summary));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class AMX_IntrOp<string AMX_IntrOp:mnemonic = ?, int AMX_IntrOp:numResults = ?, list<Trait> AMX_IntrOp:traits = []> {	// Op LLVM_OpBase Results LLVM_IntrOpBase
  Dialect opDialect = AMX_Dialect;
  string opName = AMX_IntrOp:mnemonic;
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = !if(!gt(AMX_IntrOp:numResults, 0), (outs LLVM_Type:$res), (outs));
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = AMX_IntrOp:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::}], !strconcat(!strconcat("x86_", !strconcat(!subst(".", "_", AMX_IntrOp:mnemonic), "_internal")), !strconcat([{,
        { }], !strconcat(!interleave(!listconcat(ListIntSubst<resultPattern, []>.lst, []), ", "), !strconcat([{
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    }], !strconcat([{auto *inst = builder.CreateCall(fn, operands);
    }], !strconcat("(void) inst;", !strconcat("(void) inst;", !if(!gt(AMX_IntrOp:numResults, 0), "$res = inst;", "")))))))));
  string resultPattern = !if(!gt(AMX_IntrOp:numResults, 1), [{moduleTranslation.convertType(
        opInst.getResult(0).getType().cast<LLVM::LLVMStructType>()
              .getBody()[$0])}], [{moduleTranslation.convertType(opInst.getResult($0).getType())}]);
  string llvmEnumName = !strconcat("x86_", !strconcat(!subst(".", "_", AMX_IntrOp:mnemonic), "_internal"));
}
class AMX_Op<string AMX_Op:mnemonic = ?, list<Trait> AMX_Op:traits = []> {	// Op
  Dialect opDialect = AMX_Dialect;
  string opName = AMX_Op:mnemonic;
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = AMX_Op:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
class APFloatParameter<string APFloatParameter:desc = ?> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = "$_lhs.bitwiseIsEqual($_rhs)";
  string cppType = "::llvm::APFloat";
  string cppAccessorType = "::llvm::APFloat";
  string cppStorageType = ?;
  string summary = APFloatParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class AllAttrConstraintsOf<list<AttrConstraint> AllAttrConstraintsOf:constraints = ?> {	// Constraint AttrConstraint
  Pred predicate = And<!listconcat([!head(AllAttrConstraintsOf:constraints).predicate], !foreach(pred, !tail(AllAttrConstraintsOf:constraints), pred.predicate))>;
  string summary = !interleave(!foreach(con, AllAttrConstraintsOf:constraints, con.summary), " and ");
}
class AllElementCountsMatch<list<string> AllElementCountsMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllElementCountsMatch:names, ", "), "} have same element count"));
  Pred predicate = AllMatchSameOperatorPred<AllElementCountsMatch:names, "$_self.getType().cast<::mlir::ShapedType>().getNumElements()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllElementCountsMatch:names;
}
class AllElementTypesMatch<list<string> AllElementTypesMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllElementTypesMatch:names, ", "), "} have same element type"));
  Pred predicate = AllMatchSameOperatorPred<AllElementTypesMatch:names, "getElementTypeOrSelf($_self)">;
  list<Trait> dependentTraits = [];
  list<string> values = AllElementTypesMatch:names;
}
class AllMatch<list<string> AllMatch:values = ?, string AllMatch:summary = ?> {	// Trait PredTrait PredOpTrait
  string summary = AllMatch:summary;
  Pred predicate = AllMatchPred<AllMatch:values>;
  list<Trait> dependentTraits = [];
}
class AllMatchPred<list<string> AllMatchPred:values = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("::llvm::is_splat(::llvm::makeArrayRef({", !strconcat(!interleave(AllMatchPred:values, ", "), "}))")), ")"));
}
class AllMatchSameOperatorPred<list<string> AllMatchSameOperatorPred:names = ?, string AllMatchSameOperatorPred:operator = ?> {	// Pred CPred AllMatchPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("::llvm::is_splat(::llvm::makeArrayRef({", !strconcat(!interleave(!foreach(n, AllMatchSameOperatorPred:names, !subst("$_self", !strconcat("$", n), AllMatchSameOperatorPred:operator)), ", "), "}))")), ")"));
}
class AllMatchSameOperatorTrait<list<string> AllMatchSameOperatorTrait:names = ?, string AllMatchSameOperatorTrait:operator = ?, string AllMatchSameOperatorTrait:summary = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllMatchSameOperatorTrait:names, ", "), !strconcat("} have same ", AllMatchSameOperatorTrait:summary)));
  Pred predicate = AllMatchSameOperatorPred<AllMatchSameOperatorTrait:names, AllMatchSameOperatorTrait:operator>;
  list<Trait> dependentTraits = [];
  list<string> values = AllMatchSameOperatorTrait:names;
}
class AllRanksMatch<list<string> AllRanksMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllRanksMatch:names, ", "), "} have same rank"));
  Pred predicate = AllMatchSameOperatorPred<AllRanksMatch:names, "$_self.getType().cast<::mlir::ShapedType>().getRank()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllRanksMatch:names;
}
class AllShapesMatch<list<string> AllShapesMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllShapesMatch:names, ", "), "} have same shape"));
  Pred predicate = AllMatchSameOperatorPred<AllShapesMatch:names, "$_self.getType().cast<::mlir::ShapedType>().getShape()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllShapesMatch:names;
}
class AllTypesMatch<list<string> AllTypesMatch:names = ?> {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait
  string summary = !strconcat("all of {", !strconcat(!interleave(AllTypesMatch:names, ", "), "} have same type"));
  Pred predicate = AllMatchSameOperatorPred<AllTypesMatch:names, "$_self.getType()">;
  list<Trait> dependentTraits = [];
  list<string> values = AllTypesMatch:names;
}
class And<list<Pred> And:children = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = And:children;
}
class AnyAttrOf<list<Attr> AnyAttrOf:allowedAttrs = ?, string AnyAttrOf:summary = "", string AnyAttrOf:cppClassName = "::mlir::Attribute", string AnyAttrOf:fromStorage = "$_self"> {	// Constraint AttrConstraint Attr
  Pred predicate = Or<!foreach(allowedattr, AnyAttrOf:allowedAttrs, allowedattr.predicate)>;
  string summary = !if(!eq(AnyAttrOf:summary, ""), !interleave(!foreach(t, AnyAttrOf:allowedAttrs, t.summary), " or "), AnyAttrOf:summary);
  string storageType = ?;
  string returnType = AnyAttrOf:cppClassName;
  string convertFromStorage = AnyAttrOf:fromStorage;
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class AnyI<int AnyI:width = ?> {	// Constraint TypeConstraint Type
  Pred predicate = CPred<!strconcat("$_self.isInteger(", !strconcat(!cast<string>(AnyI:width), ")"))>;
  string summary = !strconcat(!cast<string>(AnyI:width), "-bit integer");
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = AnyI:width;
}
class AnyIntOfWidths<list<int> AnyIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<!foreach(allowedtype, !foreach(w, AnyIntOfWidths:widths, AnyI<w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(AnyIntOfWidths:widths, "/"), "-bit integer"), ""), !interleave(!foreach(t, !foreach(w, AnyIntOfWidths:widths, AnyI<w>), t.summary), " or "), !strconcat(!interleave(AnyIntOfWidths:widths, "/"), "-bit integer"));
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "";
}
class AnyIntegerAttrBase<AnyI AnyIntegerAttrBase:attrValType = ?, string AnyIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isInteger(", !strconcat(!cast<string>(AnyIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = AnyIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class AnyStridedMemRefOfRank<int AnyStridedMemRefOfRank:rank = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[anonymous_132, MemRefRankOf<[AnyType], [AnyStridedMemRefOfRank:rank]>.predicate]>;
  string summary = !strconcat("strided memref of any type values", !strconcat(" of rank ", !cast<string>(AnyStridedMemRefOfRank:rank)));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class AnyTypeOf<list<Type> AnyTypeOf:allowedTypes = ?, string AnyTypeOf:summary = "", string AnyTypeOf:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = Or<!foreach(allowedtype, AnyTypeOf:allowedTypes, allowedtype.predicate)>;
  string summary = !if(!eq(AnyTypeOf:summary, ""), !interleave(!foreach(t, AnyTypeOf:allowedTypes, t.summary), " or "), AnyTypeOf:summary);
  string cppClassName = AnyTypeOf:cppClassName;
  string description = "";
  string builderCall = "";
}
class Arg<Constraint Arg:constraint = ?, string Arg:desc = "", list<OpVariableDecorator> Arg:decorators = []> {	// OpVariable
  Constraint constraint = Arg:constraint;
  string summary = Arg:desc;
  list<OpVariableDecorator> decorators = Arg:decorators;
}
class Arguments<dag Arguments:args = ?> {
  dag arguments = Arguments:args;
}
class ArrayAttrBase<Pred ArrayAttrBase:condition = ?, string ArrayAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = ArrayAttrBase:condition;
  string summary = ArrayAttrBase:summary;
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class ArrayCount<int ArrayCount:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::ArrayAttr>().size() == ", !cast<string>(ArrayCount:n))>;
  string summary = !strconcat("with exactly ", !strconcat(!cast<string>(ArrayCount:n), " elements"));
}
class ArrayMinCount<int ArrayMinCount:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::ArrayAttr>().size() >= ", !cast<string>(ArrayMinCount:n))>;
  string summary = !strconcat("with at least ", !strconcat(!cast<string>(ArrayMinCount:n), " elements"));
}
class ArrayRefOfSelfAllocationParameter<string ArrayRefOfSelfAllocationParameter:arrayOf = ?, string ArrayRefOfSelfAllocationParameter:desc = ?> {	// AttrOrTypeParameter
  string allocator = !strconcat([{
    llvm::SmallVector<}], !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, !strconcat([{, 4> tmpFields;
    for (size_t i = 0, e = $_self.size(); i < e; ++i)
      tmpFields.push_back($_self[i].allocateInto($_allocator));
    $_dst = $_allocator.copyInto(ArrayRef<}], !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, [{>(tmpFields));
  }]))));
  string comparator = ?;
  string cppType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, ">"));
  string cppAccessorType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefOfSelfAllocationParameter:arrayOf, ">"));
  string cppStorageType = ?;
  string summary = ArrayRefOfSelfAllocationParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class ArrayRefParameter<string ArrayRefParameter:arrayOf = ?, string ArrayRefParameter:desc = ""> {	// AttrOrTypeParameter
  code allocator = [{$_dst = $_allocator.copyInto($_self);}];
  string comparator = ?;
  string cppType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefParameter:arrayOf, ">"));
  string cppAccessorType = !strconcat("::llvm::ArrayRef<", !strconcat(ArrayRefParameter:arrayOf, ">"));
  string cppStorageType = !strconcat("::llvm::SmallVector<", !strconcat(ArrayRefParameter:arrayOf, ">"));
  string summary = ArrayRefParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class Attr<Pred Attr:condition = ?, string Attr:summary = ""> {	// Constraint AttrConstraint
  Pred predicate = Attr:condition;
  string summary = Attr:summary;
  string storageType = ?;
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class AttrBuilder<dag AttrBuilder:parameters = ?, string AttrBuilder:bodyCode = ""> {	// AttrOrTypeBuilder
  dag dagParams = AttrBuilder:parameters;
  string body = AttrBuilder:bodyCode;
  bit hasInferredContextParam = 0;
}
class AttrBuilderWithInferredContext<dag AttrBuilderWithInferredContext:parameters = ?, string AttrBuilderWithInferredContext:bodyCode = ""> {	// AttrOrTypeBuilder TypeBuilder AttrOrTypeBuilderWithInferredContext
  dag dagParams = AttrBuilderWithInferredContext:parameters;
  string body = AttrBuilderWithInferredContext:bodyCode;
  bit hasInferredContextParam = 1;
}
class AttrConstraint<Pred AttrConstraint:predicate = ?, string AttrConstraint:summary = ""> {	// Constraint
  Pred predicate = AttrConstraint:predicate;
  string summary = AttrConstraint:summary;
}
class AttrDef<Dialect AttrDef:dialect = ?, string AttrDef:name = ?, list<Trait> AttrDef:traits = [], string AttrDef:baseCppClass = "::mlir::Attribute"> {	// Constraint AttrConstraint Attr DialectAttr AttrOrTypeDef
  Pred predicate = CPred<!strconcat("$_self.isa<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">()"))))>;
  string summary = "";
  string storageType = !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(AttrDef:name, "Attr")));
  string returnType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string convertFromStorage = !strconcat("$_self.cast<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">()"))));
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = AttrDef:dialect.cppNamespace;
  string description = "";
  Dialect dialect = AttrDef:dialect;
  string cppBaseClassName = AttrDef:baseCppClass;
  string storageClass = !strconcat(AttrDef:name, "AttrStorage");
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = AttrDef:traits;
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  string cppClassName = !strconcat(AttrDef:name, "Attr");
  string cppType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string typeBuilder = ?;
}
class AttrInterface<string AttrInterface:name = ?> {	// Interface Trait NativeTrait InterfaceTrait
  string description = "";
  string cppClassName = AttrInterface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(AttrInterface:name, "::Trait");
  string extraTraitClassDeclaration = "";
}
class AttrOrTypeBuilder<dag AttrOrTypeBuilder:parameters = ?, string AttrOrTypeBuilder:bodyCode = ""> {
  dag dagParams = AttrOrTypeBuilder:parameters;
  string body = AttrOrTypeBuilder:bodyCode;
  bit hasInferredContextParam = 0;
}
class AttrOrTypeBuilderWithInferredContext<dag AttrOrTypeBuilderWithInferredContext:parameters = ?, string AttrOrTypeBuilderWithInferredContext:bodyCode = ""> {	// AttrOrTypeBuilder TypeBuilder
  dag dagParams = AttrOrTypeBuilderWithInferredContext:parameters;
  string body = AttrOrTypeBuilderWithInferredContext:bodyCode;
  bit hasInferredContextParam = 1;
}
class AttrOrTypeDef<string AttrOrTypeDef:valueType = ?, string AttrOrTypeDef:name = ?, list<Trait> AttrOrTypeDef:defTraits = ?, string AttrOrTypeDef:baseCppClass = ?> {
  string cppBaseClassName = AttrOrTypeDef:baseCppClass;
  string description = "";
  string storageClass = !strconcat(AttrOrTypeDef:name, !strconcat(AttrOrTypeDef:valueType, "Storage"));
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = AttrOrTypeDef:defTraits;
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
}
class AttrOrTypeParameter<string AttrOrTypeParameter:type = ?, string AttrOrTypeParameter:desc = ?, string AttrOrTypeParameter:accessorType = ""> {
  string allocator = ?;
  string comparator = ?;
  string cppType = AttrOrTypeParameter:type;
  string cppAccessorType = !if(!empty(AttrOrTypeParameter:accessorType), AttrOrTypeParameter:type, AttrOrTypeParameter:accessorType);
  string cppStorageType = ?;
  string summary = AttrOrTypeParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class AttrParameter<string AttrParameter:type = ?, string AttrParameter:desc = ?, string AttrParameter:accessorType = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = AttrParameter:type;
  string cppAccessorType = !if(!empty(AttrParameter:accessorType), AttrParameter:type, AttrParameter:accessorType);
  string cppStorageType = ?;
  string summary = AttrParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class AttributeSelfTypeParameter<string AttributeSelfTypeParameter:desc = ?, string AttributeSelfTypeParameter:derivedType = "::mlir::Type"> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = AttributeSelfTypeParameter:derivedType;
  string cppAccessorType = AttributeSelfTypeParameter:derivedType;
  string cppStorageType = ?;
  string summary = AttributeSelfTypeParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class BitEnumAttr<I BitEnumAttr:intType = ?, string BitEnumAttr:name = ?, string BitEnumAttr:summary = ?, list<BitEnumAttrCaseBase> BitEnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = BitEnumAttrBase<BitEnumAttr:intType, BitEnumAttr:cases, BitEnumAttr:summary>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = BitEnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = BitEnumAttr:cases;
  string underlyingType = "";
  string underlyingToSymbolFnName = !strconcat("symbolize", BitEnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", BitEnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", BitEnumAttr:name);
  string symbolToStringFnRetType = "std::string";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", BitEnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = BitEnumAttrBase<BitEnumAttr:intType, BitEnumAttr:cases, BitEnumAttr:summary>;
  string specializedAttrClassName = !strconcat(BitEnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    }], !strconcat(cppType, !strconcat([{ flags = {};
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    do {
      if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
      if (!maybeEnum) {
          return {(::mlir::LogicalResult)($_parser.emitError(loc) << }], !strconcat([{"expected " << "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), !strconcat([{)};
      }
      flags = flags | *maybeEnum;
    } while(::mlir::succeeded($_parser.}], !strconcat(parseSeparatorFn, [{()));
    return flags;
  }()}])))))))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
  int validBits = !foldl(0, BitEnumAttr:cases, value, bitcase, !or(value, bitcase.value));
  string separator = "|";
  string parseSeparatorFn = !if(!ge(!find(separator, "|", 0), 0), "parseOptionalVerticalBar", "parseOptionalComma");
  bit printBitEnumPrimaryGroups = 0;
}
class BitEnumAttrBase<I BitEnumAttrBase:intType = ?, list<BitEnumAttrCaseBase> BitEnumAttrBase:cases = ?, string BitEnumAttrBase:summary = ?> {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase
  Pred predicate = And<[SignlessIntegerAttrBase<BitEnumAttrBase:intType, summary>.predicate, CPred<!strconcat("!($_self.cast<::mlir::IntegerAttr>().getValue().getZExtValue() & (~(", !strconcat(!interleave(!foreach(case, BitEnumAttrBase:cases, !strconcat(!cast<string>(case.value), "u")), "|"), ")))"))>]>;
  string summary = BitEnumAttrBase:summary;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(BitEnumAttrBase:intType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = BitEnumAttrBase:intType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class BitEnumAttrCaseBase<I BitEnumAttrCaseBase:intType = ?, string BitEnumAttrCaseBase:sym = ?, int BitEnumAttrCaseBase:val = ?, string BitEnumAttrCaseBase:str = BitEnumAttrCaseBase:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase
  string symbol = BitEnumAttrCaseBase:sym;
  int value = BitEnumAttrCaseBase:val;
  string str = BitEnumAttrCaseBase:str;
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(", !strconcat(!cast<string>(BitEnumAttrCaseBase:intType.bitwidth), ")"))>]>;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(BitEnumAttrCaseBase:intType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = BitEnumAttrCaseBase:intType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class BitEnumAttrCaseBit<I BitEnumAttrCaseBit:intType = ?, string BitEnumAttrCaseBit:sym = ?, int BitEnumAttrCaseBit:pos = ?, string BitEnumAttrCaseBit:str = BitEnumAttrCaseBit:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase
  string symbol = BitEnumAttrCaseBit:sym;
  int value = !shl(1, BitEnumAttrCaseBit:pos);
  string str = BitEnumAttrCaseBit:str;
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(", !strconcat(!cast<string>(BitEnumAttrCaseBit:intType.bitwidth), ")"))>]>;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(BitEnumAttrCaseBit:intType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = BitEnumAttrCaseBit:intType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class BitEnumAttrCaseGroup<I BitEnumAttrCaseGroup:intType = ?, string BitEnumAttrCaseGroup:sym = ?, list<BitEnumAttrCaseBase> BitEnumAttrCaseGroup:cases = ?, string BitEnumAttrCaseGroup:str = BitEnumAttrCaseGroup:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase
  string symbol = BitEnumAttrCaseGroup:sym;
  int value = !foldl(0, BitEnumAttrCaseGroup:cases, value, bitcase, !or(value, bitcase.value));
  string str = BitEnumAttrCaseGroup:str;
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(", !strconcat(!cast<string>(BitEnumAttrCaseGroup:intType.bitwidth), ")"))>]>;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(BitEnumAttrCaseGroup:intType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = BitEnumAttrCaseGroup:intType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class BuildableType<string BuildableType:builder = ?> {
  string builderCall = BuildableType:builder;
}
class CArg<string CArg:ty = ?, string CArg:value = ""> {
  string type = CArg:ty;
  string defaultValue = CArg:value;
}
class CPred<string CPred:pred = ?> {	// Pred
  string predExpr = !strconcat("(", !strconcat(CPred:pred, ")"));
}
class CombinedPred<PredCombinerKind CombinedPred:k = ?, list<Pred> CombinedPred:c = ?> {	// Pred
  PredCombinerKind kind = CombinedPred:k;
  list<Pred> children = CombinedPred:c;
}
class Complex<Type Complex:type = ?> {	// Constraint TypeConstraint Type SameBuildabilityAs
  Pred predicate = And<[anonymous_37, SubstLeaves<"$_self", "$_self.cast<::mlir::ComplexType>().getElementType()", Complex:type.predicate>]>;
  string summary = !strconcat("complex type with ", !strconcat(Complex:type.summary, " elements"));
  string cppClassName = "::mlir::ComplexType";
  string description = "";
  string builderCall = !if(!empty(Complex:type.builderCall), "", !strconcat("::mlir::ComplexType::get($_builder.get", !strconcat(!cast<string>(Complex:type), "Type())")));
  Type elementType = Complex:type;
}
class Concat<string Concat:pre = ?, Pred Concat:child = ?, string Concat:suf = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [Concat:child];
  string prefix = Concat:pre;
  string suffix = Concat:suf;
}
class Confined<Attr Confined:attr = ?, list<AttrConstraint> Confined:constraints = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = And<!listconcat([Confined:attr.predicate], !foreach(pred, Confined:constraints, pred.predicate))>;
  string summary = !foldl(Confined:attr.summary, Confined:constraints, prev, cur, !strconcat(prev, !strconcat(" ", cur.summary)));
  string storageType = Confined:attr.storageType;
  string returnType = Confined:attr.returnType;
  string convertFromStorage = Confined:attr.convertFromStorage;
  string constBuilderCall = Confined:attr.constBuilderCall;
  string defaultValue = Confined:attr.defaultValue;
  Type valueType = Confined:attr.valueType;
  bit isOptional = Confined:attr.isOptional;
  Attr baseAttr = Confined:attr;
  string cppNamespace = "";
  string description = "";
}
class ConstF32Attr<string ConstF32Attr:val = ?> {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = CPred<!strconcat("$_self == ", !subst("$0", ConstF32Attr:val, "$_builder.getFloatAttr($_builder.getF32Type(), $0)"))>;
  string summary = !strconcat("constant attribute ", ConstF32Attr:val);
  Attr attr = F32Attr;
  string value = ConstF32Attr:val;
}
class ConstantAttr<Attr ConstantAttr:attribute = ?, string ConstantAttr:val = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<!strconcat("$_self == ", !subst("$0", ConstantAttr:val, ConstantAttr:attribute.constBuilderCall))>;
  string summary = !strconcat("constant attribute ", ConstantAttr:val);
  Attr attr = ConstantAttr:attribute;
  string value = ConstantAttr:val;
}
class ConstantStrAttr<Attr ConstantStrAttr:attribute = ?, string ConstantStrAttr:val = ?> {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = CPred<!strconcat("$_self == ", !subst("$0", !strconcat(""", !strconcat(ConstantStrAttr:val, """)), ConstantStrAttr:attribute.constBuilderCall))>;
  string summary = !strconcat("constant attribute ", !strconcat(""", !strconcat(ConstantStrAttr:val, """)));
  Attr attr = ConstantStrAttr:attribute;
  string value = !strconcat(""", !strconcat(ConstantStrAttr:val, """));
}
class Constraint<Pred Constraint:pred = ?, string Constraint:desc = ""> {
  Pred predicate = Constraint:pred;
  string summary = Constraint:desc;
}
class ContainerType<Type ContainerType:etype = ?, Pred ContainerType:containerPred = ?, string ContainerType:elementTypeCall = ?, string ContainerType:descr = ?, string ContainerType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = And<[ContainerType:containerPred, SubstLeaves<"$_self", ContainerType:elementTypeCall, ContainerType:etype.predicate>]>;
  string summary = !strconcat(ContainerType:descr, !strconcat(" of ", !strconcat(ContainerType:etype.summary, " values")));
  string cppClassName = ContainerType:cppClassName;
  string description = "";
  string builderCall = "";
}
class DeclareAttrInterfaceMethods<AttrInterface DeclareAttrInterfaceMethods:interface = ?, list<string> DeclareAttrInterfaceMethods:overridenMethods = []> {	// DeclareInterfaceMethods Interface Trait NativeTrait InterfaceTrait AttrInterface
  list<string> alwaysOverriddenMethods = DeclareAttrInterfaceMethods:overridenMethods;
  string description = DeclareAttrInterfaceMethods:interface.description;
  string cppClassName = DeclareAttrInterfaceMethods:interface.cppClassName;
  string cppNamespace = DeclareAttrInterfaceMethods:interface.cppNamespace;
  list<InterfaceMethod> methods = DeclareAttrInterfaceMethods:interface.methods;
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(DeclareAttrInterfaceMethods:interface.cppClassName, "::Trait");
  string extraTraitClassDeclaration = "";
}
class DeclareInterfaceMethods<list<string> DeclareInterfaceMethods:overridenMethods = []> {
  list<string> alwaysOverriddenMethods = DeclareInterfaceMethods:overridenMethods;
}
class DeclareOpInterfaceMethods<OpInterface DeclareOpInterfaceMethods:interface = ?, list<string> DeclareOpInterfaceMethods:overridenMethods = []> {	// DeclareInterfaceMethods Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  list<string> alwaysOverriddenMethods = DeclareOpInterfaceMethods:overridenMethods;
  string description = DeclareOpInterfaceMethods:interface.description;
  string cppClassName = DeclareOpInterfaceMethods:interface.cppClassName;
  string cppNamespace = DeclareOpInterfaceMethods:interface.cppNamespace;
  list<InterfaceMethod> methods = DeclareOpInterfaceMethods:interface.methods;
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(DeclareOpInterfaceMethods:interface.cppClassName, "::Trait");
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
class DeclareTypeInterfaceMethods<TypeInterface DeclareTypeInterfaceMethods:interface = ?, list<string> DeclareTypeInterfaceMethods:overridenMethods = []> {	// DeclareInterfaceMethods Interface Trait NativeTrait InterfaceTrait TypeInterface
  list<string> alwaysOverriddenMethods = DeclareTypeInterfaceMethods:overridenMethods;
  string description = DeclareTypeInterfaceMethods:interface.description;
  string cppClassName = DeclareTypeInterfaceMethods:interface.cppClassName;
  string cppNamespace = DeclareTypeInterfaceMethods:interface.cppNamespace;
  list<InterfaceMethod> methods = DeclareTypeInterfaceMethods:interface.methods;
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(DeclareTypeInterfaceMethods:interface.cppClassName, "::Trait");
  string extraTraitClassDeclaration = "";
}
class DefaultValuedAttr<Attr DefaultValuedAttr:attr = ?, string DefaultValuedAttr:val = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = DefaultValuedAttr:attr.predicate;
  string summary = DefaultValuedAttr:attr.summary;
  string storageType = DefaultValuedAttr:attr.storageType;
  string returnType = DefaultValuedAttr:attr.returnType;
  string convertFromStorage = DefaultValuedAttr:attr.convertFromStorage;
  string constBuilderCall = DefaultValuedAttr:attr.constBuilderCall;
  string defaultValue = DefaultValuedAttr:val;
  Type valueType = DefaultValuedAttr:attr.valueType;
  bit isOptional = 0;
  Attr baseAttr = DefaultValuedAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class DefaultValuedParameter<string DefaultValuedParameter:type = ?, string DefaultValuedParameter:value = ?, string DefaultValuedParameter:desc = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = DefaultValuedParameter:type;
  string cppAccessorType = DefaultValuedParameter:type;
  string cppStorageType = ?;
  string summary = DefaultValuedParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 1;
  string defaultValue = DefaultValuedParameter:value;
}
class DefaultValuedStrAttr<Attr DefaultValuedStrAttr:attr = ?, string DefaultValuedStrAttr:val = ?> {	// Constraint AttrConstraint Attr DefaultValuedAttr
  Pred predicate = DefaultValuedStrAttr:attr.predicate;
  string summary = DefaultValuedStrAttr:attr.summary;
  string storageType = DefaultValuedStrAttr:attr.storageType;
  string returnType = DefaultValuedStrAttr:attr.returnType;
  string convertFromStorage = DefaultValuedStrAttr:attr.convertFromStorage;
  string constBuilderCall = DefaultValuedStrAttr:attr.constBuilderCall;
  string defaultValue = !strconcat(""", !strconcat(DefaultValuedStrAttr:val, """));
  Type valueType = DefaultValuedStrAttr:attr.valueType;
  bit isOptional = 0;
  Attr baseAttr = DefaultValuedStrAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class Deprecated<string Deprecated:reason = ?> {
  string odsDeprecated = Deprecated:reason;
}
class DerivedAttr<string DerivedAttr:ret = ?, string DerivedAttr:b = ?, string DerivedAttr:convert = ""> {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_2;
  string summary = "derived attribute";
  string storageType = ?;
  string returnType = DerivedAttr:ret;
  string convertFromStorage = DerivedAttr:convert;
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string body = DerivedAttr:b;
}
class DerivedTypeAttr<string DerivedTypeAttr:body = ?> {	// Constraint AttrConstraint Attr DerivedAttr
  Pred predicate = anonymous_2;
  string summary = "derived attribute";
  string storageType = ?;
  string returnType = "::mlir::Type";
  string convertFromStorage = "::mlir::TypeAttr::get($_self)";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string body = DerivedTypeAttr:body;
}
class Dialect {
  string name = ?;
  string summary = ?;
  string description = ?;
  list<string> dependentDialects = [];
  string cppNamespace = name;
  string extraClassDeclaration = "";
  bit hasConstantMaterializer = 0;
  bit hasNonDefaultDestructor = 0;
  bit hasOperationAttrVerify = 0;
  bit hasRegionArgAttrVerify = 0;
  bit hasRegionResultAttrVerify = 0;
  bit hasOperationInterfaceFallback = 0;
  bit useDefaultAttributePrinterParser = 0;
  bit useDefaultTypePrinterParser = 0;
  bit hasCanonicalizer = 0;
  int emitAccessorPrefix = 0;
  bit isExtensible = 0;
}
class DialectAttr<Dialect DialectAttr:d = ?, Pred DialectAttr:condition = ?, string DialectAttr:summary = ""> {	// Constraint AttrConstraint Attr
  Pred predicate = DialectAttr:condition;
  string summary = DialectAttr:summary;
  string storageType = ?;
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = DialectAttr:d.cppNamespace;
  string description = "";
  Dialect dialect = DialectAttr:d;
}
class DialectType<Dialect DialectType:d = ?, Pred DialectType:condition = ?, string DialectType:descr = "", string DialectType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = DialectType:condition;
  string summary = DialectType:descr;
  string cppClassName = DialectType:cppClassName;
  string description = "";
  string builderCall = "";
  Dialect dialect = DialectType:d;
}
class DictionaryAttrBase<Pred DictionaryAttrBase:condition = ?, string DictionaryAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = DictionaryAttrBase:condition;
  string summary = DictionaryAttrBase:summary;
  code storageType = [{ ::mlir::DictionaryAttr }];
  code returnType = [{ ::mlir::DictionaryAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class EffectOpInterfaceBase<string EffectOpInterfaceBase:name = ?, string EffectOpInterfaceBase:baseEffect = ?> {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface
  string description = "";
  string cppClassName = EffectOpInterfaceBase:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [InterfaceMethod<[{
        Collects all of the operation's effects into `effects`.
      }], "void", "getEffects", (ins !strconcat("::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<", !strconcat(EffectOpInterfaceBase:baseEffect, ">> &")):$effects)>];
  string extraClassDeclaration = !strconcat([{
    /// Collect all of the effect instances that correspond to the given
    /// `Effect` and place them in 'effects'.
    template <typename Effect> void getEffects(
      SmallVectorImpl<::mlir::SideEffects::EffectInstance<
                                              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>> &effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return !llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation exhibits the given effect.
    template <typename Effect> bool hasEffect() {
      SmallVector<SideEffects::EffectInstance<}], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      return llvm::any_of(effects, [](const auto &it) {
        return llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation only has the given effect.
    template <typename Effect> bool onlyHasEffect() {
      SmallVector<SideEffects::EffectInstance<}], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      return !effects.empty() && llvm::all_of(effects, [](const auto &it) {
        return isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation has no effects.
    bool hasNoEffect() {
      SmallVector<::mlir::SideEffects::EffectInstance<}], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      return effects.empty();
    }

    /// Returns true if the given operation has no effects for this interface.
    static bool hasNoEffect(Operation *op) {
      if (auto interface = dyn_cast<}], !strconcat(EffectOpInterfaceBase:name, !strconcat([{>(op))
        return interface.hasNoEffect();
      return op->hasTrait<::mlir::OpTrait::HasRecursiveSideEffects>();
    }

    /// Collect all of the effect instances that operate on the provided value
    /// and place them in 'effects'.
    void getEffectsOnValue(::mlir::Value value,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) { return it.getValue() != value; });
    }

    /// Return the effect of the given type `Effect` that is applied to the
    /// given value, or None if no effect exists.
    template <typename Effect>
    ::llvm::Optional<::mlir::SideEffects::EffectInstance<}], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>>
    getEffectOnValue(::mlir::Value value) {
      llvm::SmallVector<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>, 4> effects;
      getEffects(effects);
      auto it = llvm::find_if(effects, [&](auto &it) {
        return isa<Effect>(it.getEffect()) && it.getValue() == value;
      });
      if (it == effects.end())
        return llvm::None;
      return *it;
    }

    /// Collect all of the effect instances that operate on the provided symbol
    /// reference and place them in 'effects'.
    void getEffectsOnSymbol(::mlir::SymbolRefAttr value,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, !strconcat([{>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return it.getSymbolRef() != value;
      });
    }

    /// Collect all of the effect instances that operate on the provided
    /// resource and place them in 'effects'.
    void getEffectsOnResource(::mlir::SideEffects::Resource *resource,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              }], !strconcat(EffectOpInterfaceBase:baseEffect, [{>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return it.getResource() != resource;
      });
    }
  }]))))))))))))))))))));
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(EffectOpInterfaceBase:name, "::Trait");
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = EffectOpInterfaceBase:baseEffect;
}
class ElementCount<string ElementCount:name = ?> {	// StrFunc
  string result = !strconcat("$", !strconcat(ElementCount:name, ".getType().cast<::mlir::ShapedType>().getNumElements()"));
}
class ElementType<string ElementType:name = ?> {	// StrFunc
  string result = !strconcat("getElementTypeOrSelf($", !strconcat(ElementType:name, ")"));
}
class ElementTypeIs<string ElementTypeIs:name = ?, Type ElementTypeIs:type = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("'", !strconcat(ElementTypeIs:name, !strconcat("' is ", ElementTypeIs:type.summary)));
  Pred predicate = ElementTypeIsPred<ElementTypeIs:name, ElementTypeIs:type>;
  list<Trait> dependentTraits = [];
}
class ElementTypeIsPred<string ElementTypeIsPred:name = ?, Type ElementTypeIsPred:type = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [SubstLeaves<"$_self", !strconcat("$", !strconcat(ElementTypeIsPred:name, ".getType()")), IsShapedTypePred>, SubstLeaves<"$_self", !strconcat("getElementTypeOrSelf($", !strconcat(ElementTypeIsPred:name, ")")), ElementTypeIsPred:type.predicate>];
}
class ElementsAttrBase<Pred ElementsAttrBase:condition = ?, string ElementsAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = ElementsAttrBase:condition;
  string summary = ElementsAttrBase:summary;
  code storageType = [{ ::mlir::ElementsAttr }];
  code returnType = [{ ::mlir::ElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class EnumAttr<Dialect EnumAttr:dialect = ?, EnumAttrInfo EnumAttr:enumInfo = ?, string EnumAttr:name = "", list<Trait> EnumAttr:traits = []> {	// Constraint AttrConstraint Attr DialectAttr AttrOrTypeDef AttrDef
  Pred predicate = CPred<!strconcat("$_self.isa<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">()"))))>;
  string summary = EnumAttr:enumInfo.summary;
  string storageType = !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(EnumAttr:enumInfo.className, "Attr")));
  string returnType = !strconcat(EnumAttr:enumInfo.cppNamespace, !strconcat("::", EnumAttr:enumInfo.className));
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat(cppNamespace, !strconcat("::", !strconcat(cppClassName, "::get($_builder.getContext(), $0)")));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = EnumAttr:enumInfo.cppNamespace;
  string description = "";
  Dialect dialect = EnumAttr:dialect;
  string cppBaseClassName = "::mlir::Attribute";
  string storageClass = !strconcat(EnumAttr:enumInfo.className, "AttrStorage");
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins EnumParameter<EnumAttr:enumInfo>:$value);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = EnumAttr:traits;
  string mnemonic = EnumAttr:name;
  string assemblyFormat = "$value";
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  string cppClassName = !strconcat(EnumAttr:enumInfo.className, "Attr");
  string cppType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
  string typeBuilder = ?;
  EnumAttrInfo enum = EnumAttr:enumInfo;
}
class EnumAttrCaseInfo<string EnumAttrCaseInfo:sym = ?, int EnumAttrCaseInfo:intVal = ?, string EnumAttrCaseInfo:strVal = ?> {
  string symbol = EnumAttrCaseInfo:sym;
  int value = EnumAttrCaseInfo:intVal;
  string str = EnumAttrCaseInfo:strVal;
}
class EnumAttrInfo<string EnumAttrInfo:name = ?, list<EnumAttrCaseInfo> EnumAttrInfo:cases = ?, Attr EnumAttrInfo:baseClass = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = EnumAttrInfo:baseClass.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = EnumAttrInfo:name;
  list<EnumAttrCaseInfo> enumerants = EnumAttrInfo:cases;
  string underlyingType = "";
  string underlyingToSymbolFnName = !strconcat("symbolize", EnumAttrInfo:name);
  string stringToSymbolFnName = !strconcat("symbolize", EnumAttrInfo:name);
  string symbolToStringFnName = !strconcat("stringify", EnumAttrInfo:name);
  string symbolToStringFnRetType = "::llvm::StringRef";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", EnumAttrInfo:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = EnumAttrInfo:baseClass;
  string specializedAttrClassName = !strconcat(EnumAttrInfo:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = ?;
  string parameterPrinter = ?;
}
class EnumParameter<EnumAttrInfo EnumParameter:enumInfo = ?> {	// AttrOrTypeParameter AttrParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = !strconcat(EnumParameter:enumInfo.cppNamespace, !strconcat("::", EnumParameter:enumInfo.className));
  string cppAccessorType = !strconcat(EnumParameter:enumInfo.cppNamespace, !strconcat("::", EnumParameter:enumInfo.className));
  string cppStorageType = ?;
  string summary = !strconcat("an enum of type ", EnumParameter:enumInfo.className);
  string syntax = ?;
  string parser = EnumParameter:enumInfo.parameterParser;
  string printer = EnumParameter:enumInfo.parameterPrinter;
  bit isOptional = 0;
  string defaultValue = ?;
}
class F<int F:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<!strconcat("$_self.isF", !strconcat(!cast<string>(F:width), "()"))>;
  string summary = !strconcat(!cast<string>(F:width), "-bit float");
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = !strconcat("$_builder.getF", !strconcat(!cast<string>(F:width), "Type()"));
  int bitwidth = F:width;
}
class FixedVectorOf<list<Type> FixedVectorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsFixedVectorTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<FixedVectorOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("fixed-length vector", !strconcat(" of ", !strconcat(AnyTypeOf<FixedVectorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class FixedVectorOfLength<list<int> FixedVectorOfLength:allowedLengths = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsFixedVectorOfLengthPred<FixedVectorOfLength:allowedLengths>;
  string summary = !strconcat(" of length ", !interleave(FixedVectorOfLength:allowedLengths, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class FixedVectorOfLengthAndType<list<int> FixedVectorOfLengthAndType:allowedLengths = ?, list<Type> FixedVectorOfLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[FixedVectorOf<FixedVectorOfLengthAndType:allowedTypes>.predicate, FixedVectorOfLength<FixedVectorOfLengthAndType:allowedLengths>.predicate]>;
  string summary = !strconcat(FixedVectorOf<FixedVectorOfLengthAndType:allowedTypes>.summary, FixedVectorOfLength<FixedVectorOfLengthAndType:allowedLengths>.summary);
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class FloatAttrBase<F FloatAttrBase:attrValType = ?, string FloatAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<[anonymous_207, CPred<!strconcat("$_self.cast<::mlir::FloatAttr>().getType().isF", !strconcat(!cast<string>(FloatAttrBase:attrValType.bitwidth), "()"))>]>;
  string summary = FloatAttrBase:descr;
  string storageType = "::mlir::FloatAttr";
  code returnType = [{ ::llvm::APFloat }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("FloatAttr", !strconcat("(", !strconcat(FloatAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = FloatAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class FloatElementsAttr<int FloatElementsAttr:width = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = CPred<!strconcat("$_self.isa<::mlir::DenseFPElementsAttr>() &&$_self.cast<::mlir::DenseElementsAttr>().getType().getElementType().isF", !strconcat(!cast<string>(FloatElementsAttr:width), "()"))>;
  string summary = !strconcat(!cast<string>(FloatElementsAttr:width), "-bit float elements attribute");
  code storageType = [{ ::mlir::DenseElementsAttr }];
  code returnType = [{ ::mlir::DenseElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getF", !strconcat(!cast<string>(FloatElementsAttr:width), "Type()),::llvm::makeArrayRef($0))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class FloatOfWidths<list<int> FloatOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<!foreach(allowedtype, !foreach(w, FloatOfWidths:widths, F<w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(FloatOfWidths:widths, "/"), "-bit float"), ""), !interleave(!foreach(t, !foreach(w, FloatOfWidths:widths, F<w>), t.summary), " or "), !strconcat(!interleave(FloatOfWidths:widths, "/"), "-bit float"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class GenInternalAttrTrait<string GenInternalAttrTrait:prop = ?> {	// Trait GenInternalTrait
  string trait = !strconcat("::mlir::", !strconcat("Attribute", !strconcat("Trait::", GenInternalAttrTrait:prop)));
}
class GenInternalOpTrait<string GenInternalOpTrait:prop = ?, list<Trait> GenInternalOpTrait:traits = []> {	// Trait GenInternalTrait
  string trait = !strconcat("::mlir::", !strconcat("Op", !strconcat("Trait::", GenInternalOpTrait:prop)));
  list<Trait> dependentTraits = GenInternalOpTrait:traits;
}
class GenInternalTrait<string GenInternalTrait:prop = ?, string GenInternalTrait:entityType = ?> {	// Trait
  string trait = !strconcat("::mlir::", !strconcat(GenInternalTrait:entityType, !strconcat("Trait::", GenInternalTrait:prop)));
}
class GenInternalTypeTrait<string GenInternalTypeTrait:prop = ?> {	// Trait GenInternalTrait
  string trait = !strconcat("::mlir::", !strconcat("Type", !strconcat("Trait::", GenInternalTypeTrait:prop)));
}
class HasAnyRankOfPred<list<int> HasAnyRankOfPred:ranks = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, Or<!foreach(rank, HasAnyRankOfPred:ranks, CPred<!strconcat([{$_self.cast<::mlir::ShapedType>().getRank()
                         == }], !cast<string>(rank))>)>];
}
class HasParent<string HasParent:op = ?> {	// Trait NativeTrait ParamNativeTrait ParamNativeOpTrait StructuralOpTrait
  string trait = !strconcat("HasParent", !strconcat("<", !strconcat(HasParent:op, ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
class I<int I:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<!strconcat("$_self.isSignlessInteger(", !strconcat(!cast<string>(I:width), ")"))>;
  string summary = !strconcat(!cast<string>(I:width), "-bit signless integer");
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = !strconcat("$_builder.getIntegerType(", !strconcat(!cast<string>(I:width), ")"));
  int bitwidth = I:width;
}
class I32BitEnumAttr<string I32BitEnumAttr:name = ?, string I32BitEnumAttr:summary = ?, list<BitEnumAttrCaseBase> I32BitEnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo BitEnumAttr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = BitEnumAttrBase<I32, I32BitEnumAttr:cases, I32BitEnumAttr:summary>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = I32BitEnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = I32BitEnumAttr:cases;
  string underlyingType = "uint32_t";
  string underlyingToSymbolFnName = !strconcat("symbolize", I32BitEnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", I32BitEnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", I32BitEnumAttr:name);
  string symbolToStringFnRetType = "std::string";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", I32BitEnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = BitEnumAttrBase<I32, I32BitEnumAttr:cases, I32BitEnumAttr:summary>;
  string specializedAttrClassName = !strconcat(I32BitEnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    }], !strconcat(cppType, !strconcat([{ flags = {};
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    do {
      if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
      if (!maybeEnum) {
          return {(::mlir::LogicalResult)($_parser.emitError(loc) << }], !strconcat([{"expected " << "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), !strconcat([{)};
      }
      flags = flags | *maybeEnum;
    } while(::mlir::succeeded($_parser.}], !strconcat(parseSeparatorFn, [{()));
    return flags;
  }()}])))))))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
  int validBits = !foldl(0, I32BitEnumAttr:cases, value, bitcase, !or(value, bitcase.value));
  string separator = "|";
  string parseSeparatorFn = !if(!ge(!find(separator, "|", 0), 0), "parseOptionalVerticalBar", "parseOptionalComma");
  bit printBitEnumPrimaryGroups = 0;
}
class I32BitEnumAttrCase<string I32BitEnumAttrCase:sym = ?, int I32BitEnumAttrCase:val = ?, string I32BitEnumAttrCase:str = I32BitEnumAttrCase:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase
  string symbol = I32BitEnumAttrCase:sym;
  int value = I32BitEnumAttrCase:val;
  string str = I32BitEnumAttrCase:str;
  Pred predicate = anonymous_184;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I32BitEnumAttrCaseBit<string I32BitEnumAttrCaseBit:sym = ?, int I32BitEnumAttrCaseBit:pos = ?, string I32BitEnumAttrCaseBit:str = I32BitEnumAttrCaseBit:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase BitEnumAttrCaseBit
  string symbol = I32BitEnumAttrCaseBit:sym;
  int value = !shl(1, I32BitEnumAttrCaseBit:pos);
  string str = I32BitEnumAttrCaseBit:str;
  Pred predicate = anonymous_184;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I32BitEnumAttrCaseGroup<string I32BitEnumAttrCaseGroup:sym = ?, list<BitEnumAttrCaseBase> I32BitEnumAttrCaseGroup:cases = ?, string I32BitEnumAttrCaseGroup:str = I32BitEnumAttrCaseGroup:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase BitEnumAttrCaseGroup
  string symbol = I32BitEnumAttrCaseGroup:sym;
  int value = !foldl(0, I32BitEnumAttrCaseGroup:cases, value, bitcase, !or(value, bitcase.value));
  string str = I32BitEnumAttrCaseGroup:str;
  Pred predicate = anonymous_184;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I32BitEnumAttrCaseNone<string I32BitEnumAttrCaseNone:sym = ?, string I32BitEnumAttrCaseNone:str = I32BitEnumAttrCaseNone:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase I32BitEnumAttrCase
  string symbol = I32BitEnumAttrCaseNone:sym;
  int value = 0;
  string str = I32BitEnumAttrCaseNone:str;
  Pred predicate = anonymous_184;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I32EnumAttr<string I32EnumAttr:name = ?, string I32EnumAttr:summary = ?, list<I32EnumAttrCase> I32EnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo IntEnumAttr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = IntEnumAttrBase<I32, I32EnumAttr:cases, !if(!empty(I32EnumAttr:summary), !strconcat("allowed ", !strconcat("32-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, I32EnumAttr:cases, case.value), ", ")))), I32EnumAttr:summary)>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = I32EnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = I32EnumAttr:cases;
  string underlyingType = "uint32_t";
  string underlyingToSymbolFnName = !strconcat("symbolize", I32EnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", I32EnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", I32EnumAttr:name);
  string symbolToStringFnRetType = "::llvm::StringRef";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", I32EnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = IntEnumAttrBase<I32, I32EnumAttr:cases, !if(!empty(I32EnumAttr:summary), !strconcat("allowed ", !strconcat("32-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, I32EnumAttr:cases, case.value), ", ")))), I32EnumAttr:summary)>;
  string specializedAttrClassName = !strconcat(I32EnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
      return ::mlir::failure();
    auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
    if (maybeEnum)
      return *maybeEnum;
    return {(::mlir::LogicalResult)($_parser.emitError(loc) << "expected " }], !strconcat([{<< "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), [{)};
  }()}])))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
}
class I32EnumAttrCase<string I32EnumAttrCase:sym = ?, int I32EnumAttrCase:val = ?, string I32EnumAttrCase:str = I32EnumAttrCase:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase IntEnumAttrCaseBase
  string symbol = I32EnumAttrCase:sym;
  int value = I32EnumAttrCase:val;
  string str = I32EnumAttrCase:str;
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getInt() == ", !cast<string>(I32EnumAttrCase:val))>;
  string summary = !strconcat("case ", I32EnumAttrCase:str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I64BitEnumAttr<string I64BitEnumAttr:name = ?, string I64BitEnumAttr:summary = ?, list<BitEnumAttrCaseBase> I64BitEnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo BitEnumAttr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = BitEnumAttrBase<I64, I64BitEnumAttr:cases, I64BitEnumAttr:summary>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = I64BitEnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = I64BitEnumAttr:cases;
  string underlyingType = "uint64_t";
  string underlyingToSymbolFnName = !strconcat("symbolize", I64BitEnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", I64BitEnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", I64BitEnumAttr:name);
  string symbolToStringFnRetType = "std::string";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", I64BitEnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = BitEnumAttrBase<I64, I64BitEnumAttr:cases, I64BitEnumAttr:summary>;
  string specializedAttrClassName = !strconcat(I64BitEnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    }], !strconcat(cppType, !strconcat([{ flags = {};
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    do {
      if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
      if (!maybeEnum) {
          return {(::mlir::LogicalResult)($_parser.emitError(loc) << }], !strconcat([{"expected " << "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), !strconcat([{)};
      }
      flags = flags | *maybeEnum;
    } while(::mlir::succeeded($_parser.}], !strconcat(parseSeparatorFn, [{()));
    return flags;
  }()}])))))))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
  int validBits = !foldl(0, I64BitEnumAttr:cases, value, bitcase, !or(value, bitcase.value));
  string separator = "|";
  string parseSeparatorFn = !if(!ge(!find(separator, "|", 0), 0), "parseOptionalVerticalBar", "parseOptionalComma");
  bit printBitEnumPrimaryGroups = 0;
}
class I64BitEnumAttrCase<string I64BitEnumAttrCase:sym = ?, int I64BitEnumAttrCase:val = ?, string I64BitEnumAttrCase:str = I64BitEnumAttrCase:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase
  string symbol = I64BitEnumAttrCase:sym;
  int value = I64BitEnumAttrCase:val;
  string str = I64BitEnumAttrCase:str;
  Pred predicate = anonymous_186;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I64BitEnumAttrCaseBit<string I64BitEnumAttrCaseBit:sym = ?, int I64BitEnumAttrCaseBit:pos = ?, string I64BitEnumAttrCaseBit:str = I64BitEnumAttrCaseBit:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase BitEnumAttrCaseBit
  string symbol = I64BitEnumAttrCaseBit:sym;
  int value = !shl(1, I64BitEnumAttrCaseBit:pos);
  string str = I64BitEnumAttrCaseBit:str;
  Pred predicate = anonymous_186;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I64BitEnumAttrCaseGroup<string I64BitEnumAttrCaseGroup:sym = ?, list<BitEnumAttrCaseBase> I64BitEnumAttrCaseGroup:cases = ?, string I64BitEnumAttrCaseGroup:str = I64BitEnumAttrCaseGroup:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase BitEnumAttrCaseGroup
  string symbol = I64BitEnumAttrCaseGroup:sym;
  int value = !foldl(0, I64BitEnumAttrCaseGroup:cases, value, bitcase, !or(value, bitcase.value));
  string str = I64BitEnumAttrCaseGroup:str;
  Pred predicate = anonymous_186;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I64BitEnumAttrCaseNone<string I64BitEnumAttrCaseNone:sym = ?, string I64BitEnumAttrCaseNone:str = I64BitEnumAttrCaseNone:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase BitEnumAttrCaseBase I64BitEnumAttrCase
  string symbol = I64BitEnumAttrCaseNone:sym;
  int value = 0;
  string str = I64BitEnumAttrCaseNone:str;
  Pred predicate = anonymous_186;
  string summary = !strconcat("case ", str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class I64EnumAttr<string I64EnumAttr:name = ?, string I64EnumAttr:summary = ?, list<I64EnumAttrCase> I64EnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo IntEnumAttr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = IntEnumAttrBase<I64, I64EnumAttr:cases, !if(!empty(I64EnumAttr:summary), !strconcat("allowed ", !strconcat("64-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, I64EnumAttr:cases, case.value), ", ")))), I64EnumAttr:summary)>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = I64EnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = I64EnumAttr:cases;
  string underlyingType = "uint64_t";
  string underlyingToSymbolFnName = !strconcat("symbolize", I64EnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", I64EnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", I64EnumAttr:name);
  string symbolToStringFnRetType = "::llvm::StringRef";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", I64EnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = IntEnumAttrBase<I64, I64EnumAttr:cases, !if(!empty(I64EnumAttr:summary), !strconcat("allowed ", !strconcat("64-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, I64EnumAttr:cases, case.value), ", ")))), I64EnumAttr:summary)>;
  string specializedAttrClassName = !strconcat(I64EnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
      return ::mlir::failure();
    auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
    if (maybeEnum)
      return *maybeEnum;
    return {(::mlir::LogicalResult)($_parser.emitError(loc) << "expected " }], !strconcat([{<< "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), [{)};
  }()}])))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
}
class I64EnumAttrCase<string I64EnumAttrCase:sym = ?, int I64EnumAttrCase:val = ?, string I64EnumAttrCase:str = I64EnumAttrCase:sym> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase IntEnumAttrCaseBase
  string symbol = I64EnumAttrCase:sym;
  int value = I64EnumAttrCase:val;
  string str = I64EnumAttrCase:str;
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getInt() == ", !cast<string>(I64EnumAttrCase:val))>;
  string summary = !strconcat("case ", I64EnumAttrCase:str);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntArrayNthElemEq<int IntArrayNthElemEq:index = ?, int IntArrayNthElemEq:value = ?> {	// Constraint AttrConstraint
  Pred predicate = And<[CPred<!strconcat("$_self.cast<::mlir::ArrayAttr>().size() > ", !cast<string>(IntArrayNthElemEq:index))>, CPred<!strconcat("$_self.cast<::mlir::ArrayAttr>()[", !strconcat(!cast<string>(IntArrayNthElemEq:index), !strconcat("].cast<::mlir::IntegerAttr>().getInt() == ", !cast<string>(IntArrayNthElemEq:value))))>]>;
  string summary = !strconcat("whose ", !strconcat(!cast<string>(IntArrayNthElemEq:index), !strconcat("-th element must be ", !cast<string>(IntArrayNthElemEq:value))));
}
class IntArrayNthElemMinValue<int IntArrayNthElemMinValue:index = ?, int IntArrayNthElemMinValue:min = ?> {	// Constraint AttrConstraint
  Pred predicate = And<[CPred<!strconcat("$_self.cast<::mlir::ArrayAttr>().size() > ", !cast<string>(IntArrayNthElemMinValue:index))>, CPred<!strconcat("$_self.cast<::mlir::ArrayAttr>()[", !strconcat(!cast<string>(IntArrayNthElemMinValue:index), !strconcat("].cast<::mlir::IntegerAttr>().getInt() >= ", !cast<string>(IntArrayNthElemMinValue:min))))>]>;
  string summary = !strconcat("whose ", !strconcat(!cast<string>(IntArrayNthElemMinValue:index), !strconcat("-th element must be at least ", !cast<string>(IntArrayNthElemMinValue:min))));
}
class IntElementsAttrBase<Pred IntElementsAttrBase:condition = ?, string IntElementsAttrBase:summary = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = And<[anonymous_219, IntElementsAttrBase:condition]>;
  string summary = IntElementsAttrBase:summary;
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntElementsAttrOf<int IntElementsAttrOf:width = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = And<[anonymous_219, CPred<!strconcat("$_self.cast<::mlir::DenseIntElementsAttr>().getType().getElementType().isInteger(", !strconcat(!cast<string>(IntElementsAttrOf:width), ")"))>]>;
  string summary = !strconcat(!cast<string>(IntElementsAttrOf:width), "-bit integer elements attribute");
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntEnumAttr<I IntEnumAttr:intType = ?, string IntEnumAttr:name = ?, string IntEnumAttr:summary = ?, list<IntEnumAttrCaseBase> IntEnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = IntEnumAttrBase<IntEnumAttr:intType, IntEnumAttr:cases, !if(!empty(IntEnumAttr:summary), !strconcat("allowed ", !strconcat(IntEnumAttr:intType.summary, !strconcat(" cases: ", !interleave(!foreach(case, IntEnumAttr:cases, case.value), ", ")))), IntEnumAttr:summary)>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = IntEnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = IntEnumAttr:cases;
  string underlyingType = "";
  string underlyingToSymbolFnName = !strconcat("symbolize", IntEnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", IntEnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", IntEnumAttr:name);
  string symbolToStringFnRetType = "::llvm::StringRef";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", IntEnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = IntEnumAttrBase<IntEnumAttr:intType, IntEnumAttr:cases, !if(!empty(IntEnumAttr:summary), !strconcat("allowed ", !strconcat(IntEnumAttr:intType.summary, !strconcat(" cases: ", !interleave(!foreach(case, IntEnumAttr:cases, case.value), ", ")))), IntEnumAttr:summary)>;
  string specializedAttrClassName = !strconcat(IntEnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
      return ::mlir::failure();
    auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
    if (maybeEnum)
      return *maybeEnum;
    return {(::mlir::LogicalResult)($_parser.emitError(loc) << "expected " }], !strconcat([{<< "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), [{)};
  }()}])))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
}
class IntEnumAttrBase<I IntEnumAttrBase:intType = ?, list<IntEnumAttrCaseBase> IntEnumAttrBase:cases = ?, string IntEnumAttrBase:summary = ?> {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase
  Pred predicate = And<[SignlessIntegerAttrBase<IntEnumAttrBase:intType, summary>.predicate, Or<!foreach(case, IntEnumAttrBase:cases, case.predicate)>]>;
  string summary = IntEnumAttrBase:summary;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(IntEnumAttrBase:intType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = IntEnumAttrBase:intType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntEnumAttrCaseBase<I IntEnumAttrCaseBase:intType = ?, string IntEnumAttrCaseBase:sym = ?, string IntEnumAttrCaseBase:strVal = ?, int IntEnumAttrCaseBase:intVal = ?> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase
  string symbol = IntEnumAttrCaseBase:sym;
  int value = IntEnumAttrCaseBase:intVal;
  string str = IntEnumAttrCaseBase:strVal;
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getInt() == ", !cast<string>(IntEnumAttrCaseBase:intVal))>;
  string summary = !strconcat("case ", IntEnumAttrCaseBase:strVal);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(IntEnumAttrCaseBase:intType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = IntEnumAttrCaseBase:intType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class IntMaxValue<int IntMaxValue:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getInt() <= ", !cast<string>(IntMaxValue:n))>;
  string summary = !strconcat("whose maximum value is ", !cast<string>(IntMaxValue:n));
}
class IntMinValue<int IntMinValue:n = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getInt() >= ", !cast<string>(IntMinValue:n))>;
  string summary = !strconcat("whose minimum value is ", !cast<string>(IntMinValue:n));
}
class Interface<string Interface:name = ?> {
  string description = "";
  string cppClassName = Interface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
}
class InterfaceMethod<string InterfaceMethod:desc = ?, string InterfaceMethod:retTy = ?, string InterfaceMethod:methodName = ?, dag InterfaceMethod:args = (ins), code InterfaceMethod:methodBody = [{}], code InterfaceMethod:defaultImplementation = [{}]> {
  string description = InterfaceMethod:desc;
  string name = InterfaceMethod:methodName;
  string returnType = InterfaceMethod:retTy;
  dag arguments = InterfaceMethod:args;
  string body = InterfaceMethod:methodBody;
  string defaultBody = InterfaceMethod:defaultImplementation;
}
class InterfaceTrait<string InterfaceTrait:name = ?> {	// Trait NativeTrait
  string trait = !strconcat(InterfaceTrait:name, "::Trait");
  string cppNamespace = "";
  string extraTraitClassDeclaration = "";
}
class IntrinsicResource<string IntrinsicResource:resourceName = ?> {	// Resource
  string name = !strconcat("::mlir::SideEffects::", IntrinsicResource:resourceName);
}
class IsFixedVectorOfLengthPred<list<int> IsFixedVectorOfLengthPred:allowedLengths = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsFixedVectorTypePred, Or<!foreach(allowedlength, IsFixedVectorOfLengthPred:allowedLengths, CPred<!strconcat([{$_self.cast<::mlir::VectorType>().getNumElements()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsScalableVectorOfLengthPred<list<int> IsScalableVectorOfLengthPred:allowedLengths = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsScalableVectorTypePred, Or<!foreach(allowedlength, IsScalableVectorOfLengthPred:allowedLengths, CPred<!strconcat([{$_self.cast<::mlir::VectorType>().getNumElements()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsVectorOfLengthPred<list<int> IsVectorOfLengthPred:allowedLengths = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, Or<!foreach(allowedlength, IsVectorOfLengthPred:allowedLengths, CPred<!strconcat([{$_self.cast<::mlir::VectorType>().getNumElements()
                           == }], !cast<string>(allowedlength))>)>];
}
class IsVectorOfRankPred<list<int> IsVectorOfRankPred:allowedRanks = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, Or<!foreach(allowedlength, IsVectorOfRankPred:allowedRanks, CPred<!strconcat([{$_self.cast<::mlir::VectorType>().getRank()
                           == }], !cast<string>(allowedlength))>)>];
}
class LLVM_CEnumAttr<string LLVM_CEnumAttr:name = ?, string LLVM_CEnumAttr:llvmNS = ?, string LLVM_CEnumAttr:description = ?, list<LLVM_EnumAttrCase> LLVM_CEnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo IntEnumAttr I64EnumAttr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = IntEnumAttrBase<I64, LLVM_CEnumAttr:cases, !if(!empty(LLVM_CEnumAttr:description), !strconcat("allowed ", !strconcat("64-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, LLVM_CEnumAttr:cases, case.value), ", ")))), LLVM_CEnumAttr:description)>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = LLVM_CEnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = LLVM_CEnumAttr:cases;
  string underlyingType = "uint64_t";
  string underlyingToSymbolFnName = !strconcat("symbolize", LLVM_CEnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", LLVM_CEnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", LLVM_CEnumAttr:name);
  string symbolToStringFnRetType = "::llvm::StringRef";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", LLVM_CEnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = IntEnumAttrBase<I64, LLVM_CEnumAttr:cases, !if(!empty(LLVM_CEnumAttr:description), !strconcat("allowed ", !strconcat("64-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, LLVM_CEnumAttr:cases, case.value), ", ")))), LLVM_CEnumAttr:description)>;
  string specializedAttrClassName = !strconcat(LLVM_CEnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
      return ::mlir::failure();
    auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
    if (maybeEnum)
      return *maybeEnum;
    return {(::mlir::LogicalResult)($_parser.emitError(loc) << "expected " }], !strconcat([{<< "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), [{)};
  }()}])))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
  string llvmClassName = LLVM_CEnumAttr:llvmNS;
}
class LLVM_EnumAttr<string LLVM_EnumAttr:name = ?, string LLVM_EnumAttr:llvmName = ?, string LLVM_EnumAttr:description = ?, list<LLVM_EnumAttrCase> LLVM_EnumAttr:cases = ?> {	// Constraint AttrConstraint Attr EnumAttrInfo IntEnumAttr I64EnumAttr
  Pred predicate = !if(genSpecializedAttr, CPred<!strconcat("$_self.isa<", !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, ">()"))))>, baseAttrClass.predicate);
  string summary = IntEnumAttrBase<I64, LLVM_EnumAttr:cases, !if(!empty(LLVM_EnumAttr:description), !strconcat("allowed ", !strconcat("64-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, LLVM_EnumAttr:cases, case.value), ", ")))), LLVM_EnumAttr:description)>.summary;
  string storageType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", specializedAttrClassName)), baseAttrClass.storageType);
  string returnType = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", className)), baseAttrClass.returnType);
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !if(genSpecializedAttr, !strconcat(cppNamespace, !strconcat("::", !strconcat(specializedAttrClassName, "::get($_builder.getContext(), $0)"))), baseAttrClass.constBuilderCall);
  string defaultValue = ?;
  Type valueType = baseAttrClass.valueType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string className = LLVM_EnumAttr:name;
  list<EnumAttrCaseInfo> enumerants = LLVM_EnumAttr:cases;
  string underlyingType = "uint64_t";
  string underlyingToSymbolFnName = !strconcat("symbolize", LLVM_EnumAttr:name);
  string stringToSymbolFnName = !strconcat("symbolize", LLVM_EnumAttr:name);
  string symbolToStringFnName = !strconcat("stringify", LLVM_EnumAttr:name);
  string symbolToStringFnRetType = "::llvm::StringRef";
  string maxEnumValFnName = !strconcat("getMaxEnumValFor", LLVM_EnumAttr:name);
  bit genSpecializedAttr = 1;
  Attr baseAttrClass = IntEnumAttrBase<I64, LLVM_EnumAttr:cases, !if(!empty(LLVM_EnumAttr:description), !strconcat("allowed ", !strconcat("64-bit signless integer", !strconcat(" cases: ", !interleave(!foreach(case, LLVM_EnumAttr:cases, case.value), ", ")))), LLVM_EnumAttr:description)>;
  string specializedAttrClassName = !strconcat(LLVM_EnumAttr:name, "Attr");
  string cppType = !strconcat(cppNamespace, !strconcat("::", className));
  string parameterParser = !strconcat([{[&]() -> ::mlir::FailureOr<}], !strconcat(cppType, !strconcat([{> {
    auto loc = $_parser.getCurrentLocation();
    ::llvm::StringRef enumKeyword;
    if (::mlir::failed($_parser.parseKeyword(&enumKeyword)))
      return ::mlir::failure();
    auto maybeEnum = }], !strconcat(cppNamespace, !strconcat("::", !strconcat(stringToSymbolFnName, !strconcat([{(enumKeyword);
    if (maybeEnum)
      return *maybeEnum;
    return {(::mlir::LogicalResult)($_parser.emitError(loc) << "expected " }], !strconcat([{<< "}], !strconcat(cppType, !strconcat([{" << " to be one of: " << }], !strconcat(!interleave(!foreach(enum, enumerants, !strconcat(""", !strconcat(enum.str, """))), [{ << ", " << }]), [{)};
  }()}])))))))))));
  string parameterPrinter = !strconcat("$_printer << ", !strconcat(symbolToStringFnName, "($_self)"));
  string llvmClassName = LLVM_EnumAttr:llvmName;
}
class LLVM_EnumAttrCase<string LLVM_EnumAttrCase:cppSym = ?, string LLVM_EnumAttrCase:irSym = ?, string LLVM_EnumAttrCase:llvmSym = ?, int LLVM_EnumAttrCase:val = ?> {	// EnumAttrCaseInfo Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase IntEnumAttrCaseBase I64EnumAttrCase
  string symbol = LLVM_EnumAttrCase:cppSym;
  int value = LLVM_EnumAttrCase:val;
  string str = LLVM_EnumAttrCase:irSym;
  Pred predicate = CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getInt() == ", !cast<string>(LLVM_EnumAttrCase:val))>;
  string summary = !strconcat("case ", LLVM_EnumAttrCase:irSym);
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  string llvmEnumerant = LLVM_EnumAttrCase:llvmSym;
}
class LLVM_IntPtrBase<int LLVM_IntPtrBase:width = ?, int LLVM_IntPtrBase:addressSpace = 0> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = LLVM_PointerTo<I<LLVM_IntPtrBase:width>>.predicate;
  string summary = !strconcat("LLVM pointer to ", I<LLVM_IntPtrBase:width>.summary);
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = !strconcat("::mlir::LLVM::LLVMPointerType::get(::mlir::IntegerType::get($_builder.getContext(), ", !strconcat(!cast<string>(LLVM_IntPtrBase:width), !strconcat("), ", !strconcat(!cast<string>(LLVM_IntPtrBase:addressSpace), ")"))));
}
class LLVM_IntrOp<string LLVM_IntrOp:mnem = ?, list<int> LLVM_IntrOp:overloadedResults = ?, list<int> LLVM_IntrOp:overloadedOperands = ?, list<Trait> LLVM_IntrOp:traits = ?, int LLVM_IntrOp:numResults = ?, bit LLVM_IntrOp:requiresAccessGroup = 0, bit LLVM_IntrOp:requiresAliasScope = 0> {	// Op LLVM_OpBase Results LLVM_IntrOpBase
  Dialect opDialect = LLVM_Dialect;
  string opName = !strconcat("intr.", LLVM_IntrOp:mnem);
  string cppNamespace = "::mlir::LLVM";
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = !if(!gt(LLVM_IntrOp:numResults, 0), (outs LLVM_Type:$res), (outs));
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = LLVM_IntrOp:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::}], !strconcat(!subst(".", "_", LLVM_IntrOp:mnem), !strconcat([{,
        { }], !strconcat(!interleave(!listconcat(ListIntSubst<resultPattern, LLVM_IntrOp:overloadedResults>.lst, ListIntSubst<[{moduleTranslation.convertType(opInst.getOperand($0).getType())}], LLVM_IntrOp:overloadedOperands>.lst), ", "), !strconcat([{
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    }], !strconcat([{auto *inst = builder.CreateCall(fn, operands);
    }], !strconcat(!if(!gt(LLVM_IntrOp:requiresAccessGroup, 0), "moduleTranslation.setAccessGroupsMetadata(op, inst);", "(void) inst;"), !strconcat(!if(!gt(LLVM_IntrOp:requiresAliasScope, 0), "moduleTranslation.setAliasScopeMetadata(op, inst);", "(void) inst;"), !if(!gt(LLVM_IntrOp:numResults, 0), "$res = inst;", "")))))))));
  string resultPattern = !if(!gt(LLVM_IntrOp:numResults, 1), [{moduleTranslation.convertType(
        opInst.getResult(0).getType().cast<LLVM::LLVMStructType>()
              .getBody()[$0])}], [{moduleTranslation.convertType(opInst.getResult($0).getType())}]);
  string llvmEnumName = !subst(".", "_", LLVM_IntrOp:mnem);
}
class LLVM_IntrOpBase<Dialect LLVM_IntrOpBase:dialect = ?, string LLVM_IntrOpBase:opName = ?, string LLVM_IntrOpBase:enumName = ?, list<int> LLVM_IntrOpBase:overloadedResults = ?, list<int> LLVM_IntrOpBase:overloadedOperands = ?, list<Trait> LLVM_IntrOpBase:traits = ?, int LLVM_IntrOpBase:numResults = ?, bit LLVM_IntrOpBase:requiresAccessGroup = 0, bit LLVM_IntrOpBase:requiresAliasScope = 0> {	// Op LLVM_OpBase Results
  Dialect opDialect = LLVM_IntrOpBase:dialect;
  string opName = LLVM_IntrOpBase:opName;
  string cppNamespace = LLVM_IntrOpBase:dialect.cppNamespace;
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = !if(!gt(LLVM_IntrOpBase:numResults, 0), (outs LLVM_Type:$res), (outs));
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = LLVM_IntrOpBase:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::}], !strconcat(LLVM_IntrOpBase:enumName, !strconcat([{,
        { }], !strconcat(!interleave(!listconcat(ListIntSubst<resultPattern, LLVM_IntrOpBase:overloadedResults>.lst, ListIntSubst<[{moduleTranslation.convertType(opInst.getOperand($0).getType())}], LLVM_IntrOpBase:overloadedOperands>.lst), ", "), !strconcat([{
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    }], !strconcat([{auto *inst = builder.CreateCall(fn, operands);
    }], !strconcat(!if(!gt(LLVM_IntrOpBase:requiresAccessGroup, 0), "moduleTranslation.setAccessGroupsMetadata(op, inst);", "(void) inst;"), !strconcat(!if(!gt(LLVM_IntrOpBase:requiresAliasScope, 0), "moduleTranslation.setAliasScopeMetadata(op, inst);", "(void) inst;"), !if(!gt(LLVM_IntrOpBase:numResults, 0), "$res = inst;", "")))))))));
  string resultPattern = !if(!gt(LLVM_IntrOpBase:numResults, 1), [{moduleTranslation.convertType(
        opInst.getResult(0).getType().cast<LLVM::LLVMStructType>()
              .getBody()[$0])}], [{moduleTranslation.convertType(opInst.getResult($0).getType())}]);
  string llvmEnumName = LLVM_IntrOpBase:enumName;
}
class LLVM_OneResultIntrOp<string LLVM_OneResultIntrOp:mnem = ?, list<int> LLVM_OneResultIntrOp:overloadedResults = [], list<int> LLVM_OneResultIntrOp:overloadedOperands = [], list<Trait> LLVM_OneResultIntrOp:traits = []> {	// Op LLVM_OpBase Results LLVM_IntrOpBase LLVM_IntrOp
  Dialect opDialect = LLVM_Dialect;
  string opName = !strconcat("intr.", LLVM_OneResultIntrOp:mnem);
  string cppNamespace = "::mlir::LLVM";
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = LLVM_OneResultIntrOp:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::}], !strconcat(!subst(".", "_", LLVM_OneResultIntrOp:mnem), !strconcat([{,
        { }], !strconcat(!interleave(!listconcat(ListIntSubst<resultPattern, LLVM_OneResultIntrOp:overloadedResults>.lst, ListIntSubst<[{moduleTranslation.convertType(opInst.getOperand($0).getType())}], LLVM_OneResultIntrOp:overloadedOperands>.lst), ", "), [{
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}]))));
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = !subst(".", "_", LLVM_OneResultIntrOp:mnem);
}
class LLVM_Op<string LLVM_Op:mnemonic = ?, list<Trait> LLVM_Op:traits = []> {	// Op LLVM_OpBase
  Dialect opDialect = LLVM_Dialect;
  string opName = LLVM_Op:mnemonic;
  string cppNamespace = "::mlir::LLVM";
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = LLVM_Op:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = "";
}
class LLVM_OpBase<Dialect LLVM_OpBase:dialect = ?, string LLVM_OpBase:mnemonic = ?, list<Trait> LLVM_OpBase:traits = []> {	// Op
  Dialect opDialect = LLVM_OpBase:dialect;
  string opName = LLVM_OpBase:mnemonic;
  string cppNamespace = LLVM_OpBase:dialect.cppNamespace;
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = LLVM_OpBase:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = "";
}
class LLVM_PointerTo<Type LLVM_PointerTo:pointee = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[anonymous_290, Or<[anonymous_291, SubstLeaves<"$_self", "$_self.cast<::mlir::LLVM::LLVMPointerType>().getElementType()", LLVM_PointerTo:pointee.predicate>]>]>;
  string summary = !strconcat("LLVM pointer to ", LLVM_PointerTo:pointee.summary);
  string cppClassName = "::mlir::LLVM::LLVMPointerType";
  string description = "";
  string builderCall = "";
}
class LLVM_ScalarOrVectorOf<Type LLVM_ScalarOrVectorOf:element = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<[LLVM_ScalarOrVectorOf:element.predicate, LLVM_VectorOf<LLVM_ScalarOrVectorOf:element>.predicate]>;
  string summary = !interleave([LLVM_ScalarOrVectorOf:element.summary, LLVM_VectorOf<LLVM_ScalarOrVectorOf:element>.summary], " or ");
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class LLVM_VectorOf<Type LLVM_VectorOf:element = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[anonymous_307, SubstLeaves<"$_self", "::mlir::LLVM::getVectorElementType($_self)", LLVM_VectorOf:element.predicate>]>;
  string summary = !strconcat("LLVM dialect-compatible vector of ", LLVM_VectorOf:element.summary);
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class LLVM_VectorReduction<string LLVM_VectorReduction:mnem = ?> {	// Op LLVM_OpBase Results LLVM_IntrOpBase LLVM_IntrOp LLVM_OneResultIntrOp Arguments
  Dialect opDialect = LLVM_Dialect;
  string opName = !strconcat("intr.", !strconcat("vector.reduce.", LLVM_VectorReduction:mnem));
  string cppNamespace = "::mlir::LLVM";
  string summary = "";
  string description = "";
  dag arguments = (ins LLVM_Type);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [NoSideEffect];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::}], !strconcat(!subst(".", "_", !strconcat("vector.reduce.", LLVM_VectorReduction:mnem)), !strconcat([{,
        { }], !strconcat(!interleave(!listconcat(ListIntSubst<resultPattern, []>.lst, ["moduleTranslation.convertType(opInst.getOperand(0).getType())"]), ", "), [{
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}]))));
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = !subst(".", "_", !strconcat("vector.reduce.", LLVM_VectorReduction:mnem));
}
class LLVM_VectorReductionAcc<string LLVM_VectorReductionAcc:mnem = ?> {	// Op LLVM_OpBase Results Arguments
  Dialect opDialect = LLVM_Dialect;
  string opName = !strconcat("intr.vector.reduce.", LLVM_VectorReductionAcc:mnem);
  string cppNamespace = "::mlir::LLVM";
  string summary = "";
  string description = "";
  dag arguments = (ins LLVM_Type, LLVM_Type, anonymous_309:$reassoc);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [NoSideEffect];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::vector_reduce_}], !strconcat(LLVM_VectorReductionAcc:mnem, [{,
        { moduleTranslation.convertType(opInst.getOperand(1).getType())
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    llvm::FastMathFlags origFM = builder.getFastMathFlags();
    llvm::FastMathFlags tempFM = origFM;
    tempFM.setAllowReassoc($reassoc);
    builder.setFastMathFlags(tempFM);  // set fastmath flag
    $res = builder.CreateCall(fn, operands);
    builder.setFastMathFlags(origFM);  // restore fastmath flag
  }]));
}
class LLVM_ZeroResultIntrOp<string LLVM_ZeroResultIntrOp:mnem = ?, list<int> LLVM_ZeroResultIntrOp:overloadedOperands = [], list<Trait> LLVM_ZeroResultIntrOp:traits = []> {	// Op LLVM_OpBase Results LLVM_IntrOpBase LLVM_IntrOp
  Dialect opDialect = LLVM_Dialect;
  string opName = !strconcat("intr.", LLVM_ZeroResultIntrOp:mnem);
  string cppNamespace = "::mlir::LLVM";
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = LLVM_ZeroResultIntrOp:traits;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  string llvmBuilder = !strconcat([{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::}], !strconcat(!subst(".", "_", LLVM_ZeroResultIntrOp:mnem), !strconcat([{,
        { }], !strconcat(!interleave(!listconcat(ListIntSubst<resultPattern, []>.lst, ListIntSubst<[{moduleTranslation.convertType(opInst.getOperand($0).getType())}], LLVM_ZeroResultIntrOp:overloadedOperands>.lst), ", "), [{
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;}]))));
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = !subst(".", "_", LLVM_ZeroResultIntrOp:mnem);
}
class ListIntSubst<string ListIntSubst:pattern = ?, list<int> ListIntSubst:values = ?> {
  list<string> lst = !foreach(x, ListIntSubst:values, !subst("$0", !cast<string>(x), ListIntSubst:pattern));
}
class MemAlloc<Resource MemAlloc:resource = ?> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Allocate";
  string resource = MemAlloc:resource.name;
}
class MemFree<Resource MemFree:resource = ?> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Free";
  string resource = MemFree:resource.name;
}
class MemRead<Resource MemRead:resource = ?> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Read";
  string resource = MemRead:resource.name;
}
class MemRefOf<list<Type> MemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsMemRefTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<MemRefOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("memref", !strconcat(" of ", !strconcat(AnyTypeOf<MemRefOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class MemRefRankOf<list<Type> MemRefRankOf:allowedTypes = ?, list<int> MemRefRankOf:ranks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[MemRefOf<MemRefRankOf:allowedTypes>.predicate, HasAnyRankOfPred<MemRefRankOf:ranks>]>;
  string summary = !strconcat(!interleave(!foreach(rank, MemRefRankOf:ranks, !strconcat(!cast<string>(rank), "D")), "/"), !strconcat(" ", MemRefOf<MemRefRankOf:allowedTypes>.summary));
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class MemWrite<Resource MemWrite:resource = ?> {	// OpVariableDecorator SideEffect MemoryEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Write";
  string resource = MemWrite:resource.name;
}
class MemoryEffect<string MemoryEffect:effectName = ?, Resource MemoryEffect:resource = ?> {	// OpVariableDecorator SideEffect
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = MemoryEffect:effectName;
  string resource = MemoryEffect:resource.name;
}
class MemoryEffects<list<MemoryEffect> MemoryEffects:effects = []> {	// Trait NativeTrait InterfaceTrait OpInterfaceTrait SideEffectsTraitBase
  string trait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  list<SideEffect> effects = MemoryEffects:effects;
}
class MinSizedRegion<int MinSizedRegion:numBlocks = ?> {	// Constraint RegionConstraint Region
  Pred predicate = CPred<!strconcat("::llvm::hasNItemsOrMore($_self, ", !strconcat(!cast<string>(MinSizedRegion:numBlocks), ")"))>;
  string summary = !strconcat("region with at least ", !strconcat(!cast<string>(MinSizedRegion:numBlocks), " blocks"));
}
class MixedContainerType<Type MixedContainerType:etype = ?, Pred MixedContainerType:containerPred = ?, string MixedContainerType:elementTypesCall = ?, string MixedContainerType:descr = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[MixedContainerType:containerPred, Concat<!strconcat("::llvm::all_of(", !strconcat(MixedContainerType:elementTypesCall, ", [](Type t) { return t && (")), SubstLeaves<"$_self", "t", MixedContainerType:etype.predicate>, "); })">]>;
  string summary = !strconcat(MixedContainerType:descr, !strconcat(" with any combination of ", !strconcat(MixedContainerType:etype.summary, " values")));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Type elementType = MixedContainerType:etype;
  string getElementTypesCall = MixedContainerType:elementTypesCall;
}
class NativeAttrTrait<string NativeAttrTrait:name = ?> {	// Trait NativeTrait
  string trait = NativeAttrTrait:name;
  string cppNamespace = "::mlir::AttributeTrait";
}
class NativeOpTrait<string NativeOpTrait:name = ?, list<Trait> NativeOpTrait:traits = []> {	// Trait NativeTrait
  string trait = NativeOpTrait:name;
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = NativeOpTrait:traits;
}
class NativeTrait<string NativeTrait:name = ?, string NativeTrait:entityType = ?> {	// Trait
  string trait = NativeTrait:name;
  string cppNamespace = !strconcat("::mlir::", !strconcat(NativeTrait:entityType, "Trait"));
}
class NativeTypeTrait<string NativeTypeTrait:name = ?> {	// Trait NativeTrait
  string trait = NativeTypeTrait:name;
  string cppNamespace = "::mlir::TypeTrait";
}
class Neg<Pred Neg:child = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerNot;
  list<Pred> children = [Neg:child];
}
class NestedTupleOf<list<Type> NestedTupleOf:allowedTypes = ?> {	// Constraint TypeConstraint Type MixedContainerType
  Pred predicate = And<[IsTupleTypePred, Concat<"::llvm::all_of(getFlattenedTypes($_self.cast<::mlir::TupleType>()), [](Type t) { return t && (", SubstLeaves<"$_self", "t", AnyTypeOf<NestedTupleOf:allowedTypes>.predicate>, "); })">]>;
  string summary = !strconcat("nested tuple", !strconcat(" with any combination of ", !strconcat(AnyTypeOf<NestedTupleOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Type elementType = AnyTypeOf<NestedTupleOf:allowedTypes>;
  string getElementTypesCall = "getFlattenedTypes($_self.cast<::mlir::TupleType>())";
}
class Op<Dialect Op:dialect = ?, string Op:mnemonic = ?, list<Trait> Op:props = []> {
  Dialect opDialect = Op:dialect;
  string opName = Op:mnemonic;
  string cppNamespace = Op:dialect.cppNamespace;
  string summary = "";
  string description = "";
  dag arguments = (ins);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = Op:props;
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
}
class OpBuilder<dag OpBuilder:p = ?, string OpBuilder:b = ""> {
  dag dagParams = OpBuilder:p;
  string body = OpBuilder:b;
}
class OpInterface<string OpInterface:name = ?> {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait
  string description = "";
  string cppClassName = OpInterface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(OpInterface:name, "::Trait");
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
}
class OpInterfaceTrait<string OpInterfaceTrait:name = ?, code OpInterfaceTrait:verifyBody = [{}], list<Trait> OpInterfaceTrait:traits = []> {	// Trait NativeTrait InterfaceTrait
  string trait = !strconcat(OpInterfaceTrait:name, "::Trait");
  string cppNamespace = "";
  string extraTraitClassDeclaration = "";
  string verify = OpInterfaceTrait:verifyBody;
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = OpInterfaceTrait:traits;
}
class OpVariable<Constraint OpVariable:varConstraint = ?, string OpVariable:desc = "", list<OpVariableDecorator> OpVariable:varDecorators = []> {
  Constraint constraint = OpVariable:varConstraint;
  string summary = OpVariable:desc;
  list<OpVariableDecorator> decorators = OpVariable:varDecorators;
}
class OpVariableDecorator {
}
class OpaqueType<string OpaqueType:dialect = ?, string OpaqueType:name = ?, string OpaqueType:summary = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<!strconcat("isOpaqueTypeWithName($_self, "", !strconcat(OpaqueType:dialect, !strconcat("", "", !strconcat(OpaqueType:name, "")"))))>;
  string summary = OpaqueType:summary;
  string cppClassName = "::mlir::OpaqueType";
  string description = "";
  string builderCall = !strconcat("::mlir::OpaqueType::get($_builder.getStringAttr("", !strconcat(OpaqueType:dialect, !strconcat(""), "", !strconcat(OpaqueType:name, "")"))));
}
class Optional<Type Optional:type = ?> {	// Constraint TypeConstraint
  Pred predicate = Optional:type.predicate;
  string summary = Optional:type.summary;
  string cppClassName = Optional:type.cppClassName;
  Type baseType = Optional:type;
}
class OptionalAttr<Attr OptionalAttr:attr = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = OptionalAttr:attr.predicate;
  string summary = OptionalAttr:attr.summary;
  string storageType = OptionalAttr:attr.storageType;
  string returnType = !strconcat("::llvm::Optional<", !strconcat(OptionalAttr:attr.returnType, ">"));
  string convertFromStorage = !strconcat("$_self ? ", !strconcat(returnType, !strconcat("(", !strconcat(OptionalAttr:attr.convertFromStorage, ") : (::llvm::None)"))));
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = OptionalAttr:attr.valueType;
  bit isOptional = 1;
  Attr baseAttr = OptionalAttr:attr;
  string cppNamespace = "";
  string description = "";
}
class OptionalParameter<string OptionalParameter:type = ?, string OptionalParameter:desc = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = OptionalParameter:type;
  string cppAccessorType = OptionalParameter:type;
  string cppStorageType = ?;
  string summary = OptionalParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 1;
  string defaultValue = ?;
}
class Or<list<Pred> Or:children = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = Or:children;
}
class ParamNativeAttrTrait<string ParamNativeAttrTrait:prop = ?, string ParamNativeAttrTrait:params = ?> {	// Trait NativeTrait ParamNativeTrait
  string trait = !strconcat(ParamNativeAttrTrait:prop, !strconcat("<", !strconcat(ParamNativeAttrTrait:params, ">::Impl")));
  string cppNamespace = "::mlir::AttributeTrait";
}
class ParamNativeOpTrait<string ParamNativeOpTrait:prop = ?, string ParamNativeOpTrait:params = ?, list<Trait> ParamNativeOpTrait:traits = []> {	// Trait NativeTrait ParamNativeTrait
  string trait = !strconcat(ParamNativeOpTrait:prop, !strconcat("<", !strconcat(ParamNativeOpTrait:params, ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = ParamNativeOpTrait:traits;
}
class ParamNativeTrait<string ParamNativeTrait:prop = ?, string ParamNativeTrait:params = ?, string ParamNativeTrait:entityType = ?> {	// Trait NativeTrait
  string trait = !strconcat(ParamNativeTrait:prop, !strconcat("<", !strconcat(ParamNativeTrait:params, ">::Impl")));
  string cppNamespace = !strconcat("::mlir::", !strconcat(ParamNativeTrait:entityType, "Trait"));
}
class ParamNativeTypeTrait<string ParamNativeTypeTrait:prop = ?, string ParamNativeTypeTrait:params = ?> {	// Trait NativeTrait ParamNativeTrait
  string trait = !strconcat(ParamNativeTypeTrait:prop, !strconcat("<", !strconcat(ParamNativeTypeTrait:params, ">::Impl")));
  string cppNamespace = "::mlir::TypeTrait";
}
class ParentOneOf<list<string> ParentOneOf:ops = ?> {	// Trait NativeTrait ParamNativeTrait ParamNativeOpTrait StructuralOpTrait
  string trait = !strconcat("HasParent", !strconcat("<", !strconcat(!interleave(ParentOneOf:ops, ", "), ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
class Pred {
}
class PredAttrTrait<string PredAttrTrait:descr = ?, Pred PredAttrTrait:pred = ?> {	// Trait PredTrait
  string summary = PredAttrTrait:descr;
  Pred predicate = PredAttrTrait:pred;
}
class PredCombinerKind {
}
class PredOpTrait<string PredOpTrait:descr = ?, Pred PredOpTrait:pred = ?, list<Trait> PredOpTrait:traits = []> {	// Trait PredTrait
  string summary = PredOpTrait:descr;
  Pred predicate = PredOpTrait:pred;
  list<Trait> dependentTraits = PredOpTrait:traits;
}
class PredTrait<string PredTrait:descr = ?, Pred PredTrait:pred = ?> {	// Trait
  string summary = PredTrait:descr;
  Pred predicate = PredTrait:pred;
}
class PredTypeTrait<string PredTypeTrait:descr = ?, Pred PredTypeTrait:pred = ?> {	// Trait PredTrait
  string summary = PredTypeTrait:descr;
  Pred predicate = PredTypeTrait:pred;
}
class RangedTypesMatchWith<string RangedTypesMatchWith:summary = ?, string RangedTypesMatchWith:lhsArg = ?, string RangedTypesMatchWith:rhsArg = ?, string RangedTypesMatchWith:transform = ?> {	// Trait PredTrait PredOpTrait TypesMatchWith
  string summary = RangedTypesMatchWith:summary;
  Pred predicate = CPred<!strconcat("llvm::equal", !strconcat("(", !strconcat(!subst("$_self", !strconcat("$", !strconcat(RangedTypesMatchWith:lhsArg, ".getType()")), RangedTypesMatchWith:transform), !strconcat(", $", !strconcat(RangedTypesMatchWith:rhsArg, ".getType())")))))>;
  list<Trait> dependentTraits = [];
  string lhs = RangedTypesMatchWith:lhsArg;
  string rhs = RangedTypesMatchWith:rhsArg;
  string transformer = RangedTypesMatchWith:transform;
}
class Rank<string Rank:name = ?> {	// StrFunc
  string result = !strconcat("$", !strconcat(Rank:name, ".getType().cast<::mlir::ShapedType>().getRank()"));
}
class RankedF32ElementsAttr<list<int> RankedF32ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase RankedFloatElementsAttr
  Pred predicate = CPred<!strconcat("$_self.isa<::mlir::DenseFPElementsAttr>() &&$_self.cast<::mlir::DenseFPElementsAttr>().getType().getElementType().isF", !strconcat("32", !strconcat("() && $_self.cast<::mlir::DenseFPElementsAttr>().getType().hasRank() && $_self.cast<::mlir::DenseFPElementsAttr>().getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedF32ElementsAttr:dims, ", "), "})"))))>;
  string summary = !strconcat("32", !strconcat("-bit float elements attribute of shape [", !strconcat(!interleave(RankedF32ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseFPElementsAttr }];
  code returnType = [{ ::mlir::DenseFPElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedF32ElementsAttr:dims, ", "), "}, $_builder.getF32Type()), ::llvm::makeArrayRef($0)).cast<::mlir::DenseFPElementsAttr>()"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedF64ElementsAttr<list<int> RankedF64ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase RankedFloatElementsAttr
  Pred predicate = CPred<!strconcat("$_self.isa<::mlir::DenseFPElementsAttr>() &&$_self.cast<::mlir::DenseFPElementsAttr>().getType().getElementType().isF", !strconcat("64", !strconcat("() && $_self.cast<::mlir::DenseFPElementsAttr>().getType().hasRank() && $_self.cast<::mlir::DenseFPElementsAttr>().getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedF64ElementsAttr:dims, ", "), "})"))))>;
  string summary = !strconcat("64", !strconcat("-bit float elements attribute of shape [", !strconcat(!interleave(RankedF64ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseFPElementsAttr }];
  code returnType = [{ ::mlir::DenseFPElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedF64ElementsAttr:dims, ", "), "}, $_builder.getF64Type()), ::llvm::makeArrayRef($0)).cast<::mlir::DenseFPElementsAttr>()"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedFloatElementsAttr<int RankedFloatElementsAttr:width = ?, list<int> RankedFloatElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = CPred<!strconcat("$_self.isa<::mlir::DenseFPElementsAttr>() &&$_self.cast<::mlir::DenseFPElementsAttr>().getType().getElementType().isF", !strconcat(!cast<string>(RankedFloatElementsAttr:width), !strconcat("() && $_self.cast<::mlir::DenseFPElementsAttr>().getType().hasRank() && $_self.cast<::mlir::DenseFPElementsAttr>().getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedFloatElementsAttr:dims, ", "), "})"))))>;
  string summary = !strconcat(!cast<string>(RankedFloatElementsAttr:width), !strconcat("-bit float elements attribute of shape [", !strconcat(!interleave(RankedFloatElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseFPElementsAttr }];
  code returnType = [{ ::mlir::DenseFPElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedFloatElementsAttr:dims, ", "), !strconcat("}, $_builder.getF", !strconcat(!cast<string>(RankedFloatElementsAttr:width), "Type()), ::llvm::makeArrayRef($0)).cast<::mlir::DenseFPElementsAttr>()"))));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedI32ElementsAttr<list<int> RankedI32ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr RankedSignlessIntElementsAttr
  Pred predicate = And<[anonymous_228, CPred<!strconcat("$_self.cast<::mlir::DenseIntElementsAttr>().getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedI32ElementsAttr:dims, ", "), "})"))>]>;
  string summary = !strconcat("32", !strconcat("-bit signless int elements attribute of shape [", !strconcat(!interleave(RankedI32ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseIntElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedI32ElementsAttr:dims, ", "), "}, $_builder.getIntegerType(32)), ::llvm::makeArrayRef($0))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedI64ElementsAttr<list<int> RankedI64ElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr RankedSignlessIntElementsAttr
  Pred predicate = And<[anonymous_230, CPred<!strconcat("$_self.cast<::mlir::DenseIntElementsAttr>().getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedI64ElementsAttr:dims, ", "), "})"))>]>;
  string summary = !strconcat("64", !strconcat("-bit signless int elements attribute of shape [", !strconcat(!interleave(RankedI64ElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseIntElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedI64ElementsAttr:dims, ", "), "}, $_builder.getIntegerType(64)), ::llvm::makeArrayRef($0))"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedOrUnrankedMemRefOf<list<Type> RankedOrUnrankedMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<[UnrankedMemRefOf<RankedOrUnrankedMemRefOf:allowedTypes>.predicate, MemRefOf<RankedOrUnrankedMemRefOf:allowedTypes>.predicate]>;
  string summary = !interleave([UnrankedMemRefOf<RankedOrUnrankedMemRefOf:allowedTypes>.summary, MemRefOf<RankedOrUnrankedMemRefOf:allowedTypes>.summary], " or ");
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class RankedSignlessIntElementsAttr<int RankedSignlessIntElementsAttr:width = ?, list<int> RankedSignlessIntElementsAttr:dims = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = And<[SignlessIntElementsAttr<RankedSignlessIntElementsAttr:width>.predicate, CPred<!strconcat("$_self.cast<::mlir::DenseIntElementsAttr>().getType().getShape() == ::mlir::ArrayRef<int64_t>({", !strconcat(!interleave(RankedSignlessIntElementsAttr:dims, ", "), "})"))>]>;
  string summary = !strconcat(!cast<string>(RankedSignlessIntElementsAttr:width), !strconcat("-bit signless int elements attribute of shape [", !strconcat(!interleave(RankedSignlessIntElementsAttr:dims, ", "), "]")));
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseIntElementsAttr::get(::mlir::RankedTensorType::get({", !strconcat(!interleave(RankedSignlessIntElementsAttr:dims, ", "), !strconcat("}, $_builder.getIntegerType(", !strconcat(!cast<string>(RankedSignlessIntElementsAttr:width), ")), ::llvm::makeArrayRef($0))"))));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class RankedTensorOf<list<Type> RankedTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[anonymous_48, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<RankedTensorOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("ranked tensor", !strconcat(" of ", !strconcat(AnyTypeOf<RankedTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class ReferToOp<string ReferToOp:opClass = ?> {	// Constraint AttrConstraint
  Pred predicate = CPred<!strconcat("isa_and_nonnull<", !strconcat(ReferToOp:opClass, ">(::mlir::SymbolTable::lookupNearestSymbolFrom(&$_op, $_self.cast<::mlir::FlatSymbolRefAttr>().getAttr()))"))>;
  string summary = !strconcat("referencing to a '", !strconcat(ReferToOp:opClass, "' symbol"));
}
class Region<Pred Region:condition = ?, string Region:descr = ""> {	// Constraint RegionConstraint
  Pred predicate = Region:condition;
  string summary = Region:descr;
}
class RegionConstraint<Pred RegionConstraint:predicate = ?, string RegionConstraint:summary = ""> {	// Constraint
  Pred predicate = RegionConstraint:predicate;
  string summary = RegionConstraint:summary;
}
class Res<Constraint Res:constraint = ?, string Res:desc = "", list<OpVariableDecorator> Res:decorators = []> {	// OpVariable
  Constraint constraint = Res:constraint;
  string summary = Res:desc;
  list<OpVariableDecorator> decorators = Res:decorators;
}
class Resource<string Resource:resourceName = ?> {
  string name = Resource:resourceName;
}
class Results<dag Results:rets = ?> {
  dag results = Results:rets;
}
class SI<int SI:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<!strconcat("$_self.isSignedInteger(", !strconcat(!cast<string>(SI:width), ")"))>;
  string summary = !strconcat(!cast<string>(SI:width), "-bit signed integer");
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = !strconcat("$_builder.getIntegerType(", !strconcat(!cast<string>(SI:width), ", /*isSigned=*/true)"));
  int bitwidth = SI:width;
}
class SameBuildabilityAs<Type SameBuildabilityAs:type = ?, string SameBuildabilityAs:builder = ?> {
  string builderCall = !if(!empty(SameBuildabilityAs:type.builderCall), "", SameBuildabilityAs:builder);
}
class ScalableVectorOf<list<Type> ScalableVectorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsScalableVectorTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<ScalableVectorOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("scalable vector", !strconcat(" of ", !strconcat(AnyTypeOf<ScalableVectorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class ScalableVectorOfLength<list<int> ScalableVectorOfLength:allowedLengths = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsScalableVectorOfLengthPred<ScalableVectorOfLength:allowedLengths>;
  string summary = !strconcat(" of length ", !interleave(ScalableVectorOfLength:allowedLengths, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class ScalableVectorOfLengthAndType<list<int> ScalableVectorOfLengthAndType:allowedLengths = ?, list<Type> ScalableVectorOfLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[ScalableVectorOf<ScalableVectorOfLengthAndType:allowedTypes>.predicate, ScalableVectorOfLength<ScalableVectorOfLengthAndType:allowedLengths>.predicate]>;
  string summary = !strconcat(ScalableVectorOf<ScalableVectorOfLengthAndType:allowedTypes>.summary, ScalableVectorOfLength<ScalableVectorOfLengthAndType:allowedLengths>.summary);
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class SelfAllocationParameter<string SelfAllocationParameter:type = ?, string SelfAllocationParameter:desc = ?> {	// AttrOrTypeParameter
  code allocator = [{$_dst = $_self.allocateInto($_allocator);}];
  string comparator = ?;
  string cppType = SelfAllocationParameter:type;
  string cppAccessorType = SelfAllocationParameter:type;
  string cppStorageType = ?;
  string summary = SelfAllocationParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class Shape<string Shape:name = ?> {	// StrFunc
  string result = !strconcat("$", !strconcat(Shape:name, ".getType().cast<::mlir::ShapedType>().getShape()"));
}
class ShapedContainerType<list<Type> ShapedContainerType:allowedTypes = ?, Pred ShapedContainerType:containerPred = ?, string ShapedContainerType:descr = ?, string ShapedContainerType:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint Type
  Pred predicate = And<[ShapedContainerType:containerPred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<ShapedContainerType:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat(ShapedContainerType:descr, !strconcat(" of ", !strconcat(AnyTypeOf<ShapedContainerType:allowedTypes>.summary, " values")));
  string cppClassName = ShapedContainerType:cppClassName;
  string description = "";
  string builderCall = "";
}
class SideEffect<EffectOpInterfaceBase SideEffect:interface = ?, string SideEffect:effectName = ?, Resource SideEffect:resourceReference = ?> {	// OpVariableDecorator
  string baseEffectName = SideEffect:interface.baseEffectName;
  string interfaceTrait = SideEffect:interface.trait;
  string cppNamespace = SideEffect:interface.cppNamespace;
  string effect = SideEffect:effectName;
  string resource = SideEffect:resourceReference.name;
}
class SideEffectsTraitBase<EffectOpInterfaceBase SideEffectsTraitBase:parentInterface = ?, list<SideEffect> SideEffectsTraitBase:staticEffects = ?> {	// Trait NativeTrait InterfaceTrait OpInterfaceTrait
  string trait = SideEffectsTraitBase:parentInterface.trait;
  string cppNamespace = SideEffectsTraitBase:parentInterface.cppNamespace;
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = SideEffectsTraitBase:parentInterface.baseEffectName;
  list<SideEffect> effects = SideEffectsTraitBase:staticEffects;
}
class SignedIntOfWidths<list<int> SignedIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<!foreach(allowedtype, !foreach(w, SignedIntOfWidths:widths, SI<w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(SignedIntOfWidths:widths, "/"), "-bit signed integer"), ""), !interleave(!foreach(t, !foreach(w, SignedIntOfWidths:widths, SI<w>), t.summary), " or "), !strconcat(!interleave(SignedIntOfWidths:widths, "/"), "-bit signed integer"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class SignedIntegerAttrBase<SI SignedIntegerAttrBase:attrValType = ?, string SignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(", !strconcat(!cast<string>(SignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = SignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(SignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = SignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class SignlessIntElementsAttr<int SignlessIntElementsAttr:width = ?> {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = And<[anonymous_219, CPred<!strconcat("$_self.cast<::mlir::DenseIntElementsAttr>().getType().getElementType().isSignlessInteger(", !strconcat(!cast<string>(SignlessIntElementsAttr:width), ")"))>]>;
  string summary = !strconcat(!cast<string>(SignlessIntElementsAttr:width), "-bit signless integer elements attribute");
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = !strconcat("::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(", !strconcat(!cast<string>(SignlessIntElementsAttr:width), ")), ::llvm::makeArrayRef($0)).cast<::mlir::DenseIntElementsAttr>()"));
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class SignlessIntOfWidths<list<int> SignlessIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<!foreach(allowedtype, !foreach(w, SignlessIntOfWidths:widths, I<w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(SignlessIntOfWidths:widths, "/"), "-bit signless integer"), ""), !interleave(!foreach(t, !foreach(w, SignlessIntOfWidths:widths, I<w>), t.summary), " or "), !strconcat(!interleave(SignlessIntOfWidths:widths, "/"), "-bit signless integer"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class SignlessIntegerAttrBase<I SignlessIntegerAttrBase:attrValType = ?, string SignlessIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(", !strconcat(!cast<string>(SignlessIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = SignlessIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(SignlessIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = SignlessIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class SingleBlockImplicitTerminator<string SingleBlockImplicitTerminator:op = ?> {	// Trait NativeTrait ParamNativeTrait ParamNativeOpTrait StructuralOpTrait
  string trait = !strconcat("SingleBlockImplicitTerminator", !strconcat("<", !strconcat(SingleBlockImplicitTerminator:op, ">::Impl")));
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
class SizedRegion<int SizedRegion:numBlocks = ?> {	// Constraint RegionConstraint Region
  Pred predicate = CPred<!strconcat("::llvm::hasNItems($_self, ", !strconcat(!cast<string>(SizedRegion:numBlocks), ")"))>;
  string summary = !strconcat("region with ", !strconcat(!cast<string>(SizedRegion:numBlocks), " blocks"));
}
class StaticInterfaceMethod<string StaticInterfaceMethod:desc = ?, string StaticInterfaceMethod:retTy = ?, string StaticInterfaceMethod:methodName = ?, dag StaticInterfaceMethod:args = (ins), code StaticInterfaceMethod:methodBody = [{}], code StaticInterfaceMethod:defaultImplementation = [{}]> {	// InterfaceMethod
  string description = StaticInterfaceMethod:desc;
  string name = StaticInterfaceMethod:methodName;
  string returnType = StaticInterfaceMethod:retTy;
  dag arguments = StaticInterfaceMethod:args;
  string body = StaticInterfaceMethod:methodBody;
  string defaultBody = StaticInterfaceMethod:defaultImplementation;
}
class StaticShapeMemRefOf<list<Type> StaticShapeMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[MemRefOf<StaticShapeMemRefOf:allowedTypes>.predicate, HasStaticShapePred]>;
  string summary = !strconcat("statically shaped ", MemRefOf<StaticShapeMemRefOf:allowedTypes>.summary);
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
class StaticShapeTensorOf<list<Type> StaticShapeTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[TensorOf<StaticShapeTensorOf:allowedTypes>.predicate, HasStaticShapePred]>;
  string summary = !strconcat("statically shaped ", TensorOf<StaticShapeTensorOf:allowedTypes>.summary);
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class StrFunc<string StrFunc:r = ?> {
  string result = StrFunc:r;
}
class StridedMemRefOf<list<Type> StridedMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[MemRefOf<StridedMemRefOf:allowedTypes>.predicate, HasStridesPred]>;
  string summary = !strconcat("strided ", MemRefOf<StridedMemRefOf:allowedTypes>.summary);
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class StridedMemRefRankOf<list<Type> StridedMemRefRankOf:allowedTypes = ?, list<int> StridedMemRefRankOf:ranks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[MemRefOf<StridedMemRefRankOf:allowedTypes>.predicate, HasAnyRankOfPred<StridedMemRefRankOf:ranks>]>;
  string summary = !strconcat(!interleave(!foreach(rank, StridedMemRefRankOf:ranks, !strconcat(!cast<string>(rank), "D")), "/"), !strconcat(" ", MemRefOf<StridedMemRefRankOf:allowedTypes>.summary));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class StringBasedAttr<Pred StringBasedAttr:condition = ?, string StringBasedAttr:descr = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = StringBasedAttr:condition;
  string summary = StringBasedAttr:descr;
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class StringRefParameter<string StringRefParameter:desc = ""> {	// AttrOrTypeParameter
  code allocator = [{$_dst = $_allocator.copyInto($_self);}];
  string comparator = ?;
  string cppType = "::llvm::StringRef";
  string cppAccessorType = "::llvm::StringRef";
  string cppStorageType = "std::string";
  string summary = StringRefParameter:desc;
  string syntax = ?;
  string parser = ?;
  code printer = [{$_printer << '"' << $_self << '"';}];
  bit isOptional = 0;
  string defaultValue = ?;
}
class StructAttr<string StructAttr:name = ?, Dialect StructAttr:d = ?, list<StructFieldAttr> StructAttr:attributes = ?> {	// Constraint AttrConstraint Attr DictionaryAttrBase
  Pred predicate = CPred<!strconcat("$_self.isa<", !strconcat(StructAttr:d.cppNamespace, !strconcat("::", !strconcat(StructAttr:name, ">()"))))>;
  string summary = !strconcat("DictionaryAttr with field(s): ", !strconcat(!interleave(!foreach(a, StructAttr:attributes, !strconcat("'", !strconcat(a.name, "'"))), ", "), " (each field having its own constraints)"));
  string storageType = !strconcat(StructAttr:d.cppNamespace, !strconcat("::", StructAttr:name));
  string returnType = !strconcat(StructAttr:d.cppNamespace, !strconcat("::", StructAttr:name));
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = StructAttr:d.cppNamespace;
  string description = "";
  string className = StructAttr:name;
  Dialect dialect = StructAttr:d;
  list<StructFieldAttr> fields = StructAttr:attributes;
}
class StructFieldAttr<string StructFieldAttr:thisName = ?, Attr StructFieldAttr:thisType = ?> {
  string name = StructFieldAttr:thisName;
  Attr type = StructFieldAttr:thisType;
}
class StructuralOpTrait {
}
class SubstLeaves<string SubstLeaves:pat = ?, string SubstLeaves:repl = ?, Pred SubstLeaves:child = ?> {	// Pred CombinedPred
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [SubstLeaves:child];
  string pattern = SubstLeaves:pat;
  string replacement = SubstLeaves:repl;
}
class Successor<Pred Successor:condition = ?, string Successor:descr = ""> {	// Constraint SuccessorConstraint
  Pred predicate = Successor:condition;
  string summary = Successor:descr;
}
class SuccessorConstraint<Pred SuccessorConstraint:predicate = ?, string SuccessorConstraint:summary = ""> {	// Constraint
  Pred predicate = SuccessorConstraint:predicate;
  string summary = SuccessorConstraint:summary;
}
class TCOpIsBroadcastableToRes<int TCOpIsBroadcastableToRes:opId = ?, int TCOpIsBroadcastableToRes:resId = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [TCOpResIsShapedTypePred<TCOpIsBroadcastableToRes:opId, TCOpIsBroadcastableToRes:resId>, CPred<!strconcat("::mlir::OpTrait::util::getBroadcastedType($_op.getOperand(", !strconcat(!cast<string>(TCOpIsBroadcastableToRes:opId), !strconcat(").getType(), $_op.getResult(", !strconcat(!cast<string>(TCOpIsBroadcastableToRes:resId), ").getType())"))))>];
}
class TCOpResIsShapedTypePred<int TCOpResIsShapedTypePred:i = ?, int TCOpResIsShapedTypePred:j = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<!strconcat("$_op.getNumResults() > ", !cast<string>(TCOpResIsShapedTypePred:i))>, CPred<!strconcat("$_op.getNumOperands() > ", !cast<string>(TCOpResIsShapedTypePred:j))>, SubstLeaves<"$_self", !strconcat("$_op.getResult(", !strconcat(!cast<string>(TCOpResIsShapedTypePred:i), ").getType()")), IsShapedTypePred>, SubstLeaves<"$_self", !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCOpResIsShapedTypePred:j), ").getType()")), IsShapedTypePred>];
}
class TCopVTEtAreSameAt<list<int> TCopVTEtAreSameAt:indices = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("::llvm::is_splat(::llvm::map_range(::mlir::ArrayRef<unsigned>({", !strconcat(!interleave(TCopVTEtAreSameAt:indices, ", "), "}), [this](unsigned i) { return getElementTypeOrSelf(this->getOperand(i)); }))")), ")"));
}
class TCopVTEtIs<int TCopVTEtIs:idx = ?, Type TCopVTEtIs:type = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<!strconcat("$_op.getNumOperands() > ", !cast<string>(TCopVTEtIs:idx))>, SubstLeaves<"$_self", !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIs:idx), ").getType()")), IsShapedTypePred>, SubstLeaves<"$_self", !strconcat("getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIs:idx), "))")), TCopVTEtIs:type.predicate>];
}
class TCopVTEtIsSameAs<int TCopVTEtIsSameAs:i = ?, int TCopVTEtIsSameAs:j = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [CPred<!strconcat("$_op.getNumOperands() > ", !cast<string>(!if(!gt(TCopVTEtIsSameAs:i, TCopVTEtIsSameAs:j), TCopVTEtIsSameAs:i, TCopVTEtIsSameAs:j)))>, SubstLeaves<"$_self", !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:i), ").getType()")), IsShapedTypePred>, SubstLeaves<"$_self", !strconcat("$_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:j), ").getType()")), IsShapedTypePred>, CPred<!strconcat("::mlir::getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:i), !strconcat(")) == ::mlir::getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCopVTEtIsSameAs:j), "))"))))>];
}
class TCresIsSameAsOpBase<int TCresIsSameAsOpBase:i = ?, int TCresIsSameAsOpBase:j = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("$_op.getResult(", !strconcat(!cast<string>(TCresIsSameAsOpBase:i), !strconcat(").getType() == $_op.getOperand(", !strconcat(!cast<string>(TCresIsSameAsOpBase:j), ").getType()")))), ")"));
}
class TCresVTEtIsSameAsOp<int TCresVTEtIsSameAsOp:i = ?, int TCresVTEtIsSameAsOp:j = ?> {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [TCOpResIsShapedTypePred<TCresVTEtIsSameAsOp:i, TCresVTEtIsSameAsOp:j>, TCresVTEtIsSameAsOpBase<TCresVTEtIsSameAsOp:i, TCresVTEtIsSameAsOp:j>];
}
class TCresVTEtIsSameAsOpBase<int TCresVTEtIsSameAsOpBase:i = ?, int TCresVTEtIsSameAsOpBase:j = ?> {	// Pred CPred
  string predExpr = !strconcat("(", !strconcat(!strconcat("getElementTypeOrSelf($_op.getResult(", !strconcat(!cast<string>(TCresVTEtIsSameAsOpBase:i), !strconcat(")) == getElementTypeOrSelf($_op.getOperand(", !strconcat(!cast<string>(TCresVTEtIsSameAsOpBase:j), "))")))), ")"));
}
class TensorOf<list<Type> TensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsTensorTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<TensorOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("tensor", !strconcat(" of ", !strconcat(AnyTypeOf<TensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class TensorRankOf<list<Type> TensorRankOf:allowedTypes = ?, list<int> TensorRankOf:ranks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[TensorOf<TensorRankOf:allowedTypes>.predicate, HasAnyRankOfPred<TensorRankOf:ranks>]>;
  string summary = !strconcat(!interleave(!foreach(rank, TensorRankOf:ranks, !strconcat(!cast<string>(rank), "D")), "/"), !strconcat(" ", TensorOf<TensorRankOf:allowedTypes>.summary));
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
class Trait {
}
class TraitList<list<Trait> TraitList:props = ?> {	// Trait
  list<Trait> traits = TraitList:props;
}
class TupleOf<list<Type> TupleOf:allowedTypes = ?> {	// Constraint TypeConstraint Type MixedContainerType
  Pred predicate = And<[IsTupleTypePred, Concat<"::llvm::all_of($_self.cast<::mlir::TupleType>().getTypes(), [](Type t) { return t && (", SubstLeaves<"$_self", "t", AnyTypeOf<TupleOf:allowedTypes>.predicate>, "); })">]>;
  string summary = !strconcat("tuple", !strconcat(" with any combination of ", !strconcat(AnyTypeOf<TupleOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Type elementType = AnyTypeOf<TupleOf:allowedTypes>;
  string getElementTypesCall = "$_self.cast<::mlir::TupleType>().getTypes()";
}
class Type<Pred Type:condition = ?, string Type:descr = "", string Type:cppClassName = "::mlir::Type"> {	// Constraint TypeConstraint
  Pred predicate = Type:condition;
  string summary = Type:descr;
  string cppClassName = Type:cppClassName;
  string description = "";
  string builderCall = "";
}
class TypeAlias<Type TypeAlias:t = ?, string TypeAlias:summary = TypeAlias:t.summary> {	// Constraint TypeConstraint Type
  Pred predicate = TypeAlias:t.predicate;
  string summary = TypeAlias:summary;
  string cppClassName = "::mlir::Type";
  string description = TypeAlias:t.description;
  string builderCall = TypeAlias:t.builderCall;
}
class TypeAttrBase<string TypeAttrBase:retType = ?, string TypeAttrBase:summary = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = And<[anonymous_213, CPred<!strconcat("$_self.cast<::mlir::TypeAttr>().getValue().isa<", !strconcat(TypeAttrBase:retType, ">()"))>]>;
  string summary = TypeAttrBase:summary;
  code storageType = [{ ::mlir::TypeAttr }];
  string returnType = TypeAttrBase:retType;
  string convertFromStorage = !strconcat("$_self.getValue().cast<", !strconcat(TypeAttrBase:retType, ">()"));
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypeAttrOf<Type TypeAttrOf:ty = ?> {	// Constraint AttrConstraint Attr TypeAttrBase
  Pred predicate = And<[anonymous_213, CPred<!strconcat("$_self.cast<::mlir::TypeAttr>().getValue().isa<", !strconcat(TypeAttrOf:ty.cppClassName, ">()"))>]>;
  string summary = !strconcat("type attribute of ", TypeAttrOf:ty.summary);
  code storageType = [{ ::mlir::TypeAttr }];
  string returnType = TypeAttrOf:ty.cppClassName;
  string convertFromStorage = !strconcat("$_self.getValue().cast<", !strconcat(TypeAttrOf:ty.cppClassName, ">()"));
  string constBuilderCall = "::mlir::TypeAttr::get($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypeBuilder<dag TypeBuilder:parameters = ?, string TypeBuilder:bodyCode = ""> {	// AttrOrTypeBuilder
  dag dagParams = TypeBuilder:parameters;
  string body = TypeBuilder:bodyCode;
  bit hasInferredContextParam = 0;
}
class TypeBuilderWithInferredContext<dag TypeBuilderWithInferredContext:parameters = ?, string TypeBuilderWithInferredContext:bodyCode = ""> {	// AttrOrTypeBuilder TypeBuilder AttrOrTypeBuilderWithInferredContext
  dag dagParams = TypeBuilderWithInferredContext:parameters;
  string body = TypeBuilderWithInferredContext:bodyCode;
  bit hasInferredContextParam = 1;
}
class TypeConstraint<Pred TypeConstraint:predicate = ?, string TypeConstraint:summary = "", string TypeConstraint:cppClassNameParam = "::mlir::Type"> {	// Constraint
  Pred predicate = TypeConstraint:predicate;
  string summary = TypeConstraint:summary;
  string cppClassName = TypeConstraint:cppClassNameParam;
}
class TypeDef<Dialect TypeDef:dialect = ?, string TypeDef:name = ?, list<Trait> TypeDef:traits = [], string TypeDef:baseCppClass = "::mlir::Type"> {	// Constraint TypeConstraint Type DialectType AttrOrTypeDef
  Pred predicate = CPred<!strconcat("$_self.isa<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">()"))))>;
  string summary = "";
  string cppClassName = !strconcat(TypeDef:name, "Type");
  string description = "";
  string builderCall = !if(!empty(parameters), !strconcat("$_builder.getType<", !strconcat(dialect.cppNamespace, !strconcat("::", !strconcat(cppClassName, ">()")))), "");
  Dialect dialect = TypeDef:dialect;
  string cppBaseClassName = TypeDef:baseCppClass;
  string storageClass = !strconcat(TypeDef:name, "TypeStorage");
  string storageNamespace = "detail";
  bit genStorageClass = 1;
  bit hasStorageCustomConstructor = 0;
  dag parameters = (ins);
  list<AttrOrTypeBuilder> builders = ?;
  list<Trait> traits = TypeDef:traits;
  string mnemonic = ?;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit genAccessors = 1;
  bit skipDefaultBuilders = 0;
  bit genVerifyDecl = 0;
  code extraClassDeclaration = [{}];
  string cppType = !strconcat(dialect.cppNamespace, !strconcat("::", cppClassName));
}
class TypeInterface<string TypeInterface:name = ?> {	// Interface Trait NativeTrait InterfaceTrait
  string description = "";
  string cppClassName = TypeInterface:name;
  string cppNamespace = "";
  list<InterfaceMethod> methods = [];
  string extraClassDeclaration = "";
  string extraSharedClassDeclaration = "";
  string trait = !strconcat(TypeInterface:name, "::Trait");
  string extraTraitClassDeclaration = "";
}
class TypeIs<string TypeIs:name = ?, Type TypeIs:type = ?> {	// Trait PredTrait PredOpTrait
  string summary = !strconcat("'", !strconcat(TypeIs:name, !strconcat("' is ", TypeIs:type.summary)));
  Pred predicate = TypeIsPred<TypeIs:name, TypeIs:type>;
  list<Trait> dependentTraits = [];
}
class TypeIsPred<string TypeIsPred:name = ?, Type TypeIsPred:type = ?> {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [TypeIsPred:type.predicate];
  string pattern = "$_self";
  string replacement = !strconcat("$", !strconcat(TypeIsPred:name, ".getType()"));
}
class TypeOrContainer<Type TypeOrContainer:allowedType = ?, string TypeOrContainer:name = ?> {	// Constraint TypeConstraint
  Pred predicate = Or<[TypeOrContainer:allowedType.predicate, VectorOf<[TypeOrContainer:allowedType]>.predicate, TensorOf<[TypeOrContainer:allowedType]>.predicate]>;
  string summary = TypeOrContainer:name;
  string cppClassName = "::mlir::Type";
}
class TypeOrContainerOfAnyRank<Type TypeOrContainerOfAnyRank:allowedType = ?, string TypeOrContainerOfAnyRank:name = ?> {	// Constraint TypeConstraint
  Pred predicate = Or<[TypeOrContainerOfAnyRank:allowedType.predicate, VectorOfAnyRankOf<[TypeOrContainerOfAnyRank:allowedType]>.predicate, TensorOf<[TypeOrContainerOfAnyRank:allowedType]>.predicate]>;
  string summary = TypeOrContainerOfAnyRank:name;
  string cppClassName = "::mlir::Type";
}
class TypeParameter<string TypeParameter:type = ?, string TypeParameter:desc = ?, string TypeParameter:accessorType = ""> {	// AttrOrTypeParameter
  string allocator = ?;
  string comparator = ?;
  string cppType = TypeParameter:type;
  string cppAccessorType = !if(!empty(TypeParameter:accessorType), TypeParameter:type, TypeParameter:accessorType);
  string cppStorageType = ?;
  string summary = TypeParameter:desc;
  string syntax = ?;
  string parser = ?;
  string printer = ?;
  bit isOptional = 0;
  string defaultValue = ?;
}
class TypedArrayAttrBase<Attr TypedArrayAttrBase:element = ?, string TypedArrayAttrBase:summary = ?> {	// Constraint AttrConstraint Attr ArrayAttrBase
  Pred predicate = And<[anonymous_236, Concat<"::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (", SubstLeaves<"$_self", "attr", TypedArrayAttrBase:element.predicate>, "); })">]>;
  string summary = TypedArrayAttrBase:summary;
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = TypedArrayAttrBase:element;
}
class TypedAttrBase<Type TypedAttrBase:attrValType = ?, string TypedAttrBase:attrKind = ?, Pred TypedAttrBase:condition = ?, string TypedAttrBase:descr = ?> {	// Constraint AttrConstraint Attr
  Pred predicate = TypedAttrBase:condition;
  string summary = TypedAttrBase:descr;
  string storageType = !strconcat("::mlir::", TypedAttrBase:attrKind);
  string returnType = ?;
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat(TypedAttrBase:attrKind, !strconcat("(", !strconcat(TypedAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedSignedIntegerAttrBase<SI TypedSignedIntegerAttrBase:attrValType = ?, string TypedSignedIntegerAttrBase:retType = ?, string TypedSignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(", !strconcat(!cast<string>(TypedSignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = TypedSignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  string returnType = TypedSignedIntegerAttrBase:retType;
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(TypedSignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedSignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedSignlessIntegerAttrBase<I TypedSignlessIntegerAttrBase:attrValType = ?, string TypedSignlessIntegerAttrBase:retType = ?, string TypedSignlessIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(", !strconcat(!cast<string>(TypedSignlessIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = TypedSignlessIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  string returnType = TypedSignlessIntegerAttrBase:retType;
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(TypedSignlessIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedSignlessIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedStrAttr<Type TypedStrAttr:ty = ?> {	// Constraint AttrConstraint Attr StringBasedAttr
  Pred predicate = anonymous_212;
  string summary = "string attribute";
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = TypedStrAttr:ty;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypedUnsignedIntegerAttrBase<UI TypedUnsignedIntegerAttrBase:attrValType = ?, string TypedUnsignedIntegerAttrBase:retType = ?, string TypedUnsignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(", !strconcat(!cast<string>(TypedUnsignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = TypedUnsignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  string returnType = TypedUnsignedIntegerAttrBase:retType;
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(TypedUnsignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = TypedUnsignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class TypesMatchWith<string TypesMatchWith:summary = ?, string TypesMatchWith:lhsArg = ?, string TypesMatchWith:rhsArg = ?, string TypesMatchWith:transform = ?, string TypesMatchWith:comparator = "std::equal_to<>()"> {	// Trait PredTrait PredOpTrait
  string summary = TypesMatchWith:summary;
  Pred predicate = CPred<!strconcat(TypesMatchWith:comparator, !strconcat("(", !strconcat(!subst("$_self", !strconcat("$", !strconcat(TypesMatchWith:lhsArg, ".getType()")), TypesMatchWith:transform), !strconcat(", $", !strconcat(TypesMatchWith:rhsArg, ".getType())")))))>;
  list<Trait> dependentTraits = [];
  string lhs = TypesMatchWith:lhsArg;
  string rhs = TypesMatchWith:rhsArg;
  string transformer = TypesMatchWith:transform;
}
class UI<int UI:width = ?> {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = CPred<!strconcat("$_self.isUnsignedInteger(", !strconcat(!cast<string>(UI:width), ")"))>;
  string summary = !strconcat(!cast<string>(UI:width), "-bit unsigned integer");
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = !strconcat("$_builder.getIntegerType(", !strconcat(!cast<string>(UI:width), ", /*isSigned=*/false)"));
  int bitwidth = UI:width;
}
class UnrankedMemRefOf<list<Type> UnrankedMemRefOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsUnrankedMemRefTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<UnrankedMemRefOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("unranked.memref", !strconcat(" of ", !strconcat(AnyTypeOf<UnrankedMemRefOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::UnrankedMemRefType";
  string description = "";
  string builderCall = "";
}
class UnrankedTensorOf<list<Type> UnrankedTensorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsUnrankedTensorTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<UnrankedTensorOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("unranked.tensor", !strconcat(" of ", !strconcat(AnyTypeOf<UnrankedTensorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::UnrankedTensorType";
  string description = "";
  string builderCall = "";
}
class UnsignedIntOfWidths<list<int> UnsignedIntOfWidths:widths = ?> {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = Or<!foreach(allowedtype, !foreach(w, UnsignedIntOfWidths:widths, UI<w>), allowedtype.predicate)>;
  string summary = !if(!eq(!strconcat(!interleave(UnsignedIntOfWidths:widths, "/"), "-bit unsigned integer"), ""), !interleave(!foreach(t, !foreach(w, UnsignedIntOfWidths:widths, UI<w>), t.summary), " or "), !strconcat(!interleave(UnsignedIntOfWidths:widths, "/"), "-bit unsigned integer"));
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
class UnsignedIntegerAttrBase<UI UnsignedIntegerAttrBase:attrValType = ?, string UnsignedIntegerAttrBase:descr = ?> {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = And<[anonymous_164, CPred<!strconcat("$_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(", !strconcat(!cast<string>(UnsignedIntegerAttrBase:attrValType.bitwidth), ")"))>]>;
  string summary = UnsignedIntegerAttrBase:descr;
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = !strconcat("$_builder.get", !strconcat("IntegerAttr", !strconcat("(", !strconcat(UnsignedIntegerAttrBase:attrValType.builderCall, ", $0)"))));
  string defaultValue = ?;
  Type valueType = UnsignedIntegerAttrBase:attrValType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
class Variadic<Type Variadic:type = ?> {	// Constraint TypeConstraint
  Pred predicate = Variadic:type.predicate;
  string summary = Variadic:type.summary;
  string cppClassName = Variadic:type.cppClassName;
  Type baseType = Variadic:type;
  int minSize = 0;
}
class VariadicOfVariadic<Type VariadicOfVariadic:type = ?, string VariadicOfVariadic:variadicSegmentAttrName = ?> {	// Constraint TypeConstraint Variadic
  Pred predicate = VariadicOfVariadic:type.predicate;
  string summary = VariadicOfVariadic:type.summary;
  string cppClassName = VariadicOfVariadic:type.cppClassName;
  Type baseType = VariadicOfVariadic:type;
  int minSize = 0;
  string segmentAttrName = VariadicOfVariadic:variadicSegmentAttrName;
}
class VariadicRegion<Region VariadicRegion:region = ?> {	// Constraint RegionConstraint Region
  Pred predicate = VariadicRegion:region.predicate;
  string summary = VariadicRegion:region.summary;
}
class VariadicSuccessor<Successor VariadicSuccessor:successor = ?> {	// Constraint SuccessorConstraint Successor
  Pred predicate = VariadicSuccessor:successor.predicate;
  string summary = VariadicSuccessor:successor.summary;
}
class VectorOf<list<Type> VectorOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsVectorTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<VectorOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("vector", !strconcat(" of ", !strconcat(AnyTypeOf<VectorOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfAnyRankOf<list<Type> VectorOfAnyRankOf:allowedTypes = ?> {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = And<[IsVectorOfAnyRankTypePred, Concat<"[](::mlir::Type elementType) { return ", SubstLeaves<"$_self", "elementType", AnyTypeOf<VectorOfAnyRankOf:allowedTypes>.predicate>, "; }($_self.cast<::mlir::ShapedType>().getElementType())">]>;
  string summary = !strconcat("vector", !strconcat(" of ", !strconcat(AnyTypeOf<VectorOfAnyRankOf:allowedTypes>.summary, " values")));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfLength<list<int> VectorOfLength:allowedLengths = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsVectorOfLengthPred<VectorOfLength:allowedLengths>;
  string summary = !strconcat(" of length ", !interleave(VectorOfLength:allowedLengths, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfLengthAndType<list<int> VectorOfLengthAndType:allowedLengths = ?, list<Type> VectorOfLengthAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[VectorOf<VectorOfLengthAndType:allowedTypes>.predicate, VectorOfLength<VectorOfLengthAndType:allowedLengths>.predicate]>;
  string summary = !strconcat(VectorOf<VectorOfLengthAndType:allowedTypes>.summary, VectorOfLength<VectorOfLengthAndType:allowedLengths>.summary);
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfRank<list<int> VectorOfRank:allowedRanks = ?> {	// Constraint TypeConstraint Type
  Pred predicate = IsVectorOfRankPred<VectorOfRank:allowedRanks>;
  string summary = !strconcat(" of ranks ", !interleave(VectorOfRank:allowedRanks, "/"));
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
class VectorOfRankAndType<list<int> VectorOfRankAndType:allowedRanks = ?, list<Type> VectorOfRankAndType:allowedTypes = ?> {	// Constraint TypeConstraint Type
  Pred predicate = And<[VectorOf<VectorOfRankAndType:allowedTypes>.predicate, VectorOfRank<VectorOfRankAndType:allowedRanks>.predicate]>;
  string summary = !strconcat(VectorOf<VectorOfRankAndType:allowedTypes>.summary, VectorOfRank<VectorOfRankAndType:allowedRanks>.summary);
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
------------- Defs -----------------
def AMX_Dialect {	// Dialect
  string name = "amx";
  string summary = ?;
  code description = [{
    The Intel Advanced Matrix Extensions (AMX) provide a tile matrix
    multiply unit (TMUL), a tile control register (TILECFG), and eight
    tile registers TMM0 through TMM7 (TILEDATA).

    This `AMX` dialect provides a bridge between MLIR concepts such as
    vectors and memrefs and the lower level LLVM IR support of AMX.
    The dialect is split into user-facing AMX ops (AMX_Op) and
    backend-facing intrinsic ops (AMX_IntrOp).

    Note that since configuration changes (implicit at dialect level) are
    costly, it is highly recommended to use the AMX dialect on same-shaped
    vectors, at least within a single method.

    For details, see the Intel documentation:
    https://software.intel.com/content/www/us/en/develop/articles/intel-sdm.html
  }];
  list<string> dependentDialects = [];
  string cppNamespace = "::mlir::amx";
  string extraClassDeclaration = "";
  bit hasConstantMaterializer = 0;
  bit hasNonDefaultDestructor = 0;
  bit hasOperationAttrVerify = 0;
  bit hasRegionArgAttrVerify = 0;
  bit hasRegionResultAttrVerify = 0;
  bit hasOperationInterfaceFallback = 0;
  bit useDefaultAttributePrinterParser = 0;
  bit useDefaultTypePrinterParser = 0;
  bit hasCanonicalizer = 0;
  int emitAccessorPrefix = 0;
  bit isExtensible = 0;
}
def APIntAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_164;
  string summary = "arbitrary integer attribute";
  code storageType = [{ ::mlir::IntegerAttr }];
  code returnType = [{ ::mlir::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AffineMapArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_239;
  string summary = "AffineMap array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getAffineMapArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = AffineMapAttr;
}
def AffineMapAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_235;
  string summary = "AffineMap attribute";
  code storageType = [{::mlir::AffineMapAttr }];
  code returnType = [{ ::mlir::AffineMap }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "::mlir::AffineMapAttr::get($0)";
  string defaultValue = ?;
  Type valueType = Index;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AffineScope {	// Trait NativeTrait NativeOpTrait
  string trait = "AffineScope";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def AnyAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_2;
  string summary = "any attribute";
  string storageType = "::mlir::Attribute";
  string returnType = "::mlir::Attribute";
  string convertFromStorage = "$_self";
  string constBuilderCall = "$0";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyComplex {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_37;
  string summary = "complex-type";
  string cppClassName = "::mlir::ComplexType";
  string description = "";
  string builderCall = "";
}
def AnyFixedVector {	// Constraint TypeConstraint Type ShapedContainerType FixedVectorOf
  Pred predicate = anonymous_45;
  string summary = "fixed-length vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def AnyFloat {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_30;
  string summary = "floating-point";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "";
}
def AnyI1 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_5;
  string summary = "1-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 1;
}
def AnyI16 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_7;
  string summary = "16-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 16;
}
def AnyI16Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_172;
  string summary = "16-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI1Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_168;
  string summary = "1-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI32 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_8;
  string summary = "32-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 32;
}
def AnyI32Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_174;
  string summary = "32-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI32ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase IntElementsAttrOf
  Pred predicate = anonymous_224;
  string summary = "32-bit integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI64 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_9;
  string summary = "64-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 64;
}
def AnyI64Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_176;
  string summary = "64-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI64ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase IntElementsAttrOf
  Pred predicate = anonymous_226;
  string summary = "64-bit integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyI8 {	// Constraint TypeConstraint Type AnyI
  Pred predicate = anonymous_6;
  string summary = "8-bit integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  int bitwidth = 8;
}
def AnyI8Attr {	// Constraint AttrConstraint Attr TypedAttrBase AnyIntegerAttrBase
  Pred predicate = anonymous_170;
  string summary = "8-bit integer attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = AnyI8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyIntElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = anonymous_222;
  string summary = "integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AnyInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_4;
  string summary = "integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "";
}
def AnyMemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_119;
  string summary = "memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def AnyRankedOrUnrankedMemRef {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_120;
  string summary = "unranked.memref of any type values or memref of any type values";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyRankedTensor {	// Constraint TypeConstraint Type ShapedContainerType RankedTensorOf
  Pred predicate = anonymous_50;
  string summary = "ranked tensor of any type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def AnyRegion {	// Constraint RegionConstraint Region
  Pred predicate = anonymous_2;
  string summary = "any region";
}
def AnyScalableVector {	// Constraint TypeConstraint Type ShapedContainerType ScalableVectorOf
  Pred predicate = anonymous_46;
  string summary = "scalable vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def AnyShaped {	// Constraint TypeConstraint Type ShapedContainerType
  Pred predicate = anonymous_47;
  string summary = "shaped of any type values";
  string cppClassName = "::mlir::ShapedType";
  string description = "";
  string builderCall = "";
}
def AnySignedInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_16;
  string summary = "signed integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnySignlessInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_10;
  string summary = "signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "";
}
def AnySignlessIntegerOrIndex {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_29;
  string summary = "signless integer or index";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyStaticShapeMemRef {	// Constraint TypeConstraint Type StaticShapeMemRefOf
  Pred predicate = anonymous_131;
  string summary = "statically shaped memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def AnyStaticShapeTensor {	// Constraint TypeConstraint Type StaticShapeTensorOf
  Pred predicate = anonymous_52;
  string summary = "statically shaped tensor of any type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def AnyStridedMemRef {	// Constraint TypeConstraint Type StridedMemRefOf
  Pred predicate = anonymous_132;
  string summary = "strided memref of any type values";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnySuccessor {	// Constraint SuccessorConstraint Successor
  Pred predicate = ?;
  string summary = "any successor";
}
def AnyTensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_49;
  string summary = "tensor of any type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def AnyTuple {	// Constraint TypeConstraint Type
  Pred predicate = IsTupleTypePred;
  string summary = "tuple";
  string cppClassName = "::mlir::TupleType";
  string description = "";
  string builderCall = "";
}
def AnyType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_2;
  string summary = "any type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyUnrankedMemRef {	// Constraint TypeConstraint Type ShapedContainerType UnrankedMemRefOf
  Pred predicate = anonymous_118;
  string summary = "unranked.memref of any type values";
  string cppClassName = "::mlir::UnrankedMemRefType";
  string description = "";
  string builderCall = "";
}
def AnyUnsignedInteger {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_22;
  string summary = "unsigned integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def AnyVector {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_43;
  string summary = "vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def AnyVectorOfAnyRank {	// Constraint TypeConstraint Type ShapedContainerType VectorOfAnyRankOf
  Pred predicate = anonymous_44;
  string summary = "vector of any type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase
  Pred predicate = anonymous_236;
  string summary = "array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def AttrSizedOperandSegments {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "AttrSizedOperandSegments";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def AttrSizedResultSegments {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "AttrSizedResultSegments";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def AutomaticAllocationScope {	// Trait NativeTrait NativeOpTrait
  string trait = "AutomaticAllocationScope";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def AutomaticAllocationScopeResource {	// Resource IntrinsicResource
  string name = "::mlir::SideEffects::AutomaticAllocationScopeResource";
}
def BF16 {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_36;
  string summary = "bfloat16 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "$_builder.getBF16Type()";
}
def BF16MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_126;
  string summary = "memref of bfloat16 type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def BF16Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_87;
  string summary = "tensor of bfloat16 type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def BoolArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_242;
  string summary = "1-bit boolean array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getBoolArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = BoolAttr;
}
def BoolAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_163;
  string summary = "bool attribute";
  code storageType = [{ ::mlir::BoolAttr }];
  code returnType = [{ bool }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getBoolAttr($0)";
  string defaultValue = ?;
  Type valueType = I1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def BoolLike {	// Constraint TypeConstraint TypeOrContainer
  Pred predicate = anonymous_137;
  string summary = "bool-like";
  string cppClassName = "::mlir::Type";
}
def BoolLikeOfAnyRank {	// Constraint TypeConstraint TypeOrContainerOfAnyRank
  Pred predicate = anonymous_140;
  string summary = "bool-like";
  string cppClassName = "::mlir::Type";
}
def Commutative {	// Trait NativeTrait NativeOpTrait
  string trait = "IsCommutative";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def ConstBoolAttrFalse {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = anonymous_272;
  string summary = "constant attribute false";
  Attr attr = BoolAttr;
  string value = "false";
}
def ConstBoolAttrTrue {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = anonymous_273;
  string summary = "constant attribute true";
  Attr attr = BoolAttr;
  string value = "true";
}
def ConstUnitAttr {	// Constraint AttrConstraint ConstantAttr
  Pred predicate = anonymous_274;
  string summary = "constant attribute unit";
  Attr attr = UnitAttr;
  string value = "unit";
}
def ConstantLike {	// Trait NativeTrait NativeOpTrait
  string trait = "ConstantLike";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def DefaultResource {	// Resource IntrinsicResource
  string name = "::mlir::SideEffects::DefaultResource";
}
def DictionaryAttr {	// Constraint AttrConstraint Attr DictionaryAttrBase
  Pred predicate = anonymous_217;
  string summary = "dictionary of named attribute values";
  code storageType = [{ ::mlir::DictionaryAttr }];
  code returnType = [{ ::mlir::DictionaryAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = anonymous_218;
  string summary = "constant vector/tensor attribute";
  code storageType = [{ ::mlir::ElementsAttr }];
  code returnType = [{ ::mlir::ElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def Elementwise {	// Trait NativeTrait NativeOpTrait
  string trait = "Elementwise";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def ElementwiseMappable {	// Trait TraitList
  list<Trait> traits = [Elementwise, Scalarizable, Vectorizable, Tensorizable];
}
def F128 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_35;
  string summary = "128-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF128Type()";
  int bitwidth = 128;
}
def F16 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_31;
  string summary = "16-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF16Type()";
  int bitwidth = 16;
}
def F16MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_127;
  string summary = "memref of 16-bit float values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def F16Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_92;
  string summary = "tensor of 16-bit float values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def F32 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_32;
  string summary = "32-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF32Type()";
  int bitwidth = 32;
}
def F32ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_251;
  string summary = "32-bit float array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getF32ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = F32Attr;
}
def F32Attr {	// Constraint AttrConstraint Attr TypedAttrBase FloatAttrBase
  Pred predicate = anonymous_209;
  string summary = "32-bit float attribute";
  string storageType = "::mlir::FloatAttr";
  code returnType = [{ ::llvm::APFloat }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getFloatAttr($_builder.getF32Type(), $0)";
  string defaultValue = ?;
  Type valueType = F32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def F32MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_128;
  string summary = "memref of 32-bit float values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def F32Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_97;
  string summary = "tensor of 32-bit float values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def F64 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_33;
  string summary = "64-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF64Type()";
  int bitwidth = 64;
}
def F64ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_254;
  string summary = "64-bit float array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getF64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = F64Attr;
}
def F64Attr {	// Constraint AttrConstraint Attr TypedAttrBase FloatAttrBase
  Pred predicate = anonymous_211;
  string summary = "64-bit float attribute";
  string storageType = "::mlir::FloatAttr";
  code returnType = [{ ::llvm::APFloat }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getFloatAttr($_builder.getF64Type(), $0)";
  string defaultValue = ?;
  Type valueType = F64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def F64ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase FloatElementsAttr
  Pred predicate = anonymous_233;
  string summary = "64-bit float elements attribute";
  code storageType = [{ ::mlir::DenseElementsAttr }];
  code returnType = [{ ::mlir::DenseElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getF64Type()),::llvm::makeArrayRef($0))";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def F64MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_129;
  string summary = "memref of 64-bit float values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def F64Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_102;
  string summary = "tensor of 64-bit float values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def F80 {	// Constraint TypeConstraint Type BuildableType F
  Pred predicate = anonymous_34;
  string summary = "80-bit float";
  string cppClassName = "::mlir::FloatType";
  string description = "";
  string builderCall = "$_builder.getF80Type()";
  int bitwidth = 80;
}
def FirstAttrDerivedResultType {	// Trait GenInternalTrait GenInternalOpTrait
  string trait = "::mlir::OpTrait::FirstAttrDerivedResultType";
  list<Trait> dependentTraits = [];
}
def FlatSymbolRefArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_271;
  string summary = "flat symbol ref array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = FlatSymbolRefAttr;
}
def FlatSymbolRefAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_265;
  string summary = "flat symbol reference attribute";
  code storageType = [{ ::mlir::FlatSymbolRefAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "::mlir::SymbolRefAttr::get($_builder.getContext(), $0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def FloatLike {	// Constraint TypeConstraint TypeOrContainer
  Pred predicate = anonymous_161;
  string summary = "floating-point-like";
  string cppClassName = "::mlir::Type";
}
def FunctionType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_38;
  string summary = "function type";
  string cppClassName = "::mlir::FunctionType";
  string description = "";
  string builderCall = "";
}
def HasRankPred {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::ShapedType>().hasRank())";
}
def HasStaticShapePred {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::ShapedType>().hasStaticShape())";
}
def HasStridesPred {	// Pred CPred
  code predExpr = [{( isStrided($_self.cast<::mlir::MemRefType>()) )}];
}
def I1 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_11;
  string summary = "1-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(1)";
  int bitwidth = 1;
}
def I16 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_13;
  string summary = "16-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(16)";
  int bitwidth = 16;
}
def I16Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_182;
  string summary = "16-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint16_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(16), $0)";
  string defaultValue = ?;
  Type valueType = I16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I16MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_123;
  string summary = "memref of 16-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I16Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_67;
  string summary = "tensor of 16-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I1Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_178;
  string summary = "1-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "bool";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(1), $0)";
  string defaultValue = ?;
  Type valueType = I1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I1MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_121;
  string summary = "memref of 1-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I1Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_57;
  string summary = "tensor of 1-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I32 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_14;
  string summary = "32-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(32)";
  int bitwidth = 32;
}
def I32ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_245;
  string summary = "32-bit integer array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getI32ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I32Attr;
}
def I32Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_184;
  string summary = "32-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint32_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32), $0)";
  string defaultValue = ?;
  Type valueType = I32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I32ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_228;
  string summary = "32-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(32)), ::llvm::makeArrayRef($0)).cast<::mlir::DenseIntElementsAttr>()";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I32MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_124;
  string summary = "memref of 32-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I32Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_72;
  string summary = "tensor of 32-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I64 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_15;
  string summary = "64-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(64)";
  int bitwidth = 64;
}
def I64ArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_248;
  string summary = "64-bit integer array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getI64ArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I64Attr;
}
def I64Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_186;
  string summary = "64-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint64_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64), $0)";
  string defaultValue = ?;
  Type valueType = I64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I64ElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_230;
  string summary = "64-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(64)), ::llvm::makeArrayRef($0)).cast<::mlir::DenseIntElementsAttr>()";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I64MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_125;
  string summary = "memref of 64-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I64Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_77;
  string summary = "tensor of 64-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def I8 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_12;
  string summary = "8-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8)";
  int bitwidth = 8;
}
def I8Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignlessIntegerAttrBase TypedSignlessIntegerAttrBase
  Pred predicate = anonymous_180;
  string summary = "8-bit signless integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint8_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(8), $0)";
  string defaultValue = ?;
  Type valueType = I8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def I8MemRef {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_122;
  string summary = "memref of 8-bit signless integer values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def I8Tensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_62;
  string summary = "tensor of 8-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def Idempotent {	// Trait NativeTrait NativeOpTrait
  string trait = "IsIdempotent";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def Index {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_28;
  string summary = "index";
  string cppClassName = "::mlir::IndexType";
  string description = "";
  string builderCall = "$_builder.getIndexType()";
}
def IndexAttr {	// Constraint AttrConstraint Attr TypedAttrBase
  Pred predicate = anonymous_166;
  string summary = "index attribute";
  string storageType = "::mlir::IntegerAttr";
  code returnType = [{ ::llvm::APInt }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIndexType(), $0)";
  string defaultValue = ?;
  Type valueType = Index;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def IndexElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase
  Pred predicate = anonymous_221;
  string summary = "index elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def IndexListArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_263;
  string summary = "Array of 64-bit integer array attributes";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = I64ArrayAttr;
}
def IndexTensor {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_82;
  string summary = "tensor of index values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def IntNonNegative {	// Constraint AttrConstraint
  Pred predicate = anonymous_275;
  string summary = "whose value is non-negative";
}
def IntPositive {	// Constraint AttrConstraint
  Pred predicate = anonymous_276;
  string summary = "whose value is positive";
}
def Involution {	// Trait NativeTrait NativeOpTrait
  string trait = "IsInvolution";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def IsBaseMemRefTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::BaseMemRefType>())";
}
def IsFixedVectorTypePred {	// Pred CPred
  code predExpr = [{($_self.isa<::mlir::VectorType>() &&
                                  !$_self.cast<VectorType>().isScalable())}];
}
def IsMemRefTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::MemRefType>())";
}
def IsNullAttr {	// Constraint AttrConstraint
  Pred predicate = anonymous_277;
  string summary = "empty attribute (for optional attributes)";
}
def IsScalableVectorTypePred {	// Pred CPred
  code predExpr = [{($_self.isa<::mlir::VectorType>() &&
                                   $_self.cast<VectorType>().isScalable())}];
}
def IsShapedTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::ShapedType>())";
}
def IsTensorTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::TensorType>())";
}
def IsTupleTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::TupleType>())";
}
def IsUnrankedMemRefTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::UnrankedMemRefType>())";
}
def IsUnrankedTensorTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::UnrankedTensorType>())";
}
def IsVectorOfAnyRankTypePred {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::VectorType>())";
}
def IsVectorTypePred {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_0, anonymous_1];
}
def IsolatedFromAbove {	// Trait NativeTrait NativeOpTrait
  string trait = "IsIsolatedFromAbove";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def LLVM_AnyAggregate {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_304;
  string summary = "LLVM aggregate type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_AnyFloat {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_289;
  string summary = "floating point LLVM type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_AnyNonAggregate {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_306;
  string summary = "LLVM-compatible non-aggregate type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_AnyPointer {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_290;
  string summary = "LLVM pointer type";
  string cppClassName = "::mlir::LLVM::LLVMPointerType";
  string description = "";
  string builderCall = "";
}
def LLVM_AnyStruct {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_297;
  string summary = "LLVM structure type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_AnyVector {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_307;
  string summary = "LLVM dialect-compatible vector type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_Dialect {	// Dialect
  string name = "llvm";
  string summary = ?;
  string description = ?;
  list<string> dependentDialects = [];
  string cppNamespace = "::mlir::LLVM";
  code extraClassDeclaration = [{
    /// Name of the data layout attributes.
    static StringRef getDataLayoutAttrName() { return "llvm.data_layout"; }
    static StringRef getAlignAttrName() { return "llvm.align"; }
    static StringRef getNoAliasAttrName() { return "llvm.noalias"; }
    static StringRef getNoAliasScopesAttrName() { return "noalias_scopes"; }
    static StringRef getAliasScopesAttrName() { return "alias_scopes"; }
    static StringRef getLoopAttrName() { return "llvm.loop"; }
    static StringRef getParallelAccessAttrName() { return "parallel_access"; }
    static StringRef getLoopOptionsAttrName() { return "options"; }
    static StringRef getAccessGroupsAttrName() { return "access_groups"; }
    static StringRef getStructAttrsAttrName() { return "llvm.struct_attrs"; }

    /// Verifies if the attribute is a well-formed value for "llvm.struct_attrs"
    static LogicalResult verifyStructAttr(
        Operation *op, Attribute attr, Type annotatedType);

    /// Verifies if the given string is a well-formed data layout descriptor.
    /// Uses `reportError` to report errors.
    static LogicalResult verifyDataLayoutString(
        StringRef descr, llvm::function_ref<void (const Twine &)> reportError);

    /// Name of the target triple attribute.
    static StringRef getTargetTripleAttrName() { return "llvm.target_triple"; }
  }];
  bit hasConstantMaterializer = 0;
  bit hasNonDefaultDestructor = 0;
  bit hasOperationAttrVerify = 1;
  bit hasRegionArgAttrVerify = 1;
  bit hasRegionResultAttrVerify = 1;
  bit hasOperationInterfaceFallback = 0;
  bit useDefaultAttributePrinterParser = 1;
  bit useDefaultTypePrinterParser = 1;
  bit hasCanonicalizer = 0;
  int emitAccessorPrefix = 1;
  bit isExtensible = 0;
}
def LLVM_FunctionType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_288;
  string summary = "LLVM function type";
  string cppClassName = "::mlir::LLVM::LLVMFunctionType";
  string description = "";
  string builderCall = "";
}
def LLVM_IntrPatterns {
  code operand = [{moduleTranslation.convertType(opInst.getOperand($0).getType())}];
  code result = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  code structResult = [{moduleTranslation.convertType(
        opInst.getResult(0).getType().cast<LLVM::LLVMStructType>()
              .getBody()[$0])}];
}
def LLVM_LoadableType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_303;
  string summary = "LLVM type with size";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_OneResultOpBuilder {	// OpBuilder
  dag dagParams = (ins "Type":$resultType, "ValueRange":$operands, anonymous_311:$attributes);
  code body = [{
    if (resultType) $_state.addTypes(resultType);
    $_state.addOperands(operands);
    for (auto namedAttr : attributes)
      $_state.addAttribute(namedAttr.getName(), namedAttr.getValue());
  }];
}
def LLVM_OpaqueStruct {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_299;
  string summary = "";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_PointerElementType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_300;
  string summary = "LLVM-compatible pointer element type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_PrimitiveType {	// Constraint TypeConstraint Type
  Pred predicate = anonymous_287;
  string summary = "primitive LLVM type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def LLVM_TerminatorPassthroughOpBuilder {	// OpBuilder
  dag dagParams = (ins "ValueRange":$operands, "SuccessorRange":$destinations, anonymous_311:$attributes);
  code body = [{
    $_state.addOperands(operands);
    $_state.addSuccessors(destinations);
    $_state.addAttributes(attributes);
  }];
}
def LLVM_TokenType {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_285;
  string summary = "LLVM token type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "::mlir::LLVM::LLVMTokenType::get($_builder.getContext())";
}
def LLVM_Type {	// Constraint TypeConstraint Type DialectType
  Pred predicate = anonymous_284;
  string summary = "LLVM dialect-compatible type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
  Dialect dialect = LLVM_Dialect;
}
def LLVM_VoidResultTypeOpBuilder {	// OpBuilder
  dag dagParams = (ins "Type":$resultType, "ValueRange":$operands, anonymous_311:$attributes);
  code body = [{
    assert(isCompatibleType(resultType) && "result must be an LLVM type");
    assert(resultType.isa<LLVMVoidType>() &&
           "for zero-result operands, only 'void' is accepted as result type");
    build($_builder, $_state, operands, attributes);
  }];
}
def LLVM_ZeroResultOpBuilder {	// OpBuilder
  dag dagParams = (ins "ValueRange":$operands, anonymous_311:$attributes);
  code body = [{
    $_state.addOperands(operands);
    for (auto namedAttr : attributes)
      $_state.addAttribute(namedAttr.getName(), namedAttr.getValue());
  }];
}
def LLVM_i8Ptr {	// Constraint TypeConstraint Type BuildableType LLVM_IntPtrBase
  Pred predicate = anonymous_296;
  string summary = "LLVM pointer to 8-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "::mlir::LLVM::LLVMPointerType::get(::mlir::IntegerType::get($_builder.getContext(), 8), 0)";
}
def LLVM_x86_amx_tdpbf16ps {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tdpbf16ps";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tdpbf16ps_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tdpbf16ps_internal";
}
def LLVM_x86_amx_tdpbssd {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tdpbssd";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tdpbssd_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tdpbssd_internal";
}
def LLVM_x86_amx_tdpbsud {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tdpbsud";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tdpbsud_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tdpbsud_internal";
}
def LLVM_x86_amx_tdpbusd {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tdpbusd";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tdpbusd_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tdpbusd_internal";
}
def LLVM_x86_amx_tdpbuud {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tdpbuud";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, AnyInteger, LLVM_Type, LLVM_Type, LLVM_Type);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tdpbuud_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tdpbuud_internal";
}
def LLVM_x86_amx_tileloadd64 {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tileloadd64";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, LLVM_AnyPointer, AnyInteger);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tileloadd64_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tileloadd64_internal";
}
def LLVM_x86_amx_tilestored64 {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tilestored64";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger, LLVM_AnyPointer, AnyInteger, LLVM_Type);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tilestored64_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tilestored64_internal";
}
def LLVM_x86_amx_tilezero {	// Op LLVM_OpBase Results LLVM_IntrOpBase AMX_IntrOp Arguments
  Dialect opDialect = AMX_Dialect;
  string opName = "tilezero";
  string cppNamespace = "::mlir::amx";
  string summary = "";
  string description = "";
  dag arguments = (ins AnyInteger, AnyInteger);
  dag results = (outs LLVM_Type:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = ?;
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 0;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  string extraClassDeclaration = ?;
  string extraClassDefinition = ?;
  code llvmBuilder = [{
    llvm::Module *module = builder.GetInsertBlock()->getModule();
    llvm::Function *fn = llvm::Intrinsic::getDeclaration(
        module,
        llvm::Intrinsic::x86_tilezero_internal,
        { 
        });
    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto *inst = builder.CreateCall(fn, operands);
    (void) inst;(void) inst;$res = inst;}];
  code resultPattern = [{moduleTranslation.convertType(opInst.getResult($0).getType())}];
  string llvmEnumName = "x86_tilezero_internal";
}
def MemAlloc {	// OpVariableDecorator SideEffect MemoryEffect MemAlloc
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Allocate";
  string resource = "::mlir::SideEffects::DefaultResource";
}
def MemFree {	// OpVariableDecorator SideEffect MemoryEffect MemFree
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Free";
  string resource = "::mlir::SideEffects::DefaultResource";
}
def MemRead {	// OpVariableDecorator SideEffect MemoryEffect MemRead
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Read";
  string resource = "::mlir::SideEffects::DefaultResource";
}
def MemRefsNormalizable {	// Trait NativeTrait NativeOpTrait
  string trait = "MemRefsNormalizable";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def MemWrite {	// OpVariableDecorator SideEffect MemoryEffect MemWrite
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  string interfaceTrait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string effect = "::mlir::MemoryEffects::Write";
  string resource = "::mlir::SideEffects::DefaultResource";
}
def MemoryEffectsOpInterface {	// Interface Trait NativeTrait InterfaceTrait OpInterfaceTrait OpInterface EffectOpInterfaceBase
  code description = [{
    An interface used to query information about the memory effects applied by
    an operation.
  }];
  string cppClassName = "MemoryEffectOpInterface";
  string cppNamespace = "::mlir";
  list<InterfaceMethod> methods = [anonymous_283];
  code extraClassDeclaration = [{
    /// Collect all of the effect instances that correspond to the given
    /// `Effect` and place them in 'effects'.
    template <typename Effect> void getEffects(
      SmallVectorImpl<::mlir::SideEffects::EffectInstance<
                                              ::mlir::MemoryEffects::Effect>> &effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return !llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation exhibits the given effect.
    template <typename Effect> bool hasEffect() {
      SmallVector<SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return llvm::any_of(effects, [](const auto &it) {
        return llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation only has the given effect.
    template <typename Effect> bool onlyHasEffect() {
      SmallVector<SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return !effects.empty() && llvm::all_of(effects, [](const auto &it) {
        return isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation has no effects.
    bool hasNoEffect() {
      SmallVector<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return effects.empty();
    }

    /// Returns true if the given operation has no effects for this interface.
    static bool hasNoEffect(Operation *op) {
      if (auto interface = dyn_cast<MemoryEffectOpInterface>(op))
        return interface.hasNoEffect();
      return op->hasTrait<::mlir::OpTrait::HasRecursiveSideEffects>();
    }

    /// Collect all of the effect instances that operate on the provided value
    /// and place them in 'effects'.
    void getEffectsOnValue(::mlir::Value value,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) { return it.getValue() != value; });
    }

    /// Return the effect of the given type `Effect` that is applied to the
    /// given value, or None if no effect exists.
    template <typename Effect>
    ::llvm::Optional<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>>
    getEffectOnValue(::mlir::Value value) {
      llvm::SmallVector<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      auto it = llvm::find_if(effects, [&](auto &it) {
        return isa<Effect>(it.getEffect()) && it.getValue() == value;
      });
      if (it == effects.end())
        return llvm::None;
      return *it;
    }

    /// Collect all of the effect instances that operate on the provided symbol
    /// reference and place them in 'effects'.
    void getEffectsOnSymbol(::mlir::SymbolRefAttr value,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return it.getSymbolRef() != value;
      });
    }

    /// Collect all of the effect instances that operate on the provided
    /// resource and place them in 'effects'.
    void getEffectsOnResource(::mlir::SideEffects::Resource *resource,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return it.getResource() != resource;
      });
    }
  }];
  string extraSharedClassDeclaration = "";
  string trait = "MemoryEffectOpInterface::Trait";
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = "::mlir::MemoryEffects::Effect";
}
def NoRegionArguments {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "NoRegionArguments";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def NoSideEffect {	// Trait NativeTrait InterfaceTrait OpInterfaceTrait SideEffectsTraitBase MemoryEffects
  string trait = "MemoryEffectOpInterface::Trait";
  string cppNamespace = "::mlir";
  string extraTraitClassDeclaration = "";
  code verify = [{}];
  bit verifyWithRegions = 0;
  list<Trait> dependentTraits = [];
  string baseEffectName = "::mlir::MemoryEffects::Effect";
  list<SideEffect> effects = [];
}
def NoTerminator {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "NoTerminator";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def NoneType {	// Constraint TypeConstraint Type BuildableType
  Pred predicate = anonymous_3;
  string summary = "none type";
  string cppClassName = "::mlir::NoneType";
  string description = "";
  string builderCall = "$_builder.getType<::mlir::NoneType>()";
}
def PredCombinerAnd {	// PredCombinerKind
}
def PredCombinerConcat {	// PredCombinerKind
}
def PredCombinerNot {	// PredCombinerKind
}
def PredCombinerOr {	// PredCombinerKind
}
def PredCombinerSubstLeaves {	// PredCombinerKind
}
def RecursiveSideEffects {	// Trait NativeTrait NativeOpTrait
  string trait = "HasRecursiveSideEffects";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def ResultsAreFloatLike {	// Trait NativeTrait NativeOpTrait
  string trait = "ResultsAreFloatLike";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def ResultsBroadcastableShape {	// Trait NativeTrait NativeOpTrait
  string trait = "ResultsBroadcastableShape";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def SI1 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_17;
  string summary = "1-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(1, /*isSigned=*/true)";
  int bitwidth = 1;
}
def SI16 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_19;
  string summary = "16-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(16, /*isSigned=*/true)";
  int bitwidth = 16;
}
def SI16Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_192;
  string summary = "16-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int16_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(16, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI1Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_188;
  string summary = "1-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "bool";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(1, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI32 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_20;
  string summary = "32-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(32, /*isSigned=*/true)";
  int bitwidth = 32;
}
def SI32Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_194;
  string summary = "32-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int32_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI64 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_21;
  string summary = "64-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(64, /*isSigned=*/true)";
  int bitwidth = 64;
}
def SI64Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_196;
  string summary = "64-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int64_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SI8 {	// Constraint TypeConstraint Type BuildableType SI
  Pred predicate = anonymous_18;
  string summary = "8-bit signed integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8, /*isSigned=*/true)";
  int bitwidth = 8;
}
def SI8Attr {	// Constraint AttrConstraint Attr TypedAttrBase SignedIntegerAttrBase TypedSignedIntegerAttrBase
  Pred predicate = anonymous_190;
  string summary = "8-bit signed integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "int8_t";
  string convertFromStorage = "$_self.getValue().getSExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(8, /*isSigned=*/true), $0)";
  string defaultValue = ?;
  Type valueType = SI8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SameOperandsAndResultElementType {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsAndResultElementType";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def SameOperandsAndResultShape {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsAndResultShape";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def SameOperandsElementType {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsElementType";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def SameOperandsShape {	// Trait NativeTrait NativeOpTrait
  string trait = "SameOperandsShape";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def SameTypeOperands {	// Trait NativeTrait NativeOpTrait
  string trait = "SameTypeOperands";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def SameVariadicOperandSize {	// Trait GenInternalTrait GenInternalOpTrait
  string trait = "::mlir::OpTrait::SameVariadicOperandSize";
  list<Trait> dependentTraits = [];
}
def SameVariadicResultSize {	// Trait GenInternalTrait GenInternalOpTrait
  string trait = "::mlir::OpTrait::SameVariadicResultSize";
  list<Trait> dependentTraits = [];
}
def Scalarizable {	// Trait NativeTrait NativeOpTrait
  string trait = "Scalarizable";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [Elementwise];
}
def SignlessIntegerLike {	// Constraint TypeConstraint TypeOrContainer
  Pred predicate = anonymous_149;
  string summary = "signless-integer-like";
  string cppClassName = "::mlir::Type";
}
def SignlessIntegerLikeOfAnyRank {	// Constraint TypeConstraint TypeOrContainerOfAnyRank
  Pred predicate = anonymous_152;
  string summary = "signless-integer-like";
  string cppClassName = "::mlir::Type";
}
def SignlessIntegerOrFloatLike {	// Constraint TypeConstraint
  Pred predicate = anonymous_162;
  string summary = "signless-integer-like or floating-point-like";
  string cppClassName = "::mlir::Type";
}
def SingleBlock {	// Trait NativeTrait NativeOpTrait StructuralOpTrait
  string trait = "SingleBlock";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def StrArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_257;
  string summary = "string array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getStrArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = StrAttr;
}
def StrAttr {	// Constraint AttrConstraint Attr StringBasedAttr
  Pred predicate = anonymous_212;
  string summary = "string attribute";
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def StringElementsAttr {	// Constraint AttrConstraint Attr ElementsAttrBase
  Pred predicate = anonymous_234;
  string summary = "string elements attribute";
  code storageType = [{ ::mlir::DenseElementsAttr }];
  code returnType = [{ ::mlir::DenseElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SymbolNameAttr {	// Constraint AttrConstraint Attr StringBasedAttr
  Pred predicate = anonymous_212;
  string summary = "string attribute";
  code storageType = [{ ::mlir::StringAttr }];
  code returnType = [{ ::llvm::StringRef }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getStringAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def SymbolRefArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_268;
  string summary = "symbol ref array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = ?;
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = SymbolRefAttr;
}
def SymbolRefAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_264;
  string summary = "symbol reference attribute";
  code storageType = [{ ::mlir::SymbolRefAttr }];
  code returnType = [{ ::mlir::SymbolRefAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::SymbolRefAttr::get($_builder.getContext(), $0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def Tensorizable {	// Trait NativeTrait NativeOpTrait
  string trait = "Tensorizable";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [Elementwise];
}
def Terminator {	// Trait NativeTrait NativeOpTrait
  string trait = "IsTerminator";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [];
}
def TileLoadOp {	// Op AMX_Op
  Dialect opDialect = AMX_Dialect;
  string opName = "tile_load";
  string cppNamespace = "::mlir::amx";
  string summary = "tile load operation";
  code description = [{
    Loads a tile from memory defined by a base and indices, with the
    shape defined by the 2-dim vector type of the result. This is
    eventually lowered into the "tileloadd" instruction with the
    corresponding tile configuration.

    Example:

    ```mlir
      %0 = amx.tile_load %arg0[%c0, %c0] : memref<?x?xi8> into vector<16x64xi8>
    ```
  }];
  dag arguments = (ins anonymous_325:$base, anonymous_326:$indices);
  dag results = (outs anonymous_313:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = "$base `[` $indices `]` attr-dict `:` type($base) `into` type($res)";
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 1;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [NoSideEffect];
  code extraClassDeclaration = [{
    MemRefType getMemRefType() {
      return base().getType().cast<MemRefType>();
    }
    VectorType getVectorType() {
      return res().getType().cast<VectorType>();
    }
  }];
  string extraClassDefinition = ?;
}
def TileMulFOp {	// Op AMX_Op
  Dialect opDialect = AMX_Dialect;
  string opName = "tile_mulf";
  string cppNamespace = "::mlir::amx";
  string summary = "tile multiplication operation (floating-point)";
  code description = [{
    Multiplies a "m x k" tile with a "k x n" tile and accumulates the results
    into a "m x n" destination tile. Supports "f32 <- bf16 x bf16" (with
    pairs of "bf16"). The operation is eventually lowered into the
    "tdpbf16ps" instruction with the corresponding tile configuration.

    Example:

    ```mlir
      %0 = amx.tile_mulf %a, %b, %c
        : vector<16x32xbf16>, vector<16x32xbf16>, vector<16x16xf32>
    ```
  }];
  dag arguments = (ins anonymous_330:$lhs, anonymous_330:$rhs, anonymous_330:$acc);
  dag results = (outs anonymous_330:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = "$lhs `,` $rhs `,` $acc attr-dict `:` type($lhs) `,` type($rhs) `,` type($acc) ";
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 1;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [NoSideEffect, anonymous_328];
  code extraClassDeclaration = [{
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
  string extraClassDefinition = ?;
}
def TileMulIOp {	// Op AMX_Op
  Dialect opDialect = AMX_Dialect;
  string opName = "tile_muli";
  string cppNamespace = "::mlir::amx";
  string summary = "tile multiplication operation (integer)";
  code description = [{
    Multiplies a "m x k" tile with a "k x n" tile and accumulates the results
    into a "m x n" destination tile. Supports all "si32 <- s/ui8 x s/ui8"
    combinations (4 bytes packed into dwords in the columns of both the
    source operand tiles; the zero or sign extension is specified with
    the attributes and default to sign extended). The operation is eventually
    lowered into one of the "tdpbssd", "tdpbsud", "tdpbusd", or "tdpbuud"
    instructions with the corresponding tile configuration.

    Example:

    ```mlir
      %0 = amx.tile_muli %a zext, %b zext, %c
        : vector<16x64xi8>, vector<16x64xi8>, vector<16x16xi32>
    ```
  }];
  dag arguments = (ins anonymous_338:$lhs, anonymous_338:$rhs, anonymous_338:$acc, UnitAttr:$isZextLhs, UnitAttr:$isZextRhs);
  dag results = (outs anonymous_338:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = "$lhs (`zext` $isZextLhs^)? `,` $rhs (`zext` $isZextRhs^)? `,` $acc attr-dict `:` type($lhs) `,` type($rhs) `,` type($acc) ";
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 1;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [NoSideEffect, anonymous_328];
  code extraClassDeclaration = [{
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
  string extraClassDefinition = ?;
}
def TileStoreOp {	// Op AMX_Op
  Dialect opDialect = AMX_Dialect;
  string opName = "tile_store";
  string cppNamespace = "::mlir::amx";
  string summary = "tile store operation";
  code description = [{
    Stores a tile to memory defined by a base and indices, with the
    shape defined by the 2-dim vector type of the value. This is
    eventually lowered into the "tilestored" instruction with the
    corresponding tile configuration.

    Example:

    ```mlir
      amx.tile_store %arg1[%c0, %c0], %0 : memref<?x?xi8>, vector<16x64xi8>
    ```
  }];
  dag arguments = (ins anonymous_327:$base, anonymous_326:$indices, anonymous_313:$val);
  dag results = (outs);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = "$base `[` $indices `]` `,` $val attr-dict `:` type($base) `,` type($val)";
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 1;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [];
  code extraClassDeclaration = [{
    MemRefType getMemRefType() {
      return base().getType().cast<MemRefType>();
    }
    VectorType getVectorType() {
      return val().getType().cast<VectorType>();
    }
  }];
  string extraClassDefinition = ?;
}
def TileZeroOp {	// Op AMX_Op
  Dialect opDialect = AMX_Dialect;
  string opName = "tile_zero";
  string cppNamespace = "::mlir::amx";
  string summary = "tile zero operation";
  code description = [{
    Zeroes the destination tile, with the shape defined by the 2-dim
    vector type of the result. This is eventually lowered into the
    "tilezero" instruction with the corresponding tile configuration.

    Example:

    ```mlir
      %0 = amx.tile_zero : vector<16x16xbf16>
    ```
  }];
  dag arguments = (ins);
  dag results = (outs anonymous_313:$res);
  dag regions = (region);
  dag successors = (successor);
  list<OpBuilder> builders = ?;
  bit skipDefaultBuilders = 0;
  string assemblyFormat = "attr-dict `:` type($res)";
  bit hasCustomAssemblyFormat = 0;
  bit hasVerifier = 1;
  bit hasRegionVerifier = 0;
  bit hasCanonicalizer = 0;
  bit hasCanonicalizeMethod = 0;
  bit hasFolder = 0;
  list<Trait> traits = [NoSideEffect];
  code extraClassDeclaration = [{
    VectorType getVectorType() {
      return res().getType().cast<VectorType>();
    }
  }];
  string extraClassDefinition = ?;
}
def TypeArrayAttr {	// Constraint AttrConstraint Attr ArrayAttrBase TypedArrayAttrBase
  Pred predicate = anonymous_260;
  string summary = "type array attribute";
  code storageType = [{ ::mlir::ArrayAttr }];
  code returnType = [{ ::mlir::ArrayAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "$_builder.getTypeArrayAttr($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
  Attr elementAttr = TypeAttr;
}
def TypeAttr {	// Constraint AttrConstraint Attr TypeAttrBase
  Pred predicate = anonymous_215;
  string summary = "any type attribute";
  code storageType = [{ ::mlir::TypeAttr }];
  string returnType = "::mlir::Type";
  string convertFromStorage = "$_self.getValue().cast<::mlir::Type>()";
  string constBuilderCall = "::mlir::TypeAttr::get($0)";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI1 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_23;
  string summary = "1-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(1, /*isSigned=*/false)";
  int bitwidth = 1;
}
def UI16 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_25;
  string summary = "16-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(16, /*isSigned=*/false)";
  int bitwidth = 16;
}
def UI16Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_202;
  string summary = "16-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint16_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(16, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI16;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI1Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_198;
  string summary = "1-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "bool";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(1, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI1;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI32 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_26;
  string summary = "32-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(32, /*isSigned=*/false)";
  int bitwidth = 32;
}
def UI32Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_204;
  string summary = "32-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint32_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(32, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI32;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI64 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_27;
  string summary = "64-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(64, /*isSigned=*/false)";
  int bitwidth = 64;
}
def UI64Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_206;
  string summary = "64-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint64_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(64, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI64;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UI8 {	// Constraint TypeConstraint Type BuildableType UI
  Pred predicate = anonymous_24;
  string summary = "8-bit unsigned integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8, /*isSigned=*/false)";
  int bitwidth = 8;
}
def UI8Attr {	// Constraint AttrConstraint Attr TypedAttrBase UnsignedIntegerAttrBase TypedUnsignedIntegerAttrBase
  Pred predicate = anonymous_200;
  string summary = "8-bit unsigned integer attribute";
  string storageType = "::mlir::IntegerAttr";
  string returnType = "uint8_t";
  string convertFromStorage = "$_self.getValue().getZExtValue()";
  string constBuilderCall = "$_builder.getIntegerAttr($_builder.getIntegerType(8, /*isSigned=*/false), $0)";
  string defaultValue = ?;
  Type valueType = UI8;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def UnitAttr {	// Constraint AttrConstraint Attr
  Pred predicate = anonymous_216;
  string summary = "unit attribute";
  code storageType = [{ ::mlir::UnitAttr }];
  string returnType = "bool";
  string convertFromStorage = "$_self != nullptr";
  string constBuilderCall = "$_builder.getUnitAttr()";
  string defaultValue = ?;
  Type valueType = NoneType;
  bit isOptional = 1;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def Vectorizable {	// Trait NativeTrait NativeOpTrait
  string trait = "Vectorizable";
  string cppNamespace = "::mlir::OpTrait";
  list<Trait> dependentTraits = [Elementwise];
}
def anonymous_0 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::VectorType>())";
}
def anonymous_1 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::VectorType>().getRank() > 0)";
}
def anonymous_10 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger())";
}
def anonymous_100 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_99];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_101 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_100];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_102 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_101];
}
def anonymous_103 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_105];
}
def anonymous_104 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::ShapedType>().getRank()
                         == 0)}];
}
def anonymous_105 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_104];
}
def anonymous_106 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_108];
}
def anonymous_107 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::ShapedType>().getRank()
                         == 1)}];
}
def anonymous_108 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_107];
}
def anonymous_109 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_111];
}
def anonymous_11 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(1))";
}
def anonymous_110 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::ShapedType>().getRank()
                         == 2)}];
}
def anonymous_111 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_110];
}
def anonymous_112 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_114];
}
def anonymous_113 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::ShapedType>().getRank()
                         == 3)}];
}
def anonymous_114 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_113];
}
def anonymous_115 {	// Pred CombinedPred And HasAnyRankOfPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [HasRankPred, anonymous_117];
}
def anonymous_116 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::ShapedType>().getRank()
                         == 4)}];
}
def anonymous_117 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_116];
}
def anonymous_118 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsUnrankedMemRefTypePred, anonymous_42];
}
def anonymous_119 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_42];
}
def anonymous_12 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(8))";
}
def anonymous_120 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_118, anonymous_119];
}
def anonymous_121 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_56];
}
def anonymous_122 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_61];
}
def anonymous_123 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_66];
}
def anonymous_124 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_71];
}
def anonymous_125 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_76];
}
def anonymous_126 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_86];
}
def anonymous_127 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_91];
}
def anonymous_128 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_96];
}
def anonymous_129 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsMemRefTypePred, anonymous_101];
}
def anonymous_13 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(16))";
}
def anonymous_130 {	// Constraint TypeConstraint Type ShapedContainerType MemRefOf
  Pred predicate = anonymous_119;
  string summary = "memref of any type values";
  string cppClassName = "::mlir::MemRefType";
  string description = "";
  string builderCall = "";
}
def anonymous_131 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_119, HasStaticShapePred];
}
def anonymous_132 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_119, HasStridesPred];
}
def anonymous_133 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_135;
  string summary = "vector of 1-bit signless integer values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_134 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_54;
  string summary = "1-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_135 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_56];
}
def anonymous_136 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_57;
  string summary = "tensor of 1-bit signless integer values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_137 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_11, anonymous_135, anonymous_57];
}
def anonymous_138 {	// Constraint TypeConstraint Type ShapedContainerType VectorOfAnyRankOf
  Pred predicate = anonymous_139;
  string summary = "vector of 1-bit signless integer values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_139 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorOfAnyRankTypePred, anonymous_56];
}
def anonymous_14 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(32))";
}
def anonymous_140 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_11, anonymous_139, anonymous_57];
}
def anonymous_141 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_146;
  string summary = "vector of signless integer or index values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_142 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_143;
  string summary = "signless integer or index";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_143 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_29];
}
def anonymous_144 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_143];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_145 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_144];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_146 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_145];
}
def anonymous_147 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_148;
  string summary = "tensor of signless integer or index values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_148 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_145];
}
def anonymous_149 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_29, anonymous_146, anonymous_148];
}
def anonymous_15 {	// Pred CPred
  string predExpr = "($_self.isSignlessInteger(64))";
}
def anonymous_150 {	// Constraint TypeConstraint Type ShapedContainerType VectorOfAnyRankOf
  Pred predicate = anonymous_151;
  string summary = "vector of signless integer or index values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_151 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorOfAnyRankTypePred, anonymous_145];
}
def anonymous_152 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_29, anonymous_151, anonymous_148];
}
def anonymous_153 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_158;
  string summary = "vector of floating-point values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_154 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_155;
  string summary = "floating-point";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_155 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_30];
}
def anonymous_156 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_155];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_157 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_156];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_158 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_157];
}
def anonymous_159 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_160;
  string summary = "tensor of floating-point values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_16 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger())";
}
def anonymous_160 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_157];
}
def anonymous_161 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_30, anonymous_158, anonymous_160];
}
def anonymous_162 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_149, anonymous_161];
}
def anonymous_163 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::BoolAttr>())";
}
def anonymous_164 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::IntegerAttr>())";
}
def anonymous_165 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isa<::mlir::IndexType>())";
}
def anonymous_166 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_165];
}
def anonymous_167 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isInteger(1))";
}
def anonymous_168 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_167];
}
def anonymous_169 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isInteger(8))";
}
def anonymous_17 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(1))";
}
def anonymous_170 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_169];
}
def anonymous_171 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isInteger(16))";
}
def anonymous_172 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_171];
}
def anonymous_173 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isInteger(32))";
}
def anonymous_174 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_173];
}
def anonymous_175 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isInteger(64))";
}
def anonymous_176 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_175];
}
def anonymous_177 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(1))";
}
def anonymous_178 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_177];
}
def anonymous_179 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(8))";
}
def anonymous_18 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(8))";
}
def anonymous_180 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_179];
}
def anonymous_181 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(16))";
}
def anonymous_182 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_181];
}
def anonymous_183 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(32))";
}
def anonymous_184 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_183];
}
def anonymous_185 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignlessInteger(64))";
}
def anonymous_186 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_185];
}
def anonymous_187 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(1))";
}
def anonymous_188 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_187];
}
def anonymous_189 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(8))";
}
def anonymous_19 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(16))";
}
def anonymous_190 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_189];
}
def anonymous_191 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(16))";
}
def anonymous_192 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_191];
}
def anonymous_193 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(32))";
}
def anonymous_194 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_193];
}
def anonymous_195 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isSignedInteger(64))";
}
def anonymous_196 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_195];
}
def anonymous_197 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(1))";
}
def anonymous_198 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_197];
}
def anonymous_199 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(8))";
}
def anonymous_2 {	// Pred CPred
  string predExpr = "(true)";
}
def anonymous_20 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(32))";
}
def anonymous_200 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_199];
}
def anonymous_201 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(16))";
}
def anonymous_202 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_201];
}
def anonymous_203 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(32))";
}
def anonymous_204 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_203];
}
def anonymous_205 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getType().isUnsignedInteger(64))";
}
def anonymous_206 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_164, anonymous_205];
}
def anonymous_207 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::FloatAttr>())";
}
def anonymous_208 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::FloatAttr>().getType().isF32())";
}
def anonymous_209 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_207, anonymous_208];
}
def anonymous_21 {	// Pred CPred
  string predExpr = "($_self.isSignedInteger(64))";
}
def anonymous_210 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::FloatAttr>().getType().isF64())";
}
def anonymous_211 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_207, anonymous_210];
}
def anonymous_212 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::StringAttr>())";
}
def anonymous_213 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::TypeAttr>())";
}
def anonymous_214 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::TypeAttr>().getValue().isa<::mlir::Type>())";
}
def anonymous_215 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_213, anonymous_214];
}
def anonymous_216 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::UnitAttr>())";
}
def anonymous_217 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::DictionaryAttr>())";
}
def anonymous_218 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::ElementsAttr>())";
}
def anonymous_219 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::DenseIntElementsAttr>())";
}
def anonymous_22 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger())";
}
def anonymous_220 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::DenseIntElementsAttr>()
                                      .getType()
                                      .getElementType()
                                      .isIndex())}];
}
def anonymous_221 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_219, anonymous_220];
}
def anonymous_222 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_219, anonymous_2];
}
def anonymous_223 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::DenseIntElementsAttr>().getType().getElementType().isInteger(32))";
}
def anonymous_224 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_219, anonymous_223];
}
def anonymous_225 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::DenseIntElementsAttr>().getType().getElementType().isInteger(64))";
}
def anonymous_226 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_219, anonymous_225];
}
def anonymous_227 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::DenseIntElementsAttr>().getType().getElementType().isSignlessInteger(32))";
}
def anonymous_228 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_219, anonymous_227];
}
def anonymous_229 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::DenseIntElementsAttr>().getType().getElementType().isSignlessInteger(64))";
}
def anonymous_23 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(1))";
}
def anonymous_230 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_219, anonymous_229];
}
def anonymous_231 {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_228;
  string summary = "32-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(32)), ::llvm::makeArrayRef($0)).cast<::mlir::DenseIntElementsAttr>()";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def anonymous_232 {	// Constraint AttrConstraint Attr ElementsAttrBase IntElementsAttrBase SignlessIntElementsAttr
  Pred predicate = anonymous_230;
  string summary = "64-bit signless integer elements attribute";
  code storageType = [{ ::mlir::DenseIntElementsAttr }];
  code returnType = [{ ::mlir::DenseIntElementsAttr }];
  string convertFromStorage = "$_self";
  string constBuilderCall = "::mlir::DenseElementsAttr::get(::mlir::RankedTensorType::get({}, $_builder.getIntegerType(64)), ::llvm::makeArrayRef($0)).cast<::mlir::DenseIntElementsAttr>()";
  string defaultValue = ?;
  Type valueType = ?;
  bit isOptional = 0;
  Attr baseAttr = ?;
  string cppNamespace = "";
  string description = "";
}
def anonymous_233 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::DenseFPElementsAttr>() &&$_self.cast<::mlir::DenseElementsAttr>().getType().getElementType().isF64())";
}
def anonymous_234 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::DenseStringElementsAttr>())";
}
def anonymous_235 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::AffineMapAttr>())";
}
def anonymous_236 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::ArrayAttr>())";
}
def anonymous_237 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_235];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_238 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_237];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_239 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_238];
}
def anonymous_24 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(8))";
}
def anonymous_240 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_163];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_241 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_240];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_242 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_241];
}
def anonymous_243 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_184];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_244 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_243];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_245 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_244];
}
def anonymous_246 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_186];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_247 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_246];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_248 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_247];
}
def anonymous_249 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_209];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_25 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(16))";
}
def anonymous_250 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_249];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_251 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_250];
}
def anonymous_252 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_211];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_253 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_252];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_254 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_253];
}
def anonymous_255 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_212];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_256 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_255];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_257 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_256];
}
def anonymous_258 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_215];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_259 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_258];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_26 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(32))";
}
def anonymous_260 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_259];
}
def anonymous_261 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_248];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_262 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_261];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_263 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_262];
}
def anonymous_264 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::SymbolRefAttr>())";
}
def anonymous_265 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::FlatSymbolRefAttr>())";
}
def anonymous_266 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_264];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_267 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_266];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_268 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_267];
}
def anonymous_269 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_265];
  string pattern = "$_self";
  string replacement = "attr";
}
def anonymous_27 {	// Pred CPred
  string predExpr = "($_self.isUnsignedInteger(64))";
}
def anonymous_270 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_269];
  string prefix = "::llvm::all_of($_self.cast<::mlir::ArrayAttr>(), [&](::mlir::Attribute attr) { return attr && (";
  string suffix = "); })";
}
def anonymous_271 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_236, anonymous_270];
}
def anonymous_272 {	// Pred CPred
  string predExpr = "($_self == $_builder.getBoolAttr(false))";
}
def anonymous_273 {	// Pred CPred
  string predExpr = "($_self == $_builder.getBoolAttr(true))";
}
def anonymous_274 {	// Pred CPred
  string predExpr = "($_self == $_builder.getUnitAttr())";
}
def anonymous_275 {	// Pred CPred
  string predExpr = "(!$_self.cast<::mlir::IntegerAttr>().getValue().isNegative())";
}
def anonymous_276 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::IntegerAttr>().getValue().isStrictlyPositive())";
}
def anonymous_277 {	// Pred CPred
  string predExpr = "(!$_self)";
}
def anonymous_278 {	// StrFunc ElementCount
  string result = "$_self.getType().cast<::mlir::ShapedType>().getNumElements()";
}
def anonymous_279 {	// StrFunc ElementType
  string result = "getElementTypeOrSelf($_self)";
}
def anonymous_28 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::IndexType>())";
}
def anonymous_280 {	// StrFunc Rank
  string result = "$_self.getType().cast<::mlir::ShapedType>().getRank()";
}
def anonymous_281 {	// StrFunc Shape
  string result = "$_self.getType().cast<::mlir::ShapedType>().getShape()";
}
def anonymous_282 {	// Pred CPred
  string predExpr = "()";
}
def anonymous_283 {	// InterfaceMethod
  code description = [{
        Collects all of the operation's effects into `effects`.
      }];
  string name = "getEffects";
  string returnType = "void";
  dag arguments = (ins "::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &":$effects);
  code body = [{}];
  code defaultBody = [{}];
}
def anonymous_284 {	// Pred CPred
  string predExpr = "(::mlir::LLVM::isCompatibleOuterType($_self))";
}
def anonymous_285 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::LLVM::LLVMTokenType>())";
}
def anonymous_286 {	// Pred CPred
  string predExpr = "(!$_self.isa<::mlir::LLVM::LLVMVoidType, ::mlir::LLVM::LLVMFunctionType>())";
}
def anonymous_287 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_284, anonymous_286];
}
def anonymous_288 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::LLVM::LLVMFunctionType>())";
}
def anonymous_289 {	// Pred CPred
  string predExpr = "(::mlir::LLVM::isCompatibleFloatingPointType($_self))";
}
def anonymous_29 {	// Pred CPred
  string predExpr = "($_self.isSignlessIntOrIndex())";
}
def anonymous_290 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::LLVM::LLVMPointerType>())";
}
def anonymous_291 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::LLVM::LLVMPointerType>().isOpaque())";
}
def anonymous_292 {	// Constraint TypeConstraint Type BuildableType I
  Pred predicate = anonymous_12;
  string summary = "8-bit signless integer";
  string cppClassName = "::mlir::IntegerType";
  string description = "";
  string builderCall = "$_builder.getIntegerType(8)";
  int bitwidth = 8;
}
def anonymous_293 {	// Constraint TypeConstraint Type LLVM_PointerTo
  Pred predicate = anonymous_296;
  string summary = "LLVM pointer to 8-bit signless integer";
  string cppClassName = "::mlir::LLVM::LLVMPointerType";
  string description = "";
  string builderCall = "";
}
def anonymous_294 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_12];
  string pattern = "$_self";
  string replacement = "$_self.cast<::mlir::LLVM::LLVMPointerType>().getElementType()";
}
def anonymous_295 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_291, anonymous_294];
}
def anonymous_296 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_290, anonymous_295];
}
def anonymous_297 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::LLVM::LLVMStructType>())";
}
def anonymous_298 {	// Pred CPred
  string predExpr = "($_self.cast<::mlir::LLVM::LLVMStructType>().isOpaque())";
}
def anonymous_299 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_297, anonymous_298];
}
def anonymous_3 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::NoneType>())";
}
def anonymous_30 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::FloatType>())";
}
def anonymous_300 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::LLVM::PointerElementTypeInterface>())";
}
def anonymous_301 {	// Pred CombinedPred Neg
  PredCombinerKind kind = PredCombinerNot;
  list<Pred> children = [anonymous_299];
}
def anonymous_302 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_287, anonymous_301];
}
def anonymous_303 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_302, anonymous_300];
}
def anonymous_304 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::LLVM::LLVMStructType, ::mlir::LLVM::LLVMArrayType>())";
}
def anonymous_305 {	// Pred CombinedPred Neg
  PredCombinerKind kind = PredCombinerNot;
  list<Pred> children = [anonymous_304];
}
def anonymous_306 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_284, anonymous_305];
}
def anonymous_307 {	// Pred CPred
  string predExpr = "(::mlir::LLVM::isCompatibleVectorType($_self))";
}
def anonymous_308 {	// ListIntSubst
  list<string> lst = ["moduleTranslation.convertType(opInst.getOperand(0).getType())"];
}
def anonymous_309 {	// Constraint AttrConstraint Attr DefaultValuedAttr
  Pred predicate = anonymous_163;
  string summary = "bool attribute";
  code storageType = [{ ::mlir::BoolAttr }];
  code returnType = [{ bool }];
  string convertFromStorage = "$_self.getValue()";
  string constBuilderCall = "$_builder.getBoolAttr($0)";
  string defaultValue = "false";
  Type valueType = I1;
  bit isOptional = 0;
  Attr baseAttr = BoolAttr;
  string cppNamespace = "";
  string description = "";
}
def anonymous_31 {	// Pred CPred
  string predExpr = "($_self.isF16())";
}
def anonymous_310 {	// ListIntSubst
  list<string> lst = ["moduleTranslation.convertType(opInst.getOperand(1).getType())"];
}
def anonymous_311 {	// CArg
  string type = "ArrayRef<NamedAttribute>";
  string defaultValue = "{}";
}
def anonymous_312 {	// ListIntSubst
  list<string> lst = [];
}
def anonymous_313 {	// Constraint TypeConstraint Type VectorOfRankAndType
  Pred predicate = anonymous_324;
  string summary = "vector of 32-bit float or bfloat16 type or 32-bit signless integer or 8-bit signless integer values of ranks 2";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_314 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_319;
  string summary = "vector of 32-bit float or bfloat16 type or 32-bit signless integer or 8-bit signless integer values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_315 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_316;
  string summary = "32-bit float or bfloat16 type or 32-bit signless integer or 8-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_316 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_32, anonymous_36, anonymous_14, anonymous_12];
}
def anonymous_317 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_316];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_318 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_317];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_319 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_318];
}
def anonymous_32 {	// Pred CPred
  string predExpr = "($_self.isF32())";
}
def anonymous_320 {	// Constraint TypeConstraint Type VectorOfRank
  Pred predicate = anonymous_321;
  string summary = " of ranks 2";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_321 {	// Pred CombinedPred And IsVectorOfRankPred
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_323];
}
def anonymous_322 {	// Pred CPred
  code predExpr = [{($_self.cast<::mlir::VectorType>().getRank()
                           == 2)}];
}
def anonymous_323 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_322];
}
def anonymous_324 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_319, anonymous_321];
}
def anonymous_325 {	// OpVariable Arg
  Constraint constraint = AnyMemRef;
  string summary = "load base";
  list<OpVariableDecorator> decorators = [MemRead];
}
def anonymous_326 {	// Constraint TypeConstraint Variadic
  Pred predicate = anonymous_28;
  string summary = "index";
  string cppClassName = "::mlir::IndexType";
  Type baseType = Index;
  int minSize = 0;
}
def anonymous_327 {	// OpVariable Arg
  Constraint constraint = AnyMemRef;
  string summary = "store base";
  list<OpVariableDecorator> decorators = [MemWrite];
}
def anonymous_328 {	// Trait PredTrait PredOpTrait AllMatchSameOperatorTrait AllTypesMatch
  string summary = "all of {acc, res} have same type";
  Pred predicate = anonymous_329;
  list<Trait> dependentTraits = [];
  list<string> values = ["acc", "res"];
}
def anonymous_329 {	// Pred CPred AllMatchPred AllMatchSameOperatorPred
  string predExpr = "(::llvm::is_splat(::llvm::makeArrayRef({$acc.getType(), $res.getType()})))";
}
def anonymous_33 {	// Pred CPred
  string predExpr = "($_self.isF64())";
}
def anonymous_330 {	// Constraint TypeConstraint Type VectorOfRankAndType
  Pred predicate = anonymous_337;
  string summary = "vector of 32-bit float or bfloat16 type values of ranks 2";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_331 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_336;
  string summary = "vector of 32-bit float or bfloat16 type values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_332 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_333;
  string summary = "32-bit float or bfloat16 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_333 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_32, anonymous_36];
}
def anonymous_334 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_333];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_335 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_334];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_336 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_335];
}
def anonymous_337 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_336, anonymous_321];
}
def anonymous_338 {	// Constraint TypeConstraint Type VectorOfRankAndType
  Pred predicate = anonymous_345;
  string summary = "vector of 32-bit signless integer or 8-bit signless integer values of ranks 2";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_339 {	// Constraint TypeConstraint Type ShapedContainerType VectorOf
  Pred predicate = anonymous_344;
  string summary = "vector of 32-bit signless integer or 8-bit signless integer values";
  string cppClassName = "::mlir::VectorType";
  string description = "";
  string builderCall = "";
}
def anonymous_34 {	// Pred CPred
  string predExpr = "($_self.isF80())";
}
def anonymous_340 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_341;
  string summary = "32-bit signless integer or 8-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_341 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_14, anonymous_12];
}
def anonymous_342 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_341];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_343 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_342];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_344 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_343];
}
def anonymous_345 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_344, anonymous_321];
}
def anonymous_346 {	// ListIntSubst
  list<string> lst = [];
}
def anonymous_35 {	// Pred CPred
  string predExpr = "($_self.isF128())";
}
def anonymous_36 {	// Pred CPred
  string predExpr = "($_self.isBF16())";
}
def anonymous_37 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::ComplexType>())";
}
def anonymous_38 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::FunctionType>())";
}
def anonymous_39 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_40;
  string summary = "any type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_4 {	// Pred CPred
  string predExpr = "($_self.isa<::mlir::IntegerType>())";
}
def anonymous_40 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_2];
}
def anonymous_41 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_40];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_42 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_41];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_43 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorTypePred, anonymous_42];
}
def anonymous_44 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsVectorOfAnyRankTypePred, anonymous_42];
}
def anonymous_45 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsFixedVectorTypePred, anonymous_42];
}
def anonymous_46 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsScalableVectorTypePred, anonymous_42];
}
def anonymous_47 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsShapedTypePred, anonymous_42];
}
def anonymous_48 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, HasRankPred];
}
def anonymous_49 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_42];
}
def anonymous_5 {	// Pred CPred
  string predExpr = "($_self.isInteger(1))";
}
def anonymous_50 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_48, anonymous_42];
}
def anonymous_51 {	// Constraint TypeConstraint Type ShapedContainerType TensorOf
  Pred predicate = anonymous_49;
  string summary = "tensor of any type values";
  string cppClassName = "::mlir::TensorType";
  string description = "";
  string builderCall = "";
}
def anonymous_52 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [anonymous_49, HasStaticShapePred];
}
def anonymous_53 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_54;
  string summary = "1-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_54 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_11];
}
def anonymous_55 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_54];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_56 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_55];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_57 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_56];
}
def anonymous_58 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_59;
  string summary = "8-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_59 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_12];
}
def anonymous_6 {	// Pred CPred
  string predExpr = "($_self.isInteger(8))";
}
def anonymous_60 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_59];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_61 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_60];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_62 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_61];
}
def anonymous_63 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_64;
  string summary = "16-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_64 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_13];
}
def anonymous_65 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_64];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_66 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_65];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_67 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_66];
}
def anonymous_68 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_69;
  string summary = "32-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_69 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_14];
}
def anonymous_7 {	// Pred CPred
  string predExpr = "($_self.isInteger(16))";
}
def anonymous_70 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_69];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_71 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_70];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_72 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_71];
}
def anonymous_73 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_74;
  string summary = "64-bit signless integer";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_74 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_15];
}
def anonymous_75 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_74];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_76 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_75];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_77 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_76];
}
def anonymous_78 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_79;
  string summary = "index";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_79 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_28];
}
def anonymous_8 {	// Pred CPred
  string predExpr = "($_self.isInteger(32))";
}
def anonymous_80 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_79];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_81 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_80];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_82 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_81];
}
def anonymous_83 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_84;
  string summary = "bfloat16 type";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_84 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_36];
}
def anonymous_85 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_84];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_86 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_85];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_87 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_86];
}
def anonymous_88 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_89;
  string summary = "16-bit float";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_89 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_31];
}
def anonymous_9 {	// Pred CPred
  string predExpr = "($_self.isInteger(64))";
}
def anonymous_90 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_89];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_91 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_90];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_92 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_91];
}
def anonymous_93 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_94;
  string summary = "32-bit float";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_94 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_32];
}
def anonymous_95 {	// Pred CombinedPred SubstLeaves
  PredCombinerKind kind = PredCombinerSubstLeaves;
  list<Pred> children = [anonymous_94];
  string pattern = "$_self";
  string replacement = "elementType";
}
def anonymous_96 {	// Pred CombinedPred Concat
  PredCombinerKind kind = PredCombinerConcat;
  list<Pred> children = [anonymous_95];
  string prefix = "[](::mlir::Type elementType) { return ";
  string suffix = "; }($_self.cast<::mlir::ShapedType>().getElementType())";
}
def anonymous_97 {	// Pred CombinedPred And
  PredCombinerKind kind = PredCombinerAnd;
  list<Pred> children = [IsTensorTypePred, anonymous_96];
}
def anonymous_98 {	// Constraint TypeConstraint Type AnyTypeOf
  Pred predicate = anonymous_99;
  string summary = "64-bit float";
  string cppClassName = "::mlir::Type";
  string description = "";
  string builderCall = "";
}
def anonymous_99 {	// Pred CombinedPred Or
  PredCombinerKind kind = PredCombinerOr;
  list<Pred> children = [anonymous_33];
}
def ins {
}
def outs {
}
def region {
}
def successor {
}
