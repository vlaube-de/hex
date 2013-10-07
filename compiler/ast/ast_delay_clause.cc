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

#include "ast_delay_clause.h"
#include "ast_task_clause.h"
#include "ast_task_state.h"
#include "ast_expr_list.h"
#include "ast_conditional_clause.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstDelayClause::_HexAstDelayClause()
{
  this->reprOK();
}

void
_HexAstDelayClause::reprOK()
{
  // Do nothing here.
}

_HexAstConditionalDelayClause::_HexAstConditionalDelayClause(
  HexAstExprList exprs,
  HexAstConditionalClause condition
):_exprs(exprs), _condition(condition)
{
  this->reprOK();
}

void
_HexAstConditionalDelayClause::reprOK()
{
  HEX_ASSERT(this->exprs());
  HEX_ASSERT(this->condition());
}

HexAstExprList
_HexAstConditionalDelayClause::exprs()
{
  return this->_exprs.get();
}

HexAstConditionalClause
_HexAstConditionalDelayClause::condition()
{
  return this->_condition.get();
}

void
_HexAstConditionalDelayClause::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstConditionalDelayClause
_HexAstConditionalDelayClause::create(
  HexAstExprList exprs,
  HexAstConditionalClause condition
)
{
  HEX_ASSERT(exprs);
  HEX_ASSERT(condition);

  HexAstConditionalDelayClause obj = new _HexAstConditionalDelayClause(
    exprs,
    condition
  );

  HEX_ASSERT(obj);

  return obj;
}

_HexAstFixedDelayClause::_HexAstFixedDelayClause(
  HexAstExprList exprs,
  HexAstExpr delay
):_exprs(exprs), _delay(delay)
{
  this->reprOK();
}

void
_HexAstFixedDelayClause::reprOK()
{
  HEX_ASSERT(this->delay());
}

HexAstExprList
_HexAstFixedDelayClause::exprs()
{
  return this->_exprs.get();
}

HexAstExpr
_HexAstFixedDelayClause::delay()
{
  return this->_delay.get();
}

void
_HexAstFixedDelayClause::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstFixedDelayClause
_HexAstFixedDelayClause::create(
  HexAstExprList exprs,
  HexAstExpr delay
)
{
  HEX_ASSERT(delay);

  HexAstFixedDelayClause obj = new _HexAstFixedDelayClause(
    exprs,
    delay
  );

  HEX_ASSERT(obj);

  return obj;
}
