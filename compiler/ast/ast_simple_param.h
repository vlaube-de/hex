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
#include "ast_node.h"
#include "ast_name.h"
#include "ast_identifier.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_SIMPLE_PARAM_H_
#define _AST_SIMPLE_PARAM_H_

typedef class _HexAstSimpleParam : public _HexAstNode {
public:
  _HexAstSimpleParam(HexAstIdentifier, HexAstName);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  HexAstIdentifier name();
  HexAstName type();

  static _HexAstSimpleParam* create(HexAstIdentifier, HexAstName);
private:
  boost::scoped_ptr<_HexAstIdentifier> _name;
  boost::scoped_ptr<_HexAstName> _type;
} * HexAstSimpleParam;

#endif /* _AST_SIMPLE_PARAM_H_ */
