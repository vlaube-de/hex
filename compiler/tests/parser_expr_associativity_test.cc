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
 * assignment expr ------- RL
 ***************************************************/

std::vector<HexTestFile> hex_parser_expr_associativity_testfiles = {
  /* 0 */ {"./assets/associativity/hex_unary_expr.hex", "./assets/associativity/xml/hex_unary_expr.xml"},
  /* 1 */ {"./assets/associativity/hex_additive_expr.hex", "./assets/associativity/xml/hex_additive_expr.xml"},
  /* 2 */ {"./assets/associativity/hex_multiplicative_expr.hex", "./assets/associativity/xml/hex_multiplicative_expr.xml"},
  /* 3 */ {"./assets/associativity/hex_bitwise_shift_expr.hex", "./assets/associativity/xml/hex_bitwise_shift_expr.xml"},
  /* 4 */ {"./assets/associativity/hex_logical_and_expr.hex", "./assets/associativity/xml/hex_logical_and_expr.xml"},
  /* 5 */ {"./assets/associativity/hex_bitwise_xor_expr.hex", "./assets/associativity/xml/hex_bitwise_xor_expr.xml"},
  /* 6 */ {"./assets/associativity/hex_logical_or_expr.hex", "./assets/associativity/xml/hex_logical_or_expr.xml"},
  /* 7 */ {"./assets/associativity/hex_comparison_expr.hex", "./assets/associativity/xml/hex_comparison_expr.xml"},
  /* 8 */ {"./assets/associativity/hex_assignment_expr_1.hex", "./assets/associativity/xml/hex_assignment_expr_1.xml"},
  /* 9 */ {"./assets/associativity/hex_assignment_expr_2.hex", "./assets/associativity/xml/hex_assignment_expr_2.xml"}
};

class HexParserExprAssociativityTest : public HexParserXmlTestBase {
public:
  HexParserExprAssociativityTest():
    HexParserXmlTestBase(hex_parser_expr_associativity_testfiles)
  {
    // Do nothing here.
  }
};

TEST_F(HexParserExprAssociativityTest, TestUnaryExprAssociativity) { test(0); }
TEST_F(HexParserExprAssociativityTest, TestAdditiveExprAssociativity) { test(1); }
TEST_F(HexParserExprAssociativityTest, TestMultiplicativeExprAssociativity) { test(2); }
TEST_F(HexParserExprAssociativityTest, TestBitwiseShiftExprAssociativity) { test(3); }
TEST_F(HexParserExprAssociativityTest, TestLogicAndExprAssociativity) { test(4); }
TEST_F(HexParserExprAssociativityTest, TestBitwiseXorExprAssociativity) { test(5); }
TEST_F(HexParserExprAssociativityTest, TestLogicOrExprAssociativity) { test(6); }
TEST_F(HexParserExprAssociativityTest, TestComparisonExprAssociativity) { test(7); }
TEST_F(HexParserExprAssociativityTest, TestAssignmentExprAssociativity1) { test(8); }
TEST_F(HexParserExprAssociativityTest, TestAssignmentExprAssociativity2) { test(9); }