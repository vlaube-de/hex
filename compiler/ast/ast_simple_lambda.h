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
#include "ast_parameter_list.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_SIMPLE_LAMBDA_H_
#define _AST_SIMPLE_LAMBDA_H_

typedef class _HexAstSimpleLambda : public _HexAstLambda {
public:
  _HexAstSimpleLambda(HexAstParameterList params, HexAstExpr expr):
    _expr(expr),
    _HexAstLambda(params)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->expr());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExpr expr() { return this->_expr.get(); }

private:
  boost::scoped_ptr<_HexAstExpr> _expr;
} * HexAstSimpleLambda;

#endif /* _AST_SIMPLE_LAMBDA_H_ */