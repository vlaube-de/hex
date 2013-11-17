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
#include <string>
#include "../ast.h"
#include "ast_to_xml_visitor.h"
#include "../../../base/assert.h"
#include "../../../base/memory.h"


AstToXmlVisitor::AstToXmlVisitor()
  :_strbuf(new std::string())
{
  HEX_ASSERT(_strbuf);
}

AstToXmlVisitor::~AstToXmlVisitor()
{
  HEX_DELETE(_strbuf);
}

const c_str
AstToXmlVisitor::str()
{
  c_str str = strdup(_strbuf->c_str());
  HEX_ASSERT(str);
  return (const c_str)str;
}

void
AstToXmlVisitor::append(const c_str s)
{
  HEX_ASSERT(s);
  this->_strbuf->append(s);
}

void
AstToXmlVisitor::begin_tag(const c_str tag)
{
  std::string str;
  str.append("<");
  str.append(tag);
  str.append(">");

  this->append((const c_str)str.c_str());
}

void
AstToXmlVisitor::end_tag(const c_str tag)
{
  std::string str;
  str.append("<");
  str.append(tag);
  str.append("/>");

  this->append((const c_str)str.c_str());
}

void
AstToXmlVisitor::double_tag(const c_str tag, c_str value)
{
  this->begin_tag(tag);
  this->append(value);
  this->end_tag(tag);
}

template<class Function>
void
AstToXmlVisitor::double_tag(const c_str tag, Function f)
{
  this->begin_tag(tag);
  f();
  this->end_tag(tag);
}

template<class T, class Function>
void
AstToXmlVisitor::iterate(std::list<T>* list, Function f, bool breakOnLast)
{
  typename std::list<T>::iterator itr;
  for(itr=list->begin(); itr != list->end();) {
    f((T)(*itr));
    if(++itr == list->end() && breakOnLast) break;
  }
}

template<class T>
void
AstToXmlVisitor::double_tag_for_binary_expr(T expr, const c_str tag_)
{
  std::string tag_left(tag_);
  std::string tag_right(tag_);

  this->double_tag(
    tag_,
    [this, expr, &tag_left, &tag_right]() {
      this->double_tag(
        (const c_str)tag_left.append("-left").c_str(),
        [this, expr]() {
          expr->left()->accept(this);
        }
      );

      this->double_tag(
        (const c_str)tag_right.append("-right").c_str(),
        [this, expr]() {
          expr->right()->accept(this);
        }
      );
    }
  );
}

HexAstIdentifier
AstToXmlVisitor::visit(HexAstIdentifier identifier_)
{
  HexAstIdentifier identifier = AstVisitor::visit(identifier_);

	this->double_tag("identifier", identifier->value());

  return identifier;
}

HexAstIntegerLiteral
AstToXmlVisitor::visit(HexAstIntegerLiteral literal_)
{
  HexAstIntegerLiteral literal = AstVisitor::visit(literal_);

  this->double_tag("integer_literal", literal->value());

  return literal;
}

HexAstFloatLiteral
AstToXmlVisitor::visit(HexAstFloatLiteral literal_)
{
  HexAstFloatLiteral literal = AstVisitor::visit(literal_);

  this->double_tag("floating_literal", literal->value());

  return literal;
}

HexAstStringLiteral
AstToXmlVisitor::visit(HexAstStringLiteral literal_)
{
  HexAstStringLiteral literal = AstVisitor::visit(literal_);

  this->double_tag("string_literal", literal->value());

  return literal;
}

HexAstCall
AstToXmlVisitor::visit(HexAstCall call_)
{
  HexAstCall call = AstVisitor::visit(call_);

  this->double_tag(
    "call",
    [this, call]() {
      this->double_tag(
        "call-source",
        [this, call]() {
          call->source()->accept(this);
        }
      );

      if(call->arglist()) {
        this->double_tag(
          "call-args",
          [this, call]() {
            call->arglist()->accept(this);
          }
        );
      }

    }
  );

  return call;
}

HexAstAttributeRef
AstToXmlVisitor::visit(HexAstAttributeRef ref_)
{
  HexAstAttributeRef ref = AstVisitor::visit(ref_);

  this->double_tag(
    "attribute",
    [this, ref]() {
      this->double_tag(
        "attribute-source",
        [this, ref]() {
          ref->source()->accept(this);
        }
      );

      this->double_tag(
        "attribute-target",
        [this, ref]() {
          ref->attribute()->accept(this);
        }
      );
    }
  );

  return ref;
}

HexAstSlicing
AstToXmlVisitor::visit(HexAstSlicing slicing_)
{
  HexAstSlicing slicing = AstVisitor::visit(slicing_);

  this->double_tag(
    "slicing",
    [this, slicing]() {
      this->double_tag(
        "slicing-source",
        [this, slicing]() {
          slicing->source()->accept(this);
        }
      );

      this->double_tag(
        "slicing-target",
        [this, slicing]() {
          slicing->slice()->accept(this);
        }
      );
    }
  );

  return slicing;
}

HexAstTargetList
AstToXmlVisitor::visit(HexAstTargetList targets_)
{
  HexAstTargetList targets = AstVisitor::visit(targets_);

  this->double_tag(
    "target_list",
    [this, targets]() {
      this->iterate<HexAstIdentifier>(
        targets->list(),
        [this](HexAstIdentifier identifier) {
          identifier->accept(this);
        }
      );
    }
  );

  return targets;
}

HexAstName
AstToXmlVisitor::visit(HexAstName name_)
{
  HexAstName name = AstVisitor::visit(name_);

  this->double_tag(
    "name",
    [this, name]() {
      this->iterate<HexAstIdentifier>(
        name->list(),
        [this](HexAstIdentifier identifier) {
          identifier->accept(this);
        }
      );
    }
  );

  return name;
}

