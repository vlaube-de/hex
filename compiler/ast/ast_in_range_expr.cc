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


#include "ast_in_range_expr.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstInclusiveRangeExpr::_HexAstInclusiveRangeExpr(
  HexAstExpr begin,
  HexAstExpr end
): _begin(begin), _end(end)
{
  this->reprOK();
}

void
_HexAstInclusiveRangeExpr::reprOK()
{
  HEX_ASSERT(this->begin());
  HEX_ASSERT(this->end());
}

HexAstExpr
_HexAstInclusiveRangeExpr::begin()
{
	return this->_begin.get();
}

HexAstExpr
_HexAstInclusiveRangeExpr::end()
{
  return this->_end.get();
}

void
_HexAstInclusiveRangeExpr::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstInclusiveRangeExpr
_HexAstInclusiveRangeExpr::create(HexAstExpr begin, HexAstExpr end)
{
  HexAstInclusiveRangeExpr obj = new _HexAstInclusiveRangeExpr(begin, end);
  HEX_ASSERT(obj);

  return obj;
}
