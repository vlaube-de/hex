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
#include "ast_compound_stmt.h"
#include "ast_name.h"
#include "ast_decorator_list.h"
#include "ast_attribute_def_list.h"
#include "ast_identifier.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_CLASS_DEF_H_
#define _AST_CLASS_DEF_H_

typedef class _HexAstClassDef : public _HexAstCompoundStmt {
public:
  _HexAstClassDef(
    HexAstDecoratorList,
    HexAstIdentifier,
    HexAstName,
    HexAstAttributeDefList
  );

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstDecoratorList decorators();
  HexAstIdentifier name();
  HexAstName parent();
  HexAstAttributeDefList attributes();

  static _HexAstClassDef* create(
    HexAstDecoratorList,
    HexAstIdentifier,
    HexAstName,
    HexAstAttributeDefList
  );

private:
  boost::scoped_ptr<_HexAstDecoratorList> _decorators;
  boost::scoped_ptr<_HexAstIdentifier> _name;
  boost::scoped_ptr<_HexAstName> _parent;
  boost::scoped_ptr<_HexAstAttributeDefList> _attributes;
} * HexAstClassDef;

#endif /* _AST_CLASS_DEF_H_ */
