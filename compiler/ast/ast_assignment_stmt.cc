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

#include "ast_assignment_stmt.h"
#include "ast_node.h"
#include "ast_primary.h"
#include "ast_expr_list.h"
#include "ast_lambda.h"
#include "ast_decorator_list.h"
#include "ast_task_def.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstAssignmentStmt::_HexAstAssignmentStmt(
  HexAstPrimary target,
  bool defer
):
  _target(target),
  _defer(defer)
{
  this->reprOK();
}

void
_HexAstAssignmentStmt::reprOK()
{
  HEX_ASSERT(this->target());
}

HexAstPrimary
_HexAstAssignmentStmt::target()
{
  return this->_target.get();
}

bool
_HexAstAssignmentStmt::defer()
{
  return this->_defer;
}

_HexAstExprListAssignmentStmt::_HexAstExprListAssignmentStmt(
  HexAstPrimary target,
  HexAstExprList src,
  bool defer
):
  _HexAstAssignmentStmt(target, defer),
  _src(src)
{
  this->reprOK();
}

void
_HexAstExprListAssignmentStmt::reprOK()
{
  HEX_ASSERT(this->src());
}

void
_HexAstExprListAssignmentStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstExprList
_HexAstExprListAssignmentStmt::src()
{
  return this->_src.get();
}

HexAstExprListAssignmentStmt
_HexAstExprListAssignmentStmt::create(
  HexAstPrimary target,
  HexAstExprList src,
  bool defer
)
{
  HexAstExprListAssignmentStmt obj = new _HexAstExprListAssignmentStmt(
    target,
    src,
    defer
  );

  HEX_ASSERT(obj);
  return obj;
}

_HexAstLambdaAssignmentStmt::_HexAstLambdaAssignmentStmt(
  HexAstDecoratorList decorators,
  HexAstPrimary target,
  HexAstLambda src,
  bool defer
):
  _decorators(decorators),
  _src(src),
  _HexAstAssignmentStmt(target, defer)
{
  this->reprOK();
}

void
_HexAstLambdaAssignmentStmt::reprOK()
{
  HEX_ASSERT(this->src());
}

void
_HexAstLambdaAssignmentStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstDecoratorList
_HexAstLambdaAssignmentStmt::decorators()
{
  return this->_decorators.get();
}

HexAstLambda
_HexAstLambdaAssignmentStmt::src()
{
  return this->_src.get();
}

HexAstLambdaAssignmentStmt
_HexAstLambdaAssignmentStmt::create(
  HexAstDecoratorList decorators,
  HexAstPrimary target,
  HexAstLambda src,
  bool defer
)
{
  HexAstLambdaAssignmentStmt obj = new _HexAstLambdaAssignmentStmt(
    decorators,
    target,
    src,
    defer
  );

  HEX_ASSERT(obj);
  return obj;
}

_HexAstTaskDefAssignmentStmt::_HexAstTaskDefAssignmentStmt(
  HexAstPrimary target,
  HexAstTaskDef src,
  bool defer
):
  _src(src),
  _HexAstAssignmentStmt(target, defer)
{
  this->reprOK();
}

void
_HexAstTaskDefAssignmentStmt::reprOK()
{
  HEX_ASSERT(this->src());
}

void
_HexAstTaskDefAssignmentStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstTaskDef
_HexAstTaskDefAssignmentStmt::src()
{
  return this->_src.get();
}

HexAstTaskDefAssignmentStmt
_HexAstTaskDefAssignmentStmt::create(
  HexAstPrimary target,
  HexAstTaskDef src,
  bool defer
)
{
  HexAstTaskDefAssignmentStmt obj = new _HexAstTaskDefAssignmentStmt(
    target,
    src,
    defer
  );

  HEX_ASSERT(obj);
  return obj;
}
