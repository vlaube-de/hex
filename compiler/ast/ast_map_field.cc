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

#include "ast_map_field.h"
#include "ast_expr.h"
#include "ast_val_atom.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstMapField::_HexAstMapField(
  HexAstExpr key,
  HexAstValAtom val
):_key(key), _val(val)
{
  this->reprOK();
}

bool
_HexAstMapField::reprOK()
{
  HEX_ASSERT(this->_key);
  HEX_ASSERT(this->_val);
}

HexAstExpr
_HexAstMapField::key()
{
  return this->_key.get();
}

HexAstValAtom
_HexAstMapField::val()
{
  return this->_val.get();
}

void
_HexAstMapField::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstMapField
_HexAstMapField::create(
  HexAstExpr key,
  HexAstValAtom val
)
{
  HEX_ASSERT(key);
  HEX_ASSERT(val);

  HexAstMapField obj = new _HexAstMapField(key, val);
  HEX_ASSERT(obj);
  return obj;
}
