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
#include "ast_assignment_source.h"
#include "ast_reference.h"
#include "ast_simple_stmt.h"
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

#ifndef _AST_ASSIGNMENT_STMT_H_
#define _AST_ASSIGNMENT_STMT_H_

typedef class _HexAstAssignmentStmt : public _HexAstSimpleStmt {
public:
  _HexAstAssignmentStmt(
    HexAstReference target,
    HexAstAssignmentFeature feature,
    HexAstAssignmentSource source
  ):
    _target(target),
    _feature(feature),
    _source(source)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->target());
    HEX_ASSERT(this->feature());
    HEX_ASSERT(this->source());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  virtual HexAstReference target() { return this->_target.get(); }
  virtual HexAstAssignmentSource source() { return this->_source.get(); }
  virtual HexAstAssignmentFeature feature() { return this->_feature; }

protected:
  boost::scoped_ptr<_HexAstReference> _target;  
  boost::scoped_ptr<_HexAstAssignmentSource> _source;
  HexAstAssignmentFeature _feature;

} * HexAstAssignmentStmt;

#endif /* _AST_ASSIGNMENT_STMT_H_ */