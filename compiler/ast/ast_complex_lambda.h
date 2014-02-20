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
#include "ast_lambda.h"
#include "ast_parameter_list.h"
#include "ast_stmt_group.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_COMPLEX_LAMBDA_H_
#define _AST_COMPLEX_LAMBDA_H_

typedef class _HexAstComplexLambda : public _HexAstLambda {
public:
  _HexAstComplexLambda(HexAstParameterList params, HexAstStmtGroup stmts):
    _stmts(stmts),
    _HexAstLambda(params)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstStmtGroup stmts() { return this->_stmts.get(); }

private:
  boost::scoped_ptr<_HexAstStmtGroup> _stmts;
} * HexAstComplexLambda;

#endif /* _AST_COMPLEX_LAMBDA_H_ */