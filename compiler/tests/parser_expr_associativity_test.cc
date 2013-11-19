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
#include "../visitor/ast_to_xml_visitor.h"


/***************************************************
 * HEX expression associativity
 *
 * LR: left to right
 * RL: right to left
 * 
 * primary --------------- LR
 * power ----------------- LR
 * unary expr ------------ LR
 * multiplicative expr --- LR
 * additive expr --------- LR
 * shift expr ------------ LR
 * and expr -------------- LR
 * xor expr -------------- LR
 * or expr --------------- LR
 * comparison expr ------- LR
 * pseudo expr ----------- RL
 ***************************************************/


class HexParserExprAssociativityTest : public HexParserXmlTestBase {};


TEST_F(HexParserExprAssociativityTest, TestUnaryExprAssociativity)
{
  // ~ (not (not ( (-a) ++) ? ) )
  test(
    "~ not not -a++?;",
    wrap_single_expr(
      "<bitwise_not_expr>"
        "<not_expr>"
          "<not_expr>"
            "<existential_expr>"
              "<increment_expr>"
                "<negative_expr>"
                  "<identifier>a<identifier/>"
                "<negative_expr/>"
              "<increment_expr/>"
            "<existential_expr/>"
          "<not_expr/>"
        "<not_expr/>"
      "<bitwise_not_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestAdditiveExprAssociativity)
{
  // ( a + b ) - c
  test(
    "a + b - c;",
    wrap_single_expr(
      "<minus_expr>"
        "<minus_expr-left>"
          "<add_expr>"
            "<add_expr-left>"
              "<identifier>a<identifier/>"
            "<add_expr-left/>"
            "<add_expr-right>"
              "<identifier>b<identifier/>"
            "<add_expr-right/>"
          "<add_expr/>"
        "<minus_expr-left/>"
        "<minus_expr-right>"
          "<identifier>c<identifier/>"
        "<minus_expr-right/>"
      "<minus_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestMultiplicativeExprAssociativity)
{
  // ( ( a * b ) / c ) % d
  test(
    "a * b / c % d;",
    wrap_single_expr(
      "<modulus_expr>"
        "<modulus_expr-left>"
          "<divide_expr>"
            "<divide_expr-left>"
              "<multiply_expr>"
                "<multiply_expr-left>"
                  "<identifier>a<identifier/>"
                "<multiply_expr-left/>"
                "<multiply_expr-right>"
                  "<identifier>b<identifier/>"
                "<multiply_expr-right/>"
              "<multiply_expr/>"
            "<divide_expr-left/>"
            "<divide_expr-right>"
              "<identifier>c<identifier/>"
            "<divide_expr-right/>"
          "<divide_expr/>"
        "<modulus_expr-left/>"
        "<modulus_expr-right>"
          "<identifier>d<identifier/>"
        "<modulus_expr-right/>"
      "<modulus_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestBitwiseShiftExprAssociativity)
{
  // ( a << b ) >> c
  test(
    "a << b >> c;",
    wrap_single_expr(
      "<bitwise_shift_right_expr>"
        "<bitwise_shift_right_expr-left>"
          "<bitwise_shift_left_expr>"
            "<bitwise_shift_left_expr-left>"
              "<identifier>a<identifier/>"
            "<bitwise_shift_left_expr-left/>"
            "<bitwise_shift_left_expr-right>"
              "<identifier>b<identifier/>"
            "<bitwise_shift_left_expr-right/>"
          "<bitwise_shift_left_expr/>"
        "<bitwise_shift_right_expr-left/>"
        "<bitwise_shift_right_expr-right>"
          "<identifier>c<identifier/>"
        "<bitwise_shift_right_expr-right/>"
      "<bitwise_shift_right_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestLogicAndExprAssociativity)
{
  // ( a and b ) and c
  test(
    "a and b and c;",
    wrap_single_expr(
      "<and_expr>"
        "<and_expr-left>"
          "<and_expr>"
            "<and_expr-left>"
              "<identifier>a<identifier/>"
            "<and_expr-left/>"
            "<and_expr-right>"
              "<identifier>b<identifier/>"
            "<and_expr-right/>"
          "<and_expr/>"
        "<and_expr-left/>"
        "<and_expr-right>"
          "<identifier>c<identifier/>"
        "<and_expr-right/>"
      "<and_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestBitwiseXorExprAssociativity)
{
  // ( a ^ b ) ^ c
  test(
    "a ^ b ^ c;",
    wrap_single_expr(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<bitwise_xor_expr>"
            "<bitwise_xor_expr-left>"
              "<identifier>a<identifier/>"
            "<bitwise_xor_expr-left/>"
            "<bitwise_xor_expr-right>"
              "<identifier>b<identifier/>"
            "<bitwise_xor_expr-right/>"
          "<bitwise_xor_expr/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<identifier>c<identifier/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestLogicOrExprAssociativity)
{
  // ( a or b ) or c
  test(
    "a or b or c;",
    wrap_single_expr(
      "<or_expr>"
        "<or_expr-left>"
          "<or_expr>"
            "<or_expr-left>"
              "<identifier>a<identifier/>"
            "<or_expr-left/>"
            "<or_expr-right>"
              "<identifier>b<identifier/>"
            "<or_expr-right/>"
          "<or_expr/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<identifier>c<identifier/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestComparisonExprAssociativity)
{
  // ( ( (a is b) is not c ) in d ) not in e
  test(
    "a is b is not c in d not in e;",
    wrap_single_expr(
      "<not_in_expr>"
        "<not_in_expr-left>"
          "<in_expr>"
            "<in_expr-left>"
              "<is_not_expr>"
                "<is_not_expr-left>"
                  "<is_expr>"
                    "<is_expr-left>"
                      "<identifier>a<identifier/>"
                    "<is_expr-left/>"
                    "<is_expr-right>"
                      "<identifier>b<identifier/>"
                    "<is_expr-right/>"
                  "<is_expr/>"
                "<is_not_expr-left/>"
                "<is_not_expr-right>"
                  "<identifier>c<identifier/>"
                "<is_not_expr-right/>"
              "<is_not_expr/>"
            "<in_expr-left/>"
            "<in_expr-right>"
              "<identifier>d<identifier/>"
            "<in_expr-right/>"
          "<in_expr/>"
        "<not_in_expr-left/>"
        "<not_in_expr-right>"
          "<identifier>e<identifier/>"
        "<not_in_expr-right/>"
      "<not_in_expr/>"
    )
  );

  test(
    "a == b != c > d >= e < f <= g;",
    wrap_single_expr(
      "<le_expr>"
        "<le_expr-left>"
          "<lt_expr>"
            "<lt_expr-left>"
              "<ge_expr>"
                "<ge_expr-left>"
                  "<gt_expr>"
                    "<gt_expr-left>"
                      "<not_equal_expr>"
                        "<not_equal_expr-left>"
                          "<equals_expr>"
                            "<equals_expr-left>"
                              "<identifier>a<identifier/>"
                            "<equals_expr-left/>"
                            "<equals_expr-right>"
                              "<identifier>b<identifier/>"
                            "<equals_expr-right/>"
                          "<equals_expr/>"
                        "<not_equal_expr-left/>"
                        "<not_equal_expr-right>"
                          "<identifier>c<identifier/>"
                        "<not_equal_expr-right/>"
                      "<not_equal_expr/>"
                    "<gt_expr-left/>"
                    "<gt_expr-right>"
                      "<identifier>d<identifier/>"
                    "<gt_expr-right/>"
                  "<gt_expr/>"
                "<ge_expr-left/>"
                "<ge_expr-right>"
                  "<identifier>e<identifier/>"
                "<ge_expr-right/>"
              "<ge_expr/>"
            "<lt_expr-left/>"
            "<lt_expr-right>"
              "<identifier>f<identifier/>"
            "<lt_expr-right/>"
          "<lt_expr/>"
        "<le_expr-left/>"
        "<le_expr-right>"
          "<identifier>g<identifier/>"
        "<le_expr-right/>"
      "<le_expr/>"
    )
  );
}

TEST_F(HexParserExprAssociativityTest, TestPseudoAssignmentExprAssociativity)
{
  // a += ( b -= ( c *= ( d /= ( e %= f ) ) ) )
  test(
    "a += b -= c *= d /= e %= f;",
    wrap_single_expr(
      "<pseudo_plus>"
        "<pseudo_plus-left>"
          "<identifier>a<identifier/>"
        "<pseudo_plus-left/>"
        "<pseudo_plus-right>"
          "<pseudo_minus>"
            "<pseudo_minus-left>"
              "<identifier>b<identifier/>"
            "<pseudo_minus-left/>"
            "<pseudo_minus-right>"
              "<pseudo_multiply>"
                "<pseudo_multiply-left>"
                  "<identifier>c<identifier/>"
                "<pseudo_multiply-left/>"
                "<pseudo_multiply-right>"
                  "<pseudo_divide>"
                    "<pseudo_divide-left>"
                      "<identifier>d<identifier/>"
                    "<pseudo_divide-left/>"
                    "<pseudo_divide-right>"
                      "<pseudo_modulus>"
                        "<pseudo_modulus-left>"
                          "<identifier>e<identifier/>"
                        "<pseudo_modulus-left/>"
                        "<pseudo_modulus-right>"
                          "<identifier>f<identifier/>"
                        "<pseudo_modulus-right/>"
                      "<pseudo_modulus/>"
                    "<pseudo_divide-right/>"
                  "<pseudo_divide/>"
                "<pseudo_multiply-right/>"
              "<pseudo_multiply/>"
            "<pseudo_minus-right/>"
          "<pseudo_minus/>"
        "<pseudo_plus-right/>"
      "<pseudo_plus/>"
    )
  );

  // a &= ( b |= ( c ^= ( d <<= ( e >>= f ) ) ) )
  test(
    "a &= b |= c ^= d <<= e >>= f;",
    wrap_single_expr(
      "<pseudo_bitwise_and>"
        "<pseudo_bitwise_and-left>"
          "<identifier>a<identifier/>"
        "<pseudo_bitwise_and-left/>"
        "<pseudo_bitwise_and-right>"
          "<pseudo_bitwise_or>"
            "<pseudo_bitwise_or-left>"
              "<identifier>b<identifier/>"
            "<pseudo_bitwise_or-left/>"
            "<pseudo_bitwise_or-right>"
              "<pseudo_bitwise_xor>"
                "<pseudo_bitwise_xor-left>"
                  "<identifier>c<identifier/>"
                "<pseudo_bitwise_xor-left/>"
                "<pseudo_bitwise_xor-right>"
                  "<pseudo_bitwise_left_shift>"
                    "<pseudo_bitwise_left_shift-left>"
                      "<identifier>d<identifier/>"
                    "<pseudo_bitwise_left_shift-left/>"
                    "<pseudo_bitwise_left_shift-right>"
                      "<pseudo_bitwise_right_shift>"
                        "<pseudo_bitwise_right_shift-left>"
                          "<identifier>e<identifier/>"
                        "<pseudo_bitwise_right_shift-left/>"
                        "<pseudo_bitwise_right_shift-right>"
                          "<identifier>f<identifier/>"
                        "<pseudo_bitwise_right_shift-right/>"
                      "<pseudo_bitwise_right_shift/>"
                    "<pseudo_bitwise_left_shift-right/>"
                  "<pseudo_bitwise_left_shift/>"
                "<pseudo_bitwise_xor-right/>"
              "<pseudo_bitwise_xor/>"
            "<pseudo_bitwise_or-right/>"
          "<pseudo_bitwise_or/>"
        "<pseudo_bitwise_and-right/>"
      "<pseudo_bitwise_and/>"
    )
  );
}
