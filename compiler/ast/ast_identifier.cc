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

#include "ast_identifier.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"


_HexAstIdentifier::_HexAstIdentifier(
  c_str identifier
):_identifier(strdup(identifier))
{
  this->reprOK();
}

bool
_HexAstIdentifier::reprOK()
{
  HEX_ASSERT(this->_identifier);
}

c_str
_HexAstIdentifier::identifier()
{
  return this->_identifier;
}

void
_HexAstIdentifier::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstIdentifier
_HexAstIdentifier::create(c_str identifier)
{
  HEX_ASSERT(identifier);

  HexAstIdentifier obj = new _HexAstIdentifier(identifier);
  HEX_ASSERT(obj);
  return obj;
}