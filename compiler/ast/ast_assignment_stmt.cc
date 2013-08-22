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
#include "../../base/assert.h"

_HexAstAssignmentStmt::_HexAstAssignmentStmt(
  HexAstDecoratorList decorators,
  HexAstPrimary dst,
  void* src,
  char type,
  bool defer
):_decorators(decorators), _dst(dst), _src(src), _type(type), _defer(defer)
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
    this->_type==AST_ASSIGNMENT_STMT_LAMBDA
  );
}
