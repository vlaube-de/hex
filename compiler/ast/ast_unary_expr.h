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
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_expr.h"
#include "examiner.h"

#ifndef _AST_UNARY_EXPR_H_
#define _AST_UNARY_EXPR_H_


typedef class _HexAstUnaryExpr : public _HexAstExpr {
public:
  _HexAstUnaryExpr(
    HexAstExpr,
    HexAstExprAssociativity,
    HexAstExprPrecedence
  );

  virtual void reprOK();

  HexAstExpr expr();

  template<typename T>
  static T* create(HexAstExpr);
protected:
  boost::scoped_ptr<_HexAstExpr> _expr;
} * HexAstUnaryExpr;

template<typename T>
T*
_HexAstUnaryExpr::create(HexAstExpr expr)
{
  T* obj = new T(expr);
  return obj;
}

#endif /* _AST_UNARY_EXPR_H_ */
