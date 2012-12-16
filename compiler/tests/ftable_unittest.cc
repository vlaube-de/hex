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

#include "../../base/memory.h"
#include "../../base/unittest.h"
#include "../../base/assert.h"
#include "../../base/uuid.h"
#include "../../base/utils.h"
#include "../ast.h"
#include "../ftable.h"
#include "../testing/factories/paramlist_factory.h"

using ::testing::factory::ParamlistFactory;

class FtableTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _ftable = ftable_create();
    _paramlistFactory = new ParamlistFactory();
  }

  virtual void TearDown() {
    ftable_free(&_ftable);
    delete _paramlistFactory;
  }

  Ftable _ftable;
  ParamlistFactory *_paramlistFactory;
};


TEST_F(FtableTest, FtableCreationTest) {
  HEX_ASSERT(_ftable);
  ASSERT_EQ(0, ftable_size(_ftable));
  ASSERT_LE(0, ftable_capacity(_ftable));
}

TEST_F(FtableTest, ftable_putTest1) {
  /*
   * Test that ftable_put works.
   */
  char module_name[] = "hex.compiler.ftable";
  char name[] = "do_something";
  hash_t parent_id = uuid_create_and_hash();
  hex_type_t return_type = 1;
  ParameterList paramlist = (ParameterList)_paramlistFactory->create();

  FtableEntry actual_entry = ftable_put(
    _ftable,
    parent_id,
    module_name,
    name,
    return_type,
    paramlist
  );

  HEX_ASSERT(actual_entry);
  HEX_ASSERT(actual_entry->id);

  ASSERT_STREQ(module_name, actual_entry->module_name);
  ASSERT_STREQ(name, actual_entry->name);
  ASSERT_EQ(parent_id, actual_entry->parent_id);
  ASSERT_EQ(return_type, actual_entry->return_type);
  ASSERT_EQ(paramlist, actual_entry->paramlist);

  char *mingled_name = ftable_mingle_name(actual_entry);
  ASSERT_STREQ(mingled_name, actual_entry->mingled_name);

  ASSERT_EQ(1, ftable_size(_ftable));

  FtableEntry expected_entry = (FtableEntry)ftable_lookup(
    _ftable,
    module_name,
    name,
    paramlist
  );

  HEX_ASSERT(expected_entry);

  ASSERT_TRUE(ftable_compare(actual_entry, expected_entry));

  HEX_FREE(mingled_name);
}

TEST_F(FtableTest, ftable_putTest2) {
  /*
   * Test that two functions of different name and return type
   * in the same module gives two different FtableEntry.
   */
  char module_name1[] = "hex.compiler.ftable";
  char module_name2[] = "hex.compiler.ftable";
  char name1[] = "doSomething";
  char name2[] = "doNothing";
  hash_t parent_id = uuid_create_and_hash();
  hex_type_t return_type1 = 1;
  hex_type_t return_type2 = 2;
  ParameterList paramlist1 = NULL;
  ParameterList paramlist2 = NULL;

  FtableEntry actual_entry_1 = ftable_put(
    _ftable,
    parent_id,
    module_name1,
    name1,
    return_type1,
    paramlist1
  );

  FtableEntry actual_entry_2 = ftable_put(
    _ftable,
    parent_id,
    module_name2,
    name2,
    return_type2,
    paramlist2
  );

  HEX_ASSERT(actual_entry_1);
  HEX_ASSERT(actual_entry_2);

  ASSERT_STREQ(name1, actual_entry_1->name);
  ASSERT_EQ(return_type1, actual_entry_1->return_type);
  ASSERT_EQ(paramlist1, actual_entry_1->paramlist);

  ASSERT_STREQ(name2, actual_entry_2->name);
  ASSERT_EQ(return_type2, actual_entry_2->return_type);
  ASSERT_EQ(paramlist2, actual_entry_2->paramlist);

  ASSERT_FALSE(ftable_compare(actual_entry_1, actual_entry_2));
}

