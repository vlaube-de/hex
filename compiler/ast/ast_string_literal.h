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

#include "ast_literal.h"
#include "ast_unparsed.h"
#include "../visitor/ast_visitor.h"
#include "../../base/c_str.h"
#include "../../base/assert.h"

#ifndef _AST_STRING_LITERAL_H_
#define _AST_STRING_LITERAL_H_

typedef class _HexAstStringLiteral : public _HexAstLiteral {
public:
  _HexAstStringLiteral(c_str);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  template<typename T>
  static T* create(c_str);

} * HexAstStringLiteral;

template<typename T>
T*
_HexAstStringLiteral::create(c_str value)
{
  T* obj = new T(value);
  HEX_ASSERT(obj);
  return obj;
}

typedef class _HexAstSingleQuoteStringLiteral : public _HexAstStringLiteral {
public:
  _HexAstSingleQuoteStringLiteral(c_str);
} * HexAstSingleQuoteStringLiteral;

typedef class _HexAstDoubleQuoteStringLiteral : public _HexAstStringLiteral {
public:
  _HexAstDoubleQuoteStringLiteral(c_str);
} * HexAstDoubleQuoteStringLiteral;

#endif /* _AST_STRING_LITERAL_H_ */
