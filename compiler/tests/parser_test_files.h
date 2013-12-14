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

#include <vector>
#include "hex_parser_test_file.h"

#ifndef _HEX_PARSER_TEST_FILES_H_
#define _HEX_PARSER_TEST_FILES_H_

std::vector<HexTestFile> hex_parser_testfiles = {
    /* 00 */ {"./assets/hex_blank.hex", "./assets/xml/hex_blank.xml"},
    /* 01 */ {"./assets/hex_identifier.hex", "./assets/xml/hex_identifier.xml"},
    /* 02 */ {"./assets/hex_decimal_integer_literal.hex", "./assets/xml/hex_decimal_integer_literal.xml"},
    /* 03 */ {"./assets/hex_binary_integer_literal.hex", "./assets/xml/hex_binary_integer_literal.xml"},
    /* 04 */ {"./assets/hex_octal_integer_literal.hex", "./assets/xml/hex_octal_integer_literal.xml"},
    /* 05 */ {"./assets/hex_hexadecimal_integer_literal.hex", "./assets/xml/hex_hexadecimal_integer_literal.xml"},
    /* 06 */ {"./assets/hex_floating_literal.hex", "./assets/xml/hex_floating_literal.xml"},
    /* 07 */ {"./assets/hex_string_literal.hex", "./assets/xml/hex_string_literal.xml"},
    /* 08 */ {"./assets/hex_call_1.hex", "./assets/xml/hex_call_1.xml"},
    /* 09 */ {"./assets/hex_call_2.hex", "./assets/xml/hex_call_2.xml"},
    /* 10 */ {"./assets/hex_call_3.hex", "./assets/xml/hex_call_3.xml"},
    /* 11 */ {"./assets/hex_call_4.hex", "./assets/xml/hex_call_4.xml"},
    /* 12 */ {"./assets/hex_call_5.hex", "./assets/xml/hex_call_5.xml"},
    /* 13 */ {"./assets/hex_call_6.hex", "./assets/xml/hex_call_6.xml"},
    /* 14 */ {"./assets/hex_call_7.hex", "./assets/xml/hex_call_7.xml"},
    /* 15 */ {"./assets/hex_call_8.hex", "./assets/xml/hex_call_8.xml"},
    /* 16 */ {"./assets/hex_call_9.hex", "./assets/xml/hex_call_9.xml"},
    /* 17 */ {"./assets/hex_call_10.hex", "./assets/xml/hex_call_10.xml"},
    /* 18 */ {"./assets/hex_call_11.hex", "./assets/xml/hex_call_11.xml"},
    /* 19 */ {"./assets/hex_call_12.hex", "./assets/xml/hex_call_12.xml"},
    /* 20 */ {"./assets/hex_call_13.hex", "./assets/xml/hex_call_13.xml"},
    /* 21 */ {"./assets/hex_call_14.hex", "./assets/xml/hex_call_14.xml"},
    /* 22 */ {"./assets/hex_call_15.hex", "./assets/xml/hex_call_15.xml"},
    /* 23 */ {"./assets/hex_attribute_ref.hex", "./assets/xml/hex_attribute_ref.xml"},
    /* 24 */ {"./assets/hex_slicing_1.hex", "./assets/xml/hex_slicing_1.xml"},
    /* 25 */ {"./assets/hex_slicing_2.hex", "./assets/xml/hex_slicing_2.xml"},
    /* 26 */ {"./assets/hex_increment_expr.hex", "./assets/xml/hex_increment_expr.xml"},
    /* 27 */ {"./assets/hex_decrement_expr.hex", "./assets/xml/hex_decrement_expr.xml"},
    /* 28 */ {"./assets/hex_existential_expr.hex", "./assets/xml/hex_existential_expr.xml"},
    /* 29 */ {"./assets/hex_positive_expr.hex", "./assets/xml/hex_positive_expr.xml"},
    /* 30 */ {"./assets/hex_negative_expr.hex", "./assets/xml/hex_negative_expr.xml"},
    /* 31 */ {"./assets/hex_not_expr.hex", "./assets/xml/hex_not_expr.xml"},
    /* 32 */ {"./assets/hex_bitwise_not_expr.hex", "./assets/xml/hex_bitwise_not_expr.xml"},
    /* 33 */ {"./assets/hex_additive_expr.hex", "./assets/xml/hex_additive_expr.xml"},
    /* 34 */ {"./assets/hex_multiplicative_expr.hex", "./assets/xml/hex_multiplicative_expr.xml"},
    /* 35 */ {"./assets/hex_power_expr.hex", "./assets/xml/hex_power_expr.xml"},
    /* 36 */ {"./assets/hex_bitwise_expr_1.hex", "./assets/xml/hex_bitwise_expr_1.xml"},
    /* 37 */ {"./assets/hex_bitwise_expr_2.hex", "./assets/xml/hex_bitwise_expr_2.xml"},
    /* 38 */ {"./assets/hex_comparison_expr_1.hex", "./assets/xml/hex_comparison_expr_1.xml"},
    /* 39 */ {"./assets/hex_comparison_expr_2.hex", "./assets/xml/hex_comparison_expr_2.xml"},
    /* 40 */ {"./assets/hex_comparison_expr_3.hex", "./assets/xml/hex_comparison_expr_3.xml"},
    /* 41 */ {"./assets/hex_logical_expr.hex", "./assets/xml/hex_logical_expr.xml"},
    /* 42 */ {"./assets/hex_range_expr.hex", "./assets/xml/hex_range_expr.xml"},
    /* 43 */ {"./assets/hex_conditional_expr.hex", "./assets/xml/hex_conditional_expr.xml"},
    /* 44 */ {"./assets/hex_assignment_expr_1.hex", "./assets/xml/hex_assignment_expr_1.xml"},
    /* 45 */ {"./assets/hex_assignment_expr_2.hex", "./assets/xml/hex_assignment_expr_2.xml"},
    /* 46 */ {"./assets/hex_assignment_expr_3.hex", "./assets/xml/hex_assignment_expr_3.xml"},
    /* 47 */ {"./assets/hex_yield_expr.hex", "./assets/xml/hex_yield_expr.xml"},
    /* 48 */ {"./assets/hex_string_composition_expr.hex", "./assets/xml/hex_string_composition_expr.xml"},
    /* 49 */ {"./assets/hex_generator_expr_1.hex", "./assets/xml/hex_generator_expr_1.xml"},
    /* 50 */ {"./assets/hex_generator_expr_2.hex", "./assets/xml/hex_generator_expr_2.xml"},
    /* 51 */ {"./assets/hex_paren_form.hex", "./assets/xml/hex_paren_form.xml"},
    /* 52 */ {"./assets/hex_list_form_1.hex", "./assets/xml/hex_list_form_1.xml"},
    /* 53 */ {"./assets/hex_list_form_2.hex", "./assets/xml/hex_list_form_2.xml"},
    /* 54 */ {"./assets/hex_dict_form.hex", "./assets/xml/hex_dict_form.xml"},
    /* 55 */ {"./assets/hex_object_form.hex", "./assets/xml/hex_object_form.xml"},
    /* 56 */ {"./assets/hex_using_stmt.hex", "./assets/xml/hex_using_stmt.xml"},
    /* 57 */ {"./assets/hex_if_stmt.hex", "./assets/xml/hex_if_stmt.xml"},
    /* 58 */ {"./assets/hex_for_stmt_1.hex", "./assets/xml/hex_for_stmt_1.xml"},
    /* 59 */ {"./assets/hex_for_stmt_2.hex", "./assets/xml/hex_for_stmt_2.xml"},
    /* 60 */ {"./assets/hex_with_stmt.hex", "./assets/xml/hex_with_stmt.xml"},
    /* 61 */ {"./assets/hex_lock_stmt.hex", "./assets/xml/hex_lock_stmt.xml"},
    /* 62 */ {"./assets/hex_while_stmt.hex", "./assets/xml/hex_while_stmt.xml"},
    /* 63 */ {"./assets/hex_try_stmt.hex", "./assets/xml/hex_try_stmt.xml"},
    /* 64 */ {"./assets/hex_class_def_1.hex", "./assets/xml/hex_class_def_1.xml"},
    /* 65 */ {"./assets/hex_class_def_2.hex", "./assets/xml/hex_class_def_2.xml"},
    /* 66 */ {"./assets/hex_class_def_3.hex", "./assets/xml/hex_class_def_3.xml"},
    /* 67 */ {"./assets/hex_assignment_stmt_1.hex", "./assets/xml/hex_assignment_stmt_1.xml"},
    /* 68 */ {"./assets/hex_assignment_stmt_2.hex", "./assets/xml/hex_assignment_stmt_2.xml"},
    /* 69 */ {"./assets/hex_await_stmt.hex", "./assets/xml/hex_await_stmt.xml"},
    /* 70 */ {"./assets/hex_task_def_1.hex", "./assets/xml/hex_task_def_1.xml"},
    /* 71 */ {"./assets/hex_task_def_2.hex", "./assets/xml/hex_task_def_2.xml"},
    /* 72 */ {"./assets/hex_input_stmt.hex", "./assets/xml/hex_input_stmt.xml"},
    /* 73 */ {"./assets/hex_output_stmt.hex", "./assets/xml/hex_output_stmt.xml"},
    /* 74 */ {"./assets/hex_return_stmt.hex", "./assets/xml/hex_return_stmt.xml"},
    /* 75 */ {"./assets/hex_break_stmt.hex", "./assets/xml/hex_break_stmt.xml"},
    /* 76 */ {"./assets/hex_continue_stmt.hex", "./assets/xml/hex_continue_stmt.xml"},
    /* 77 */ {"./assets/hex_raise_stmt.hex", "./assets/xml/hex_raise_stmt.xml"},
    /* 78 */ {"./assets/hex_expr_list_stmt.hex", "./assets/xml/hex_expr_list_stmt.xml"},
    /* 79 */ {"./assets/hex_simple_if_stmt.hex", "./assets/xml/hex_simple_if_stmt.xml"}
  };

#endif /* _HEX_PARSER_TEST_FILES_H_ */