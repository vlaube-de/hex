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

#include "hex_compilation_unit_metadata.h"
#include "../../base/assert.h"
#include "../../base/c_str.h"
#include "../../base/dict.h"

HexCompilationUnitMetadata::HexCompilationUnitMetadata()
{
  this->init();
}

HexCompilationUnitMetadata::HexCompilationUnitMetadata(
  const c_str input_path,
  const c_str input_filename,
  const c_str input_checksum,
  const c_str input_encoding,
  const c_str time_compiled_at
)
{
  this->init();
  dict_put(this->_dict, "input_path", input_path);
  dict_put(this->_dict, "input_filename", input_filename);
  dict_put(this->_dict, "input_checksum", input_checksum);
  dict_put(this->_dict, "input_encoding", input_encoding);
  dict_put(this->_dict, "time_compiled_at", time_compiled_at);
}

HexCompilationUnitMetadata::~HexCompilationUnitMetadata()
{
  dict_free(&this->_dict);
}

void
HexCompilationUnitMetadata::init()
{
  this->_dict = dict_create();
}

const c_str
HexCompilationUnitMetadata::input_path()
{
  return (const c_str)dict_get(this->_dict, "input_path");
}

const c_str
HexCompilationUnitMetadata::input_filename()
{
  return (const c_str)dict_get(this->_dict, "input_filename");
}

const c_str
HexCompilationUnitMetadata::input_checksum()
{
  return (const c_str)dict_get(this->_dict, "input_checksum");
}

const c_str
HexCompilationUnitMetadata::input_encoding()
{
  return (const c_str)dict_get(this->_dict, "input_encoding");
}

const c_str
HexCompilationUnitMetadata::time_compiled_at()
{
  return (const c_str)dict_get(this->_dict, "time_compiled_at");
}