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


#include "../ast/ast.h"
#include "../hex_parser.h"
#include "../../base/c_str.h"
#include "../../base/unittest.h"
#include "../ast/visitor/ast_to_xml_visitor.h"


#ifndef _HEX_PARSER_XML_TEST_BASE_H_
#define _HEX_PARSER_XML_TEST_BASE_H_

class HexParserXmlTestBase : public ::testing::Test {
protected:
  virtual void SetUp() {
    parser = new HexParser();
  }

  virtual void TearDown() {
    delete parser;
  }

  virtual void test(const c_str, const c_str);

  HexParser *parser;

  virtual const c_str wrap_single_stmt(const c_str);
  virtual const c_str wrap_single_expr(const c_str);
};

#endif /* _HEX_PARSER_XML_TEST_BASE_H_ */