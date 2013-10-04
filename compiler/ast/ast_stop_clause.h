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
#include "ast_task_clause.h"
#include "ast_expr_list.h"
#include "ast_conditional_clause.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_STOP_CLAUSE_H_
#define _AST_STOP_CLAUSE_H_

typedef class _HexAstStopClause : public _HexAstTaskClause {
public:
  _HexAstStopClause(HexAstExprList, HexAstConditionalClause);

  virtual bool reprOK();

  HexAstExprList exprs();
  HexAstConditionalClause condition();

  virtual void accept(AstVisitor* visitor);

  static _HexAstStopClause* create(HexAstExprList, HexAstConditionalClause);
private:
  boost::scoped_ptr<_HexAstExprList> _exprs;
  boost::scoped_ptr<_HexAstConditionalClause> _condition;
} * HexAstStopClause;

#endif /* _AST_STOP_CLAUSE_H_ */
