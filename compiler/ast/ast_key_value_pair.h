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

#include <boost/smart_ptr.hpp>
#include "ast_expr.h"
#include "ast_val_atom.h"
#include "ast_node.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_KEY_VALUE_PAIR_H_
#define _AST_KEY_VALUE_PAIR_H_

typedef class _HexAstKeyValuePair : public _HexAstNode {
public:
  _HexAstKeyValuePair(HexAstExpr, HexAstValAtom);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstExpr key();
  HexAstValAtom value();

  static
  _HexAstKeyValuePair* create(HexAstExpr, HexAstValAtom);
private:
  boost::scoped_ptr<_HexAstExpr> _key;
  boost::scoped_ptr<_HexAstValAtom> _value;
} * HexAstKeyValuePair;

#endif /* _AST_KEY_VALUE_PAIR_H_ */
