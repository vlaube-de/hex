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
#include "../../base/assert.h"


_HexAstParenForm::_HexAstParenForm(
  HexAstExprList exprs
):_exprs(exprs)
{
  this->reprOK();
}

bool
_HexAstParenForm::reprOK()
{
  HEX_ASSERT(this->_exprs);
}

HexAstParenForm
_HexAstParenForm::create(
  HexAstExprList exprs
)
{
  HEX_ASSERT(exprs);

  HexAstParenForm obj = new _HexAstParenForm(exprs);
  HEX_ASSERT(obj);
  return obj;
}
