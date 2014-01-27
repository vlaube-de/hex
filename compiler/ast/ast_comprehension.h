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
#include "ast_expr_list.h"
#include "ast_node.h"
#include "ast_target_list.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_COMPREHENSION_H_
#define _AST_COMPREHENSION_H_

typedef class _HexAstComprehension : public _HexAstNode {
public:
  _HexAstComprehension(
    HexAstTargetList targets,
    HexAstExprList sources,
    HexAstExpr predicate
  ):
    _targets(targets),
    _sources(sources),
    _predicate(predicate)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->targets());
    HEX_ASSERT(this->sources());
  }

  virtual void accept(AstVisitor*)=0;

  HexAstTargetList targets() { return this->_targets.get(); }
  HexAstExprList sources() { return this->_sources.get(); }
  HexAstExpr predicate() { return this->_predicate.get(); }

protected:
  boost::scoped_ptr<_HexAstTargetList> _targets;
  boost::scoped_ptr<_HexAstExprList> _sources;
  boost::scoped_ptr<_HexAstExpr> _predicate;
} * HexAstComprehension;

#endif /* _AST_COMPREHENSION_H_ */