TEST_F(FtableTest, ftable_putTest3) {
  /*
   * Test that two functions with same name, return type
   * but with different parameter in the same module
   * gives two different FtableEntry. */
  char module_name1[] = "hex.compiler.ftable";
  char module_name2[] = "hex.compiler.ftable";
  char name1[] = "factorial";
  char name2[] = "factorial";
  hash_t parent_id = uuid_create_and_hash();
  hex_type_t return_type1 = 1;
  hex_type_t return_type2 = 1;
  ParameterList paramlist1 = NULL;
  ParameterList paramlist2 = HEX_MALLOC(struct HexParameterList);

  HEX_ASSERT(paramlist2);

  Parameter param = HEX_MALLOC(struct HexParameter);
  HEX_ASSERT(param);

  param->parameter_name = (char*)"myobj";
  param->type_specifier = 1;

  paramlist2->parameter = param;
  paramlist2->next = NULL;

  FtableEntry actual_entry_1 = ftable_put(
    _ftable,
    parent_id,
    module_name1,
    name1,
    return_type1,
    paramlist1
  );

  FtableEntry actual_entry_2 = ftable_put(
    _ftable,
    parent_id,
    module_name2,
    name2,
    return_type2,
    paramlist2
  );

  HEX_ASSERT(actual_entry_1);
  HEX_ASSERT(actual_entry_2);

  ASSERT_STREQ(name1, actual_entry_1->name);
  ASSERT_EQ(return_type1, actual_entry_1->return_type);
  ASSERT_EQ(paramlist1, actual_entry_1->paramlist);

  ASSERT_STREQ(name2, actual_entry_2->name);
  ASSERT_EQ(return_type2, actual_entry_2->return_type);
  ASSERT_EQ(paramlist2, actual_entry_2->paramlist);

  FtableEntry expected_entry_1 = ftable_lookup_by_id(
    _ftable,
    actual_entry_1->id
  );

  FtableEntry expected_entry_2 = ftable_lookup_by_id(
    _ftable,
    actual_entry_2->id
  );

  HEX_ASSERT(expected_entry_1);
  HEX_ASSERT(expected_entry_2);

  ASSERT_FALSE(ftable_compare(actual_entry_1, actual_entry_2));
  ASSERT_FALSE(ftable_compare(expected_entry_1, expected_entry_2));
  ASSERT_TRUE(ftable_compare(actual_entry_1, expected_entry_1));
  ASSERT_TRUE(ftable_compare(actual_entry_2, expected_entry_2));
}

TEST_F(FtableTest, ftable_putTest4) {
  /*
   * Test that two functions of same name, return type but
   * different parameter in different modules givens two different
   * FtableEntry.
   */
  char module_name1[] = "hex.compiler.vtable";
  char module_name2[] = "hex.compiler.ftable";
  char name1[] = "factorial";
  char name2[] = "factorial";
  hash_t parent_id1 = uuid_create_and_hash();
  hash_t parent_id2 = uuid_create_and_hash();
  hex_type_t return_type1 = 1;
  hex_type_t return_type2 = 1;
  ParameterList paramlist1 = HEX_MALLOC(struct HexParameterList);
  ParameterList paramlist2 = HEX_MALLOC(struct HexParameterList);

  HEX_ASSERT(paramlist1);
  HEX_ASSERT(paramlist2);

  Parameter param1 = HEX_MALLOC(struct HexParameter);
  HEX_ASSERT(param1);
  param1->parameter_name = (char*)"myobj";
  param1->type_specifier = 1;

  Parameter param2 = HEX_MALLOC(struct HexParameter);
  HEX_ASSERT(param2);
  param2->parameter_name = (char*)"yourobj";
  param2->type_specifier = param1->type_specifier;

  paramlist1->parameter = param1;
  paramlist1->next = NULL;

  paramlist2->parameter = param2;
  paramlist2->next = NULL;

  FtableEntry actual_entry_1 = ftable_put(
    _ftable,
    parent_id1,
    module_name1,
    name1,
    return_type1,
    paramlist1
  );

  FtableEntry actual_entry_2 = ftable_put(
    _ftable,
    parent_id2,
    module_name2,
    name2,
    return_type2,
    paramlist2
  );

  HEX_ASSERT(actual_entry_1);
  HEX_ASSERT(actual_entry_2);

  ASSERT_STREQ(name1, actual_entry_1->name);
  ASSERT_EQ(return_type1, actual_entry_1->return_type);
  ASSERT_EQ(paramlist1, actual_entry_1->paramlist);

  ASSERT_STREQ(name2, actual_entry_2->name);
  ASSERT_EQ(return_type2, actual_entry_2->return_type);
  ASSERT_EQ(paramlist2, actual_entry_2->paramlist);

  FtableEntry expected_entry_1 = ftable_lookup_by_id(
    _ftable,
    actual_entry_1->id
  );

  FtableEntry expected_entry_2 = ftable_lookup_by_id(
    _ftable,
    actual_entry_2->id
  );

  HEX_ASSERT(expected_entry_1);
  HEX_ASSERT(expected_entry_2);

  ASSERT_FALSE(ftable_compare(actual_entry_1, actual_entry_2));
  ASSERT_FALSE(ftable_compare(expected_entry_1, expected_entry_2));
  ASSERT_TRUE(ftable_compare(actual_entry_1, expected_entry_1));
  ASSERT_TRUE(ftable_compare(actual_entry_2, expected_entry_2));
}

