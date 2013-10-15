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

/*
 * Generic AST node for HEX expressions
 */

#include "ast_val_atom.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"

#ifndef _AST_EXPR_H_
#define _AST_EXPR_H_

typedef class _HexAstExpr : public _HexAstValAtom {
public:
  _HexAstExpr(
    HexAstExprAssociativity associativity,
    HexAstExprPrecedence precedence
  ) : _associativity(associativity), _precedence(precedence) {}

  virtual HexAstExprAssociativity associativity() { return this->_associativity; }
  virtual HexAstExprPrecedence precedence() { return this->_precedence; }
protected:
  HexAstExprAssociativity _associativity;
  HexAstExprPrecedence _precedence;
} * HexAstExpr;

#endif /* _AST_EXPR_H_ */
