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
#include "ast_catch_stmt_group.h"
#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_TRY_STMT_H_
#define _AST_TRY_STMT_H_

typedef class _HexAstTryStmt : public _HexAstCompoundStmt {
public:
  _HexAstTryStmt(
    HexAstStmtGroup stmts,
    HexAstCatchStmtGroup catch_stmt_group,
    HexAstStmtGroup else_stmts
  ):
    _HexAstCompoundStmt(stmts),
    _catch_stmt_group(catch_stmt_group),
    _else_stmts(else_stmts)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstCatchStmtGroup catch_stmt_group() { return this->_catch_stmt_group.get(); }
  HexAstStmtGroup else_stmts() { return this->_else_stmts.get(); }

private:
  boost::scoped_ptr<_HexAstCatchStmtGroup> _catch_stmt_group;
  boost::scoped_ptr<_HexAstStmtGroup> _else_stmts;
} * HexAstTryStmt;

#endif /* _AST_TRY_STMT_H_ */