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
#include "visitor/ast_visitor.h"

#ifndef _AST_TASK_STATE_H_
#define _AST_TASK_STATE_H_

enum HexAstTaskStateEnum {
  AST_TASK_STATE_START=0x01,
  AST_TASK_STATE_PAUSE=0x02,
  AST_TASK_STATE_CANCEL=0x04,
  AST_TASK_STATE_RESUME=0x08,
  AST_TASK_STATE_FINISH=0x16,
  AST_TASK_STATE_STOP=0x32
};

typedef class _HexAstTaskState : public _HexAstNode {
public:
  _HexAstTaskState(HexAstTaskStateEnum);

  virtual bool reprOK();

  HexAstTaskStateEnum state();

  virtual void accept(AstVisitor*);

  static _HexAstTaskState* create(HexAstTaskStateEnum);
private:
  HexAstTaskStateEnum _state;
} * HexAstTaskState;


#endif /* _AST_TASK_STATE_H_ */
