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


/*
This is the captain speaking:

This file is for testing the representation of AST through XML.
And, this test is HUUUUUGE, so please fasten your seatbelt and
enjoy some long XMLs...

                              |
                        --====|====--
                              |  
                          .-"""""-. 
                        .'_________'. 
                       /_/_|__|__|_\_\
                      ;'-._       _.-';
 ,--------------------|    `-. .-'    |--------------------,
  ``""--..__    ___   ;       '       ;   ___    __..--""``
            `"-// \\.._\             /_..// \\-"`
               \\_//    '._       _.'    \\_//
                `"`        ``---``        `"`
*/


#include "parser_xml_test_base.h"
#include "../../base/c_str.h"


class HexParserXmlTest : public HexParserXmlTestBase {
public:
  const c_str embed_code_in_xml(const c_str, const c_str);
  void test_indentifier(const c_str);
  void test_integer_literal(const c_str);
  void test_floating_literal(const c_str);
  void test_string_literal(const c_str);
};


const c_str
HexParserXmlTest::embed_code_in_xml(const c_str code_, const c_str xml_)
{
  char xml[3000];

  // remove semicolon.
  std::string code(code_);
  code.erase(code.end()-1);

  sprintf(
    xml,
    xml_,
    code.c_str()
  );

  return (const c_str)strdup(xml);
}

void
HexParserXmlTest::test_indentifier(const c_str code)
{
  test(
    code,
    wrap_single_expr(
      embed_code_in_xml(
        code,
        "<identifier>%s<identifier/>"
      )
    )
  );
}

void
HexParserXmlTest::test_integer_literal(const c_str code)
{
  test(
    code,
    wrap_single_expr(
      embed_code_in_xml(
        code,
        "<integer_literal>%s<integer_literal/>"
      )
    )
  );
}

void
HexParserXmlTest::test_floating_literal(const c_str code)
{
  test(
    code,
    wrap_single_expr(
      embed_code_in_xml(
        code,
        "<floating_literal>%s<floating_literal/>"
      )
    )
  );
}

void
HexParserXmlTest::test_string_literal(const c_str code)
{
  test(
    code,
    wrap_single_expr(
      embed_code_in_xml(
        code,
        "<string_literal>%s<string_literal/>"
      )
    )
  );
}

TEST_F(HexParserXmlTest, TestIdentifier)
{
  test_indentifier("a;");
  test_indentifier("self;");
  test_indentifier("abc;");
  test_indentifier("_abc;");
  test_indentifier("_;");
  test_indentifier("___;");
  test_indentifier("_123;");
  test_indentifier("_x123;");
  test_indentifier("_x242x_;");
  test_indentifier("__test__;");
  test_indentifier("x__x;");
}

TEST_F(HexParserXmlTest, TestIntegerLiteral)
{
  test_integer_literal("0;");
  test_integer_literal("123;");
  test_integer_literal("0123;");

  // binaries
  test_integer_literal("0b00;");
  test_integer_literal("0b01;");
  test_integer_literal("0B00;");
  test_integer_literal("0B01;");

  // octals...
  test_integer_literal("0o00;");
  test_integer_literal("0o01;");
  test_integer_literal("0O00;");
  test_integer_literal("0O01;");

  // hexadecimals...
  test_integer_literal("0x00;");
  test_integer_literal("0xFF;");
  test_integer_literal("0X00;");
  test_integer_literal("0XFF;");
}

TEST_F(HexParserXmlTest, TestFloatingLiteral)
{
  test_floating_literal("0.0;");
  test_floating_literal("3.1415926;");
  test_floating_literal("0.05e+3;");
  test_floating_literal("8.46e-5;");
}

TEST_F(HexParserXmlTest, TestStringLiteral)
{
  // double quote strings...
  test_string_literal("\"\";");
  test_string_literal("\"     \";");
  test_string_literal("\"this is a string\";");
  test_string_literal("\"1234567890\";");
  test_string_literal("\"!@#$%^&*()_+\";");
  test_string_literal("\"[]|;',./\";");
  test_string_literal("\"<>/?\";");
  test_string_literal("\"\n\t\r\";");

  // single quote strings...
  test_string_literal("\'\';");
  test_string_literal("\'     \';");
  test_string_literal("\'this is a string\';");
  test_string_literal("\'1234567890\';");
  test_string_literal("\'!@#$%^&*()_+\';");
  // test_string_literal("\'[]|;',./\';");
  test_string_literal("\'<>/?\';");
  test_string_literal("\'\n\t\r\';");
}

