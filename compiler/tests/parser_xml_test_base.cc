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

#include "parser_xml_test_base.h"
#include "../ast2/ast.h"
#include "../hex_parser.h"
#include "../visitor/ast_to_xml_visitor.h"
#include "../../base/assert.h"
#include "../../base/freader.h"

void
HexParserXmlTestBase::test(int index)
{
  AstToXmlVisitor visitor;
  HexAstHexProgram program = NULL;

  c_str filepath = this->testfiles[index].filePath;
  c_str xmlFilePath = this->testfiles[index].xmlFilePath;

  c_str expected_str = NULL;
  FileReader freader(xmlFilePath);
  freader.read_file(&expected_str);
  HEX_ASSERT(expected_str);

  int res = this->parser->parse_from_file(filepath, &program);
  EXPECT_EQ(0, res);
  HEX_ASSERT(program);

  program->accept(&visitor);
  c_str actual_str = visitor.str();
  HEX_ASSERT(actual_str);

  ASSERT_STREQ(expected_str, actual_str);
}