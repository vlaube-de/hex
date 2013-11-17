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
#include "../../base/c_str.h"
#include "../../base/memory.h"
#include "../../base/assert.h"


class HexParserAcceptanceTest : public HexParserTestBase {
protected:
  void test(const c_str);
};

void
HexParserAcceptanceTest::test(const c_str path)
{
  int res = parser->parse_from_file(path, NULL);
  EXPECT_EQ(0, res);
}

TEST_F(HexParserAcceptanceTest, TestAcceptance01) { test("./assets/hex_blank.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance02) { test("./assets/hex_expr.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance03) { test("./assets/hex_integer.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance04) { test("./assets/hex_floating.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance05) { test("./assets/hex_string_literal.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance06) { test("./assets/hex_attribute_ref.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance07) { test("./assets/hex_call.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance08) { test("./assets/hex_slicing.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance09) { test("./assets/hex_list.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance10) { test("./assets/hex_dict.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance12) { test("./assets/hex_lambda.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance13) { test("./assets/hex_class.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance14) { test("./assets/hex_target_list.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance15) { test("./assets/hex_input_output_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance16) { test("./assets/hex_if_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance17) { test("./assets/hex_for_loop.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance18) { test("./assets/hex_lock_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance19) { test("./assets/hex_task_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance20) { test("./assets/hex_try_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance21) { test("./assets/hex_while_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance22) { test("./assets/hex_with_stmt.hex"); }
TEST_F(HexParserAcceptanceTest, TestAcceptance23) { test("./assets/hex_await_stmt.hex"); }
