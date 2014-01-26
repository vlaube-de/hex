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

#include <algorithm>
#include <string>
#include "quadruple_code_vector_generator.h"


QuadrupleCodeVectorGenerator::QuadrupleCodeVectorGenerator()
{
	// Do nothing.
}

QuadrupleCodeVectorGenerator::~QuadrupleCodeVectorGenerator()
{
  // Do nothing.
}

size_t
QuadrupleCodeVectorGenerator::size()
{
  return this->_vector.size();
}

void
QuadrupleCodeVectorGenerator::append(
  const c_str label,
  const c_str code,
  const c_str op1,
  const c_str op2
)
{
  this->_vector.push_back(quadruple_instr(label, code, op1, op2));
}

void
QuadrupleCodeVectorGenerator::iterate(QuadrupleInstrHandler* handler)
{
  // std::for_each(
  //   this->_vector.begin(),
  //   this->_vector.end(),
  //   *handler
  // );
  typename std::vector<quadruple_instr>::iterator itr;
  for(itr=this->_vector.begin(); itr != this->_vector.end(); itr++) {
    quadruple_instr instr = (quadruple_instr)(*itr);
    (*handler)(instr);
  }
}

// template<class Function>
// void
// QuadrupleCodeVectorGenerator::iterate(Function f)
// {
//   typename std::vector<quadruple_instr>::iterator itr;
//   for(itr=this->_vector.begin(); itr != this->_vector.end(); itr++) {
//     quadruple_instr instr = (quadruple_instr)(*itr);
//     f(instr);
//   }
// }

const c_str
QuadrupleCodeVectorGenerator::instr_to_str(quadruple_instr instr)
{
  std::string stringbuilder;

  const c_str label = instr.get<0>();
  const c_str code  = instr.get<1>();
  const c_str op1   = instr.get<2>();
  const c_str op2   = instr.get<3>();

  if(label) {
    stringbuilder.append(label);
    stringbuilder.append(": ");
  }

  if(code) {
    stringbuilder.append(code);
  }

  if(op1) {
    stringbuilder.append(" ");
    stringbuilder.append(op1);
  }

  if(op2) {
    stringbuilder.append(" ");
    stringbuilder.append(op2);
  }

  const c_str s = (const c_str)stringbuilder.c_str();

  return strdup(s);
}