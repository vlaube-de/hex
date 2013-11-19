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

#include "ast_keyword_param.h"
#include "ast_name.h"
#include "ast_identifier.h"
#include "ast_val_atom.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstKeywordParam::_HexAstKeywordParam(
  HexAstName type,
  HexAstIdentifier name,
  HexAstValAtom value
) :
  _type(type),
  _name(name),
  _value(value)
{
  this->reprOK();
}

void
_HexAstKeywordParam::reprOK()
{
  HEX_ASSERT(this->name());
  HEX_ASSERT(this->value());
}

void
_HexAstKeywordParam::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstName
_HexAstKeywordParam::type()
{
  return this->_type.get();
}

HexAstIdentifier
_HexAstKeywordParam::name()
{
  return this->_name.get();
}

HexAstValAtom
_HexAstKeywordParam::value()
{
  return this->_value.get();
}

HexAstKeywordParam
_HexAstKeywordParam::create(
  HexAstName type,
  HexAstIdentifier name,
  HexAstValAtom value
)
{
  HexAstKeywordParam obj = new _HexAstKeywordParam(type, name, value);
  HEX_ASSERT(obj);
  return obj;
}
