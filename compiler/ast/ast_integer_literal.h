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
#include "ast_typed.h"
#include "../../base/c_str.h"

#ifndef _AST_INTEGER_LITERAL_H_
#define _AST_INTEGER_LITERAL_H_

enum {
  AST_INTEGER_LITERAL_DECIMAL=0x02,
  AST_INTEGER_LITERAL_BINARY=0x04,
  AST_INTEGER_LITERAL_OCTAL=0x08,
  AST_INTEGER_LITERAL_HEXADECIMAL=0x10
};

typedef class _HexAstIntegerLiteral : public _HexAstLiteral, AstTyped {
public:
  _HexAstIntegerLiteral(ast_type_t, c_str);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  static _HexAstIntegerLiteral* create(ast_type_t, c_str);
} * HexAstIntegerLiteral;


#endif /* _AST_INTEGER_LITERAL_H_ */
