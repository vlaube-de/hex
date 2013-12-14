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
#include "ast_identifier.h"
#include "ast_keyword_param_list.h"
#include "ast_node.h"
#include "ast_simple_param_list.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_PARAMETER_LIST_H_
#define _AST_PARAMETER_LIST_H_

typedef class _HexAstParameterList : public _HexAstNode {
public:
  _HexAstParameterList(
    HexAstSimpleParamList simple_params,
    HexAstIdentifier args,
    HexAstKeywordParamList keyword_param,
    HexAstIdentifier kwargs
  ):
    _simple_params(simple_params),
    _args(args),
    _keyword_params(keyword_param),
    _kwargs(kwargs)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstSimpleParamList simple_params() { return this->_simple_params.get(); }
  HexAstIdentifier args() { return this->_args.get(); }
  HexAstKeywordParamList keyword_params() { return this->_keyword_params.get(); }
  HexAstIdentifier kwargs() { return this->_kwargs.get(); }

private:
  boost::scoped_ptr<_HexAstSimpleParamList> _simple_params;
  boost::scoped_ptr<_HexAstIdentifier> _args;
  boost::scoped_ptr<_HexAstKeywordParamList> _keyword_params;
  boost::scoped_ptr<_HexAstIdentifier> _kwargs;
} * HexAstParameterList;

#endif /* _AST_PARAMETER_LIST_H_ */