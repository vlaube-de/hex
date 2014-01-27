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

#include "ast_hex_program.h"
#include "../../base/memory.h"


HexAstHexProgram __root__ = NULL;


void
_HexAstHexProgram::clear()
{
  HEX_DELETE(__root__);
}

int
_HexAstHexProgram::get_parse_tree_root(HexAstHexProgram *dst)
{
  *dst = __root__;
  return 1;
}

void
_HexAstHexProgram::set_parse_tree_root(HexAstHexProgram *root)
{
  // Free the root for the previous parse tree.
  _HexAstHexProgram::clear();

  // Make sure the root we are setting is not null.
  HEX_ASSERT(*root);

  // Set the root.
  __root__ = *root;
}

HexAstHexProgram
_HexAstHexProgram::create(HexAstStmtGroup stmts)
{
  HexAstHexProgram obj = new _HexAstHexProgram(stmts);
  HEX_ASSERT(obj);

  _HexAstHexProgram::set_parse_tree_root(&obj);

  return obj;
}