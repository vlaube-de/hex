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

#include "ast_with_stmt.h"
#include "ast_expr_list.h"
#include "ast_compound_stmt.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstWithStmt::_HexAstWithStmt(
  HexAstExprList exprs,
  HexAstIdentifier alias,
  HexAstStmtGroup stmts
):_exprs(exprs), _alias(alias), _HexAstCompoundStmt(stmts)
{
  this->reprOK();
}

void
_HexAstWithStmt::reprOK()
{
  HEX_ASSERT(this->exprs());
}

HexAstExprList
_HexAstWithStmt::exprs()
{
  return this->_exprs.get();
}

HexAstIdentifier
_HexAstWithStmt::alias()
{
  return this->_alias.get();
}

void
_HexAstWithStmt::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstWithStmt
_HexAstWithStmt::create(
  HexAstExprList exprs,
  HexAstIdentifier alias,
  HexAstStmtGroup stmts
)
{
  HEX_ASSERT(exprs);

  HexAstWithStmt obj = new _HexAstWithStmt(
    exprs,
    alias,
    stmts
  );

  HEX_ASSERT(obj);

  return obj;
}
