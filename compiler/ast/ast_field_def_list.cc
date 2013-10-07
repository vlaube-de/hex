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

#include "ast_field_def_list.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstFieldDefList::_HexAstFieldDefList()
{
  this->reprOK();
}

void
_HexAstFieldDefList::reprOK()
{
  AstListObj::reprOK();
}

void
_HexAstFieldDefList::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}
