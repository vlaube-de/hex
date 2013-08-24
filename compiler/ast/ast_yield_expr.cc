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


#include "ast_expr.h"
#include "ast_expr_list.h"
#include "ast_yield_expr.h"
#include "../../base/assert.h"

_HexAstYieldExpr::_HexAstYieldExpr(
  HexAstExprList exprs
): _exprs(exprs)
{
}

HexAstYieldExpr
_HexAstYieldExpr::create(HexAstExprList exprs)
{
  HexAstYieldExpr obj = new _HexAstYieldExpr(exprs);
  HEX_ASSERT(obj);
  return obj;
}
