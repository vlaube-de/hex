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
#include "../../base/uuid.h"
#include "../../base/hash.h"
#include "../../base/assert.h"
#include "../../base/utils.h"
#include "../vtable.h"


class VtableTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _vtable = vtable_create();
  }

  virtual void TearDown() {
    vtable_free(&_vtable);
  }

  Vtable _vtable;
};


TEST_F(VtableTest, VtableCreationTest) {
  HEX_ASSERT(_vtable);
  ASSERT_EQ(0, vtable_size(_vtable));
  ASSERT_LE(0, vtable_capacity(_vtable));
}

TEST_F(VtableTest, vtable_putTest1) {
  char module_name[] = "hex.compiler.vtable";
  char name[] = "obj";
  hex_scope_type_t scope_type = HEX_VAR_SCOPE_TYPE_LOCAL;
  hash_t parent_id = uuid_create_and_hash();
  hex_type_t type = 1;
  hex_type_qualifier_t type_qualifier = HEX_TYPE_QUALIFIER_CONST;
  unsigned int indent_level = 1;

  VtableEntry actual_entry = (VtableEntry)vtable_put(
    _vtable,
    parent_id,
    module_name,
    name,
    scope_type,type,
    type_qualifier,
    indent_level
  );

  HEX_ASSERT(actual_entry);

  ASSERT_STREQ(actual_entry->module_name, module_name);
  ASSERT_STREQ(actual_entry->name, name);
  ASSERT_EQ(actual_entry->parent_id, parent_id);
  ASSERT_EQ(actual_entry->scope_type, scope_type);
  ASSERT_EQ(actual_entry->type, type);
  ASSERT_EQ(actual_entry->type_qualifier, type_qualifier);
  ASSERT_EQ(actual_entry->indent_level, indent_level);

  char *mingled_name = vtable_mingle_name(actual_entry);
  ASSERT_STREQ(mingled_name, actual_entry->mingled_name);

  VtableEntry expected_entry=NULL;

  expected_entry = vtable_lookup_by_parent_id(
    _vtable,
    parent_id,
    name
  );

  HEX_ASSERT(expected_entry);

  ASSERT_EQ(1, vtable_compare(actual_entry, expected_entry));

  expected_entry = vtable_lookup_by_id(
    _vtable,
    actual_entry->id
  );

  HEX_ASSERT(expected_entry);

  ASSERT_EQ(1, vtable_compare(actual_entry, expected_entry));
}

TEST_F(VtableTest, vtable_putTest2) {
  /*
   * Test that two variables of same name in different modules
   * and with different scope gives two different VtableEntry.
   */
  char module_name1[] = "hex.compiler.vtable";
  char module_name2[] = "hex.compiler.ftable";
  char name1[] = "myobj";
  char name2[] = "myobj";
  hash_t parent_id1 = uuid_create_and_hash();
  hash_t parent_id2 = uuid_create_and_hash();
  hex_scope_type_t scope_type_1 = HEX_VAR_SCOPE_TYPE_LOCAL;
  hex_scope_type_t scope_type_2 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_type_t type_1 = 0x01;
  hex_type_t type_2 = 0x01;
  hex_type_qualifier_t type_qualifier_1 = 0x0;
  hex_type_qualifier_t type_qualifier_2 = 0x0;
  unsigned int indent_level_1 = 0x02;
  unsigned int indent_level_2 = 0x01;

  VtableEntry actual_entry_1 = (VtableEntry)vtable_put(
    _vtable,
    parent_id1,
    module_name1,
    name1,
    scope_type_1,
    type_1,
    type_qualifier_1,
    indent_level_1
  );

  VtableEntry actual_entry_2 = (VtableEntry)vtable_put(
    _vtable,
    parent_id2,
    module_name2,
    name2,
    scope_type_2,
    type_2,
    type_qualifier_2,
    indent_level_2
  );

  HEX_ASSERT(actual_entry_1);
  HEX_ASSERT(actual_entry_2);

  ASSERT_STREQ(module_name1, actual_entry_1->module_name);
  ASSERT_STREQ(name1, actual_entry_1->name);
  ASSERT_EQ(parent_id1, actual_entry_1->parent_id);
  ASSERT_EQ(scope_type_1, actual_entry_1->scope_type);
  ASSERT_EQ(type_1, actual_entry_1->type);
  ASSERT_EQ(type_qualifier_1, actual_entry_1->type_qualifier);
  ASSERT_EQ(indent_level_1, actual_entry_1->indent_level);

  ASSERT_STREQ(module_name2, actual_entry_2->module_name);
  ASSERT_STREQ(name2, actual_entry_2->name);
  ASSERT_EQ(parent_id2, actual_entry_2->parent_id);
  ASSERT_EQ(scope_type_2, actual_entry_2->scope_type);
  ASSERT_EQ(type_2, actual_entry_2->type);
  ASSERT_EQ(type_qualifier_2, actual_entry_2->type_qualifier);
  ASSERT_EQ(indent_level_2, actual_entry_2->indent_level);

  VtableEntry expected_entry_1 = vtable_lookup(
    _vtable,
    module_name1,
    name1,
    indent_level_1
  );

  VtableEntry expected_entry_2 = vtable_lookup(
    _vtable,
    module_name2,
    name2,
    indent_level_2
  );

  ASSERT_EQ(1, vtable_compare(actual_entry_1, expected_entry_1));
  ASSERT_EQ(1, vtable_compare(actual_entry_2, expected_entry_2));
  ASSERT_EQ(0, vtable_compare(actual_entry_1, actual_entry_2));
  ASSERT_EQ(0, vtable_compare(expected_entry_1, expected_entry_2));
}

