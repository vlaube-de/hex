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
#include "quadruple_code_vector_generator.h"
#include "../../base/c_str.h"

#ifndef _HEX_OBJECT_BLOCK_GENERATOR_H_
#define _HEX_OBJECT_BLOCK_GENERATOR_H_

class HexObjectBlockGenerator {
public:
	HexObjectBlockGenerator(
    const c_str address,
    const c_str flags,
    const c_str scope_id,
    const c_str parent_scope_id,
    const c_str object_manager_id,
    QuadrupleCodeVectorGenerator * code_generator
  );

	~HexObjectBlockGenerator();

  const c_str to_string();

  const c_str address();
  const c_str flags();
  const c_str scope_id();
  const c_str parent_scope_id();
  const c_str object_manager_id();
  QuadrupleCodeVectorGenerator * code_generator();

protected:

  boost::scoped_ptr<char> _address;
  boost::scoped_ptr<char> _flags;
  boost::scoped_ptr<char> _scope_id;
  boost::scoped_ptr<char> _parent_scope_id;
  boost::scoped_ptr<char> _object_manager_id;
  boost::scoped_ptr<QuadrupleCodeVectorGenerator> _code_generator;
};

#endif /* _HEX_OBJECT_BLOCK_GENERATOR_H_ */