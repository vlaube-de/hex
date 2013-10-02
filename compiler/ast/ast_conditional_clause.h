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

#include "ast_node.h"
#include "ast_task_state.h"
#include "ast_expr_list.h"
#include "ast_conditional_preposition.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_CONDITIONAL_CLAUSE_H_
#define _AST_CONDITIONAL_CLAUSE_H_


typedef class _HexAstConditionalClause : public _HexAstNode {
public:
  _HexAstConditionalClause(
    HexAstConditionalPreposition, HexAstExprList, HexAstTaskState);

  virtual bool reprOK();

  HexAstConditionalPreposition preposition();
  HexAstExprList exprs();
  HexAstTaskState state();

  virtual void accept(AstVisitor*);

  static _HexAstConditionalClause* create(HexAstConditionalPreposition, HexAstExprList, HexAstTaskState);
private:
  HexAstConditionalPreposition _preposition;
  HexAstExprList _exprs;
  HexAstTaskState _state;
} * HexAstConditionalClause;

#endif /* _AST_CONDITIONAL_CLAUSE_H_ */