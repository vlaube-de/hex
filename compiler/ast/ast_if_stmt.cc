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

#include "ast_if_stmt.h"
#include "ast_expr.h"
#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "ast_elif_stmt_group.h"
#include "ast_else_stmt.h"
#include "../../base/assert.h"

_HexAstIfStmt::_HexAstIfStmt(
  HexAstExpr predicate,
  HexAstStmtGroup stmts,
  HexAstElifStmtGroup elif_stmts,
  HexAstElseStmt else_stmt
):_predicate(predicate), _HexAstCompoundStmt(stmts), _elif_stmts(elif_stmts), _else_stmt(else_stmt)
{
  this->reprOK();
}

bool
_HexAstIfStmt::reprOK()
{
  HEX_ASSERT(this->_predicate);
}
