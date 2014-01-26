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

/* Represents one quadruple code instruction. */

#include "boost/tuple/tuple.hpp"
#include "../../base/c_str.h"

#ifndef _QUADRUPLE_INSTR_H_
#define _QUADRUPLE_INSTR_H_

typedef boost::tuple<const c_str, const c_str, const c_str, const c_str> quadruple_instr;

#endif /* _QUADRUPLE_INSTR_H_ */