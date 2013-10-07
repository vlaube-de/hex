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

#include "ast_while_stmt.h"
#include "ast_expr.h"
#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstWhileStmt::_HexAstWhileStmt(
  HexAstExpr expr,
  HexAstStmtGroup stmts
):_expr(expr), _HexAstCompoundStmt(stmts)
{
  this->reprOK();
}

void
_HexAstWhileStmt::reprOK()
{
  HEX_ASSERT(this->expr());
}

HexAstExpr
_HexAstWhileStmt::expr()
{
  return this->_expr.get();
}

void
_HexAstWhileStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstWhileStmt
_HexAstWhileStmt::create(
  HexAstExpr exprs,
  HexAstStmtGroup stmts
)
{
  HEX_ASSERT(exprs);

  HexAstWhileStmt obj = new _HexAstWhileStmt(exprs, stmts);
  HEX_ASSERT(obj);
  return obj;
}