HexAstPositiveExpr
AstToXmlVisitor::visit(HexAstPositiveExpr expr_)
{
  HexAstPositiveExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "positive_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstNegativeExpr
AstToXmlVisitor::visit(HexAstNegativeExpr expr_)
{
  HexAstNegativeExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "negative_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstNotExpr
AstToXmlVisitor::visit(HexAstNotExpr expr_)
{
  HexAstNotExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "not_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstBitwiseNotExpr
AstToXmlVisitor::visit(HexAstBitwiseNotExpr expr_)
{
  HexAstBitwiseNotExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "bitwise_not_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstIncrementExpr
AstToXmlVisitor::visit(HexAstIncrementExpr expr_)
{
  HexAstIncrementExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "increment_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstDecrementExpr
AstToXmlVisitor::visit(HexAstDecrementExpr expr_)
{
  HexAstDecrementExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "decrement_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstExistentialExpr
AstToXmlVisitor::visit(HexAstExistentialExpr expr_)
{
  HexAstExistentialExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "existential_expr",
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );

  return expr;
}

HexAstAddExpr
AstToXmlVisitor::visit(HexAstAddExpr expr_)
{
  HexAstAddExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstAddExpr>(expr, "add_expr");

  return expr;
}

HexAstMinusExpr
AstToXmlVisitor::visit(HexAstMinusExpr expr_)
{
  HexAstMinusExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstMinusExpr>(expr, "minus_expr");

  return expr;
}

HexAstMultiplyExpr
AstToXmlVisitor::visit(HexAstMultiplyExpr expr_)
{
  HexAstMultiplyExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstMultiplyExpr>(expr, "multiply_expr");

  return expr;
}

HexAstDivideExpr
AstToXmlVisitor::visit(HexAstDivideExpr expr_)
{
  HexAstDivideExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstDivideExpr>(expr, "divide_expr");

  return expr;
}

HexAstModulusExpr
AstToXmlVisitor::visit(HexAstModulusExpr expr_)
{
  HexAstModulusExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstModulusExpr>(expr, "modulus_expr");

  return expr;
}

HexAstPowerExpr
AstToXmlVisitor::visit(HexAstPowerExpr expr_)
{
  HexAstPowerExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPowerExpr>(expr, "power_expr");

  return expr;
}

HexAstBitwiseAndExpr
AstToXmlVisitor::visit(HexAstBitwiseAndExpr expr_)
{
  HexAstBitwiseAndExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseAndExpr>(expr, "bitwise_and_expr");

  return expr;
}

HexAstBitwiseOrExpr
AstToXmlVisitor::visit(HexAstBitwiseOrExpr expr_)
{
  HexAstBitwiseOrExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseOrExpr>(expr, "bitwise_or_expr");

  return expr;
}

HexAstBitwiseXorExpr
AstToXmlVisitor::visit(HexAstBitwiseXorExpr expr_)
{
  HexAstBitwiseXorExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseXorExpr>(expr, "bitwise_xor_expr");

  return expr;
}

HexAstBitwiseShiftLeftExpr
AstToXmlVisitor::visit(HexAstBitwiseShiftLeftExpr expr_)
{
  HexAstBitwiseShiftLeftExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseShiftLeftExpr>(expr, "bitwise_shift_left_expr");

  return expr;
}

HexAstBitwiseShiftRightExpr
AstToXmlVisitor::visit(HexAstBitwiseShiftRightExpr expr_)
{
  HexAstBitwiseShiftRightExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseShiftRightExpr>(expr, "bitwise_shift_right_expr");

  return expr;
}

HexAstEqualsExpr
AstToXmlVisitor::visit(HexAstEqualsExpr expr_)
{
  HexAstEqualsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstEqualsExpr>(expr, "equals_expr");

  return expr;
}

HexAstNotEqualExpr
AstToXmlVisitor::visit(HexAstNotEqualExpr expr_)
{
  HexAstNotEqualExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstNotEqualExpr>(expr, "not_equal_expr");

  return expr;
}

HexAstIsExpr
AstToXmlVisitor::visit(HexAstIsExpr expr_)
{
  HexAstIsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstIsExpr>(expr, "is_expr");

  return expr;
}

HexAstIsNotExpr
AstToXmlVisitor::visit(HexAstIsNotExpr expr_)
{
  HexAstIsNotExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstIsNotExpr>(expr, "is_not_expr");

  return expr;
}

HexAstLessThanExpr
AstToXmlVisitor::visit(HexAstLessThanExpr expr_)
{
  HexAstLessThanExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstLessThanExpr>(expr, "lt_expr");

  return expr;
}

HexAstGreaterThanExpr
AstToXmlVisitor::visit(HexAstGreaterThanExpr expr_)
{
  HexAstGreaterThanExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstGreaterThanExpr>(expr, "gt_expr");

  return expr;
}

HexAstGreaterOrEqualsExpr
AstToXmlVisitor::visit(HexAstGreaterOrEqualsExpr expr_)
{
  HexAstGreaterOrEqualsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstGreaterOrEqualsExpr>(expr, "ge_expr");

  return expr;
}

HexAstLessOrEqualsExpr
AstToXmlVisitor::visit(HexAstLessOrEqualsExpr expr_)
{
  HexAstLessOrEqualsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstLessOrEqualsExpr>(expr, "le_expr");

  return expr;
}

HexAstInExpr
AstToXmlVisitor::visit(HexAstInExpr expr_)
{
  HexAstInExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr(expr, "in_expr");

  return expr;
}

HexAstNotInExpr
AstToXmlVisitor::visit(HexAstNotInExpr expr_)
{
  HexAstNotInExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstNotInExpr>(expr, "not_in_expr");

  return expr;
}

HexAstAndExpr
AstToXmlVisitor::visit(HexAstAndExpr expr_)
{
  HexAstAndExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstAndExpr>(expr, "and_expr");

  return expr;
}

HexAstOrExpr
AstToXmlVisitor::visit(HexAstOrExpr expr_)
{
  HexAstOrExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstOrExpr>(expr, "or_expr");

  return expr;
}

HexAstInclusiveRangeExpr
AstToXmlVisitor::visit(HexAstInclusiveRangeExpr expr_)
{
  HexAstInclusiveRangeExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "inclusive_range_expr",
    [this, expr]() {

      if(expr->begin()) {
        this->double_tag(
          "inclusive_range_expr-begin",
          [this, expr]() {
            expr->begin()->accept(this);
          }
        );
      }

      if(expr->end()) {
        this->double_tag(
          "inclusive_range_expr-end",
          [this, expr]() {
            expr->end()->accept(this);
          }
        );
      }

    }
  );

  return expr;
}

HexAstExclusiveRangeExpr
AstToXmlVisitor::visit(HexAstExclusiveRangeExpr expr_)
{
  HexAstExclusiveRangeExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "exclusive_range_expr",
    [this, expr]() {

      if(expr->begin()) {
        this->double_tag(
          "exclusive_range_expr-begin",
          [this, expr]() {
            expr->begin()->accept(this);
          }
        );
      }

      if(expr->end()) {
        this->double_tag(
          "exclusive_range_expr-end",
          [this, expr]() {
            expr->end()->accept(this);
          }
        );
      }

    }
  );

  return expr;
}

HexAstPseudoAssignPlusExpr
AstToXmlVisitor::visit(HexAstPseudoAssignPlusExpr expr_)
{
  HexAstPseudoAssignPlusExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignPlusExpr>(expr, "pseudo_plus");

  return expr;
}

HexAstPseudoAssignMinusExpr
AstToXmlVisitor::visit(HexAstPseudoAssignMinusExpr expr_)
{
  HexAstPseudoAssignMinusExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignMinusExpr>(expr, "pseudo_minus");

  return expr;
}

HexAstPseudoAssignMultiplyExpr
AstToXmlVisitor::visit(HexAstPseudoAssignMultiplyExpr expr_)
{
  HexAstPseudoAssignMultiplyExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignMultiplyExpr>(expr, "pseudo_multiply");

  return expr;
}

HexAstPseudoAssignDivideExpr
AstToXmlVisitor::visit(HexAstPseudoAssignDivideExpr expr_)
{
  HexAstPseudoAssignDivideExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignDivideExpr>(expr, "pseudo_divide");

  return expr;
}

HexAstPseudoAssignModulusExpr
AstToXmlVisitor::visit(HexAstPseudoAssignModulusExpr expr_)
{
  HexAstPseudoAssignModulusExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignModulusExpr>(expr, "pseudo_modulus");

  return expr;
}

HexAstPseudoAssignBitwiseAndExpr
AstToXmlVisitor::visit(HexAstPseudoAssignBitwiseAndExpr expr_)
{
  HexAstPseudoAssignBitwiseAndExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignBitwiseAndExpr>(expr, "pseudo_bitwise_and");

  return expr;
}

HexAstPseudoAssignBitwiseOrExpr
AstToXmlVisitor::visit(HexAstPseudoAssignBitwiseOrExpr expr_)
{
  HexAstPseudoAssignBitwiseOrExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignBitwiseOrExpr>(expr, "pseudo_bitwise_or");

  return expr;
}

HexAstPseudoAssignBitwiseXorExpr
AstToXmlVisitor::visit(HexAstPseudoAssignBitwiseXorExpr expr_)
{
  HexAstPseudoAssignBitwiseXorExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignBitwiseXorExpr>(expr, "pseudo_bitwise_xor");

  return expr;
}

HexAstPseudoAssignBitwiseLeftShiftExpr
AstToXmlVisitor::visit(HexAstPseudoAssignBitwiseLeftShiftExpr expr_)
{
  HexAstPseudoAssignBitwiseLeftShiftExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignBitwiseLeftShiftExpr>(expr, "pseudo_bitwise_left_shift");

  return expr;
}

HexAstPseudoAssignBitwiseRightShiftExpr
AstToXmlVisitor::visit(HexAstPseudoAssignBitwiseRightShiftExpr expr_)
{
  HexAstPseudoAssignBitwiseRightShiftExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPseudoAssignBitwiseRightShiftExpr>(expr, "pseudo_bitwise_right_shift");

  return expr;
}

HexAstConditionalExpr
AstToXmlVisitor::visit(HexAstConditionalExpr expr_)
{
  HexAstConditionalExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "conditional_expr",
    [this, expr]() {

      // predicate
      this->double_tag(
        "conditional_expr-predicate",
        [this, expr]() {
          expr->predicate()->accept(this);
        }
      );

      // consequent
      this->double_tag(
        "conditional_expr-consequent",
        [this, expr]() {
          expr->consequent()->accept(this);
        }
      );

      // alternate
      this->double_tag(
        "conditional_expr-alternate",
        [this, expr]() {
          expr->alternate()->accept(this);
        }
      );

    }
  );

  return expr;
}

HexAstYieldExpr
AstToXmlVisitor::visit(HexAstYieldExpr expr_)
{
  HexAstYieldExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "yield_expr",
    [this, expr]() {

      if(expr->exprs()) {
        this->double_tag(
          "yield_expr-exprs",
            [this, expr]() {
              expr->exprs()->accept(this);
            }
        );
      }

    }
  );

  return expr;
}

HexAstStringExpr
AstToXmlVisitor::visit(HexAstStringExpr expr_)
{
  HexAstStringExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "string_expr",
    [this, expr]() {

      this->double_tag(
        "string_expr-literal",
        [this, expr]() {
          expr->string()->accept(this);
        }
      );

      this->double_tag(
        "string_expr-exprs",
        [this, expr]() {
          expr->exprs()->accept(this);
        }
      );
    }
  );

  return expr;
}

