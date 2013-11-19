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

#include "ast_keyword_val.h"
#include "ast_identifier.h"
#include "ast_val_atom.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"


_HexAstKeywordVal::_HexAstKeywordVal(
  HexAstIdentifier key,
  HexAstValAtom val
):_key(key), _val(val)
{
  this->reprOK();
}

void
_HexAstKeywordVal::reprOK()
{
  HEX_ASSERT(this->key());
  HEX_ASSERT(this->val());
}

HexAstIdentifier
_HexAstKeywordVal::key()
{
  return this->_key.get();
}

HexAstValAtom
_HexAstKeywordVal::val()
{
  return this->_val.get();
}

void
_HexAstKeywordVal::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstKeywordVal
_HexAstKeywordVal::create(
  HexAstIdentifier key,
  HexAstValAtom val
)
{
  HEX_ASSERT(key);
  HEX_ASSERT(val);

  HexAstKeywordVal obj = new _HexAstKeywordVal(key, val);
  HEX_ASSERT(obj);

  return obj;
}
