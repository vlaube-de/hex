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
#include "ast_identifier.h"
#include "ast_task_clause.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_START_CLAUSE_H_
#define _AST_START_CLAUSE_H_

typedef class _HexAstStartClause : public _HexAstTaskClause {
public:
  _HexAstStartClause(
    HexAstExprList tasks,
    HexAstIdentifier alias,
    HexAstConditionalClause condition_clause
  ):
    _alias(alias),
    _HexAstTaskClause(tasks, condition_clause)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    _HexAstTaskClause::reprOK();
    HEX_ASSERT(this->alias());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstIdentifier alias() {
    return this->_alias.get();
  }

protected:
  boost::scoped_ptr<_HexAstIdentifier> _alias;
} * HexAstStartClause;

#endif /* _AST_START_CLAUSE_H_ */