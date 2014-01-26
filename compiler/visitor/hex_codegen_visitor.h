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

/* Visitor that traverses the AST and generates code. */

#include <boost/smart_ptr.hpp>
#include "ast_visitor.h"
#include "../../base/c_str.h"

#ifndef _HEX_CODEGEN_VISITOR_H_
#define _HEX_CODEGEN_VISITOR_H_

class HexCodeGenerationVisitor : public AstVisitor {
public:
  HexCodeGenerationVisitor();

  // virtual HexAstIdentifier visit(HexAstIdentifier);
  // virtual HexAstDecimalIntegerLiteral visit(HexAstDecimalIntegerLiteral);
  // virtual HexAstBinaryIntegerLiteral visit(HexAstBinaryIntegerLiteral);
  // virtual HexAstOctalIntegerLiteral visit(HexAstOctalIntegerLiteral);
  // virtual HexAstHexadecimalIntegerLiteral visit(HexAstHexadecimalIntegerLiteral);
  // virtual HexAstFloatLiteral visit(HexAstFloatLiteral);
  // virtual HexAstSingleQuoteStringLiteral visit(HexAstSingleQuoteStringLiteral);
  // virtual HexAstDoubleQuoteStringLiteral visit(HexAstDoubleQuoteStringLiteral);
  // virtual HexAstCall visit(HexAstCall);
  // virtual HexAstAttributeRef visit(HexAstAttributeRef);
  // virtual HexAstSlicing visit(HexAstSlicing);
  // virtual HexAstTargetList visit(HexAstTargetList);
  // virtual HexAstName visit(HexAstName);
  // virtual HexAstNameList visit(HexAstNameList);
  // virtual HexAstPositiveExpr visit(HexAstPositiveExpr);
  // virtual HexAstNegativeExpr visit(HexAstNegativeExpr);
  // virtual HexAstNotExpr visit(HexAstNotExpr);
  // virtual HexAstBitwiseNotExpr visit(HexAstBitwiseNotExpr);
  // virtual HexAstIncrementExpr visit(HexAstIncrementExpr);
  // virtual HexAstDecrementExpr visit(HexAstDecrementExpr);
  // virtual HexAstExistentialExpr visit(HexAstExistentialExpr);
  // virtual HexAstAdditionExpr visit(HexAstAdditionExpr);
  // virtual HexAstSubtractionExpr visit(HexAstSubtractionExpr);
  // virtual HexAstMultiplicationExpr visit(HexAstMultiplicationExpr);
  // virtual HexAstDivisionExpr visit(HexAstDivisionExpr);
  // virtual HexAstModulusExpr visit(HexAstModulusExpr);
  // virtual HexAstPowerExpr visit(HexAstPowerExpr);
  // virtual HexAstBitwiseANDExpr visit(HexAstBitwiseANDExpr);
  // virtual HexAstBitwiseORExpr visit(HexAstBitwiseORExpr);
  // virtual HexAstBitwiseXORExpr visit(HexAstBitwiseXORExpr);
  // virtual HexAstBitwiseLeftShiftExpr visit(HexAstBitwiseLeftShiftExpr);
  // virtual HexAstBitwiseRightShiftExpr visit(HexAstBitwiseRightShiftExpr);
  // virtual HexAstEqualsExpr visit(HexAstEqualsExpr);
  // virtual HexAstNotEqualExpr visit(HexAstNotEqualExpr);
  // virtual HexAstIsExpr visit(HexAstIsExpr);
  // virtual HexAstIsNotExpr visit(HexAstIsNotExpr);
  // virtual HexAstLessThanExpr visit(HexAstLessThanExpr);
  // virtual HexAstGreaterThanExpr visit(HexAstGreaterThanExpr);
  // virtual HexAstGreaterOrEqualsExpr visit(HexAstGreaterOrEqualsExpr);
  // virtual HexAstLessOrEqualsExpr visit(HexAstLessOrEqualsExpr);
  // virtual HexAstInExpr visit(HexAstInExpr);
  // virtual HexAstNotInExpr visit(HexAstNotInExpr);
  // virtual HexAstLogicalANDExpr visit(HexAstLogicalANDExpr);
  // virtual HexAstLogicalORExpr visit(HexAstLogicalORExpr);
  // virtual HexAstInclusiveRangeExpr visit(HexAstInclusiveRangeExpr);
  // virtual HexAstExclusiveRangeExpr visit(HexAstExclusiveRangeExpr);
  // virtual HexAstConditionalExpr visit(HexAstConditionalExpr);
  // virtual HexAstAdditionAssignmentExpr visit(HexAstAdditionAssignmentExpr);
  // virtual HexAstSubtractionAssignmentExpr visit(HexAstSubtractionAssignmentExpr);
  // virtual HexAstMultiplicationAssignmentExpr visit(HexAstMultiplicationAssignmentExpr);
  // virtual HexAstDivisionAssignmentExpr visit(HexAstDivisionAssignmentExpr);
  // virtual HexAstModulusAssignmentExpr visit(HexAstModulusAssignmentExpr);
  // virtual HexAstBitwiseANDAssignmentExpr visit(HexAstBitwiseANDAssignmentExpr);
  // virtual HexAstBitwiseORAssignmentExpr visit(HexAstBitwiseORAssignmentExpr);
  // virtual HexAstBitwiseXORAssignmentExpr visit(HexAstBitwiseXORAssignmentExpr);
  // virtual HexAstBitwiseLeftShiftAssignmentExpr visit(HexAstBitwiseLeftShiftAssignmentExpr);
  // virtual HexAstBitwiseRightShiftAssignmentExpr visit(HexAstBitwiseRightShiftAssignmentExpr);
  // virtual HexAstYieldExpr visit(HexAstYieldExpr);
  // virtual HexAstStringCompositionExpr visit(HexAstStringCompositionExpr);
  // virtual HexAstNestedComprehension visit(HexAstNestedComprehension);
  // virtual HexAstExprComprehension visit(HexAstExprComprehension);
  // virtual HexAstGeneratorExpr visit(HexAstGeneratorExpr);
  // virtual HexAstParenForm visit(HexAstParenForm);
  // virtual HexAstExplicitListForm visit(HexAstExplicitListForm);
  // virtual HexAstImplicitListForm visit(HexAstImplicitListForm);
  // virtual HexAstExplicitDictForm visit(HexAstExplicitDictForm);
  // virtual HexAstImplicitDictForm visit(HexAstImplicitDictForm);
  // virtual HexAstObjectForm visit(HexAstObjectForm);
  // virtual HexAstExprList visit(HexAstExprList);
  // virtual HexAstSimpleParam visit(HexAstSimpleParam);
  // virtual HexAstSimpleParamList visit(HexAstSimpleParamList);
  // virtual HexAstKeywordParam visit(HexAstKeywordParam);
  // virtual HexAstKeywordParamList visit(HexAstKeywordParamList);
  // virtual HexAstParameterList visit(HexAstParameterList);
  // virtual HexAstSimpleArgList visit(HexAstSimpleArgList);
  // virtual HexAstKeywordArg visit(HexAstKeywordArg);
  // virtual HexAstKeywordArgList visit(HexAstKeywordArgList);
  // virtual HexAstArgList visit(HexAstArgList);
  // virtual HexAstFieldDef visit(HexAstFieldDef);
  // virtual HexAstFieldDefList visit(HexAstFieldDefList);
  // virtual HexAstKeyValuePair visit(HexAstKeyValuePair);
  // virtual HexAstKeyValuePairList visit(HexAstKeyValuePairList);
  // virtual HexAstAttributeValuePair visit(HexAstAttributeValuePair);
  // virtual HexAstAttributeValuePairList visit(HexAstAttributeValuePairList);
  // virtual HexAstDecorator visit(HexAstDecorator);
  // virtual HexAstDecoratorList visit(HexAstDecoratorList);
  // virtual HexAstAssignmentFeature visit(HexAstAssignmentFeature);
  // virtual HexAstAssignmentStmt visit(HexAstAssignmentStmt);
  // virtual HexAstUsingSrc visit(HexAstUsingSrc);
  // virtual HexAstRelativeUsingStmt visit(HexAstRelativeUsingStmt);
  // virtual HexAstAbsoluteUsingStmt visit(HexAstAbsoluteUsingStmt);
  // virtual HexAstElifStmt visit(HexAstElifStmt);
  // virtual HexAstElifStmtGroup visit(HexAstElifStmtGroup);
  // virtual HexAstIfStmt visit(HexAstIfStmt);
  // virtual HexAstForStmt visit(HexAstForStmt);
  // virtual HexAstWithStmt visit(HexAstWithStmt);
  // virtual HexAstLockStmt visit(HexAstLockStmt);
  // virtual HexAstWhileStmt visit(HexAstWhileStmt);
  // virtual HexAstCatchStmt visit(HexAstCatchStmt);
  // virtual HexAstCatchStmtGroup visit(HexAstCatchStmtGroup);
  // virtual HexAstTryStmt visit(HexAstTryStmt);
  // virtual HexAstClassDef visit(HexAstClassDef);
  // virtual HexAstSimpleLambda visit(HexAstSimpleLambda);
  // virtual HexAstComplexLambda visit(HexAstComplexLambda);
  // virtual HexAstInputStmt visit(HexAstInputStmt);
  // virtual HexAstOutputStmt visit(HexAstOutputStmt);
  // virtual HexAstTaskState visit(HexAstTaskState);
  // virtual HexAstConditionalPreposition visit(HexAstConditionalPreposition);
  // virtual HexAstConditionalClause visit(HexAstConditionalClause);
  // virtual HexAstStartClause visit(HexAstStartClause);
  // virtual HexAstPauseClause visit(HexAstPauseClause);
  // virtual HexAstResumeClause visit(HexAstResumeClause);
  // virtual HexAstCancelClause visit(HexAstCancelClause);
  // virtual HexAstStopClause visit(HexAstStopClause);
  // virtual HexAstTaskDef visit(HexAstTaskDef);
  // virtual HexAstAwaitStmt visit(HexAstAwaitStmt);
  // virtual HexAstReturnStmt visit(HexAstReturnStmt);
  // virtual HexAstBreakStmt visit(HexAstBreakStmt);
  // virtual HexAstContinueStmt visit(HexAstContinueStmt);
  // virtual HexAstRaiseStmt visit(HexAstRaiseStmt);
  // virtual HexAstExprListStmt visit(HexAstExprListStmt);
  // virtual HexAstSimpleIfStmt visit(HexAstSimpleIfStmt);
  // virtual HexAstStmtGroup visit(HexAstStmtGroup);
  virtual HexAstHexProgram visit(HexAstHexProgram);
};

#endif /* _HEX_CODEGEN_VISITOR_H_ */