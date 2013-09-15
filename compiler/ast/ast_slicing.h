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


#include "ast_primary.h"
#include "ast_expr.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_SLICING_H_
#define _AST_SLICING_H_

typedef class _HexAstSlicing : public _HexAstPrimary {
public:
  _HexAstSlicing(HexAstPrimary, HexAstExpr);

  virtual bool reprOK();

  HexAstPrimary source();
  HexAstExpr slice();

  virtual void accept(AstVisitor*);

  static _HexAstSlicing* create(HexAstPrimary, HexAstExpr);
private:
  HexAstPrimary _source;
  HexAstExpr _slice;
} * HexAstSlicing;

#endif /* _AST_SLICING_H_ */
