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
#include "../../base/c_str.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_IDENTIFIER_H_
#define _AST_IDENTIFIER_H_

typedef class _HexAstIdentifier : public _HexAstPrimary {
public:
  _HexAstIdentifier(c_str);

  virtual bool reprOK();

  static _HexAstIdentifier* create(c_str);

  c_str identifier();

  virtual void accept(AstVisitor*);

private:
  c_str _identifier;
} * HexAstIdentifier;

#endif /* _AST_IDENTIFIER_H_ */