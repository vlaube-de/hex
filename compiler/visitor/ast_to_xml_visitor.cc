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
#include "ast_tostring_helper.h"
#include "ast_to_xml_visitor.h"
#include "../ast2/ast.h"
#include "../../base/assert.h"


AstToXmlVisitor::AstToXmlVisitor()
  :AstToStringHelper()
{
  // Do nothing here.
}

AstToXmlVisitor::~AstToXmlVisitor()
{
  // Do nothing here.
}

void
AstToXmlVisitor::begin_tag(const c_str tag, const c_str attributes)
{
  std::string str;
  str.append("<");
  str.append(tag);
  if(attributes) {
    str.append(" ");
    str.append(attributes);
  }
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
AstToXmlVisitor::double_tag(const c_str tag)
{
  this->indentation();
  this->begin_tag(tag);
  this->end_tag(tag);
  this->newline();
}

void
AstToXmlVisitor::double_tag(const c_str tag, c_str value)
{
  this->indentation();
  this->begin_tag(tag);
  this->append(value);
  this->end_tag(tag);
  this->newline();
}

template<class Function>
void
AstToXmlVisitor::double_tag(const c_str tag, Function f)
{
  this->indentation();
  this->begin_tag(tag);
  this->newline();
  this->indent();
  f();
  this->dedent();
  this->indentation();
  this->end_tag(tag);
  this->newline();
}

template<class Function>
void
AstToXmlVisitor::double_tag(const c_str tag, const c_str attributes, Function f)
{
  this->indentation();
  this->begin_tag(tag, attributes);
  this->newline();
  this->indent();
  f();
  this->dedent();
  this->indentation();
  this->end_tag(tag);
  this->newline();
}

template<class Function>
void
AstToXmlVisitor::double_tag_simple(const c_str tag, Function f)
{
  this->indentation();
  this->begin_tag(tag);
  f();
  this->end_tag(tag);
  this->newline();
}

template<class Function>
void
AstToXmlVisitor::double_tag_simple(const c_str tag, const c_str attributes, Function f)
{
  this->indentation();
  this->begin_tag(tag, attributes);
  f();
  this->end_tag(tag);
  this->newline();
}

template<class T>
void
AstToXmlVisitor::iterate(std::list<T>* list, bool breakOnLast)
{
  typename std::list<T>::iterator itr;
  for(itr=list->begin(); itr != list->end();) {
    // this->newline();
    // this->indentation();
    ((T)(*itr))->accept(this);
    // this->newline();
    // if(++itr == list->end()) this->newline();
    if(++itr == list->end() && breakOnLast) break;
  }
}

template<class T>
void
AstToXmlVisitor::double_tag_for_unary_expr(T expr, const c_str tag)
{
  this->double_tag(
    tag,
    [this, expr]() {
      expr->expr()->accept(this);
    }
  );
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
          expr->lexpr()->accept(this);
        }
      );

      this->double_tag(
        (const c_str)tag_right.append("-right").c_str(),
        [this, expr]() {
          expr->rexpr()->accept(this);
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

HexAstDecimalIntegerLiteral
AstToXmlVisitor::visit(HexAstDecimalIntegerLiteral literal_)
{
  HexAstDecimalIntegerLiteral literal = AstVisitor::visit(literal_);

  this->double_tag_simple(
    "integer_literal",
    "type=\"decimal\"",
    [this, literal]() {
      this->append(literal->value());
    }
  );
  // this->begin_tag("integer_literal", "type=\"decimal\"");
  // this->append(literal->value());
  // this->end_tag("integer_literal");

  return literal;
}

HexAstBinaryIntegerLiteral
AstToXmlVisitor::visit(HexAstBinaryIntegerLiteral literal_)
{
  HexAstBinaryIntegerLiteral literal = AstVisitor::visit(literal_);

  this->double_tag_simple(
    "integer_literal",
    "type=\"binary\"",
    [this, literal]() {
      this->append(literal->value());
    }
  );
  // this->begin_tag("integer_literal", "type=\"binary\"");
  // this->append(literal->value());
  // this->end_tag("integer_literal");

  return literal;
}

HexAstOctalIntegerLiteral
AstToXmlVisitor::visit(HexAstOctalIntegerLiteral literal_)
{
  HexAstOctalIntegerLiteral literal = AstVisitor::visit(literal_);

  this->double_tag_simple(
    "integer_literal",
    "type=\"octal\"",
    [this, literal]() {
      this->append(literal->value());
    }
  );
  // this->begin_tag("integer_literal", "type=\"octal\"");
  // this->append(literal->value());
  // this->end_tag("integer_literal");

  return literal;
}

HexAstHexadecimalIntegerLiteral
AstToXmlVisitor::visit(HexAstHexadecimalIntegerLiteral literal_)
{
  HexAstHexadecimalIntegerLiteral literal = AstVisitor::visit(literal_);

  this->double_tag_simple(
    "integer_literal",
    "type=\"hexadecimal\"",
    [this, literal]() {
      this->append(literal->value());
    }
  );
  // this->begin_tag("integer_literal", "type=\"hexadecimal\"");
  // this->append(literal->value());
  // this->end_tag("integer_literal");

  return literal;
}

HexAstFloatLiteral
AstToXmlVisitor::visit(HexAstFloatLiteral literal_)
{
  HexAstFloatLiteral literal = AstVisitor::visit(literal_);

  this->double_tag("floating_literal", literal->value());

  return literal;
}

HexAstSingleQuoteStringLiteral
AstToXmlVisitor::visit(HexAstSingleQuoteStringLiteral literal_)
{
  HexAstSingleQuoteStringLiteral literal = AstVisitor::visit(literal_);

  this->double_tag_simple(
    "string_literal",
    "type=\"single\"",
    [this, literal]() {
      this->append(literal->value());
    }
  );
  // this->begin_tag("string_literal", "quote=\"single\"");
  // this->append(literal->value());
  // this->end_tag("string_literal");

  return literal;
}

HexAstDoubleQuoteStringLiteral
AstToXmlVisitor::visit(HexAstDoubleQuoteStringLiteral literal_)
{
  HexAstDoubleQuoteStringLiteral literal = AstVisitor::visit(literal_);

  this->double_tag_simple(
    "string_literal",
    "type=\"double\"",
    [this, literal]() {
      this->append(literal->value());
    }
  );
  // this->begin_tag("string_literal", "quote=\"double\"");
  // this->append(literal->value());
  // this->end_tag("string_literal");

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
        "call-caller",
        [this, call]() {
          call->caller()->accept(this);
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

void
AstToXmlVisitor::_visit_slicing_start(HexAstSlicing slicing)
{
  this->double_tag(
    "slicing_start",
    [this, slicing]() {
      slicing->start()->accept(this);
    }
  );
}

void
AstToXmlVisitor::_visit_slicing_step(HexAstSlicing slicing)
{
  this->double_tag(
    "slicing_step",
    [this, slicing]() {
      slicing->step()->accept(this);
    }
  );
}

void
AstToXmlVisitor::_visit_slicing_stop(HexAstSlicing slicing)
{
  this->double_tag(
    "slicing_stop",
    [this, slicing]() {
      slicing->stop()->accept(this);
    }
  );
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

      switch(slicing->type()) {
        case AST_SLICING_TYPE_1:
          {
            this->_visit_slicing_start(slicing);
            this->_visit_slicing_step(slicing);
            this->_visit_slicing_stop(slicing);
          }
          break;
        case AST_SLICING_TYPE_2:
          {
            this->_visit_slicing_start(slicing);
            this->_visit_slicing_step(slicing);
          }
          break;
        case AST_SLICING_TYPE_3:
          {
            this->_visit_slicing_start(slicing);
            this->_visit_slicing_step(slicing);
          }
          break;
        case AST_SLICING_TYPE_4:
          {
            this->_visit_slicing_start(slicing);
            this->_visit_slicing_stop(slicing);
          }
          break;
        case AST_SLICING_TYPE_5:
          {
            this->_visit_slicing_start(slicing);
          }
          break;
        case AST_SLICING_TYPE_6:
          {
            this->_visit_slicing_step(slicing);
            this->_visit_slicing_stop(slicing);
          }
          break;
        case AST_SLICING_TYPE_7:
          {
            this->_visit_slicing_step(slicing);
          }
          break;
        case AST_SLICING_TYPE_8:
          {
            this->_visit_slicing_stop(slicing);
          }
          break;
        case AST_SLICING_TYPE_9:
          {
            // Do nothing here.
          }
          break;
        case AST_SLICING_TYPE_A:
          {
            // Do nothing here.
          }
          break;
        case AST_SLICING_TYPE_B:
          {
            this->_visit_slicing_stop(slicing);
          }
          break;
        case AST_SLICING_TYPE_C:
          {
            this->_visit_slicing_start(slicing);
          }
          break;
        case AST_SLICING_TYPE_D:
          {
            this->_visit_slicing_start(slicing);
          }
          break;
        default:
          break;
      }

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
        targets->list()
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
        name->list()
      );
    }
  );

  return name;
}

HexAstNameList
AstToXmlVisitor::visit(HexAstNameList names_)
{
  HexAstNameList names = AstVisitor::visit(names_);

  this->double_tag(
    "names",
    [this, names]() {
      this->iterate<HexAstName>(
        names->list()
      );
    }
  );

  return names;
}

HexAstPositiveExpr
AstToXmlVisitor::visit(HexAstPositiveExpr expr_)
{
  HexAstPositiveExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstPositiveExpr>(
    expr,
    "positive_expr"
  );

  return expr;
}

HexAstNegativeExpr
AstToXmlVisitor::visit(HexAstNegativeExpr expr_)
{
  HexAstNegativeExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstNegativeExpr>(
    expr,
    "negative_expr"
  );

  return expr;
}

HexAstNotExpr
AstToXmlVisitor::visit(HexAstNotExpr expr_)
{
  HexAstNotExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstNotExpr>(
    expr,
    "not_expr"
  );

  return expr;
}

HexAstBitwiseNotExpr
AstToXmlVisitor::visit(HexAstBitwiseNotExpr expr_)
{
  HexAstBitwiseNotExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstBitwiseNotExpr>(
    expr,
    "bitwise_not_expr"
  );

  return expr;
}

HexAstIncrementExpr
AstToXmlVisitor::visit(HexAstIncrementExpr expr_)
{
  HexAstIncrementExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstIncrementExpr>(
    expr,
    "increment_expr"
  );

  return expr;
}

HexAstDecrementExpr
AstToXmlVisitor::visit(HexAstDecrementExpr expr_)
{
  HexAstDecrementExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstDecrementExpr>(
    expr,
    "decrement_expr"
  );

  return expr;
}

HexAstExistentialExpr
AstToXmlVisitor::visit(HexAstExistentialExpr expr_)
{
  HexAstExistentialExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_unary_expr<HexAstExistentialExpr>(
    expr,
    "existential_expr"
  );

  return expr;
}

HexAstAdditionExpr
AstToXmlVisitor::visit(HexAstAdditionExpr expr_)
{
  HexAstAdditionExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstAdditionExpr>(
    expr,
    "add_expr"
  );

  return expr;
}

HexAstSubtractionExpr
AstToXmlVisitor::visit(HexAstSubtractionExpr expr_)
{
  HexAstSubtractionExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstSubtractionExpr>(
    expr,
    "minus_expr"
  );

  return expr;
}

HexAstMultiplicationExpr
AstToXmlVisitor::visit(HexAstMultiplicationExpr expr_)
{
  HexAstMultiplicationExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstMultiplicationExpr>(
    expr,
    "multiply_expr"
  );

  return expr;
}

HexAstDivisionExpr
AstToXmlVisitor::visit(HexAstDivisionExpr expr_)
{
  HexAstDivisionExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstDivisionExpr>(
    expr,
    "divide_expr"
  );

  return expr;
}

HexAstModulusExpr
AstToXmlVisitor::visit(HexAstModulusExpr expr_)
{
  HexAstModulusExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstModulusExpr>(
    expr,
    "modulus_expr"
  );

  return expr;
}

HexAstPowerExpr
AstToXmlVisitor::visit(HexAstPowerExpr expr_)
{
  HexAstPowerExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstPowerExpr>(
    expr,
    "power_expr"
  );

  return expr;
}

HexAstBitwiseANDExpr
AstToXmlVisitor::visit(HexAstBitwiseANDExpr expr_)
{
  HexAstBitwiseANDExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseANDExpr>(
    expr,
    "bitwise_and_expr"
  );

  return expr;
}

HexAstBitwiseORExpr
AstToXmlVisitor::visit(HexAstBitwiseORExpr expr_)
{
  HexAstBitwiseORExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseORExpr>(
    expr,
    "bitwise_or_expr"
  );

  return expr;
}

HexAstBitwiseXORExpr
AstToXmlVisitor::visit(HexAstBitwiseXORExpr expr_)
{
  HexAstBitwiseXORExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseXORExpr>(
    expr,
    "bitwise_xor_expr"
  );

  return expr;
}

HexAstBitwiseLeftShiftExpr
AstToXmlVisitor::visit(HexAstBitwiseLeftShiftExpr expr_)
{
  HexAstBitwiseLeftShiftExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseLeftShiftExpr>(
    expr,
    "bitwise_shift_left_expr"
  );

  return expr;
}

HexAstBitwiseRightShiftExpr
AstToXmlVisitor::visit(HexAstBitwiseRightShiftExpr expr_)
{
  HexAstBitwiseRightShiftExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseRightShiftExpr>(
    expr,
    "bitwise_shift_right_expr"
  );

  return expr;
}

HexAstEqualsExpr
AstToXmlVisitor::visit(HexAstEqualsExpr expr_)
{
  HexAstEqualsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstEqualsExpr>(
    expr,
    "equals_expr"
  );

  return expr;
}

HexAstNotEqualExpr
AstToXmlVisitor::visit(HexAstNotEqualExpr expr_)
{
  HexAstNotEqualExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstNotEqualExpr>(
    expr,
    "not_equal_expr"
  );

  return expr;
}

HexAstIsExpr
AstToXmlVisitor::visit(HexAstIsExpr expr_)
{
  HexAstIsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstIsExpr>(
    expr,
    "is_expr"
  );

  return expr;
}

HexAstIsNotExpr
AstToXmlVisitor::visit(HexAstIsNotExpr expr_)
{
  HexAstIsNotExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstIsNotExpr>(
    expr,
    "is_not_expr"
  );

  return expr;
}

HexAstLessThanExpr
AstToXmlVisitor::visit(HexAstLessThanExpr expr_)
{
  HexAstLessThanExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstLessThanExpr>(
    expr,
    "lt_expr"
  );

  return expr;
}

HexAstGreaterThanExpr
AstToXmlVisitor::visit(HexAstGreaterThanExpr expr_)
{
  HexAstGreaterThanExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstGreaterThanExpr>(
    expr,
    "gt_expr"
  );

  return expr;
}

HexAstGreaterOrEqualsExpr
AstToXmlVisitor::visit(HexAstGreaterOrEqualsExpr expr_)
{
  HexAstGreaterOrEqualsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstGreaterOrEqualsExpr>(
    expr,
    "ge_expr"
  );

  return expr;
}

HexAstLessOrEqualsExpr
AstToXmlVisitor::visit(HexAstLessOrEqualsExpr expr_)
{
  HexAstLessOrEqualsExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstLessOrEqualsExpr>(
    expr,
    "le_expr"
  );

  return expr;
}

HexAstInExpr
AstToXmlVisitor::visit(HexAstInExpr expr_)
{
  HexAstInExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr(
    expr,
    "in_expr"
  );

  return expr;
}

HexAstNotInExpr
AstToXmlVisitor::visit(HexAstNotInExpr expr_)
{
  HexAstNotInExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstNotInExpr>(
    expr,
    "not_in_expr"
  );

  return expr;
}

HexAstLogicalANDExpr
AstToXmlVisitor::visit(HexAstLogicalANDExpr expr_)
{
  HexAstLogicalANDExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstLogicalANDExpr>(
    expr,
    "and_expr"
  );

  return expr;
}

HexAstLogicalORExpr
AstToXmlVisitor::visit(HexAstLogicalORExpr expr_)
{
  HexAstLogicalORExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstLogicalORExpr>(
    expr,
    "or_expr"
  );

  return expr;
}

HexAstInclusiveRangeExpr
AstToXmlVisitor::visit(HexAstInclusiveRangeExpr expr_)
{
  HexAstInclusiveRangeExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstInclusiveRangeExpr>(
    expr,
    "inclusive_range_expr"
  );

  return expr;
}

HexAstExclusiveRangeExpr
AstToXmlVisitor::visit(HexAstExclusiveRangeExpr expr_)
{
  HexAstExclusiveRangeExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstExclusiveRangeExpr>(
    expr,
    "exclusive_range_expr"
  );

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

HexAstAdditionAssignmentExpr
AstToXmlVisitor::visit(HexAstAdditionAssignmentExpr expr_)
{
  HexAstAdditionAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstAdditionAssignmentExpr>(
    expr,
    "addition_assignment_expr"
  );

  return expr;
}

HexAstSubtractionAssignmentExpr
AstToXmlVisitor::visit(HexAstSubtractionAssignmentExpr expr_)
{
  HexAstSubtractionAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstSubtractionAssignmentExpr>(
    expr,
    "subtraction_assignment_expr"
  );

  return expr;
}

HexAstMultiplicationAssignmentExpr
AstToXmlVisitor::visit(HexAstMultiplicationAssignmentExpr expr_)
{
  HexAstMultiplicationAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstMultiplicationAssignmentExpr>(
    expr,
    "multiplication_assignment_expr"
  );

  return expr;
}

HexAstDivisionAssignmentExpr
AstToXmlVisitor::visit(HexAstDivisionAssignmentExpr expr_)
{
  HexAstDivisionAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstDivisionAssignmentExpr>(
    expr,
    "division_assignment_expr"
  );

  return expr;
}

HexAstModulusAssignmentExpr
AstToXmlVisitor::visit(HexAstModulusAssignmentExpr expr_)
{
  HexAstModulusAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstModulusAssignmentExpr>(
    expr,
    "modulus_assignment_expr"
  );

  return expr;
}

HexAstBitwiseANDAssignmentExpr
AstToXmlVisitor::visit(HexAstBitwiseANDAssignmentExpr expr_)
{
  HexAstBitwiseANDAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseANDAssignmentExpr>(
    expr,
    "bitwise_and_assignment_expr"
  );

  return expr;
}

HexAstBitwiseORAssignmentExpr
AstToXmlVisitor::visit(HexAstBitwiseORAssignmentExpr expr_)
{
  HexAstBitwiseORAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseORAssignmentExpr>(
    expr,
    "bitwise_or_assignment_expr"
  );

  return expr;
}

HexAstBitwiseXORAssignmentExpr
AstToXmlVisitor::visit(HexAstBitwiseXORAssignmentExpr expr_)
{
  HexAstBitwiseXORAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseXORAssignmentExpr>(
    expr,
    "bitwise_xor_assignment_expr"
  );

  return expr;
}

HexAstBitwiseLeftShiftAssignmentExpr
AstToXmlVisitor::visit(HexAstBitwiseLeftShiftAssignmentExpr expr_)
{
  HexAstBitwiseLeftShiftAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseLeftShiftAssignmentExpr>(
    expr,
    "bitwise_left_shift_assignment_expr"
  );

  return expr;
}

HexAstBitwiseRightShiftAssignmentExpr
AstToXmlVisitor::visit(HexAstBitwiseRightShiftAssignmentExpr expr_)
{
  HexAstBitwiseRightShiftAssignmentExpr expr = AstVisitor::visit(expr_);

  this->double_tag_for_binary_expr<HexAstBitwiseRightShiftAssignmentExpr>(
    expr,
    "bitwise_right_shift_assignment_expr"
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

HexAstStringCompositionExpr
AstToXmlVisitor::visit(HexAstStringCompositionExpr expr_)
{
  HexAstStringCompositionExpr expr = AstVisitor::visit(expr_);

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
          expr->paren()->accept(this);
        }
      );
    }
  );

  return expr;
}

