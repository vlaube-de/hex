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
#include <sneaker/libc/assert.h>
#include "ast_arg_list.h"
#include "ast_name.h"
#include "ast_node.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_DECORATOR_H_
#define _AST_DECORATOR_H_

typedef class _HexAstDecorator : public _HexAstNode {
public:
  _HexAstDecorator(HexAstName name, HexAstArgList args):
    _name(name),
    _args(args)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->name());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstName name() { return this->_name.get(); }
  HexAstArgList args() { return this->_args.get(); }

private:
  boost::scoped_ptr<_HexAstName> _name;
  boost::scoped_ptr<_HexAstArgList> _args;
} * HexAstDecorator;

#endif /* _AST_DECORATOR_H_ */