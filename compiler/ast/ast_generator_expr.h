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
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_GENERATOR_EXPR_H_
#define _AST_GENERATOR_EXPR_H_

typedef class _HexAstGeneratorExpr : public _HexAstExpr {
public:
  _HexAstGeneratorExpr(HexAstComprehension comprehension):
    _comprehension(comprehension),
    _HexAstExpr(EXPR_ASSOCIATIVITY_LEFT, EXPR_PRECEDENCE_PRIMARY_1)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->comprehension());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstComprehension comprehension() { return this->_comprehension.get(); }

private:
  boost::scoped_ptr<_HexAstComprehension> _comprehension;
} * HexAstGeneratorExpr;

#endif /* _AST_GENERATOR_EXPR_H_ */