HexAstParenForm
AstToXmlVisitor::visit(HexAstParenForm form_)
{
  HexAstParenForm form = AstVisitor::visit(form_);

  this->double_tag(
    "paren_form",
    [this, form]() {
      if(form->exprs()) {
        form->exprs()->accept(this);
      }
    }
  );

  return form;
}

HexAstExprList
AstToXmlVisitor::visit(HexAstExprList exprlist_)
{
  HexAstExprList exprlist = AstVisitor::visit(exprlist_);

  this->double_tag(
    "exprlist",
    [this, exprlist]() {
      this->iterate<HexAstExpr>(
        exprlist->list(),
        [this](HexAstExpr expr) {
          expr->accept(this);
        }
      );
    }
  );

  return exprlist;
}

HexAstSimpleParam
AstToXmlVisitor::visit(HexAstSimpleParam param_)
{
  HexAstSimpleParam param = AstVisitor::visit(param_);

  this->double_tag(
    "simple_param",
    [this, param]() {
      if(param->type()) {
        this->double_tag(
          "simple_param-type",
          [this, param]() {
            param->type()->accept(this);
          }
        );
      }

      this->double_tag(
        "simple_param-name",
        [this, param]() {
          param->name()->accept(this);
        }
      );
    }
  );

  return param;
}

HexAstSimpleParamList
AstToXmlVisitor::visit(HexAstSimpleParamList params_)
{
  HexAstSimpleParamList params = AstVisitor::visit(params_);

  this->double_tag(
    "simple_parameter_list",
    [this, params]() {
      this->iterate<HexAstSimpleParam>(
        params->list(),
        [this](HexAstSimpleParam param) {
          param->accept(this);
        }
      );
    }
  );

  return params;
}

HexAstKeywordParam
AstToXmlVisitor::visit(HexAstKeywordParam param_)
{
  HexAstKeywordParam param = AstVisitor::visit(param_);

  this->double_tag(
    "keyword_param",
    [this, param]() {

      if(param->type()) {
        this->double_tag(
          "keyword_param-type",
          [this, param]() {
            param->type()->accept(this);
          }
        );
      }

      this->double_tag(
        "keyword_param-name",
        [this, param]() {
          param->name()->accept(this);
        }
      );

      this->double_tag(
        "keyword_param-value",
        [this, param]() {
          param->value()->accept(this);
        }
      );
    }
  );

  return param;
}