TEST_F(VtableTest, vtable_putTest3) {
  /*
   * Test that two variables of different name and with
   * different scope in the same module gives two different VtableEntry.
   */
  char module_name1[] = "hex.compiler.vtable";
  char module_name2[] = "hex.compiler.vtable";
  char name1[] = "myobj1";
  char name2[] = "myobj2";
  hash_t parent_id1 = uuid_create_and_hash();
  hash_t parent_id2 = uuid_create_and_hash();
  hex_scope_type_t scope_type_1 = HEX_VAR_SCOPE_TYPE_LOCAL;
  hex_scope_type_t scope_type_2 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_type_t type_1 = 0x01;
  hex_type_t type_2 = 0x01;
  hex_type_qualifier_t type_qualifier_1 = 0x0;
  hex_type_qualifier_t type_qualifier_2 = 0x0;
  unsigned int indent_level_1 = 0x02;
  unsigned int indent_level_2 = 0x01;

  VtableEntry actual_entry_1 = (VtableEntry)vtable_put(
    _vtable,
    parent_id1,
    module_name1,
    name1,
    scope_type_1,
    type_1,
    type_qualifier_1,
    indent_level_1
  );

  VtableEntry actual_entry_2 = (VtableEntry)vtable_put(
    _vtable,
    parent_id2,
    module_name2,
    name2,
    scope_type_2,
    type_2,
    type_qualifier_2,
    indent_level_2
  );

  HEX_ASSERT(actual_entry_1);
  HEX_ASSERT(actual_entry_2);

  ASSERT_STREQ(module_name1, actual_entry_1->module_name);
  ASSERT_STREQ(name1, actual_entry_1->name);
  ASSERT_EQ(parent_id1, actual_entry_1->parent_id);
  ASSERT_EQ(scope_type_1, actual_entry_1->scope_type);
  ASSERT_EQ(type_1, actual_entry_1->type);
  ASSERT_EQ(type_qualifier_1, actual_entry_1->type_qualifier);
  ASSERT_EQ(indent_level_1, actual_entry_1->indent_level);

  ASSERT_STREQ(module_name2, actual_entry_2->module_name);
  ASSERT_STREQ(name2, actual_entry_2->name);
  ASSERT_EQ(parent_id2, actual_entry_2->parent_id);
  ASSERT_EQ(scope_type_2, actual_entry_2->scope_type);
  ASSERT_EQ(type_2, actual_entry_2->type);
  ASSERT_EQ(type_qualifier_2, actual_entry_2->type_qualifier);
  ASSERT_EQ(indent_level_2, actual_entry_2->indent_level);

  VtableEntry expected_entry_1 = vtable_lookup(
    _vtable,
    module_name1,
    name1,
    indent_level_1
  );

  VtableEntry expected_entry_2 = vtable_lookup(
    _vtable,
    module_name2,
    name2,
    indent_level_2
  );

  ASSERT_EQ(1, vtable_compare(actual_entry_1, expected_entry_1));
  ASSERT_EQ(1, vtable_compare(actual_entry_2, expected_entry_2));
  ASSERT_EQ(0, vtable_compare(actual_entry_1, actual_entry_2));
  ASSERT_EQ(0, vtable_compare(expected_entry_1, expected_entry_2));
}

