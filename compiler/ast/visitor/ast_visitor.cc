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

#include "ast_visitor.h"
#include "../ast.h"
#include "../../../base/assert.h"


HexAstIdentifier
AstVisitor::visit(HexAstIdentifier identifier)
{
  HEX_ASSERT(identifier);
  return identifier;
}

HexAstIntegerLiteral
AstVisitor::visit(HexAstIntegerLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstFloatLiteral
AstVisitor::visit(HexAstFloatLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstStringLiteral
AstVisitor::visit(HexAstStringLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstCall
AstVisitor::visit(HexAstCall call)
{
  HEX_ASSERT(call);
  return call;
}

HexAstAttributeRef
AstVisitor::visit(HexAstAttributeRef ref)
{
  HEX_ASSERT(ref);
  return ref;
}

HexAstSlicing
AstVisitor::visit(HexAstSlicing slicing)
{
  HEX_ASSERT(slicing);
  return slicing;
}

HexAstTargetList
AstVisitor::visit(HexAstTargetList targets)
{
  HEX_ASSERT(targets);
  return targets;
}

HexAstName
AstVisitor::visit(HexAstName name)
{
  HEX_ASSERT(name);
  return name;
}

HexAstPositiveExpr
AstVisitor::visit(HexAstPositiveExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstNegativeExpr
AstVisitor::visit(HexAstNegativeExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstNotExpr
AstVisitor::visit(HexAstNotExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseNotExpr
AstVisitor::visit(HexAstBitwiseNotExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstIncrementExpr
AstVisitor::visit(HexAstIncrementExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstDecrementExpr
AstVisitor::visit(HexAstDecrementExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstExistentialExpr
AstVisitor::visit(HexAstExistentialExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstAddExpr
AstVisitor::visit(HexAstAddExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstMinusExpr
AstVisitor::visit(HexAstMinusExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstMultiplyExpr
AstVisitor::visit(HexAstMultiplyExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstDivideExpr
AstVisitor::visit(HexAstDivideExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstModulusExpr
AstVisitor::visit(HexAstModulusExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPowerExpr
AstVisitor::visit(HexAstPowerExpr expr)
{
  HEX_ASSERT(expr);
  return expr; 
}

HexAstBitwiseAndExpr
AstVisitor::visit(HexAstBitwiseAndExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseOrExpr
AstVisitor::visit(HexAstBitwiseOrExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseXorExpr
AstVisitor::visit(HexAstBitwiseXorExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseShiftLeftExpr
AstVisitor::visit(HexAstBitwiseShiftLeftExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseShiftRightExpr
AstVisitor::visit(HexAstBitwiseShiftRightExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstEqualsExpr
AstVisitor::visit(HexAstEqualsExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstNotEqualExpr
AstVisitor::visit(HexAstNotEqualExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstIsExpr
AstVisitor::visit(HexAstIsExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstIsNotExpr
AstVisitor::visit(HexAstIsNotExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstLessThanExpr
AstVisitor::visit(HexAstLessThanExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstGreaterThanExpr
AstVisitor::visit(HexAstGreaterThanExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstGreaterOrEqualsExpr
AstVisitor::visit(HexAstGreaterOrEqualsExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstLessOrEqualsExpr
AstVisitor::visit(HexAstLessOrEqualsExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstInExpr
AstVisitor::visit(HexAstInExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstNotInExpr
AstVisitor::visit(HexAstNotInExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstAndExpr
AstVisitor::visit(HexAstAndExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstOrExpr
AstVisitor::visit(HexAstOrExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstInclusiveRangeExpr
AstVisitor::visit(HexAstInclusiveRangeExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstExclusiveRangeExpr
AstVisitor::visit(HexAstExclusiveRangeExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstConditionalExpr
AstVisitor::visit(HexAstConditionalExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignPlusExpr
AstVisitor::visit(HexAstPseudoAssignPlusExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignMinusExpr
AstVisitor::visit(HexAstPseudoAssignMinusExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignMultiplyExpr
AstVisitor::visit(HexAstPseudoAssignMultiplyExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignDivideExpr
AstVisitor::visit(HexAstPseudoAssignDivideExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignModulusExpr
AstVisitor::visit(HexAstPseudoAssignModulusExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignBitwiseAndExpr
AstVisitor::visit(HexAstPseudoAssignBitwiseAndExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignBitwiseOrExpr
AstVisitor::visit(HexAstPseudoAssignBitwiseOrExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignBitwiseXorExpr
AstVisitor::visit(HexAstPseudoAssignBitwiseXorExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignBitwiseLeftShiftExpr
AstVisitor::visit(HexAstPseudoAssignBitwiseLeftShiftExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstPseudoAssignBitwiseRightShiftExpr
AstVisitor::visit(HexAstPseudoAssignBitwiseRightShiftExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstYieldExpr
AstVisitor::visit(HexAstYieldExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstStringExpr
AstVisitor::visit(HexAstStringExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstParenForm
AstVisitor::visit(HexAstParenForm form)
{
  HEX_ASSERT(form);
  return form; 
}

HexAstExprList
AstVisitor::visit(HexAstExprList exprlist)
{
  HEX_ASSERT(exprlist);
  return exprlist;
}

HexAstSimpleParam
AstVisitor::visit(HexAstSimpleParam param)
{
  HEX_ASSERT(param);
  return param;
}

HexAstSimpleParamList
AstVisitor::visit(HexAstSimpleParamList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstKeywordVal
AstVisitor::visit(HexAstKeywordVal keyval)
{
  HEX_ASSERT(keyval);
  return keyval;
}

HexAstKeywordValList
AstVisitor::visit(HexAstKeywordValList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstParameterList
AstVisitor::visit(HexAstParameterList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstValAtom
AstVisitor::visit(HexAstValAtom atom)
{
  HEX_ASSERT(atom);
  return atom;
}

HexAstValList
AstVisitor::visit(HexAstValList vallist)
{
  HEX_ASSERT(vallist);
  return vallist;
}

HexAstArgList
AstVisitor::visit(HexAstArgList arglist)
{
  HEX_ASSERT(arglist);
  return arglist;
}

HexAstComprehension
AstVisitor::visit(HexAstComprehension comprehension)
{
  HEX_ASSERT(comprehension);
  return comprehension;
}

HexAstExplicitListForm
AstVisitor::visit(HexAstExplicitListForm form)
{
  HEX_ASSERT(form);
  return form;
}

HexAstImplicitListForm
AstVisitor::visit(HexAstImplicitListForm form)
{
  HEX_ASSERT(form);
  return form;
}

HexAstFieldDef
AstVisitor::visit(HexAstFieldDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstMapField
AstVisitor::visit(HexAstMapField field)
{
  HEX_ASSERT(field);
  return field;
}

HexAstMapFieldList
AstVisitor::visit(HexAstMapFieldList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstMapForm
AstVisitor::visit(HexAstMapForm map)
{
  HEX_ASSERT(map);
  return map;
}

HexAstFieldDefList
AstVisitor::visit(HexAstFieldDefList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstExplicitDictForm
AstVisitor::visit(HexAstExplicitDictForm dict)
{
  HEX_ASSERT(dict);
  return dict;
}

HexAstImplicitDictForm
AstVisitor::visit(HexAstImplicitDictForm dict)
{
  HEX_ASSERT(dict);
  return dict;
}

HexAstDecorator
AstVisitor::visit(HexAstDecorator decorator)
{
  HEX_ASSERT(decorator);
  return decorator;
}

HexAstDecoratorList
AstVisitor::visit(HexAstDecoratorList decorators)
{
  HEX_ASSERT(decorators);
  return decorators;
}

HexAstOperator
AstVisitor::visit(HexAstOperator op)
{
  HEX_ASSERT(op); 
  return op;
}

HexAstOperatorDef
AstVisitor::visit(HexAstOperatorDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstAttributeDefList
AstVisitor::visit(HexAstAttributeDefList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstExprListAssignmentStmt
AstVisitor::visit(HexAstExprListAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstLambdaAssignmentStmt
AstVisitor::visit(HexAstLambdaAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstTaskDefAssignmentStmt
AstVisitor::visit(HexAstTaskDefAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstUsingSrc
AstVisitor::visit(HexAstUsingSrc src)
{
  HEX_ASSERT(src);
  return src;
}

HexAstUsingStmtDirect
AstVisitor::visit(HexAstUsingStmtDirect stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstUsingStmtRelative
AstVisitor::visit(HexAstUsingStmtRelative stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstElifStmt
AstVisitor::visit(HexAstElifStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstElifStmtGroup
AstVisitor::visit(HexAstElifStmtGroup group)
{
  HEX_ASSERT(group);
  return group;
}

HexAstElseStmt
AstVisitor::visit(HexAstElseStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstIfStmt
AstVisitor::visit(HexAstIfStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstForStmt
AstVisitor::visit(HexAstForStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstWithStmt
AstVisitor::visit(HexAstWithStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstLockStmt
AstVisitor::visit(HexAstLockStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstWhileStmt
AstVisitor::visit(HexAstWhileStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstCatchStmt
AstVisitor::visit(HexAstCatchStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstCatchStmtGroup
AstVisitor::visit(HexAstCatchStmtGroup stmts)
{
  HEX_ASSERT(stmts);
  return stmts;
}

HexAstTryStmt
AstVisitor::visit(HexAstTryStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstClassDef
AstVisitor::visit(HexAstClassDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstLambdaSimple
AstVisitor::visit(HexAstLambdaSimple lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstLambdaComplex
AstVisitor::visit(HexAstLambdaComplex lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstInputStmt
AstVisitor::visit(HexAstInputStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstOutputStmt
AstVisitor::visit(HexAstOutputStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstTaskState
AstVisitor::visit(HexAstTaskState state)
{
  HEX_ASSERT(state);
  return state;
}

HexAstConditionalPreposition
AstVisitor::visit(HexAstConditionalPreposition preposition)
{
  HEX_ASSERT(preposition); 
  return preposition;
}

HexAstConditionalClause
AstVisitor::visit(HexAstConditionalClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStartClauseSingle
AstVisitor::visit(HexAstStartClauseSingle clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStartClauseMultiple
AstVisitor::visit(HexAstStartClauseMultiple clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstPauseClause
AstVisitor::visit(HexAstPauseClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstResumeClause
AstVisitor::visit(HexAstResumeClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstCancelClause
AstVisitor::visit(HexAstCancelClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstConditionalDelayClause
AstVisitor::visit(HexAstConditionalDelayClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstFixedDelayClause
AstVisitor::visit(HexAstFixedDelayClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStopClause
AstVisitor::visit(HexAstStopClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstTaskDef
AstVisitor::visit(HexAstTaskDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstAwaitStmt
AstVisitor::visit(HexAstAwaitStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstReturnStmt
AstVisitor::visit(HexAstReturnStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstBreakStmt
AstVisitor::visit(HexAstBreakStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstContinueStmt
AstVisitor::visit(HexAstContinueStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstRaiseStmt
AstVisitor::visit(HexAstRaiseStmt stmt)
{
  HEX_ASSERT(stmt); 
  return stmt;
}

HexAstExprListStmt
AstVisitor::visit(HexAstExprListStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstStmtGroup
AstVisitor::visit(HexAstStmtGroup group)
{
  HEX_ASSERT(group);
  return group;
}

HexAstHexProgram
AstVisitor::visit(HexAstHexProgram program)
{
  HEX_ASSERT(program);
  return program;
}