TEST_F(HexParserXmlTest, TestCall)
{
  test(
    "hello_world();",
    wrap_single_expr(
      "<call>"
        "<call-source>"
          "<identifier>hello_world<identifier/>"
        "<call-source/>"
      "<call/>"
    )
  );

  test(
    "print(\"Hello world!\");",
    wrap_single_expr(
      "<call>"
        "<call-source>"
          "<identifier>print<identifier/>"
        "<call-source/>"
        "<call-args>"
          "<arg_list>"
            "<arg_list-simple_args>"
              "<val_atom_list>"
                "<string_literal>\"Hello world!\"<string_literal/>"
              "<val_atom_list/>"
            "<arg_list-simple_args/>"
          "<arg_list/>"
        "<call-args/>"
      "<call/>"
    )
  );

  test(
    "person.set_age(24);",
    wrap_single_expr(
      "<call>"
        "<call-source>"
          "<attribute>"
            "<attribute-source>"
              "<identifier>person<identifier/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>set_age<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<call-source/>"
        "<call-args>"
          "<arg_list>"
            "<arg_list-simple_args>"
              "<val_atom_list>"
                "<integer_literal>24<integer_literal/>"
              "<val_atom_list/>"
            "<arg_list-simple_args/>"
          "<arg_list/>"
        "<call-args/>"
      "<call/>"
    )
  );

  test(
    "person.get_info().to_dict();",
    wrap_single_expr(
      "<call>"
        "<call-source>"
          "<attribute>"
            "<attribute-source>"
              "<call>"
                "<call-source>"
                  "<attribute>"
                    "<attribute-source>"
                      "<identifier>person<identifier/>"
                    "<attribute-source/>"
                    "<attribute-target>"
                      "<identifier>get_info<identifier/>"
                    "<attribute-target/>"
                  "<attribute/>"
                "<call-source/>"
              "<call/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>to_dict<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<call-source/>"
      "<call/>"
    )
  );

  test(
    "person.father().name;",
    wrap_single_expr(
      "<attribute>"
        "<attribute-source>"
          "<call>"
            "<call-source>"
              "<attribute>"
                "<attribute-source>"
                  "<identifier>person<identifier/>"
                "<attribute-source/>"
                "<attribute-target>"
                  "<identifier>father<identifier/>"
                "<attribute-target/>"
              "<attribute/>"
            "<call-source/>"
          "<call/>"
        "<attribute-source/>"
        "<attribute-target>"
          "<identifier>name<identifier/>"
        "<attribute-target/>"
      "<attribute/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestAttributeRef)
{
  test(
    "obj.attr.field;",
    wrap_single_expr(
      "<attribute>"
        "<attribute-source>"
          "<attribute>"
            "<attribute-source>"
              "<identifier>obj<identifier/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>attr<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<attribute-source/>"
        "<attribute-target>"
          "<identifier>field<identifier/>"
        "<attribute-target/>"
      "<attribute/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestTargetList)
{
  test(
    "[for name in names];",
    wrap_single_expr(
      "<list_form>"
        "<comprehension>"
          "<comprehension-candidates>"
            "<target_list>"
              "<identifier>name<identifier/>"
            "<target_list/>"
          "<comprehension-candidates/>"
          "<comprehension-source>"
            "<exprlist>"
              "<identifier>names<identifier/>"
            "<exprlist/>"
          "<comprehension-source/>"
        "<comprehension/>"
      "<list_form/>"
    )
  );

  test(
    "[for a, e, i, o, u in alphabets];",
    wrap_single_expr(
      "<list_form>"
        "<comprehension>"
          "<comprehension-candidates>"
            "<target_list>"
              "<identifier>a<identifier/>"
              "<identifier>e<identifier/>"
              "<identifier>i<identifier/>"
              "<identifier>o<identifier/>"
              "<identifier>u<identifier/>"
            "<target_list/>"
          "<comprehension-candidates/>"
          "<comprehension-source>"
            "<exprlist>"
              "<identifier>alphabets<identifier/>"
            "<exprlist/>"
          "<comprehension-source/>"
        "<comprehension/>"
      "<list_form/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestPositiveExpr)
{
  test(
    "+0987654321;",
    wrap_single_expr(
      "<positive_expr>"
        "<integer_literal>0987654321<integer_literal/>"
      "<positive_expr/>"
    )
  );

  test(
    "+0x0123456789ABCDEF;",
    wrap_single_expr(
      "<positive_expr>"
        "<integer_literal>0x0123456789ABCDEF<integer_literal/>"
      "<positive_expr/>"
    )
  );

  test(
    "+0.987654321;",
    wrap_single_expr(
      "<positive_expr>"
        "<floating_literal>0.987654321<floating_literal/>"
      "<positive_expr/>"
    )
  );

  test(
    "+987.654e-321;",
    wrap_single_expr(
      "<positive_expr>"
        "<floating_literal>987.654e-321<floating_literal/>"
      "<positive_expr/>"
    )
  );

  test(
    "+(1);",
    wrap_single_expr(
      "<positive_expr>"
        "<paren_form>"
          "<exprlist>"
            "<integer_literal>1<integer_literal/>"
          "<exprlist/>"
        "<paren_form/>"
      "<positive_expr/>"
    )
  );

  test(
    "+(1 + 1);",
    wrap_single_expr(
      "<positive_expr>"
        "<paren_form>"
          "<exprlist>"
            "<add_expr>"
              "<add_expr-left>"
                "<integer_literal>1<integer_literal/>"
              "<add_expr-left/>"
              "<add_expr-right>"
                "<integer_literal>1<integer_literal/>"
              "<add_expr-right/>"
            "<add_expr/>"
          "<exprlist/>"
        "<paren_form/>"
      "<positive_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestNegativeExpr)
{
  test(
    "-0987654321;",
    wrap_single_expr(
      "<negative_expr>"
        "<integer_literal>0987654321<integer_literal/>"
      "<negative_expr/>"
    )
  );

  test(
    "-0x0123456789ABCDEF;",
    wrap_single_expr(
      "<negative_expr>"
        "<integer_literal>0x0123456789ABCDEF<integer_literal/>"
      "<negative_expr/>"
    )
  );

  test(
    "-0.987654321;",
    wrap_single_expr(
      "<negative_expr>"
        "<floating_literal>0.987654321<floating_literal/>"
      "<negative_expr/>"
    )
  );

  test(
    "-987.654e-321;",
    wrap_single_expr(
      "<negative_expr>"
        "<floating_literal>987.654e-321<floating_literal/>"
      "<negative_expr/>"
    )
  );

  test(
    "-(1);",
    wrap_single_expr(
      "<negative_expr>"
        "<paren_form>"
          "<exprlist>"
            "<integer_literal>1<integer_literal/>"
          "<exprlist/>"
        "<paren_form/>"
      "<negative_expr/>"
    )
  );

  test(
    "-(1 + 1);",
    wrap_single_expr(
      "<negative_expr>"
        "<paren_form>"
          "<exprlist>"
            "<add_expr>"
              "<add_expr-left>"
                "<integer_literal>1<integer_literal/>"
              "<add_expr-left/>"
              "<add_expr-right>"
                "<integer_literal>1<integer_literal/>"
              "<add_expr-right/>"
            "<add_expr/>"
          "<exprlist/>"
        "<paren_form/>"
      "<negative_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestNotExpr)
{
  test(
    "not 1;",
    wrap_single_expr(
      "<not_expr>"
        "<integer_literal>1<integer_literal/>"
      "<not_expr/>"
    )
  );

  test(
    "not not 1;",
    wrap_single_expr(
      "<not_expr>"
        "<not_expr>"
          "<integer_literal>1<integer_literal/>"
        "<not_expr/>"
      "<not_expr/>"
    )
  );

  test(
    "not 1 != 1;",
    wrap_single_expr(
      "<not_equal_expr>"
        "<not_equal_expr-left>"
          "<not_expr>"
            "<integer_literal>1<integer_literal/>"
          "<not_expr/>"
          "<not_equal_expr-left/>"
          "<not_equal_expr-right>"
            "<integer_literal>1<integer_literal/>"
          "<not_equal_expr-right/>"
      "<not_equal_expr/>"
    )
  );

  // test(
  //   "not a is not b;",
  //   wrap_single_expr(
  //     "<is_expr>"
  //       "<is_expr-left>"
  //         "<not_expr>"
  //           "<identifier>a<identifier/>"
  //         "<not_expr/>"
  //       "<is_expr-left/>"
  //       "<is_expr-right>"
  //         "<not_expr>"
  //           "<identifier>b<identifier/>"
  //         "<not_expr/>"
  //       "<is_expr-right/>"
  //     "<is_expr/>"
  //   )
  // );
}

TEST_F(HexParserXmlTest, TestBitwiseNotExpr)
{
  test(
    "~123;",
    wrap_single_expr(
      "<bitwise_not_expr>"
        "<integer_literal>123<integer_literal/>"
      "<bitwise_not_expr/>"
    )
  );

  test(
    "~~123;",
    wrap_single_expr(
      "<bitwise_not_expr>"
        "<bitwise_not_expr>"
          "<integer_literal>123<integer_literal/>"
        "<bitwise_not_expr/>"
      "<bitwise_not_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestIncrementExpr)
{
  test(
    "c++;",
    wrap_single_expr(
      "<increment_expr>"
        "<identifier>c<identifier/>"
      "<increment_expr/>"
    )
  );

  test(
    "(1 + 2)++;",
    wrap_single_expr(
      "<increment_expr>"
        "<paren_form>"
          "<exprlist>"
            "<add_expr>"
              "<add_expr-left>"
                "<integer_literal>1<integer_literal/>"
              "<add_expr-left/>"
              "<add_expr-right>"
                "<integer_literal>2<integer_literal/>"
              "<add_expr-right/>"
            "<add_expr/>"
          "<exprlist/>"
        "<paren_form/>"
      "<increment_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestDecrementExpr)
{
  test(
    "i--;",
    wrap_single_expr(
      "<decrement_expr>"
        "<identifier>i<identifier/>"
      "<decrement_expr/>"
    )
  );

  // (c++)--
  test(
    "c++--;",
    wrap_single_expr(
      "<decrement_expr>"
        "<increment_expr>"
          "<identifier>c<identifier/>"
        "<increment_expr/>"
      "<decrement_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestExistentialExpr)
{
  test(
    "a?;",
    wrap_single_expr(
      "<existential_expr>"
        "<identifier>a<identifier/>"
      "<existential_expr/>"
    )
  );

  test(
    "(a or b)?;",
    wrap_single_expr(
      "<existential_expr>"
        "<paren_form>"
          "<exprlist>"
            "<or_expr>"
              "<or_expr-left>"
                "<identifier>a<identifier/>"
              "<or_expr-left/>"
              "<or_expr-right>"
                "<identifier>b<identifier/>"
              "<or_expr-right/>"
            "<or_expr/>"
          "<exprlist/>"
        "<paren_form/>"
      "<existential_expr/>"
    )
  );

  test(
    "((a or b)? and (c is d)?)?;",
    wrap_single_expr(
      "<existential_expr>"
        "<paren_form>"
          "<exprlist>"
            "<and_expr>"
              "<and_expr-left>"
                "<existential_expr>"
                  "<paren_form>"
                    "<exprlist>"
                      "<or_expr>"
                        "<or_expr-left>"
                          "<identifier>a<identifier/>"
                        "<or_expr-left/>"
                        "<or_expr-right>"
                          "<identifier>b<identifier/>"
                        "<or_expr-right/>"
                      "<or_expr/>"
                    "<exprlist/>"
                  "<paren_form/>"
                "<existential_expr/>"
              "<and_expr-left/>"
              "<and_expr-right>"
                "<existential_expr>"
                  "<paren_form>"
                    "<exprlist>"
                      "<is_expr>"
                        "<is_expr-left>"
                          "<identifier>c<identifier/>"
                        "<is_expr-left/>"
                        "<is_expr-right>"
                          "<identifier>d<identifier/>"
                        "<is_expr-right/>"
                      "<is_expr/>"
                    "<exprlist/>"
                  "<paren_form/>"
                "<existential_expr/>"
              "<and_expr-right/>"
            "<and_expr/>"
          "<exprlist/>"
        "<paren_form/>"
      "<existential_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestAdditiveExpr)
{
  test(
    "1 + 1;",
    wrap_single_expr(
      "<add_expr>"
        "<add_expr-left>"
          "<integer_literal>1<integer_literal/>"
        "<add_expr-left/>"
        "<add_expr-right>"
          "<integer_literal>1<integer_literal/>"
        "<add_expr-right/>"
      "<add_expr/>"
    )
  );

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
}

TEST_F(HexParserXmlTest, TestMultiplicativeExpr)
{
  test(
    "3.14 * 3 / 9.543 % 5;",
    wrap_single_expr(
      "<modulus_expr>"
        "<modulus_expr-left>"
          "<divide_expr>"
            "<divide_expr-left>"
              "<multiply_expr>"
                "<multiply_expr-left>"
                  "<floating_literal>3.14<floating_literal/>"
                "<multiply_expr-left/>"
                "<multiply_expr-right>"
                  "<integer_literal>3<integer_literal/>"
                "<multiply_expr-right/>"
              "<multiply_expr/>"
            "<divide_expr-left/>"
            "<divide_expr-right>"
              "<floating_literal>9.543<floating_literal/>"
            "<divide_expr-right/>"
          "<divide_expr/>"
        "<modulus_expr-left/>"
        "<modulus_expr-right>"
          "<integer_literal>5<integer_literal/>"
        "<modulus_expr-right/>"
      "<modulus_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestPowerExpr)
{
  // TODO: associtivity is wrong...
  test(
    "a ** 2 + 1;",
    wrap_single_expr(
      "<add_expr>"
        "<add_expr-left>"
          "<power_expr>"
            "<power_expr-left>"
              "<identifier>a<identifier/>"
            "<power_expr-left/>"
            "<power_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<power_expr-right/>"
          "<power_expr/>"
        "<add_expr-left/>"
        "<add_expr-right>"
          "<integer_literal>1<integer_literal/>"
        "<add_expr-right/>"
      "<add_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestBitwiseExpr)
{
  // TODO: associtivity is wrong...
  test(
    "1 & 2 | 3 ^ 4;",
    wrap_single_expr(
      "<bitwise_xor_expr>"
        "<bitwise_xor_expr-left>"
          "<bitwise_or_expr>"
            "<bitwise_or_expr-left>"
              "<bitwise_and_expr>"
                "<bitwise_and_expr-left>"
                  "<integer_literal>1<integer_literal/>"
                "<bitwise_and_expr-left/>"
                "<bitwise_and_expr-right>"
                  "<integer_literal>2<integer_literal/>"
                "<bitwise_and_expr-right/>"
              "<bitwise_and_expr/>"
            "<bitwise_or_expr-left/>"
            "<bitwise_or_expr-right>"
              "<integer_literal>3<integer_literal/>"
            "<bitwise_or_expr-right/>"
          "<bitwise_or_expr/>"
        "<bitwise_xor_expr-left/>"
        "<bitwise_xor_expr-right>"
          "<integer_literal>4<integer_literal/>"
        "<bitwise_xor_expr-right/>"
      "<bitwise_xor_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestComparisonExpr)
{
  // (a is not 2) is true
  test(
    "a is not 2 is true;",
    wrap_single_expr(
      "<is_expr>"
        "<is_expr-left>"
          "<is_not_expr>"
            "<is_not_expr-left>"
              "<identifier>a<identifier/>"
            "<is_not_expr-left/>"
            "<is_not_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<is_not_expr-right/>"
          "<is_not_expr/>"
        "<is_expr-left/>"
        "<is_expr-right>"
          "<identifier>true<identifier/>"
        "<is_expr-right/>"
      "<is_expr/>"
    )
  );

  // ( ( 1 + 1 ) == 2 ) != 0
  test(
    "1 + 1 == 2 != 0;",
    wrap_single_expr(
      "<not_equal_expr>"
        "<not_equal_expr-left>"
          "<equals_expr>"
            "<equals_expr-left>"
              "<add_expr>"
                "<add_expr-left>"
                  "<integer_literal>1<integer_literal/>"
                "<add_expr-left/>"
                "<add_expr-right>"
                  "<integer_literal>1<integer_literal/>"
                "<add_expr-right/>"
              "<add_expr/>"
            "<equals_expr-left/>"
            "<equals_expr-right>"
              "<integer_literal>2<integer_literal/>"
            "<equals_expr-right/>"
          "<equals_expr/>"
        "<not_equal_expr-left/>"
        "<not_equal_expr-right>"
          "<integer_literal>0<integer_literal/>"
        "<not_equal_expr-right/>"
      "<not_equal_expr/>"
    )
  );

  test(
    "a in b in c in d;",
    wrap_single_expr(
      "<in_expr>"
        "<in_expr-left>"
          "<in_expr>"
            "<in_expr-left>"
              "<in_expr>"
                "<in_expr-left>"
                  "<identifier>a<identifier/>"
                "<in_expr-left/>"
                "<in_expr-right>"
                  "<identifier>b<identifier/>"
                "<in_expr-right/>"
              "<in_expr/>"
            "<in_expr-left/>"
            "<in_expr-right>"
              "<identifier>c<identifier/>"
            "<in_expr-right/>"
          "<in_expr/>"
        "<in_expr-left/>"
        "<in_expr-right>"
          "<identifier>d<identifier/>"
        "<in_expr-right/>"
      "<in_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestLogicExpr)
{
  // (a and b) or c
  test(
    "a and b or c;",
    wrap_single_expr(
      "<or_expr>"
        "<or_expr-left>"
          "<and_expr>"
            "<and_expr-left>"
              "<identifier>a<identifier/>"
            "<and_expr-left/>"
            "<and_expr-right>"
              "<identifier>b<identifier/>"
            "<and_expr-right/>"
          "<and_expr/>"
        "<or_expr-left/>"
        "<or_expr-right>"
          "<identifier>c<identifier/>"
        "<or_expr-right/>"
      "<or_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestRangeExpr)
{
  test(
    "1...100;",
    wrap_single_expr(
      "<inclusive_range_expr>"
        "<inclusive_range_expr-begin>"
          "<integer_literal>1<integer_literal/>"
        "<inclusive_range_expr-begin/>"
        "<inclusive_range_expr-end>"
          "<integer_literal>100<integer_literal/>"
        "<inclusive_range_expr-end/>"
      "<inclusive_range_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestPseudoAssignExprs)
{
  // a += ( b -= ( c *= ( d /= ( e %= 1 ) ) ) )
  test(
    "a += b -= c *= d /= e %= 1;",
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
                          "<integer_literal>1<integer_literal/>"
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
}

TEST_F(HexParserXmlTest, TestYieldExpr)
{
  test(
    "yield;",
    wrap_single_expr(
      "<yield_expr><yield_expr/>"
    )
  );

  test(
    "yield (yield);",
    wrap_single_expr(
      "<yield_expr>"
        "<yield_expr-exprs>"
          "<exprlist>"
            "<yield_expr>"
            "<yield_expr/>"
          "<exprlist/>"
        "<yield_expr-exprs/>"
      "<yield_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestStringExpr)
{
  // TODO: This is wrong...
  test(
    "\"My name is %s and I'm %d years old.\" %% (\'Yanzheng Li\', 20);",
    wrap_single_expr(
      "<string_expr>"
        "<string_expr-literal>"
          "<string_literal>"
            "\"My name is %s and I'm %d years old.\""
          "<string_literal/>"
        "<string_expr-literal/>"
        "<string_expr-exprs>"
          "<exprlist>"
            "<string_literal>'Yanzheng Li'<string_literal/>"
            "<integer_literal>20<integer_literal/>"
          "<exprlist/>"
        "<string_expr-exprs/>"
      "<string_expr/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestParenForm)
{
  test(
    "(1, 2, 3);",
    wrap_single_expr(
      "<paren_form>"
        "<exprlist>"
          "<integer_literal>1<integer_literal/>"
          "<integer_literal>2<integer_literal/>"
          "<integer_literal>3<integer_literal/>"
        "<exprlist/>"
      "<paren_form/>"
    )
  );

  test(
    "(1, (2, 3), (4, 5, 6), (7, 8, 9, 10));",
    wrap_single_expr(
      "<paren_form>"
        "<exprlist>"
          "<integer_literal>1<integer_literal/>"
          "<paren_form>"
            "<exprlist>"
              "<integer_literal>2<integer_literal/>"
              "<integer_literal>3<integer_literal/>"
            "<exprlist/>"
          "<paren_form/>"
          "<paren_form>"
            "<exprlist>"
              "<integer_literal>4<integer_literal/>"
              "<integer_literal>5<integer_literal/>"
              "<integer_literal>6<integer_literal/>"
            "<exprlist/>"
          "<paren_form/>"
          "<paren_form>"
            "<exprlist>"
              "<integer_literal>7<integer_literal/>"
              "<integer_literal>8<integer_literal/>"
              "<integer_literal>9<integer_literal/>"
              "<integer_literal>10<integer_literal/>"
            "<exprlist/>"
          "<paren_form/>"
        "<exprlist/>"
      "<paren_form/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestListForm)
{
  test(
    "[];",
    wrap_single_expr(
      "<list_form><list_form/>"
    )
  );

  test(
    "[[], [], []];",
    wrap_single_expr(
      "<list_form>"
        "<exprlist>"
          "<list_form><list_form/>"
          "<list_form><list_form/>"
          "<list_form><list_form/>"
        "<exprlist/>"
      "<list_form/>"
    )
  );

  test(
    "[[[]]];",
    wrap_single_expr(
      "<list_form>"
        "<exprlist>"
          "<list_form>"
            "<exprlist>"
              "<list_form><list_form/>"
            "<exprlist/>"
          "<list_form/>"
        "<exprlist/>"
      "<list_form/>"
    )
  );

  test(
    "[1, 2, 4, 8, 16, 32];",
    wrap_single_expr(
      "<list_form>"
        "<exprlist>"
          "<integer_literal>1<integer_literal/>"
          "<integer_literal>2<integer_literal/>"
          "<integer_literal>4<integer_literal/>"
          "<integer_literal>8<integer_literal/>"
          "<integer_literal>16<integer_literal/>"
          "<integer_literal>32<integer_literal/>"
        "<exprlist/>"
      "<list_form/>"
    )
  );

  test(
    "[for i in 1...100];",
    wrap_single_expr(
      "<list_form>"
        "<comprehension>"
          "<comprehension-candidates>"
            "<target_list>"
              "<identifier>i<identifier/>"
            "<target_list/>"
          "<comprehension-candidates/>"
          "<comprehension-source>"
            "<exprlist>"
              "<inclusive_range_expr>"
                "<inclusive_range_expr-begin>"
                  "<integer_literal>1<integer_literal/>"
                "<inclusive_range_expr-begin/>"
                "<inclusive_range_expr-end>"
                  "<integer_literal>100<integer_literal/>"
                "<inclusive_range_expr-end/>"
              "<inclusive_range_expr/>"
            "<exprlist/>"
          "<comprehension-source/>"
        "<comprehension/>"
      "<list_form/>"
    )
  );

  test(
    "[for i in 1...100 if isprime(i)];",
    wrap_single_expr(
      "<list_form>"
        "<comprehension>"
          "<comprehension-candidates>"
            "<target_list>"
              "<identifier>i<identifier/>"
            "<target_list/>"
          "<comprehension-candidates/>"
          "<comprehension-source>"
            "<exprlist>"
              "<inclusive_range_expr>"
                "<inclusive_range_expr-begin>"
                  "<integer_literal>1<integer_literal/>"
                "<inclusive_range_expr-begin/>"
                "<inclusive_range_expr-end>"
                  "<integer_literal>100<integer_literal/>"
                "<inclusive_range_expr-end/>"
              "<inclusive_range_expr/>"
            "<exprlist/>"
          "<comprehension-source/>"
          "<comprehension-predicate>"
            "<call>"
              "<call-source>"
                "<identifier>isprime<identifier/>"
              "<call-source/>"
              "<call-args>"
                "<arg_list>"
                  "<arg_list-simple_args>"
                    "<val_atom_list>"
                      "<identifier>i<identifier/>"
                    "<val_atom_list/>"
                  "<arg_list-simple_args/>"
                "<arg_list/>"
              "<call-args/>"
            "<call/>"
          "<comprehension-predicate/>"
        "<comprehension/>"
      "<list_form/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestDictForm)
{
  test(
    "{};",
    wrap_single_expr(
      "<dict_form><dict_form/>"
    )
  );

  test(
    "{a: 1, b: 2};",
    wrap_single_expr(
      "<dict_form>"
        "<field_def_list>"
          "<field_def>"
            "<field_def-name>"
              "<identifier>a<identifier/>"
            "<field_def-name/>"
            "<field_def-val>"
              "<integer_literal>1<integer_literal/>"
            "<field_def-val/>"
          "<field_def/>"
          "<field_def>"
            "<field_def-name>"
              "<identifier>b<identifier/>"
            "<field_def-name/>"
            "<field_def-val>"
              "<integer_literal>2<integer_literal/>"
            "<field_def-val/>"
          "<field_def/>"
        "<field_def_list/>"
      "<dict_form/>"
    )
  );

  test(
    "{list: [], paren: (1), dict: {}};",
    wrap_single_expr(
      "<dict_form>"
        "<field_def_list>"
          "<field_def>"
            "<field_def-name>"
              "<identifier>list<identifier/>"
            "<field_def-name/>"
            "<field_def-val>"
              "<list_form><list_form/>"
            "<field_def-val/>"
          "<field_def/>"
          "<field_def>"
            "<field_def-name>"
              "<identifier>paren<identifier/>"
            "<field_def-name/>"
            "<field_def-val>"
              "<paren_form>"
                "<exprlist>"
                  "<integer_literal>1<integer_literal/>"
                "<exprlist/>"
              "<paren_form/>"
            "<field_def-val/>"
          "<field_def/>"
          "<field_def>"
            "<field_def-name>"
              "<identifier>dict<identifier/>"
            "<field_def-name/>"
            "<field_def-val>"
              "<dict_form><dict_form/>"
            "<field_def-val/>"
          "<field_def/>"
        "<field_def_list/>"
      "<dict_form/>"
    )
  );

  test(
    "{a: {b: {c: {}}}};",
    wrap_single_expr(
      "<dict_form>"
        "<field_def_list>"
          "<field_def>"
            "<field_def-name>"
              "<identifier>a<identifier/>"
            "<field_def-name/>"
            "<field_def-val>"
              "<dict_form>"
                "<field_def_list>"
                  "<field_def>"
                    "<field_def-name>"
                      "<identifier>b<identifier/>"
                    "<field_def-name/>"
                    "<field_def-val>"
                      "<dict_form>"
                        "<field_def_list>"
                          "<field_def>"
                            "<field_def-name>"
                              "<identifier>c<identifier/>"
                            "<field_def-name/>"
                            "<field_def-val>"
                              "<dict_form>"
                              "<dict_form/>"
                            "<field_def-val/>"
                          "<field_def/>"
                        "<field_def_list/>"
                      "<dict_form/>"
                    "<field_def-val/>"
                  "<field_def/>"
                "<field_def_list/>"
              "<dict_form/>"
            "<field_def-val/>"
          "<field_def/>"
        "<field_def_list/>"
      "<dict_form/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestMapForm)
{
  test(
    "{apples => 10, oranges => 15};",
    wrap_single_expr(
      "<map_form>"
        "<map_field_list>"
          "<map_field>"
            "<map_field-key>"
              "<identifier>apples<identifier/>"
            "<map_field-key/>"
            "<map_field-val>"
              "<integer_literal>10<integer_literal/>"
            "<map_field-val/>"
          "<map_field/>"
          "<map_field>"
            "<map_field-key>"
              "<identifier>oranges<identifier/>"
            "<map_field-key/>"
            "<map_field-val>"
              "<integer_literal>15<integer_literal/>"
            "<map_field-val/>"
          "<map_field/>"
        "<map_field_list/>"
      "<map_form/>"
    )
  );

  test(
    "{fruits => {citrus => {orange => 10}}};",
    wrap_single_expr(
      "<map_form>"
        "<map_field_list>"
          "<map_field>"
            "<map_field-key>"
              "<identifier>fruits<identifier/>"
            "<map_field-key/>"
            "<map_field-val>"
              "<map_form>"
                "<map_field_list>"
                  "<map_field>"
                    "<map_field-key>"
                      "<identifier>citrus<identifier/>"
                    "<map_field-key/>"
                    "<map_field-val>"
                      "<map_form>"
                        "<map_field_list>"
                          "<map_field>"
                            "<map_field-key>"
                              "<identifier>orange<identifier/>"
                            "<map_field-key/>"
                            "<map_field-val>"
                              "<integer_literal>10<integer_literal/>"
                            "<map_field-val/>"
                          "<map_field/>"
                        "<map_field_list/>"
                      "<map_form/>"
                    "<map_field-val/>"
                  "<map_field/>"
                "<map_field_list/>"
              "<map_form/>"
            "<map_field-val/>"
          "<map_field/>"
        "<map_field_list/>"
      "<map_form/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestLambdaSimple)
{
  test(
    "sqr = (x) -> x * x;",
    wrap_single_stmt(
      "<assignment_stmt>"
        "<assignment_stmt-dst>"
          "<identifier>sqr<identifier/>"
        "<assignment_stmt-dst/>"
        "<assignment_stmt-src>"
          "<lambda_simple>"
            "<lambda_simple-params>"
              "<parameter_list>"
                "<parameter_list-simple_params>"
                  "<simple_parameter_list>"
                    "<identifier>x<identifier/>"
                  "<simple_parameter_list/>"
                "<parameter_list-simple_params/>"
              "<parameter_list/>"
            "<lambda_simple-params/>"
            "<lambda_simple-expr>"
              "<multiply_expr>"
                "<multiply_expr-left>"
                  "<identifier>x<identifier/>"
                "<multiply_expr-left/>"
                "<multiply_expr-right>"
                  "<identifier>x<identifier/>"
                "<multiply_expr-right/>"
              "<multiply_expr/>"
            "<lambda_simple-expr/>"
          "<lambda_simple/>"
        "<assignment_stmt-src/>"
      "<assignment_stmt/>"
    )
  );

  test(
    "wrapper = (func, *args, **kwargs) -> func(session(), *args, **kwargs);",
    wrap_single_stmt(
      "<assignment_stmt>"
        "<assignment_stmt-dst>"
          "<identifier>wrapper<identifier/>"
        "<assignment_stmt-dst/>"
        "<assignment_stmt-src>"
          "<lambda_simple>"
            "<lambda_simple-params>"
              "<parameter_list>"
                "<parameter_list-simple_params>"
                  "<simple_parameter_list>"
                    "<identifier>func<identifier/>"
                  "<simple_parameter_list/>"
                "<parameter_list-simple_params/>"
                "<parameter_list-args>"
                  "<identifier>args<identifier/>"
                "<parameter_list-args/>"
                "<parameter_list-kwargs>"
                  "<identifier>kwargs<identifier/>"
                "<parameter_list-kwargs/>"
              "<parameter_list/>"
            "<lambda_simple-params/>"
            "<lambda_simple-expr>"
              "<call>"
                "<call-source>"
                  "<identifier>func<identifier/>"
                "<call-source/>"
                "<call-args>"
                  "<arg_list>"
                    "<arg_list-simple_args>"
                      "<val_atom_list>"
                        "<call>"
                          "<call-source>"
                            "<identifier>session<identifier/>"
                          "<call-source/>"
                        "<call/>"
                      "<val_atom_list/>"
                    "<arg_list-simple_args/>"
                    "<arg_list-args>"
                      "<identifier>args<identifier/>"
                    "<arg_list-args/>"
                    "<arg_list-kwargs>"
                      "<identifier>kwargs<identifier/>"
                    "<arg_list-kwargs/>"
                  "<arg_list/>"
                "<call-args/>"
              "<call/>"
            "<lambda_simple-expr/>"
          "<lambda_simple/>"
        "<assignment_stmt-src/>"
      "<assignment_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestLambdaComplex)
{
  test(
    "inc = (n) => {"
      "n++;"
    "};",
    wrap_single_stmt(
      "<assignment_stmt>"
        "<assignment_stmt-dst>"
          "<identifier>inc<identifier/>"
        "<assignment_stmt-dst/>"
        "<assignment_stmt-src>"
          "<lambda_complex>"
            "<lambda_complex-params>"
              "<parameter_list>"
                "<parameter_list-simple_params>"
                  "<simple_parameter_list>"
                    "<identifier>n<identifier/>"
                  "<simple_parameter_list/>"
                "<parameter_list-simple_params/>"
              "<parameter_list/>"
            "<lambda_complex-params/>"
            "<lambda_complex-stmts>"
              "<stmt_group>"
                "<expr_list_stmt>"
                  "<exprlist>"
                    "<increment_expr>"
                      "<identifier>n<identifier/>"
                    "<increment_expr/>"
                  "<exprlist/>"
                "<expr_list_stmt/>"
              "<stmt_group/>"
            "<lambda_complex-stmts/>"
          "<lambda_complex/>"
        "<assignment_stmt-src/>"
      "<assignment_stmt/>"
    )
  );

  test(
    "@with_txn(session=true)"
"\n"
    "@log_error"
"\n"
    "commit_transaction = (session, changes, user_id, lock_db=true, **kwargs) => {"
      "log(\"Begin transaction from %s\" % user_id);"
      "changes = self.validate_and_filter_changes(changes, user_id);"
      "self._commit(changes, user_id, lock_db=lock_db, **kwargs);"
    "};",
    wrap_single_stmt(
      "<assignment_stmt>"
        "<assignment_stmt-decorators>"
          "<decorator_list>"
            "<decorator>"
              "<decorator-name>"
                "<name>"
                  "<identifier>with_txn<identifier/>"
                "<name/>"
              "<decorator-name/>"
              "<decorator-args>"
                "<arg_list>"
                  "<arg_list-keyword_args>"
                    "<keyword_val_list>"
                      "<keyword_val>"
                        "<keyword_val-key>"
                          "<identifier>session<identifier/>"
                        "<keyword_val-key/>"
                        "<keyword_val-val>"
                          "<identifier>true<identifier/>"
                        "<keyword_val-val/>"
                      "<keyword_val/>"
                    "<keyword_val_list/>"
                  "<arg_list-keyword_args/>"
                "<arg_list/>"
              "<decorator-args/>"
            "<decorator/>"
            "<decorator>"
              "<decorator-name>"
                "<name>"
                  "<identifier>log_error<identifier/>"
                "<name/>"
              "<decorator-name/>"
            "<decorator/>"
          "<decorator_list/>"
        "<assignment_stmt-decorators/>"
        "<assignment_stmt-dst>"
          "<identifier>commit_transaction<identifier/>"
        "<assignment_stmt-dst/>"
        "<assignment_stmt-src>"
          "<lambda_complex>"
            "<lambda_complex-params>"
              "<parameter_list>"
                "<parameter_list-simple_params>"
                  "<simple_parameter_list>"
                    "<identifier>session<identifier/>"
                    "<identifier>changes<identifier/>"
                    "<identifier>user_id<identifier/>"
                  "<simple_parameter_list/>"
                "<parameter_list-simple_params/>"
                "<parameter_list-keyword_params>"
                  "<keyword_val_list>"
                    "<keyword_val>"
                      "<keyword_val-key>"
                        "<identifier>lock_db<identifier/>"
                      "<keyword_val-key/>"
                      "<keyword_val-val>"
                        "<identifier>true<identifier/>"
                      "<keyword_val-val/>"
                    "<keyword_val/>"
                  "<keyword_val_list/>"
                "<parameter_list-keyword_params/>"
                "<parameter_list-kwargs>"
                  "<identifier>kwargs<identifier/>"
                "<parameter_list-kwargs/>"
              "<parameter_list/>"
            "<lambda_complex-params/>"
            "<lambda_complex-stmts>"
              "<stmt_group>"
                "<expr_list_stmt>"
                  "<exprlist>"
                    "<call>"
                      "<call-source>"
                        "<identifier>log<identifier/>"
                      "<call-source/>"
                      "<call-args>"
                      "<arg_list>"
                          "<arg_list-simple_args>"
                            "<val_atom_list>"
                              "<modulus_expr>"
                                "<modulus_expr-left>"
                                  "<string_literal>\"Begin transaction from %s\"<string_literal/>"
                                "<modulus_expr-left/>"
                                "<modulus_expr-right>"
                                  "<identifier>user_id<identifier/>"
                                "<modulus_expr-right/>"
                              "<modulus_expr/>"
                            "<val_atom_list/>"
                          "<arg_list-simple_args/>"
                        "<arg_list/>"
                      "<call-args/>"
                    "<call/>"
                  "<exprlist/>"
                "<expr_list_stmt/>"
                "<assignment_stmt>"
                  "<assignment_stmt-dst>"
                    "<identifier>changes<identifier/>"
                  "<assignment_stmt-dst/>"
                  "<assignment_stmt-src>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>self<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>validate_and_filter_changes<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<identifier>changes<identifier/>"
                                "<identifier>user_id<identifier/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<assignment_stmt-src/>"
                "<assignment_stmt/>"
                "<expr_list_stmt>"
                  "<exprlist>"
                    "<call>"
                      "<call-source>"
                        "<attribute>"
                          "<attribute-source>"
                            "<identifier>self<identifier/>"
                          "<attribute-source/>"
                          "<attribute-target>"
                            "<identifier>_commit<identifier/>"
                          "<attribute-target/>"
                        "<attribute/>"
                      "<call-source/>"
                      "<call-args>"
                        "<arg_list>"
                          "<arg_list-simple_args>"
                            "<val_atom_list>"
                              "<identifier>changes<identifier/>"
                              "<identifier>user_id<identifier/>"
                            "<val_atom_list/>"
                          "<arg_list-simple_args/>"
                          "<arg_list-keyword_args>"
                            "<keyword_val_list>"
                              "<keyword_val>"
                                "<keyword_val-key>"
                                  "<identifier>lock_db<identifier/>"
                                "<keyword_val-key/>"
                                "<keyword_val-val>"
                                  "<identifier>lock_db<identifier/>"
                                "<keyword_val-val/>"
                              "<keyword_val/>"
                            "<keyword_val_list/>"
                          "<arg_list-keyword_args/>"
                          "<arg_list-kwargs>"
                            "<identifier>kwargs<identifier/>"
                          "<arg_list-kwargs/>"
                        "<arg_list/>"
                      "<call-args/>"
                    "<call/>"
                  "<exprlist/>"
                "<expr_list_stmt/>"
              "<stmt_group/>"
            "<lambda_complex-stmts/>"
          "<lambda_complex/>"
        "<assignment_stmt-src/>"
      "<assignment_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestInputStmt)
{
  test(
    "stdout <<< logging.log <<< filters <<< src();",
    wrap_single_stmt(
      "<input_stmt>"
        "<input_stmt-component>"
          "<identifier>stdout<identifier/>"
        "<input_stmt-component/>"
        "<input_stmt-component>"
          "<attribute>"
            "<attribute-source>"
              "<identifier>logging<identifier/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>log<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<input_stmt-component/>"
        "<input_stmt-component>"
          "<identifier>filters<identifier/>"
        "<input_stmt-component/>"
        "<input_stmt-component>"
          "<call>"
            "<call-source>"
              "<identifier>src<identifier/>"
            "<call-source/>"
          "<call/>"
        "<input_stmt-component/>"
      "<input_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestOutputStmt)
{
  test(
    "stdin >>> logging.log >>> filters >>> dst();",
    wrap_single_stmt(
      "<output_stmt>"
        "<output_stmt-component>"
          "<identifier>stdin<identifier/>"
        "<output_stmt-component/>"
        "<output_stmt-component>"
          "<attribute>"
            "<attribute-source>"
              "<identifier>logging<identifier/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>log<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<output_stmt-component/>"
        "<output_stmt-component>"
          "<identifier>filters<identifier/>"
        "<output_stmt-component/>"
        "<output_stmt-component>"
          "<call>"
            "<call-source>"
              "<identifier>dst<identifier/>"
            "<call-source/>"
          "<call/>"
        "<output_stmt-component/>"
      "<output_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestClassDef)
{
  test(
    "class MyObject;",
    wrap_single_stmt(
      "<class_def>"
        "<class_def-name>"
          "<identifier>MyObject<identifier/>"
        "<class_def-name/>"
      "<class_def/>"
    )
  );

  test(
    "class MyObject extends YourObject;",
    wrap_single_stmt(
      "<class_def>"
        "<class_def-name>"
          "<identifier>MyObject<identifier/>"
        "<class_def-name/>"
        "<class_def-parent>"
          "<name>"
            "<identifier>YourObject<identifier/>"
          "<name/>"
        "<class_def-parent/>"
      "<class_def/>"
    )
  );

    test(
    "@add_to_cache"
"\n"
    "class Student extends Person {"

      "grade: 8"
"\n"
      "courses: {}"
"\n"
      "hello: () -> hello_world()"
"\n"
    "}",
    wrap_single_stmt(
      "<class_def>"
        "<class_def-decorators>"
          "<decorator_list>"
            "<decorator>"
              "<decorator-name>"
                "<name>"
                  "<identifier>add_to_cache<identifier/>"
                "<name/>"
              "<decorator-name/>"
            "<decorator/>"
          "<decorator_list/>"
        "<class_def-decorators/>"
        "<class_def-name>"
          "<identifier>Student<identifier/>"
        "<class_def-name/>"
        "<class_def-parent>"
          "<name>"
            "<identifier>Person<identifier/>"
          "<name/>"
        "<class_def-parent/>"
        "<class_def-attributes>"
          "<attribute_def_list>"
            "<field_def>"
              "<field_def-name>"
                "<identifier>grade<identifier/>"
              "<field_def-name/>"
              "<field_def-val>"
                "<integer_literal>8<integer_literal/>"
              "<field_def-val/>"
            "<field_def/>"
            "<field_def>"
              "<field_def-name>"
                "<identifier>courses<identifier/>"
              "<field_def-name/>"
              "<field_def-val>"
                "<dict_form><dict_form/>"
              "<field_def-val/>"
            "<field_def/>"
            "<field_def>"
              "<field_def-name>"
                "<identifier>hello<identifier/>"
              "<field_def-name/>"
              "<field_def-val>"
                "<lambda_simple>"
                  "<lambda_simple-expr>"
                    "<call>"
                      "<call-source>"
                        "<identifier>hello_world<identifier/>"
                      "<call-source/>"
                    "<call/>"
                  "<lambda_simple-expr/>"
                "<lambda_simple/>"
              "<field_def-val/>"
            "<field_def/>"
          "<attribute_def_list/>"
        "<class_def-attributes/>"
      "<class_def/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestUsingStmt)
{
  test(
    "using http;",
    wrap_single_stmt(
      "<using_stmt_direct>"
        "<using_stmt_direct-target>"
          "<name>"
            "<identifier>http<identifier/>"
          "<name/>"
        "<using_stmt_direct-target/>"
      "<using_stmt_direct/>"
    )
  );

  test(
    "using rsa_hash as hash;",
    wrap_single_stmt(
      "<using_stmt_direct>"
        "<using_stmt_direct-target>"
          "<name>"
            "<identifier>rsa_hash<identifier/>"
          "<name/>"
        "<using_stmt_direct-target/>"
        "<using_stmt_direct-alias>"
          "<identifier>hash<identifier/>"
        "<using_stmt_direct-alias/>"
      "<using_stmt_direct/>"
    )
  );

  test(
    "using qsort, bsort, isort in sorts;",
    wrap_single_stmt(
      "<using_stmt_relative>"
        "<using_stmt_relative-targets>"
          "<target_list>"
            "<identifier>qsort<identifier/>"
            "<identifier>bsort<identifier/>"
            "<identifier>isort<identifier/>"
          "<target_list/>"
        "<using_stmt_relative-targets/>"
        "<using_stmt_relative-src>"
          "<using_src>"
            "<name>"
              "<identifier>sorts<identifier/>"
            "<name/>"
          "<using_src/>"
        "<using_stmt_relative-src/>"
      "<using_stmt_relative/>"
    )
  );

  test(
    "using encid, decid in lib.core.id;",
    wrap_single_stmt(
      "<using_stmt_relative>"
        "<using_stmt_relative-targets>"
          "<target_list>"
            "<identifier>encid<identifier/>"
            "<identifier>decid<identifier/>"
          "<target_list/>"
        "<using_stmt_relative-targets/>"
        "<using_stmt_relative-src>"
          "<using_src>"
            "<name>"
              "<identifier>lib<identifier/>"
              "<identifier>core<identifier/>"
              "<identifier>id<identifier/>"
            "<name/>"
          "<using_src/>"
        "<using_stmt_relative-src/>"
      "<using_stmt_relative/>"
    )
  );

  test(
    "using encid, decid in .;",
    wrap_single_stmt(
      "<using_stmt_relative>"
        "<using_stmt_relative-targets>"
          "<target_list>"
            "<identifier>encid<identifier/>"
            "<identifier>decid<identifier/>"
          "<target_list/>"
        "<using_stmt_relative-targets/>"
        "<using_stmt_relative-src>"
          "<using_src><using_src/>"
        "<using_stmt_relative-src/>"
      "<using_stmt_relative/>"
    )
  );

  // TODO: missing using target.
  test(
    "using * in lib;",
    wrap_single_stmt(
      "<using_stmt_relative>"
        "<using_stmt_relative-src>"
          "<using_src>"
            "<name>"
              "<identifier>lib<identifier/>"
            "<name/>"
          "<using_src/>"
        "<using_stmt_relative-src/>"
      "<using_stmt_relative/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestIfElseStmt)
{
  test(
    "if argc == 0 {"
      "hello_world();"
    "}",
    wrap_single_stmt(
      "<if_stmt>"
        "<if_stmt-predicate>"
          "<equals_expr>"
            "<equals_expr-left>"
              "<identifier>argc<identifier/>"
            "<equals_expr-left/>"
            "<equals_expr-right>"
              "<integer_literal>0<integer_literal/>"
            "<equals_expr-right/>"
          "<equals_expr/>"
        "<if_stmt-predicate/>"
        "<if_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<identifier>hello_world<identifier/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<if_stmt-stmts/>"
      "<if_stmt/>"
    )
  );

  test(
    "if(argc == 0){"
      "1;"
    "} else {"
      "-1;"
    "}",
    wrap_single_stmt(
      "<if_stmt>"
        "<if_stmt-predicate>"
          "<paren_form>"
            "<exprlist>"
              "<equals_expr>"
                "<equals_expr-left>"
                  "<identifier>argc<identifier/>"
                "<equals_expr-left/>"
                "<equals_expr-right>"
                  "<integer_literal>0<integer_literal/>"
                "<equals_expr-right/>"
              "<equals_expr/>"
            "<exprlist/>"
          "<paren_form/>"
        "<if_stmt-predicate/>"
        "<if_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<integer_literal>1<integer_literal/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<if_stmt-stmts/>"
        "<if_stmt-else_stmts>"
          "<else_stmt>"
            "<stmt_group>"
              "<expr_list_stmt>"
                "<exprlist>"
                  "<negative_expr>"
                    "<integer_literal>1<integer_literal/>"
                  "<negative_expr/>"
                "<exprlist/>"
              "<expr_list_stmt/>"
            "<stmt_group/>"
          "<else_stmt/>"
        "<if_stmt-else_stmts/>"
      "<if_stmt/>"
    )
  );

  test(
    "if argc == 0 {"
      "hello_world();"
    "} elif argc == 1 {"
      "print_usage();"
    "} else {"
      "exit(-1);"
    "}",
    wrap_single_stmt(
      "<if_stmt>"
        "<if_stmt-predicate>"
          "<equals_expr>"
            "<equals_expr-left>"
              "<identifier>argc<identifier/>"
            "<equals_expr-left/>"
            "<equals_expr-right>"
              "<integer_literal>0<integer_literal/>"
            "<equals_expr-right/>"
          "<equals_expr/>"
        "<if_stmt-predicate/>"
        "<if_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<identifier>hello_world<identifier/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<if_stmt-stmts/>"
        "<if_stmt-elif_stmts>"
          "<elif_stmt_group>"
            "<elif_stmt>"
              "<elif_stmt-predicate>"
                "<equals_expr>"
                  "<equals_expr-left>"
                    "<identifier>argc<identifier/>"
                  "<equals_expr-left/>"
                  "<equals_expr-right>"
                    "<integer_literal>1<integer_literal/>"
                  "<equals_expr-right/>"
                "<equals_expr/>"
              "<elif_stmt-predicate/>"
              "<elif_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<identifier>print_usage<identifier/>"
                        "<call-source/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<elif_stmt-stmts/>"
            "<elif_stmt/>"
          "<elif_stmt_group/>"
        "<if_stmt-elif_stmts/>"
        "<if_stmt-else_stmts>"
          "<else_stmt>"
            "<stmt_group>"
              "<expr_list_stmt>"
                "<exprlist>"
                  "<call>"
                    "<call-source>"
                      "<identifier>exit<identifier/>"
                    "<call-source/>"
                    "<call-args>"
                      "<arg_list>"
                        "<arg_list-simple_args>"
                          "<val_atom_list>"
                            "<negative_expr>"
                              "<integer_literal>1<integer_literal/>"
                            "<negative_expr/>"
                          "<val_atom_list/>"
                        "<arg_list-simple_args/>"
                      "<arg_list/>"
                    "<call-args/>"
                  "<call/>"
                "<exprlist/>"
              "<expr_list_stmt/>"
            "<stmt_group/>"
          "<else_stmt/>"
        "<if_stmt-else_stmts/>"
      "<if_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestForStmt)
{
  test(
    "for i in 1...100 {"
      "if isprime(i) {"
        "print(i);"
      "}"
    "}",
    wrap_single_stmt(
      "<for_stmt>"
        "<for_stmt-targets>"
          "<target_list>"
            "<identifier>i<identifier/>"
          "<target_list/>"
        "<for_stmt-targets/>"
        "<for_stmt-exprs>"
          "<exprlist>"
            "<inclusive_range_expr>"
              "<inclusive_range_expr-begin>"
                "<integer_literal>1<integer_literal/>"
              "<inclusive_range_expr-begin/>"
              "<inclusive_range_expr-end>"
                "<integer_literal>100<integer_literal/>"
              "<inclusive_range_expr-end/>"
            "<inclusive_range_expr/>"
          "<exprlist/>"
        "<for_stmt-exprs/>"
        "<for_stmt-stmts>"
          "<stmt_group>"
            "<if_stmt>"
              "<if_stmt-predicate>"
                "<call>"
                  "<call-source>"
                    "<identifier>isprime<identifier/>"
                  "<call-source/>"
                  "<call-args>"
                    "<arg_list>"
                      "<arg_list-simple_args>"
                        "<val_atom_list>"
                          "<identifier>i<identifier/>"
                        "<val_atom_list/>"
                      "<arg_list-simple_args/>"
                    "<arg_list/>"
                  "<call-args/>"
                "<call/>"
              "<if_stmt-predicate/>"
              "<if_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<identifier>print<identifier/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<identifier>i<identifier/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<if_stmt-stmts/>"
            "<if_stmt/>"
          "<stmt_group/>"
        "<for_stmt-stmts/>"
      "<for_stmt/>"
    )
  );

  test(
    "for i, j in [(i, i * 2) for i in 1...100] where i + j >= 50 {"
      "compute(i, j);"
    "}",
    wrap_single_stmt(
      "<for_stmt>"
        "<for_stmt-targets>"
          "<target_list>"
            "<identifier>i<identifier/>"
            "<identifier>j<identifier/>"
          "<target_list/>"
        "<for_stmt-targets/>"
        "<for_stmt-exprs>"
          "<exprlist>"
            "<list_form>"
              "<comprehension>"
                "<comprehension-dst>"
                  "<exprlist>"
                    "<paren_form>"
                      "<exprlist>"
                        "<identifier>i<identifier/>"
                        "<multiply_expr>"
                          "<multiply_expr-left>"
                            "<identifier>i<identifier/>"
                          "<multiply_expr-left/>"
                          "<multiply_expr-right>"
                            "<integer_literal>2<integer_literal/>"
                          "<multiply_expr-right/>"
                        "<multiply_expr/>"
                      "<exprlist/>"
                    "<paren_form/>"
                  "<exprlist/>"
                "<comprehension-dst/>"
                "<comprehension-candidates>"
                  "<target_list>"
                    "<identifier>i<identifier/>"
                  "<target_list/>"
                "<comprehension-candidates/>"
                "<comprehension-source>"
                  "<exprlist>"
                    "<inclusive_range_expr>"
                      "<inclusive_range_expr-begin>"
                        "<integer_literal>1<integer_literal/>"
                      "<inclusive_range_expr-begin/>"
                      "<inclusive_range_expr-end>"
                        "<integer_literal>100<integer_literal/>"
                      "<inclusive_range_expr-end/>"
                    "<inclusive_range_expr/>"
                  "<exprlist/>"
                "<comprehension-source/>"
              "<comprehension/>"
            "<list_form/>"
          "<exprlist/>"
        "<for_stmt-exprs/>"
        "<for_stmt-predicate>"
          "<ge_expr>"
            "<ge_expr-left>"
              "<add_expr>"
                "<add_expr-left>"
                  "<identifier>i<identifier/>"
                "<add_expr-left/>"
                "<add_expr-right>"
                  "<identifier>j<identifier/>"
                "<add_expr-right/>"
              "<add_expr/>"
            "<ge_expr-left/>"
            "<ge_expr-right>"
              "<integer_literal>50<integer_literal/>"
            "<ge_expr-right/>"
          "<ge_expr/>"
        "<for_stmt-predicate/>"
        "<for_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<identifier>compute<identifier/>"
                  "<call-source/>"
                  "<call-args>"
                    "<arg_list>"
                      "<arg_list-simple_args>"
                        "<val_atom_list>"
                          "<identifier>i<identifier/>"
                          "<identifier>j<identifier/>"
                        "<val_atom_list/>"
                      "<arg_list-simple_args/>"
                    "<arg_list/>"
                  "<call-args/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<for_stmt-stmts/>"
      "<for_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestWithStmt)
{
  test(
    "with self.logic.begin(session=True) as session {"
      "user = models.User.load(session, id);"
      "user.call();"
    "}",
    wrap_single_stmt(
      "<with_stmt>"
        "<with_stmt-exprs>"
          "<exprlist>"
            "<call>"
              "<call-source>"
                "<attribute>"
                  "<attribute-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>logic<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<attribute-source/>"
                  "<attribute-target>"
                    "<identifier>begin<identifier/>"
                  "<attribute-target/>"
                "<attribute/>"
              "<call-source/>"
                "<call-args>"
                  "<arg_list>"
                    "<arg_list-keyword_args>"
                      "<keyword_val_list>"
                        "<keyword_val>"
                          "<keyword_val-key>"
                            "<identifier>session<identifier/>"
                          "<keyword_val-key/>"
                          "<keyword_val-val>"
                            "<identifier>True<identifier/>"
                          "<keyword_val-val/>"
                        "<keyword_val/>"
                      "<keyword_val_list/>"
                    "<arg_list-keyword_args/>"
                  "<arg_list/>"
                "<call-args/>"
            "<call/>"
          "<exprlist/>"
        "<with_stmt-exprs/>"
        "<with_stmt-alias>"
          "<identifier>session<identifier/>"
        "<with_stmt-alias/>"
        "<with_stmt-stmts>"
          "<stmt_group>"
            "<assignment_stmt>"
              "<assignment_stmt-dst>"
                "<identifier>user<identifier/>"
              "<assignment_stmt-dst/>"
              "<assignment_stmt-src>"
                "<exprlist>"
                  "<call>"
                    "<call-source>"
                      "<attribute>"
                        "<attribute-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>models<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>User<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<attribute-source/>"
                        "<attribute-target>"
                          "<identifier>load<identifier/>"
                        "<attribute-target/>"
                      "<attribute/>"
                    "<call-source/>"
                    "<call-args>"
                      "<arg_list>"
                        "<arg_list-simple_args>"
                          "<val_atom_list>"
                            "<identifier>session<identifier/>"
                            "<identifier>id<identifier/>"
                          "<val_atom_list/>"
                        "<arg_list-simple_args/>"
                      "<arg_list/>"
                    "<call-args/>"
                  "<call/>"
                "<exprlist/>"
              "<assignment_stmt-src/>"
            "<assignment_stmt/>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>user<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>call<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<with_stmt-stmts/>"
      "<with_stmt/>"
    )
  );

  test(
    "with self.logic.begin(session=True), self.logic.cache() as session_cache {"
      "for user in self.get_users() {"
        "user.register(session_cache);"
      "}"
    "}",
    wrap_single_stmt(
      "<with_stmt>"
        "<with_stmt-exprs>"
          "<exprlist>"
            "<call>"
              "<call-source>"
                "<attribute>"
                  "<attribute-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>logic<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<attribute-source/>"
                  "<attribute-target>"
                    "<identifier>begin<identifier/>"
                  "<attribute-target/>"
                "<attribute/>"
              "<call-source/>"
              "<call-args>"
                "<arg_list>"
                  "<arg_list-keyword_args>"
                    "<keyword_val_list>"
                      "<keyword_val>"
                        "<keyword_val-key>"
                          "<identifier>session<identifier/>"
                        "<keyword_val-key/>"
                        "<keyword_val-val>"
                          "<identifier>True<identifier/>"
                        "<keyword_val-val/>"
                      "<keyword_val/>"
                    "<keyword_val_list/>"
                  "<arg_list-keyword_args/>"
                "<arg_list/>"
              "<call-args/>"
            "<call/>"
            "<call>"
              "<call-source>"
                "<attribute>"
                  "<attribute-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>logic<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<attribute-source/>"
                  "<attribute-target>"
                    "<identifier>cache<identifier/>"
                  "<attribute-target/>"
                "<attribute/>"
              "<call-source/>"
            "<call/>"
          "<exprlist/>"
        "<with_stmt-exprs/>"
        "<with_stmt-alias>"
          "<identifier>session_cache<identifier/>"
        "<with_stmt-alias/>"
        "<with_stmt-stmts>"
          "<stmt_group>"
            "<for_stmt>"
              "<for_stmt-targets>"
                "<target_list>"
                  "<identifier>user<identifier/>"
                "<target_list/>"
              "<for_stmt-targets/>"
              "<for_stmt-exprs>"
                "<exprlist>"
                  "<call>"
                    "<call-source>"
                      "<attribute>"
                        "<attribute-source>"
                          "<identifier>self<identifier/>"
                        "<attribute-source/>"
                        "<attribute-target>"
                          "<identifier>get_users<identifier/>"
                        "<attribute-target/>"
                      "<attribute/>"
                    "<call-source/>"
                  "<call/>"
                "<exprlist/>"
              "<for_stmt-exprs/>"
              "<for_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>user<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>register<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<identifier>session_cache<identifier/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<for_stmt-stmts/>"
            "<for_stmt/>"
          "<stmt_group/>"
        "<with_stmt-stmts/>"
      "<with_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestWhileStmt)
{
  test(
    "while 1 {"
      "hello_world();"
    "}",
    wrap_single_stmt(
      "<while_stmt>"
        "<while_stmt-expr>"
          "<integer_literal>1<integer_literal/>"
        "<while_stmt-expr/>"
        "<while_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<identifier>hello_world<identifier/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<while_stmt-stmts/>"
      "<while_stmt/>"
    )
  );

  test(
    "with self.logic.begin(session=True) as session {"
      "for user in self.get_users() {"
        "user.register(session);"
      "}"
    "}",
    wrap_single_stmt(
      "<with_stmt>"
        "<with_stmt-exprs>"
          "<exprlist>"
            "<call>"
              "<call-source>"
                "<attribute>"
                  "<attribute-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>logic<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<attribute-source/>"
                  "<attribute-target>"
                    "<identifier>begin<identifier/>"
                  "<attribute-target/>"
                "<attribute/>"
              "<call-source/>"
              "<call-args>"
                "<arg_list>"
                  "<arg_list-keyword_args>"
                    "<keyword_val_list>"
                      "<keyword_val>"
                        "<keyword_val-key>"
                          "<identifier>session<identifier/>"
                        "<keyword_val-key/>"
                        "<keyword_val-val>"
                          "<identifier>True<identifier/>"
                        "<keyword_val-val/>"
                      "<keyword_val/>"
                    "<keyword_val_list/>"
                  "<arg_list-keyword_args/>"
                "<arg_list/>"
              "<call-args/>"
            "<call/>"
          "<exprlist/>"
        "<with_stmt-exprs/>"
        "<with_stmt-alias>"
          "<identifier>session<identifier/>"
        "<with_stmt-alias/>"
        "<with_stmt-stmts>"
          "<stmt_group>"
            "<for_stmt>"
              "<for_stmt-targets>"
                "<target_list>"
                  "<identifier>user<identifier/>"
                "<target_list/>"
              "<for_stmt-targets/>"
              "<for_stmt-exprs>"
                "<exprlist>"
                  "<call>"
                    "<call-source>"
                      "<attribute>"
                        "<attribute-source>"
                          "<identifier>self<identifier/>"
                        "<attribute-source/>"
                        "<attribute-target>"
                          "<identifier>get_users<identifier/>"
                        "<attribute-target/>"
                      "<attribute/>"
                    "<call-source/>"
                  "<call/>"
                "<exprlist/>"
              "<for_stmt-exprs/>"
              "<for_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>user<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>register<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<identifier>session<identifier/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<for_stmt-stmts/>"
            "<for_stmt/>"
          "<stmt_group/>"
        "<with_stmt-stmts/>"
      "<with_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestLockStmt)
{
  test(
    "lock self.counter {"
      "self.increment_counter();"
    "}",
    wrap_single_stmt(
      "<lock_stmt>"
        "<lock_stmt-exprs>"
          "<exprlist>"
            "<attribute>"
              "<attribute-source>"
                "<identifier>self<identifier/>"
              "<attribute-source/>"
              "<attribute-target>"
                "<identifier>counter<identifier/>"
              "<attribute-target/>"
            "<attribute/>"
          "<exprlist/>"
        "<lock_stmt-exprs/>"
        "<lock_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>""increment_counter<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<lock_stmt-stmts/>"
      "<lock_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestTryCatchStmt)
{
  test(
    "try {"
      "self.do_something_dangerous();"
    "} catch {"
      "print(\'Everything is alright.\');"
    "}",
    wrap_single_stmt(
      "<try_stmt>"
        "<try_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>do_something_dangerous<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<try_stmt-stmts/>"
        "<try_stmt-catch_stmts>"
          "<catch_stmt_group>"
            "<catch_stmt>"
              "<catch_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<identifier>print<identifier/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<string_literal>\'Everything is alright.\'<string_literal/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<catch_stmt-stmts/>"
            "<catch_stmt/>"
          "<catch_stmt_group/>"
        "<try_stmt-catch_stmts/>"
      "<try_stmt/>"
    )
  );

  test(
    "try {"
      "self.do_something_dangerous();"
    "} catch IOError, SocketError, MemError as e {"
      "self.log_error(e);"
      "print(\'Everything is alright.\');"
    "} catch OperationalError {"
      "self.log_error(e);"
      "exit(-1);"
    "}",
    wrap_single_stmt(
      "<try_stmt>"
        "<try_stmt-stmts>"
          "<stmt_group>"
            "<expr_list_stmt>"
              "<exprlist>"
                "<call>"
                  "<call-source>"
                    "<attribute>"
                      "<attribute-source>"
                        "<identifier>self<identifier/>"
                      "<attribute-source/>"
                      "<attribute-target>"
                        "<identifier>do_something_dangerous<identifier/>"
                      "<attribute-target/>"
                    "<attribute/>"
                  "<call-source/>"
                "<call/>"
              "<exprlist/>"
            "<expr_list_stmt/>"
          "<stmt_group/>"
        "<try_stmt-stmts/>"
        "<try_stmt-catch_stmts>"
          "<catch_stmt_group>"
            "<catch_stmt>"
              "<catch_stmt-targets>"
                "<target_list>"
                  "<identifier>IOError<identifier/>"
                  "<identifier>SocketError<identifier/>"
                  "<identifier>MemError<identifier/>"
                "<target_list/>"
              "<catch_stmt-targets/>"
              "<catch_stmt-alias>"
                "<identifier>e<identifier/>"
              "<catch_stmt-alias/>"
              "<catch_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>self<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>log_error<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<identifier>e<identifier/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<identifier>print<identifier/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<string_literal>\'Everything is alright.\'<string_literal/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<catch_stmt-stmts/>"
            "<catch_stmt/>"
            "<catch_stmt>"
              "<catch_stmt-targets>"
                "<target_list>"
                  "<identifier>OperationalError<identifier/>"
                "<target_list/>"
              "<catch_stmt-targets/>"
              "<catch_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>self<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>log_error<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<identifier>e<identifier/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<identifier>exit<identifier/>"
                        "<call-source/>"
                        "<call-args>"
                          "<arg_list>"
                            "<arg_list-simple_args>"
                              "<val_atom_list>"
                                "<negative_expr>"
                                  "<integer_literal>1<integer_literal/>"
                                "<negative_expr/>"
                              "<val_atom_list/>"
                            "<arg_list-simple_args/>"
                          "<arg_list/>"
                        "<call-args/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<catch_stmt-stmts/>"
            "<catch_stmt/>"
          "<catch_stmt_group/>"
        "<try_stmt-catch_stmts/>"
      "<try_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestAwaitStmt)
{
  test(
    "await {"
      "for _ in 1...10 {"
        "self.run() async;"
      "}"
    "}",
    wrap_single_stmt(
      "<await_stmt>"
        "<await_stmt-stmts>"
          "<stmt_group>"
            "<for_stmt>"
              "<for_stmt-targets>"
                "<target_list>"
                  "<identifier>_<identifier/>"
                "<target_list/>"
              "<for_stmt-targets/>"
              "<for_stmt-exprs>"
                "<exprlist>"
                  "<inclusive_range_expr>"
                    "<inclusive_range_expr-begin>"
                      "<integer_literal>1<integer_literal/>"
                    "<inclusive_range_expr-begin/>"
                    "<inclusive_range_expr-end>"
                      "<integer_literal>10<integer_literal/>"
                    "<inclusive_range_expr-end/>"
                  "<inclusive_range_expr/>"
                "<exprlist/>"
              "<for_stmt-exprs/>"
              "<for_stmt-stmts>"
                "<stmt_group>"
                  "<expr_list_stmt>"
                    "<exprlist>"
                      "<call>"
                        "<call-source>"
                          "<attribute>"
                            "<attribute-source>"
                              "<identifier>self<identifier/>"
                            "<attribute-source/>"
                            "<attribute-target>"
                              "<identifier>run<identifier/>"
                            "<attribute-target/>"
                          "<attribute/>"
                        "<call-source/>"
                      "<call/>"
                    "<exprlist/>"
                  "<expr_list_stmt/>"
                "<stmt_group/>"
              "<for_stmt-stmts/>"
            "<for_stmt/>"
          "<stmt_group/>"
        "<await_stmt-stmts/>"
      "<await_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestReturnStmt)
{
  test(
    "return;",
    wrap_single_stmt(
      "<return_stmt><return_stmt/>"
    )
  );

  test(
    "return obj;",
    wrap_single_stmt(
      "<return_stmt>"
        "<return_stmt-return_vals>"
          "<exprlist>"
            "<identifier>obj<identifier/>"
          "<exprlist/>"
        "<return_stmt-return_vals/>"
      "<return_stmt/>"
    )
  );

  test(
    "return num if isprime(num);",
    wrap_single_stmt(
      "<return_stmt>"
        "<return_stmt-return_vals>"
          "<exprlist>"
            "<identifier>num<identifier/>"
          "<exprlist/>"
        "<return_stmt-return_vals/>"
        "<return_vals-predicate>"
          "<call>"
            "<call-source>"
              "<identifier>isprime<identifier/>"
            "<call-source/>"
            "<call-args>"
              "<arg_list>"
                "<arg_list-simple_args>"
                  "<val_atom_list>"
                    "<identifier>num<identifier/>"
                  "<val_atom_list/>"
                "<arg_list-simple_args/>"
              "<arg_list/>"
            "<call-args/>"
          "<call/>"
        "<return_vals-predicate/>"
      "<return_stmt/>"
    )
  );

  test(
    "return 1, 2, 3;",
    wrap_single_stmt(
      "<return_stmt>"
        "<return_stmt-return_vals>"
          "<exprlist>"
            "<integer_literal>1<integer_literal/>"
            "<integer_literal>2<integer_literal/>"
            "<integer_literal>3<integer_literal/>"
          "<exprlist/>"
        "<return_stmt-return_vals/>"
      "<return_stmt/>"
    )
  );

  test(
    "return x, y, z if sum(x, y) == z;",
    wrap_single_stmt(
      "<return_stmt>"
        "<return_stmt-return_vals>"
          "<exprlist>"
            "<identifier>x<identifier/>"
            "<identifier>y<identifier/>"
            "<identifier>z<identifier/>"
          "<exprlist/>"
        "<return_stmt-return_vals/>"
        "<return_vals-predicate>"
          "<equals_expr>"
            "<equals_expr-left>"
              "<call>"
                "<call-source>"
                  "<identifier>sum<identifier/>"
                "<call-source/>"
                "<call-args>"
                  "<arg_list>"
                    "<arg_list-simple_args>"
                      "<val_atom_list>"
                        "<identifier>x<identifier/>"
                        "<identifier>y<identifier/>"
                      "<val_atom_list/>"
                    "<arg_list-simple_args/>"
                  "<arg_list/>"
                "<call-args/>"
              "<call/>"
            "<equals_expr-left/>"
            "<equals_expr-right>"
              "<identifier>z<identifier/>"
            "<equals_expr-right/>"
          "<equals_expr/>"
        "<return_vals-predicate/>"
      "<return_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestBreakStmt)
{
  test(
    "break;",
    wrap_single_stmt(
      "<break_stmt><break_stmt/>"
    )
  );

  test(
    "break if self.job.stopped;",
    wrap_single_stmt(
      "<break_stmt>"
        "<break_vals-predicate>"
          "<attribute>"
            "<attribute-source>"
              "<attribute>"
                "<attribute-source>"
                  "<identifier>self<identifier/>"
                "<attribute-source/>"
                "<attribute-target>"
                  "<identifier>job<identifier/>"
                "<attribute-target/>"
              "<attribute/>"
            "<attribute-source/>"
            "<attribute-target>"
              "<identifier>stopped<identifier/>"
            "<attribute-target/>"
          "<attribute/>"
        "<break_vals-predicate/>"
      "<break_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestContinueStmt)
{
  test(
    "continue;",
    wrap_single_stmt(
      "<continue_stmt><continue_stmt/>"
    )
  );

  test(
    "continue if self.skip(i);",
    wrap_single_stmt(
      "<continue_stmt>"
        "<continue_vals-predicate>"
          "<call>"
            "<call-source>"
              "<attribute>"
                "<attribute-source>"
                  "<identifier>self<identifier/>"
                "<attribute-source/>"
                "<attribute-target>"
                  "<identifier>skip<identifier/>"
                "<attribute-target/>"
              "<attribute/>"
            "<call-source/>"
            "<call-args>"
              "<arg_list>"
                "<arg_list-simple_args>"
                  "<val_atom_list>"
                    "<identifier>i<identifier/>"
                  "<val_atom_list/>"
                "<arg_list-simple_args/>"
              "<arg_list/>"
            "<call-args/>"
          "<call/>"
        "<continue_vals-predicate/>"
      "<continue_stmt/>"
    )
  );
}

TEST_F(HexParserXmlTest, TestRaiseStmt)
{
  test(
    "raise IOError();",
    wrap_single_stmt(
      "<raise_stmt>"
        "<raise_stmt-expr>"
          "<call>"
            "<call-source>"
              "<identifier>IOError<identifier/>"
            "<call-source/>"
          "<call/>"
        "<raise_stmt-expr/>"
      "<raise_stmt/>"
    )
  );

  test(
    "raise errors.OperationalError();",
    wrap_single_stmt(
      "<raise_stmt>"
        "<raise_stmt-expr>"
          "<call>"
            "<call-source>"
              "<attribute>"
                "<attribute-source>"
                  "<identifier>errors<identifier/>"
                "<attribute-source/>"
                "<attribute-target>"
                  "<identifier>OperationalError<identifier/>"
                "<attribute-target/>"
              "<attribute/>"
            "<call-source/>"
          "<call/>"
        "<raise_stmt-expr/>"
      "<raise_stmt/>"
    )
  );
}