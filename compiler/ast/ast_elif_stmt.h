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
#include <sneaker/libc/c_str.h>
#include "ast_compound_stmt.h"
#include "ast_expr.h"
#include "ast_stmt_group.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_ELIF_STMT_H_
#define _AST_ELIF_STMT_H_

typedef class _HexAstElifStmt : public _HexAstCompoundStmt {
public:
  _HexAstElifStmt(HexAstExpr predicate, HexAstStmtGroup stmts):
    _predicate(predicate),
    _HexAstCompoundStmt(stmts)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->predicate());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExpr predicate() { return this->_predicate.get(); }

private:
  boost::scoped_ptr<_HexAstExpr> _predicate;
} * HexAstElifStmt;

#endif /* _AST_ELIF_STMT_H_ */