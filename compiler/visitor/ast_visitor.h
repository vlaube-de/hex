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

/* Generic visitor of AST tree. */

#ifndef _AST_VISITOR_H_
#define _AST_VISITOR_H_

#include "../ast.h"

class AstVisitor {
public:
  virtual HexAstIdentifier visit(HexAstIdentifier);
  virtual HexAstLiteral visit(HexAstLiteral);
  virtual HexAstCall visit(HexAstCall);
  virtual HexAstAttributeDef visit(HexAstAttributeDef);
  virtual HexAstSliceItem visit(HexAstSliceItem);
  virtual HexAstSlicing visit(HexAstSlicing);
  virtual HexAstTargetList visit(HexAstTargetList);
  virtual HexAstName visit(HexAstName);
  virtual HexAstNegateExpr visit(HexAstNegateExpr);
  virtual HexAstNotExpr visit(HexAstNotExpr);
  virtual HexAstBitwiseNotExpr visit(HexAstBitwiseNotExpr);
  virtual HexAstIncrementExpr visit(HexAstIncrementExpr);
  virtual HexAstDecrementExpr visit(HexAstDecrementExpr);
  virtual HexAstExistentialExpr visit(HexAstExistentialExpr);
  virtual HexAstBinaryExpr visit(HexAstBinaryExpr);
  virtual HexAstConditionalExpr visit(HexAstConditionalExpr);
  virtual HexAstYieldExpr visit(HexAstYieldExpr);
  virtual HexAstStringExpr visit(HexAstStringExpr);
  virtual HexAstParenForm visit(HexAstParenForm);
  virtual HexAstExpList visit(HexAstExprList);
  virtual HexAstSimpleParamList visit(HexAstSimpleParamList);
  virtual HexAstKeywordVal visit(HexAstKeywordVal);
  virtual HexAstKeywordValList visit(HexAstKeywordValList);
  virtual HexAstParameterList visit(HexAstParameterList);
  virtual HexAstValList visit(HexAstValList);
  virtual HexAstValAtom visit(HexAstValAtom);
  virtual HexAstArgList visit(HexAstArgList);
  virtual HexAstComprehension visit(HexAstComprehension);
  virtual HexAstListForm visit(HexAstListForm);
  virtual HexAstFieldDef visit(HexAstFieldDef);
  virtual HexAstMapField visit(HexAstMapField);
  virtual HexAstMapFieldList visit(HexAstMapFieldList);
  virtual HexAstMapForm visit(HexAstMapForm);
  virtual HexAstFieldDefList visit(HexAstFieldDefList);
  virtual HexAstDictForm visit(HexAstDictForm);
  virtual HexAstDecorator visit(HexAstDecorator);
  virtual HexAstDecoratorList visit(HexAstDecoratorList);
  virtual HexAstOperator visit(HexAstOperator);
  virtual HexAstOperatorDef visit(HexAstOperatorDef);
  virtual HexAstAttributeDef visit(HexAstAttributeDef);
  virtual HexAstAttributeDefList visit(HexAstAttributeDefList);
  virtual HexAstAssignmentStmt visit(HexAstAssignmentStmt);
  virtual HexAstUsingSrc visit(HexAstUsingSrc);
  virtual HexAstUsingStmtDirect visit(HexAstUsingStmtDirect);
  virtual HexAstUsingStmtRelative visit(HexAstUsingStmtRelative);
  virtual HexAstElifStmt visit(HexAstElifStmt);
  virtual HexAstElifGroup visit(HexAstElifGroup);
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
  virtual HexAstConditionalPreposition visit(HexAstConditionalPrepositon);
  virtual HexAstConditionalClause visit(HexAstConditionalClause);
  virtual HexAstStartClauseSingle visit(HexAstStartClauseSingle);
  virtual HexAstStartClauseMultiple visit(HexAstStartClauseMultiple);
  virtual HexAstPauseClause visit(HexAstPauseClause);
  virtual HexAstResumeClause visit(HexAstResumeClause);
  virtual HexAstCancelClause visit(HexAstCancelClause);
  virtual HexAstDelayClause visit(HexAstDelayClause);
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
};

#endif /* _AST_VISITOR_H_ */
