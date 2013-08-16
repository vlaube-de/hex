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
#include "ast_list_obj.h"
#include "ast_attribute_def.h"

#ifndef _AST_ATTRIBUTE_DEF_LIST_H_
#define _AST_ATTRIBUTE_DEF_LIST_H_

typedef class _HexAstAttributeDefList : public AstListObj<HexAstAttributeDef>, _HexAstNode {
public:
  _HexAstAttributeDefList();
} * HexAstAttributeDefList;

#endif /* _AST_ATTRIBUTE_DEF_H_ */
