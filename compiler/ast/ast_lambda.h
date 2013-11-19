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
#include "ast_parameter_list.h"
#include "ast_stmt_group.h"
#include "ast_expr.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_LAMBDA_H_
#define _AST_LAMBDA_H_

typedef class _HexAstLambda : public _HexAstValAtom {
public:
  _HexAstLambda(HexAstParameterList);

  virtual void reprOK();

  HexAstParameterList params();
protected:
  boost::scoped_ptr<_HexAstParameterList> _params;
} * HexAstLambda;

typedef class _HexAstLambdaSimple : public _HexAstLambda {
public:
  _HexAstLambdaSimple(HexAstParameterList, HexAstExpr);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstExpr expr();

  static _HexAstLambdaSimple* create(HexAstParameterList, HexAstExpr);
private:
  boost::scoped_ptr<_HexAstExpr> _expr;
} * HexAstLambdaSimple;

typedef class _HexAstLambdaComplex : public _HexAstLambda {
public:
  _HexAstLambdaComplex(HexAstParameterList, HexAstStmtGroup);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstStmtGroup stmts();

  static _HexAstLambdaComplex* create(HexAstParameterList, HexAstStmtGroup);
private:
  boost::scoped_ptr<_HexAstStmtGroup> _stmts;
} * HexAstLambdaComplex;

#endif /* _AST_LAMBDA_H_ */
