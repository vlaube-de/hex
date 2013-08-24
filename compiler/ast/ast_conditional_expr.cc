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


#include "ast_conditional_expr.h"
#include "ast_expr.h"
#include "../../base/assert.h"


_HexAstConditionalExpr::_HexAstConditionalExpr(
  HexAstExpr predicate,
  HexAstExpr consequent,
  HexAstExpr alternate
): _predicate(predicate), _consequent(consequent), _alternate(alternate)
{
  this->reprOK();
}

bool
_HexAstConditionalExpr::reprOK()
{
  HEX_ASSERT(this->_predicate);
  HEX_ASSERT(this->_consequent);
  HEX_ASSERT(this->_alternate);
}

HexAstConditionalExpr
_HexAstConditionalExpr::create(
  HexAstExpr predicate,
  HexAstExpr consequent,
  HexAstExpr alternate
)
{
  HEX_ASSERT(predicate);
  HEX_ASSERT(consequent);
  HEX_ASSERT(alternate);

  HexAstConditionalExpr obj = new _HexAstConditionalExpr(
    predicate,
    consequent,
    alternate
  );

  HEX_ASSERT(obj);

  return obj;
}