HexAstNestedComprehension
AstToXmlVisitor::visit(HexAstNestedComprehension comprehension_)
{
  HexAstNestedComprehension comprehension = AstVisitor::visit(comprehension_);

  this->double_tag(
    "nested_comprehension",
    [this, comprehension]() {

      this->double_tag(
        "nested_comprehension-nested-comprehension",
        [this, comprehension]() {
          comprehension->nested_comprehension()->accept(this);
        }
      );

      this->double_tag(
        "nested_comprehension-targets",
        [this, comprehension]() {
          comprehension->targets()->accept(this);
        }
      );

      this->double_tag(
        "nested_comprehension-sources",
        [this, comprehension]() {
          comprehension->sources()->accept(this);
        }
      );

      if(comprehension->predicate()) {
        this->double_tag(
          "nested_comprehension-predicate",
          [this, comprehension]() {
            comprehension->predicate()->accept(this);
          }
        );
      }

    }
  );

  return comprehension;
}

HexAstExprComprehension
AstToXmlVisitor::visit(HexAstExprComprehension comprehension_)
{
  HexAstExprComprehension comprehension = AstVisitor::visit(comprehension_);

  this->double_tag(
    "expr_comprehension",
    [this, comprehension]() {

      this->double_tag(
        "expr_comprehension-exprs",
        [this, comprehension]() {
          comprehension->exprs()->accept(this);
        }
      );

      this->double_tag(
        "expr_comprehension-targets",
        [this, comprehension]() {
          comprehension->targets()->accept(this);
        }
      );

      this->double_tag(
        "expr_comprehension-sources",
        [this, comprehension]() {
          comprehension->sources()->accept(this);
        }
      );

      if(comprehension->predicate()) {
        this->double_tag(
          "nested_comprehension-predicate",
          [this, comprehension]() {
            comprehension->predicate()->accept(this);
          }
        );
      }

    }
  );

  return comprehension;
}

