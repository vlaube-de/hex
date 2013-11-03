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

#include "ast_simple_param.h"
#include "ast_identifier.h"
#include "ast_name.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstSimpleParam::_HexAstSimpleParam(
  HexAstIdentifier name,
  HexAstName type
) : _name(name), _type(type)
{
  this->reprOK();
}

void
_HexAstSimpleParam::reprOK()
{
  HEX_ASSERT(this->name());
}

void
_HexAstSimpleParam::accept(AstVisitor *visitor)
{
  visitor->visit(this);
}

HexAstIdentifier
_HexAstSimpleParam::name()
{
  return this->_name.get();
}

HexAstName
_HexAstSimpleParam::type()
{
  return this->_type.get();
}

HexAstSimpleParam
_HexAstSimpleParam::create(HexAstIdentifier name, HexAstName type)
{
  HexAstSimpleParam obj = new _HexAstSimpleParam(name, type);
  HEX_ASSERT(obj);
  return obj;
}
