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
#include "../base/assert.h"


/* Bring out the parser functions that live in C land. */
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_buffer(char *, size_t);
extern YY_BUFFER_STATE yy_scan_string(const char *);
extern void yy_delete_buffer(YY_BUFFER_STATE);
extern void yy_flush_buffer(YY_BUFFER_STATE);
extern void yy_switch_to_buffer(YY_BUFFER_STATE);


HexParser::HexParser(
  const char *path
):_path(path)
{
  HEX_ASSERT(this->_path);
}

int
HexParser::parse()
{
  int res;
  char *content = this->read_file();

  // prepare for parsing.
  YY_BUFFER_STATE buffer = yy_scan_string(content);
  yy_switch_to_buffer(buffer);

  // the real magic happens here.
  res = yyparse();

  // flush the buffer right after parsing.
  yy_flush_buffer(buffer);
  yy_delete_buffer(buffer);

  delete content;

  return res;
}

char*
HexParser::read_file()
{
  std::ifstream file(this->_path);

  std::stringstream buffer;
  buffer << file.rdbuf();

  file.close();

  std::string str = buffer.str();

  return strdup(str.c_str());
}
