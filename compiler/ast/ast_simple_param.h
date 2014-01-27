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
#include "ast_name.h"
#include "ast_node.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_SIMPLE_PARAM_H_
#define _AST_SIMPLE_PARAM_H_

typedef class _HexAstSimpleParam : public _HexAstNode {
public:
  _HexAstSimpleParam(HexAstName type, HexAstIdentifier name):
    _type(type),
    _name(name)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->name());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstName type() { return this->_type.get(); }
  HexAstIdentifier name() { return this->_name.get(); }

private:
  boost::scoped_ptr<_HexAstName> _type;
  boost::scoped_ptr<_HexAstIdentifier> _name;
} * HexAstSimpleParam;

#endif /* _AST_SIMPLE_PARAM_H_ */