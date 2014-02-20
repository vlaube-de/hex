/*
 * HEX Programming Language
 * Copyrexpr (C) 2013  Yanzheng Li
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

#include "hex_stmt_codegen_visitor.h"
#include <sneaker/libc/assert.h>
#include "../ast/ast.h"


HexStmtCodeGenerationVisitor::HexStmtCodeGenerationVisitor():
  _cv_generator(new QuadrupleCodeVectorGenerator())
{
}

QuadrupleCodeVectorGenerator*
HexStmtCodeGenerationVisitor::cv_generator()
{
  return this->_cv_generator;
}

template<class T>
void
HexStmtCodeGenerationVisitor::iterate(std::list<T>* list)
{
  typename std::list<T>::iterator itr;
  for(itr=list->begin(); itr != list->end(); itr++) {
    ((T)(*itr))->accept(this);
  }
}

HexAstIdentifier
HexStmtCodeGenerationVisitor::visit(HexAstIdentifier identifier_)
{
  HexAstIdentifier identifier = AstVisitor::visit(identifier_);
  // TODO: to be implemented...
  return identifier;
}

HexAstDecimalIntegerLiteral
HexStmtCodeGenerationVisitor::visit(HexAstDecimalIntegerLiteral literal_)
{
  HexAstDecimalIntegerLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstBinaryIntegerLiteral
HexStmtCodeGenerationVisitor::visit(HexAstBinaryIntegerLiteral literal_)
{
  HexAstBinaryIntegerLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstOctalIntegerLiteral
HexStmtCodeGenerationVisitor::visit(HexAstOctalIntegerLiteral literal_)
{
  HexAstOctalIntegerLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstHexadecimalIntegerLiteral
HexStmtCodeGenerationVisitor::visit(HexAstHexadecimalIntegerLiteral literal_)
{
  HexAstHexadecimalIntegerLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstFloatLiteral
HexStmtCodeGenerationVisitor::visit(HexAstFloatLiteral literal_)
{
  HexAstFloatLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstSingleQuoteStringLiteral
HexStmtCodeGenerationVisitor::visit(HexAstSingleQuoteStringLiteral literal_)
{
  HexAstSingleQuoteStringLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstDoubleQuoteStringLiteral
HexStmtCodeGenerationVisitor::visit(HexAstDoubleQuoteStringLiteral literal_)
{
  HexAstDoubleQuoteStringLiteral literal = AstVisitor::visit(literal_);
  // TODO: to be implemented...
  return literal;
}

HexAstCall
HexStmtCodeGenerationVisitor::visit(HexAstCall call_)
{
  HexAstCall call = AstVisitor::visit(call_);
  // TODO: to be implemented...
  return call;
}

HexAstAttributeRef
HexStmtCodeGenerationVisitor::visit(HexAstAttributeRef ref_)
{
  HexAstAttributeRef ref = AstVisitor::visit(ref_);
  // TODO: to be implemented...
  return ref;
}

HexAstSlicing
HexStmtCodeGenerationVisitor::visit(HexAstSlicing slicing_)
{
  HexAstSlicing slicing = AstVisitor::visit(slicing_);
  // TODO: to be implemented...
  return slicing;
}

HexAstTargetList
HexStmtCodeGenerationVisitor::visit(HexAstTargetList targets_)
{
  HexAstTargetList targets = AstVisitor::visit(targets_);
  // TODO: to be implemented...
  return targets;
}

HexAstName
HexStmtCodeGenerationVisitor::visit(HexAstName name_)
{
  HexAstName name = AstVisitor::visit(name_);
  // TODO: to be implemented...
  return name;
}

HexAstNameList
HexStmtCodeGenerationVisitor::visit(HexAstNameList names_)
{
  HexAstNameList names = AstVisitor::visit(names_);
  // TODO: to be implemented...
  return names;
}

HexAstPositiveExpr
HexStmtCodeGenerationVisitor::visit(HexAstPositiveExpr expr_)
{
  HexAstPositiveExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstNegativeExpr
HexStmtCodeGenerationVisitor::visit(HexAstNegativeExpr expr_)
{
  HexAstNegativeExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstNotExpr
HexStmtCodeGenerationVisitor::visit(HexAstNotExpr expr_)
{
  HexAstNotExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseNotExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseNotExpr expr_)
{
  HexAstBitwiseNotExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstIncrementExpr
HexStmtCodeGenerationVisitor::visit(HexAstIncrementExpr expr_)
{
  HexAstIncrementExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstDecrementExpr
HexStmtCodeGenerationVisitor::visit(HexAstDecrementExpr expr_)
{
  HexAstDecrementExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstExistentialExpr
HexStmtCodeGenerationVisitor::visit(HexAstExistentialExpr expr_)
{
  HexAstExistentialExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstAdditionExpr
HexStmtCodeGenerationVisitor::visit(HexAstAdditionExpr expr_)
{
  HexAstAdditionExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstSubtractionExpr
HexStmtCodeGenerationVisitor::visit(HexAstSubtractionExpr expr_)
{
  HexAstSubtractionExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstMultiplicationExpr
HexStmtCodeGenerationVisitor::visit(HexAstMultiplicationExpr expr_)
{
  HexAstMultiplicationExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstDivisionExpr
HexStmtCodeGenerationVisitor::visit(HexAstDivisionExpr expr_)
{
  HexAstDivisionExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstModulusExpr
HexStmtCodeGenerationVisitor::visit(HexAstModulusExpr expr_)
{
  HexAstModulusExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstPowerExpr
HexStmtCodeGenerationVisitor::visit(HexAstPowerExpr expr_)
{
  HexAstPowerExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseANDExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseANDExpr expr_)
{
  HexAstBitwiseANDExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseORExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseORExpr expr_)
{
  HexAstBitwiseORExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseXORExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseXORExpr expr_)
{
  HexAstBitwiseXORExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseLeftShiftExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseLeftShiftExpr expr_)
{
  HexAstBitwiseLeftShiftExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseRightShiftExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseRightShiftExpr expr_)
{
  HexAstBitwiseRightShiftExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstEqualsExpr
HexStmtCodeGenerationVisitor::visit(HexAstEqualsExpr expr_)
{
  HexAstEqualsExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstNotEqualExpr
HexStmtCodeGenerationVisitor::visit(HexAstNotEqualExpr expr_)
{
  HexAstNotEqualExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstIsExpr
HexStmtCodeGenerationVisitor::visit(HexAstIsExpr expr_)
{
  HexAstIsExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstIsNotExpr
HexStmtCodeGenerationVisitor::visit(HexAstIsNotExpr expr_)
{
  HexAstIsNotExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstLessThanExpr
HexStmtCodeGenerationVisitor::visit(HexAstLessThanExpr expr_)
{
  HexAstLessThanExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstGreaterThanExpr
HexStmtCodeGenerationVisitor::visit(HexAstGreaterThanExpr expr_)
{
  HexAstGreaterThanExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstGreaterOrEqualsExpr
HexStmtCodeGenerationVisitor::visit(HexAstGreaterOrEqualsExpr expr_)
{
  HexAstGreaterOrEqualsExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstLessOrEqualsExpr
HexStmtCodeGenerationVisitor::visit(HexAstLessOrEqualsExpr expr_)
{
  HexAstLessOrEqualsExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstInExpr
HexStmtCodeGenerationVisitor::visit(HexAstInExpr expr_)
{
  HexAstInExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstNotInExpr
HexStmtCodeGenerationVisitor::visit(HexAstNotInExpr expr_)
{
  HexAstNotInExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstLogicalANDExpr
HexStmtCodeGenerationVisitor::visit(HexAstLogicalANDExpr expr_)
{
  HexAstLogicalANDExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstLogicalORExpr
HexStmtCodeGenerationVisitor::visit(HexAstLogicalORExpr expr_)
{
  HexAstLogicalORExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstInclusiveRangeExpr
HexStmtCodeGenerationVisitor::visit(HexAstInclusiveRangeExpr expr_)
{
  HexAstInclusiveRangeExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstExclusiveRangeExpr
HexStmtCodeGenerationVisitor::visit(HexAstExclusiveRangeExpr expr_)
{
  HexAstExclusiveRangeExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstConditionalExpr
HexStmtCodeGenerationVisitor::visit(HexAstConditionalExpr expr_)
{
  HexAstConditionalExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstAdditionAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstAdditionAssignmentExpr expr_)
{
  HexAstAdditionAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstSubtractionAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstSubtractionAssignmentExpr expr_)
{
  HexAstSubtractionAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstMultiplicationAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstMultiplicationAssignmentExpr expr_)
{
  HexAstMultiplicationAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstDivisionAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstDivisionAssignmentExpr expr_)
{
  HexAstDivisionAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstModulusAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstModulusAssignmentExpr expr_)
{
  HexAstModulusAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseANDAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseANDAssignmentExpr expr_)
{
  HexAstBitwiseANDAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseORAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseORAssignmentExpr expr_)
{
  HexAstBitwiseORAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseXORAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseXORAssignmentExpr expr_)
{
  HexAstBitwiseXORAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseLeftShiftAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseLeftShiftAssignmentExpr expr_)
{
  HexAstBitwiseLeftShiftAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstBitwiseRightShiftAssignmentExpr
HexStmtCodeGenerationVisitor::visit(HexAstBitwiseRightShiftAssignmentExpr expr_)
{
  HexAstBitwiseRightShiftAssignmentExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstYieldExpr
HexStmtCodeGenerationVisitor::visit(HexAstYieldExpr expr_)
{
  HexAstYieldExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstStringCompositionExpr
HexStmtCodeGenerationVisitor::visit(HexAstStringCompositionExpr expr_)
{
  HexAstStringCompositionExpr expr = AstVisitor::visit(expr_);
  // TODO: to be implemented...
  return expr;
}

HexAstExplicitListForm
HexStmtCodeGenerationVisitor::visit(HexAstExplicitListForm list_)
{
  HexAstExplicitListForm list = AstVisitor::visit(list_);
  // TODO: to be implemented...
  return list;
}

HexAstImplicitListForm
HexStmtCodeGenerationVisitor::visit(HexAstImplicitListForm list_)
{
  HexAstImplicitListForm list = AstVisitor::visit(list_);
  // TODO: to be implemented...
  return list;
}

HexAstExplicitDictForm
HexStmtCodeGenerationVisitor::visit(HexAstExplicitDictForm dict_)
{
  HexAstExplicitDictForm dict = AstVisitor::visit(dict_);
  // TODO: to be implemented...
  return dict;
}

HexAstImplicitDictForm
HexStmtCodeGenerationVisitor::visit(HexAstImplicitDictForm dict_)
{
  HexAstImplicitDictForm dict = AstVisitor::visit(dict_);
  // TODO: to be implemented...
  return dict;
}

HexAstObjectForm
HexStmtCodeGenerationVisitor::visit(HexAstObjectForm object_)
{
  HexAstObjectForm object = AstVisitor::visit(object_);
  // TODO: to be implemented...
  return object;
}

HexAstExprList
HexStmtCodeGenerationVisitor::visit(HexAstExprList exprs_)
{
  HexAstExprList exprs = AstVisitor::visit(exprs_);
  // TODO: to be implemented...
  return exprs;
}

HexAstSimpleParam
HexStmtCodeGenerationVisitor::visit(HexAstSimpleParam param_)
{
  HexAstSimpleParam param = AstVisitor::visit(param_);
  // TODO: to be implemented...
  return param;
}

HexAstSimpleParamList
HexStmtCodeGenerationVisitor::visit(HexAstSimpleParamList params_)
{
  HexAstSimpleParamList params = AstVisitor::visit(params_);
  // TODO: to be implemented...
  return params;
}

HexAstKeywordParam
HexStmtCodeGenerationVisitor::visit(HexAstKeywordParam param_)
{
  HexAstKeywordParam param = AstVisitor::visit(param_);
  // TODO: to be implemented...
  return param;
}

HexAstKeywordParamList
HexStmtCodeGenerationVisitor::visit(HexAstKeywordParamList params_)
{
  HexAstKeywordParamList params = AstVisitor::visit(params_);
  // TODO: to be implemented...
  return params;
}

HexAstParameterList
HexStmtCodeGenerationVisitor::visit(HexAstParameterList params_)
{
  HexAstParameterList params = AstVisitor::visit(params_);
  // TODO: to be implemented...
  return params;
}

HexAstSimpleArgList
HexStmtCodeGenerationVisitor::visit(HexAstSimpleArgList args_)
{
  HexAstSimpleArgList args = AstVisitor::visit(args_);
  // TODO: to be implemented...
  return args;
}

HexAstKeywordArg
HexStmtCodeGenerationVisitor::visit(HexAstKeywordArg arg_)
{
  HexAstKeywordArg arg = AstVisitor::visit(arg_);
  // TODO: to be implemented...
  return arg;
}

HexAstKeywordArgList
HexStmtCodeGenerationVisitor::visit(HexAstKeywordArgList args_)
{
  HexAstKeywordArgList args = AstVisitor::visit(args_);
  // TODO: to be implemented...
  return args;
}

HexAstArgList
HexStmtCodeGenerationVisitor::visit(HexAstArgList args_)
{
  HexAstArgList args = AstVisitor::visit(args_);
  // TODO: to be implemented...
  return args;
}

HexAstFieldDef
HexStmtCodeGenerationVisitor::visit(HexAstFieldDef field_)
{
  HexAstFieldDef field = AstVisitor::visit(field_);
  // TODO: to be implemented...
  return field;
}

HexAstFieldDefList
HexStmtCodeGenerationVisitor::visit(HexAstFieldDefList fields_)
{
  HexAstFieldDefList fields = AstVisitor::visit(fields_);
  // TODO: to be implemented...
  return fields;
}

HexAstKeyValuePair
HexStmtCodeGenerationVisitor::visit(HexAstKeyValuePair pair_)
{
  HexAstKeyValuePair pair = AstVisitor::visit(pair_);
  // TODO: to be implemented...
  return pair;
}

HexAstKeyValuePairList
HexStmtCodeGenerationVisitor::visit(HexAstKeyValuePairList pairs_)
{
  HexAstKeyValuePairList pairs = AstVisitor::visit(pairs_);
  // TODO: to be implemented...
  return pairs;
}

HexAstAttributeValuePair
HexStmtCodeGenerationVisitor::visit(HexAstAttributeValuePair pair_)
{
  HexAstAttributeValuePair pair = AstVisitor::visit(pair_);
  // TODO: to be implemented...
  return pair;
}

HexAstAttributeValuePairList
HexStmtCodeGenerationVisitor::visit(HexAstAttributeValuePairList pairs_)
{
  HexAstAttributeValuePairList pairs = AstVisitor::visit(pairs_);
  // TODO: to be implemented...
  return pairs;
}

HexAstDecorator
HexStmtCodeGenerationVisitor::visit(HexAstDecorator decorator_)
{
  HexAstDecorator decorator = AstVisitor::visit(decorator_);
  // TODO: to be implemented...
  return decorator;
}

HexAstDecoratorList
HexStmtCodeGenerationVisitor::visit(HexAstDecoratorList decorators_)
{
  HexAstDecoratorList decorators = AstVisitor::visit(decorators_);
  // TODO: to be implemented...
  return decorators;
}

HexAstAssignmentStmt
HexStmtCodeGenerationVisitor::visit(HexAstAssignmentStmt stmt_)
{
  HexAstAssignmentStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstRelativeUsingStmt
HexStmtCodeGenerationVisitor::visit(HexAstRelativeUsingStmt stmt_)
{
  HexAstRelativeUsingStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstAbsoluteUsingStmt
HexStmtCodeGenerationVisitor::visit(HexAstAbsoluteUsingStmt stmt_)
{
  HexAstAbsoluteUsingStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstElifStmt
HexStmtCodeGenerationVisitor::visit(HexAstElifStmt stmt_)
{
  HexAstElifStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstElifStmtGroup
HexStmtCodeGenerationVisitor::visit(HexAstElifStmtGroup stmts_)
{
  HexAstElifStmtGroup stmts = AstVisitor::visit(stmts_);
  // TODO: to be implemented...
  return stmts;
}

HexAstIfStmt
HexStmtCodeGenerationVisitor::visit(HexAstIfStmt stmt_)
{
  HexAstIfStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstForStmt
HexStmtCodeGenerationVisitor::visit(HexAstForStmt stmt_)
{
  HexAstForStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstWithStmt
HexStmtCodeGenerationVisitor::visit(HexAstWithStmt stmt_)
{
  HexAstWithStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstLockStmt
HexStmtCodeGenerationVisitor::visit(HexAstLockStmt stmt_)
{
  HexAstLockStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstWhileStmt
HexStmtCodeGenerationVisitor::visit(HexAstWhileStmt stmt_)
{
  HexAstWhileStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstCatchStmt
HexStmtCodeGenerationVisitor::visit(HexAstCatchStmt stmt_)
{
  HexAstCatchStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstCatchStmtGroup
HexStmtCodeGenerationVisitor::visit(HexAstCatchStmtGroup stmts_)
{
  HexAstCatchStmtGroup stmts = AstVisitor::visit(stmts_);
  // TODO: to be implemented...
  return stmts;
}

HexAstTryStmt
HexStmtCodeGenerationVisitor::visit(HexAstTryStmt stmt_)
{
  HexAstTryStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstInputStmt
HexStmtCodeGenerationVisitor::visit(HexAstInputStmt stmt_)
{
  HexAstInputStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstOutputStmt
HexStmtCodeGenerationVisitor::visit(HexAstOutputStmt stmt_)
{
  HexAstOutputStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstTaskState
HexStmtCodeGenerationVisitor::visit(HexAstTaskState state_)
{
  HexAstTaskState state = AstVisitor::visit(state_);
  // TODO: to be implemented...
  return state;
}

HexAstConditionalPreposition
HexStmtCodeGenerationVisitor::visit(HexAstConditionalPreposition preposition_)
{
  HexAstConditionalPreposition preposition = AstVisitor::visit(preposition_);
  // TODO: to be implemented...
  return preposition;
}

HexAstConditionalClause
HexStmtCodeGenerationVisitor::visit(HexAstConditionalClause clause_)
{
  HexAstConditionalClause clause = AstVisitor::visit(clause_);
  // TODO: to be implemented...
  return clause;
}

HexAstStartClause
HexStmtCodeGenerationVisitor::visit(HexAstStartClause clause_)
{
  HexAstStartClause clause = AstVisitor::visit(clause_);
  // TODO: to be implemented...
  return clause;
}

HexAstPauseClause
HexStmtCodeGenerationVisitor::visit(HexAstPauseClause clause_)
{
  HexAstPauseClause clause = AstVisitor::visit(clause_);
  // TODO: to be implemented...
  return clause;
}

HexAstResumeClause
HexStmtCodeGenerationVisitor::visit(HexAstResumeClause clause_)
{
  HexAstResumeClause clause = AstVisitor::visit(clause_);
  // TODO: to be implemented...
  return clause;
}

HexAstCancelClause
HexStmtCodeGenerationVisitor::visit(HexAstCancelClause clause_)
{
  HexAstCancelClause clause = AstVisitor::visit(clause_);
  // TODO: to be implemented...
  return clause;
}

HexAstStopClause
HexStmtCodeGenerationVisitor::visit(HexAstStopClause clause_)
{
  HexAstStopClause clause = AstVisitor::visit(clause_);
  // TODO: to be implemented...
  return clause;
}

HexAstTaskDef
HexStmtCodeGenerationVisitor::visit(HexAstTaskDef def_)
{
  HexAstTaskDef def = AstVisitor::visit(def_);
  // TODO: to be implemented...
  return def;
}

HexAstAwaitStmt
HexStmtCodeGenerationVisitor::visit(HexAstAwaitStmt stmt_)
{
  HexAstAwaitStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstReturnStmt
HexStmtCodeGenerationVisitor::visit(HexAstReturnStmt stmt_)
{
  HexAstReturnStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstBreakStmt
HexStmtCodeGenerationVisitor::visit(HexAstBreakStmt stmt_)
{
  HexAstBreakStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstContinueStmt
HexStmtCodeGenerationVisitor::visit(HexAstContinueStmt stmt_)
{
  HexAstContinueStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstRaiseStmt
HexStmtCodeGenerationVisitor::visit(HexAstRaiseStmt stmt_)
{
  HexAstRaiseStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstExprListStmt
HexStmtCodeGenerationVisitor::visit(HexAstExprListStmt stmt_)
{
  HexAstExprListStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstSimpleIfStmt
HexStmtCodeGenerationVisitor::visit(HexAstSimpleIfStmt stmt_)
{
  HexAstSimpleIfStmt stmt = AstVisitor::visit(stmt_);
  // TODO: to be implemented...
  return stmt;
}

HexAstStmtGroup
HexStmtCodeGenerationVisitor::visit(HexAstStmtGroup stmts_)
{
  HexAstStmtGroup stmts = AstVisitor::visit(stmts_);
  // TODO: to be implemented...
  return stmts;
}