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
#include "ast_name.h"

#ifndef _AST_USING_SRC_H_
#define _AST_USING_SRC_H_

enum {
  AST_USING_SRC_NAME=0x0A,
  AST_USING_SRC_DOT=0x0F
};

typedef class _HexAstUsingSrc : public _HexAstNode {
public:
  _HexAstUsingSrc(HexAstName, char);

  virtual bool reprOK();
private:
  HexAstName _name;
  char _type;
} * HexAstUsingSrc;

#endif /* _AST_USING_SRC_H_ */
