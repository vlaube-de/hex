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
#include "ast_expr.h"
#include "ast_parameter_list.h"
#include "ast_simple_arg.h"
#include "ast_stmt_group.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_LAMBDA_H_
#define _AST_LAMBDA_H_

typedef class _HexAstLambda:
  public _HexAstSimpleArg, public _HexAstAssignmentSource
{
public:
  _HexAstLambda(HexAstParameterList params):
    _params(params)
  {
  }

  HexAstParameterList params() { return this->_params.get(); }

protected:
  boost::scoped_ptr<_HexAstParameterList> _params;
} * HexAstLambda;

#endif /* _AST_LAMBDA_H_ */