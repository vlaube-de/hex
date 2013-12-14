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
#include "ast_list_form.h"
#include "ast_expr_list.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_EXPLICIT_LIST_FORM_H_
#define _AST_EXPLICIT_LIST_FORM_H_

typedef class _HexAstExplicitListForm: public _HexAstListForm {
public:
  _HexAstExplicitListForm(HexAstExprList elements):
    _elements(elements)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExprList elements() { return this->_elements.get(); }

private:
  boost::scoped_ptr<_HexAstExprList> _elements;
} * HexAstExplicitListForm;

#endif /* _AST_EXPLICIT_LIST_FORM_H_ */