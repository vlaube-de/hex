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


#include "ast_unary_expr.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "../../base/assert.h"


_HexAstUnaryExpr::_HexAstUnaryExpr(
  HexAstExpr expr,
  HexAstExprAssociativity associativity,
  HexAstExprPrecedence precedence
):
  _expr(expr),
  _HexAstExpr(associativity, precedence)
{
  this->reprOK();
}

void
_HexAstUnaryExpr::reprOK()
{
  HEX_ASSERT(this->expr());
}

HexAstExpr
_HexAstUnaryExpr::expr()
{
  return this->_expr.get();
}
