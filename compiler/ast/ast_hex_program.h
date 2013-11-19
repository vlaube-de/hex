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

/* Top level of AST. */


#include <boost/smart_ptr.hpp>
#include "ast_stmt_group.h"
#include "ast_node.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_HEX_PROGRAM_H_
#define _AST_HEX_PROGRAM_H_

typedef class _HexAstHexProgram : public _HexAstNode {
public:
  _HexAstHexProgram(HexAstStmtGroup);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstStmtGroup stmts();

  static _HexAstHexProgram* create(HexAstStmtGroup);
  static int get_parse_tree_root(_HexAstHexProgram**);
  static void clear();
private:
  boost::scoped_ptr<_HexAstStmtGroup> _stmts;

  static void set_parse_tree_root(_HexAstHexProgram**);

} * HexAstHexProgram;


#endif /* _AST_HEX_PROGRAM_H_ */
