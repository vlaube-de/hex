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
AstVisitor::visit(HexAstIdentifier identifier)
{
  HEX_ASSERT(identifier);
  return identifier;
}

HexAstDecimalIntegerLiteral
AstVisitor::visit(HexAstDecimalIntegerLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstBinaryIntegerLiteral
AstVisitor::visit(HexAstBinaryIntegerLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstOctalIntegerLiteral
AstVisitor::visit(HexAstOctalIntegerLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstHexadecimalIntegerLiteral
AstVisitor::visit(HexAstHexadecimalIntegerLiteral literal)
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

HexAstSingleQuoteStringLiteral
AstVisitor::visit(HexAstSingleQuoteStringLiteral literal)
{
  HEX_ASSERT(literal);
  return literal;
}

HexAstDoubleQuoteStringLiteral
AstVisitor::visit(HexAstDoubleQuoteStringLiteral literal)
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

HexAstNameList
AstVisitor::visit(HexAstNameList names)
{
  HEX_ASSERT(names);
  return names;
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

HexAstAdditionExpr
AstVisitor::visit(HexAstAdditionExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstSubtractionExpr
AstVisitor::visit(HexAstSubtractionExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstMultiplicationExpr
AstVisitor::visit(HexAstMultiplicationExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstDivisionExpr
AstVisitor::visit(HexAstDivisionExpr expr)
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

HexAstBitwiseANDExpr
AstVisitor::visit(HexAstBitwiseANDExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseORExpr
AstVisitor::visit(HexAstBitwiseORExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseXORExpr
AstVisitor::visit(HexAstBitwiseXORExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseLeftShiftExpr
AstVisitor::visit(HexAstBitwiseLeftShiftExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseRightShiftExpr
AstVisitor::visit(HexAstBitwiseRightShiftExpr expr)
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

HexAstLogicalANDExpr
AstVisitor::visit(HexAstLogicalANDExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstLogicalORExpr
AstVisitor::visit(HexAstLogicalORExpr expr)
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

HexAstAdditionAssignmentExpr
AstVisitor::visit(HexAstAdditionAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstSubtractionAssignmentExpr
AstVisitor::visit(HexAstSubtractionAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstMultiplicationAssignmentExpr
AstVisitor::visit(HexAstMultiplicationAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstDivisionAssignmentExpr
AstVisitor::visit(HexAstDivisionAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstModulusAssignmentExpr
AstVisitor::visit(HexAstModulusAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseANDAssignmentExpr
AstVisitor::visit(HexAstBitwiseANDAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseORAssignmentExpr
AstVisitor::visit(HexAstBitwiseORAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseXORAssignmentExpr
AstVisitor::visit(HexAstBitwiseXORAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseLeftShiftAssignmentExpr
AstVisitor::visit(HexAstBitwiseLeftShiftAssignmentExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstBitwiseRightShiftAssignmentExpr
AstVisitor::visit(HexAstBitwiseRightShiftAssignmentExpr expr)
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

HexAstStringCompositionExpr
AstVisitor::visit(HexAstStringCompositionExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstNestedComprehension
AstVisitor::visit(HexAstNestedComprehension comprehension)
{
  HEX_ASSERT(comprehension);
  return comprehension;
}

HexAstExprComprehension
AstVisitor::visit(HexAstExprComprehension comprehension)
{
  HEX_ASSERT(comprehension);
  return comprehension;
}

HexAstGeneratorExpr
AstVisitor::visit(HexAstGeneratorExpr expr)
{
  HEX_ASSERT(expr);
  return expr;
}

HexAstParenForm
AstVisitor::visit(HexAstParenForm paren)
{
  HEX_ASSERT(paren);
  return paren; 
}

HexAstExplicitListForm
AstVisitor::visit(HexAstExplicitListForm list)
{
  HEX_ASSERT(list);
  return list;
}

HexAstImplicitListForm
AstVisitor::visit(HexAstImplicitListForm list)
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

HexAstObjectForm
AstVisitor::visit(HexAstObjectForm object)
{
  HEX_ASSERT(object);
  return object;
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

HexAstKeywordParam
AstVisitor::visit(HexAstKeywordParam param)
{
  HEX_ASSERT(param);
  return param;
}

HexAstKeywordParamList
AstVisitor::visit(HexAstKeywordParamList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstParameterList
AstVisitor::visit(HexAstParameterList params)
{
  HEX_ASSERT(params);
  return params;
}

HexAstSimpleArgList
AstVisitor::visit(HexAstSimpleArgList args)
{
  HEX_ASSERT(args);
  return args;
}

HexAstKeywordArg
AstVisitor::visit(HexAstKeywordArg arg)
{
  HEX_ASSERT(arg);
  return arg;
}

HexAstKeywordArgList
AstVisitor::visit(HexAstKeywordArgList args)
{
  HEX_ASSERT(args);
  return args;
}

HexAstArgList
AstVisitor::visit(HexAstArgList arglist)
{
  HEX_ASSERT(arglist);
  return arglist;
}

HexAstFieldDef
AstVisitor::visit(HexAstFieldDef def)
{
  HEX_ASSERT(def);
  return def;
}

HexAstFieldDefList
AstVisitor::visit(HexAstFieldDefList fields)
{
  HEX_ASSERT(fields);
  return fields;
}

HexAstKeyValuePair
AstVisitor::visit(HexAstKeyValuePair pair)
{
  HEX_ASSERT(pair);
  return pair;
}

HexAstKeyValuePairList
AstVisitor::visit(HexAstKeyValuePairList pairs)
{
  HEX_ASSERT(pairs);
  return pairs;
}

HexAstAttributeValuePair
AstVisitor::visit(HexAstAttributeValuePair pair)
{
  HEX_ASSERT(pair);
  return pair;
}

HexAstAttributeValuePairList
AstVisitor::visit(HexAstAttributeValuePairList pairs)
{
  HEX_ASSERT(pairs);
  return pairs;
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

HexAstAssignmentFeature
AstVisitor::visit(HexAstAssignmentFeature feature)
{
  HEX_ASSERT(feature);
  return feature;
}

HexAstAssignmentStmt
AstVisitor::visit(HexAstAssignmentStmt stmt)
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

HexAstRelativeUsingStmt
AstVisitor::visit(HexAstRelativeUsingStmt stmt)
{
  HEX_ASSERT(stmt);
  return stmt;
}

HexAstAbsoluteUsingStmt
AstVisitor::visit(HexAstAbsoluteUsingStmt stmt)
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

HexAstSimpleLambda
AstVisitor::visit(HexAstSimpleLambda lambda)
{
  HEX_ASSERT(lambda);
  return lambda;
}

HexAstComplexLambda
AstVisitor::visit(HexAstComplexLambda lambda)
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

HexAstStartClause
AstVisitor::visit(HexAstStartClause clause)
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

HexAstSimpleIfStmt
AstVisitor::visit(HexAstSimpleIfStmt stmt)
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