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

#include "ast_float_literal.h"
#include "ast_unparsed.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"


_HexAstFloatLiteral::_HexAstFloatLiteral(
  c_str value
):_HexAstLiteral(value)
{
  this->reprOK();
}

void
_HexAstFloatLiteral::reprOK()
{
  // Do nothing here.
}

void
_HexAstFloatLiteral::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstFloatLiteral
_HexAstFloatLiteral::create(c_str value)
{
  HexAstFloatLiteral obj = new _HexAstFloatLiteral(value);
  HEX_ASSERT(obj);
  return obj;
}