TEST_F(FtableTest, ftable_lookup_by_nameTest) {
  /*
   * Test that lookup by name works for existing entry
   * and not for non-existing entries.
   */
  char module_name[] = "hex.compiler.ftable";
  char name[] = "calculate_mass_of_sun";
  hash_t parent_id = uuid_create_and_hash();

  FtableEntry actual_entry = ftable_put(
    _ftable,
    parent_id,
    module_name,
    name,
    0x0,
    NULL
  );

  HEX_ASSERT(actual_entry);
  HEX_ASSERT(actual_entry->id);

  ASSERT_STREQ(module_name, actual_entry->module_name);
  ASSERT_STREQ(name, actual_entry->name);

  FtableEntry expected_entry = ftable_lookup_by_name(
    _ftable,
    module_name,
    name
  );

  HEX_ASSERT(expected_entry);
  HEX_ASSERT(expected_entry->id);

  ASSERT_TRUE(ftable_compare(actual_entry, expected_entry));

  FtableEntry unexpected_entry = ftable_lookup_by_name(
    _ftable,
    module_name,
    generate_text(10, 12) 
  );

  HEX_ASSERT(unexpected_entry == NULL);
}

TEST_F(FtableTest, ftable_lookup_by_parent_idTest) {
  /*
   * Test that lookup by parent id works for existing entry
   * and not for non-existing entries. */
  char module_name[] = "hex.compiler.ftable";
  char name[] = "calculate_mass_of_sun";
  hash_t parent_id = uuid_create_and_hash();
  hex_type_t return_type = 0x01;
  ParameterList paramlist = NULL;

  FtableEntry actual_entry = ftable_put(
    _ftable,
    parent_id,
    module_name,
    name,
    return_type,
    paramlist
  );

  HEX_ASSERT(actual_entry);

  ASSERT_STREQ(module_name, actual_entry->module_name);
  ASSERT_STREQ(name, actual_entry->name);

  FtableEntry expected_entry = ftable_lookup_by_parent_id(
    _ftable,
    parent_id,
    name
  );

  HEX_ASSERT(expected_entry);

  ASSERT_TRUE(ftable_compare(actual_entry, expected_entry));

  /* Look up with an invalid parent id */
  FtableEntry unexpected_entry_1 = ftable_lookup_by_parent_id(
    _ftable,
    uuid_create_and_hash(),
    name
  );

  HEX_ASSERT(unexpected_entry_1 == NULL);

  /* Look up with an invalid entry name */
  FtableEntry unexpected_entry_2 = ftable_lookup_by_parent_id(
    _ftable,
    parent_id,
    generate_text(10, 12)
  );

  HEX_ASSERT(unexpected_entry_2 == NULL);
}
