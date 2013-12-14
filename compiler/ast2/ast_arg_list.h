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
#include "ast_keyword_arg_list.h"
#include "ast_node.h"
#include "ast_simple_arg_list.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_ARG_LIST_H_
#define _AST_ARG_LIST_H_

typedef class _HexAstArgList : public _HexAstNode {
public:
  _HexAstArgList(
    HexAstSimpleArgList simple_args,
    HexAstIdentifier args,
    HexAstKeywordArgList keyword_args,
    HexAstIdentifier kwargs
  ):
    _simple_args(simple_args),
    _args(args),
    _keyword_args(keyword_args),
    _kwargs(kwargs)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(
      this->simple_args() ||
      this->args() ||
      this->keyword_args() ||
      this->kwargs()
    );
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstSimpleArgList simple_args() { return this->_simple_args.get(); }
  HexAstIdentifier args() { return this->_args.get(); }
  HexAstKeywordArgList keyword_args() { return this->_keyword_args.get(); }
  HexAstIdentifier kwargs() { return this->_kwargs.get(); }

private:
  boost::scoped_ptr<_HexAstSimpleArgList> _simple_args;
  boost::scoped_ptr<_HexAstIdentifier> _args;
  boost::scoped_ptr<_HexAstKeywordArgList> _keyword_args;
  boost::scoped_ptr<_HexAstIdentifier> _kwargs;
} * HexAstArgList;

#endif /* _AST_ARG_LIST_H_ */