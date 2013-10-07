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
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstIfStmt::_HexAstIfStmt(
  HexAstExpr predicate,
  HexAstStmtGroup stmts,
  HexAstElifStmtGroup elif_stmts,
  HexAstElseStmt else_stmt
):
  _predicate(predicate),
  _HexAstCompoundStmt(stmts),
  _elif_stmts(elif_stmts),
  _else_stmt(else_stmt)
{
  this->reprOK();
}

void
_HexAstIfStmt::reprOK()
{
  HEX_ASSERT(this->predicate());
}

HexAstExpr
_HexAstIfStmt::predicate()
{
  return this->_predicate.get();
}

HexAstElifStmtGroup
_HexAstIfStmt::elif_stmts()
{
  return this->_elif_stmts.get();
}

HexAstElseStmt
_HexAstIfStmt::else_stmt()
{
  return this->_else_stmt.get();
}

void
_HexAstIfStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstIfStmt
_HexAstIfStmt::create(
  HexAstExpr predicate,
  HexAstStmtGroup stmts,
  HexAstElifStmtGroup elif_stmts,
  HexAstElseStmt else_stmt
)
{
  HEX_ASSERT(predicate);

  HexAstIfStmt obj = new _HexAstIfStmt(
    predicate,
    stmts,
    elif_stmts,
    else_stmt
  );

  HEX_ASSERT(obj);

  return obj;
}
