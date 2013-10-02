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


#include "ast_expr.h"
#include "ast_range_expr.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_IN_RANGE_EXPR_H_
#define _AST_IN_RANGE_EXPR_H_

typedef class _HexAstInclusiveRangeExpr : public _HexAstRangeExpr {
public:
  _HexAstInclusiveRangeExpr(HexAstExpr, HexAstExpr);

  virtual bool reprOK();

  HexAstExpr begin();
  HexAstExpr end();

  virtual void accept(AstVisitor*);

  static _HexAstInclusiveRangeExpr* create(HexAstExpr, HexAstExpr);
private:
  HexAstExpr _begin;
  HexAstExpr _end;
} * HexAstInclusiveRangeExpr;


#endif /* _AST_IN_RANGE_EXPR_H_ */