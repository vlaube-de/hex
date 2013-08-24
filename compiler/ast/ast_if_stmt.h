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

#include "ast_expr.h"
#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "ast_elif_stmt_group.h"
#include "ast_else_stmt.h"

#ifndef _AST_IF_STMT_H_
#define _AST_IF_STMT_H_

typedef class _HexAstIfStmt : public _HexAstCompoundStmt {
public:
  _HexAstIfStmt(HexAstExpr, HexAstStmtGroup, HexAstElifStmtGroup, HexAstElseStmt);

  virtual bool reprOK();

  static _HexAstIfStmt* create(HexAstExpr, HexAstStmtGroup, HexAstElifStmtGroup, HexAstElseStmt);
private:
  HexAstExpr _predicate;
  HexAstElifStmtGroup _elif_stmts;
  HexAstElseStmt _else_stmt;
} * HexAstIfStmt;

#endif /* _AST_IF_STMT_H_ */
