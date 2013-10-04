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
#include "ast_simple_stmt.h"
#include "ast_primary.h"
#include "ast_decorator_list.h"
#include "ast_typed.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_ASSIGNMENT_STMT_H_
#define _AST_ASSIGNMENT_STMT_H_

enum {
  AST_ASSIGNMENT_STMT_EXPR_LIST=0x0A,
  AST_ASSIGNMENT_STMT_LAMBDA=0x0C,
  AST_ASSIGNMENT_STMT_TASK=0x0F
};

typedef class _HexAstAssignmentStmt : public AstTyped, public _HexAstSimpleStmt {
public:
  _HexAstAssignmentStmt(HexAstDecoratorList, HexAstPrimary, void*, ast_type_t, bool);

  virtual bool reprOK();

  HexAstDecoratorList decorators();
  HexAstPrimary dst();
  void* src();
  bool defer();

  virtual void accept(AstVisitor*);

  static _HexAstAssignmentStmt* create(
    HexAstDecoratorList,
    HexAstPrimary,
    void*,
    ast_type_t,
    bool
  );

private:
  boost::scoped_ptr<_HexAstDecoratorList> _decorators;
  boost::scoped_ptr<_HexAstPrimary> _dst;
  void* _src;
  bool _defer;
} * HexAstAssignmentStmt;

#endif /* _AST_ASSIGNMENT_STMT_H_ */
