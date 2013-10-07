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
#include "ast_typed.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstUsingSrc::_HexAstUsingSrc(
  HexAstName name,
  ast_type_t type
):_name(name), AstTyped(type)
{
  this->reprOK();
}

void
_HexAstUsingSrc::reprOK()
{
  HEX_ASSERT(this->_type);
  if(this->_type == AST_USING_SRC_NAME) {
    HEX_ASSERT(this->_name);
  }
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
  HexAstName name,
  ast_type_t type
)
{
  HexAstUsingSrc obj = new _HexAstUsingSrc(name, type);
  HEX_ASSERT(obj);
  return obj;
}
