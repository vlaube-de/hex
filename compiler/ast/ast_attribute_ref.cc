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

#include <list>
#include "ast_identifier.h"
#include "ast_primary.h"
#include "ast_attribute_ref.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstAttributeRef::_HexAstAttributeRef(
  HexAstPrimary source,
  HexAstIdentifier attribute
): _source(source), _attribute(attribute)
{
  this->reprOK();
}

bool
_HexAstAttributeRef::reprOK()
{
  HEX_ASSERT(this->_source);
  HEX_ASSERT(this->_attribute);
}

HexAstPrimary
_HexAstAttributeRef::source()
{
  return this->_source.get();
}

HexAstIdentifier
_HexAstAttributeRef::attribute()
{
  return this->_attribute.get();
}

void
_HexAstAttributeRef::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstAttributeRef
_HexAstAttributeRef::create(
  HexAstPrimary source,
  HexAstIdentifier attribute
)
{
  HexAstAttributeRef obj = new _HexAstAttributeRef(source, attribute);
  HEX_ASSERT(obj);
  return obj;
}
