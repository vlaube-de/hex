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

/* HEX parser. */

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.tab.hh"
#include "hex_parser.h"
#include "ast/ast.h"
#include "../base/assert.h"
#include "../base/c_str.h"


/* Bring out the parser functions that live in C land. */
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_buffer(char *, size_t);
extern YY_BUFFER_STATE yy_scan_string(const char *);
extern void yy_delete_buffer(YY_BUFFER_STATE);
extern void yy_flush_buffer(YY_BUFFER_STATE);
extern void yy_switch_to_buffer(YY_BUFFER_STATE);


HexParser::HexParser()
{
}

int
HexParser::parse_from_file(const c_str path, HexAstHexProgram* program)
{
  HEX_ASSERT(path);
  c_str content = this->_read_file(path);
  return this->_parse(content, program);
}

int
HexParser::parse(const c_str content, HexAstHexProgram* program)
{
  HEX_ASSERT(content);
  return this->_parse(content, program);
}

int
HexParser::_parse(const c_str content, HexAstHexProgram* program)
{
  int res;

  // prepare for parsing.
  YY_BUFFER_STATE buffer = yy_scan_string(content);
  yy_switch_to_buffer(buffer);

  // Clears the AST.
  _HexAstHexProgram::clear();

  // the real magic happens here.
  res = yyparse();

  // flush the buffer right after parsing.
  yy_flush_buffer(buffer);
  yy_delete_buffer(buffer);

  // Get the root of the parse tree.
  HexAstHexProgram root = NULL;
  _HexAstHexProgram::get_parse_tree_root(&root);

  HEX_ASSERT(root);

  if(program) {
    *program = root;
    HEX_ASSERT(*program);
  }

  return res;
}

c_str
HexParser::_read_file(const c_str path)
{
  std::ifstream file(path);

  std::stringstream buffer;
  buffer << file.rdbuf();

  file.close();

  std::string str = buffer.str();

  return (c_str)strdup(str.c_str());
}