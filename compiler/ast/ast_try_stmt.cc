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

#include "ast_try_stmt.h"
#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstTryStmt::_HexAstTryStmt(
  HexAstStmtGroup stmts,
  HexAstCatchStmtGroup catch_stmt_group
):_HexAstCompoundStmt(stmts), _catch_stmt_group(catch_stmt_group)
{
  this->reprOK();
}

bool
_HexAstTryStmt::reprOK()
{
  HEX_ASSERT(this->_catch_stmt_group);
}

HexAstCatchStmtGroup
_HexAstTryStmt::catch_stmt_group()
{
  return this->_catch_stmt_group.get();
}

void
_HexAstTryStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstTryStmt
_HexAstTryStmt::create(
  HexAstStmtGroup stmts,
  HexAstCatchStmtGroup catch_stmt_group
)
{
  HEX_ASSERT(catch_stmt_group);

  HexAstTryStmt obj = new _HexAstTryStmt(
    stmts,
    catch_stmt_group
  );

  HEX_ASSERT(obj);

  return obj;
}
