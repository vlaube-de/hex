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

#include <boost/smart_ptr.hpp>
#include "ast_primary.h"
#include "ast_key_value_pair_list.h"
#include "ast_comprehension_list.h"
#include "ast_expr_precedence.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_DICT_FORM_H_
#define _AST_DICT_FORM_H_

typedef class _HexAstDictForm : public _HexAstPrimary {
public:
  _HexAstDictForm();
} * HexAstDictForm;

typedef class _HexAstExplicitDictForm : public _HexAstDictForm {
public:
  _HexAstExplicitDictForm(HexAstKeyValuePairList);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstKeyValuePairList fields(); 

  static _HexAstExplicitDictForm* create(HexAstKeyValuePairList);
private:
  boost::scoped_ptr<_HexAstKeyValuePairList> _fields;
} * HexAstExplicitDictForm;

typedef class _HexAstImplicitDictForm : public _HexAstDictForm {
public:
  _HexAstImplicitDictForm(HexAstComprehensionList);    

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstComprehensionList comprehensions();

  static _HexAstImplicitDictForm* create(HexAstComprehensionList);
private:
  boost::scoped_ptr<_HexAstComprehensionList> _comprehensions;
} * HexAstImplicitDictForm;

#endif /* _AST_DICT_FORM_H_ */
