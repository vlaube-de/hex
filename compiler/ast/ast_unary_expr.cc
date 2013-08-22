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
#include "../../base/assert.h"


_HexAstUnaryExpr::_HexAstUnaryExpr(HexAstExpr expr)
{
  this->_expr = expr;
  this->reprOK();
}

bool
_HexAstUnaryExpr::reprOK()
{
  HEX_ASSERT(this->_expr);
}

HexAstExpr
_HexAstUnaryExpr::expr()
{
  return this->_expr;
}

bool
_HexAstUnaryExpr::equals(void* obj)
{
  return this->examine(Examiners::Equals, obj);
}

bool
_HexAstUnaryExpr::isomorphic(void* obj)
{
  return this->examine(Examiners::Isomorphic, obj);
}

bool
_HexAstUnaryExpr::equivalent(void *obj)
{
  return this->examine(Examiners::Equivalent, obj);
}

bool
_HexAstUnaryExpr::examine(Examiner e, void* obj)
{
  if(obj == NULL) return false;

  HexAstUnaryExpr that = (HexAstUnaryExpr)obj;

  if(this == that) return true;

  return e->examine(this->expr(), that->expr());
}
