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
#include "visitor/ast_visitor.h"

#ifndef _AST_DICT_FORM_H_
#define _AST_DICT_FORM_H_

enum {
  AST_DICT_FORM_EMPTY=0x01,
  AST_DICT_FORM_EXPLICIT=0x02,
  AST_DICT_FORM_COMPREHENSION=0x04
};

typedef class _HexAstDictForm : public AstTyped, public _HexAstPrimary {
public:
  _HexAstDictForm(void*, ast_type_t);

  virtual bool reprOK();

  void* core();

  virtual void accept(AstVisitor*);

  static _HexAstDictForm* create(void*, ast_type_t);
private:
  void* _core;
} * HexAstDictForm;

#endif /* _AST_DICT_FORM_H_ */
