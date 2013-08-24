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

#include "ast_pause_clause.h"
#include "ast_task_clause.h"
#include "ast_expr_list.h"
#include "ast_conditional_clause.h"
#include "../../base/assert.h"

_HexAstPauseClause::_HexAstPauseClause(
  HexAstExprList exprs,
  HexAstConditionalClause condition
):_exprs(exprs), _condition(condition)
{
  this->reprOK();
}

bool
_HexAstPauseClause::reprOK()
{
  HEX_ASSERT(this->_exprs);
  HEX_ASSERT(this->_condition);
}

HexAstPauseClause
_HexAstPauseClause::create(
  HexAstExprList exprs,
  HexAstConditionalClause condition
)
{
  HEX_ASSERT(exprs);
  HEX_ASSERT(condition);

  HexAstPauseClause obj = new _HexAstPauseClause(
    exprs,
    condition
  );

  HEX_ASSERT(obj);

  return obj;
}
