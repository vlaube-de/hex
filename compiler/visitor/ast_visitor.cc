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

#include <sneaker/libc/assert.h>
#include "ast_visitor.h"


HexAstIdentifier
AstVisitor::visit(HexAstIdentifier identifier)
{
  ASSERT(identifier);
  return identifier;
}

HexAstDecimalIntegerLiteral
AstVisitor::visit(HexAstDecimalIntegerLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstBinaryIntegerLiteral
AstVisitor::visit(HexAstBinaryIntegerLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstOctalIntegerLiteral
AstVisitor::visit(HexAstOctalIntegerLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstHexadecimalIntegerLiteral
AstVisitor::visit(HexAstHexadecimalIntegerLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstFloatLiteral
AstVisitor::visit(HexAstFloatLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstSingleQuoteStringLiteral
AstVisitor::visit(HexAstSingleQuoteStringLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstDoubleQuoteStringLiteral
AstVisitor::visit(HexAstDoubleQuoteStringLiteral literal)
{
  ASSERT(literal);
  return literal;
}

HexAstCall
AstVisitor::visit(HexAstCall call)
{
  ASSERT(call);
  return call;
}

HexAstAttributeRef
AstVisitor::visit(HexAstAttributeRef ref)
{
  ASSERT(ref);
  return ref;
}

HexAstSlicing
AstVisitor::visit(HexAstSlicing slicing)
{
  ASSERT(slicing);
  return slicing;
}

HexAstTargetList
AstVisitor::visit(HexAstTargetList targets)
{
  ASSERT(targets);
  return targets;
}

HexAstName
AstVisitor::visit(HexAstName name)
{
  ASSERT(name);
  return name;
}

HexAstNameList
AstVisitor::visit(HexAstNameList names)
{
  ASSERT(names);
  return names;
}

HexAstPositiveExpr
AstVisitor::visit(HexAstPositiveExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstNegativeExpr
AstVisitor::visit(HexAstNegativeExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstNotExpr
AstVisitor::visit(HexAstNotExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseNotExpr
AstVisitor::visit(HexAstBitwiseNotExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstIncrementExpr
AstVisitor::visit(HexAstIncrementExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstDecrementExpr
AstVisitor::visit(HexAstDecrementExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstExistentialExpr
AstVisitor::visit(HexAstExistentialExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstAdditionExpr
AstVisitor::visit(HexAstAdditionExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstSubtractionExpr
AstVisitor::visit(HexAstSubtractionExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstMultiplicationExpr
AstVisitor::visit(HexAstMultiplicationExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstDivisionExpr
AstVisitor::visit(HexAstDivisionExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstModulusExpr
AstVisitor::visit(HexAstModulusExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstPowerExpr
AstVisitor::visit(HexAstPowerExpr expr)
{
  ASSERT(expr);
  return expr; 
}

HexAstBitwiseANDExpr
AstVisitor::visit(HexAstBitwiseANDExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseORExpr
AstVisitor::visit(HexAstBitwiseORExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseXORExpr
AstVisitor::visit(HexAstBitwiseXORExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseLeftShiftExpr
AstVisitor::visit(HexAstBitwiseLeftShiftExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseRightShiftExpr
AstVisitor::visit(HexAstBitwiseRightShiftExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstEqualsExpr
AstVisitor::visit(HexAstEqualsExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstNotEqualExpr
AstVisitor::visit(HexAstNotEqualExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstIsExpr
AstVisitor::visit(HexAstIsExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstIsNotExpr
AstVisitor::visit(HexAstIsNotExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstLessThanExpr
AstVisitor::visit(HexAstLessThanExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstGreaterThanExpr
AstVisitor::visit(HexAstGreaterThanExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstGreaterOrEqualsExpr
AstVisitor::visit(HexAstGreaterOrEqualsExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstLessOrEqualsExpr
AstVisitor::visit(HexAstLessOrEqualsExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstInExpr
AstVisitor::visit(HexAstInExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstNotInExpr
AstVisitor::visit(HexAstNotInExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstLogicalANDExpr
AstVisitor::visit(HexAstLogicalANDExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstLogicalORExpr
AstVisitor::visit(HexAstLogicalORExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstInclusiveRangeExpr
AstVisitor::visit(HexAstInclusiveRangeExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstExclusiveRangeExpr
AstVisitor::visit(HexAstExclusiveRangeExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstConditionalExpr
AstVisitor::visit(HexAstConditionalExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstAdditionAssignmentExpr
AstVisitor::visit(HexAstAdditionAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstSubtractionAssignmentExpr
AstVisitor::visit(HexAstSubtractionAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstMultiplicationAssignmentExpr
AstVisitor::visit(HexAstMultiplicationAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstDivisionAssignmentExpr
AstVisitor::visit(HexAstDivisionAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstModulusAssignmentExpr
AstVisitor::visit(HexAstModulusAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseANDAssignmentExpr
AstVisitor::visit(HexAstBitwiseANDAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseORAssignmentExpr
AstVisitor::visit(HexAstBitwiseORAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseXORAssignmentExpr
AstVisitor::visit(HexAstBitwiseXORAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseLeftShiftAssignmentExpr
AstVisitor::visit(HexAstBitwiseLeftShiftAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstBitwiseRightShiftAssignmentExpr
AstVisitor::visit(HexAstBitwiseRightShiftAssignmentExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstYieldExpr
AstVisitor::visit(HexAstYieldExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstStringCompositionExpr
AstVisitor::visit(HexAstStringCompositionExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstNestedComprehension
AstVisitor::visit(HexAstNestedComprehension comprehension)
{
  ASSERT(comprehension);
  return comprehension;
}

HexAstExprComprehension
AstVisitor::visit(HexAstExprComprehension comprehension)
{
  ASSERT(comprehension);
  return comprehension;
}

HexAstGeneratorExpr
AstVisitor::visit(HexAstGeneratorExpr expr)
{
  ASSERT(expr);
  return expr;
}

HexAstParenForm
AstVisitor::visit(HexAstParenForm paren)
{
  ASSERT(paren);
  return paren; 
}

HexAstExplicitListForm
AstVisitor::visit(HexAstExplicitListForm list)
{
  ASSERT(list);
  return list;
}

HexAstImplicitListForm
AstVisitor::visit(HexAstImplicitListForm list)
{
  ASSERT(list);
  return list;
}

HexAstExplicitDictForm
AstVisitor::visit(HexAstExplicitDictForm dict)
{
  ASSERT(dict);
  return dict;
}

HexAstImplicitDictForm
AstVisitor::visit(HexAstImplicitDictForm dict)
{
  ASSERT(dict);
  return dict;
}

HexAstObjectForm
AstVisitor::visit(HexAstObjectForm object)
{
  ASSERT(object);
  return object;
}

HexAstExprList
AstVisitor::visit(HexAstExprList exprlist)
{
  ASSERT(exprlist);
  return exprlist;
}

HexAstSimpleParam
AstVisitor::visit(HexAstSimpleParam param)
{
  ASSERT(param);
  return param;
}

HexAstSimpleParamList
AstVisitor::visit(HexAstSimpleParamList params)
{
  ASSERT(params);
  return params;
}

HexAstKeywordParam
AstVisitor::visit(HexAstKeywordParam param)
{
  ASSERT(param);
  return param;
}

HexAstKeywordParamList
AstVisitor::visit(HexAstKeywordParamList params)
{
  ASSERT(params);
  return params;
}

HexAstParameterList
AstVisitor::visit(HexAstParameterList params)
{
  ASSERT(params);
  return params;
}

HexAstSimpleArgList
AstVisitor::visit(HexAstSimpleArgList args)
{
  ASSERT(args);
  return args;
}

HexAstKeywordArg
AstVisitor::visit(HexAstKeywordArg arg)
{
  ASSERT(arg);
  return arg;
}

HexAstKeywordArgList
AstVisitor::visit(HexAstKeywordArgList args)
{
  ASSERT(args);
  return args;
}

HexAstArgList
AstVisitor::visit(HexAstArgList arglist)
{
  ASSERT(arglist);
  return arglist;
}

HexAstFieldDef
AstVisitor::visit(HexAstFieldDef def)
{
  ASSERT(def);
  return def;
}

HexAstFieldDefList
AstVisitor::visit(HexAstFieldDefList fields)
{
  ASSERT(fields);
  return fields;
}

HexAstKeyValuePair
AstVisitor::visit(HexAstKeyValuePair pair)
{
  ASSERT(pair);
  return pair;
}

HexAstKeyValuePairList
AstVisitor::visit(HexAstKeyValuePairList pairs)
{
  ASSERT(pairs);
  return pairs;
}

HexAstAttributeValuePair
AstVisitor::visit(HexAstAttributeValuePair pair)
{
  ASSERT(pair);
  return pair;
}

HexAstAttributeValuePairList
AstVisitor::visit(HexAstAttributeValuePairList pairs)
{
  ASSERT(pairs);
  return pairs;
}

HexAstDecorator
AstVisitor::visit(HexAstDecorator decorator)
{
  ASSERT(decorator);
  return decorator;
}

HexAstDecoratorList
AstVisitor::visit(HexAstDecoratorList decorators)
{
  ASSERT(decorators);
  return decorators;
}

HexAstAssignmentFeature
AstVisitor::visit(HexAstAssignmentFeature feature)
{
  ASSERT(feature);
  return feature;
}

HexAstAssignmentStmt
AstVisitor::visit(HexAstAssignmentStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstUsingSrc
AstVisitor::visit(HexAstUsingSrc src)
{
  ASSERT(src);
  return src;
}

HexAstRelativeUsingStmt
AstVisitor::visit(HexAstRelativeUsingStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstAbsoluteUsingStmt
AstVisitor::visit(HexAstAbsoluteUsingStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstElifStmt
AstVisitor::visit(HexAstElifStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstElifStmtGroup
AstVisitor::visit(HexAstElifStmtGroup group)
{
  ASSERT(group);
  return group;
}

HexAstIfStmt
AstVisitor::visit(HexAstIfStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstForStmt
AstVisitor::visit(HexAstForStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstWithStmt
AstVisitor::visit(HexAstWithStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstLockStmt
AstVisitor::visit(HexAstLockStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstWhileStmt
AstVisitor::visit(HexAstWhileStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstCatchStmt
AstVisitor::visit(HexAstCatchStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstCatchStmtGroup
AstVisitor::visit(HexAstCatchStmtGroup stmts)
{
  ASSERT(stmts);
  return stmts;
}

HexAstTryStmt
AstVisitor::visit(HexAstTryStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstClassDef
AstVisitor::visit(HexAstClassDef def)
{
  ASSERT(def);
  return def;
}

HexAstSimpleLambda
AstVisitor::visit(HexAstSimpleLambda lambda)
{
  ASSERT(lambda);
  return lambda;
}

HexAstComplexLambda
AstVisitor::visit(HexAstComplexLambda lambda)
{
  ASSERT(lambda);
  return lambda;
}

HexAstInputStmt
AstVisitor::visit(HexAstInputStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstOutputStmt
AstVisitor::visit(HexAstOutputStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstTaskState
AstVisitor::visit(HexAstTaskState state)
{
  ASSERT(state);
  return state;
}

HexAstConditionalPreposition
AstVisitor::visit(HexAstConditionalPreposition preposition)
{
  ASSERT(preposition); 
  return preposition;
}

HexAstConditionalClause
AstVisitor::visit(HexAstConditionalClause clause)
{
  ASSERT(clause);
  return clause;
}

HexAstStartClause
AstVisitor::visit(HexAstStartClause clause)
{
  ASSERT(clause);
  return clause;
}

HexAstPauseClause
AstVisitor::visit(HexAstPauseClause clause)
{
  ASSERT(clause);
  return clause;
}

HexAstResumeClause
AstVisitor::visit(HexAstResumeClause clause)
{
  ASSERT(clause);
  return clause;
}

HexAstCancelClause
AstVisitor::visit(HexAstCancelClause clause)
{
  ASSERT(clause);
  return clause;
}

HexAstStopClause
AstVisitor::visit(HexAstStopClause clause)
{
  ASSERT(clause);
  return clause;
}

HexAstTaskDef
AstVisitor::visit(HexAstTaskDef def)
{
  ASSERT(def);
  return def;
}

HexAstAwaitStmt
AstVisitor::visit(HexAstAwaitStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstReturnStmt
AstVisitor::visit(HexAstReturnStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstBreakStmt
AstVisitor::visit(HexAstBreakStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstContinueStmt
AstVisitor::visit(HexAstContinueStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstRaiseStmt
AstVisitor::visit(HexAstRaiseStmt stmt)
{
  ASSERT(stmt); 
  return stmt;
}

HexAstExprListStmt
AstVisitor::visit(HexAstExprListStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstSimpleIfStmt
AstVisitor::visit(HexAstSimpleIfStmt stmt)
{
  ASSERT(stmt);
  return stmt;
}

HexAstStmtGroup
AstVisitor::visit(HexAstStmtGroup group)
{
  ASSERT(group);
  return group;
}

HexAstHexProgram
AstVisitor::visit(HexAstHexProgram program)
{
  ASSERT(program);
  return program;
}