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

#include <vector>
#include "hex_parser_test_file.h"
#include "parser_xml_test_base.h"

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

std::vector<HexTestFile> hex_parser_expr_precedence_testfiles = {
  /* 0  */ {"./assets/precedence/hex_precedence_test_00.hex", "./assets/precedence/xml/hex_precedence_test_00.xml"},
  /* 1  */ {"./assets/precedence/hex_precedence_test_01.hex", "./assets/precedence/xml/hex_precedence_test_01.xml"},
  /* 2  */ {"./assets/precedence/hex_precedence_test_02.hex", "./assets/precedence/xml/hex_precedence_test_02.xml"},
  /* 3  */ {"./assets/precedence/hex_precedence_test_03.hex", "./assets/precedence/xml/hex_precedence_test_03.xml"},
  /* 4  */ {"./assets/precedence/hex_precedence_test_04.hex", "./assets/precedence/xml/hex_precedence_test_04.xml"},
  /* 5  */ {"./assets/precedence/hex_precedence_test_05.hex", "./assets/precedence/xml/hex_precedence_test_05.xml"},
  /* 6  */ {"./assets/precedence/hex_precedence_test_06.hex", "./assets/precedence/xml/hex_precedence_test_06.xml"},
  /* 7  */ {"./assets/precedence/hex_precedence_test_07.hex", "./assets/precedence/xml/hex_precedence_test_07.xml"},
  /* 8  */ {"./assets/precedence/hex_precedence_test_08.hex", "./assets/precedence/xml/hex_precedence_test_08.xml"},
  /* 9  */ {"./assets/precedence/hex_precedence_test_09.hex", "./assets/precedence/xml/hex_precedence_test_09.xml"},
  /* 10 */ {"./assets/precedence/hex_precedence_test_10.hex", "./assets/precedence/xml/hex_precedence_test_10.xml"},
  /* 11 */ {"./assets/precedence/hex_precedence_test_11.hex", "./assets/precedence/xml/hex_precedence_test_11.xml"},
  /* 12 */ {"./assets/precedence/hex_precedence_test_12.hex", "./assets/precedence/xml/hex_precedence_test_12.xml"},
  /* 13 */ {"./assets/precedence/hex_precedence_test_13.hex", "./assets/precedence/xml/hex_precedence_test_13.xml"},
  /* 14 */ {"./assets/precedence/hex_precedence_test_14.hex", "./assets/precedence/xml/hex_precedence_test_14.xml"},
  /* 15 */ {"./assets/precedence/hex_precedence_test_15.hex", "./assets/precedence/xml/hex_precedence_test_15.xml"},
  /* 16 */ {"./assets/precedence/hex_precedence_test_16.hex", "./assets/precedence/xml/hex_precedence_test_16.xml"},
  /* 17 */ {"./assets/precedence/hex_precedence_test_17.hex", "./assets/precedence/xml/hex_precedence_test_17.xml"},
};

class HexParserExprPrecedenceTest : public HexParserXmlTestBase {
public:
  HexParserExprPrecedenceTest():
    HexParserXmlTestBase(hex_parser_expr_precedence_testfiles)
  {
    // Do nothing here.
  }
};

TEST_F(HexParserExprPrecedenceTest, TestPrecedence00) { test(0); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence01) { test(1); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence02) { test(2); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence03) { test(3); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence04) { test(4); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence05) { test(5); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence06) { test(6); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence07) { test(7); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence08) { test(8); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence09) { test(9); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence10) { test(10); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence11) { test(11); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence12) { test(12); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence13) { test(13); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence14) { test(14); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence15) { test(15); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence16) { test(16); }
TEST_F(HexParserExprPrecedenceTest, TestPrecedence17) { test(17); }