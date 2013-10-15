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

#include "ast_map_form.h"
#include "ast_primary.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_map_field_list.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstMapForm::_HexAstMapForm(
  HexAstMapFieldList list
):
  _list(list),
  _HexAstPrimary(
    EXPR_ASSOCIATIVITY_LEFT,
    EXPR_PRECEDENCE_PRIMARY_1
  )
{
  this->reprOK();
}

void
_HexAstMapForm::reprOK()
{
  HEX_ASSERT(this->list());
}

HexAstMapFieldList
_HexAstMapForm::list()
{
  return this->_list.get();
}

void
_HexAstMapForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstMapForm
_HexAstMapForm::create(
  HexAstMapFieldList list
)
{
  HexAstMapForm obj = new _HexAstMapForm(list);
  HEX_ASSERT(obj);
  return obj;
}
