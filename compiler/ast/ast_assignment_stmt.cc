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
#include "ast_decorator_list.h"
#include "ast_typed.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstAssignmentStmt::_HexAstAssignmentStmt(
  HexAstDecoratorList decorators,
  HexAstPrimary dst,
  void* src,
  ast_type_t type,
  bool defer
):
  _decorators(decorators),
  _dst(dst),
  _src(src),
  AstTyped(type),
  _defer(defer)
{
  this->reprOK();
}

bool
_HexAstAssignmentStmt::reprOK()
{
  HEX_ASSERT(this->_src);
  HEX_ASSERT(this->_dst);
  HEX_ASSERT(
    this->_type==AST_ASSIGNMENT_STMT_EXPR_LIST ||
    this->_type==AST_ASSIGNMENT_STMT_LAMBDA ||
    this->_type==AST_ASSIGNMENT_STMT_TASK
  );
}

HexAstDecoratorList
_HexAstAssignmentStmt::decorators()
{
  return this->_decorators.get();
}

HexAstPrimary
_HexAstAssignmentStmt::dst()
{
  return this->_dst.get();
}

void*
_HexAstAssignmentStmt::src()
{
  return this->_src;
}

bool
_HexAstAssignmentStmt::defer()
{
  return this->_defer;
}

void
_HexAstAssignmentStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstAssignmentStmt
_HexAstAssignmentStmt::create(
  HexAstDecoratorList decorators,
  HexAstPrimary dst,
  void* src,
  ast_type_t type,
  bool defer
)
{
  HEX_ASSERT(src);
  HEX_ASSERT(dst);
  HEX_ASSERT(type);

  HexAstAssignmentStmt obj = new _HexAstAssignmentStmt(
    decorators,
    dst,
    src,
    type,
    defer
  );

  HEX_ASSERT(obj);

  return obj;
}
