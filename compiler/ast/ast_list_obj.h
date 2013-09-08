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

#include <list>
#include "../../base/assert.h"

#ifndef _AST_LIST_OBJ_
#define _AST_LIST_OBJ_

template<typename C, typename T>
class AstListObj {
public:
  AstListObj();

  virtual bool append(T);
  virtual bool push_front(T);

  std::list<T>* list();

  static C* create(T);
  static C* create(T, T);
  static C* expand(C*, T);
  static C* create_or_expand(T, C*);
protected:
  std::list<T> *_list;
};

template<typename C, typename T>
AstListObj<C, T>::AstListObj():
  _list(new std::list<T>())
{
  HEX_ASSERT(this->_list);
}

template<typename C, typename T>
bool
AstListObj<C, T>::append(T obj)
{
  HEX_ASSERT(obj);

  this->_list->push_back(obj);

  return true;
}

template<typename C, typename T>
bool
AstListObj<C, T>::push_front(T obj)
{
  HEX_ASSERT(obj);

  this->_list->push_front(obj);

  return true;
}

template<typename C, typename T>
std::list<T>*
AstListObj<C, T>::list()
{
  return this->_list;
}

template<typename C, typename T>
C*
AstListObj<C, T>::create(T child)
{
  HEX_ASSERT(child);

  C* obj = new C();
  HEX_ASSERT(obj);

  obj->append(child);

  return obj;
}

template<typename C, typename T>
C*
AstListObj<C, T>::create(T child1, T child2)
{
  HEX_ASSERT(child1);
  HEX_ASSERT(child2);

  C* obj = new C();
  HEX_ASSERT(obj);

  obj->append(child1);
  obj->append(child2);

  return obj;
}

template<typename C, typename T>
C*
AstListObj<C, T>::expand(C* list, T child)
{
  HEX_ASSERT(list);
  HEX_ASSERT(child);

  list->append(child);

  return list;
}

template<typename C, typename T>
C*
AstListObj<C, T>::create_or_expand(T child, C* list)
{
  HEX_ASSERT(child);

  if(list) {
    list->push_front(child);
    return list;
    // return AstListObj::expand(list, child);
  } else {
    return AstListObj::create(child);
  }
}

#endif /* _AST_LIST_OBJ_ */