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

#include <list>
#include "ast_visitor.h"
#include "../../base/c_str.h"

#ifndef _AST_TO_XML_VISITOR_H_
#define _AST_TO_XML_VISITOR_H_

class AstToXmlVisitor : public AstVisitor {
public:
  AstToXmlVisitor();
  ~AstToXmlVisitor();

  const c_str str();

  virtual HexAstIdentifier visit(HexAstIdentifier);
  virtual HexAstIntegerLiteral visit(HexAstIntegerLiteral);
  virtual HexAstFloatLiteral visit(HexAstFloatLiteral);
  virtual HexAstStringLiteral visit(HexAstStringLiteral);
  virtual HexAstCall visit(HexAstCall);
  virtual HexAstAttributeRef visit(HexAstAttributeRef);
  virtual HexAstSlicing visit(HexAstSlicing);
  virtual HexAstTargetList visit(HexAstTargetList);
  virtual HexAstName visit(HexAstName);
  virtual HexAstPositiveExpr visit(HexAstPositiveExpr);
  virtual HexAstNegativeExpr visit(HexAstNegativeExpr);
  virtual HexAstNotExpr visit(HexAstNotExpr);
  virtual HexAstBitwiseNotExpr visit(HexAstBitwiseNotExpr);
  virtual HexAstIncrementExpr visit(HexAstIncrementExpr);
  virtual HexAstDecrementExpr visit(HexAstDecrementExpr);
  virtual HexAstExistentialExpr visit(HexAstExistentialExpr);
  virtual HexAstAddExpr visit(HexAstAddExpr);
  virtual HexAstMinusExpr visit(HexAstMinusExpr);
  virtual HexAstMultiplyExpr visit(HexAstMultiplyExpr);
  virtual HexAstDivideExpr visit(HexAstDivideExpr);
  virtual HexAstModulusExpr visit(HexAstModulusExpr);
  virtual HexAstPowerExpr visit(HexAstPowerExpr);
  virtual HexAstBitwiseAndExpr visit(HexAstBitwiseAndExpr);
  virtual HexAstBitwiseOrExpr visit(HexAstBitwiseOrExpr);
  virtual HexAstBitwiseXorExpr visit(HexAstBitwiseXorExpr);
  virtual HexAstBitwiseShiftLeftExpr visit(HexAstBitwiseShiftLeftExpr);
  virtual HexAstBitwiseShiftRightExpr visit(HexAstBitwiseShiftRightExpr);
  virtual HexAstEqualsExpr visit(HexAstEqualsExpr);
  virtual HexAstNotEqualExpr visit(HexAstNotEqualExpr);
  virtual HexAstIsExpr visit(HexAstIsExpr);
  virtual HexAstIsNotExpr visit(HexAstIsNotExpr);
  virtual HexAstLessThanExpr visit(HexAstLessThanExpr);
  virtual HexAstGreaterThanExpr visit(HexAstGreaterThanExpr);
  virtual HexAstGreaterOrEqualsExpr visit(HexAstGreaterOrEqualsExpr);
  virtual HexAstLessOrEqualsExpr visit(HexAstLessOrEqualsExpr);
  virtual HexAstInExpr visit(HexAstInExpr);
  virtual HexAstNotInExpr visit(HexAstNotInExpr);
  virtual HexAstAndExpr visit(HexAstAndExpr);
  virtual HexAstOrExpr visit(HexAstOrExpr);
  virtual HexAstInclusiveRangeExpr visit(HexAstInclusiveRangeExpr);
  virtual HexAstExclusiveRangeExpr visit(HexAstExclusiveRangeExpr);
  virtual HexAstConditionalExpr visit(HexAstConditionalExpr);
  virtual HexAstPseudoAssignPlusExpr visit(HexAstPseudoAssignPlusExpr);
  virtual HexAstPseudoAssignMinusExpr visit(HexAstPseudoAssignMinusExpr);
  virtual HexAstPseudoAssignMultiplyExpr visit(HexAstPseudoAssignMultiplyExpr);
  virtual HexAstPseudoAssignDivideExpr visit(HexAstPseudoAssignDivideExpr);
  virtual HexAstPseudoAssignModulusExpr visit(HexAstPseudoAssignModulusExpr);
  virtual HexAstPseudoAssignBitwiseAndExpr visit(HexAstPseudoAssignBitwiseAndExpr);
  virtual HexAstPseudoAssignBitwiseOrExpr visit(HexAstPseudoAssignBitwiseOrExpr);
  virtual HexAstPseudoAssignBitwiseXorExpr visit(HexAstPseudoAssignBitwiseXorExpr);
  virtual HexAstPseudoAssignBitwiseLeftShiftExpr visit(HexAstPseudoAssignBitwiseLeftShiftExpr);
  virtual HexAstPseudoAssignBitwiseRightShiftExpr visit(HexAstPseudoAssignBitwiseRightShiftExpr);
  virtual HexAstYieldExpr visit(HexAstYieldExpr);
  virtual HexAstStringExpr visit(HexAstStringExpr);
  virtual HexAstParenForm visit(HexAstParenForm);
  virtual HexAstExprList visit(HexAstExprList);
  virtual HexAstSimpleParam visit(HexAstSimpleParam);
  virtual HexAstSimpleParamList visit(HexAstSimpleParamList);
  virtual HexAstKeywordParam visit(HexAstKeywordParam);
  virtual HexAstKeywordParamList visit(HexAstKeywordParamList);
  virtual HexAstKeywordVal visit(HexAstKeywordVal);
  virtual HexAstKeywordValList visit(HexAstKeywordValList);
  virtual HexAstParameterList visit(HexAstParameterList);
  virtual HexAstValList visit(HexAstValList);
  virtual HexAstArgList visit(HexAstArgList);
  virtual HexAstComprehension visit(HexAstComprehension);
  virtual HexAstExplicitListForm visit(HexAstExplicitListForm);
  virtual HexAstImplicitListForm visit(HexAstImplicitListForm);
  virtual HexAstFieldDef visit(HexAstFieldDef);
  virtual HexAstFieldDefList visit(HexAstFieldDefList);
  virtual HexAstKeyValuePair visit(HexAstKeyValuePair);
  virtual HexAstKeyValuePairList visit(HexAstKeyValuePairList);
  virtual HexAstExplicitDictForm visit(HexAstExplicitDictForm);
  virtual HexAstImplicitDictForm visit(HexAstImplicitDictForm);
  virtual HexAstDecorator visit(HexAstDecorator);
  virtual HexAstDecoratorList visit(HexAstDecoratorList);
  virtual HexAstExprListAssignmentStmt visit(HexAstExprListAssignmentStmt);
  virtual HexAstLambdaAssignmentStmt visit(HexAstLambdaAssignmentStmt);
  virtual HexAstTaskDefAssignmentStmt visit(HexAstTaskDefAssignmentStmt);
  virtual HexAstUsingSrc visit(HexAstUsingSrc);
  virtual HexAstUsingStmtDirect visit(HexAstUsingStmtDirect);
  virtual HexAstUsingStmtRelative visit(HexAstUsingStmtRelative);
  virtual HexAstElifStmt visit(HexAstElifStmt);
  virtual HexAstElifStmtGroup visit(HexAstElifStmtGroup);
  virtual HexAstElseStmt visit(HexAstElseStmt);
  virtual HexAstIfStmt visit(HexAstIfStmt);
  virtual HexAstForStmt visit(HexAstForStmt);
  virtual HexAstWithStmt visit(HexAstWithStmt);
  virtual HexAstLockStmt visit(HexAstLockStmt);
  virtual HexAstWhileStmt visit(HexAstWhileStmt);
  virtual HexAstCatchStmt visit(HexAstCatchStmt);
  virtual HexAstCatchStmtGroup visit(HexAstCatchStmtGroup);
  virtual HexAstTryStmt visit(HexAstTryStmt);
  virtual HexAstClassDef visit(HexAstClassDef);
  virtual HexAstLambdaSimple visit(HexAstLambdaSimple);
  virtual HexAstLambdaComplex visit(HexAstLambdaComplex);
  virtual HexAstInputStmt visit(HexAstInputStmt);
  virtual HexAstOutputStmt visit(HexAstOutputStmt);
  virtual HexAstTaskState visit(HexAstTaskState);
  virtual HexAstConditionalPreposition visit(HexAstConditionalPreposition);
  virtual HexAstConditionalClause visit(HexAstConditionalClause);
  virtual HexAstStartClauseSingle visit(HexAstStartClauseSingle);
  virtual HexAstStartClauseMultiple visit(HexAstStartClauseMultiple);
  virtual HexAstPauseClause visit(HexAstPauseClause);
  virtual HexAstResumeClause visit(HexAstResumeClause);
  virtual HexAstCancelClause visit(HexAstCancelClause);
  virtual HexAstConditionalDelayClause visit(HexAstConditionalDelayClause);
  virtual HexAstFixedDelayClause visit(HexAstFixedDelayClause);
  virtual HexAstStopClause visit(HexAstStopClause);
  virtual HexAstTaskDef visit(HexAstTaskDef);
  virtual HexAstAwaitStmt visit(HexAstAwaitStmt);
  virtual HexAstReturnStmt visit(HexAstReturnStmt);
  virtual HexAstBreakStmt visit(HexAstBreakStmt);
  virtual HexAstContinueStmt visit(HexAstContinueStmt);
  virtual HexAstRaiseStmt visit(HexAstRaiseStmt);
  virtual HexAstExprListStmt visit(HexAstExprListStmt);
  virtual HexAstStmtGroup visit(HexAstStmtGroup);
  virtual HexAstHexProgram visit(HexAstHexProgram);

protected:
  std::string* _strbuf;

  void append(const c_str);

  void begin_tag(const c_str);
  void end_tag(const c_str);
  void double_tag(const c_str, c_str);

  template<class Function>
  void double_tag(const c_str, Function);

  template<class T, class Function>
  void iterate(std::list<T>*, Function, bool breakOnLast=true);

  template<class T>
  void double_tag_for_binary_expr(T, const c_str);
};


#endif /* _AST_TO_XML_VISITOR_H_ */
