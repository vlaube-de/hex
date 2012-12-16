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
#include "../../base/memory.h"
#include "../../base/assert.h"
#include "../../base/utils.h"
#include "../ast.h"
#include "../symtable.h"


class SymTableTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    _symtable = symtable_create();
  }

  virtual void TearDown() {
    symtable_free(&_symtable);
    HEX_ASSERT(_symtable == NULL);
  }

  SymTable _symtable;
};

TEST_F(SymTableTest, symtable_createTest) {
  HEX_ASSERT(_symtable);
  ASSERT_EQ(0, symtable_size(_symtable));
  ASSERT_LE(0, symtable_capacity(_symtable));
}

TEST_F(SymTableTest, symtable_put_varTest) {
  /*
   * Test putting a global variable inside a symtable
   * and be able to look it up. */
  HEX_ASSERT(_symtable);

  char module_name[] = "hex.compiler.symtable";
  char var_name[] = "DEFAULT_SYMTABLE_CAPACITY";
  unsigned int indent_level = 0;
  hex_type_t type = 0x01;
  hex_scope_type_t scope_type = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_type_qualifier_t type_qualifier = 0x01;

  Symbol expected_symbol = symtable_put_var(
    _symtable,
    (char*)module_name,
    HEX_SYMBOL_TYPE_GLOBAL_VARIABLE,
    scope_type,
    (char*)var_name,
    type,
    type_qualifier,
    indent_level
  );

  HEX_ASSERT(expected_symbol);

  Symbol actual_symbol = symtable_lookup_var(
    _symtable,
    (char*)module_name,
    (char*)var_name,
    indent_level
  );

  ASSERT_EQ(expected_symbol, actual_symbol);
  ASSERT_TRUE(symtable_compare_symbols(expected_symbol, actual_symbol));
}

TEST_F(SymTableTest, symtable_put_varTest2) {
  /*
   * Test that putting two variables of same name but different
   * scope under the same module gives two different symbols.
   */
  HEX_ASSERT(_symtable);

  char module_name[] = "hex.compiler.ast";
  char name1[] = "myobj";
  char name2[] = "myobj";
  hex_symbol_type_t symbol_type_1 = HEX_SYMBOL_TYPE_LOCAL_VARIABLE;
  hex_symbol_type_t symbol_type_2 = HEX_SYMBOL_TYPE_GLOBAL_VARIABLE;
  hex_scope_type_t scope_type_1 = HEX_VAR_SCOPE_TYPE_LOCAL;
  hex_scope_type_t scope_type_2 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_type_t type_1 = 0x01;
  hex_type_t type_2 = 0x02;
  hex_type_qualifier_t type_qualifier_1 = 0x0;
  hex_type_qualifier_t type_qualifier_2 = 0x0;
  unsigned int indent_level_1 = 2;
  unsigned int indent_level_2 = 1;

  Symbol actual_symbol_1 = symtable_put_var(
    _symtable,
    module_name,
    symbol_type_1,
    scope_type_1,
    (char*)name1,
    type_1,
    type_qualifier_1,
    indent_level_1
  );

  Symbol actual_symbol_2 = symtable_put_var(
    _symtable,
    module_name,
    symbol_type_2,
    scope_type_2,
    (char*)name2,
    type_2,
    type_qualifier_2,
    indent_level_2
  );

  HEX_ASSERT(actual_symbol_1);
  HEX_ASSERT(actual_symbol_2);

  ASSERT_NE(actual_symbol_1, actual_symbol_2);
  ASSERT_FALSE(symtable_compare_symbols(actual_symbol_1, actual_symbol_2));

  Symbol expected_symbol_1 = symtable_lookup_var(
    _symtable,
    module_name,
    name1,
    indent_level_1
  );

  Symbol expected_symbol_2 = symtable_lookup_var(
    _symtable,
    module_name,
    name2,
    indent_level_2
  );

  HEX_ASSERT(expected_symbol_1);
  HEX_ASSERT(expected_symbol_2);

  ASSERT_NE(expected_symbol_1, expected_symbol_2);
  ASSERT_FALSE(symtable_compare_symbols(expected_symbol_1, expected_symbol_2));

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_1, actual_symbol_1));
  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_2, actual_symbol_2));
}

