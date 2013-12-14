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

#include "ast_string_literal.h"
#include "../visitor/ast_visitor.h"
#include "../../base/c_str.h"

#ifndef _AST_DOUBLE_QUOTE_STRING_LITERAL_H_
#define _AST_DOUBLE_QUOTE_STRING_LITERAL_H_

typedef class _HexAstDoubleQuoteStringLiteral : public _HexAstStringLiteral {
public:
  _HexAstDoubleQuoteStringLiteral(c_str value):
  	_HexAstStringLiteral(value)
  {
  }

  virtual void accept(AstVisitor* visitor) {
  	visitor->visit(this);
  }
} * HexAstDoubleQuoteStringLiteral;

#endif /* _AST_DOUBLE_QUOTE_STRING_LITERAL_H_ */