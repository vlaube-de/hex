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
#include "ast_expr.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_CONDITIONAL_EXPR_H_
#define _AST_CONDITIONAL_EXPR_H_

typedef class _HexAstConditionalExpr : public _HexAstExpr {
public:
  _HexAstConditionalExpr(
    HexAstExpr predicate,
    HexAstExpr consequent,
    HexAstExpr alternate
  ):
    _predicate(predicate),
    _consequent(consequent),
    _alternate(alternate),
    _HexAstExpr(
      EXPR_ASSOCIATIVITY_RIGHT,
      EXPR_PRECEDENCE_CONDITIONAL_EXPR
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->predicate());
    HEX_ASSERT(this->consequent());
    HEX_ASSERT(this->alternate());

    HEX_ASSERT(this->predicate()->precedence() >= this->precedence());
    HEX_ASSERT(this->consequent()->precedence() >= this->precedence());
    HEX_ASSERT(this->alternate()->precedence() >= this->precedence());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstExpr predicate() { return this->_predicate.get(); }
  HexAstExpr consequent() { return this->_consequent.get(); }
  HexAstExpr alternate() { return this->_alternate.get(); }

private:
  boost::scoped_ptr<_HexAstExpr> _predicate;
  boost::scoped_ptr<_HexAstExpr> _consequent;
  boost::scoped_ptr<_HexAstExpr> _alternate;
} * HexAstConditionalExpr;

#endif /* _AST_CONDITIONAL_EXPR_H_ */