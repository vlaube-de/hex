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
  return this->_lexpr;
}

HexAstExpr
_HexAstBinaryExpr::right()
{
  return this->_rexpr;
}

bool
_HexAstBinaryExpr::reprOK()
{
  HEX_ASSERT(this->_lexpr);
  HEX_ASSERT(this->_rexpr);
}

char*
_HexAstBinaryExpr::op()
{
  return "+";
}

/*
bool
_HexAstBinaryExpr::equals(void* obj)
{
  return this->examine(Examiners::Equals, obj);
}

bool
_HexAstBinaryExpr::isomorphic(void* obj)
{
  return this->examine(Examiners::Isomorphic, obj);
}

bool
_HexAstBinaryExpr::equivalent(void* obj)
{
  return this->examine(Examiners::Equivalent, obj);
}

bool
_HexAstBinaryExpr::examine(Examiner e, void* obj)
{
  if(obj == NULL) return false;

  HexAstBinaryExpr that = (HexAstBinaryExpr)obj;

  if(!e->examine(this->_lexpr, that->left())) return false;
  if(!e->examine(this->_rexpr, that->right())) return false;

  return true;
}

template<typename T>
T*
_HexAstBinaryExpr::create(
  HexAstExpr left,
  HexAstExpr right
)
{
  HEX_ASSERT(left);
  HEX_ASSERT(right);

  T* obj = new T(left, right);
  HEX_ASSERT(obj);
  return obj;
}
*/
