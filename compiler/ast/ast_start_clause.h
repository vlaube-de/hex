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
#include "ast_name.h"
#include "ast_target_list.h"
#include "ast_conditional_clause.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_START_CLAUSE_H_
#define _AST_START_CLAUSE_H_

typedef class _HexAstStartClause : public _HexAstTaskClause {
public:
  _HexAstStartClause(HexAstIdentifier, HexAstConditionalClause);

  virtual void reprOK();

  HexAstIdentifier alias();
  HexAstConditionalClause condition();

protected:
  boost::scoped_ptr<_HexAstIdentifier> _alias;
  boost::scoped_ptr<_HexAstConditionalClause> _condition;
} * HexAstStartClause;


typedef class _HexAstStartClauseSingle : public _HexAstStartClause {
public:
  _HexAstStartClauseSingle(HexAstName, HexAstIdentifier, HexAstConditionalClause);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstName target();

  static _HexAstStartClauseSingle* create(
    HexAstName,
    HexAstIdentifier,
    HexAstConditionalClause
  );

private:
  boost::scoped_ptr<_HexAstName> _target;
} * HexAstStartClauseSingle;


typedef class _HexAstStartClauseMultiple : public _HexAstStartClause {
public:
  _HexAstStartClauseMultiple(HexAstTargetList, HexAstIdentifier, HexAstConditionalClause);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstTargetList targets();

  static _HexAstStartClauseMultiple* create(
    HexAstTargetList,
    HexAstIdentifier,
    HexAstConditionalClause
  );

private:
  boost::scoped_ptr<_HexAstTargetList> _targets;
} * HexAstStartClauseMultiple;


#endif /* _AST_START_CLAUSE_H_ */