TEST_F(SymTableTest, symtable_put_varTest3) {
  /*
   * Test that putting two variables of same name and same scope
   * scope under different modules gives two different symbols.
   */
  HEX_ASSERT(_symtable);

  char module_name_1[] = "hex.compiler.ast";
  char module_name_2[] = "hex.compiler.semantics";
  char name1[] = "myobj";
  char name2[] = "myobj";
  hex_symbol_type_t symbol_type_1 = HEX_SYMBOL_TYPE_GLOBAL_VARIABLE;
  hex_symbol_type_t symbol_type_2 = HEX_SYMBOL_TYPE_GLOBAL_VARIABLE;
  hex_scope_type_t scope_type_1 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_scope_type_t scope_type_2 = HEX_VAR_SCOPE_TYPE_GLOBAL;
  hex_type_t type_1 = 0x01;
  hex_type_t type_2 = 0x01;
  hex_type_qualifier_t type_qualifier_1 = 0x0;
  hex_type_qualifier_t type_qualifier_2 = 0x0;
  unsigned int indent_level_1 = 1;
  unsigned int indent_level_2 = 1;

  Symbol actual_symbol_1 = symtable_put_var(
    _symtable,
    module_name_1,
    symbol_type_1,
    scope_type_1,
    (char*)name1,
    type_1,
    type_qualifier_1,
    indent_level_1
  );

  Symbol actual_symbol_2 = symtable_put_var(
    _symtable,
    module_name_2,
    symbol_type_2,
    scope_type_2,
    (char*)name2,
    type_2,
    type_qualifier_2,
    indent_level_2
  );

  HEX_ASSERT(actual_symbol_1);
  HEX_ASSERT(actual_symbol_2);

  ASSERT_NE(actual_symbol_1, actual_symbol_2);
  ASSERT_FALSE(symtable_compare_symbols(actual_symbol_1, actual_symbol_2));

  Symbol expected_symbol_1 = symtable_lookup_var(
    _symtable,
    module_name_1,
    name1,
    indent_level_1
  );

  Symbol expected_symbol_2 = symtable_lookup_var(
    _symtable,
    module_name_2,
    name2,
    indent_level_2
  );

  HEX_ASSERT(expected_symbol_1);
  HEX_ASSERT(expected_symbol_2);

  ASSERT_NE(expected_symbol_1, expected_symbol_2);
  ASSERT_FALSE(symtable_compare_symbols(expected_symbol_1, expected_symbol_2));

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_1, actual_symbol_1));
  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_2, actual_symbol_2));
}

TEST_F(SymTableTest, symtable_put_funcTest1) {
  /*
   * Test putting a function inside symtable and look it up. */
  char module_name[] = "hex.compiler.symtable";
  char func_name[] = "do_something";
  hex_type_t return_type = 0x01;
  ParameterList paramlist = NULL;

  Symbol actual_symbol = symtable_put_func(
    _symtable,
    module_name,
    func_name,
    return_type,
    paramlist
  );

  HEX_ASSERT(actual_symbol);

  Symbol expected_symbol = symtable_lookup_func(
    _symtable,
    module_name,
    func_name,
    paramlist
  );

  HEX_ASSERT(expected_symbol);

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol, actual_symbol));
}

