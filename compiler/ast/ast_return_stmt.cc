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

#include "ast_return_stmt.h"
#include "ast_expr_list.h"
#include "ast_expr.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstReturnStmt::_HexAstReturnStmt(
  HexAstExprList return_vals,
  HexAstExpr predicate
):_return_vals(return_vals), _predicate(predicate)
{
  this->reprOK();
}

bool
_HexAstReturnStmt::reprOK()
{
  return true;
}

HexAstExprList
_HexAstReturnStmt::return_vals()
{
  return this->_return_vals.get();
}

HexAstExpr
_HexAstReturnStmt::predicate()
{
  return this->_predicate.get();
}

void
_HexAstReturnStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstReturnStmt
_HexAstReturnStmt::create(
  HexAstExprList return_val,
  HexAstExpr predicate
)
{
  HexAstReturnStmt obj = new _HexAstReturnStmt(
    return_val,
    predicate
  );

  HEX_ASSERT(obj);

  return obj;
}
