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

#include "ast_primary.h"
#include "ast_typed.h"

#ifndef _AST_LIST_FORM_H_
#define _AST_LIST_FORM_H_

enum {
  AST_LIST_FORM_EMPTY=0x01,
  AST_LIST_FORM_EXPR_LIST=0x02,
  AST_LIST_FORM_COMPREHENSION=0x04
};

typedef class _HexAstListForm : public AstTyped, public _HexAstPrimary {
public:
  _HexAstListForm(void*, ast_type_t);

  virtual bool reprOK();

  static _HexAstListForm* create(void*, ast_type_t);
private:
  void* _core;
} * HexAstListForm;

#endif /* _AST_LIST_FORM_H_ */
