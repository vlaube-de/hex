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
#include "ast_conditional_clause.h"
#include "ast_expr_list.h"
#include "ast_node.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_TASK_CLAUSE_H_
#define _AST_TASK_CLAUSE_H_

typedef class _HexAstTaskClause : public _HexAstNode {
public:
  _HexAstTaskClause(
    HexAstExprList tasks,
    HexAstConditionalClause condition_clause
  ):
    _tasks(tasks),
    _condition_clause(condition_clause)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->tasks());
  }

  virtual void accept(AstVisitor*)=0;

  HexAstExprList tasks() { return this->_tasks.get(); }

  HexAstConditionalClause condition_clause() {
    return this->_condition_clause.get();
  }

protected:
  boost::scoped_ptr<_HexAstExprList> _tasks;
  boost::scoped_ptr<_HexAstConditionalClause> _condition_clause;
} * HexAstTaskClause;

#endif /* _AST_TASK_CLAUSE_H_ */
