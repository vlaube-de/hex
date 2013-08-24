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

#include "ast_string_literal.h"
#include "ast_unparsed.h"
#include "ast_typed.h"
#include "../../base/assert.h"


_HexAstStringLiteral::_HexAstStringLiteral(
  ast_type_t type,
  char *value 
):AstTyped(type), AstUnparsed(value)
{
  this->reprOK();
}

bool
_HexAstStringLiteral::reprOK()
{
  HEX_ASSERT(this->_value);
  HEX_ASSERT(
    this->_type==AST_STRING_LITERAL_SINGLE_QUOTE ||
    this->_type==AST_STRING_LITERAL_DOUBLE_QUOTE
  );
}

HexAstStringLiteral
_HexAstStringLiteral::create(ast_type_t type, char *value)
{
  HexAstStringLiteral obj = new _HexAstStringLiteral(type, value);
  HEX_ASSERT(obj);
  return obj;
}
