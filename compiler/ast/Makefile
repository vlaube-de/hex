#
# HEX Programming Language
# Copyright (C) 2013  Yanzheng Li
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

CC=gcc
CXX=g++
CFLAGS=-Wno-implicit -Wall -arch x86_64

ast_unparsed.o: ast_unparsed.h ast_unparsed.cpp
	$(CXX) -c ast_unparsed.cpp

ast_list_obj.o: ast_list_obj.h ast_list_obj.cpp
	$(CXX) -c ast_list_obj.cpp

ast_node.o: examinable.h ast_node.h ast_node.cpp
	$(CXX) -c ast_node.cpp

ast_target_list.o: ast_list_obj.o ast_node.o ast_target_list.h ast_target_list.cpp
	$(CXX) -c ast_target_list.cpp

ast_val_atom.o: ast_node.o ast_val_atom.h ast_val_atom.cpp
	$(CXX) -c ast_val_atom.cpp

ast_val_list.o: ast_node.o ast_list_obj.o ast_val_atom.o ast_val_list.h ast_val_list.cpp
	$(CXX) -c ast_val_list.cpp

ast_simple_param_list.o: ast_list_obj.o ast_node.o ast_simple_param_list.h ast_simple_param_list.cpp
	$(CXX) -c ast_simple_param_list.cpp

ast_keyword_val.o: ast_node.o ast_keyword_val.h ast_keyword_val.cpp
	$(CXX) -c ast_keyword_val.cpp

ast_keyword_val_list.o: ast_keyword_val.o ast_list_obj.o ast_node.o ast_keyword_val_list.h ast_keyword_val_list.cpp
	$(CXX) -c ast_keyword_val_list.cpp

ast_parameter_list.o: ast_node.o ast_parameter_list.h ast_parameter_list.cpp
	$(CXX) -c ast_parameter_list.cpp

ast_arg_list.o: ast_node.o ast_arg_list.h ast_arg_list.cpp
	$(CXX) -c ast_arg_list.cpp

ast_comprehension.o: ast_node.o ast_comprehension.h ast_comprehension.cpp
	$(CXX) -c ast_comprehension.cpp

ast_list_form.o: ast_node.o ast_comprehension.o ast_list_form.h ast_list_form.cpp
	$(CXX) -c ast_list_form.cpp

ast_map_field.o: ast_node.o ast_val_atom.o ast_map_field.h ast_map_field.cpp
	$(CXX) -c ast_map_field.cpp

ast_map_field_list.o: ast_node.o ast_list_obj.o ast_map_field_list.h ast_map_field_list.cpp
	$(CXX) -c ast_map_field_list.cpp

ast_map_form.o: ast_node.o ast_map_field_list.o ast_map_form.h ast_map_form.cpp
	$(CXX) -c ast_map_form.cpp

ast_field_def.o: ast_node.o ast_val_atom.o ast_field_def.h ast_field_def.cpp
	$(CXX) -c ast_field_def.cpp

ast_field_def_list.o: ast_field_def.o ast_list_obj.o ast_field_def_list.h ast_field_def_list.cpp
	$(CXX) -c ast_field_def_list.cpp

ast_dict_form.o: ast_node.o ast_dict_form.h ast_dict_form.cpp
	$(CXX) -c ast_dict_form.cpp

ast_name.o: ast_node.o ast_list_obj.o ast_name.h ast_name.cpp
	$(CXX) -c ast_name.cpp

ast_decorator.o: ast_node.o ast_decorator.h ast_decorator.cpp
	$(CXX) -c ast_decorator.cpp

ast_decorator_list.o: ast_decorator.o ast_decorator_list.h ast_decorator_list.cpp
	$(CXX) -c ast_decorator_list.cpp

ast_operator_def.o: ast_node.o ast_operator_def.h ast_operator_def.cpp
	$(CXX) -c ast_operator_def.cpp

ast_attribute_def.o: ast_node.o ast_attribute_def.h ast_attribute_def.cpp
	$(CXX) -c ast_attribute_def.cpp

ast_assignment_stmt.o: ast_node.o ast_assignment_stmt.h ast_assignment_stmt.cpp
	$(CXX) -c ast_assignment_stmt.cpp

ast_lambda.o: ast_node.o ast_lambda.h ast_lambda.cpp
	$(CXX) -c ast_lambda.cpp

ast_expr_list.o: ast_node.o ast_list_obj.o ast_expr_list.h ast_expr_list.cpp
	$(CXX) -c ast_expr_list.cpp

