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


#include "ast_bitwise_or_expr.h"
#include "../../base/assert.h"


_HexAstBitwiseOrExpr::_HexAstBitwiseOrExpr(
  HexAstExpr left,
  HexAstExpr right
): _HexAstCommutativeBinaryExpr(left, right)
{
}

void*
_HexAstBitwiseOrExpr::create(
  HexAstExpr left,
  HexAstExpr right
)
{
  HEX_ASSERT(left);
  HEX_ASSERT(right);

  HexAstBitwiseOrExpr obj = new _HexAstBitwiseOrExpr(left, right);
  HEX_ASSERT(obj);
  return obj;
}
