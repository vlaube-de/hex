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
#include "ast_node.h"
#include "ast_val_atom.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_KEYWORD_VAL_H_
#define _AST_KEYWORD_VAL_H_

typedef class _HexAstKeywordVal : public _HexAstNode {
public:
  _HexAstKeywordVal(HexAstIdentifier, HexAstValAtom);

  virtual bool reprOK();

  HexAstIdentifier key();
  HexAstValAtom val();

  virtual void accept(AstVisitor*);

  static _HexAstKeywordVal* create(HexAstIdentifier, HexAstValAtom);
private:
  boost::scoped_ptr<_HexAstIdentifier> _key;
  boost::scoped_ptr<_HexAstValAtom> _val;
} * HexAstKeywordVal;

#endif /* _AST_KEYWORD_VAL_H_ */
