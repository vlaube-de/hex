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
#include "visitor/ast_visitor.h"

#ifndef _AST_USING_SRC_H_
#define _AST_USING_SRC_H_

typedef class _HexAstUsingSrc : public _HexAstNode {
public:
  _HexAstUsingSrc(size_t, HexAstName);

  virtual void reprOK();
  virtual void accept(AstVisitor*);

  size_t level();
  HexAstName name();

  static _HexAstUsingSrc* create(size_t, HexAstName);
private:
  size_t _level;
  boost::scoped_ptr<_HexAstName> _name;
} * HexAstUsingSrc;

#endif /* _AST_USING_SRC_H_ */
