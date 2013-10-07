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

#include "ast_using_src.h"
#include "ast_name.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstUsingSrc::_HexAstUsingSrc(
  size_t level,
  HexAstName name
) :
  _level(level),
  _name(name)
{
  this->reprOK();
}

void
_HexAstUsingSrc::reprOK()
{
  if(this->level() == 0) {
    HEX_ASSERT(this->name());
  }
}

size_t
_HexAstUsingSrc::level()
{
  return this->_level;
}

HexAstName
_HexAstUsingSrc::name()
{
  return this->_name.get();
}

void
_HexAstUsingSrc::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstUsingSrc
_HexAstUsingSrc::create(
  size_t level,
  HexAstName name
)
{
  HexAstUsingSrc obj = new _HexAstUsingSrc(level, name);
  HEX_ASSERT(obj);
  return obj;
}
