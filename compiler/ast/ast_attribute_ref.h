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


#include "ast_identifier.h"
#include "ast_primary.h"
#include "visitor/ast_visitor.h"

#ifndef _AST_ATTRIBUTE_REF_H_
#define _AST_ATTRIBUTE_REF_H_

typedef class _HexAstAttributeRef : public _HexAstPrimary {
public:
  _HexAstAttributeRef(HexAstPrimary, HexAstIdentifier);

  virtual bool reprOK();

  HexAstPrimary source();
  HexAstIdentifier attribute();

  virtual void accept(AstVisitor*);

  static _HexAstAttributeRef* create(HexAstPrimary, HexAstIdentifier);
private:
  HexAstPrimary _source;
  HexAstIdentifier _attribute;
} * HexAstAttributeRef;

#endif /* _AST_ATTRIBUTE_REF_H_ */