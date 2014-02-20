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

#include "ast_binary_expr.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"

#ifndef _AST_ASSIGNMENT_EXPR_H_
#define _AST_ASSIGNMENT_EXPR_H_

class _HexAstAssignmentExpr : public _HexAstBinaryExpr {
public:
  _HexAstAssignmentExpr(
    HexAstExpr lexpr,
    HexAstExpr rexpr
  ):
    _HexAstBinaryExpr(
      lexpr,
      rexpr,
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_ASSIGNMENT
    )
  {
  }
};

#endif /* _AST_ASSIGNMENT_EXPR_H_ */