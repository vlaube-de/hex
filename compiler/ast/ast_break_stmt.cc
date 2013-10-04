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

#include "ast_break_stmt.h"
#include "ast_expr.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstBreakStmt::_HexAstBreakStmt(
  HexAstExpr predicate
):_predicate(predicate)
{
  this->reprOK();
}

bool
_HexAstBreakStmt::reprOK()
{
  return true;
}

HexAstExpr
_HexAstBreakStmt::predicate()
{
  return this->_predicate.get();
}

void
_HexAstBreakStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstBreakStmt
_HexAstBreakStmt::create(
  HexAstExpr expr
)
{
  HexAstBreakStmt obj = new _HexAstBreakStmt(expr);
  HEX_ASSERT(obj);
  return obj;
}
