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

#include "../../base/assert.h"

#ifndef _AST_FACTORY_H_
#define _AST_FACTORY_H_

template<class T>
class AstFactory {
public:
  // template<typename T1>
  // static T create1(T1 arg1) {
  //   T *obj = new T(arg1);
  //   HEX_ASSERT(obj);
  //   return obj;
  // }

  // template<typename T1, typename T2>
  // static T create2(T1 arg1, T2 arg2) {
  //   T *obj = new T(arg1, arg2);
  //   HEX_ASSERT(obj);
  //   return obj;
  // }

  // template<typename T1, typename T2, typename T3>
  // static T create3(T1 arg1, T2 arg2, T3 arg3) {
  //   T *obj = new T(arg1, arg2, arg3);
  //   HEX_ASSERT(obj);
  //   return obj;
  // }

  // template<typename T1, typename T2, typename T3, typename T4>
  // static T create4(T1 arg1, T2 arg2, T3 arg3, T4 arg4) {
  //   T *obj = new T(arg1, arg2, arg3, arg4);
  //   HEX_ASSERT(obj);
  //   return obj;
  // }

  template<typename... Args>
  static T* create(Args... args) {
    T *obj = new T(args...);
    HEX_ASSERT(obj);
    return obj;
  }

  // static T* create() {
  //   T *obj = new T();
  //   HEX_ASSERT(obj);
  //   return obj;
  // }
};

#endif /* _AST_FACTORY_H_ */