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

#include "ast_val_atom.h"
#include "ast_typed.h"
#include "../../base/assert.h"

_HexAstValAtom::_HexAstValAtom(
  void *val,
  ast_type_t type
): _val(val), AstTyped(type)
{
  this->reprOK();
}

bool
_HexAstValAtom::reprOK()
{
  HEX_ASSERT(
    this->_type==AST_VAL_ATOM_EXPR ||
    this->_type==AST_VAL_ATOM_LAMBDA
  );
}

HexAstValAtom
_HexAstValAtom::create(
  void* val,
  ast_type_t type
)
{
  HEX_ASSERT(val);
  HEX_ASSERT(type);

  HexAstValAtom obj = new _HexAstValAtom(val, type);
  HEX_ASSERT(obj);
  return obj;
}
