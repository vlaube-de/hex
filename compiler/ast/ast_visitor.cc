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
#include "../../base/assert.h"


HexAstIdentifier
AstToStringVisitor::visit(HexAstIdentifier identifier)
{
  HEX_ASSERT(identifier);
  return identifier;
}

HexAstLiteral
AstToStringVisitor::visit(HexAstLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstCall
AstToStringVisitor::visit(HexAstCall call)
{
  HEX_ASSERT(call);
  return call;
}

HexAstAttributeRef
AstToStringVisitor::visit(HexAstAttributeRef ref)
{
  HEXT_ASSERT(ref);
  return ref;
}

HexAstSliceItem
AstToStringVisitor::visit(HexAstSliceItem item)
{
  HEX_ASSERT(item);
  return item;
}

HexAstSlicing
AstToStringVisitor::visit(HexAstSlicing slicing)
{
  HEX_ASSERT(slicing);
  return slicing;
}

HexAstTargetList
AstToStringVisitor::visit(HexAstTargetList targets)
{
  HEX_ASSERT(targets);
  return targets;
}

HexAstName
AstToStringVisitor::visit(HexAstName name)
{
  HEX_ASSERT(name);
  return name;
}

HexAstNegateExpr
AstToStringVisitor::visit(HexAstNegateExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstNotExpr
AstToStringVisitor::visit(HexAstNotExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseNotExpr
AstToStringVisitor::visit(HexAstBitwiseNotExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstIncrementExpr
AstToStringVisitor::visit(HexAstIncrementExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstDecrementExpr
AstToStringVisitor::visit(HexAstDecrementExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstExistentialExpr
AstToStringVisitor::visit(HexAstExistentialExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBinaryExpr
_AstToStirngVisitor::visit(HexAstBinaryExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstConditionalExpr
AstToStringVisitor::visit(HexAstConditionalExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstYieldExpr
AstToStringVisitor::visit(HexAstYieldExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstStringExpr
AstToStringVisitor::visit(HexAstStringExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstParenForm
AstToStringVisitor::visit(HexAstParenForm form)
{
  HEX_ASSERT(form);
  return form; 
}

HexAstExpList
AstToStringVisitor::visit(HexAstExprList exprlist)
{
  HEX_ASSERT(exprlist);
  return exprlist;
}

HexAstSimpleParamList
AstToStringVisitor::visit(HexAstSimpleParamList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstKeywordVal
AstToStringVisitor::visit(HexAstKeywordVal keyval)
{
  HEX_ASSERT(keyval);
  return keyval;
}

HexAstKeywordValList
AstToStringVisitor::visit(HexAstKeywordValList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstParameterList
AstToStringVisitor::visit(HexAstParameterList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstValList
AstToStringVisitor::visit(HexAstValList vallist)
{
  HEX_ASSERT(vallist);
  return vallist;
}

HexAstValAtom
AstToStringVisitor::visit(HexAstValAtom atom)
{
  HEX_ASSERT(atom);
  return atom;
}

HexAstArgList
AstToStringVisitor::visit(HexAstArgList arglist)
{
  HEX_ASSERT(arglist);
  return arglist;
}

HexAstComprehension
AstToStringVisitor::visit(HexAstComprehension comprehension)
{
  HEX_ASSERT(comprehension);
  return comprehension;
}

HexAstListForm
AstToStringVisitor::visit(HexAstListForm form)
{
  HEX_ASSERT(form);
  return form;
}

HexAstFieldDef
AstToStringVisitor::visit(HexAstFieldDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstMapField
AstToStringVisitor::visit(HexAstMapField field)
{
  HEX_ASSERT(field);
  return field;
}

HexAstMapFieldList
AstToStringVisitor::visit(HexAstMapFieldList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstMapForm
AstToStringVisitor::visit(HexAstMapForm map)
{
  HEX_ASSERT(map);
  return map;
}

HexAstFieldDefList
AstToStringVisitor::visit(HexAstFieldDefList list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstDictForm
AstToStringVisitor::visit(HexAstDictForm dict)
{
  HEX_ASSERT(dict);
  return dict;
}

HexAstDecorator
AstToStringVisitor::visit(HexAstDecorator decorator)
{
  HEX_ASSERT(decorator);
  return decorator;
}

HexAstDecoratorList
AstToStringVisitor::visit(HexAstDecoratorList decorators)
{
  HEX_ASSERT(decorators);
  return decorators;
}

HexAstOperator
AstToStringVisitor::visit(HexAstOperator op)
{
  HEX_ASSERT(op); 
  return op;
}

HexAstAssignmentStmt
AstToStringVisitor::visit(HexAstAssignmentStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstUsingSrc
AstToStringVisitor::visit(HexAstUsingSrc src)
{
  HEX_ASSERT(src);
  return src;
}

HexAstUsingStmtDirect
AstToStringVisitor::visit(HexAstUsingStmtDirect stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstUsingStmtRelative
AstToStringVisitor::visit(HexAstUsingStmtRelative stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstElifStmt
AstToStringVisitor::visit(HexAstElifStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstElifGroup
AstToStringVisitor::visit(HexAstElifGroup group)
{
  HEX_ASSERT(group);
  return group;
}

HexAstElseStmt
AstToStringVisitor::visit(HexAstElseStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstIfStmt
AstToStringVisitor::visit(HexAstIfStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstForStmt
AstToStringVisitor::visit(HexAstForStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstWithStmt
AstToStringVisitor::visit(HexAstWithStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstLockStmt
AstToStringVisitor::visit(HexAstLockStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}


HexAstWhileStmt
AstToStringVisitor::visit(HexAstWhileStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstCatchStmt
AstToStringVisitor::visit(HexAstCatchStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstLambdaSimple
AstToStringVisitor::visit(HexAstLambdaSimple lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstLambdaComplex
AstToStringVisitor::visit(HexAstLambdaComplex lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstInputStmt
AstToStringVisitor::visit(HexAstInputStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstOutputStmt
AstToStringVisitor::visit(HexAstOutputStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstTaskState
AstToStringVisitor::visit(HexAstTaskState state)
{
  HEX_ASSERT(state);
  return state;
}

HexAstConditionalPreposition
AstToStringVisitor::visit(HexAstConditionalPrepositon preposition)
{
  HEX_ASSERT(preposition); 
  return preposition;
}

HexAstConditionalClause
AstToStringVisitor::visit(HexAstConditionalClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStartClauseSingle
AstToStringVisitor::visit(HexAstStartClauseSingle clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStartClauseMultiple
AstToStringVisitor::visit(HexAstClauseMultiple clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstPauseClause
AstToStringVisitor::visit(HexAstPauseClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstResumeClause
AstToStringVisitor::visit(HexAstResumeClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstCancelClause
AstToStringVisitor::visit(HexAstCancelClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstConditionalDelayClause
AstToStringVisitor::visit(HexAstDelayClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstFixedDelayClause
AstToStringVisitor::visit(HexAstFixedDelayClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstStopClause
AstToStringVisitor::visit(HexAstStopClause clause)
{
  HEX_ASSERT(clause);
  return clause;
}

HexAstTaskDef
AstToStringVisitor::visit(HexAstTaskDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstAwaitStmt
AstToStringVisitor::visit(HexAstAwaitStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstReturnStmt
AstToStringVisitor::visit(HexAstReturnStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstBreakStmt
AstToStringVisitor::visit(HexAstBreakStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstContinueStmt
AstToStringVisitor::visit(HexAstContinueStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstRaiseStmt
AstToStringVisitor::visit(HexAstRaiseStmt stmt)
{
  HEX_ASSERT(stmt); 
  return stmt;
}

HexAstExprListStmt
AstToStringVisitor::visit(HexAstExprListStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstStmtGroup
AstToStringVisitor::visit(HexAstStmtGroup group)
{
  HEX_ASSERT(group);
  return group;
}

HexAstHexProgram
AstToStringVisitor::visit(HexAstHexProgram program)
{
  HEX_ASSERT(program);
  return program;
}
