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

#include <stdio.h>
#include <string>
#include "parser_xml_test_base.h"
#include "../../base/unittest.h"
#include "../../base/memory.h"
#include "../../base/assert.h"
#include "../ast/ast.h"
#include "../hex_parser.h"
#include "../ast/visitor/ast_to_xml_visitor.h"


/***************************************************
 * Order of expression precedence.
 * Precedence decreases as list goes down.
 *
 * The order of the list should the REVERSE
 * of the order of these tokens defined in parser.y
 *
 * primary
 * power
 * unary expr
 * multiplicative expr
 * additive expr
 * shift expr
 * and expr
 * xor expr
 * or expr
 * comparison expr
 * pseudo expr
 ***************************************************/


class HexParserExprPrecedenceTest : public HexParserXmlTestBase {};


TEST_F(HexParserExprPrecedenceTest, UnaryExpr_vs_PowerExpr)
{
  // -(5 ** 2)
  test(
    "-5 ** 2;",
    wrap_single_expr(
      "<negative_expr>"
        "<power_expr>"
          "<power_expr-left>"
            "<integer_literal>5<integer_literal/>"
          "<power_expr-left/>"
          "<power_expr-right>"
            "<integer_literal>2<integer_literal/>"
          "<power_expr-right/>"
        "<power_expr/>"
      "<negative_expr/>"
    )
  );

  test(
    "(-5) ** 2;",
    wrap_single_expr(
      "<power_expr>"
        "<power_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<negative_expr>"
                "<integer_literal>5<integer_literal/>"
              "<negative_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<power_expr-left/>"
        "<power_expr-right>"
          "<integer_literal>2<integer_literal/>"
        "<power_expr-right/>"
      "<power_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, MultiplicativeExpr_vs_UnaryExpr)
{
  // 1 * (-2)
  test(
    "1 * -2;",
    wrap_single_expr(
      "<multiply_expr>"
        "<multiply_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<multiply_expr-left/>"
        "<multiply_expr-right>"
          "<negative_expr>"
            "<integer_literal>2<integer_literal/>"
          "<negative_expr/>"
        "<multiply_expr-right/>"
      "<multiply_expr/>"
    )
  );

  // (5++) * 2
  test(
    "5++ * 2;",
    wrap_single_expr(
      "<multiply_expr>"
        "<multiply_expr-left>"
          "<increment_expr>"
            "<integer_literal>5<integer_literal/>"
          "<increment_expr/>"
        "<multiply_expr-left/>"
        "<multiply_expr-right>"
          "<integer_literal>2<integer_literal/>"
        "<multiply_expr-right/>"
      "<multiply_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, AdditiveExpr_vs_MultiplicativeExpr)
{
	// 1 + (2 * 3)
  test(
    "1 + 2 * 3;",
    wrap_single_expr(
      "<add_expr>"
        "<add_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<add_expr-left/>"
        "<add_expr-right>"
          "<multiply_expr>"
            "<multiply_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<multiply_expr-left/>"
            "<multiply_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<multiply_expr-right/>"
          "<multiply_expr/>"
        "<add_expr-right/>"
      "<add_expr/>"
    )
  );

  // (1 % 2) - 3
  test(
    "1 % 2 - 3;",
    wrap_single_expr(
      "<minus_expr>"
        "<minus_expr-left>"
          "<modulus_expr>"
            "<modulus_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<modulus_expr-left/>"
            "<modulus_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<modulus_expr-right/>"
          "<modulus_expr/>"
        "<minus_expr-left/>"
        "<minus_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<minus_expr-right/>"
      "<minus_expr/>"
    )
  );

  // 3 * (2 - 1)
  test(
    "3 * (2 - 1);",
    wrap_single_expr(
      "<multiply_expr>"
        "<multiply_expr-left>"
          "<integer_literal>3<integer_literal/>"
        "<multiply_expr-left/>"
        "<multiply_expr-right>"
          "<paren_form>"
            "<exprlist>"
              "<minus_expr>"
                "<minus_expr-left>"
                  "<integer_literal>2<integer_literal/>"
                "<minus_expr-left/>"
                "<minus_expr-right>"
                  "<integer_literal>1<integer_literal/>"
                "<minus_expr-right/>"
              "<minus_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<multiply_expr-right/>"
      "<multiply_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, ShiftExpr_vs_AdditiveExpr)
{
  // (1 + 2) << 3
  test(
    "1 + 2 << 3;",
    wrap_single_expr(
      "<bitwise_shift_left_expr>"
        "<bitwise_shift_left_expr-left>"
          "<add_expr>"
            "<add_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<add_expr-left/>"
            "<add_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<add_expr-right/>"
          "<add_expr/>"
        "<bitwise_shift_left_expr-left/>"
        "<bitwise_shift_left_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<bitwise_shift_left_expr-right/>"
      "<bitwise_shift_left_expr/>"
    )
  );

  // 2 >> (1 - 3)
  test(
    "2 >> 1 - 3;",
    wrap_single_expr(
      "<bitwise_shift_right_expr>"
        "<bitwise_shift_right_expr-left>"
          "<integer_literal>2<integer_literal/>"
        "<bitwise_shift_right_expr-left/>"
        "<bitwise_shift_right_expr-right>"
          "<minus_expr>"
            "<minus_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<minus_expr-left/>"
            "<minus_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<minus_expr-right/>"
          "<minus_expr/>"
        "<bitwise_shift_right_expr-right/>"
      "<bitwise_shift_right_expr/>"
    )
  );

  // (2 << 3) - 5
  test(
    "(2 << 3) - 5;",
    wrap_single_expr(
      "<minus_expr>"
        "<minus_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<bitwise_shift_left_expr>"
                "<bitwise_shift_left_expr-left>"
                  "<integer_literal>2<integer_literal/>"
                "<bitwise_shift_left_expr-left/>"
                "<bitwise_shift_left_expr-right>"
                  "<integer_literal>3<integer_literal/>"
                "<bitwise_shift_left_expr-right/>"
              "<bitwise_shift_left_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<minus_expr-left/>"
        "<minus_expr-right>"
          "<integer_literal>5<integer_literal/>"
        "<minus_expr-right/>"
      "<minus_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, LogicAndExpr_vs_ShiftExpr)
{
  // 1 and (2 << 3)
  test(
    "1 and 2 << 3;",
    wrap_single_expr(
      "<and_expr>"
        "<and_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<and_expr-left/>"
        "<and_expr-right>"
          "<bitwise_shift_left_expr>"
            "<bitwise_shift_left_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_shift_left_expr-left/>"
            "<bitwise_shift_left_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_shift_left_expr-right/>"
          "<bitwise_shift_left_expr/>"
        "<and_expr-right/>"
      "<and_expr/>"
    )
  );

  // (1 << 2) and 3
  test(
    "1 << 2 and 3;",
    wrap_single_expr(
      "<and_expr>"
        "<and_expr-left>"
          "<bitwise_shift_left_expr>"
            "<bitwise_shift_left_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<bitwise_shift_left_expr-left/>"
            "<bitwise_shift_left_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_shift_left_expr-right/>"
          "<bitwise_shift_left_expr/>"
        "<and_expr-left/>"
        "<and_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<and_expr-right/>"
      "<and_expr/>"
    )
  );

  // (1 and 2) << 3
  test(
    "(1 and 2) << 3;",
    wrap_single_expr(
      "<bitwise_shift_left_expr>"
        "<bitwise_shift_left_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<and_expr>"
                "<and_expr-left>"
                  "<integer_literal>1<integer_literal/>"
                "<and_expr-left/>"
                "<and_expr-right>"
                  "<integer_literal>2<integer_literal/>"
                "<and_expr-right/>"
              "<and_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<bitwise_shift_left_expr-left/>"
        "<bitwise_shift_left_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<bitwise_shift_left_expr-right/>"
      "<bitwise_shift_left_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, BitwiseXor_vs_LogicAndExpr)
{
  // (1 and 2) ^ 3
  test(
    "1 and 2 ^ 3;",
    wrap_single_expr(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<and_expr>"
            "<and_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<and_expr-left/>"
            "<and_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<and_expr-right/>"
          "<and_expr/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );

  // 1 ^ (2 and 3)
  test(
    "1 ^ 2 and 3;",
    wrap_single_expr(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<and_expr>"
            "<and_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<and_expr-left/>"
            "<and_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<and_expr-right/>"
          "<and_expr/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );

  // 1 and (2 ^ 3)
  test(
    "1 and (2 ^ 3);",
    wrap_single_expr(
      "<and_expr>"
        "<and_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<and_expr-left/>"
        "<and_expr-right>"
          "<paren_form>"
            "<exprlist>"
              "<bitwise_xor_expr>"
                "<bitwise_xor_expr-left>"
                  "<integer_literal>2<integer_literal/>"
                "<bitwise_xor_expr-left/>"
                "<bitwise_xor_expr-right>"
                  "<integer_literal>3<integer_literal/>"
                "<bitwise_xor_expr-right/>"
              "<bitwise_xor_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<and_expr-right/>"
      "<and_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, LogicOrExpr_vs_BitwiseXorExpr)
{
  // 2 or (3 ^ 4)
  test(
    "2 or 3 ^ 4;",
    wrap_single_expr(
      "<or_expr>"
        "<or_expr-left>"
          "<integer_literal>2<integer_literal/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<bitwise_xor_expr>"
            "<bitwise_xor_expr-left>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_xor_expr-left/>"
            "<bitwise_xor_expr-right>"
              "<integer_literal>4<integer_literal/>"
            "<bitwise_xor_expr-right/>"
          "<bitwise_xor_expr/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );

  // (2 ^ 3) or 4
  test(
    "2 ^ 3 or 4;",
    wrap_single_expr(
      "<or_expr>"
        "<or_expr-left>"
          "<bitwise_xor_expr>"
            "<bitwise_xor_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_xor_expr-left/>"
            "<bitwise_xor_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_xor_expr-right/>"
          "<bitwise_xor_expr/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<integer_literal>4<integer_literal/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );

  // (2 or 3) ^ 4
  test(
    "(2 or 3) ^ 4;",
    wrap_single_expr(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<or_expr>"
                "<or_expr-left>"
                  "<integer_literal>2<integer_literal/>"
                "<or_expr-left/>"
                "<or_expr-right>"
                  "<integer_literal>3<integer_literal/>"
                "<or_expr-right/>"
              "<or_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<integer_literal>4<integer_literal/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, ComparisonExpr_vs_LogicOrExpr)
{
  // (2 or 3) is 2
  test(
    "2 or 3 is 2;",
    wrap_single_expr(
      "<is_expr>"
        "<is_expr-left>"
          "<or_expr>"
            "<or_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<or_expr-left/>"
            "<or_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<or_expr-right/>"
          "<or_expr/>"
        "<is_expr-left/>"
        "<is_expr-right>"
          "<integer_literal>2<integer_literal/>"
        "<is_expr-right/>"
      "<is_expr/>"
    )
  );

  // 5 >= (2 or 5)
  test(
    "5 >= 2 or 5;",
    wrap_single_expr(
      "<ge_expr>"
        "<ge_expr-left>"
          "<integer_literal>5<integer_literal/>"
        "<ge_expr-left/>"
        "<ge_expr-right>"
          "<or_expr>"
            "<or_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<or_expr-left/>"
            "<or_expr-right>"
              "<integer_literal>5<integer_literal/>"
            "<or_expr-right/>"
          "<or_expr/>"
        "<ge_expr-right/>"
      "<ge_expr/>"
    )
  );

  // (2 <= 3) or 5
  test(
    "(2 <= 3) or 5;",
    wrap_single_expr(
      "<or_expr>"
        "<or_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<le_expr>"
                "<le_expr-left>"
                  "<integer_literal>2<integer_literal/>"
                "<le_expr-left/>"
                "<le_expr-right>"
                  "<integer_literal>3<integer_literal/>"
                "<le_expr-right/>"
              "<le_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<integer_literal>5<integer_literal/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, PseudoAssignmentExpr_vs_ComparisonExpr)
{
  // a += (3 != 2)
  test(
    "a += 3 != 2;",
    wrap_single_expr(
      "<pseudo_plus>"
        "<pseudo_plus-left>"
          "<identifier>a<identifier/>"
        "<pseudo_plus-left/>"
        "<pseudo_plus-right>"
          "<not_equal_expr>"
            "<not_equal_expr-left>"
              "<integer_literal>3<integer_literal/>"
            "<not_equal_expr-left/>"
            "<not_equal_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<not_equal_expr-right/>"
          "<not_equal_expr/>"
        "<pseudo_plus-right/>"
      "<pseudo_plus/>"
    )
  );

  // (b *= 2) >> 10
  test(
    "(b *= 2) >> 10;",
    wrap_single_expr(
      "<bitwise_shift_right_expr>"
        "<bitwise_shift_right_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<pseudo_multiply>"
                "<pseudo_multiply-left>"
                  "<identifier>b<identifier/>"
                "<pseudo_multiply-left/>"
                "<pseudo_multiply-right>"
                  "<integer_literal>2<integer_literal/>"
                "<pseudo_multiply-right/>"
              "<pseudo_multiply/>"
            "<exprlist/>"
          "<paren_form/>"
        "<bitwise_shift_right_expr-left/>"
        "<bitwise_shift_right_expr-right>"
          "<integer_literal>10<integer_literal/>"
        "<bitwise_shift_right_expr-right/>"
      "<bitwise_shift_right_expr/>"
    )
  );
}