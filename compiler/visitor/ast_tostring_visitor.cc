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

#include <algorithm>
#include "ast_tostring_helper.h"
#include "ast_tostring_visitor.h"
#include "../ast2/ast.h"
#include "../../base/assert.h"

AstToStringVisitor::AstToStringVisitor()
  :AstToStringHelper()
{
  // Do nothing here.
}

AstToStringVisitor::~AstToStringVisitor()
{
  // Do nothing here.
}

void
AstToStringVisitor::open_brace()
{
  this->append(" {\n");
  this->indent();
}

void
AstToStringVisitor::close_brace()
{
  this->dedent();
  this->newline();
  this->indentation();
  this->append("}");
}

template<class T>
void
AstToStringVisitor::iterate(
  std::list<T>* list, const c_str delimiter, bool breakOnLast, bool printIndentation)
{
  typename std::list<T>::iterator itr;
  for(itr=list->begin(); itr != list->end();) {
    if(printIndentation) this->indentation();
    ((T)(*itr))->accept(this);
    if(++itr == list->end() && breakOnLast) break;
    this->append(delimiter);
  }
}

HexAstIdentifier
AstToStringVisitor::visit(HexAstIdentifier identifier_)
{
  HexAstIdentifier identifier = AstVisitor::visit(identifier_);
  this->append(identifier->value());
  return identifier;
}

