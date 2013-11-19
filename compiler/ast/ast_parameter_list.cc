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
#include "../visitor/ast_visitor.h"
#include "../../base/assert.h"

_HexAstParameterList::_HexAstParameterList(
  HexAstSimpleParamList simple_params,
  HexAstKeywordParamList keyword_params,
  HexAstIdentifier args,
  HexAstIdentifier kwargs
):_simple_params(simple_params), _keyword_params(keyword_params), _args(args), _kwargs(kwargs)
{
  this->reprOK();
}

void
_HexAstParameterList::reprOK()
{
  // Do nothing here.
}

HexAstSimpleParamList
_HexAstParameterList::simple_params()
{
  return this->_simple_params.get();
}

HexAstKeywordParamList
_HexAstParameterList::keyword_params()
{
  return this->_keyword_params.get();
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
  HexAstKeywordParamList keyword_params,
  HexAstIdentifier args,
  HexAstIdentifier kwargs
)
{
  HexAstParameterList obj = new _HexAstParameterList(
    simple_params,
    keyword_params,
    args,
    kwargs
  );

  HEX_ASSERT(obj);

  return obj;
}
