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
#include "ast_stmt.h"
#include "ast_stmt_group.h"

#ifndef _AST_COMPOUND_STMT_H_
#define _AST_COMPOUND_STMT_H_

typedef class _HexAstCompoundStmt : public _HexAstStmt {
public:
  _HexAstCompoundStmt(HexAstStmtGroup stmts):
    _stmts(stmts)
  {
  }

  HexAstStmtGroup stmts() { return this->_stmts.get(); }
protected:
  boost::scoped_ptr<_HexAstStmtGroup> _stmts;
} * HexAstCompoundStmt;

#endif /* _AST_COMPOUND_STMT_H_ */