HexAstKeywordParamList
AstToXmlVisitor::visit(HexAstKeywordParamList params_)
{
  HexAstKeywordParamList params = AstVisitor::visit(params_);

  this->double_tag(
    "keyword_param_list",
    [this, params]() {
      this->iterate<HexAstKeywordParam>(
        params->list(),
        [this](HexAstKeywordParam param) {
          param->accept(this);
        }
      );
    }
  );

  return params;
}

HexAstKeywordVal
AstToXmlVisitor::visit(HexAstKeywordVal keyval_)
{
  HexAstKeywordVal keyval = AstVisitor::visit(keyval_);

  this->double_tag(
    "keyword_val",
    [this, keyval]() {

      this->double_tag(
        "keyword_val-key",
        [this, keyval]() {
          keyval->key()->accept(this);
        }
      );

      this->double_tag(
        "keyword_val-val",
        [this, keyval]() {
          keyval->val()->accept(this);
        }
      );
    }
  );

  return keyval;
}

HexAstKeywordValList
AstToXmlVisitor::visit(HexAstKeywordValList list_)
{
  HexAstKeywordValList list = AstVisitor::visit(list_);

  this->double_tag(
    "keyword_val_list",
    [this, list]() {
      this->iterate<HexAstKeywordVal>(
        list->list(),
        [this](HexAstKeywordVal keyval) {
          keyval->accept(this);
        }
      );
    }
  );

  return list;
}

HexAstParameterList
AstToXmlVisitor::visit(HexAstParameterList params_)
{
  HexAstParameterList params = AstVisitor::visit(params_);

  this->double_tag(
    "parameter_list",
    [this, params]() {

      // simple params
      if(params->simple_params()) {
        this->double_tag(
          "parameter_list-simple_params",
          [this, params]() {
            params->simple_params()->accept(this);
          }
        );
      }

      // keyword params
      if(params->keyword_params()) {
        this->double_tag(
          "parameter_list-keyword_params",
          [this, params]() {
            params->keyword_params()->accept(this);
          }
        );
      }

      // args
      if(params->args()) {
        this->double_tag(
          "parameter_list-args",
          [this, params]() {
            params->args()->accept(this);
          }
        );
      }

      // kwargs
      if(params->kwargs()) {
        this->double_tag(
          "parameter_list-kwargs",
          [this, params]() {
            params->kwargs()->accept(this);
          }
        );
      }

    }
  );

  return params;
}

HexAstValList
AstToXmlVisitor::visit(HexAstValList vallist_)
{
  HexAstValList vallist = AstVisitor::visit(vallist_);

  this->double_tag(
    "val_atom_list",
    [this, vallist]() {
      this->iterate<HexAstValAtom>(
        vallist->list(),
        [this](HexAstValAtom atom) {
          atom->accept(this);
        }
      );
    }
  );

  return vallist;
}

HexAstArgList
AstToXmlVisitor::visit(HexAstArgList arglist_)
{
  HexAstArgList arglist = AstVisitor::visit(arglist_);

  this->double_tag(
    "arg_list",
    [this, arglist]() {

      // simple args
      if(arglist->simple_args()) {
        this->double_tag(
          "arg_list-simple_args",
          [this, arglist]() {
            arglist->simple_args()->accept(this);
          }
        );
      }

      // keyword args
      if(arglist->keyword_args()) {
        this->double_tag(
          "arg_list-keyword_args",
          [this, arglist]() {
            arglist->keyword_args()->accept(this);
          }
        );
      }

      // args
      if(arglist->args()) {
        this->double_tag(
          "arg_list-args",
          [this, arglist]() {
            arglist->args()->accept(this);
          }
        );
      }

      // kwargs
      if(arglist->kwargs()) {
        this->double_tag(
          "arg_list-kwargs",
          [this, arglist]() {
            arglist->kwargs()->accept(this);
          }
        );
      }

    }
  );

  return arglist;
}

HexAstComprehension
AstToXmlVisitor::visit(HexAstComprehension comprehension_)
{
  HexAstComprehension comprehension = AstVisitor::visit(comprehension_);

  this->double_tag(
    "comprehension",
    [this, comprehension]() {

      // destination
      if(comprehension->dst()) {
        this->double_tag(
          "comprehension-dst",
          [this, comprehension]() {
            comprehension->dst()->accept(this);
          }
        );
      }

      // candidates
      this->double_tag(
        "comprehension-candidates",
        [this, comprehension]() {
          comprehension->candidates()->accept(this);
        }
      );

      // source
      this->double_tag(
        "comprehension-source",
        [this, comprehension]() {
          comprehension->src()->accept(this);
        }
      );

      // predicate
      if(comprehension->predicate()) {
        this->double_tag(
          "comprehension-predicate",
          [this, comprehension]() {
            comprehension->predicate()->accept(this);
          }
        );
      }

    }
  );

  return comprehension;
}

HexAstExplicitListForm
AstToXmlVisitor::visit(HexAstExplicitListForm form_)
{
  HexAstExplicitListForm form = AstVisitor::visit(form_);

  this->double_tag(
    "list_form",
    [this, form]() {
      if(form->elements()) {
        HexAstExprList elements = form->elements();
        elements->accept(this);
      }
    }
  );

  return form;
}

HexAstImplicitListForm
AstToXmlVisitor::visit(HexAstImplicitListForm form_)
{
  HexAstImplicitListForm form = AstVisitor::visit(form_);

  this->double_tag(
    "list_form",
    [this, form] () {
      HexAstComprehension comprehension = form->comprehension();
      comprehension->accept(this);
    }
  );

  return form;
}

HexAstFieldDef
AstToXmlVisitor::visit(HexAstFieldDef def_)
{
  HexAstFieldDef def = AstVisitor::visit(def_);

  this->double_tag(
    "field_def",
    [this, def]() {

      // decorators
      if(def->decorators()) {
        this->double_tag(
          "field_def-decorators",
          [this, def]() {
            def->decorators()->accept(this);
          }
        );
      }

      // name
      this->double_tag(
        "field_def-name",
        [this, def]() {
          def->name()->accept(this);
        }
      );

      // val
      this->double_tag(
        "field_def-val",
        [this, def]() {
          def->val()->accept(this);
        }
      );
    }
  );

  return def;
}

HexAstFieldDefList
AstToXmlVisitor::visit(HexAstFieldDefList list_)
{
  HexAstFieldDefList list = AstVisitor::visit(list_);

  this->double_tag(
    "field_def_list",
    [this, list]() {
      this->iterate<HexAstFieldDef>(
        list->list(),
        [this](HexAstFieldDef field) {
          field->accept(this);
        }
      );
    }
  );

  return list;
}

