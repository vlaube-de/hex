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
#include "ast_primary.h"
#include "ast_expr_list.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_comprehension.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstListForm::_HexAstListForm(
) : _HexAstPrimary(
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_PRIMARY_1
    )
{
}

_HexAstExplicitListForm::_HexAstExplicitListForm(
  HexAstExprList elements
) : _elements(elements)
{
  this->reprOK();
}

void
_HexAstExplicitListForm::reprOK()
{
  // Do nothing here.
}

void
_HexAstExplicitListForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstExprList
_HexAstExplicitListForm::elements()
{
  return this->_elements.get();
}

HexAstExplicitListForm
_HexAstExplicitListForm::create(HexAstExprList elements)
{
  HexAstExplicitListForm obj = new _HexAstExplicitListForm(elements);
  HEX_ASSERT(obj);
  return obj;
}

_HexAstImplicitListForm::_HexAstImplicitListForm(
  HexAstComprehension comprehension
) : _comprehension(comprehension)
{
  this->reprOK();
}

void
_HexAstImplicitListForm::reprOK()
{
  HEX_ASSERT(this->comprehension());
}

void
_HexAstImplicitListForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstComprehension
_HexAstImplicitListForm::comprehension()
{
  return this->_comprehension.get();
}

HexAstImplicitListForm
_HexAstImplicitListForm::create(HexAstComprehension comprehension)
{
  HexAstImplicitListForm obj = new _HexAstImplicitListForm(comprehension);
  HEX_ASSERT(obj);
  return obj;
}
