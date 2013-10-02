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

#include "ast_compound_stmt.h"
#include "ast_stmt_group.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_AWAIT_STMT_H_
#define _AST_AWAIT_STMT_H_

typedef class _HexAstAwaitStmt : public _HexAstCompoundStmt {
public:
  _HexAstAwaitStmt(HexAstStmtGroup);

  virtual bool reprOK();

  virtual void accept(AstVisitor*);

  static _HexAstAwaitStmt* create(HexAstStmtGroup);
} * HexAstAwaitStmt;

#endif /* _AST_AWAIT_STMT_H_ */