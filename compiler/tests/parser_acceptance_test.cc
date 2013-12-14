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

#include "parser_test_base.h"
#include "parser_test_files.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"
#include "../../base/memory.h"

class HexParserAcceptanceTest : public HexParserTestBase {
protected:
  HexParserAcceptanceTest():
    HexParserTestBase(hex_parser_testfiles)
  {
    // Do nothing here.
  }

  virtual void test(int index);
};

void
HexParserAcceptanceTest::test(int index)
{
  int res = parser->parse_from_file(this->testfiles[index].filePath, NULL);
  EXPECT_EQ(0, res);
}

TEST_F(HexParserAcceptanceTest, TestAcceptance00) { test(0); }
TEST_F(HexParserAcceptanceTest, TestAcceptance01) { test(1); }
TEST_F(HexParserAcceptanceTest, TestAcceptance02) { test(2); }
TEST_F(HexParserAcceptanceTest, TestAcceptance03) { test(3); }
TEST_F(HexParserAcceptanceTest, TestAcceptance04) { test(4); }
TEST_F(HexParserAcceptanceTest, TestAcceptance05) { test(5); }
TEST_F(HexParserAcceptanceTest, TestAcceptance06) { test(6); }
TEST_F(HexParserAcceptanceTest, TestAcceptance07) { test(7); }
TEST_F(HexParserAcceptanceTest, TestAcceptance08) { test(8); }
TEST_F(HexParserAcceptanceTest, TestAcceptance09) { test(9); }
TEST_F(HexParserAcceptanceTest, TestAcceptance10) { test(10); }
TEST_F(HexParserAcceptanceTest, TestAcceptance11) { test(11); }
TEST_F(HexParserAcceptanceTest, TestAcceptance12) { test(12); }
TEST_F(HexParserAcceptanceTest, TestAcceptance13) { test(13); }
TEST_F(HexParserAcceptanceTest, TestAcceptance14) { test(14); }
TEST_F(HexParserAcceptanceTest, TestAcceptance15) { test(15); }
TEST_F(HexParserAcceptanceTest, TestAcceptance16) { test(16); }
TEST_F(HexParserAcceptanceTest, TestAcceptance17) { test(17); }
TEST_F(HexParserAcceptanceTest, TestAcceptance18) { test(18); }
TEST_F(HexParserAcceptanceTest, TestAcceptance19) { test(19); }
TEST_F(HexParserAcceptanceTest, TestAcceptance20) { test(20); }
TEST_F(HexParserAcceptanceTest, TestAcceptance21) { test(21); }
TEST_F(HexParserAcceptanceTest, TestAcceptance22) { test(22); }
TEST_F(HexParserAcceptanceTest, TestAcceptance23) { test(23); }
TEST_F(HexParserAcceptanceTest, TestAcceptance24) { test(24); }
TEST_F(HexParserAcceptanceTest, TestAcceptance25) { test(25); }
TEST_F(HexParserAcceptanceTest, TestAcceptance26) { test(26); }
TEST_F(HexParserAcceptanceTest, TestAcceptance27) { test(27); }
TEST_F(HexParserAcceptanceTest, TestAcceptance28) { test(28); }
TEST_F(HexParserAcceptanceTest, TestAcceptance29) { test(29); }
TEST_F(HexParserAcceptanceTest, TestAcceptance30) { test(30); }
TEST_F(HexParserAcceptanceTest, TestAcceptance31) { test(31); }
TEST_F(HexParserAcceptanceTest, TestAcceptance32) { test(32); }
TEST_F(HexParserAcceptanceTest, TestAcceptance33) { test(33); }
TEST_F(HexParserAcceptanceTest, TestAcceptance34) { test(34); }
TEST_F(HexParserAcceptanceTest, TestAcceptance35) { test(35); }
TEST_F(HexParserAcceptanceTest, TestAcceptance36) { test(36); }
TEST_F(HexParserAcceptanceTest, TestAcceptance37) { test(37); }
TEST_F(HexParserAcceptanceTest, TestAcceptance38) { test(38); }
TEST_F(HexParserAcceptanceTest, TestAcceptance39) { test(39); }
TEST_F(HexParserAcceptanceTest, TestAcceptance40) { test(40); }
TEST_F(HexParserAcceptanceTest, TestAcceptance41) { test(41); }
TEST_F(HexParserAcceptanceTest, TestAcceptance42) { test(42); }
TEST_F(HexParserAcceptanceTest, TestAcceptance43) { test(43); }
TEST_F(HexParserAcceptanceTest, TestAcceptance44) { test(44); }
TEST_F(HexParserAcceptanceTest, TestAcceptance45) { test(45); }
TEST_F(HexParserAcceptanceTest, TestAcceptance46) { test(46); }
TEST_F(HexParserAcceptanceTest, TestAcceptance47) { test(47); }
TEST_F(HexParserAcceptanceTest, TestAcceptance48) { test(48); }
TEST_F(HexParserAcceptanceTest, TestAcceptance49) { test(49); }
TEST_F(HexParserAcceptanceTest, TestAcceptance50) { test(50); }
TEST_F(HexParserAcceptanceTest, TestAcceptance51) { test(51); }
TEST_F(HexParserAcceptanceTest, TestAcceptance52) { test(52); }
TEST_F(HexParserAcceptanceTest, TestAcceptance53) { test(53); }
TEST_F(HexParserAcceptanceTest, TestAcceptance54) { test(54); }
TEST_F(HexParserAcceptanceTest, TestAcceptance55) { test(55); }
TEST_F(HexParserAcceptanceTest, TestAcceptance56) { test(56); }
TEST_F(HexParserAcceptanceTest, TestAcceptance57) { test(57); }
TEST_F(HexParserAcceptanceTest, TestAcceptance58) { test(58); }
TEST_F(HexParserAcceptanceTest, TestAcceptance59) { test(59); }
TEST_F(HexParserAcceptanceTest, TestAcceptance60) { test(60); }
TEST_F(HexParserAcceptanceTest, TestAcceptance61) { test(61); }
TEST_F(HexParserAcceptanceTest, TestAcceptance62) { test(62); }
TEST_F(HexParserAcceptanceTest, TestAcceptance63) { test(63); }
TEST_F(HexParserAcceptanceTest, TestAcceptance64) { test(64); }
TEST_F(HexParserAcceptanceTest, TestAcceptance65) { test(65); }
TEST_F(HexParserAcceptanceTest, TestAcceptance66) { test(66); }
TEST_F(HexParserAcceptanceTest, TestAcceptance67) { test(67); }
TEST_F(HexParserAcceptanceTest, TestAcceptance68) { test(68); }
TEST_F(HexParserAcceptanceTest, TestAcceptance69) { test(69); }
TEST_F(HexParserAcceptanceTest, TestAcceptance70) { test(70); }
TEST_F(HexParserAcceptanceTest, TestAcceptance71) { test(71); }
TEST_F(HexParserAcceptanceTest, TestAcceptance72) { test(72); }
TEST_F(HexParserAcceptanceTest, TestAcceptance73) { test(73); }
TEST_F(HexParserAcceptanceTest, TestAcceptance74) { test(74); }
TEST_F(HexParserAcceptanceTest, TestAcceptance75) { test(75); }
TEST_F(HexParserAcceptanceTest, TestAcceptance76) { test(76); }
TEST_F(HexParserAcceptanceTest, TestAcceptance77) { test(77); }
TEST_F(HexParserAcceptanceTest, TestAcceptance78) { test(78); }
TEST_F(HexParserAcceptanceTest, TestAcceptance79) { test(79); }