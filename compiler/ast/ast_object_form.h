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
#include "ast_attribute_value_pair_list.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_primary.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_OBJECT_FORM_H_
#define _AST_OBJECT_FORM_H_

typedef class _HexAstObjectForm : public _HexAstPrimary {
public:
  _HexAstObjectForm(HexAstAttributeValuePairList fields):
    _fields(fields),
    _HexAstPrimary(
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_PRIMARY_1
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->fields());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstAttributeValuePairList fields() { return this->_fields.get(); }
private:
  boost::scoped_ptr<_HexAstAttributeValuePairList> _fields;
} * HexAstObjectForm;

#endif /* _AST_OBJECT_FORM_H_ */