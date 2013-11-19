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
#include "ast_val_list.h"
#include "ast_keyword_val_list.h"
#include "ast_node.h"
#include "ast_identifier.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_ARG_LIST_H_
#define _AST_ARG_LIST_H_

typedef class _HexAstArgList : public _HexAstNode {
public:
  _HexAstArgList(HexAstValList, HexAstKeywordValList, HexAstIdentifier, HexAstIdentifier);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstValList simple_args();
  HexAstKeywordValList keyword_args();
  HexAstIdentifier args();
  HexAstIdentifier kwargs();

  static _HexAstArgList* create(
    HexAstValList,
    HexAstKeywordValList,
    HexAstIdentifier,
    HexAstIdentifier
  );

private:
  boost::scoped_ptr<_HexAstValList> _valList;
  boost::scoped_ptr<_HexAstKeywordValList> _keywordValList;
  boost::scoped_ptr<_HexAstIdentifier> _args;
  boost::scoped_ptr<_HexAstIdentifier> _kwargs;
} * HexAstArgList;

#endif /* _AST_ARG_LIST_H_ */
