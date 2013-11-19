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

#include "ast_conditional_preposition.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"


_HexAstConditionalPreposition::_HexAstConditionalPreposition(
  HexAstConditionalPrepositionEnum preposition
):_preposition(preposition)
{
  this->reprOK();
}

void
_HexAstConditionalPreposition::reprOK()
{
  HEX_ASSERT(this->preposition());
}

HexAstConditionalPrepositionEnum
_HexAstConditionalPreposition::preposition()
{
  return this->_preposition;
}

void
_HexAstConditionalPreposition::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstConditionalPreposition
_HexAstConditionalPreposition::create(
  HexAstConditionalPrepositionEnum preposition
)
{
  HEX_ASSERT(preposition);

  HexAstConditionalPreposition obj = new _HexAstConditionalPreposition(preposition);
  HEX_ASSERT(obj);
  return obj;
}