TEST_F(VtableTest, vtable_putTest4) {
  /*
   * Test that two variables of same name and with
   * same scope in the same module gives the same VtableEntry.
   */
  char module_name1[] = "hex.compiler.vtable";
  char module_name2[] = "hex.compiler.vtable";
  char name1[] = "myobj";
  char name2[] = "myobj";
  hex_uuid_t parent_id;
  uuid_create(&parent_id);
  hash_t parent_id1 = uuid_to_hash(parent_id);
  hash_t parent_id2 = uuid_to_hash(parent_id);
  hex_scope_type_t scope_type_1 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_scope_type_t scope_type_2 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_type_t type_1 = 0x01;
  hex_type_t type_2 = 0x01;
  hex_type_qualifier_t type_qualifier_1 = 0x0;
  hex_type_qualifier_t type_qualifier_2 = 0x0;
  unsigned int indent_level_1 = 0x01;
  unsigned int indent_level_2 = 0x01;

  VtableEntry actual_entry_1 = (VtableEntry)vtable_put(
    _vtable,
    parent_id1,
    module_name1,
    name1,
    scope_type_1,
    type_1,
    type_qualifier_1,
    indent_level_1
  );

  VtableEntry actual_entry_2 = (VtableEntry)vtable_put(
    _vtable,
    parent_id2,
    module_name2,
    name2,
    scope_type_2,
    type_2,
    type_qualifier_2,
    indent_level_2
  );

  HEX_ASSERT(actual_entry_1);
  HEX_ASSERT(actual_entry_2);

  ASSERT_STREQ(module_name1, actual_entry_1->module_name);
  ASSERT_STREQ(name1, actual_entry_1->name);
  ASSERT_EQ(parent_id1, actual_entry_1->parent_id);
  ASSERT_EQ(scope_type_1, actual_entry_1->scope_type);
  ASSERT_EQ(type_1, actual_entry_1->type);
  ASSERT_EQ(type_qualifier_1, actual_entry_1->type_qualifier);
  ASSERT_EQ(indent_level_1, actual_entry_1->indent_level);

  ASSERT_STREQ(module_name2, actual_entry_2->module_name);
  ASSERT_STREQ(name2, actual_entry_2->name);
  ASSERT_EQ(parent_id2, actual_entry_2->parent_id);
  ASSERT_EQ(scope_type_2, actual_entry_2->scope_type);
  ASSERT_EQ(type_2, actual_entry_2->type);
  ASSERT_EQ(type_qualifier_2, actual_entry_2->type_qualifier);
  ASSERT_EQ(indent_level_2, actual_entry_2->indent_level);

  VtableEntry expected_entry_1 = vtable_lookup(
    _vtable,
    module_name1,
    name1,
    indent_level_1
  );

  VtableEntry expected_entry_2 = vtable_lookup(
    _vtable,
    module_name2,
    name2,
    indent_level_2
  );

  ASSERT_EQ(1, vtable_compare(actual_entry_1, expected_entry_1));
  ASSERT_EQ(1, vtable_compare(actual_entry_2, expected_entry_2));
  ASSERT_EQ(1, vtable_compare(actual_entry_1, actual_entry_2));
  ASSERT_EQ(1, vtable_compare(expected_entry_1, expected_entry_2));
}

TEST_F(VtableTest, vtable_lookupTest) {
  /*
   * Test that vtable_lookup works.
   */
  char module_name[] = "hex.compiler.vtable";
  char name[] = "obj";
  hash_t parent_id = uuid_create_and_hash();
  hex_scope_type_t scope_type = HEX_VAR_SCOPE_TYPE_LOCAL;
  hex_type_t type = 1;
  hex_type_qualifier_t type_qualifier = HEX_TYPE_QUALIFIER_CONST;
  unsigned int indent_level = 1;

  VtableEntry actual_entry = (VtableEntry)vtable_put(
    _vtable,
    parent_id,
    module_name,
    name,
    scope_type,
    type,
    type_qualifier,
    indent_level
  );

  HEX_ASSERT(actual_entry);
  HEX_ASSERT(actual_entry->id);

  VtableEntry expected_entry = (VtableEntry)vtable_lookup(
    _vtable,
    module_name,
    name,
    indent_level
  ); 
 
  HEX_ASSERT(expected_entry);
  HEX_ASSERT(expected_entry->id);

  ASSERT_EQ(actual_entry, expected_entry);
  ASSERT_EQ(actual_entry->id, expected_entry->id);
  ASSERT_EQ(actual_entry->parent_id, expected_entry->parent_id);

  ASSERT_STREQ(module_name, expected_entry->module_name);
  ASSERT_STREQ(name, expected_entry->name);
  ASSERT_EQ(scope_type, expected_entry->scope_type);
  ASSERT_EQ(type, expected_entry->type);
  ASSERT_EQ(type_qualifier, expected_entry->type_qualifier);
  ASSERT_EQ(indent_level, expected_entry->indent_level);

  ASSERT_STREQ(actual_entry->mingled_name, expected_entry->mingled_name);
}
