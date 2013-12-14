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
#include "ast_expr_list.h"
#include "ast_simple_stmt.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_RETURN_STMT_H_
#define _AST_RETURN_STMT_H_

typedef class _HexAstReturnStmt : public _HexAstSimpleStmt {
public:
  _HexAstReturnStmt(HexAstExprList return_vals):
    _return_vals(return_vals)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExprList return_vals() { return this->_return_vals.get(); }

private:
  boost::scoped_ptr<_HexAstExprList> _return_vals;
} * HexAstReturnStmt;

#endif /* _AST_RETURN_STMT_H_ */