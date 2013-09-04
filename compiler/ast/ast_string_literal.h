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
#include "ast_typed.h"
#include "visitor/ast_visitor.h"
#include "../../base/c_str.h"

#ifndef _AST_STRING_LITERAL_H_
#define _AST_STRING_LITERAL_H_

enum {
  AST_STRING_LITERAL_SINGLE_QUOTE=0x01,
  AST_STRING_LITERAL_DOUBLE_QUOTE=0x02
};

typedef class _HexAstStringLiteral : public _HexAstLiteral, AstTyped, AstUnparsed {
public:
  _HexAstStringLiteral(ast_type_t, c_str);

  virtual bool reprOK();

  virtual c_str value();

  virtual void accept(AstVisitor*);

  static _HexAstStringLiteral* create(ast_type_t, c_str);
} * HexAstStringLiteral;

#endif /* _AST_STRING_LITERAL_H_ */
