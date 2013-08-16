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

#ifndef _AST_CONDITIONAL_CLAUSE_H_
#define _AST_CONDITIONAL_CLAUSE_H_

enum HexAstConditionalPreposition {
  AST_CONDITIONAL_PREPOSITION_BEFORE=0x02,
  AST_CONDITIONAL_PREPOSITION_AFTER=0x04,
  AST_CONDITIONAL_PREPOSITION_WHEN=0x08
};

typedef class _HexAstConditionalClause : public _HexAstNode {
public:
  _HexAstConditionalClause(
    HexAstConditionalPreposition, HexAstExprList, HexAstTaskState);

  virtual bool reprOK();
private:
  HexAstConditionalPreposition _preposition;
  HexAstExprList _exprs;
  HexAstTaskState _state;
} * HexAstConditionalClause;

#endif /* _AST_CONDITIONAL_CLAUSE_H_ */
