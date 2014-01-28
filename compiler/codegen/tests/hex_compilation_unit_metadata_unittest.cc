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

/* Unit test for compiler/codegen/hex_compilation_unit_metadata.cc */

#include "../hex_compilation_unit_metadata.h"
#include "../../../base/c_str.h"
#include "../../../base/assert.h"
#include "../../../base/unittest.h"


class HexCompilationUnitMetadataUnitTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    this->_metadata = new HexCompilationUnitMetadata(
      this->input_path,
      this->input_filename,
      this->input_checksum,
      this->input_encoding,
      this->time_compiled_at
    );
  }

  virtual void TearDown() {
    delete this->_metadata;
  }

  const c_str input_path = "./hex/example.hex";
  const c_str input_filename = "example.hex";
  const c_str input_checksum = "a77df831641186a85a18f618ad3";
  const c_str input_encoding = "utf-8";
  const c_str time_compiled_at = "2014-01-01T01:01:01";

  HexCompilationUnitMetadata * _metadata;
};


TEST_F(HexCompilationUnitMetadataUnitTest, TestInitialization)
{
  HEX_ASSERT(this->_metadata);

  ASSERT_STREQ(this->input_path, this->_metadata->input_path());
  ASSERT_STREQ(this->input_filename, this->_metadata->input_filename());
  ASSERT_STREQ(this->input_checksum, this->_metadata->input_checksum());
  ASSERT_STREQ(this->input_encoding, this->_metadata->input_encoding());
  ASSERT_STREQ(this->time_compiled_at, this->_metadata->time_compiled_at());
}

TEST_F(HexCompilationUnitMetadataUnitTest, TestInitializationWithoutMetadata)
{
  HexCompilationUnitMetadata metadata;

  const c_str null = NULL;

  ASSERT_EQ(metadata.input_path(), null);
  ASSERT_EQ(metadata.input_filename(), null);
  ASSERT_EQ(metadata.input_checksum(), null);
  ASSERT_EQ(metadata.input_encoding(), null);
  ASSERT_EQ(metadata.time_compiled_at(), null);
}

TEST_F(HexCompilationUnitMetadataUnitTest, TestPutAndGetMetadata)
{
  const c_str null = NULL;

  const c_str input_file_size = "12345";
  const c_str host_os = "OS X v10.9.1";

  ASSERT_EQ(this->_metadata->get("input_file_size"), null);
  ASSERT_EQ(this->_metadata->get("host_os"), null);

  ASSERT_EQ(input_file_size, this->_metadata->put("input_file_size", input_file_size));
  ASSERT_EQ(host_os, this->_metadata->put("host_os", host_os));

  ASSERT_EQ(input_file_size, this->_metadata->get("input_file_size"));
  ASSERT_EQ(host_os, this->_metadata->get("host_os"));

  // Replace those values.
  const c_str input_file_size_2 = "67890";
  const c_str host_os_2 = "Linux Ubuntu 13.10";

  ASSERT_EQ(input_file_size_2, this->_metadata->put("input_file_size", input_file_size_2));
  ASSERT_EQ(host_os_2, this->_metadata->put("host_os", host_os_2));

  ASSERT_EQ(input_file_size_2, this->_metadata->get("input_file_size"));
  ASSERT_EQ(host_os_2, this->_metadata->get("host_os"));
}