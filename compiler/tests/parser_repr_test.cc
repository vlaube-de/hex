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

#include "hex_parser_test_file.h"
#include "parser_test_base.h"
#include "parser_test_files.h"
#include "../ast/ast.h"
#include "../hex_parser.h"
#include "../visitor/ast_tostring_visitor.h"
#include "../../base/assert.h"
#include "../../base/freader.h"
#include "../../base/memory.h"
#include "../../base/unittest.h"

class HexParserReprTest : public HexParserTestBase {
protected:
  HexParserReprTest():
    HexParserTestBase(hex_parser_testfiles)
  {
    // Do nothing here.
  }

  virtual void test(int index);
};

void
HexParserReprTest::test(int index)
{
  AstToStringVisitor visitor;
  HexAstHexProgram program = NULL;

  c_str filepath = this->testfiles[index].filePath;

  c_str expected_str = NULL;
  FileReader freader(filepath);
  freader.read_file(&expected_str);
  HEX_ASSERT(expected_str);

  int res = parser->parse_from_file(filepath, &program);
  EXPECT_EQ(0, res);
  HEX_ASSERT(program);

  program->accept(&visitor);
  c_str actual_str = visitor.str();
  HEX_ASSERT(actual_str);

  ASSERT_STREQ(expected_str, actual_str);
}

TEST_F(HexParserReprTest, TestRepresentation00) { test(0); }
TEST_F(HexParserReprTest, TestRepresentation01) { test(1); }
TEST_F(HexParserReprTest, TestRepresentation02) { test(2); }
TEST_F(HexParserReprTest, TestRepresentation03) { test(3); }
TEST_F(HexParserReprTest, TestRepresentation04) { test(4); }
TEST_F(HexParserReprTest, TestRepresentation05) { test(5); }
TEST_F(HexParserReprTest, TestRepresentation06) { test(6); }
TEST_F(HexParserReprTest, TestRepresentation07) { test(7); }
TEST_F(HexParserReprTest, TestRepresentation08) { test(8); }
TEST_F(HexParserReprTest, TestRepresentation09) { test(9); }
TEST_F(HexParserReprTest, TestRepresentation10) { test(10); }
TEST_F(HexParserReprTest, TestRepresentation11) { test(11); }
TEST_F(HexParserReprTest, TestRepresentation12) { test(12); }
TEST_F(HexParserReprTest, TestRepresentation13) { test(13); }
TEST_F(HexParserReprTest, TestRepresentation14) { test(14); }
TEST_F(HexParserReprTest, TestRepresentation15) { test(15); }
TEST_F(HexParserReprTest, TestRepresentation16) { test(16); }
TEST_F(HexParserReprTest, TestRepresentation17) { test(17); }
TEST_F(HexParserReprTest, TestRepresentation18) { test(18); }
TEST_F(HexParserReprTest, TestRepresentation19) { test(19); }
TEST_F(HexParserReprTest, TestRepresentation20) { test(20); }
TEST_F(HexParserReprTest, TestRepresentation21) { test(21); }
TEST_F(HexParserReprTest, TestRepresentation22) { test(22); }
TEST_F(HexParserReprTest, TestRepresentation23) { test(23); }
TEST_F(HexParserReprTest, TestRepresentation24) { test(24); }
TEST_F(HexParserReprTest, TestRepresentation25) { test(25); }
TEST_F(HexParserReprTest, TestRepresentation26) { test(26); }
TEST_F(HexParserReprTest, TestRepresentation27) { test(27); }
TEST_F(HexParserReprTest, TestRepresentation28) { test(28); }
TEST_F(HexParserReprTest, TestRepresentation29) { test(29); }
TEST_F(HexParserReprTest, TestRepresentation30) { test(30); }
TEST_F(HexParserReprTest, TestRepresentation31) { test(31); }
TEST_F(HexParserReprTest, TestRepresentation32) { test(32); }
TEST_F(HexParserReprTest, TestRepresentation33) { test(33); }
TEST_F(HexParserReprTest, TestRepresentation34) { test(34); }
TEST_F(HexParserReprTest, TestRepresentation35) { test(35); }
TEST_F(HexParserReprTest, TestRepresentation36) { test(36); }
TEST_F(HexParserReprTest, TestRepresentation37) { test(37); }
TEST_F(HexParserReprTest, TestRepresentation38) { test(38); }
TEST_F(HexParserReprTest, TestRepresentation39) { test(39); }
TEST_F(HexParserReprTest, TestRepresentation40) { test(40); }
TEST_F(HexParserReprTest, TestRepresentation41) { test(41); }
TEST_F(HexParserReprTest, TestRepresentation42) { test(42); }
TEST_F(HexParserReprTest, TestRepresentation43) { test(43); } 
TEST_F(HexParserReprTest, TestRepresentation44) { test(44); }
TEST_F(HexParserReprTest, TestRepresentation45) { test(45); }
TEST_F(HexParserReprTest, TestRepresentation46) { test(46); }
TEST_F(HexParserReprTest, TestRepresentation47) { test(47); }
TEST_F(HexParserReprTest, TestRepresentation48) { test(48); }
TEST_F(HexParserReprTest, TestRepresentation49) { test(49); }
TEST_F(HexParserReprTest, TestRepresentation50) { test(50); }
TEST_F(HexParserReprTest, TestRepresentation51) { test(51); }
TEST_F(HexParserReprTest, TestRepresentation52) { test(52); }
TEST_F(HexParserReprTest, TestRepresentation53) { test(53); }
TEST_F(HexParserReprTest, TestRepresentation54) { test(54); }
TEST_F(HexParserReprTest, TestRepresentation55) { test(55); }
TEST_F(HexParserReprTest, TestRepresentation56) { test(56); }
TEST_F(HexParserReprTest, TestRepresentation57) { test(57); }
TEST_F(HexParserReprTest, TestRepresentation58) { test(58); }
TEST_F(HexParserReprTest, TestRepresentation59) { test(59); }
TEST_F(HexParserReprTest, TestRepresentation60) { test(60); }
TEST_F(HexParserReprTest, TestRepresentation61) { test(61); }
TEST_F(HexParserReprTest, TestRepresentation62) { test(62); }
TEST_F(HexParserReprTest, TestRepresentation63) { test(63); }
TEST_F(HexParserReprTest, TestRepresentation64) { test(64); }
TEST_F(HexParserReprTest, TestRepresentation65) { test(65); }
TEST_F(HexParserReprTest, TestRepresentation66) { test(66); }
TEST_F(HexParserReprTest, TestRepresentation67) { test(67); }
TEST_F(HexParserReprTest, TestRepresentation68) { test(68); }
TEST_F(HexParserReprTest, TestRepresentation69) { test(69); }
TEST_F(HexParserReprTest, TestRepresentation70) { test(70); }
TEST_F(HexParserReprTest, TestRepresentation71) { test(71); }
TEST_F(HexParserReprTest, TestRepresentation72) { test(72); }
TEST_F(HexParserReprTest, TestRepresentation73) { test(73); }
TEST_F(HexParserReprTest, TestRepresentation74) { test(74); }
TEST_F(HexParserReprTest, TestRepresentation75) { test(75); }
TEST_F(HexParserReprTest, TestRepresentation76) { test(76); }
TEST_F(HexParserReprTest, TestRepresentation77) { test(77); }
TEST_F(HexParserReprTest, TestRepresentation78) { test(78); }
TEST_F(HexParserReprTest, TestRepresentation79) { test(79); }