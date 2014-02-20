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
#include "ast_primary.h"
#include "ast_arg_list.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_CALL_H_
#define _AST_CALL_H_

typedef class _HexAstCall : public _HexAstPrimary {
public:
  _HexAstCall(HexAstPrimary caller, HexAstArgList arglist):
    _caller(caller),
    _arglist(arglist),
    _HexAstPrimary(
      EXPR_ASSOCIATIVITY_LEFT,
      EXPR_PRECEDENCE_PRIMARY_2
    )
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->caller());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstPrimary caller() {
    return this->_caller.get();
  }

  HexAstArgList arglist() {
    return this->_arglist.get();
  }

  virtual HexAstExprPrecedence precedence() {
    return EXPR_PRECEDENCE_PRIMARY_2;
  }

private:
  boost::scoped_ptr<_HexAstPrimary> _caller;
  boost::scoped_ptr<_HexAstArgList> _arglist;
} * HexAstCall;

#endif /* _AST_CALL_H_ */