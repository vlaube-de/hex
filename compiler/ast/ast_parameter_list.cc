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

#include "ast_parameter_list.h"
#include "ast_simple_param_list.h"
#include "ast_keyword_val_list.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstParameterList::_HexAstParameterList(
  HexAstSimpleParamList simple_params,
  HexAstKeywordValList keyword_vals,
  HexAstIdentifier args,
  HexAstIdentifier kwargs
):_simple_params(simple_params), _keyword_vals(keyword_vals), _args(args), _kwargs(kwargs)
{
  this->reprOK();
}

bool
_HexAstParameterList::reprOK()
{
  return true;
}

HexAstSimpleParamList
_HexAstParameterList::simple_params()
{
  return this->_simple_params.get();
}

HexAstKeywordValList
_HexAstParameterList::keyword_vals()
{
  return this->_keyword_vals.get();
}

HexAstIdentifier
_HexAstParameterList::args()
{
  return this->_args.get();
}

HexAstIdentifier
_HexAstParameterList::kwargs()
{
  return this->_kwargs.get();
}

void
_HexAstParameterList::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstParameterList
_HexAstParameterList::create(
  HexAstSimpleParamList simple_params,
  HexAstKeywordValList keyword_vals,
  HexAstIdentifier args,
  HexAstIdentifier kwargs
)
{
  HexAstParameterList obj = new _HexAstParameterList(
    simple_params,
    keyword_vals,
    args,
    kwargs
  );

  HEX_ASSERT(obj);

  return obj;
}
