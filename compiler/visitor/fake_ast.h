/*
 * HEX Programming Language
 * Copyright (C) 2013  Yanzheng Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * Forward declaration of AST types.
 * 
 * This is needed to solve the circular dependency between
 * definitions in compiler/ast/ and compiler/ast/visitors/
 *
 * Please update this file every time there are type
 * changes occur under compiler/ast/
 */

typedef class _HexAstIdentifier * HexAstIdentifier;
typedef class _HexAstDecimalIntegerLiteral * HexAstDecimalIntegerLiteral;
typedef class _HexAstBinaryIntegerLiteral * HexAstBinaryIntegerLiteral;
typedef class _HexAstOctalIntegerLiteral * HexAstOctalIntegerLiteral;
typedef class _HexAstHexadecimalIntegerLiteral * HexAstHexadecimalIntegerLiteral;
typedef class _HexAstFloatLiteral * HexAstFloatLiteral;
typedef class _HexAstSingleQuoteStringLiteral * HexAstSingleQuoteStringLiteral;
typedef class _HexAstDoubleQuoteStringLiteral * HexAstDoubleQuoteStringLiteral;
typedef class _HexAstCall * HexAstCall;
typedef class _HexAstAttributeRef * HexAstAttributeRef;
typedef class _HexAstSliceItem * HexAstSliceItem;
typedef class _HexAstSlicing * HexAstSlicing;
typedef class _HexAstTargetList * HexAstTargetList;
typedef class _HexAstName * HexAstName;
typedef class _HexAstNameList * HexAstNameList;
typedef class _HexAstPositiveExpr * HexAstPositiveExpr;
typedef class _HexAstNegativeExpr * HexAstNegativeExpr;
typedef class _HexAstNotExpr * HexAstNotExpr;
typedef class _HexAstBitwiseNotExpr * HexAstBitwiseNotExpr;
typedef class _HexAstIncrementExpr * HexAstIncrementExpr;
typedef class _HexAstDecrementExpr * HexAstDecrementExpr;
typedef class _HexAstExistentialExpr * HexAstExistentialExpr;
typedef class _HexAstAdditionExpr * HexAstAdditionExpr;
typedef class _HexAstSubtractionExpr * HexAstSubtractionExpr;
typedef class _HexAstMultiplicationExpr * HexAstMultiplicationExpr;
typedef class _HexAstDivisionExpr * HexAstDivisionExpr;
typedef class _HexAstModulusExpr * HexAstModulusExpr;
typedef class _HexAstPowerExpr * HexAstPowerExpr;
typedef class _HexAstBitwiseANDExpr * HexAstBitwiseANDExpr;
typedef class _HexAstBitwiseORExpr * HexAstBitwiseORExpr;
typedef class _HexAstBitwiseXORExpr * HexAstBitwiseXORExpr;
typedef class _HexAstBitwiseLeftShiftExpr * HexAstBitwiseLeftShiftExpr;
typedef class _HexAstBitwiseRightShiftExpr * HexAstBitwiseRightShiftExpr;
typedef class _HexAstEqualsExpr * HexAstEqualsExpr;
typedef class _HexAstNotEqualExpr * HexAstNotEqualExpr;
typedef class _HexAstIsExpr * HexAstIsExpr;
typedef class _HexAstIsNotExpr * HexAstIsNotExpr;
typedef class _HexAstLessThanExpr * HexAstLessThanExpr;
typedef class _HexAstGreaterThanExpr * HexAstGreaterThanExpr;
typedef class _HexAstGreaterOrEqualsExpr * HexAstGreaterOrEqualsExpr;
typedef class _HexAstLessOrEqualsExpr * HexAstLessOrEqualsExpr;
typedef class _HexAstInExpr * HexAstInExpr;
typedef class _HexAstNotInExpr * HexAstNotInExpr;
typedef class _HexAstLogicalANDExpr * HexAstLogicalANDExpr;
typedef class _HexAstLogicalORExpr * HexAstLogicalORExpr;
typedef class _HexAstInclusiveRangeExpr * HexAstInclusiveRangeExpr;
typedef class _HexAstExclusiveRangeExpr * HexAstExclusiveRangeExpr;
typedef class _HexAstConditionalExpr * HexAstConditionalExpr;
typedef class _HexAstAdditionAssignmentExpr * HexAstAdditionAssignmentExpr;
typedef class _HexAstSubtractionAssignmentExpr * HexAstSubtractionAssignmentExpr;
typedef class _HexAstMultiplicationAssignmentExpr * HexAstMultiplicationAssignmentExpr;
typedef class _HexAstDivisionAssignmentExpr * HexAstDivisionAssignmentExpr;
typedef class _HexAstModulusAssignmentExpr * HexAstModulusAssignmentExpr;
typedef class _HexAstBitwiseANDAssignmentExpr * HexAstBitwiseANDAssignmentExpr;
typedef class _HexAstBitwiseORAssignmentExpr * HexAstBitwiseORAssignmentExpr;
typedef class _HexAstBitwiseXORAssignmentExpr * HexAstBitwiseXORAssignmentExpr;
typedef class _HexAstBitwiseLeftShiftAssignmentExpr * HexAstBitwiseLeftShiftAssignmentExpr;
typedef class _HexAstBitwiseRightShiftAssignmentExpr * HexAstBitwiseRightShiftAssignmentExpr;
typedef class _HexAstYieldExpr * HexAstYieldExpr;
typedef class _HexAstStringCompositionExpr * HexAstStringCompositionExpr;
typedef class _HexAstNestedComprehension * HexAstNestedComprehension;
typedef class _HexAstExprComprehension * HexAstExprComprehension;
typedef class _HexAstGeneratorExpr * HexAstGeneratorExpr; 
typedef class _HexAstParenForm * HexAstParenForm;
typedef class _HexAstExplicitListForm * HexAstExplicitListForm;
typedef class _HexAstImplicitListForm * HexAstImplicitListForm;
typedef class _HexAstExplicitDictForm * HexAstExplicitDictForm;
typedef class _HexAstImplicitDictForm * HexAstImplicitDictForm;
typedef class _HexAstDictForm * HexAstDictForm;
typedef class _HexAstObjectForm * HexAstObjectForm;
typedef class _HexAstExprList * HexAstExprList;
typedef class _HexAstSimpleParam * HexAstSimpleParam;
typedef class _HexAstSimpleParamList * HexAstSimpleParamList;
typedef class _HexAstKeywordParam * HexAstKeywordParam;
typedef class _HexAstKeywordParamList * HexAstKeywordParamList;
typedef class _HexAstParameterList * HexAstParameterList;
typedef class _HexAstSimpleArg * HexAstSimpleArg;
typedef class _HexAstSimpleArgList * HexAstSimpleArgList;
typedef class _HexAstKeywordArg * HexAstKeywordArg;
typedef class _HexAstKeywordArgList * HexAstKeywordArgList;
typedef class _HexAstArgList * HexAstArgList;
typedef class _HexAstFieldDef * HexAstFieldDef;
typedef class _HexAstFieldDefList * HexAstFieldDefList;
typedef class _HexAstKeyValuePair * HexAstKeyValuePair;
typedef class _HexAstKeyValuePairList * HexAstKeyValuePairList;
typedef class _HexAstAttributeValuePair * HexAstAttributeValuePair;
typedef class _HexAstAttributeValuePairList * HexAstAttributeValuePairList;
typedef class _HexAstDecorator * HexAstDecorator;
typedef class _HexAstDecoratorList * HexAstDecoratorList;
typedef class _HexAstAssignmentFeature * HexAstAssignmentFeature;
typedef class _HexAstAssignmentStmt * HexAstAssignmentStmt;
typedef class _HexAstUsingSrc * HexAstUsingSrc;
typedef class _HexAstRelativeUsingStmt * HexAstRelativeUsingStmt;
typedef class _HexAstAbsoluteUsingStmt * HexAstAbsoluteUsingStmt;
typedef class _HexAstElifStmt * HexAstElifStmt;
typedef class _HexAstElifStmtGroup * HexAstElifStmtGroup;
typedef class _HexAstIfStmt * HexAstIfStmt;
typedef class _HexAstForStmt * HexAstForStmt;
typedef class _HexAstWithStmt * HexAstWithStmt;
typedef class _HexAstLockStmt * HexAstLockStmt;
typedef class _HexAstWhileStmt * HexAstWhileStmt;
typedef class _HexAstCatchStmt * HexAstCatchStmt;
typedef class _HexAstCatchStmtGroup * HexAstCatchStmtGroup;
typedef class _HexAstTryStmt * HexAstTryStmt;
typedef class _HexAstClassDef * HexAstClassDef;
typedef class _HexAstSimpleLambda * HexAstSimpleLambda;
typedef class _HexAstComplexLambda * HexAstComplexLambda;
typedef class _HexAstInputStmt * HexAstInputStmt;
typedef class _HexAstOutputStmt * HexAstOutputStmt;
typedef class _HexAstTaskState * HexAstTaskState;
typedef class _HexAstConditionalPreposition * HexAstConditionalPreposition;
typedef class _HexAstConditionalClause * HexAstConditionalClause;
typedef class _HexAstStartClause * HexAstStartClause;
typedef class _HexAstPauseClause * HexAstPauseClause;
typedef class _HexAstResumeClause * HexAstResumeClause;
typedef class _HexAstCancelClause * HexAstCancelClause;
typedef class _HexAstStopClause * HexAstStopClause;
typedef class _HexAstTaskDef * HexAstTaskDef;
typedef class _HexAstAwaitStmt * HexAstAwaitStmt;
typedef class _HexAstReturnStmt * HexAstReturnStmt;
typedef class _HexAstBreakStmt * HexAstBreakStmt;
typedef class _HexAstContinueStmt * HexAstContinueStmt;
typedef class _HexAstRaiseStmt * HexAstRaiseStmt;
typedef class _HexAstExprListStmt * HexAstExprListStmt;
typedef class _HexAstSimpleIfStmt * HexAstSimpleIfStmt; 
typedef class _HexAstStmtGroup * HexAstStmtGroup;
typedef class _HexAstHexProgram * HexAstHexProgram;