HexAstKeyValuePair
AstToXmlVisitor::visit(HexAstKeyValuePair pair_)
{
  HexAstKeyValuePair pair = AstVisitor::visit(pair_);

  this->double_tag(
    "key_value_pair",
    [this, pair]() {

      // key
      this->double_tag(
        "key_value_pair-key",
        [this, pair]() {
          pair->key()->accept(this);
        }
      );

      // value
      this->double_tag(
        "key_value_pair-value",
        [this, pair]() {
          pair->value()->accept(this);
        }
      );
    }
  );

  return pair;
}

HexAstKeyValuePairList
AstToXmlVisitor::visit(HexAstKeyValuePairList list_)
{
  HexAstKeyValuePairList list = AstVisitor::visit(list_);

  this->double_tag(
    "key_value_pair_list",
    [this, list]() {
      this->iterate<HexAstKeyValuePair>(
        list->list(),
        [this](HexAstKeyValuePair pair) {
          pair->accept(this);
        }
      );
    }
  );

  return list;
}

HexAstExplicitDictForm
AstToXmlVisitor::visit(HexAstExplicitDictForm dict_)
{
  HexAstExplicitDictForm dict = AstVisitor::visit(dict_);

  this->double_tag(
    "dict_form",
    [this, dict]() {
      if(dict->fields()) {
        HexAstKeyValuePairList fields = dict->fields();
        fields->accept(this); 
      }
    }
  );

  return dict;
}

HexAstImplicitDictForm
AstToXmlVisitor::visit(HexAstImplicitDictForm dict_)
{
  HexAstImplicitDictForm dict = AstVisitor::visit(dict_);

  this->double_tag(
    "dict_form",
    [this, dict] () {
      HexAstComprehension comprehension = dict->comprehension();
      comprehension->accept(this);
    }
  );

  return dict;
}

HexAstDecorator
AstToXmlVisitor::visit(HexAstDecorator decorator_)
{
  HexAstDecorator decorator = AstVisitor::visit(decorator_);

  this->double_tag(
    "decorator",
    [this, decorator]() {

      // name
      this->double_tag(
        "decorator-name",
        [this, decorator]() {
          decorator->name()->accept(this);
        }
      );

      // args
      if(decorator->args()) {
        this->double_tag(
          "decorator-args",
          [this, decorator]() {
            decorator->args()->accept(this);
          }
        );
      }

    }
  );

  return decorator;
}

HexAstDecoratorList
AstToXmlVisitor::visit(HexAstDecoratorList decorators_)
{
  HexAstDecoratorList decorators = AstVisitor::visit(decorators_);

  this->double_tag(
    "decorator_list",
    [this, decorators]() {
      this->iterate<HexAstDecorator>(
        decorators->list(),
        [this](HexAstDecorator decorator) {
          decorator->accept(this);
        }
      );
    }
  );

  return decorators;
}

HexAstOperator
AstToXmlVisitor::visit(HexAstOperator op_)
{
  HexAstOperator op = AstVisitor::visit(op_);

  char* s = NULL;

  switch(op->op()) {
    case AST_OPERATOR_PLUS:
      s = "+";
      break;
    case AST_OPERATOR_MINUS:
      s = "-";
      break;
    case AST_OPERATOR_MUL:
      s = "*";
      break;
    case AST_OPERATOR_DIV:
      s = "/";
      break;
    case AST_OPERATOR_MOD:
      s = "%";
      break;
    case AST_OPERATOR_BITWISE_NOT:
      s = "~";
      break;
    case AST_OPERATOR_BITWISE_AND:
      s = "&";
      break;
    case AST_OPERATOR_BITWISE_OR:
      s = "|";
      break;
    case AST_OPERATOR_BITWISE_XOR:
      s = "^";
      break;
    case AST_OPERATOR_BITWISE_SHIFTLEFT:
      s = "<<";
      break;
    case AST_OPERATOR_BITWISE_SHIFTRIGHT:
      s = ">>";
      break;
    case AST_OPERATOR_EQ:
      s = "==";
      break;
    case AST_OPERATOR_NEQ:
      s = "!=";
      break;
    case AST_OPERATOR_GT:
      s = ">";
      break;
    case AST_OPERATOR_LT:
      s = "<";
      break;
    case AST_OPERATOR_GEQ:
      s = ">=";
      break;
    case AST_OPERATOR_LEQ:
      s = "<=";
      break;
    case AST_OPERATOR_INC:
      s = "++";
      break;
    case AST_OPERATOR_DEC:
      s = "--";
      break;
    case AST_OPERATOR_ASSIGN_OP:
      s = "=";
      break;
    case AST_OPERATOR_ASSIGN_PLUS:
      s = "+=";
      break;
    case AST_OPERATOR_ASSIGN_MINUS:
      s = "-=";
      break;
    case AST_OPERATOR_ASSIGN_MUL:
      s = "*=";
      break;
    case AST_OPERATOR_ASSIGN_DIV:
      s = "/=";
      break;
    case AST_OPERATOR_ASSIGN_MOD:
      s = "%=";
      break;
    case AST_OPERATOR_ASSIGN_BITWISE_AND:
      s = "&=";
      break;
    case AST_OPERATOR_ASSIGN_BITWISE_OR:
      s = "|=";
      break;
    case AST_OPERATOR_ASSIGN_BITWISE_XOR:
      s = "^=";
      break;
    case AST_OPERATOR_ASSIGN_SHIFTLEFT:
      s = "<<=";
      break;
    case AST_OPERATOR_ASSIGN_SHIFTRIGHT:
      s = ">>=";
      break;
    case AST_OPERATOR_INPUT:
      s = "<<<";
      break;
    case AST_OPERATOR_OUTPUT:
      s = ">>>";
      break;
    default:
      break;
  }

  this->double_tag(
    "operator",
    [this, op, s]() {
      this->append(s);
    }
  );

  return op;
}

HexAstOperatorDef
AstToXmlVisitor::visit(HexAstOperatorDef def_)
{
  HexAstOperatorDef def = AstVisitor::visit(def_);

  this->double_tag(
    "operator_def",
    [this, def]() {

      // operator
      this->double_tag(
        "operator_def-op",
        [this, def]() {
          def->op()->accept(this);
        }
      );

      // lambda
      this->double_tag(
        "operator_def-lambda",
        [this, def]() {
          def->lambda()->accept(this);
        }
      );

    }
  );

  return def;
}

HexAstAttributeDefList
AstToXmlVisitor::visit(HexAstAttributeDefList defs_)
{
  HexAstAttributeDefList defs = AstVisitor::visit(defs_);

  this->double_tag(
    "attribute_def_list",
    [this, defs]() {
      this->iterate<HexAstAttributeDef>(
        defs->list(),
        [this](HexAstAttributeDef def) {
          def->accept(this);
        }
      );
    }
  );

  return defs;
}

