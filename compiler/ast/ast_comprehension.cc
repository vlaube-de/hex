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

#include "ast_expr_list.h"
#include "ast_expr.h"
#include "ast_target_list.h"
#include "ast_comprehension.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"


_HexAstComprehension::_HexAstComprehension(
  HexAstExprList dst,
  HexAstTargetList candidates,
  HexAstExprList src,
  HexAstExpr predicate
):_dst(dst), _candidates(candidates), _src(src), _predicate(predicate)
{
  this->reprOK();
}

void
_HexAstComprehension::reprOK()
{
  HEX_ASSERT(this->_candidates);
  HEX_ASSERT(this->_src);
}

HexAstExprList
_HexAstComprehension::dst()
{
  return this->_dst;
}

HexAstTargetList
_HexAstComprehension::candidates()
{
  return this->_candidates;
}

HexAstExprList
_HexAstComprehension::src()
{
  return this->_src;
}

HexAstExpr
_HexAstComprehension::predicate()
{
  return this->_predicate;
}

void
_HexAstComprehension::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstComprehension
_HexAstComprehension::create(
  HexAstExprList dst,
  HexAstTargetList candidates,
  HexAstExprList src,
  HexAstExpr predicate
)
{
  HEX_ASSERT(candidates);
  HEX_ASSERT(src);

  HexAstComprehension obj = new _HexAstComprehension(
    dst,
    candidates,
    src,
    predicate
  );

  HEX_ASSERT(obj);

  return obj;
}
