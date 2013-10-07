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
#include "../../base/c_str.h"
#include "../../base/assert.h"

#ifndef _AST_INTEGER_LITERAL_H_
#define _AST_INTEGER_LITERAL_H_

typedef class _HexAstIntegerLiteral : public _HexAstLiteral {
public:
  _HexAstIntegerLiteral(c_str);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  template<typename T>
  static T* create(c_str);

} * HexAstIntegerLiteral;

template<typename T>
T*
_HexAstIntegerLiteral::create(c_str value)
{
  T* obj = new T(value);
  HEX_ASSERT(obj);
  return obj;
}

typedef class _HexAstDecimalIntegerLiteral : public _HexAstIntegerLiteral {
public:
  _HexAstDecimalIntegerLiteral(c_str);
} * HexAstDecimalIntegerLiteral;

typedef class _HexAstBinaryIntegerLiteral : public _HexAstIntegerLiteral {
public:
  _HexAstBinaryIntegerLiteral(c_str);
} * HexAstBinaryIntegerLiteral;

typedef class _HexAstOctalIntegerLiteral : public _HexAstIntegerLiteral {
public:
  _HexAstOctalIntegerLiteral(c_str);
} * HexAstOctalIntegerLiteral;

typedef class _HexAstHexadecimalIntegerLiteral : public _HexAstIntegerLiteral {
public:
  _HexAstHexadecimalIntegerLiteral(c_str);
} * HexAstHexadecimalIntegerLiteral;

#endif /* _AST_INTEGER_LITERAL_H_ */
