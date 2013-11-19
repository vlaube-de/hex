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


/*
 * Base class for all AST nodes.
 */

#include "../visitor/ast_visitor.h"

#ifndef _AST_NODE_H_
#define _AST_NODE_H_


typedef class _HexAstNode {
public:
  _HexAstNode();

  /*
   * Symantic simplification for this instance.
   * Returns an instance that is equivalent
   * to this one.
   */
  // void* simplify();

  /*
   * Symantic standardization for this instance.
   * Returns an instance that is equivalent
   * to this one.
   */
  // void* standardize();

  /*
   * Representation invariance check.
   *
   * Should be used inside sub-classes's
   * constructors and public methods.
   */
  virtual void reprOK()=0;

  /* Visitor pattern. */
  virtual void accept(AstVisitor*)=0;

} * HexAstNode;

#endif /* _AST_NODE_H_ */
