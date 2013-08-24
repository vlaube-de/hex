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

#include "ast_list_form.h"
#include "../../base/assert.h"

_HexAstListForm::_HexAstListForm(
  void* core,
  ast_type_t type
):_core(core), AstTyped(type)
{
  this->reprOK();
}

bool
_HexAstListForm::reprOK()
{
  HEX_ASSERT(
    this->_type==AST_LIST_FORM_EMPTY ||
    this->_type==AST_LIST_FORM_EXPR_LIST ||
    this->_type==AST_LIST_FORM_COMPREHENSION
  );
}

HexAstListForm
_HexAstListForm::create(
  void* core, ast_type_t type
)
{
  HexAstListForm obj = new _HexAstListForm(core, type);
  HEX_ASSERT(obj);
  return obj;
}
