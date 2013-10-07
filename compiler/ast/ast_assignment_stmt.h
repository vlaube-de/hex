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
#include "ast_expr_list.h"
#include "ast_lambda.h"
#include "ast_decorator_list.h"
#include "ast_task_def.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_ASSIGNMENT_STMT_H_
#define _AST_ASSIGNMENT_STMT_H_

typedef class _HexAstAssignmentStmt : public _HexAstSimpleStmt {
public:
  _HexAstAssignmentStmt(HexAstPrimary, bool);

  virtual void reprOK();

  virtual HexAstPrimary target();
  virtual bool defer();

protected:
  boost::scoped_ptr<_HexAstPrimary> _target;
  bool _defer;
} * HexAstAssignmentStmt;

typedef class _HexAstExprListAssignmentStmt : public _HexAstAssignmentStmt {
public:
  _HexAstExprListAssignmentStmt(HexAstPrimary, HexAstExprList, bool);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstExprList src();

  static _HexAstExprListAssignmentStmt* create(
    HexAstPrimary,
    HexAstExprList,
    bool
  );

private:
  boost::scoped_ptr<_HexAstExprList> _src;
} * HexAstExprListAssignmentStmt;

typedef class _HexAstLambdaAssignmentStmt : public _HexAstAssignmentStmt {
public:
  _HexAstLambdaAssignmentStmt(
    HexAstDecoratorList,
    HexAstPrimary,
    HexAstLambda,
    bool
  );

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstDecoratorList decorators();
  HexAstLambda src();

  static _HexAstLambdaAssignmentStmt* create(
    HexAstDecoratorList,
    HexAstPrimary,
    HexAstLambda,
    bool
  );

private:
  boost::scoped_ptr<_HexAstDecoratorList> _decorators;
  boost::scoped_ptr<_HexAstLambda> _src;
} * HexAstLambdaAssignmentStmt;

typedef class _HexAstTaskDefAssignmentStmt : public _HexAstAssignmentStmt {
public:
  _HexAstTaskDefAssignmentStmt(
    HexAstPrimary,
    HexAstTaskDef,
    bool
  );

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstTaskDef src();

  static _HexAstTaskDefAssignmentStmt* create(
    HexAstPrimary,
    HexAstTaskDef,
    bool
  );

protected:
  boost::scoped_ptr<_HexAstTaskDef> _src;
} * HexAstTaskDefAssignmentStmt;

#endif /* _AST_ASSIGNMENT_STMT_H_ */
