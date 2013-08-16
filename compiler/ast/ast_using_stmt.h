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

#include "ast_using_src.h"
#include "ast_node.h"
#include "ast_target_list.h"
#include "ast_identifier.h"
#include "ast_name.h"

#ifndef _AST_USING_STMT_H_
#define _AST_USING_STMT_H_


typedef class _HexAstUsingStmt : public _HexAstNode {
} * HexAstUsingStmt;


typedef class _HexAstUsingStmtDirect : public _HexAstUsingStmt {
public:
  _HexAstUsingStmtDirect(HexAstName, HexAstIdentifier);

  virtual bool reprOK();
private:
  HexAstName _target;
  HexAstIdentifier _alias;
} * HexAstUsingStmtDirect;

enum {
  AST_USING_STMT_RELATIVE_TARGET=0x0A,
  AST_USING_STMT_RELATIVE_ALL=0x0F
};

typedef class _HexAstUsingStmtRelative : public _HexAstUsingStmt {
public:
  _HexAstUsingStmtRelative(HexAstTargetList, HexAstUsingSrc, HexAstIdentifier, char);

  virtual bool reprOK();
private:
  HexAstTargetList _target;
  HexAstUsingSrc _src;
  HexAstIdentifier _alias;
  char _type;
} * HexAstUsingStmtRelative;


#endif /* _AST_USING_STMT_H_ */