HexAstGeneratorExpr
AstToXmlVisitor::visit(HexAstGeneratorExpr expr_)
{
  HexAstGeneratorExpr expr = AstVisitor::visit(expr_);

  this->double_tag(
    "generator_expr",
    [this, expr]() {

      this->double_tag(
        "generator_expr-comprehension",
        [this, expr]() {
          expr->comprehension()->accept(this);
        }
      );

    }
  );

  return expr;
}

HexAstParenForm
AstToXmlVisitor::visit(HexAstParenForm paren_)
{
  HexAstParenForm paren = AstVisitor::visit(paren_);

  this->double_tag(
    "paren_form",
    [this, paren]() {
      if(paren->exprs()) {
        paren->exprs()->accept(this);
      }
    }
  );

  return paren;
}

HexAstExplicitListForm
AstToXmlVisitor::visit(HexAstExplicitListForm list_)
{
  HexAstExplicitListForm list = AstVisitor::visit(list_);

  this->double_tag(
    "list_form",
    [this, list]() {
      if(list->elements()) {
        list->elements()->accept(this);
      }
    }
  );

  return list;
}

HexAstImplicitListForm
AstToXmlVisitor::visit(HexAstImplicitListForm list_)
{
  HexAstImplicitListForm list = AstVisitor::visit(list_);

  this->double_tag(
    "list_form",
    [this, list] () {
      list->comprehension()->accept(this);
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
        dict->fields()->accept(this);
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
      dict->comprehension()->accept(this);
    }
  );

  return dict;
}

