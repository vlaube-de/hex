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
#include "ast_comprehension.h"
#include "ast_expr.h"
#include "ast_expr_list.h"
#include "ast_target_list.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_EXPR_COMPREHENSION_H_
#define _AST_EXPR_COMPREHENSION_H_

typedef class _HexAstExprComprehension : public _HexAstComprehension {
public:
  _HexAstExprComprehension(
    HexAstExprList exprs,
    HexAstTargetList targets,
    HexAstExprList sources,
    HexAstExpr predicate
  ):
    _exprs(exprs),
    _HexAstComprehension(targets, sources, predicate)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    _HexAstComprehension::reprOK();
    HEX_ASSERT(this->exprs());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExprList exprs() { return this->_exprs.get(); }

private:
  boost::scoped_ptr<_HexAstExprList> _exprs;
} * HexAstExprComprehension;

#endif /* _AST_EXPR_COMPREHENSION_H_ */