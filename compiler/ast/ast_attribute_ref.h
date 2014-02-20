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

#include <boost/scoped_ptr.hpp>
#include "ast_identifier.h"
#include "ast_reference.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_ATTRIBUTE_REF_H_
#define _AST_ATTRIBUTE_REF_H_

typedef class _HexAstAttributeRef : public _HexAstReference {
public:
  _HexAstAttributeRef(HexAstPrimary source, HexAstIdentifier attribute):
  	_source(source),
  	_attribute(attribute),
  	_HexAstReference(
    	EXPR_ASSOCIATIVITY_LEFT,
    	EXPR_PRECEDENCE_PRIMARY_2
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->source());
    ASSERT(this->attribute());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstPrimary source() {
    return this->_source.get();
  }

  HexAstIdentifier attribute() {
    return this->_attribute.get();
  }

private:
  boost::scoped_ptr<_HexAstPrimary> _source;
  boost::scoped_ptr<_HexAstIdentifier> _attribute;
} * HexAstAttributeRef;

#endif /* _AST_ATTRIBUTE_REF_H_ */