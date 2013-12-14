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
#include "ast_expr.h"
#include "ast_expr_associativity.h"
#include "ast_expr_list.h"
#include "ast_expr_precedence.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_YIELD_EXPR_H_
#define _AST_YIELD_EXPR_H_

typedef class _HexAstYieldExpr : public _HexAstExpr {
public:
  _HexAstYieldExpr(HexAstExprList exprs):
    _exprs(exprs),
    _HexAstExpr(
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_YIELD_EXPR
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExprList exprs() { return this->_exprs.get(); }

private:
  boost::scoped_ptr<_HexAstExprList> _exprs;
} * HexAstYieldExpr;

#endif /* _AST_YIELD_EXPR_H_ */