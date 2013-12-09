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
#include "../ast/ast.h"
#include "../hex_parser.h"
#include "../visitor/ast_to_xml_visitor.h"
#include "../../base/unittest.h"
#include "../../base/memory.h"
#include "../../base/assert.h"


/***********************************************************************************************************
 *
 * |-------------------------------------------------------------------------------------------------------|
 * |                   HEX expression precedence (precedence decreases as list goes down)                  |
 * |-------------------------------------------------------------------------------------------------------|
 * | Description                                       |    Operator                                       |
 * |---------------------------------------------------|---------------------------------------------------|
 * | identifiers, literals, tuples, list, dict         |     (), [], {}                                    |
 * | subscription, slicing, call, attribute reference  |                                                   |
 * | exponentiation                                    |     **                                            |
 * | positive, negative expression                     |     +, -                                          |
 * | increment, decrement                              |     ++, --                                        |
 * | bitwise not                                       |     ~                                             |
 * | existential                                       |     ?                                             |
 * | string composition                                |     %%                                            |
 * | multiplicative expression                         |     *, /, %                                       |
 * | additive expression                               |     +, -                                          |
 * | bitwise shift                                     |     <<, >>                                        |
 * | bitwise AND                                       |     &                                             |
 * | bitwise XOR                                       |     ^                                             |
 * | bitwise OR                                        |     |                                             |
 * | equality comparison                               |     ==, !=, is, is not, in, not in, >, <, >=, <=  |
 * | logical NOT                                       |     not                                           |
 * | logical AND                                       |     and                                           |
 * | logical OR                                        |     or                                            |
 * | range expression                                  |     ...                                           |
 * | conditional expression                            |     if else then                                  |
 * | input & output expression                         |     <<<, >>>                                      |
 * | assignment, pseudo assignment                     |     =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=   |
 * |________________________________________________________________________________________________________
 *
 *       The order of the list should the REVERSE of the order of these tokens defined in parser.y
 *
 **********************************************************************************************************/


class HexParserExprPrecedenceTest : public HexParserXmlTestBase {};


