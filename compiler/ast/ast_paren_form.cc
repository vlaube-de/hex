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

#include "ast_expr_list.h"
#include "ast_paren_form.h"
#include "ast_primary.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "../../base/assert.h"
#include "visitor/ast_visitor.h"

_HexAstParenForm::_HexAstParenForm(
  HexAstExprList exprs
) :
  _exprs(exprs),
  _HexAstPrimary(
    EXPR_ASSOCIATIVITY_LEFT,
    EXPR_PRECEDENCE_PRIMARY_1
  )
{
  this->reprOK();
}

void
_HexAstParenForm::reprOK()
{
  // Do nothing here.
}

HexAstExprList
_HexAstParenForm::exprs()
{
  return this->_exprs.get();
}

void
_HexAstParenForm::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstParenForm
_HexAstParenForm::create(
  HexAstExprList exprs
)
{
  HexAstParenForm obj = new _HexAstParenForm(exprs);
  HEX_ASSERT(obj);
  return obj;
}