TEST_F(SymTableTest, symtable_put_funcTest2) {
  /*
   * Test that two functions of different name and return type
   * in the same module gives two different symbols. */
  char module_name1[] = "hex.compiler.symtable";
  char module_name2[] = "hex.compiler.symtable";
  char name1[] = "do_something";
  char name2[] = "do_nothing";
  hex_type_t return_type1 = 0x01;
  hex_type_t return_type2 = 0x02;
  ParameterList paramlist1 = NULL;
  ParameterList paramlist2 = NULL;

  Symbol actual_symbol_1 = symtable_put_func(
    _symtable,
    module_name1,
    name1,
    return_type1,
    paramlist1
  );

  Symbol actual_symbol_2 = symtable_put_func(
    _symtable,
    module_name2,
    name2,
    return_type2,
    paramlist2
  );

  HEX_ASSERT(actual_symbol_1);
  HEX_ASSERT(actual_symbol_2);

  ASSERT_FALSE(symtable_compare_symbols(actual_symbol_1, actual_symbol_2));

  Symbol expected_symbol_1 = symtable_lookup_func(
    _symtable,
    module_name1,
    name1,
    paramlist1
  );

  Symbol expected_symbol_2 = symtable_lookup_func(
    _symtable,
    module_name2,
    name2,
    paramlist2
  );

  HEX_ASSERT(expected_symbol_1);
  HEX_ASSERT(expected_symbol_2);

  ASSERT_FALSE(symtable_compare_symbols(expected_symbol_1, expected_symbol_2));

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_1, actual_symbol_1));
  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_2, actual_symbol_2));
}

TEST_F(SymTableTest, symtable_put_funcTest3) {
  /*
   * Test that two functions with same name, return type but
   * different parameter in the same module gives two different symbols. */
  char module_name[] = "hex.compiler.symtable";
  char name[] = "do_something";
  hex_type_t return_type_1 = 0x01;
  hex_type_t return_type_2 = 0x01;
  ParameterList paramlist1=NULL;
  ParameterList paramlist2 = HEX_MALLOC(struct HexParameterList);

  Parameter param = HEX_MALLOC(struct HexParameter);
  param->parameter_name = (char*)"myobj";
  param->type_specifier = 0x01;
  paramlist2->parameter = param;
  paramlist2->next = NULL;

  Symbol actual_symbol_1 = symtable_put_func(
    _symtable,
    module_name,
    name,
    return_type_1,
    paramlist1
  );

  Symbol actual_symbol_2 = symtable_put_func(
    _symtable,
    module_name,
    name,
    return_type_2,
    paramlist2
  );

  HEX_ASSERT(actual_symbol_1);
  HEX_ASSERT(actual_symbol_2);

  ASSERT_FALSE(symtable_compare_symbols(actual_symbol_1, actual_symbol_2));

  Symbol expected_symbol_1 = symtable_lookup_func(
    _symtable,
    module_name,
    name,
    paramlist1
  );

  Symbol expected_symbol_2 = symtable_lookup_func(
    _symtable,
    module_name,
    name,
    paramlist2
  );

  HEX_ASSERT(expected_symbol_1);
  HEX_ASSERT(expected_symbol_2);

  ASSERT_FALSE(symtable_compare_symbols(expected_symbol_1, expected_symbol_2));

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_1, actual_symbol_1));
  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_2, actual_symbol_2));
}

TEST_F(SymTableTest, symtable_put_funcTest4) {
  /*
   * Test that two functions of same name, return type but different
   * parameter in different modules gives two different symbols. */
  char module_name1[] = "hex.compiler.vtable";
  char module_name2[] = "hex.compiler.ftable";
  char name1[] = "factorial";
  char name2[] = "factorial";
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

  Symbol actual_symbol_1 = symtable_put_func(
    _symtable,
    module_name1,
    name1,
    return_type1,
    paramlist1
  );

  Symbol actual_symbol_2 = symtable_put_func(
    _symtable,
    module_name2,
    name2,
    return_type2,
    paramlist2
  );

  HEX_ASSERT(actual_symbol_1);
  HEX_ASSERT(actual_symbol_2);

  ASSERT_FALSE(symtable_compare_symbols(actual_symbol_1, actual_symbol_2));

  Symbol expected_symbol_1 = symtable_lookup_func(
    _symtable,
    module_name1,
    name1,
    paramlist1
  );

  Symbol expected_symbol_2 = symtable_lookup_func(
    _symtable,
    module_name2,
    name2,
    paramlist2
  );

  HEX_ASSERT(expected_symbol_1);
  HEX_ASSERT(expected_symbol_2);

  ASSERT_FALSE(symtable_compare_symbols(expected_symbol_1, expected_symbol_2));

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_1, actual_symbol_1));
  ASSERT_TRUE(symtable_compare_symbols(expected_symbol_2, actual_symbol_2));
}

