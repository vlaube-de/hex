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
#include "examiner.h"

#ifndef _HEX_AST_BINARY_EXPR_H_
#define _HEX_AST_BINARY_EXPR_H_


typedef class _HexAstBinaryExpr : public _HexAstExpr {
public:
  _HexAstBinaryExpr(HexAstExpr lexpr, HexAstExpr rexpr);

  virtual bool reprOK();

  HexAstExpr left();
  HexAstExpr right();

  //virtual bool equals(void*);
  //virtual bool isomorphic(void*);
  //virtual bool equivalent(void*);

  template<typename T>
  static T* create(HexAstExpr, HexAstExpr);

protected:
  boost::scoped_ptr<_HexAstExpr> _lexpr;
  boost::scoped_ptr<_HexAstExpr> _rexpr;

private:
  //bool examine(Examiner, void*);

} * HexAstBinaryExpr;

template<typename T>
T*
_HexAstBinaryExpr::create(
  HexAstExpr l,
  HexAstExpr r
)
{
  T* obj = new T(l,r);
  return obj;
}

#endif /* _HEX_AST_BINARY_EXPR_H_ */
