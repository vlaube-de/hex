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

#include "ast_start_clause.h"
#include "ast_task_clause.h"
#include "ast_name.h"
#include "ast_target_list.h"
#include "ast_conditional_clause.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstStartClause::_HexAstStartClause(
  HexAstIdentifier alias,
  HexAstConditionalClause condition
):_alias(alias), _condition(condition)
{
  this->reprOK();
}

void
_HexAstStartClause::reprOK()
{
  // Do nothing here.
}

HexAstIdentifier
_HexAstStartClause::alias()
{
  return this->_alias.get();
}

HexAstConditionalClause
_HexAstStartClause::condition()
{
  return this->_condition.get();
}

_HexAstStartClauseSingle::_HexAstStartClauseSingle(
  HexAstName target,
  HexAstIdentifier alias,
  HexAstConditionalClause condition
):_target(target), _HexAstStartClause(alias, condition)
{
  this->reprOK();
}

void
_HexAstStartClauseSingle::reprOK()
{
  HEX_ASSERT(this->target());
}

HexAstName
_HexAstStartClauseSingle::target()
{
  return this->_target.get();
}

void
_HexAstStartClauseSingle::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstStartClauseSingle
_HexAstStartClauseSingle::create(
  HexAstName target,
  HexAstIdentifier alias,
  HexAstConditionalClause condition
)
{
  HEX_ASSERT(target);

  HexAstStartClauseSingle obj = new _HexAstStartClauseSingle(
    target,
    alias,
    condition
  );

  HEX_ASSERT(obj);

  return obj;
}

_HexAstStartClauseMultiple::_HexAstStartClauseMultiple(
  HexAstTargetList targets,
  HexAstIdentifier alias,
  HexAstConditionalClause condition
):_targets(targets), _HexAstStartClause(alias, condition)
{
  this->reprOK();
}

void
_HexAstStartClauseMultiple::reprOK()
{
  HEX_ASSERT(this->targets());
}

HexAstTargetList
_HexAstStartClauseMultiple::targets()
{
  return this->_targets.get();
}

void
_HexAstStartClauseMultiple::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstStartClauseMultiple
_HexAstStartClauseMultiple::create(
  HexAstTargetList targets,
  HexAstIdentifier alias,
  HexAstConditionalClause condition
)
{
  HEX_ASSERT(targets);

  HexAstStartClauseMultiple obj = new _HexAstStartClauseMultiple(
    targets,
    alias,
    condition
  );

  HEX_ASSERT(obj);

  return obj;
}
