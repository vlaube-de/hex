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

_HexAstParameterList::_HexAstParameterList(
  HexAstSimpleParamList simple_params,
  HexAstKeywordValList keyword_vals,
  char *args,
  char *kwargs
):_simple_params(simple_params), _keyword_vals(keyword_vals), _args(args), _kwargs(kwargs)
{
  this->reprOK();
}

bool
_HexAstParameterList::reprOK()
{
  return true;
}