HexAstDecimalIntegerLiteral
AstToStringVisitor::visit(HexAstDecimalIntegerLiteral literal_)
{
  HexAstDecimalIntegerLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstBinaryIntegerLiteral
AstToStringVisitor::visit(HexAstBinaryIntegerLiteral literal_)
{
  HexAstBinaryIntegerLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstOctalIntegerLiteral
AstToStringVisitor::visit(HexAstOctalIntegerLiteral literal_)
{
  HexAstOctalIntegerLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstHexadecimalIntegerLiteral
AstToStringVisitor::visit(HexAstHexadecimalIntegerLiteral literal_)
{
  HexAstHexadecimalIntegerLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstFloatLiteral
AstToStringVisitor::visit(HexAstFloatLiteral literal_)
{
  HexAstFloatLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstSingleQuoteStringLiteral
AstToStringVisitor::visit(HexAstSingleQuoteStringLiteral literal_)
{
  HexAstSingleQuoteStringLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstDoubleQuoteStringLiteral
AstToStringVisitor::visit(HexAstDoubleQuoteStringLiteral literal_)
{
  HexAstDoubleQuoteStringLiteral literal = AstVisitor::visit(literal_);
  this->append(literal->value());
  return literal;
}

HexAstCall
AstToStringVisitor::visit(HexAstCall call_)
{
  HexAstCall call = AstVisitor::visit(call_);

  call->caller()->accept(this);
  this->append("(");
  if(call->arglist()) {
    call->arglist()->accept(this);
  }
  this->append(")");

  return call;
}

HexAstAttributeRef
AstToStringVisitor::visit(HexAstAttributeRef ref_)
{
  HexAstAttributeRef ref = AstVisitor::visit(ref_);

  ref->source()->accept(this);
  this->append(".");
  ref->attribute()->accept(this);

  return ref;
}

HexAstSlicing
AstToStringVisitor::visit(HexAstSlicing slicing_)
{
  HexAstSlicing slicing = AstVisitor::visit(slicing_);

  slicing->source()->accept(this);
  this->append("[");

  switch(slicing->type()) {
    case AST_SLICING_TYPE_1:
      {
        slicing->start()->accept(this);
        this->append(":");
        slicing->step()->accept(this);
        this->append(":");
        slicing->stop()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_2:
      {
        slicing->start()->accept(this);
        this->append(":");
        slicing->step()->accept(this);
        this->append(":");
      }
      break;
    case AST_SLICING_TYPE_3:
      {
        slicing->start()->accept(this);
        this->append(":");
        slicing->step()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_4:
      {
        slicing->start()->accept(this);
        this->append(":");
        this->append(":");
        slicing->stop()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_5:
      {
        slicing->start()->accept(this);
        this->append(":");
        this->append(":");
      }
      break;
    case AST_SLICING_TYPE_6:
      {
        this->append(":");
        slicing->step()->accept(this);
        this->append(":");
        slicing->stop()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_7:
      {
        this->append(":");
        slicing->step()->accept(this);
        this->append(":");
      }
      break;
    case AST_SLICING_TYPE_8:
      {
        this->append(":");
        this->append(":");
        slicing->stop()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_9:
      {
        this->append(":");
        this->append(":");
      }
      break;
    case AST_SLICING_TYPE_A:
      {
        this->append(":");
      }
      break;
    case AST_SLICING_TYPE_B:
      {
        this->append(":");
        slicing->stop()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_C:
      {
        slicing->start()->accept(this);
      }
      break;
    case AST_SLICING_TYPE_D:
      {
        slicing->start()->accept(this);
        this->append(":");
      }
      break;
    default:
      break;
  }

  this->append("]");

  return slicing;
}

HexAstTargetList
AstToStringVisitor::visit(HexAstTargetList targets_)
{
  HexAstTargetList targets = AstVisitor::visit(targets_);

  this->iterate<HexAstIdentifier>(
    targets->list(),
    this->_commaDelimiter
  );

  return targets;
}

HexAstName
AstToStringVisitor::visit(HexAstName name_)
{
  HexAstName name = AstVisitor::visit(name_);

  this->iterate<HexAstIdentifier>(
    name->list(),
    this->_dotDelimiter
  );

  return name;
}

HexAstNameList
AstToStringVisitor::visit(HexAstNameList names_)
{
  HexAstNameList names = AstVisitor::visit(names_);

  this->iterate<HexAstName>(
    names->list(),
    this->_commaDelimiter
  );

  return names;
}

HexAstPositiveExpr
AstToStringVisitor::visit(HexAstPositiveExpr expr_)
{
  HexAstPositiveExpr expr = AstVisitor::visit(expr_);

  this->append("+");
  expr->expr()->accept(this);

  return expr;
}

HexAstNegativeExpr
AstToStringVisitor::visit(HexAstNegativeExpr expr_)
{
  HexAstNegativeExpr expr = AstVisitor::visit(expr_);

  this->append("-");
  expr->expr()->accept(this);

  return expr;
}

HexAstNotExpr
AstToStringVisitor::visit(HexAstNotExpr expr_)
{
  HexAstNotExpr expr = AstVisitor::visit(expr_);

  this->append("not ");
  expr->expr()->accept(this);

  return expr;
}

HexAstBitwiseNotExpr
AstToStringVisitor::visit(HexAstBitwiseNotExpr expr_)
{
  HexAstBitwiseNotExpr expr = AstVisitor::visit(expr_);

  this->append("~");
  expr->expr()->accept(this);

  return expr;
}

HexAstIncrementExpr
AstToStringVisitor::visit(HexAstIncrementExpr expr_)
{
  HexAstIncrementExpr expr = AstVisitor::visit(expr_);

  expr->expr()->accept(this);
  this->append("++");

  return expr;
}

HexAstDecrementExpr
AstToStringVisitor::visit(HexAstDecrementExpr expr_)
{
  HexAstDecrementExpr expr = AstVisitor::visit(expr_);

  expr->expr()->accept(this);
  this->append("--");

  return expr;
}

HexAstExistentialExpr
AstToStringVisitor::visit(HexAstExistentialExpr expr_)
{
  HexAstExistentialExpr expr = AstVisitor::visit(expr_);

  expr->expr()->accept(this);
  this->append("?");

  return expr;
}

HexAstAdditionExpr
AstToStringVisitor::visit(HexAstAdditionExpr expr_)
{
  HexAstAdditionExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" + ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstSubtractionExpr
AstToStringVisitor::visit(HexAstSubtractionExpr expr_)
{
  HexAstSubtractionExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" - ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstMultiplicationExpr
AstToStringVisitor::visit(HexAstMultiplicationExpr expr_)
{
  HexAstMultiplicationExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" * ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstDivisionExpr
AstToStringVisitor::visit(HexAstDivisionExpr expr_)
{
  HexAstDivisionExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" / ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstModulusExpr
AstToStringVisitor::visit(HexAstModulusExpr expr_)
{
  HexAstModulusExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" % ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstPowerExpr
AstToStringVisitor::visit(HexAstPowerExpr expr_)
{
  HexAstPowerExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" ** ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseANDExpr
AstToStringVisitor::visit(HexAstBitwiseANDExpr expr_)
{
  HexAstBitwiseANDExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" & ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseORExpr
AstToStringVisitor::visit(HexAstBitwiseORExpr expr_)
{
  HexAstBitwiseORExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" | ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseXORExpr
AstToStringVisitor::visit(HexAstBitwiseXORExpr expr_)
{
  HexAstBitwiseXORExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" ^ ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseLeftShiftExpr
AstToStringVisitor::visit(HexAstBitwiseLeftShiftExpr expr_)
{
  HexAstBitwiseLeftShiftExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" << ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseRightShiftExpr
AstToStringVisitor::visit(HexAstBitwiseRightShiftExpr expr_)
{
  HexAstBitwiseRightShiftExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" >> ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstEqualsExpr
AstToStringVisitor::visit(HexAstEqualsExpr expr_)
{
  HexAstEqualsExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" == ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstNotEqualExpr
AstToStringVisitor::visit(HexAstNotEqualExpr expr_)
{
  HexAstNotEqualExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" != ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstIsExpr
AstToStringVisitor::visit(HexAstIsExpr expr_)
{
  HexAstIsExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" is ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstIsNotExpr
AstToStringVisitor::visit(HexAstIsNotExpr expr_)
{
  HexAstIsNotExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" is not ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstLessThanExpr
AstToStringVisitor::visit(HexAstLessThanExpr expr_)
{
  HexAstLessThanExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" < ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstGreaterThanExpr
AstToStringVisitor::visit(HexAstGreaterThanExpr expr_)
{
  HexAstGreaterThanExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" > ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstGreaterOrEqualsExpr
AstToStringVisitor::visit(HexAstGreaterOrEqualsExpr expr_)
{
  HexAstGreaterOrEqualsExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" >= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstLessOrEqualsExpr
AstToStringVisitor::visit(HexAstLessOrEqualsExpr expr_)
{
  HexAstLessOrEqualsExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" <= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstInExpr
AstToStringVisitor::visit(HexAstInExpr expr_)
{
  HexAstInExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" in ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstNotInExpr
AstToStringVisitor::visit(HexAstNotInExpr expr_)
{
  HexAstNotInExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" not in ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstLogicalANDExpr
AstToStringVisitor::visit(HexAstLogicalANDExpr expr_)
{
  HexAstLogicalANDExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" and ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstLogicalORExpr
AstToStringVisitor::visit(HexAstLogicalORExpr expr_)
{
  HexAstLogicalORExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" or ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstInclusiveRangeExpr
AstToStringVisitor::visit(HexAstInclusiveRangeExpr expr_)
{
  HexAstInclusiveRangeExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append("...");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstExclusiveRangeExpr
AstToStringVisitor::visit(HexAstExclusiveRangeExpr expr_)
{
  HexAstExclusiveRangeExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append("..");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstConditionalExpr
AstToStringVisitor::visit(HexAstConditionalExpr expr_)
{
  HexAstConditionalExpr expr = AstVisitor::visit(expr_);

  this->append("if ");
  expr->predicate()->accept(this);
  this->append(" then ");
  expr->consequent()->accept(this);
  this->append(" else ");
  expr->alternate()->accept(this);

  return expr;
}

HexAstAdditionAssignmentExpr
AstToStringVisitor::visit(HexAstAdditionAssignmentExpr expr_)
{
  HexAstAdditionAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" += ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstSubtractionAssignmentExpr
AstToStringVisitor::visit(HexAstSubtractionAssignmentExpr expr_)
{
  HexAstSubtractionAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" -= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstMultiplicationAssignmentExpr
AstToStringVisitor::visit(HexAstMultiplicationAssignmentExpr expr_)
{
  HexAstMultiplicationAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" *= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstDivisionAssignmentExpr
AstToStringVisitor::visit(HexAstDivisionAssignmentExpr expr_)
{
  HexAstDivisionAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" /= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstModulusAssignmentExpr
AstToStringVisitor::visit(HexAstModulusAssignmentExpr expr_)
{
  HexAstModulusAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" %= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseANDAssignmentExpr
AstToStringVisitor::visit(HexAstBitwiseANDAssignmentExpr expr_)
{
  HexAstBitwiseANDAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" &= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseORAssignmentExpr
AstToStringVisitor::visit(HexAstBitwiseORAssignmentExpr expr_)
{
  HexAstBitwiseORAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" |= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseXORAssignmentExpr
AstToStringVisitor::visit(HexAstBitwiseXORAssignmentExpr expr_)
{
  HexAstBitwiseXORAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" ^= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseLeftShiftAssignmentExpr
AstToStringVisitor::visit(HexAstBitwiseLeftShiftAssignmentExpr expr_)
{
  HexAstBitwiseLeftShiftAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" <<= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstBitwiseRightShiftAssignmentExpr
AstToStringVisitor::visit(HexAstBitwiseRightShiftAssignmentExpr expr_)
{
  HexAstBitwiseRightShiftAssignmentExpr expr = AstVisitor::visit(expr_);

  expr->lexpr()->accept(this);
  this->append(" >>= ");
  expr->rexpr()->accept(this);

  return expr;
}

HexAstYieldExpr
AstToStringVisitor::visit(HexAstYieldExpr expr_)
{
  HexAstYieldExpr expr = AstVisitor::visit(expr_);

  this->append("yield");
  if(expr->exprs()) {
    this->append(" (");
    expr->exprs()->accept(this);
    this->append(")");
  }

  return expr;
}

HexAstStringCompositionExpr
AstToStringVisitor::visit(HexAstStringCompositionExpr expr_)
{
  HexAstStringCompositionExpr expr = AstVisitor::visit(expr_);

  expr->string()->accept(this);
  this->append(" %% ");
  expr->paren()->accept(this);

  return expr;
}

HexAstNestedComprehension
AstToStringVisitor::visit(HexAstNestedComprehension comprehension_)
{
  HexAstNestedComprehension comprehension = AstVisitor::visit(comprehension_);

  comprehension->nested_comprehension()->accept(this);
  this->append(" for ");
  comprehension->targets()->accept(this);
  this->append(" in ");
  comprehension->sources()->accept(this);

  if(comprehension->predicate()) {
    this->append(" if ");
    comprehension->predicate()->accept(this);
  }

  return comprehension;
}

HexAstExprComprehension
AstToStringVisitor::visit(HexAstExprComprehension comprehension_)
{
  HexAstExprComprehension comprehension = AstVisitor::visit(comprehension_);

  comprehension->exprs()->accept(this);
  this->append(" for ");
  comprehension->targets()->accept(this);
  this->append(" in ");
  comprehension->sources()->accept(this);

  if(comprehension->predicate()) {
    this->append(" if ");
    comprehension->predicate()->accept(this);
  }

  return comprehension;
}

HexAstGeneratorExpr
AstToStringVisitor::visit(HexAstGeneratorExpr expr_)
{
  HexAstGeneratorExpr expr = AstVisitor::visit(expr_);

  this->append("(");
  expr->comprehension()->accept(this);
  this->append(")");

  return expr;
}

HexAstParenForm
AstToStringVisitor::visit(HexAstParenForm form_)
{
  HexAstParenForm form = AstVisitor::visit(form_);

  this->append("(");
  if(form->exprs()) {
    form->exprs()->accept(this);
  }
  this->append(")");

  return form; 
}

HexAstExplicitListForm
AstToStringVisitor::visit(HexAstExplicitListForm list_)
{
  HexAstExplicitListForm list = AstVisitor::visit(list_);

  this->append("[");
  if(list->elements()) {
    list->elements()->accept(this);
  }
  this->append("]");

  return list;
}

HexAstImplicitListForm
AstToStringVisitor::visit(HexAstImplicitListForm list_)
{
  HexAstImplicitListForm list = AstVisitor::visit(list_);

  this->append("[");
  list->comprehension()->accept(this);
  this->append("]");

  return list;
}

HexAstExplicitDictForm
AstToStringVisitor::visit(HexAstExplicitDictForm dict_)
{
  HexAstExplicitDictForm dict = AstVisitor::visit(dict_);

  this->append("{");
  if(dict->fields()) {
    dict->fields()->accept(this);
  }
  this->append("}");

  return dict;
}

HexAstImplicitDictForm
AstToStringVisitor::visit(HexAstImplicitDictForm dict_)
{
  HexAstImplicitDictForm dict = AstVisitor::visit(dict_);

  this->append("{");
  dict->comprehension()->accept(this);
  this->append("}");

  return dict;
}

HexAstObjectForm
AstToStringVisitor::visit(HexAstObjectForm object_)
{
  HexAstObjectForm object = AstVisitor::visit(object_);

  this->append("{");
  object->fields()->accept(this);
  this->append("}");

  return object;
}

HexAstExprList
AstToStringVisitor::visit(HexAstExprList exprs_)
{
  HexAstExprList exprs = AstVisitor::visit(exprs_);

  this->iterate<HexAstExpr>(
    exprs->list(),
    this->_commaDelimiter
  );

  return exprs;
}

HexAstSimpleParam
AstToStringVisitor::visit(HexAstSimpleParam param_)
{
  HexAstSimpleParam param = AstVisitor::visit(param_);

  if(param->type()) {
    this->append("@");
    param->type()->accept(this);
    this->append(" ");
  }
  param->name()->accept(this);

  return param;
}

HexAstSimpleParamList
AstToStringVisitor::visit(HexAstSimpleParamList params_)
{
  HexAstSimpleParamList params = AstVisitor::visit(params_);

  this->iterate<HexAstSimpleParam>(
    params->list(),
    this->_commaDelimiter
  );

  return params;
}

HexAstKeywordParam
AstToStringVisitor::visit(HexAstKeywordParam param_)
{
  HexAstKeywordParam param = AstVisitor::visit(param_);

  if(param->type()) {
    this->append("@");
    param->type()->accept(this);
    this->append(" ");
  }
  param->name()->accept(this);
  this->append("=");
  param->value()->accept(this);

  return param;
}

HexAstKeywordParamList
AstToStringVisitor::visit(HexAstKeywordParamList params_)
{
  HexAstKeywordParamList params = AstVisitor::visit(params_);

  this->iterate<HexAstKeywordParam>(
    params->list(),
    this->_commaDelimiter
  ); 

  return params;
}

HexAstParameterList
AstToStringVisitor::visit(HexAstParameterList params_)
{
  HexAstParameterList params = AstVisitor::visit(params_);

  bool prev = false;

  if(params->simple_params()) {
    params->simple_params()->accept(this);
    prev = true;
  }

  if(params->args()) {
    if(prev) this->append(", ");
    this->append("*");
    params->args()->accept(this);
    prev = true;
  }

  if(params->keyword_params()) {
    if(prev) this->append(", ");
    params->keyword_params()->accept(this); 
    prev = true;
  }

  if(params->kwargs()) {
    if(prev) this->append(", ");
    this->append("**");
    params->kwargs()->accept(this);
    prev = true;
  }

  return params;
}

HexAstSimpleArgList
AstToStringVisitor::visit(HexAstSimpleArgList args_)
{
  HexAstSimpleArgList args = AstVisitor::visit(args_);

  this->iterate<HexAstSimpleArg>(
    args->list(),
    this->_commaDelimiter
  );

  return args;
}

HexAstKeywordArg
AstToStringVisitor::visit(HexAstKeywordArg arg_)
{
  HexAstKeywordArg arg = AstVisitor::visit(arg_);

  arg->name()->accept(this);
  this->append("=");
  arg->value()->accept(this);

  return arg;
}

HexAstKeywordArgList
AstToStringVisitor::visit(HexAstKeywordArgList args_)
{
  HexAstKeywordArgList args = AstVisitor::visit(args_);

  this->iterate<HexAstKeywordArg>(
    args->list(),
    this->_commaDelimiter
  );

  return args;
}

HexAstArgList
AstToStringVisitor::visit(HexAstArgList arglist_)
{
  HexAstArgList arglist = AstVisitor::visit(arglist_);

  bool prev = false;

  if(arglist->simple_args()) {
    arglist->simple_args()->accept(this);
    prev = true;
  }

  if(arglist->args()) {
    if(prev) this->append(", ");
    this->append("*");
    arglist->args()->accept(this);
    prev = true;
  }

  if(arglist->keyword_args()) {
    if(prev) this->append(", ");
    arglist->keyword_args()->accept(this);
    prev = true;
  }

  if(arglist->kwargs()) {
    if(prev) this->append(", ");
    this->append("**");
    arglist->kwargs()->accept(this);
    prev = true;
  }

  return arglist;
}

HexAstFieldDef
AstToStringVisitor::visit(HexAstFieldDef field_)
{
  HexAstFieldDef field = AstVisitor::visit(field_);

  if(field->decorators()) {
    this->indent();
    field->decorators()->accept(this);
    this->dedent();
  }

  this->indent();
  this->indentation();
  field->name()->accept(this);
  this->append(": ");
  field->value()->accept(this);
  this->dedent();

  return field;
}

HexAstFieldDefList
AstToStringVisitor::visit(HexAstFieldDefList fields_)
{
  HexAstFieldDefList fields = AstVisitor::visit(fields_);

  this->iterate<HexAstFieldDef>(
    fields->list(),
    this->_doubleNewlineDelimiter,
    true,
    false
  );

  return fields;
}

HexAstKeyValuePair
AstToStringVisitor::visit(HexAstKeyValuePair pair_)
{
  HexAstKeyValuePair pair = AstVisitor::visit(pair_);

  pair->key()->accept(this);
  this->append(": ");
  pair->value()->accept(this);

  return pair;
}

HexAstKeyValuePairList
AstToStringVisitor::visit(HexAstKeyValuePairList pairs_)
{
  HexAstKeyValuePairList pairs = AstVisitor::visit(pairs_);

  this->iterate<HexAstKeyValuePair>(
    pairs->list(),
    this->_commaDelimiter
  );

  return pairs;
}

HexAstAttributeValuePair
AstToStringVisitor::visit(HexAstAttributeValuePair pair_)
{
  HexAstAttributeValuePair pair = AstVisitor::visit(pair_);

  this->append(".");
  pair->attribute()->accept(this);
  this->append("=");
  pair->value()->accept(this);

  return pair;
}

HexAstAttributeValuePairList
AstToStringVisitor::visit(HexAstAttributeValuePairList pairs_)
{
  HexAstAttributeValuePairList pairs = AstVisitor::visit(pairs_);

  this->iterate<HexAstAttributeValuePair>(
    pairs->list(),
    this->_commaDelimiter
  );

  return pairs;
}

HexAstDecorator
AstToStringVisitor::visit(HexAstDecorator decorator_)
{
  HexAstDecorator decorator = AstVisitor::visit(decorator_);

  this->append("@");
  decorator->name()->accept(this);

  if(decorator->args()) {
    this->append("(");
    decorator->args()->accept(this);
    this->append(")");
  }

  return decorator;
}

HexAstDecoratorList
AstToStringVisitor::visit(HexAstDecoratorList decorators_)
{
  HexAstDecoratorList decorators = AstVisitor::visit(decorators_);

  this->iterate<HexAstDecorator>(
    decorators->list(),
    this->_newlineDelimiter,
    false,
    true
  );

  return decorators;
}

HexAstAssignmentFeature
AstToStringVisitor::visit(HexAstAssignmentFeature feature_)
{
  HexAstAssignmentFeature feature = AstVisitor::visit(feature_);

  switch(feature->feature())
  {
    case HEX_AST_ASSIGNMENT_FEATURE_DEFER:
      {
        this->append("defer ");
      }
      break;
    default:
      break;
  }

  return feature;
}

HexAstAssignmentStmt
AstToStringVisitor::visit(HexAstAssignmentStmt stmt_)
{
  HexAstAssignmentStmt stmt = AstVisitor::visit(stmt_);

  stmt->target()->accept(this);
  this->append(" = ");
  stmt->feature()->accept(this);
  stmt->source()->accept(this);
  this->append(";");

  return stmt;
}

HexAstUsingSrc
AstToStringVisitor::visit(HexAstUsingSrc src_)
{
  HexAstUsingSrc src = AstVisitor::visit(src_);

  size_t level = src->level();
  HexAstName name = src->name();

  for(int i = 0; i < level; i++) {
    this->append(".");
  }

  if(src->name()) {
    src->name()->accept(this);
  }

  return src;
}

HexAstRelativeUsingStmt
AstToStringVisitor::visit(HexAstRelativeUsingStmt stmt_)
{
  HexAstRelativeUsingStmt stmt = AstVisitor::visit(stmt_);

  this->append("using ");

  if(stmt->targets()) {
    stmt->targets()->accept(this);
  } else {
    this->append("*");
  }

  this->append(" in ");
  stmt->source()->accept(this);

  if(stmt->alias()) {
    this->append(" as ");
    stmt->alias()->accept(this);
  }

  this->append(";");

  return stmt;
}

HexAstAbsoluteUsingStmt
AstToStringVisitor::visit(HexAstAbsoluteUsingStmt stmt_)
{
  HexAstAbsoluteUsingStmt stmt = AstVisitor::visit(stmt_);

  this->append("using ");
  stmt->source()->accept(this);

  if(stmt->alias()) {
    this->append(" as ");
    stmt->alias()->accept(this);
  }

  this->append(";");

  return stmt;
}

HexAstElifStmt
AstToStringVisitor::visit(HexAstElifStmt stmt_)
{
  HexAstElifStmt stmt = AstVisitor::visit(stmt_);

  this->append(" elif ");
  stmt->predicate()->accept(this);
  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  return stmt;
}

HexAstElifStmtGroup
AstToStringVisitor::visit(HexAstElifStmtGroup stmts_)
{
  HexAstElifStmtGroup stmts = AstVisitor::visit(stmts_);

  this->iterate<HexAstElifStmt>(
    stmts->list(),
    this->_nullDelimiter
  );

  return stmts;
}

HexAstIfStmt
AstToStringVisitor::visit(HexAstIfStmt stmt_)
{
  HexAstIfStmt stmt = AstVisitor::visit(stmt_);

  this->append("if");

  if(stmt->predicate()) {
    this->append(" ");
    stmt->predicate()->accept(this);
  }

  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  if(stmt->elif_stmts()) {
    stmt->elif_stmts()->accept(this);
  }

  if(stmt->else_stmts()) {
    this->append(" else");
    this->open_brace();
    stmt->else_stmts()->accept(this);
    this->close_brace();
  }

  return stmt;
}

HexAstForStmt
AstToStringVisitor::visit(HexAstForStmt stmt_)
{
  HexAstForStmt stmt = AstVisitor::visit(stmt_);

  this->append("for ");
  stmt->targets()->accept(this);
  this->append(" in ");
  stmt->sources()->accept(this);

  if(stmt->predicate()) {
    this->append(" if ");
    stmt->predicate()->accept(this);
  }

  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  return stmt;
}

HexAstWithStmt
AstToStringVisitor::visit(HexAstWithStmt stmt_)
{
  HexAstWithStmt stmt = AstVisitor::visit(stmt_);

  this->append("with ");
  stmt->expr()->accept(this);

  if(stmt->alias()) {
    this->append(" as ");
    stmt->alias()->accept(this);
  }

  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  return stmt;
}

HexAstLockStmt
AstToStringVisitor::visit(HexAstLockStmt stmt_)
{
  HexAstLockStmt stmt = AstVisitor::visit(stmt_);

  this->append("lock ");
  stmt->target()->accept(this);
  this->append(" {\n");
  this->indent();
  stmt->stmts()->accept(this);
  this->dedent();
  this->indentation();
  this->append("\n}");

  return stmt;
}

HexAstWhileStmt
AstToStringVisitor::visit(HexAstWhileStmt stmt_)
{
  HexAstWhileStmt stmt = AstVisitor::visit(stmt_);

  this->append("while ");
  stmt->predicate()->accept(this);
  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  return stmt;
}

HexAstCatchStmt
AstToStringVisitor::visit(HexAstCatchStmt stmt_)
{
  HexAstCatchStmt stmt = AstVisitor::visit(stmt_);

  this->append(" catch");
  if(stmt->types()) {
    this->append(" ");
    stmt->types()->accept(this);
    if(stmt->alias()) {
      this->append(" as ");
      stmt->alias()->accept(this);
    }
  }

  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  return stmt;
}

HexAstCatchStmtGroup
AstToStringVisitor::visit(HexAstCatchStmtGroup stmts_)
{
  HexAstCatchStmtGroup stmts = AstVisitor::visit(stmts_);

  this->iterate<HexAstCatchStmt>(
    stmts->list(),
    this->_nullDelimiter
  );

  return stmts;
}

HexAstTryStmt
AstToStringVisitor::visit(HexAstTryStmt stmt_)
{
  HexAstTryStmt stmt = AstVisitor::visit(stmt_);

  this->append("try");
  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();
  stmt->catch_stmt_group()->accept(this);

  return stmt;
}

HexAstClassDef
AstToStringVisitor::visit(HexAstClassDef def_)
{
  HexAstClassDef def = AstVisitor::visit(def_);

  if(def->decorators()) {
    def->decorators()->accept(this);
  }
  this->append("class ");
  def->name()->accept(this);

  if(def->parents()) {
    this->append(" extends ");
    def->parents()->accept(this);
  }

  if(def->attributes()) {
    this->open_brace();
    this->dedent();
    this->newline();
    def->attributes()->accept(this);
    this->indent();
    this->close_brace();
  } else {
    this->append(";");
  }

  return def;
}

HexAstSimpleLambda
AstToStringVisitor::visit(HexAstSimpleLambda lambda_)
{
  HexAstSimpleLambda lambda = AstVisitor::visit(lambda_);

  this->append("lambda (");
  if(lambda->params()) {
    lambda->params()->accept(this);
  }
  this->append(") -> ");
  lambda->expr()->accept(this);

  return lambda;
}

HexAstComplexLambda
AstToStringVisitor::visit(HexAstComplexLambda lambda_)
{
  HexAstComplexLambda lambda = AstVisitor::visit(lambda_);

  this->append("lambda (");
  if(lambda->params()) {
    lambda->params()->accept(this);
  }

  this->append(") =>");
  this->open_brace();
  lambda->stmts()->accept(this);
  this->close_brace();

  return lambda;
}

HexAstInputStmt
AstToStringVisitor::visit(HexAstInputStmt stmt_)
{
  HexAstInputStmt stmt = AstVisitor::visit(stmt_);

  this->iterate<HexAstPrimary>(
    stmt->list(),
    this->_inputDelimiter
  );

  this->append(";");

  return stmt;
}

HexAstOutputStmt
AstToStringVisitor::visit(HexAstOutputStmt stmt_)
{
  HexAstOutputStmt stmt = AstVisitor::visit(stmt_);

  this->iterate<HexAstPrimary>(
    stmt->list(),
    this->_outputDelimiter
  );

  this->append(";");

  return stmt;
}

HexAstTaskState
AstToStringVisitor::visit(HexAstTaskState state_)
{
  HexAstTaskState state = AstVisitor::visit(state_);

  char* s = NULL;

  switch(state->state()) {
    case AST_TASK_STATE_START:
      s = "start";
      break;
    case AST_TASK_STATE_PAUSE:
      s = "pause";
      break;
    case AST_TASK_STATE_CANCEL:
      s = "cancel";
      break;
    case AST_TASK_STATE_RESUME:
      s = "resume";
      break;
    case AST_TASK_STATE_FINISH:
      s = "finish";
      break;
    default:
      break;
  }

  HEX_ASSERT(s);
  this->append(s);

  return state;
}

HexAstConditionalPreposition
AstToStringVisitor::visit(HexAstConditionalPreposition preposition_)
{
  HexAstConditionalPreposition preposition = AstVisitor::visit(preposition_);

  char* s = NULL;

  switch(preposition->preposition()) {
    case AST_TASK_CONDITIONAL_PREPOSITION_BEFORE:
      s = "before";
      break;
    case AST_TASK_CONDITIONAL_PREPOSITION_AFTER:
      s = "after";
      break;
    default:
      break;
  }

  HEX_ASSERT(s);
  this->append(s);

  return preposition;
}

HexAstConditionalClause
AstToStringVisitor::visit(HexAstConditionalClause clause_)
{
  HexAstConditionalClause clause = AstVisitor::visit(clause_);

  clause->preposition()->accept(this);
  this->append(" ");
  clause->exprs()->accept(this);
  this->append(" ");
  clause->state()->accept(this);

  return clause;
}

HexAstStartClause
AstToStringVisitor::visit(HexAstStartClause clause_)
{
  HexAstStartClause clause = AstVisitor::visit(clause_);

  this->append("start ");
  clause->tasks()->accept(this);
  this->append(" as ");
  clause->alias()->accept(this);

  if(clause->condition_clause()) {
    this->append(" ");
    clause->condition_clause()->accept(this);
  }

  return clause;
}

HexAstPauseClause
AstToStringVisitor::visit(HexAstPauseClause clause_)
{
  HexAstPauseClause clause = AstVisitor::visit(clause_);

  this->append("pause ");
  clause->tasks()->accept(this);
  this->append(" ");
  clause->condition_clause()->accept(this);

  return clause;
}

HexAstResumeClause
AstToStringVisitor::visit(HexAstResumeClause clause_)
{
  HexAstResumeClause clause = AstVisitor::visit(clause_);

  this->append("resume ");
  clause->tasks()->accept(this);
  this->append(" ");
  clause->condition_clause()->accept(this);

  return clause;
}

HexAstCancelClause
AstToStringVisitor::visit(HexAstCancelClause clause_)
{
  HexAstCancelClause clause = AstVisitor::visit(clause_);

  this->append("cancel ");
  clause->tasks()->accept(this);
  this->append(" ");
  clause->condition_clause()->accept(this);

  return clause;
}

HexAstStopClause
AstToStringVisitor::visit(HexAstStopClause clause_)
{
  HexAstStopClause clause = AstVisitor::visit(clause_);

  this->append("stop ");
  clause->tasks()->accept(this);
  this->append(" ");
  clause->condition_clause()->accept(this);

  return clause;
}

HexAstTaskDef
AstToStringVisitor::visit(HexAstTaskDef def_)
{
  HexAstTaskDef def = AstVisitor::visit(def_);

  this->newline();
  this->indent();
  this->iterate<HexAstTaskClause>(
    def->list(),
    this->_commaNewlineDelimiter,
    true,
    true
  );
  this->dedent();

  return def;
}

HexAstAwaitStmt
AstToStringVisitor::visit(HexAstAwaitStmt stmt_)
{
  HexAstAwaitStmt stmt = AstVisitor::visit(stmt_);

  this->append("await");
  this->open_brace();
  stmt->stmts()->accept(this);
  this->close_brace();

  return stmt;
}

HexAstReturnStmt
AstToStringVisitor::visit(HexAstReturnStmt stmt_)
{
  HexAstReturnStmt stmt = AstVisitor::visit(stmt_);

  this->append("return");
  if(stmt->return_vals()) {
    this->append(" ");
    stmt->return_vals()->accept(this);
  }
  this->append(";");

  return stmt;
}

HexAstBreakStmt
AstToStringVisitor::visit(HexAstBreakStmt stmt_)
{
  HexAstBreakStmt stmt = AstVisitor::visit(stmt_);

  this->append("break;");

  return stmt;
}

HexAstContinueStmt
AstToStringVisitor::visit(HexAstContinueStmt stmt_)
{
  HexAstContinueStmt stmt = AstVisitor::visit(stmt_);

  this->append("continue;");

  return stmt;
}

HexAstRaiseStmt
AstToStringVisitor::visit(HexAstRaiseStmt stmt_)
{
  HexAstRaiseStmt stmt = AstVisitor::visit(stmt_);

  this->append("raise ");
  stmt->target()->accept(this);
  this->append(";");

  return stmt;
}

HexAstExprListStmt
AstToStringVisitor::visit(HexAstExprListStmt stmt_)
{
  HexAstExprListStmt stmt = AstVisitor::visit(stmt_);

  stmt->exprs()->accept(this);
  this->append(";");

  return stmt;
}

HexAstSimpleIfStmt
AstToStringVisitor::visit(HexAstSimpleIfStmt stmt_)
{
  HexAstSimpleIfStmt stmt = AstVisitor::visit(stmt_);

  this->append("if ");
  stmt->predicate()->accept(this);
  this->append(": ");
  stmt->stmt()->accept(this);

  return stmt;
}

HexAstStmtGroup
AstToStringVisitor::visit(HexAstStmtGroup stmts_)
{
  HexAstStmtGroup stmts = AstVisitor::visit(stmts_);

  this->iterate<HexAstStmt>(
    stmts->list(),
    this->_newlineDelimiter,
    true,
    true
  );

  return stmts;
}

HexAstHexProgram
AstToStringVisitor::visit(HexAstHexProgram program_)
{
  HexAstHexProgram program = AstVisitor::visit(program_);

  if(program->stmts()) {
    program->stmts()->accept(this);
  }

  return program;
}