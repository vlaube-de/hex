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


/* An abstract class(interface) that represents an examinable object
 * that can be examined and compared with instances of the same type.
 */

#ifndef _EXAMINABLE_H_
#define _EXAMINABLE_H_

class Examinable {
public:
  /*
   * Compares two objects for equality based on their computation.
   *
   * Two objects are considered equal if any computation that uses
   * either one will produce idential results.
   */
  virtual bool equal(void*)=0;

  /*
   * Compares two objects for equality based on their elements.
   *
   * Two objects are considered isomorphic if they have the same
   * elements, perhaps arranged in a different order.
   *
   * Any objects that are equal are also isomorphic.
   */
  virtual bool isomorphic(void*)=0;

  /*
   * Compares two objects for equality based on their underlying
   * semantic meaning.
   *
   * Two objects are considered equivalent if they have the same
   * underlying semantic meaning or representation, but may have
   * superficial or syntactic differences.
   *
   * i.e. the boolean values 'true' and 'not false' are equivalent
   * because they both evaluate to true, but they are represented
   * differently here.
   *
   * Any objects that are isomorphic are also equivalent.
   */
  virtual bool equivalent(void*)=0;
};

#endif /* _EXAMINABLE_H_ */
