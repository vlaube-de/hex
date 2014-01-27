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

#include <boost/smart_ptr.hpp>
#include "ast_compound_stmt.h"
#include "ast_expr.h"
#include "ast_identifier.h"
#include "ast_stmt_group.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_WITH_STMT_H_
#define _AST_WITH_STMT_H_

typedef class _HexAstWithStmt : public _HexAstCompoundStmt {
public:
  _HexAstWithStmt(
    HexAstExpr expr,
    HexAstIdentifier alias,
    HexAstStmtGroup stmts
  ):
    _expr(expr),
    _alias(alias),
    _HexAstCompoundStmt(stmts)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->expr());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExpr expr() { return this->_expr.get(); }
  HexAstIdentifier alias() { return this->_alias.get(); }

private:
  boost::scoped_ptr<_HexAstExpr> _expr;
  boost::scoped_ptr<_HexAstIdentifier> _alias;
} * HexAstWithStmt;

#endif /* _AST_WITH_STMT_H_ */