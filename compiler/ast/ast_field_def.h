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
#include "ast_decorator_list.h"
#include "ast_identifier.h"
#include "ast_simple_arg.h"
#include "ast_node.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_FIELD_DEF_H_
#define _AST_FIELD_DEF_H_

typedef class _HexAstFieldDef : public _HexAstNode {
public:
  _HexAstFieldDef(
    HexAstDecoratorList decorators,
    HexAstIdentifier name,
    HexAstSimpleArg value
  ):
    _decorators(decorators),
    _name(name),
    _value(value)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->name());
    ASSERT(this->value());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstDecoratorList decorators() { return this->_decorators.get(); }
  HexAstIdentifier name() { return this->_name.get(); }
  HexAstSimpleArg value() { return this->_value.get(); }

private:
  boost::scoped_ptr<_HexAstDecoratorList> _decorators;
  boost::scoped_ptr<_HexAstIdentifier> _name;
  boost::scoped_ptr<_HexAstSimpleArg> _value;
} * HexAstFieldDef;

#endif /* _AST_FIELD_DEF_H_ */