ast_unary_expr.o: ast_expr.h ast_unary_expr.h ast_unary_expr.cpp
	$(CXX) -c ast_unary_expr.cpp

ast_neg_expr.o: ast_unary_expr.o ast_neg_expr.h ast_neg_expr.cpp
	$(CXX) -c ast_neg_expr.cpp

ast_not_expr.o: ast_unary_expr.o ast_not_expr.h ast_not_expr.cpp
	$(CXX) -c ast_not_expr.cpp

ast_bitwise_not_expr.o: ast_unary_expr.o ast_bitwise_not_expr.h ast_bitwise_not_expr.cpp
	$(CXX) -c ast_bitwise_not_expr.cpp

ast_inc_expr.o: ast_unary_expr.o ast_inc_expr.h ast_inc_expr.cpp
	$(CXX) -c ast_inc_expr.cpp

ast_dec_expr.o: ast_unary_expr.o ast_dec_expr.h ast_dec_expr.cpp
	$(CXX) -c ast_dec_expr.cpp

ast_exitential_expr.o: ast_unary_expr.o ast_existential_expr.h ast_existential_expr.cpp
	$(CXX) -c ast_existential_expr.cpp

ast_binary_expr.o: ast_expr.h ast_binary_expr.h ast_binary_expr.cpp
	$(CXX) -c ast_binary_expr.cpp

ast_commutative_binary_expr.o: ast_binary_expr.o ast_commutative_binary_expr.h ast_commutative_binary_expr.cpp
	$(CXX) -c ast_commutative_binary_expr.cpp

ast_and_expr.o: ast_commutative_binary_expr.o ast_and_expr.h ast_and_expr.cpp
	$(CXX) -c ast_and_expr.cpp

ast_or_expr.o: ast_commutative_binary_expr.o ast_or_expr.h ast_or_expr.cpp
	$(CXX) -c ast_or_expr.cpp

ast_bitwise_and_expr.o: ast_commutative_binary_expr.o ast_bitwise_and_expr.h ast_bitwise_and_expr.cpp
	$(CXX) -c ast_bitwise_and_expr.cpp

ast_bitwise_or_expr.o: ast_commutative_binary_expr.o ast_bitwise_or_expr.h ast_bitwise_or_expr.cpp
	$(CXX) -c ast_bitwise_or_expr.cpp

ast_bitwise_xor_expr.o: ast_commutative_binary_expr.o ast_bitwise_xor_expr.h ast_bitwise_xor_expr.cpp
	$(CXX) -c ast_bitwise_xor_expr.cpp

ast_bitwise_shift_left_expr.o: ast_binary_expr.o ast_bitwise_shift_left_expr.h ast_bitwise_shift_left_expr.cpp
	$(CXX) -c ast_bitwise_shift_left_expr.cpp

ast_bitwise_shift_right_expr.o: ast_binary_expr.o ast_bitwise_shift_right_expr.h ast_bitwise_shift_right_expr.cpp
	$(CXX) -c ast_bitwise_shift_right_expr.cpp

ast_power_expr.o: ast_binary_expr.o ast_power_expr.h ast_power_expr.cpp
	$(CXX) -c ast_power_expr.cpp

ast_add_expr.o: ast_commutative_binary_expr.o ast_add_expr.h ast_add_expr.cpp
	$(CXX) -c ast_add_expr.cpp

ast_minus_expr.o: ast_binary_expr.o ast_minus_expr.h ast_minus_expr.cpp
	$(CXX) -c ast_minus_expr.cpp

ast_multiply_expr.o: ast_commutative_binary_expr.o ast_multiply_expr.h ast_multiply_expr.cpp
	$(CXX) -c ast_multiply_expr.cpp

ast_divide_expr.o: ast_binary_expr.o ast_divide_expr.h ast_divide_expr.cpp
	$(CXX) -c ast_divide_expr.cpp

ast_mod_expr.o: ast_binary_expr.o ast_mod_expr.h ast_mod_expr.cpp
	$(CXX) -c ast_mod_expr.cpp

ast_eq_expr.o: ast_commutative_binary_expr.o ast_eq_expr.h ast_eq_expr.cpp
	$(CXX) -c ast_eq_expr.cpp

ast_neq_expr.o: ast_commutative_binary_expr.o ast_neq_expr.h ast_neq_expr.cpp
	$(CXX) -c ast_neq_expr.cpp

