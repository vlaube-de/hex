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
#include "ast_compound_stmt.h"
#include "ast_expr.h"
#include "ast_expr_list.h"
#include "ast_stmt_group.h"
#include "ast_target_list.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_FOR_STMT_H_
#define _AST_FOR_STMT_H_

typedef class _HexAstForStmt : public _HexAstCompoundStmt {
public:
  _HexAstForStmt(
    HexAstTargetList targets,
    HexAstExprList sources,
    HexAstExpr predicate,
    HexAstStmtGroup stmts
  ):
    _targets(targets),
    _sources(sources),
    _predicate(predicate),
    _HexAstCompoundStmt(stmts)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->targets());
    ASSERT(this->sources());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstTargetList targets() { return this->_targets.get(); }
  HexAstExprList sources() { return this->_sources.get(); }
  HexAstExpr predicate() { return this->_predicate.get(); }

private:
  boost::scoped_ptr<_HexAstTargetList> _targets;
  boost::scoped_ptr<_HexAstExprList> _sources;
  boost::scoped_ptr<_HexAstExpr> _predicate;
} * HexAstForStmt;

#endif /* _AST_FOR_STMT_H_ */