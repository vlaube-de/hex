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
#include "ast_primary.h"
#include "ast_attribute_ref.h"
#include "../../base/assert.h"

_HexAstAttributeRef::_HexAstAttributeRef(
  HexAstPrimary source,
  char *attribute
): _source(source), _attribute(strdup(attribute))
{
  this->reprOK();
}

bool
_HexAstAttributeRef::reprOK()
{
  HEX_ASSERT(this->_source);
  HEX_ASSERT(this->_attribute);
}

HexAstAttributeRef
_HexAstAttributeRef::create(
  HexAstPrimary source,
  char *attribute
)
{
  HexAstAttributeRef obj = new _HexAstAttributeRef(source, attribute);
  HEX_ASSERT(obj);
  return obj;
}