ast_is_expr.o: ast_commutative_binary_expr.o ast_is_expr.h ast_is_expr.cpp
	$(CXX) -c ast_is_expr.cpp

ast_lt_expr.o: ast_binary_expr.o ast_lt_expr.h ast_lt_expr.cpp
	$(CXX) -c ast_lt_expr.cpp

ast_le_expr.o: ast_binary_expr.o ast_le_expr.h ast_le_expr.cpp
	$(CXX) -c ast_le_expr.cpp

ast_gt_expr.o: ast_binary_expr.o ast_gt_expr.h ast_gt_expr.cpp
	$(CXX) -c ast_gt_expr.cpp

ast_ge_expr.o: ast_binary_expr.o ast_ge_expr.h ast_ge_expr.cpp
	$(CXX) -c ast_ge_expr.cpp

ast_in_expr.o: ast_binary_expr.o ast_in_expr.h ast_in_expr.cpp
	$(CXX) -c ast_in_expr.cpp

ast_not_in_expr.o: ast_binary_expr.o ast_not_in_expr.h ast_not_in_expr.cpp
	$(CXX) -c ast_not_in_expr.cpp

ast_in_range_expr.o: ast_binary_expr.o ast_in_range_expr.h ast_in_range_expr.cpp
	$(CXX) -c ast_in_range_expr.cpp

ast_ex_range_expr.o: ast_binary_expr.o ast_ex_range_expr.h ast_ex_range_expr.cpp
	$(CXX) -c ast_ex_range_expr.cpp

ast_conditional_expr.o: ast_binary_expr.o ast_conditional_expr.h ast_conditional_expr.cpp
	$(CXX) -c ast_conditional_expr.cpp

ast_yield_expr.o: ast_expr.h ast_expr_list.o  ast_yield_expr.h ast_yield_expr.cpp
	$(CXX) -c ast_yield_expr.cpp

ast_string_expr.o: ast_expr.h ast_expr_list.o ast_string_expr.h ast_string_expr.cpp
	$(CXX) -c ast_string_expr.cpp

ast_pseudo_assign_expr.o: ast_binary_expr.o ast_pseudo_assign_expr.h ast_pseudo_assign_expr.cpp
	$(CXX) -c ast_pseudo_assign_expr.cpp

ast_pseudo_assign_plus_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_plus_expr.h ast_pseudo_assign_plus_expr.cpp
	$(CXX) -c ast_pseudo_assign_plus_expr.cpp

ast_pseudo_assign_minus_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_minus_expr.h ast_pseudo_assign_minus_expr.cpp
	$(CXX) -c ast_pseudo_assign_minus_expr.cpp

ast_pseudo_assign_mul_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_mul_expr.h ast_pseudo_assign_mul_expr.cpp
	$(CXX) -c ast_pseudo_assign_mul_expr.cpp

ast_pseudo_assign_div_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_div_expr.h ast_pseudo_assign_div_expr.cpp
	$(CXX) -c ast_pseudo_assign_div_expr.cpp

ast_pseudo_assign_mod_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_mod_expr.h ast_pseudo_assign_mod_expr.cpp
	$(CXX) -c ast_pseudo_assign_mod_expr.cpp

ast_pseudo_assign_bitwise_and_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_and_expr.h ast_pseudo_assign_bitwise_and_expr.cpp
	$(CXX) -c ast_pseudo_assign_bitwise_and_expr.cpp

ast_pseudo_assign_bitwise_or_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_or_expr.h ast_pseudo_assign_bitwise_or_expr.cpp
	$(CXX) -c ast_pseudo_assign_bitwise_or_expr.cpp

ast_pseudo_assign_bitwise_xor_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_xor_expr.h ast_pseudo_assign_bitwise_xor_expr.cpp
	$(CXX) -c ast_pseudo_assign_bitwise_xor_expr.cpp

ast_pseudo_assign_bitwise_left_shift_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_left_shift_expr.h ast_pseudo_assign_bitwise_left_shift_expr.cpp
	$(CXX) -c ast_pseudo_assign_bitwise_left_shift_expr.cpp

ast_pseudo_assign_bitwise_right_shift_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_right_shift_expr.h ast_pseudo_assign_bitwise_right_shift_expr.cpp
	$(CXX) -c ast_pseudo_assign_bitwise_right_shift_expr.cpp

ast_primary.o: ast_expr.h ast_primary.h ast_primary.cpp
	$(CXX) -c ast_primary.cpp

