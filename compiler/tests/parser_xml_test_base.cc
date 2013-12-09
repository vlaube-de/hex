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
#include "parser_xml_test_base.h"
#include "../ast/ast.h"
#include "../hex_parser.h"
#include "../visitor/ast_to_xml_visitor.h"
#include "../../base/unittest.h"
#include "../../base/memory.h"
#include "../../base/assert.h"


#define MAX_XML_LENGTH 5000


void
HexParserXmlTestBase::test(const c_str content_str, const c_str expected_xml)
{
  AstToXmlVisitor* visitor = new AstToXmlVisitor();
  HexAstHexProgram program = NULL;

  parser->parse(content_str, &program);

  HEX_ASSERT(program);

  program->accept(visitor);
  c_str actual_xml = visitor->str();

  HEX_DELETE(visitor);

  ASSERT_STREQ(expected_xml, actual_xml);
}

const c_str
HexParserXmlTestBase::wrap_single_stmt(const c_str innerXML)
{
  char xml[MAX_XML_LENGTH];

  sprintf(
    xml,
    "<hex_program>"
      "<hex_program-stmts>"
        "<stmt_group>"
          "%s"
        "<stmt_group/>"
      "<hex_program-stmts/>"
    "<hex_program/>",
    innerXML
  );

  return (const c_str)strdup(xml);
}

const c_str
HexParserXmlTestBase::wrap_single_expr_stmt(const c_str innerXML)
{
  char xml[MAX_XML_LENGTH];

  sprintf(
    xml,
    "<hex_program>"
      "<hex_program-stmts>"
        "<stmt_group>"
          "<expr_list_stmt>"
            "<exprlist>"
              "%s"
            "<exprlist/>"
          "<expr_list_stmt/>"
        "<stmt_group/>"
      "<hex_program-stmts/>"
    "<hex_program/>",
    innerXML
  );

  return (const c_str)strdup(xml);
}
