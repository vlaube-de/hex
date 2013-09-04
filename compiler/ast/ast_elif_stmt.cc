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

#include "ast_elif_stmt.h"
#include "ast_expr.h"
#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstElifStmt::_HexAstElifStmt(
  HexAstExpr predicate,
  HexAstStmtGroup stmts
):_predicate(predicate), _HexAstCompoundStmt(stmts)
{
  this->reprOK();
}

bool
_HexAstElifStmt::reprOK()
{
  HEX_ASSERT(this->_predicate);
}

HexAstExpr
_HexAstElifStmt::predicate()
{
  return this->_predicate;
}

void
_HexAstElifStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstElifStmt
_HexAstElifStmt::create(
  HexAstExpr predicate,
  HexAstStmtGroup stmts
)
{
  HEX_ASSERT(predicate);

  HexAstElifStmt obj = new _HexAstElifStmt(predicate, stmts);
  HEX_ASSERT(obj);
  return obj;
}
