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

#include "ast_arg_list.h"
#include "ast_val_list.h"
#include "ast_identifier.h"
#include "ast_keyword_val_list.h"
#include "visitor/ast_visitor.h"
#include "../../base/assert.h"


_HexAstArgList::_HexAstArgList(
  HexAstValList valList,
  HexAstKeywordValList keywordValList,
  HexAstIdentifier args,
  HexAstIdentifier kwargs
):_valList(valList), _keywordValList(keywordValList), _args(args), _kwargs(kwargs)
{
  this->reprOK();
}

bool
_HexAstArgList::reprOK()
{
  HEX_ASSERT(
    this->_valList ||
    this->_keywordValList ||
    this->_args ||
    this->_kwargs
  );
}

void
_HexAstArgList::accept(AstVisitor* visitor)
{
  visitor->visit(this);
}

HexAstArgList
_HexAstArgList::create(
  HexAstValList vallist,
  HexAstKeywordValList keywordValList,
  HexAstIdentifier args,
  HexAstIdentifier kwargs
)
{
  HexAstArgList obj = new _HexAstArgList(
    vallist,
    keywordValList,
    args,
    kwargs
  );

  HEX_ASSERT(obj);

  return obj;
}
