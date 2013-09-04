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
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"


_HexAstIntegerLiteral::_HexAstIntegerLiteral(
  ast_type_t type,
  c_str value
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

c_str
_HexAstIntegerLiteral::value()
{
  return this->_value;
}

void
_HexAstIntegerLiteral::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstIntegerLiteral
_HexAstIntegerLiteral::create(ast_type_t type, c_str value)
{
  HexAstIntegerLiteral obj = new _HexAstIntegerLiteral(type, value);
  HEX_ASSERT(obj);
  return obj;
}
