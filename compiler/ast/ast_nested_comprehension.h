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
#include "ast_comprehension.h"
#include "ast_expr.h"
#include "ast_target_list.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_NESTED_COMPREHENSION_H_
#define _AST_NESTED_COMPREHENSION_H_

typedef class _HexAstNestedComprehension : public _HexAstComprehension {
public:
  _HexAstNestedComprehension(
    HexAstComprehension nested_comprehension,
    HexAstTargetList targets,
    HexAstExprList sources,
    HexAstExpr predicate
  ):
    _nested_comprehension(nested_comprehension),
    _HexAstComprehension(targets, sources, predicate)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    _HexAstComprehension::reprOK();
    ASSERT(this->nested_comprehension());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstComprehension nested_comprehension() {
    return this->_nested_comprehension.get();
  }

private:
  boost::scoped_ptr<_HexAstComprehension> _nested_comprehension;
} * HexAstNestedComprehension;

#endif /* _AST_NESTED_COMPREHENSION_H_ */