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
#include "ast_catch_stmt_group.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_TRY_STMT_H_
#define _AST_TRY_STMT_H_

typedef class _HexAstTryStmt : public _HexAstCompoundStmt {
public:
  _HexAstTryStmt(HexAstStmtGroup, HexAstCatchStmtGroup);

  virtual bool reprOK();

  HexAstCatchStmtGroup catch_stmt_group();

  virtual void accept(AstVisitor*);

  static _HexAstTryStmt* create(HexAstStmtGroup, HexAstCatchStmtGroup);
private:
  boost::scoped_ptr<_HexAstCatchStmtGroup> _catch_stmt_group;
} * HexAstTryStmt;

#endif /* _AST_TRY_STMT_H_ */
