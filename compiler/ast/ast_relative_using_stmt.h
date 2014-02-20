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
#include "ast_identifier.h"
#include "ast_target_list.h"
#include "ast_using_src.h"
#include "ast_using_stmt.h"
#include "../visitor/ast_visitor.h"


#ifndef _AST_RELATIVE_USING_STMT_H_
#define _AST_RELATIVE_USING_STMT_H_

typedef class _HexAstRelativeUsingStmt : public _HexAstUsingStmt {
public:
  _HexAstRelativeUsingStmt(
    HexAstTargetList targets,
    HexAstUsingSrc source,
    HexAstIdentifier alias
  ):
    _targets(targets),
    _source(source),
    _alias(alias)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    ASSERT(this->source());
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstTargetList targets() { return this->_targets.get(); }
  HexAstUsingSrc source() { return this->_source.get(); }
  HexAstIdentifier alias() { return this->_alias.get(); }

private:
  boost::scoped_ptr<_HexAstTargetList> _targets;
  boost::scoped_ptr<_HexAstUsingSrc> _source;
  boost::scoped_ptr<_HexAstIdentifier> _alias;
} * HexAstRelativeUsingStmt;

#endif /* _AST_RELATIVE_USING_STMT_H_ */