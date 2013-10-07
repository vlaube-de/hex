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

#include "ast_dict_form.h"
#include "ast_typed.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstDictForm::_HexAstDictForm(
  void* core,
  ast_type_t type
):_core(core), AstTyped(type)
{
  this->reprOK();
}

void
_HexAstDictForm::reprOK()
{
  HEX_ASSERT(
    this->_type==AST_DICT_FORM_EMPTY ||
    this->_type==AST_DICT_FORM_EXPLICIT ||
    this->_type==AST_DICT_FORM_COMPREHENSION
  );
}

void*
_HexAstDictForm::core()
{
  return this->_core;
}

void
_HexAstDictForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstDictForm
_HexAstDictForm::create(
  void* core,
  ast_type_t type
)
{
  HexAstDictForm obj = new _HexAstDictForm(core, type);
  HEX_ASSERT(obj);
  return obj;
}
