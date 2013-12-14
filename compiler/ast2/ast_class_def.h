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
#include "ast_compound_stmt.h"
#include "ast_decorator_list.h"
#include "ast_field_def_list.h"
#include "ast_identifier.h"
#include "ast_name.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_CLASS_DEF_H_
#define _AST_CLASS_DEF_H_

typedef class _HexAstClassDef : public _HexAstCompoundStmt {
public:
  _HexAstClassDef(
    HexAstDecoratorList decorators,
    HexAstIdentifier name,
    HexAstNameList parents,
    HexAstFieldDefList attributes
  ):
    _decorators(decorators),
    _name(name),
    _parents(parents),
    _attributes(attributes),
    _HexAstCompoundStmt(NULL)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->name());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstDecoratorList decorators() { return this->_decorators.get(); }
  HexAstIdentifier name() { return this->_name.get(); }
  HexAstNameList parents() { return this->_parents.get(); }
  HexAstFieldDefList attributes() { return this->_attributes.get(); }

private:
  boost::scoped_ptr<_HexAstDecoratorList> _decorators;
  boost::scoped_ptr<_HexAstIdentifier> _name;
  boost::scoped_ptr<_HexAstNameList> _parents;
  boost::scoped_ptr<_HexAstFieldDefList> _attributes;
} * HexAstClassDef;

#endif /* _AST_CLASS_DEF_H_ */