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

/* Top level of Hex AST. */

#include <boost/smart_ptr.hpp>
#include "ast_node.h"
#include "ast_stmt_group.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_HEX_PROGRAM_H_
#define _AST_HEX_PROGRAM_H_

typedef class _HexAstHexProgram : public _HexAstNode {
public:
  _HexAstHexProgram(HexAstStmtGroup stmts):
    _stmts(stmts)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    // Do nothing here.
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }

  HexAstStmtGroup stmts() { return this->_stmts.get(); }

  static int get_parse_tree_root(_HexAstHexProgram**);
  static void clear();
  static _HexAstHexProgram* create(HexAstStmtGroup);

private:
  boost::scoped_ptr<_HexAstStmtGroup> _stmts;

  static void set_parse_tree_root(_HexAstHexProgram**);

} * HexAstHexProgram;

#endif /* _AST_HEX_PROGRAM_H_ */