HexAstObjectForm
AstToXmlVisitor::visit(HexAstObjectForm object_)
{
  HexAstObjectForm object = AstVisitor::visit(object_);

  this->double_tag(
    "object_form",
    [this, object]() {
      object->fields()->accept(this);
    }    
  );

  return object;
}

HexAstExprList
AstToXmlVisitor::visit(HexAstExprList exprlist_)
{
  HexAstExprList exprlist = AstVisitor::visit(exprlist_);

  this->double_tag(
    "exprlist",
    [this, exprlist]() {
      this->iterate<HexAstExpr>(
        exprlist->list()
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
        params->list()
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
        params->list()
      );
    }
  );

  return params;
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

      // args
      if(params->args()) {
        this->double_tag(
          "parameter_list-args",
          [this, params]() {
            params->args()->accept(this);
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

HexAstSimpleArgList
AstToXmlVisitor::visit(HexAstSimpleArgList args_)
{
  HexAstSimpleArgList args = AstVisitor::visit(args_);

  this->double_tag(
    "simple_args_list",
    [this, args]() {
      this->iterate<HexAstSimpleArg>(
        args->list()
      );
    }
  );

  return args;
}

HexAstKeywordArg
AstToXmlVisitor::visit(HexAstKeywordArg arg_)
{
  HexAstKeywordArg arg = AstVisitor::visit(arg_);

  this->double_tag(
    "keyword_arg",
    [this, arg]() {

      this->double_tag(
        "keyword_arg-name",
        [this, arg]() {
          arg->name()->accept(this);
        }
      );

      this->double_tag(
        "keyword_arg-value",
        [this, arg]() {
          arg->value()->accept(this);
        }
      );
    }
  );

  return arg;
}

HexAstKeywordArgList
AstToXmlVisitor::visit(HexAstKeywordArgList args_)
{
  HexAstKeywordArgList args = AstVisitor::visit(args_);

  this->double_tag(
    "keyword_args_list",
    [this, args]() {
      this->iterate<HexAstKeywordArg>(
        args->list()
      );
    }
  );

  return args;
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

      // args
      if(arglist->args_argument()) {
        this->double_tag(
          "arg_list-args_argument",
          [this, arglist]() {
            arglist->args_argument()->accept(this);
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

      // kwargs
      if(arglist->kwargs_argument()) {
        this->double_tag(
          "arg_list-kwargs_argument",
          [this, arglist]() {
            arglist->kwargs_argument()->accept(this);
          }
        );
      }

    }
  );

  return arglist;
}

HexAstFieldDef
AstToXmlVisitor::visit(HexAstFieldDef field_)
{
  HexAstFieldDef field = AstVisitor::visit(field_);

  this->double_tag(
    "field_def",
    [this, field]() {

      // decorators
      if(field->decorators()) {
        this->double_tag(
          "field_def-decorators",
          [this, field]() {
            field->decorators()->accept(this);
          }
        );
      }

      // name
      this->double_tag(
        "field_def-name",
        [this, field]() {
          field->name()->accept(this);
        }
      );

      // val
      this->double_tag(
        "field_def-value",
        [this, field]() {
          field->value()->accept(this);
        }
      );
    }
  );

  return field;
}

HexAstFieldDefList
AstToXmlVisitor::visit(HexAstFieldDefList fields_)
{
  HexAstFieldDefList fields = AstVisitor::visit(fields_);

  this->double_tag(
    "field_def_list",
    [this, fields]() {
      this->iterate<HexAstFieldDef>(
        fields->list()
      );
    }
  );

  return fields;
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
AstToXmlVisitor::visit(HexAstKeyValuePairList pairs_)
{
  HexAstKeyValuePairList pairs = AstVisitor::visit(pairs_);

  this->double_tag(
    "key_value_pair_list",
    [this, pairs]() {
      this->iterate<HexAstKeyValuePair>(
        pairs->list()
      );
    }
  );

  return pairs;
}

HexAstAttributeValuePair
AstToXmlVisitor::visit(HexAstAttributeValuePair pair_)
{
  HexAstAttributeValuePair pair = AstVisitor::visit(pair_);

  this->double_tag(
    "attribute_value_pair",
    [this, pair]() {

      this->double_tag(
        "attributes_value_pair-attribute",
        [this, pair]() {
          pair->attribute()->accept(this);
        }
      );

      this->double_tag(
        "attributes_value_pair-value",
        [this, pair]() {
          pair->value()->accept(this);
        }
      );

    }
  );

  return pair;
}

HexAstAttributeValuePairList
AstToXmlVisitor::visit(HexAstAttributeValuePairList pairs_)
{
  HexAstAttributeValuePairList pairs = AstVisitor::visit(pairs_);

  this->double_tag(
    "attribute_value_pair_list",
    [this, pairs]() {
      this->iterate<HexAstAttributeValuePair>(
        pairs->list()
      );
    }
  );

  return pairs;
}

HexAstDecorator
AstToXmlVisitor::visit(HexAstDecorator decorator_)
{
  HexAstDecorator decorator = AstVisitor::visit(decorator_);

  this->double_tag(
    "decorator",
    [this, decorator]() {

      this->double_tag(
        "decorator-name",
        [this, decorator]() {
          decorator->name()->accept(this);
        }
      );

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
        decorators->list()
      );
    }
  );

  return decorators;
}

HexAstAssignmentStmt
AstToXmlVisitor::visit(HexAstAssignmentStmt stmt_)
{
  HexAstAssignmentStmt stmt = AstVisitor::visit(stmt_);

  char *feature = NULL;
  switch(stmt->feature()->feature())
  {
    case HEX_AST_ASSIGNMENT_FEATURE_NONE:
      feature = "type=\"none\"";
      break;
    case HEX_AST_ASSIGNMENT_FEATURE_DEFER:
      feature = "type=\"defer\"";
      break;
    default:
      break;
  }

  this->double_tag(
    "assignment_stmt",
    feature,
    [this, stmt]() {

      this->double_tag(
        "assignment_stmt-target",
        [this, stmt]() {
          stmt->target()->accept(this);
        }
      );

      this->double_tag(
        "assignment_stmt-source",
        [this, stmt]() {
          stmt->source()->accept(this);
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

HexAstRelativeUsingStmt
AstToXmlVisitor::visit(HexAstRelativeUsingStmt stmt_)
{
  HexAstRelativeUsingStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "using_stmt_relative",
    [this, stmt]() {

      if(stmt->targets()) {
        this->double_tag(
          "using_stmt_relative-targets",
          [this, stmt]() {
            stmt->targets()->accept(this);
          }
        );
      }

      this->double_tag(
        "using_stmt_relative-source",
        [this, stmt]() {
          stmt->source()->accept(this);
        }
      );

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

HexAstAbsoluteUsingStmt
AstToXmlVisitor::visit(HexAstAbsoluteUsingStmt stmt_)
{
  HexAstAbsoluteUsingStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "using_stmt_direct",
    [this, stmt]() {

      this->double_tag(
        "using_stmt_direct-source",
        [this, stmt]() {
          stmt->source()->accept(this);
        }
      );

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

HexAstElifStmt
AstToXmlVisitor::visit(HexAstElifStmt stmt_)
{
  HexAstElifStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "elif_stmt",
    [this, stmt]() {

      this->double_tag(
        "elif_stmt-predicate",
        [this, stmt]() {
          stmt->predicate()->accept(this);
        }
      );

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
        stmts->list()
      );
    }
  );

  return stmts;
}

HexAstIfStmt
AstToXmlVisitor::visit(HexAstIfStmt stmt_)
{
  HexAstIfStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "if_stmt",
    [this, stmt]() {

      this->double_tag(
        "if_stmt-predicate",
        [this, stmt]() {
          stmt->predicate()->accept(this);
        }
      );

      this->double_tag(
        "if_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

      if(stmt->elif_stmts()) {
        this->double_tag(
          "if_stmt-elif_stmts",
          [this, stmt]() {
            stmt->elif_stmts()->accept(this);
          }
        );
      }

      if(stmt->else_stmts()) {
        this->double_tag(
          "if_stmt-else_stmts",
          [this, stmt]() {
            stmt->else_stmts()->accept(this);
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

      this->double_tag(
        "for_stmt-targets",
        [this, stmt]() {
          stmt->targets()->accept(this);
        }
      );

      this->double_tag(
        "for_stmt-sources",
        [this, stmt]() {
          stmt->sources()->accept(this);
        }
      );

      if(stmt->predicate()) {
        this->double_tag(
          "for_stmt-predicate",
          [this, stmt]() {
            stmt->predicate()->accept(this);
          }
        );
      }

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

      this->double_tag(
        "with_stmt-expr",
        [this, stmt]() {
          stmt->expr()->accept(this);
        }
      );

      if(stmt->alias()) {
        this->double_tag(
          "with_stmt-alias",
          [this, stmt]() {
            stmt->alias()->accept(this);
          }
        );
      }

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

      this->double_tag(
        "lock_stmt-target",
        [this, stmt]() {
          stmt->target()->accept(this);
        }
      );

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

      this->double_tag(
        "while_stmt-predicate",
        [this, stmt]() {
          stmt->predicate()->accept(this);
        }
      );

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

      if(stmt->types()) {
        this->double_tag(
          "catch_stmt-types",
          [this, stmt]() {
            stmt->types()->accept(this);
          }
        );

        if(stmt->alias()) {
          this->double_tag(
            "catch_stmt-alias",
            [this, stmt]() {
              stmt->alias()->accept(this);
            }
          );
        }
      }

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
        stmts->list()
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

      this->double_tag(
        "try_stmt-stmts",
        [this, stmt]() {
          stmt->stmts()->accept(this);
        }
      );

      this->double_tag(
        "try_stmt-catch_stmts",
        [this, stmt]() {
          stmt->catch_stmt_group()->accept(this);
        }
      );

      if(stmt->else_stmts()) {
        this->double_tag(
          "try_stmt-else_stmts",
          [this, stmt]() {
            stmt->else_stmts()->accept(this);
          }
        );
      }

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

      if(def->decorators()) {
        this->double_tag(
          "class_def-decorators",
          [this, def]() {
            def->decorators()->accept(this);
          }
        );
      }

      this->double_tag(
        "class_def-name",
        [this, def]() {
          def->name()->accept(this);
        }
      );

      if(def->parents()) {
        this->double_tag(
          "class_def-parents",
          [this, def]() {
            def->parents()->accept(this);
          }
        );
      }

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

HexAstSimpleLambda
AstToXmlVisitor::visit(HexAstSimpleLambda lambda_)
{
  HexAstSimpleLambda lambda = AstVisitor::visit(lambda_);

  this->double_tag(
    "lambda_simple",
    [this, lambda]() {

      if(lambda->params()) {
        this->double_tag(
          "lambda_simple-params",
          [this, lambda]() {
            lambda->params()->accept(this);
          }
        );
      }

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

HexAstComplexLambda
AstToXmlVisitor::visit(HexAstComplexLambda lambda_)
{
  HexAstComplexLambda lambda = AstVisitor::visit(lambda_);

  this->double_tag(
    "lambda_complex",
    [this, lambda]() {

      if(lambda->params()) {
        this->double_tag(
          "lambda_complex-params",
          [this, lambda]() {
            lambda->params()->accept(this);
          }
        );
      }

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
        stmt->list()
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
        stmt->list()
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
    // case AST_TASK_STATE_STOP:
    //   s = "stop";
    //   break;
    default:
      break;
  }

  this->double_tag_simple(
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
    default:
      break;
  }

  HEX_ASSERT(s);

  this->double_tag_simple(
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

      this->double_tag(
        "conditional_clause-preposition",
        [this, clause]() {
          clause->preposition()->accept(this);
        }
      );

      this->double_tag(
        "conditional_clause-exprs",
        [this, clause]() {
          clause->exprs()->accept(this);
        }
      );

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

HexAstStartClause
AstToXmlVisitor::visit(HexAstStartClause clause_)
{
  HexAstStartClause clause = AstVisitor::visit(clause_);

  this->double_tag(
    "start_clause",
    [this, clause]() {

      this->double_tag(
        "start_clause-tasks",
        [this, clause]() {
          clause->tasks()->accept(this);
        }
      );

      if(clause->alias()) {
        this->double_tag(
          "start_clause-alias",
          [this, clause]() {
            clause->alias()->accept(this);
          }
        );
      }

      if(clause->condition_clause()) {
        this->double_tag(
          "start_clause-condition-clause",
          [this, clause]() {
            clause->condition_clause()->accept(this);
          }
        );
      }

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

      this->double_tag(
        "pause_clause-tasks",
        [this, clause]() {
          clause->tasks()->accept(this);
        }
      );

      this->double_tag(
        "pause_clause-condition-clause",
        [this, clause]() {
          clause->condition_clause()->accept(this);
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

      this->double_tag(
        "resume_clause-tasks",
        [this, clause]() {
          clause->tasks()->accept(this);
        }
      );

      this->double_tag(
        "resume_clause-condition-clause",
        [this, clause]() {
          clause->condition_clause()->accept(this);
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

      this->double_tag(
        "cancel_clause-tasks",
        [this, clause]() {
          clause->tasks()->accept(this);
        }
      );

      this->double_tag(
        "cancel_clause-condition-clause",
        [this, clause]() {
          clause->condition_clause()->accept(this);
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

      this->double_tag(
        "stop_clause-tasks",
        [this, clause]() {
          clause->tasks()->accept(this);
        }
      );

      this->double_tag(
        "stop_clause-condition-clause",
        [this, clause]() {
          clause->condition_clause()->accept(this);
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
        def->list()
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

      if(stmt->return_vals()) {
        this->double_tag(
          "return_stmt-return_vals",
          [this, stmt]() {
            stmt->return_vals()->accept(this);
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

  this->double_tag("break_stmt");

  return stmt;
}

HexAstContinueStmt
AstToXmlVisitor::visit(HexAstContinueStmt stmt_)
{
  HexAstContinueStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag("continue_stmt");

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
        "raise_stmt-target",
        [this, stmt]() {
          stmt->target()->accept(this);
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

HexAstSimpleIfStmt
AstToXmlVisitor::visit(HexAstSimpleIfStmt stmt_)
{
  HexAstSimpleIfStmt stmt = AstVisitor::visit(stmt_);

  this->double_tag(
    "simple_if_stmt",
    [this, stmt]() {

      this->double_tag(
        "simple_if_stmt-predicate",
        [this, stmt]() {
          stmt->predicate()->accept(this);
        }
      );

      this->double_tag(
        "simple_if_stmt-stmt",
        [this, stmt]() {
          stmt->stmt()->accept(this);
        }
      );

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
        stmts->list()
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