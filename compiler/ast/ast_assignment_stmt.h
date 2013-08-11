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
#include "ast_primary.h"
#include "ast_decorator_list.h"

#ifndef _AST_ASSIGNMENT_STMT_H_
#define _AST_ASSIGNMENT_STMT_H_

enum {
  AST_ASSIGNMENT_STMT_EXPR_LIST=0x0A,
  AST_ASSIGNMENT_STMT_LAMBDA=0x0F
};

typedef class _HexAstAssignmentStmt : public _HexAstNode {
public:
  _HexAstAssignmentStmt(HexAstDecoratorList, HexAstPrimary, void*, char, bool);

  virtual bool reprOK();
private:
  HexAstDecoratorList _decorators;
  HexAstPrimary _dst;
  void* _src;
  char _type;
  bool _defer;
} * HexAstAssignmentStmt;

#endif /* _AST_ASSIGNMENT_STMT_H_ */
