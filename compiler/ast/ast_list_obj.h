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
#include <boost/smart_ptr.hpp>
#include <sneaker/libc/assert.h>

#ifndef _AST_LIST_OBJ_
#define _AST_LIST_OBJ_

template<typename C, typename T>
class AstListObj {
public:
  AstListObj();

  virtual void reprOK();
  virtual bool append(T);
  virtual bool push_front(T);

  std::list<T>* list();

  static C* create(T);
  static C* create(T, T);
  static C* extend(C*, T);
protected:
  boost::scoped_ptr< std::list<T> > _list;
};

template<typename C, typename T>
AstListObj<C, T>::AstListObj():
  _list(new std::list<T>())
{
  ASSERT(this->list());
}

template<typename C, typename T>
void
AstListObj<C, T>::reprOK()
{
  ASSERT(this->list());
}

template<typename C, typename T>
bool
AstListObj<C, T>::append(T obj)
{
  ASSERT(obj);

  this->_list->push_back(obj);

  return true;
}

template<typename C, typename T>
bool
AstListObj<C, T>::push_front(T obj)
{
  ASSERT(obj);

  this->_list->push_front(obj);

  return true;
}

template<typename C, typename T>
std::list<T>*
AstListObj<C, T>::list()
{
  return this->_list.get();
}

template<typename C, typename T>
C*
AstListObj<C, T>::create(T child)
{
  ASSERT(child);

  C* obj = new C();
  ASSERT(obj);

  obj->append(child);

  return obj;
}

template<typename C, typename T>
C*
AstListObj<C, T>::create(T child1, T child2)
{
  ASSERT(child1);
  ASSERT(child2);

  C* obj = new C();
  ASSERT(obj);

  obj->append(child1);
  obj->append(child2);

  return obj;
}

template<typename C, typename T>
C*
AstListObj<C, T>::extend(C* listobj, T element)
{
  ASSERT(listobj);
  ASSERT(element);

  listobj->append(element);

  return listobj;
}

#endif /* _AST_LIST_OBJ_ */