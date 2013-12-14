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

#include "ast_integer_literal.h"
#include "../visitor/ast_visitor.h"
#include "../../base/c_str.h"

#ifndef _AST_BINARY_INTEGER_LITERAL_H_
#define _AST_BINARY_INTEGER_LITERAL_H_

typedef class _HexAstBinaryIntegerLiteral : public _HexAstIntegerLiteral {
public:
  _HexAstBinaryIntegerLiteral(c_str value):
    _HexAstIntegerLiteral(value)
  {
  }

  virtual void accept(AstVisitor* visitor) {
  	visitor->visit(this);
  }
} * HexAstBinaryIntegerLiteral;

#endif /* _AST_BINARY_INTEGER_LITERAL_H_ */