TEST_F(SymTableTest, symtable_put_typeTest1) {
  char module_name[] = "hex.compiler.symtable";
  char name[] = "MyObject";

  Symbol actual_symbol = symtable_put_type(
    _symtable,
    module_name,
    name
  );

  Symbol expected_symbol = symtable_lookup_type(
    _symtable,
    module_name,
    name
  );

  HEX_ASSERT(actual_symbol);
  HEX_ASSERT(expected_symbol);

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol, actual_symbol));
}

TEST_F(SymTableTest, symtable_put_typeTest2) {
  /*
   * Test that after entering a type, a lookup on a non-existent
   * type failes. */
  char module_name[] = "hex.compiler.symtable";
  char name[] = "MyObject";

  Symbol actual_symbol = symtable_put_type(
    _symtable,
    module_name,
    name
  );

  Symbol expected_symbol = symtable_lookup_type(
    _symtable,
    generate_text(6, 10),
    name
  );

  HEX_ASSERT(actual_symbol);
  HEX_ASSERT(expected_symbol == NULL);
}

TEST_F(SymTableTest, symtable_put_typeTest3) {
  /*
   * Test that after entering a type, a lookup on a non-existent
   * type failes. */
  char module_name[] = "hex.compiler.symtable";
  char name[] = "MyObject";

  Symbol actual_symbol = symtable_put_type(
    _symtable,
    module_name,
    name
  );

  Symbol expected_symbol = symtable_lookup_type(
    _symtable,
    module_name,
    generate_text(6, 10)
  );

  HEX_ASSERT(actual_symbol);
  HEX_ASSERT(expected_symbol == NULL);
}

TEST_F(SymTableTest, symtable_put_memberTest) {
  char module_name[] = "hex.compiler.symtable";
  char type_name[] = "MyObject";
  char member_name[] = "counter";
  hex_type_t member_type = 0x01;
  hex_type_qualifier_t type_qualifier = 0x01;

  Symbol actual_symbol = symtable_put_type(
    _symtable,
    module_name,
    type_name
  );

  Symbol actual_member = symtable_put_member(
    _symtable,
    module_name,
    type_name,
    member_name,
    member_type,
    type_qualifier
  );

  Symbol expected_symbol = symtable_lookup_type(
    _symtable,
    module_name,
    type_name
  );

  Symbol expected_member = symtable_lookup_member(
    _symtable,
    module_name,
    type_name,
    member_name
  );

  HEX_ASSERT(actual_symbol);
  HEX_ASSERT(expected_symbol);
  HEX_ASSERT(actual_member);
  HEX_ASSERT(expected_member);

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol, actual_symbol));
  ASSERT_TRUE(symtable_compare_symbols(expected_member, actual_member));
}

TEST_F(SymTableTest, symtable_put_methodTest) {
  char module_name[] = "hex.compiler.symtable";
  char type_name[] = "MyObject";
  char method_name[] = "do_something";
  hex_type_t return_type = 0x01;
  ParameterList paramlist = NULL;

  Symbol actual_symbol = symtable_put_type(
    _symtable,
    module_name,
    type_name
  );

  Symbol actual_method = symtable_put_method(
    _symtable,
    module_name,
    type_name,
    method_name,
    return_type,
    paramlist
  );

  Symbol expected_symbol = symtable_lookup_type(
    _symtable,
    module_name,
    type_name
  );

  Symbol expected_method = symtable_lookup_method(
    _symtable,
    module_name,
    type_name,
    method_name,
    paramlist
  );

  HEX_ASSERT(actual_symbol);
  HEX_ASSERT(expected_symbol);
  HEX_ASSERT(actual_method);
  HEX_ASSERT(expected_method);

  ASSERT_TRUE(symtable_compare_symbols(expected_symbol, actual_symbol));
  ASSERT_TRUE(symtable_compare_symbols(expected_method, actual_method));
}
