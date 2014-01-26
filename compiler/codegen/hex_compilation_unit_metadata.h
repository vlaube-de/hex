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
 * A wrapper around a set of metadata for one compilation unit. 
 */

#include "../../base/c_str.h"
#include "../../base/dict.h"

#ifndef _HEX_COMPILATION_UNIT_METADATA_H_
#define _HEX_COMPILATION_UNIT_METADATA_H_

class HexCompilationUnitMetadata {
public:
  HexCompilationUnitMetadata();

  HexCompilationUnitMetadata(
    const c_str input_path,
    const c_str input_filename,
    const c_str input_encoding,
    const c_str input_checksum,
    const c_str time_compiled_at
  );
  ~HexCompilationUnitMetadata();

  const c_str input_path();
  const c_str input_filename();
  const c_str input_encoding();
  const c_str input_checksum();
  const c_str time_compiled_at();

protected:
  Dict _dict;

  void init();
};

#endif /* _HEX_COMPILATION_UNIT_METADATA_H_ */