HexAstExprListAssignmentStmt
AstToXmlVisitor::visit(HexAstExprListAssignmentStmt stmt_)
{
  HexAstExprListAssignmentStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "assignment_stmt",
    [this, stmt]() {

      // dst
      this->double_tag(
        "assignment_stmt-dst",
        [this, stmt]() {
          stmt->target()->accept(this);
        }
      );

      // src
      this->double_tag(
        "assignment_stmt-src",
        [this, stmt]() {
          HexAstExprList exprlist = stmt->src();
          exprlist->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstLambdaAssignmentStmt
AstToXmlVisitor::visit(HexAstLambdaAssignmentStmt stmt_)
{
  HexAstLambdaAssignmentStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "assignment_stmt",
    [this, stmt]() {

      // decorators
      if(stmt->decorators()) {
        this->double_tag(
          "assignment_stmt-decorators",
          [this, stmt]() {
            stmt->decorators()->accept(this);
          }
        );
      }

      // dst
      this->double_tag(
        "assignment_stmt-dst",
        [this, stmt]() {
          stmt->target()->accept(this);
        }
      );

      // src
      this->double_tag(
        "assignment_stmt-src",
        [this, stmt]() {
          HexAstLambda lambda = stmt->src();
          lambda->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstTaskDefAssignmentStmt
AstToXmlVisitor::visit(HexAstTaskDefAssignmentStmt stmt_)
{
  HexAstTaskDefAssignmentStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "assignment_stmt",
    [this, stmt]() {

      // dst
      this->double_tag(
        "assignment_stmt-dst",
        [this, stmt]() {
          stmt->target()->accept(this);
        }
      );

      // src
      this->double_tag(
        "assignment_stmt-src",
        [this, stmt]() {
          HexAstTaskDef task = stmt->src();
          task->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstUsingSrc
AstToXmlVisitor::visit(HexAstUsingSrc src_)
{
  HexAstUsingSrc src = AstVisitor::visit(src_);

  this->double_tag(
    "using_src",
    [this, src]() {
      if(src->level() > 0) {
        this->double_tag(
          "using_src_level",
          [this, src]() {
            char lvl[5] = {0};
            sprintf(lvl, "%zd", src->level());
            this->append(lvl);
          }
        );
      }
      if(src->name()) {
        src->name()->accept(this);
      }
    }
  );

  return src;
}

HexAstUsingStmtDirect
AstToXmlVisitor::visit(HexAstUsingStmtDirect stmt_)
{
  HexAstUsingStmtDirect stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "using_stmt_direct",
    [this, stmt]() {

      // target
      this->double_tag(
        "using_stmt_direct-target",
        [this, stmt]() {
          stmt->target()->accept(this);
        }
      );

      // alias
      if(stmt->alias()) {
        this->double_tag(
          "using_stmt_direct-alias",
          [this, stmt]() {
            stmt->alias()->accept(this);
          }
        );
      }

    }
  );

  return stmt;
}

HexAstUsingStmtRelative
AstToXmlVisitor::visit(HexAstUsingStmtRelative stmt_)
{
  HexAstUsingStmtRelative stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "using_stmt_relative",
    [this, stmt]() {

      // targets
      if(stmt->targets()) {
        this->double_tag(
          "using_stmt_relative-targets",
          [this, stmt]() {
            stmt->targets()->accept(this);
          }
        );
      }

      // src
      this->double_tag(
        "using_stmt_relative-src",
        [this, stmt]() {
          stmt->src()->accept(this);
        }
      );

      // alias
      if(stmt->alias()) {
        this->double_tag(
          "using_stmt_relative-alias",
          [this, stmt]() {
            stmt->alias()->accept(this);
          }
        );
      }

    }
  );

  return stmt;
}

HexAstElifStmt
AstToXmlVisitor::visit(HexAstElifStmt stmt_)
{
  HexAstElifStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "elif_stmt",
    [this, stmt]() {

      // predicate
      this->double_tag(
        "elif_stmt-predicate",
        [this, stmt]() {
          stmt->predicate()->accept(this);
        }
      );

      // stmts
      this->double_tag(
        "elif_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstElifStmtGroup
AstToXmlVisitor::visit(HexAstElifStmtGroup stmts_)
{
  HexAstElifStmtGroup stmts = AstVisitor::visit(stmts_);

  this->double_tag(
    "elif_stmt_group",
    [this, stmts]() {
      this->iterate<HexAstElifStmt>(
        stmts->list(),
        [this](HexAstElifStmt stmt) {
          stmt->accept(this);
        }
      );
    }
  );

  return stmts;
}

HexAstElseStmt
AstToXmlVisitor::visit(HexAstElseStmt stmt_)
{
  HexAstElseStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "else_stmt",
    [this, stmt]() {
      stmt->stmts()->accept(this);
    }
  );

  return stmt;
}

HexAstIfStmt
AstToXmlVisitor::visit(HexAstIfStmt stmt_)
{
  HexAstIfStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "if_stmt",
    [this, stmt]() {

      // predicate
      this->double_tag(
        "if_stmt-predicate",
        [this, stmt]() {
          stmt->predicate()->accept(this);
        }
      );

      // stmts
      this->double_tag(
        "if_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

      // elif stmts
      if(stmt->elif_stmts()) {
        this->double_tag(
          "if_stmt-elif_stmts",
          [this, stmt]() {
            stmt->elif_stmts()->accept(this);
          }
        );
      }

      // else stmts
      if(stmt->else_stmt()) {
        this->double_tag(
          "if_stmt-else_stmts",
          [this, stmt]() {
            stmt->else_stmt()->accept(this);
          }
        );
      }

    }
  );

  return stmt;
}

HexAstForStmt
AstToXmlVisitor::visit(HexAstForStmt stmt_)
{
  HexAstForStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "for_stmt",
    [this, stmt]() {

      // targets
      this->double_tag(
        "for_stmt-targets",
        [this, stmt]() {
          stmt->targets()->accept(this);
        }
      );

      // exprs
      this->double_tag(
        "for_stmt-exprs",
        [this, stmt]() {
          stmt->exprs()->accept(this);
        }
      );

      // predicate
      if(stmt->predicate()) {
        this->double_tag(
          "for_stmt-predicate",
          [this, stmt]() {
            stmt->predicate()->accept(this);
          }
        );
      }

      // stmts
      this->double_tag(
        "for_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstWithStmt
AstToXmlVisitor::visit(HexAstWithStmt stmt_)
{
  HexAstWithStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "with_stmt",
    [this, stmt]() {

      // exprs
      this->double_tag(
        "with_stmt-exprs",
        [this, stmt]() {
          stmt->exprs()->accept(this);
        }
      );

      // alias
      if(stmt->alias()) {
        this->double_tag(
          "with_stmt-alias",
          [this, stmt]() {
            stmt->alias()->accept(this);
          }
        );
      }

      // stmts
      this->double_tag(
        "with_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstLockStmt
AstToXmlVisitor::visit(HexAstLockStmt stmt_)
{
  HexAstLockStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "lock_stmt",
    [this, stmt]() {

      // exprs
      this->double_tag(
        "lock_stmt-exprs",
        [this, stmt]() {
          stmt->exprs()->accept(this);
        }
      );

      // stmts
      this->double_tag(
        "lock_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstWhileStmt
AstToXmlVisitor::visit(HexAstWhileStmt stmt_)
{
  HexAstWhileStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "while_stmt",
    [this, stmt]() {

      // expr
      this->double_tag(
        "while_stmt-expr",
        [this, stmt]() {
          stmt->expr()->accept(this);
        }
      );

      // stmts
      this->double_tag(
        "while_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstCatchStmt
AstToXmlVisitor::visit(HexAstCatchStmt stmt_)
{
  HexAstCatchStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "catch_stmt",
    [this, stmt]() {

      // targets
      if(stmt->targets()) {
        this->double_tag(
          "catch_stmt-targets",
          [this, stmt]() {
            stmt->targets()->accept(this);
          }
        );

        // alias
        if(stmt->alias()) {
          this->double_tag(
            "catch_stmt-alias",
            [this, stmt]() {
              stmt->alias()->accept(this);
            }
          );
        }
      }

      // stmts
      this->double_tag(
        "catch_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstCatchStmtGroup
AstToXmlVisitor::visit(HexAstCatchStmtGroup stmts_)
{
  HexAstCatchStmtGroup stmts = AstVisitor::visit(stmts_);

  this->double_tag(
    "catch_stmt_group",
    [this, stmts]() {
      this->iterate<HexAstCatchStmt>(
        stmts->list(),
        [this](HexAstCatchStmt stmt) {
          stmt->accept(this);
        }
      );
    }
  );

  return stmts;
}

HexAstTryStmt
AstToXmlVisitor::visit(HexAstTryStmt stmt_)
{
  HexAstTryStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "try_stmt",
    [this, stmt]() {

      // stmts
      this->double_tag(
        "try_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

      // catch stmts
      this->double_tag(
        "try_stmt-catch_stmts",
        [this, stmt]() {
          stmt->catch_stmt_group()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstClassDef
AstToXmlVisitor::visit(HexAstClassDef def_)
{
  HexAstClassDef def = AstVisitor::visit(def_);

  this->double_tag(
    "class_def",
    [this, def]() {

      // decorators
      if(def->decorators()) {
        this->double_tag(
          "class_def-decorators",
          [this, def]() {
            def->decorators()->accept(this);
          }
        );
      }

      // name
      this->double_tag(
        "class_def-name",
        [this, def]() {
          def->name()->accept(this);
        }
      );

      // parent
      if(def->parent()) {
        this->double_tag(
          "class_def-parent",
          [this, def]() {
            def->parent()->accept(this);
          }
        );
      }

      // attributes
      if(def->attributes()) {
        this->double_tag(
          "class_def-attributes",
          [this, def]() {
            def->attributes()->accept(this);
          }
        );
      }

    }
  );

  return def;
}

HexAstLambdaSimple
AstToXmlVisitor::visit(HexAstLambdaSimple lambda_)
{
  HexAstLambdaSimple lambda = AstVisitor::visit(lambda_);

  this->double_tag(
    "lambda_simple",
    [this, lambda]() {

      // params
      if(lambda->params()) {
        this->double_tag(
          "lambda_simple-params",
          [this, lambda]() {
            lambda->params()->accept(this);
          }
        );
      }

      // expr
      this->double_tag(
        "lambda_simple-expr",
        [this, lambda]() {
          lambda->expr()->accept(this);
        }
      );

    }
  );

  return lambda;
}

HexAstLambdaComplex
AstToXmlVisitor::visit(HexAstLambdaComplex lambda_)
{
  HexAstLambdaComplex lambda = AstVisitor::visit(lambda_);

  this->double_tag(
    "lambda_complex",
    [this, lambda]() {

      // params
      if(lambda->params()) {
        this->double_tag(
          "lambda_complex-params",
          [this, lambda]() {
            lambda->params()->accept(this);
          }
        );
      }

      // stmts
      this->double_tag(
        "lambda_complex-stmts",
        [this, lambda]() {
          lambda->stmts()->accept(this);
        }
      );

    }
  );

  return lambda;
}

HexAstInputStmt
AstToXmlVisitor::visit(HexAstInputStmt stmt_)
{
  HexAstInputStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "input_stmt",
    [this, stmt]() {
      this->iterate<HexAstPrimary>(
        stmt->list(),
        [this](HexAstPrimary primary) {
          this->double_tag(
            "input_stmt-component",
            [this, primary]() {
              primary->accept(this);
            }
          );
        }
      );
    }
  );

  return stmt;
}

HexAstOutputStmt
AstToXmlVisitor::visit(HexAstOutputStmt stmt_)
{
  HexAstOutputStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "output_stmt",
    [this, stmt]() {
      this->iterate<HexAstPrimary>(
        stmt->list(),
        [this](HexAstPrimary primary) {
          this->double_tag(
            "output_stmt-component",
            [this, primary]() {
              primary->accept(this);
            }
          );
        }
      );
    }
  );

  return stmt;
}

HexAstTaskState
AstToXmlVisitor::visit(HexAstTaskState state_)
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
    case AST_TASK_STATE_STOP:
      s = "stop";
      break;
    default:
      break;
  }

  this->double_tag(
    "task_state",
    [this, s]() {
      this->append(s);
    }
  );

  return state;
}

HexAstConditionalPreposition
AstToXmlVisitor::visit(HexAstConditionalPreposition preposition_)
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
    case AST_TASK_CONDITIONAL_PREPOSITION_WHEN:
      s = "when";
      break;
    default:
      break;
  }

  this->double_tag(
    "conditional_preposition",
    [this, s]() {
      this->append(s);
    }
  );

  return preposition;
}

HexAstConditionalClause
AstToXmlVisitor::visit(HexAstConditionalClause clause_)
{
  HexAstConditionalClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "conditional_clause",
    [this, clause]() {

      // preposition
      this->double_tag(
        "conditional_clause-preposition",
        [this, clause]() {
          clause->preposition()->accept(this);
        }
      );

      // exprs
      this->double_tag(
        "conditional_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // state
      this->double_tag(
        "conditional_clause-state",
        [this, clause]() {
          clause->state()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstStartClauseSingle
AstToXmlVisitor::visit(HexAstStartClauseSingle clause_)
{
  HexAstStartClauseSingle clause = AstVisitor::visit(clause_);

  this->double_tag(
    "start_clause_single",
    [this, clause]() {

      // target
      this->double_tag(
        "start_clause_single-target",
        [this, clause]() {
          clause->target()->accept(this);
        }
      );

      // alias
      if(clause->alias()) {
        this->double_tag(
          "start_clause_single-alias",
          [this, clause]() {
            clause->alias()->accept(this);
          }
        );
      }

      // condition
      this->double_tag(
        "start_clause_single-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstStartClauseMultiple
AstToXmlVisitor::visit(HexAstStartClauseMultiple clause_)
{
  HexAstStartClauseMultiple clause = AstVisitor::visit(clause_);

  this->double_tag(
    "start_clause_multiple",
    [this, clause]() {

      // targets
      this->double_tag(
        "start_clause_multiple-targets",
        [this, clause]() {
          clause->targets()->accept(this);
        }
      );

      // alias
      if(clause->alias()) {
        this->double_tag(
          "start_clause_multiple-alias",
          [this, clause]() {
            clause->alias()->accept(this);
          }
        );
      }

      // condition
      this->double_tag(
        "start_clause_multiple-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstPauseClause
AstToXmlVisitor::visit(HexAstPauseClause clause_)
{
  HexAstPauseClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "pause_clause",
    [this, clause]() {

      // exprs
      this->double_tag(
        "pause_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // condition
      this->double_tag(
        "pause_clause-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstResumeClause
AstToXmlVisitor::visit(HexAstResumeClause clause_)
{
  HexAstResumeClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "resume_clause",
    [this, clause]() {

      // exprs
      this->double_tag(
        "resume_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // condition
      this->double_tag(
        "resume_clause-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstCancelClause
AstToXmlVisitor::visit(HexAstCancelClause clause_)
{
  HexAstCancelClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "cancel_clause",
    [this, clause]() {

      // exprs
      this->double_tag(
        "cancel_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // condition
      this->double_tag(
        "cancel_clause-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstConditionalDelayClause
AstToXmlVisitor::visit(HexAstConditionalDelayClause clause_)
{
  HexAstConditionalDelayClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "conditional_delay_clause",
    [this, clause]() {

      // exprs
      this->double_tag(
        "conditional_delay_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // condition
      this->double_tag(
        "conditional_delay_clause-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstFixedDelayClause
AstToXmlVisitor::visit(HexAstFixedDelayClause clause_)
{
  HexAstFixedDelayClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "fixed_delay_clause",
    [this, clause]() {

      // exprs
      this->double_tag(
        "fixed_delay_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // delay
      this->double_tag(
        "fixed_delay_clause-delay",
        [this, clause]() {
          clause->delay()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstStopClause
AstToXmlVisitor::visit(HexAstStopClause clause_)
{
  HexAstStopClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "stop_clause",
    [this, clause]() {

      // exprs
      this->double_tag(
        "stop_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

      // condition
      this->double_tag(
        "stop_clause-condition",
        [this, clause]() {
          clause->condition()->accept(this);
        }
      );

    }
  );

  return clause;
}

HexAstTaskDef
AstToXmlVisitor::visit(HexAstTaskDef def_)
{
  HexAstTaskDef def = AstVisitor::visit(def_);

  this->double_tag(
    "task_def",
    [this, def]() {
      this->iterate<HexAstTaskClause>(
        def->list(),
        [this](HexAstTaskClause clause) {
          clause->accept(this);
        }
      );
    }
  );

  return def;
}

HexAstAwaitStmt
AstToXmlVisitor::visit(HexAstAwaitStmt stmt_)
{
  HexAstAwaitStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "await_stmt",
    [this, stmt]() {

      this->double_tag(
        "await_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstReturnStmt
AstToXmlVisitor::visit(HexAstReturnStmt stmt_)
{
  HexAstReturnStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "return_stmt",
    [this, stmt]() {

      // return vals
      if(stmt->return_vals()) {
        this->double_tag(
          "return_stmt-return_vals",
          [this, stmt]() {
            stmt->return_vals()->accept(this);
          }
        );
      }

      // predicate
      if(stmt->predicate()) {
        this->double_tag(
          "return_vals-predicate",
          [this, stmt]() {
            stmt->predicate()->accept(this);
          }
        );
      }

    }
  );

  return stmt;
}

HexAstBreakStmt
AstToXmlVisitor::visit(HexAstBreakStmt stmt_)
{
  HexAstBreakStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "break_stmt",
    [this, stmt]() {

      // predicate
      if(stmt->predicate()) {
        this->double_tag(
          "break_vals-predicate",
          [this, stmt]() {
            stmt->predicate()->accept(this);
          }
        );
      }

    }
  );

  return stmt;
}

HexAstContinueStmt
AstToXmlVisitor::visit(HexAstContinueStmt stmt_)
{
  HexAstContinueStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "continue_stmt",
    [this, stmt]() {

      // predicate
      if(stmt->predicate()) {
        this->double_tag(
          "continue_vals-predicate",
          [this, stmt]() {
            stmt->predicate()->accept(this);
          }
        );
      }

    }
  );

  return stmt;
}

HexAstRaiseStmt
AstToXmlVisitor::visit(HexAstRaiseStmt stmt_)
{
  HexAstRaiseStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "raise_stmt",
    [this, stmt]() {

      this->double_tag(
        "raise_stmt-expr",
        [this, stmt]() {
          stmt->expr()->accept(this);
        }
      );

    }
  );

  return stmt;
}

HexAstExprListStmt
AstToXmlVisitor::visit(HexAstExprListStmt stmt_)
{
  HexAstExprListStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "expr_list_stmt",
    [this, stmt]() {
      stmt->exprs()->accept(this);
    }
  );

  return stmt;
}

HexAstStmtGroup
AstToXmlVisitor::visit(HexAstStmtGroup stmts_)
{
  HexAstStmtGroup stmts = AstVisitor::visit(stmts_);

  this->double_tag(
    "stmt_group",
    [this, stmts]() {
      this->iterate<HexAstStmt>(
        stmts->list(),
        [this](HexAstStmt stmt) {
          stmt->accept(this);
        }
      );
    }
  );

  return stmts;
}

HexAstHexProgram
AstToXmlVisitor::visit(HexAstHexProgram program_)
{
  HexAstHexProgram program = AstVisitor::visit(program_);

  this->double_tag(
    "hex_program",
    [this, program]() {

      // stmts
      this->double_tag(
        "hex_program-stmts",
        [this, program]() {
          program->stmts()->accept(this);
        }
      );

    }
  );

  return program;
}
