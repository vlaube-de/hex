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
#include "ast_primary.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_key_value_pair_list.h"
#include "ast_comprehension_list.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstDictForm::_HexAstDictForm(
) :
  _HexAstPrimary(
    EXPR_ASSOCIATIVITY_LEFT,
    EXPR_PRECEDENCE_PRIMARY_1
  )
{
}

_HexAstExplicitDictForm::_HexAstExplicitDictForm(
  HexAstKeyValuePairList fields 
) : _fields(fields)
{
  this->reprOK();
}

void
_HexAstExplicitDictForm::reprOK()
{
  // Do nothing here.
}

HexAstKeyValuePairList
_HexAstExplicitDictForm::fields()
{
  return this->_fields.get();
}

void
_HexAstExplicitDictForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstExplicitDictForm
_HexAstExplicitDictForm::create(
  HexAstKeyValuePairList fields
)
{
  HexAstExplicitDictForm obj = new _HexAstExplicitDictForm(fields);
  HEX_ASSERT(obj);
  return obj;
}


_HexAstImplicitDictForm::_HexAstImplicitDictForm(
  HexAstComprehensionList comprehensions
) : _comprehensions(comprehensions)
{
  this->reprOK();
}

void
_HexAstImplicitDictForm::reprOK()
{
  HEX_ASSERT(this->comprehensions());
}

HexAstComprehensionList
_HexAstImplicitDictForm::comprehensions()
{
  return this->_comprehensions.get();
}

void
_HexAstImplicitDictForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstImplicitDictForm
_HexAstImplicitDictForm::create(HexAstComprehensionList comprehensions)
{
  HexAstImplicitDictForm obj = new _HexAstImplicitDictForm(comprehensions);
  HEX_ASSERT(obj);
  return obj;
}
