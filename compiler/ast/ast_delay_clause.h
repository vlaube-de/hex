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

#include "ast_task_clause.h"
#include "ast_expr_list.h"
#include "ast_expr.h"
#include "ast_conditional_clause.h"

#ifndef _AST_DELAY_CLAUSE_H_
#define _AST_DELAY_CLAUSE_H_

typedef class _HexAstDelayClause : public _HexAstTaskClause {
} * HexAstDelayClause;


typedef class _HexAstConditionalDelayClause : public _HexAstDelayClause {
public:
  _HexAstConditionalDelayClause(HexAstExprList, HexAstConditionalClause);

  virtual bool reprOK();

  static _HexAstConditionalDelayClause* create(HexAstExprList, HexAstConditionalClause);
private:
  HexAstExprList _exprs;
  HexAstConditionalClause _condition;
} * HexAstConditionalDelayClause;

typedef class _HexAstFixedDelayClause : public _HexAstDelayClause {
public:
  _HexAstFixedDelayClause(HexAstExprList, HexAstExpr);

  virtual bool reprOK();

  static _HexAstFixedDelayClause* create(HexAstExprList, HexAstExpr);
private:
  HexAstExprList _exprs;
  HexAstExpr _delay;
} * HexAstFixedDelayClause;


#endif /* _AST_DELAY_CLAUSE_H_ */
