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

#include "examinable.h"
#include "../../base/uuid.h"

#ifndef _AST_NODE_H_
#define _AST_NODE_H_

// Forward declaration of AstVisitor.
class AstVisitor;

typedef class _HexAstNode : public Examinable {
public:
  _HexAstNode();

  /*
   * Symantic simplification for this instance.
   * Returns an instance that is equivalent
   * to this one.
   */
  void* simplify();

  /*
   * Symantic standardization for this instance.
   * Returns an instance that is equivalent
   * to this one.
   */
  void* standardize();

  /*
   * Representation invariant check.
   *
   * Should be used at the beginning and end of
   * public methods.
   *
   * Returns true if the instance is in a correct
   * representation.
   */
  virtual bool reprOK();

  virtual bool equal(void*);
  virtual bool isomorphic(void*);
  virtual bool equivalent(void*);

  /* Declare all AST nodes to be friend with AstVisitor
   * so that the visitor can access protected/private
   * members of AST nodes.
   */
  friend class AstVisitor;
protected:
  hex_uuid_t _id;
} * HexAstNode;

#endif /* _AST_NODE_H_ */
