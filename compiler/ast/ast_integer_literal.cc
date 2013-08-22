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
#include "../../base/assert.h"


_HexAstIntegerLiteral::_HexAstIntegerLiteral(
  char type, char *value
):_intval(0), _type(type), AstUnparsed(value)
{
  this->reprOK();
}

bool
_HexAstIntegerLiteral::reprOK()
{
  HEX_ASSERT(this->_value);
  HEX_ASSERT(
    this->_type==INTEGER_LITERAL_DECIMAL ||
    this->_type==INTEGER_LITERAL_BINARY  ||
    this->_type==INTEGER_LITERAL_OCTAL   ||
    this->_type==INTEGER_LITERAL_HEXADECIMAL
  );
}
