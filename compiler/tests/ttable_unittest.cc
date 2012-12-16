/*
 * HEX Programming Language
 * Copyright (C) 2012  Yanzheng Li
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

#include "../../base/unittest.h"
#include "../../base/assert.h"
#include "../../base/memory.h"
#include "../../base/utils.h"
#include "../ast.h"
#include "../vtable.h"
#include "../ftable.h"
#include "../ttable.h"


class TtableTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _ttable = ttable_create();
    HEX_ASSERT(_ttable);
  }

  virtual void TearDown() {
    ttable_free(&_ttable);
    HEX_ASSERT(_ttable == NULL);
  }

  Ttable _ttable;
};


TEST_F(TtableTest, TtableCreationTest) {
  HEX_ASSERT(_ttable);
  ASSERT_EQ(0, ttable_size(_ttable));
  ASSERT_LE(0, ttable_capacity(_ttable));
}

TEST_F(TtableTest, ttable_putTest1) {
  char module_name[] = "hex.compiler.ttable";
  char type_name[] = "MyObject";
  
  TtableEntry expected_entry = (TtableEntry)ttable_put(
    _ttable,
    module_name,
    type_name
  );

  HEX_ASSERT(expected_entry);

  TtableEntry actual_entry = (TtableEntry)ttable_lookup(
    _ttable,
    module_name,
    type_name
  );

  HEX_ASSERT(actual_entry);

  ASSERT_EQ(expected_entry, actual_entry);
  ASSERT_TRUE(ttable_compare_entry_by_id(expected_entry, actual_entry));
}

TEST_F(TtableTest, ttable_putTest2) {
  char module_name[] = "hex.compiler.ttable";
  char type_name[] = "YourObject";

  TtableEntry entry1 = (TtableEntry)ttable_put(_ttable, module_name, type_name);

  HEX_ASSERT(entry1);

  TtableEntry entry2 = (TtableEntry)ttable_put(_ttable, module_name, type_name);

  HEX_ASSERT(entry2);

  ASSERT_EQ(entry1, entry2);
}

TEST_F(TtableTest, ttable_lookup_memberTest1) {
  char module_name[] = "hex.compiler.ttable";
  char type_name[] = "OurObject";

  TtableEntry entry = (TtableEntry)ttable_put(
    _ttable,
    module_name,
    type_name
  );

  HEX_ASSERT(entry);

  char member_name[] = "some_random_name";
  hex_type_t type = 0x01;
  hex_type_qualifier_t type_qualifier = HEX_TYPE_QUALIFIER_CONST;

  VtableEntry actual_member = (VtableEntry)ttable_put_member(
    _ttable,
    module_name,
    type_name,
    member_name,
    type,
    type_qualifier
  );

  HEX_ASSERT(actual_member);

  ASSERT_STREQ(member_name, actual_member->name);
  ASSERT_EQ(HEX_VAR_SCOPE_TYPE_MEMBER, actual_member->scope_type);
  ASSERT_EQ(type, actual_member->type);
  ASSERT_EQ(type_qualifier, actual_member->type_qualifier);

  VtableEntry expected_member = (VtableEntry)ttable_lookup_member(
    _ttable,
    module_name,
    type_name,
    member_name
  );

  HEX_ASSERT(expected_member);

  ASSERT_EQ(expected_member->id, actual_member->id);
}

TEST_F(TtableTest, ttable_put_methodTest1) {
  char module_name[] = "hex.compiler.ttable";
  char type_name[] = "OurObject";
  
  TtableEntry entry = (TtableEntry)ttable_put(_ttable, module_name, type_name);

  HEX_ASSERT(entry);

  char method_name[] = "do_something";
  hex_type_t return_type = 0x01;
  ParameterList paramlist = NULL; 

  FtableEntry actual_member = (FtableEntry)ttable_put_method(
    _ttable,
    module_name,
    type_name,
    method_name,
    return_type,
    paramlist
  );

  HEX_ASSERT(actual_member);

  ASSERT_STREQ(method_name, actual_member->name);
  ASSERT_EQ(return_type, actual_member->return_type);
  ASSERT_EQ(paramlist, actual_member->paramlist);

  FtableEntry expected_member = (FtableEntry)ttable_lookup_method(
    _ttable,
    module_name,
    type_name,
    method_name,
    paramlist
  );

  HEX_ASSERT(expected_member);

  ASSERT_EQ(expected_member->id, actual_member->id);
}