ast_identifier.o: ast_primary.o ast_identifier.h ast_identifier.cpp
	$(CXX) -c ast_identifier.cpp

ast_literal.o: ast_primary.o ast_literal.h ast_literal.cpp
	$(CXX) -c ast_literal.cpp

ast_integer_literal.o: ast_unparsed.o ast_literal.o ast_integer_literal.h ast_integer_literal.cpp
	$(CXX) -c ast_integer_literal.cpp

ast_float_literal.o: ast_unparsed.o ast_literal.o ast_float_literal.h ast_float_literal.cpp
	$(CXX) -c ast_float_literal.cpp

ast_string_literal.o: ast_unparsed.o ast_literal.o ast_string_literal.h ast_string_literal.cpp
	$(CXX) -c ast_string_literal.cpp

ast_slicing.o: ast_primary.o ast_slicing.h ast_slicing.cpp
	$(CXX) -c ast_slicing.cpp

ast_call.o: ast_primary.o ast_call.h ast_call.cpp
	$(CXX) -c ast_call.cpp

ast_attribute_ref.o: ast_primary.o ast_attribute_ref.h ast_attribute_ref.cpp
	$(CXX) -c ast_attribute_ref.cpp


all:	ast_unparsed.o		\
			ast_list_obj.o		\
			ast_node.o				\
			ast_target_list.o	\
			ast_val_atom.o	\
			ast_val_list.o	\
			ast_simple_param_list.o	\
			ast_keyword_val.o	\
			ast_keyword_val_list.o	\
			ast_parameter_list.o	\
			ast_arg_list.o	\
			ast_comprehension.o	\
			ast_list_form.o	\
			ast_map_field.o	\
			ast_map_field_list.o	\
			ast_map_form.o	\
			ast_field_def.o	\
			ast_field_def_list.o	\
			ast_dict_form.o	\
			ast_name.o	\
			ast_decorator.o	\
			ast_decorator_list.o	\
			ast_operator_def.o	\
			ast_attribute_def.o	\
			ast_assignment_stmt.o	\
			ast_lambda.o	\
			ast_expr_list.o		\
			ast_binary_expr.o	\
			ast_commutative_binary_expr.o	\
			ast_and_expr.o	\
			ast_or_expr.o		\
			ast_bitwise_and_expr.o	\
			ast_bitwise_or_expr.o	\
			ast_bitwise_xor_expr.o	\
			ast_bitwise_shift_left_expr.o	\
			ast_bitwise_shift_right_expr.o	\
			ast_unary_expr.o	\
			ast_neg_expr.o	\
			ast_not_expr.o	\
			ast_bitwise_not_expr.o	\
			ast_inc_expr.o	\
			ast_dec_expr.o	\
			ast_existential_expr.o	\
			ast_power_expr.o	\
			ast_add_expr.o	\
			ast_minus_expr.o	\
			ast_multiply_expr.o	\
			ast_divide_expr.o	\
			ast_mod_expr.o	\
			ast_eq_expr.o	\
			ast_neq_expr.o	\
			ast_is_expr.o	\
			ast_lt_expr.o	\
			ast_le_expr.o	\
			ast_gt_expr.o	\
			ast_ge_expr.o	\
			ast_in_expr.o	\
			ast_not_in_expr.o	\
			ast_in_range_expr.o	\
			ast_ex_range_expr.o	\
			ast_conditional_expr.o	\
			ast_yield_expr.o	\
			ast_string_expr.o	\
			ast_pseudo_assign_expr.o	\
			ast_pseudo_assign_plus_expr.o	\
			ast_pseudo_assign_minus_expr.o	\
			ast_pseudo_assign_mul_expr.o	\
			ast_pseudo_assign_div_expr.o	\
			ast_pseudo_assign_mod_expr.o	\
			ast_pseudo_assign_bitwise_and_expr.o	\
			ast_pseudo_assign_bitwise_or_expr.o	\
			ast_pseudo_assign_bitwise_xor_expr.o	\
			ast_pseudo_assign_bitwise_left_shift_expr.o	\
			ast_pseudo_assign_bitwise_right_shift_expr.o	\
			ast_primary.o	\
			ast_identifier.o	\
			ast_literal.o	\
			ast_integer_literal.o	\
			ast_float_literal.o	\
			ast_string_literal.o	\
			ast_slicing.o	\
			ast_attribute_ref.o	\
			ast_call.o	\


clean:
	rm *.gch *.o *.a *.out *.test
