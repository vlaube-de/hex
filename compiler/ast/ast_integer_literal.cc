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

#include "ast_integer_literal.h"
#include "ast_unparsed.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"


_HexAstIntegerLiteral::_HexAstIntegerLiteral(
  c_str value
) : _HexAstLiteral(value)
{
  this->reprOK();
}

void
_HexAstIntegerLiteral::reprOK()
{
  // Do nothing here.
}

void
_HexAstIntegerLiteral::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

_HexAstDecimalIntegerLiteral::_HexAstDecimalIntegerLiteral(
  c_str value
) : _HexAstIntegerLiteral(value)
{
}

_HexAstBinaryIntegerLiteral::_HexAstBinaryIntegerLiteral(
  c_str value
) : _HexAstIntegerLiteral(value)
{
}

_HexAstOctalIntegerLiteral::_HexAstOctalIntegerLiteral(
  c_str value
) : _HexAstIntegerLiteral(value)
{
}

_HexAstHexadecimalIntegerLiteral::_HexAstHexadecimalIntegerLiteral(
  c_str value
) : _HexAstIntegerLiteral(value)
{
}

