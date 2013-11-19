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

#include "ast_key_value_pair.h"
#include "ast_expr.h"
#include "ast_val_atom.h"
#include "../../base/assert.h"
#include "../visitor/ast_visitor.h"


_HexAstKeyValuePair::_HexAstKeyValuePair(
  HexAstExpr key,
  HexAstValAtom value
) :
  _key(key),
  _value(value)
{
  this->reprOK();
}

void
_HexAstKeyValuePair::reprOK()
{
  HEX_ASSERT(this->key());
  HEX_ASSERT(this->value());
}

void
_HexAstKeyValuePair::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstExpr
_HexAstKeyValuePair::key()
{
  return this->_key.get();
}

HexAstValAtom
_HexAstKeyValuePair::value()
{
  return this->_value.get();
}

HexAstKeyValuePair
_HexAstKeyValuePair::create(
  HexAstExpr key,
  HexAstValAtom value
)
{
  HexAstKeyValuePair obj = new _HexAstKeyValuePair(key, value);
  HEX_ASSERT(obj);
  return obj;
}
