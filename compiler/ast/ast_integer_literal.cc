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
#include "ast_typed.h"
#include "../../base/assert.h"


_HexAstIntegerLiteral::_HexAstIntegerLiteral(
  ast_type_t type,
  char *value
):AstTyped(type), AstUnparsed(value)
{
  this->reprOK();
}

bool
_HexAstIntegerLiteral::reprOK()
{
  HEX_ASSERT(this->_value);
  HEX_ASSERT(
    this->_type==AST_INTEGER_LITERAL_DECIMAL ||
    this->_type==AST_INTEGER_LITERAL_BINARY  ||
    this->_type==AST_INTEGER_LITERAL_OCTAL   ||
    this->_type==AST_INTEGER_LITERAL_HEXADECIMAL
  );
}

HexAstIntegerLiteral
_HexAstIntegerLiteral::create(ast_type_t type, char* value)
{
  HexAstIntegerLiteral obj = new _HexAstIntegerLiteral(type, value);
  HEX_ASSERT(obj);
  return obj;
}
