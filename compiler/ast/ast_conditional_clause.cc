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

#include "ast_conditional_clause.h"
#include "ast_node.h"
#include "ast_task_state.h"
#include "ast_expr_list.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstConditionalClause::_HexAstConditionalClause(
  HexAstConditionalPreposition preposition,
  HexAstExprList exprs,
  HexAstTaskState state
):_preposition(preposition), _exprs(exprs), _state(state)
{
  this->reprOK();
}

bool
_HexAstConditionalClause::reprOK()
{
  HEX_ASSERT(this->_preposition);
  HEX_ASSERT(this->_exprs);
  HEX_ASSERT(this->_state);
}

HexAstConditionalPreposition
_HexAstConditionalClause::preposition()
{
  return this->_preposition;
}

HexAstExprList
_HexAstConditionalClause::exprs()
{
  return this->_exprs;
}

HexAstTaskState
_HexAstConditionalClause::state()
{
  return this->_state;
}

void
_HexAstConditionalClause::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstConditionalClause
_HexAstConditionalClause::create(
  HexAstConditionalPreposition preposition,
  HexAstExprList exprs,
  HexAstTaskState state
)
{
  HEX_ASSERT(preposition);
  HEX_ASSERT(exprs);
  HEX_ASSERT(state);

  HexAstConditionalClause obj = new _HexAstConditionalClause(
    preposition,
    exprs,
    state
  );

  HEX_ASSERT(obj);

  return obj;
}
