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
#include "ast_stmt_group.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"
#include "../../base/memory.h"


HexAstHexProgram _HexAstHexProgram::_root = NULL;

_HexAstHexProgram::_HexAstHexProgram(
  HexAstStmtGroup stmts
):_stmts(stmts)
{
  this->reprOK();
}

bool
_HexAstHexProgram::reprOK()
{
  return true;
}

HexAstStmtGroup
_HexAstHexProgram::stmts()
{
  return this->_stmts;
}

void
_HexAstHexProgram::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstHexProgram
_HexAstHexProgram::create(
  HexAstStmtGroup stmts
)
{
  HexAstHexProgram obj = new _HexAstHexProgram(stmts);
  HEX_ASSERT(obj);

  _HexAstHexProgram::set_parse_tree_root(&obj);

  return obj;
}

int
_HexAstHexProgram::get_parse_tree_root(HexAstHexProgram *dst)
{
  *dst = _root;
  return 1;
}

void
_HexAstHexProgram::set_parse_tree_root(HexAstHexProgram *root)
{
  // Free the root for the previous parse tree.
  HEX_DELETE(_root);

  // Make sure the root we are setting is not null.
  HEX_ASSERT(*root);

  // Set the root.
  _root = *root;
}
