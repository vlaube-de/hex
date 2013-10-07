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


#include "ast_binary_expr.h"
#include "examiner.h"
#include "../../base/assert.h"


_HexAstBinaryExpr::_HexAstBinaryExpr(
  HexAstExpr lexpr,
  HexAstExpr rexpr
):_lexpr(lexpr), _rexpr(rexpr)
{
  this->reprOK();
}

HexAstExpr
_HexAstBinaryExpr::left()
{
  return this->_lexpr.get();
}

HexAstExpr
_HexAstBinaryExpr::right()
{
  return this->_rexpr.get();
}

void
_HexAstBinaryExpr::reprOK()
{
  HEX_ASSERT(this->left());
  HEX_ASSERT(this->right());
}
