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
#include "ast_simple_param_list.h"
#include "ast_keyword_val_list.h"
#include "ast_node.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_PARAMETER_LIST_H_
#define _AST_PARAMETER_LIST_H_

typedef class _HexAstParameterList : public _HexAstNode {
public:
  _HexAstParameterList(
    HexAstSimpleParamList,
    HexAstKeywordValList,
    HexAstIdentifier,
    HexAstIdentifier
  );

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstSimpleParamList simple_params();
  HexAstKeywordValList keyword_vals();
  HexAstIdentifier args();
  HexAstIdentifier kwargs();

  static _HexAstParameterList* create(
    HexAstSimpleParamList,
    HexAstKeywordValList,
    HexAstIdentifier,
    HexAstIdentifier
  );

private:
  boost::scoped_ptr<_HexAstSimpleParamList> _simple_params;
  boost::scoped_ptr<_HexAstKeywordValList> _keyword_vals;
  boost::scoped_ptr<_HexAstIdentifier> _args;
  boost::scoped_ptr<_HexAstIdentifier> _kwargs;
} * HexAstParameterList;

#endif /* _AST_PARAMETER_LIST_H_ */
