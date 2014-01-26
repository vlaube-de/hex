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

#include <vector>
#include "quadruple_instr.h"
#include "../../base/c_str.h"

#ifndef _QUADRUPLE_CODE_VECTOR_GENERATOR_H_
#define _QUADRUPLE_CODE_VECTOR_GENERATOR_H_

class QuadrupleInstrHandler {
public:
  virtual void operator()(quadruple_instr instr) = 0;
};

class QuadrupleCodeVectorGenerator {
public:
	QuadrupleCodeVectorGenerator();
	~QuadrupleCodeVectorGenerator();

  size_t size();

	void append(const c_str, const c_str, const c_str, const c_str);

  void iterate(QuadrupleInstrHandler*);

  // template<class Function>
  // void iterate(Function);

  static
  const c_str instr_to_str(quadruple_instr);

protected:
	std::vector<quadruple_instr> _vector;
};

#endif /* _QUADRUPLE_CODE_VECTOR_GENERATOR_H_ */