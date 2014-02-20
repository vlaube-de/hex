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
#include <sneaker/libc/assert.h>
#include "ast_expr.h"
#include "ast_simple_stmt.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_SIMPLE_IF_STMT_H_
#define _AST_SIMPLE_IF_STMT_H_

typedef class _HexAstSimpleIfStmt : public _HexAstSimpleStmt {
public:
  _HexAstSimpleIfStmt(HexAstExpr predicate, HexAstSimpleStmt stmt):
    _predicate(predicate),
    _stmt(stmt)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->predicate());
    ASSERT(this->stmt());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExpr predicate() { return this->_predicate.get(); }
  HexAstSimpleStmt stmt() { return this->_stmt.get(); }

private:
  boost::scoped_ptr<_HexAstExpr> _predicate;
  boost::scoped_ptr<_HexAstSimpleStmt> _stmt;
} * HexAstSimpleIfStmt;

#endif /* _AST_SIMPLE_IF_STMT_H_ */