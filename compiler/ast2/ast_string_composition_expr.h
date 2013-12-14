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
#include "ast_paren_form.h"
#include "ast_string_literal.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_STRING_COMPOSITION_EXPR_H_
#define _AST_STRING_COMPOSITION_EXPR_H_

typedef class _HexAstStringCompositionExpr : public _HexAstExpr {
public:
  _HexAstStringCompositionExpr(
    HexAstStringLiteral string, HexAstParenForm paren
  ):
    _string(string),
    _paren(paren),
    _HexAstExpr(
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_STRING_COMPOSITION
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->string());
    HEX_ASSERT(this->paren());

    HEX_ASSERT(this->precedence() < this->string()->precedence());
    HEX_ASSERT(this->precedence() < this->paren()->precedence());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstStringLiteral string() { return this->_string.get(); }
  HexAstParenForm paren() { return this->_paren.get(); }

private:
  boost::scoped_ptr<_HexAstStringLiteral> _string;
  boost::scoped_ptr<_HexAstParenForm> _paren;
} * HexAstStringCompositionExpr;

#endif /* _AST_STRING_COMPOSITION_EXPR_H_ */