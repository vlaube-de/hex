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
#include "ast_keyword_val.h"
#include "ast_list_obj.h"

#ifndef _AST_KEYWORD_VAL_LIST_H_
#define _AST_KEYWORD_VAL_LIST_H_

typedef class _HexAstKeywordValList : public AstListObj<_HexAstKeywordValList, HexAstKeywordVal>, _HexAstNode {
public:
  _HexAstKeywordValList();

  virtual bool reprOK();
} * HexAstKeywordValList;

#endif /* _AST_KEYWORD_VAL_LIST_H_ */