TEST_F(HexParserXmlTestBase, Call_vs_Primaries)
{
  test(
    "person.set_name(name);",
    wrap_single_expr_stmt(
      "<call>"
        "<call-source>"
          "<attribute>"
            "<attribute-source>"
              "<identifier>person<identifier/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>set_name<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<call-source/>"
        "<call-args>"
          "<arg_list>"
            "<arg_list-simple_args>"
              "<val_atom_list>"
                "<identifier>name<identifier/>"
              "<val_atom_list/>"
            "<arg_list-simple_args/>"
          "<arg_list/>"
        "<call-args/>"
      "<call/>"
    )
  );

  test(
    "do_something((), [], {});",
    wrap_single_expr_stmt(
      "<call>"
        "<call-source>"
          "<identifier>do_something<identifier/>"
        "<call-source/>"
        "<call-args>"
          "<arg_list>"
            "<arg_list-simple_args>"
              "<val_atom_list>"
                "<paren_form><paren_form/>"
                "<list_form><list_form/>"
                "<dict_form><dict_form/>"
              "<val_atom_list/>"
            "<arg_list-simple_args/>"
          "<arg_list/>"
        "<call-args/>"
      "<call/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, NegativeExpr_vs_PowerExpr)
{
  // -(5 ** 2)
  test(
    "-5 ** 2;",
    wrap_single_expr_stmt(
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
    wrap_single_expr_stmt(
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

TEST_F(HexParserExprPrecedenceTest, IncrementDecrement_vs_PositiveNegative)
{
  // (+1)++
  test(
    "+1++;",
    wrap_single_expr_stmt(
      "<increment_expr>"
        "<positive_expr>"
          "<integer_literal>1<integer_literal/>"
        "<positive_expr/>"
      "<increment_expr/>"
    )
  );

  // ( ( + (-1) ) ++ )--
  test(
    "+-1++--;",
    wrap_single_expr_stmt(
      "<decrement_expr>"
        "<increment_expr>"
          "<positive_expr>"
            "<negative_expr>"
              "<integer_literal>1<integer_literal/>"
            "<negative_expr/>"
          "<positive_expr/>"
        "<increment_expr/>"
      "<decrement_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, BitwiseNot_vs_IncrementDecrement)
{
  // ~ (1++)
  test(
    "~1++;",
    wrap_single_expr_stmt(
      "<bitwise_not_expr>"
        "<increment_expr>"
          "<integer_literal>1<integer_literal/>"
        "<increment_expr/>"
      "<bitwise_not_expr/>"
    )
  );

  // ~ ( ~( ( (1) ++ ) -- ) )
  test(
    "~~1++--;",
    wrap_single_expr_stmt(
      "<bitwise_not_expr>"
        "<bitwise_not_expr>"
          "<decrement_expr>"
            "<increment_expr>"
              "<integer_literal>1<integer_literal/>"
            "<increment_expr/>"
          "<decrement_expr/>"
        "<bitwise_not_expr/>"
      "<bitwise_not_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, Existential_vs_BitwiseNot)
{
  // ( ~ (1) ) ?
  test(
    "~1?;",
    wrap_single_expr_stmt(
      "<existential_expr>"
        "<bitwise_not_expr>"
          "<integer_literal>1<integer_literal/>"
        "<bitwise_not_expr/>"
      "<existential_expr/>"
    )
  );

  // ( ( ~ ( ~ (1) ) ) ? ) ?
  test(
    "~~1??;",
    wrap_single_expr_stmt(
      "<existential_expr>"
        "<existential_expr>"
          "<bitwise_not_expr>"
            "<bitwise_not_expr>"
              "<integer_literal>1<integer_literal/>"
            "<bitwise_not_expr/>"
          "<bitwise_not_expr/>"
        "<existential_expr/>"
      "<existential_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, StringComposition_vs_Existential)
{
  test(
    "\"name: %s\" %% (name?);",
    wrap_single_expr_stmt(
      "<string_expr>"
        "<string_expr-literal>"
          "<string_literal>\"name: %s\"<string_literal/>"
        "<string_expr-literal/>"
        "<string_expr-exprs>"
          "<exprlist>"
            "<existential_expr>"
              "<identifier>name<identifier/>"
            "<existential_expr/>"
          "<exprlist/>"
        "<string_expr-exprs/>"
      "<string_expr/>"
    )
  );

  test(
    "\"name: %s\" %% (\"%s\" %% (name?));",
    wrap_single_expr_stmt(
      "<string_expr>"
        "<string_expr-literal>"
          "<string_literal>\"name: %s\"<string_literal/>"
        "<string_expr-literal/>"
        "<string_expr-exprs>"
          "<exprlist>"
            "<string_expr>"
              "<string_expr-literal>"
                "<string_literal>\"%s\"<string_literal/>"
              "<string_expr-literal/>"
              "<string_expr-exprs>"
                "<exprlist>"
                  "<existential_expr>"
                    "<identifier>name<identifier/>"
                  "<existential_expr/>"
                "<exprlist/>"
              "<string_expr-exprs/>"
            "<string_expr/>"
          "<exprlist/>"
        "<string_expr-exprs/>"
      "<string_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, MultiplicativeExpr_vs_StringComposition)
{
  // ( "name: %s, " %% (name) ) * ( "age: %d" %% (age) )
  test(
    "\"name: %s, \" %% (name) * \"age: %d\" %% (age);",
    wrap_single_expr_stmt(
      "<multiply_expr>"  
        "<multiply_expr-left>"
          "<string_expr>"
            "<string_expr-literal>"
              "<string_literal>\"name: %s, \"<string_literal/>"
            "<string_expr-literal/>"
            "<string_expr-exprs>"
              "<exprlist>"
                "<identifier>name<identifier/>"
              "<exprlist/>"
            "<string_expr-exprs/>"
          "<string_expr/>"
        "<multiply_expr-left/>"
        "<multiply_expr-right>"
          "<string_expr>"
            "<string_expr-literal>"
              "<string_literal>\"age: %d\"<string_literal/>"
            "<string_expr-literal/>"
            "<string_expr-exprs>"
              "<exprlist>"
                "<identifier>age<identifier/>"
              "<exprlist/>"
            "<string_expr-exprs/>"
          "<string_expr/>"
        "<multiply_expr-right/>"
      "<multiply_expr/>"
    )
  );

  // "My sweethearts: %s" * ( " sweet voices: %s" %% ('Tomiko Van, Rainie Yang') )
  test(
    "\"My sweethearts: %s \" * \" sweet voices: %s\" %% (\'Tomiko Van\', \'Rainie Yang\');",
    wrap_single_expr_stmt(
      "<multiply_expr>"
        "<multiply_expr-left>"
          "<string_literal>\"My sweethearts: %s \"<string_literal/>"
        "<multiply_expr-left/>"
        "<multiply_expr-right>"
          "<string_expr>"
            "<string_expr-literal>"
              "<string_literal>\" sweet voices: %s\"<string_literal/>"
            "<string_expr-literal/>"
            "<string_expr-exprs>"
              "<exprlist>"
                "<string_literal>\'Tomiko Van\'<string_literal/>"
                "<string_literal>\'Rainie Yang\'<string_literal/>"
              "<exprlist/>"
            "<string_expr-exprs/>"
          "<string_expr/>"
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
    wrap_single_expr_stmt(
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
    wrap_single_expr_stmt(
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
    wrap_single_expr_stmt(
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

TEST_F(HexParserExprPrecedenceTest, BitwiseShiftExpr_vs_AdditiveExpr)
{
  // (1 + 2) << 3
  test(
    "1 + 2 << 3;",
    wrap_single_expr_stmt(
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
    wrap_single_expr_stmt(
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
    wrap_single_expr_stmt(
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

TEST_F(HexParserExprPrecedenceTest, BitwiseAndExpr_vs_BitwiseShiftExpr)
{
  // 1 & (2 << 3)
  test(
    "1 & 2 << 3;",
    wrap_single_expr_stmt(
      "<bitwise_and_expr>"
        "<bitwise_and_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<bitwise_and_expr-left/>"
        "<bitwise_and_expr-right>"
          "<bitwise_shift_left_expr>"
            "<bitwise_shift_left_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_shift_left_expr-left/>"
            "<bitwise_shift_left_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_shift_left_expr-right/>"
          "<bitwise_shift_left_expr/>"
        "<bitwise_and_expr-right/>"
      "<bitwise_and_expr/>"
    )
  );

  // (1 << 2) & 3
  test(
    "1 << 2 & 3;",
    wrap_single_expr_stmt(
      "<bitwise_and_expr>"
        "<bitwise_and_expr-left>"
          "<bitwise_shift_left_expr>"
            "<bitwise_shift_left_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<bitwise_shift_left_expr-left/>"
            "<bitwise_shift_left_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_shift_left_expr-right/>"
          "<bitwise_shift_left_expr/>"
        "<bitwise_and_expr-left/>"
        "<bitwise_and_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<bitwise_and_expr-right/>"
      "<bitwise_and_expr/>"
    )
  );

  // (1 & 2) << 3
  test(
    "(1 & 2) << 3;",
    wrap_single_expr_stmt(
      "<bitwise_shift_left_expr>"
        "<bitwise_shift_left_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<bitwise_and_expr>"
                "<bitwise_and_expr-left>"
                  "<integer_literal>1<integer_literal/>"
                "<bitwise_and_expr-left/>"
                "<bitwise_and_expr-right>"
                  "<integer_literal>2<integer_literal/>"
                "<bitwise_and_expr-right/>"
              "<bitwise_and_expr/>"
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

TEST_F(HexParserExprPrecedenceTest, BitwiseXor_vs_BitwiseAnd)
{
  // (1 & 2) ^ 3
  test(
    "1 & 2 ^ 3;",
    wrap_single_expr_stmt(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<bitwise_and_expr>"
            "<bitwise_and_expr-left>"
              "<integer_literal>1<integer_literal/>"
            "<bitwise_and_expr-left/>"
            "<bitwise_and_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_and_expr-right/>"
          "<bitwise_and_expr/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<integer_literal>3<integer_literal/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );

  // 1 ^ (2 & 3)
  test(
    "1 ^ 2 & 3;",
    wrap_single_expr_stmt(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<bitwise_and_expr>"
            "<bitwise_and_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_and_expr-left/>"
            "<bitwise_and_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_and_expr-right/>"
          "<bitwise_and_expr/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );

  // 1 & (2 ^ 3)
  test(
    "1 & (2 ^ 3);",
    wrap_single_expr_stmt(
      "<bitwise_and_expr>"
        "<bitwise_and_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<bitwise_and_expr-left/>"
        "<bitwise_and_expr-right>"
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
        "<bitwise_and_expr-right/>"
      "<bitwise_and_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, BitwiseOrExpr_vs_BitwiseXorExpr)
{
  // 2 | (3 ^ 4)
  test(
    "2 | 3 ^ 4;",
    wrap_single_expr_stmt(
      "<bitwise_or_expr>"
        "<bitwise_or_expr-left>"
          "<integer_literal>2<integer_literal/>"
        "<bitwise_or_expr-left/>"
        "<bitwise_or_expr-right>"
          "<bitwise_xor_expr>"
            "<bitwise_xor_expr-left>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_xor_expr-left/>"
            "<bitwise_xor_expr-right>"
              "<integer_literal>4<integer_literal/>"
            "<bitwise_xor_expr-right/>"
          "<bitwise_xor_expr/>"
        "<bitwise_or_expr-right/>"
      "<bitwise_or_expr/>"
    )
  );

  // (2 ^ 3) | 4
  test(
    "2 ^ 3 | 4;",
    wrap_single_expr_stmt(
      "<bitwise_or_expr>"
        "<bitwise_or_expr-left>"
          "<bitwise_xor_expr>"
            "<bitwise_xor_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_xor_expr-left/>"
            "<bitwise_xor_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_xor_expr-right/>"
          "<bitwise_xor_expr/>"
        "<bitwise_or_expr-left/>"
        "<bitwise_or_expr-right>"
          "<integer_literal>4<integer_literal/>"
        "<bitwise_or_expr-right/>"
      "<bitwise_or_expr/>"
    )
  );

  // (2 | 3) ^ 4
  test(
    "(2 | 3) ^ 4;",
    wrap_single_expr_stmt(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<paren_form>"
            "<exprlist>"
              "<bitwise_or_expr>"
                "<bitwise_or_expr-left>"
                  "<integer_literal>2<integer_literal/>"
                "<bitwise_or_expr-left/>"
                "<bitwise_or_expr-right>"
                  "<integer_literal>3<integer_literal/>"
                "<bitwise_or_expr-right/>"
              "<bitwise_or_expr/>"
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

TEST_F(HexParserExprPrecedenceTest, ComparisonExpr_vs_BitwiseOrExpr)
{
  // (2 | 3) is 2
  test(
    "2 | 3 is 2;",
    wrap_single_expr_stmt(
      "<is_expr>"
        "<is_expr-left>"
          "<bitwise_or_expr>"
            "<bitwise_or_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_or_expr-left/>"
            "<bitwise_or_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_or_expr-right/>"
          "<bitwise_or_expr/>"
        "<is_expr-left/>"
        "<is_expr-right>"
          "<integer_literal>2<integer_literal/>"
        "<is_expr-right/>"
      "<is_expr/>"
    )
  );

  // // 5 >= (2 | 5)
  test(
    "5 >= 2 | 5;",
    wrap_single_expr_stmt(
      "<ge_expr>"
        "<ge_expr-left>"
          "<integer_literal>5<integer_literal/>"
        "<ge_expr-left/>"
        "<ge_expr-right>"
          "<bitwise_or_expr>"
            "<bitwise_or_expr-left>"
              "<integer_literal>2<integer_literal/>"
            "<bitwise_or_expr-left/>"
            "<bitwise_or_expr-right>"
              "<integer_literal>5<integer_literal/>"
            "<bitwise_or_expr-right/>"
          "<bitwise_or_expr/>"
        "<ge_expr-right/>"
      "<ge_expr/>"
    )
  );

  // // (2 <= 3) | 5
  test(
    "(2 <= 3) | 5;",
    wrap_single_expr_stmt(
      "<bitwise_or_expr>"
        "<bitwise_or_expr-left>"
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
        "<bitwise_or_expr-left/>"
        "<bitwise_or_expr-right>"
          "<integer_literal>5<integer_literal/>"
        "<bitwise_or_expr-right/>"
      "<bitwise_or_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, LogicalNot_vs_ComparisonExpr)
{
  // not (1 == 1)
  test(
    "not 1 == 1;",
    wrap_single_expr_stmt(
      "<not_expr>"
        "<equals_expr>"
          "<equals_expr-left>"
            "<integer_literal>1<integer_literal/>"
          "<equals_expr-left/>"
          "<equals_expr-right>"
            "<integer_literal>1<integer_literal/>"
          "<equals_expr-right/>"
        "<equals_expr/>"
      "<not_expr/>"
    )
  );

  // (1) is not (2)
  test(
    "1 is not 2;",
    wrap_single_expr_stmt(
      "<is_not_expr>"
        "<is_not_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<is_not_expr-left/>"
        "<is_not_expr-right>"
          "<integer_literal>2<integer_literal/>"
        "<is_not_expr-right/>"
      "<is_not_expr/>"
    )
  );

  // a != (not b)
  test(
    "a != not b;",
    wrap_single_expr_stmt(
      "<not_equal_expr>"
        "<not_equal_expr-left>"
          "<identifier>a<identifier/>"
        "<not_equal_expr-left/>"
        "<not_equal_expr-right>"
          "<not_expr>"
            "<identifier>b<identifier/>"
          "<not_expr/>"
        "<not_equal_expr-right/>"
      "<not_equal_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, LogicAnd_vs_LogicNot)
{
  // ( not a ) and ( not b )
  test(
    "not a and not b;",
    wrap_single_expr_stmt(
      "<and_expr>"
        "<and_expr-left>"
          "<not_expr>"
            "<identifier>a<identifier/>"
          "<not_expr/>"
        "<and_expr-left/>"
        "<and_expr-right>"
          "<not_expr>"
            "<identifier>b<identifier/>"
          "<not_expr/>"
        "<and_expr-right/>"
      "<and_expr/>"
    )
  );


  // ( not a ) and b
  test(
    "not a and b;",
    wrap_single_expr_stmt(
      "<and_expr>"
        "<and_expr-left>"
          "<not_expr>"
            "<identifier>a<identifier/>"
          "<not_expr/>"
        "<and_expr-left/>"
        "<and_expr-right>"
          "<identifier>b<identifier/>"
        "<and_expr-right/>"
      "<and_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, LogicOr_vs_LogicAnd)
{
  // a or ( b and c )
  test(
    "a or b and c;",
    wrap_single_expr_stmt(
      "<or_expr>"
        "<or_expr-left>"
          "<identifier>a<identifier/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<and_expr>"
            "<and_expr-left>"
              "<identifier>b<identifier/>"
            "<and_expr-left/>"
            "<and_expr-right>"
              "<identifier>c<identifier/>"
            "<and_expr-right/>"
          "<and_expr/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );

  // ( a or (b and c) ) or d
  test(
    "a or b and c or d;",
    wrap_single_expr_stmt(
      "<or_expr>"
        "<or_expr-left>"
          "<or_expr>"
            "<or_expr-left>"
              "<identifier>a<identifier/>"
            "<or_expr-left/>"
            "<or_expr-right>"
              "<and_expr>"
                "<and_expr-left>"
                  "<identifier>b<identifier/>"
                "<and_expr-left/>"
                "<and_expr-right>"
                  "<identifier>c<identifier/>"
                "<and_expr-right/>"
              "<and_expr/>"
            "<or_expr-right/>"
          "<or_expr/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<identifier>d<identifier/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, RangeExpr_vs_LogicOrExpr)
{
  // ( a or b ) ... ( c or d )
  test(
    "a or b ... c or d;",
    wrap_single_expr_stmt(
      "<inclusive_range_expr>"
        "<inclusive_range_expr-begin>"
          "<or_expr>"
            "<or_expr-left>"
              "<identifier>a<identifier/>"
            "<or_expr-left/>"
            "<or_expr-right>"
              "<identifier>b<identifier/>"
            "<or_expr-right/>"
          "<or_expr/>"
        "<inclusive_range_expr-begin/>"
        "<inclusive_range_expr-end>"
          "<or_expr>"
            "<or_expr-left>"
              "<identifier>c<identifier/>"
            "<or_expr-left/>"
            "<or_expr-right>"
              "<identifier>d<identifier/>"
            "<or_expr-right/>"
          "<or_expr/>"
        "<inclusive_range_expr-end/>"
      "<inclusive_range_expr/>"
    )
  );
}

TEST_F(HexParserExprPrecedenceTest, ConditionalExpr_vs_RangeExpr)
{
  test(
    "if a is 2 then 1...2 else 1...10;",
    wrap_single_expr_stmt(
      "<conditional_expr>"
        "<conditional_expr-predicate>"
          "<is_expr>"
            "<is_expr-left>"
              "<identifier>a<identifier/>"
            "<is_expr-left/>"
            "<is_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<is_expr-right/>"
          "<is_expr/>"
        "<conditional_expr-predicate/>"
        "<conditional_expr-consequent>"
          "<inclusive_range_expr>"
            "<inclusive_range_expr-begin>"
              "<integer_literal>1<integer_literal/>"
            "<inclusive_range_expr-begin/>"
            "<inclusive_range_expr-end>"
              "<integer_literal>2<integer_literal/>"
            "<inclusive_range_expr-end/>"
          "<inclusive_range_expr/>"
        "<conditional_expr-consequent/>"
        "<conditional_expr-alternate>"
          "<inclusive_range_expr>"
            "<inclusive_range_expr-begin>"
              "<integer_literal>1<integer_literal/>"
            "<inclusive_range_expr-begin/>"
            "<inclusive_range_expr-end>"
              "<integer_literal>10<integer_literal/>"
            "<inclusive_range_expr-end/>"
          "<inclusive_range_expr/>"
        "<conditional_expr-alternate/>"
      "<conditional_expr/>"
    )
  );
}
