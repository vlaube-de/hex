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

/* Unit test for base/freader.cc */

#include <cstdio>
#include <fstream>
#include "../unittest.h"
#include "../freader.h"
#include "../assert.h"


class FileReaderUnitTest : public ::testing::Test {
protected:
  const c_str file_path = "./FileReaderUnitTest.txt";
  const c_str content = \
    "The quick brown fox jumped over the fence. All good"
    "things must come to an end. You can lead a horse to"
    "water but you can't make her drink.";

  virtual void SetUp() {
    std::ofstream f;
    f.open(file_path);
    f << content;
    f.close();
  }

  virtual void Teardown() {
    int res = remove(file_path);
    HEX_ASSERT(res == 0);
  }
};

TEST_F(FileReaderUnitTest, TestReadFile)
{
  FileReader reader(file_path);

  ASSERT_STREQ(file_path, reader.file_path());

  c_str actual_content = NULL;
  reader.read_file(&actual_content);

  ASSERT_STREQ(content, actual_content);
}
