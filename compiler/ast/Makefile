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

CXX=c++
CFLAGS=-Wno-implicit -Wno-deprecated-writable-strings -arch x86_64

AR=ar
ARFLAGS=rvs

PY=python

examiner.o: examiner.h examiner.cc
	$(CXX) $(CFLAGS) -c examiner.cc

ast_unparsed.o: ast_unparsed.h ast_unparsed.cc
	$(CXX) $(CFLAGS) -c ast_unparsed.cc

ast_list_obj.o: ast_list_obj.h ast_list_obj.cc
	$(CXX) $(CFLAGS) -c ast_list_obj.cc

ast_node.o: examinable.h ast_node.h ast_node.cc
	$(CXX) $(CFLAGS) -c ast_node.cc

ast_target_list.o: ast_list_obj.o ast_node.o ast_target_list.h ast_target_list.cc
	$(CXX) $(CFLAGS) -c ast_target_list.cc

ast_val_list.o: ast_node.o ast_list_obj.o ast_val_list.h ast_val_list.cc
	$(CXX) $(CFLAGS) -c ast_val_list.cc

ast_simple_param.o: ast_simple_param.h ast_simple_param.cc
	$(CXX) $(CFLAGS) -c ast_simple_param.cc

ast_simple_param_list.o: ast_list_obj.o ast_node.o ast_simple_param_list.h ast_simple_param_list.cc
	$(CXX) $(CFLAGS) -c ast_simple_param_list.cc

ast_keyword_param.o: ast_keyword_param.h ast_keyword_param.cc
	$(CXX) $(CFLAGS) -c ast_keyword_param.cc

ast_keyword_param_list.o: ast_keyword_param_list.h ast_keyword_param_list.cc
	$(CXX) $(CFLAGS) -c ast_keyword_param_list.cc

ast_keyword_val.o: ast_node.o ast_keyword_val.h ast_keyword_val.cc
	$(CXX) $(CFLAGS) -c ast_keyword_val.cc

ast_keyword_val_list.o: ast_keyword_val.o ast_list_obj.o ast_node.o ast_keyword_val_list.h ast_keyword_val_list.cc
	$(CXX) $(CFLAGS) -c ast_keyword_val_list.cc

ast_parameter_list.o: ast_node.o ast_parameter_list.h ast_parameter_list.cc
	$(CXX) $(CFLAGS) -c ast_parameter_list.cc

ast_arg_list.o: ast_node.o ast_arg_list.h ast_arg_list.cc
	$(CXX) $(CFLAGS) -c ast_arg_list.cc

ast_comprehension.o: ast_node.o ast_comprehension.h ast_comprehension.cc
	$(CXX) $(CFLAGS) -c ast_comprehension.cc

ast_list_form.o: ast_node.o ast_comprehension.o ast_list_form.h ast_list_form.cc
	$(CXX) $(CFLAGS) -c ast_list_form.cc

ast_field_def.o: ast_node.o ast_field_def.h ast_field_def.cc
	$(CXX) $(CFLAGS) -c ast_field_def.cc

ast_field_def_list.o: ast_field_def.o ast_list_obj.o ast_field_def_list.h ast_field_def_list.cc
	$(CXX) $(CFLAGS) -c ast_field_def_list.cc

ast_key_value_pair.o: ast_key_value_pair.h ast_key_value_pair.cc
	$(CXX) $(CFLAGS) -c ast_key_value_pair.cc

ast_key_value_pair_list.o: ast_key_value_pair_list.h ast_key_value_pair_list.cc
	$(CXX) $(CFLAGS) -c ast_key_value_pair_list.cc

ast_dict_form.o: ast_node.o ast_dict_form.h ast_dict_form.cc
	$(CXX) $(CFLAGS) -c ast_dict_form.cc

ast_name.o: ast_node.o ast_list_obj.o ast_name.h ast_name.cc
	$(CXX) $(CFLAGS) -c ast_name.cc

ast_decorator.o: ast_node.o ast_decorator.h ast_decorator.cc
	$(CXX) $(CFLAGS) -c ast_decorator.cc

ast_decorator_list.o: ast_decorator.o ast_decorator_list.h ast_decorator_list.cc
	$(CXX) $(CFLAGS) -c ast_decorator_list.cc

ast_assignment_stmt.o: ast_node.o ast_assignment_stmt.h ast_assignment_stmt.cc
	$(CXX) $(CFLAGS) -c ast_assignment_stmt.cc

ast_using_src.o: ast_node.o ast_using_src.h ast_using_src.cc
	$(CXX) $(CFLAGS) -c ast_using_src.cc

ast_using_stmt.o: ast_node.o ast_using_stmt.h ast_using_stmt.cc
	$(CXX) $(CFLAGS) -c ast_using_stmt.cc

ast_stmt_group.o: ast_node.o ast_stmt.h ast_stmt_group.h ast_stmt_group.cc
	$(CXX) $(CFLAGS) -c ast_stmt_group.cc

ast_await_stmt.o: ast_await_stmt.h ast_await_stmt.cc
	$(CXX) $(CFLAGS) -c ast_await_stmt.cc

ast_return_stmt.o: ast_node.o ast_return_stmt.h ast_return_stmt.cc
	$(CXX) $(CFLAGS) -c ast_return_stmt.cc

ast_break_stmt.o: ast_node.o ast_break_stmt.h ast_break_stmt.cc
	$(CXX) $(CFLAGS) -c ast_break_stmt.cc

ast_continue_stmt.o: ast_continue_stmt.h ast_continue_stmt.cc
	$(CXX) $(CFLAGS) -c ast_continue_stmt.cc

ast_raise_stmt.o: ast_raise_stmt.h ast_raise_stmt.cc
	$(CXX) $(CFLAGS) -c ast_raise_stmt.cc

ast_input_stmt.o: ast_input_stmt.h ast_input_stmt.cc
	$(CXX) $(CFLAGS) -c ast_input_stmt.cc

ast_output_stmt.o: ast_output_stmt.h ast_output_stmt.cc
	$(CXX) $(CFLAGS) -c ast_output_stmt.cc

ast_expr_list_stmt.o: ast_expr_list_stmt.h ast_expr_list_stmt.cc
	$(CXX) $(CFLAGS) -c ast_expr_list_stmt.cc

ast_stmt.o: ast_stmt.h ast_stmt.cc
	$(CXX) $(CFLAGS) -c ast_stmt.cc

ast_simple_stmt.o: ast_simple_stmt.h ast_simple_stmt.cc
	$(CXX) $(CFLAGS) -c ast_simple_stmt.cc

ast_compound_stmt.o: ast_compound_stmt.h ast_compound_stmt.cc
	$(CXX) $(CFLAGS) -c ast_compound_stmt.cc

ast_for_stmt.o: ast_for_stmt.h ast_for_stmt.cc
	$(CXX) $(CFLAGS) -c ast_for_stmt.cc

ast_with_stmt.o: ast_with_stmt.h ast_with_stmt.cc
	$(CXX) $(CFLAGS) -c ast_with_stmt.cc

ast_lock_stmt.o: ast_lock_stmt.h ast_lock_stmt.cc
	$(CXX) $(CFLAGS) -c ast_lock_stmt.cc

ast_catch_stmt.o: ast_catch_stmt.h ast_catch_stmt.cc
	$(CXX) $(CFLAGS) -c ast_catch_stmt.cc

ast_catch_stmt_group.o: ast_catch_stmt_group.h ast_catch_stmt_group.cc
	$(CXX) $(CFLAGS) -c ast_catch_stmt_group.cc

ast_try_stmt.o: ast_try_stmt.h ast_try_stmt.cc
	$(CXX) $(CFLAGS) -c ast_try_stmt.cc

ast_while_stmt.o: ast_while_stmt.h ast_while_stmt.cc
	$(CXX) $(CFLAGS) -c ast_while_stmt.cc

ast_else_stmt.o: ast_else_stmt.h ast_else_stmt.cc
	$(CXX) $(CFLAGS) -c ast_else_stmt.cc

ast_elif_stmt.o: ast_elif_stmt.h ast_elif_stmt.cc
	$(CXX) $(CFLAGS) -c ast_elif_stmt.cc

ast_elif_stmt_group.o: ast_elif_stmt_group.h ast_elif_stmt_group.cc
	$(CXX) $(CFLAGS) -c ast_elif_stmt_group.cc

ast_if_stmt.o: ast_if_stmt.h ast_if_stmt.cc
	$(CXX) $(CFLAGS) -c ast_if_stmt.cc

ast_lambda.o: ast_node.o ast_lambda.h ast_lambda.cc
	$(CXX) $(CFLAGS) -c ast_lambda.cc

ast_class_def.o: ast_class_def.h ast_class_def.cc
	$(CXX) $(CFLAGS) -c ast_class_def.cc

ast_task_state.o: ast_task_state.h ast_task_state.cc
	$(CXX) $(CFLAGS) -c ast_task_state.cc

ast_conditional_preposition.o: ast_conditional_preposition.h ast_conditional_preposition.cc
	$(CXX) $(CFLAGS) -c ast_conditional_preposition.cc

ast_conditional_clause.o: ast_conditional_clause.h ast_conditional_clause.cc
	$(CXX) $(CFLAGS) -c ast_conditional_clause.cc

ast_task_clause.o: ast_task_clause.h ast_task_clause.cc
	$(CXX) $(CFLAGS) -c ast_task_clause.cc

ast_start_clause.o: ast_start_clause.h ast_start_clause.cc
	$(CXX) $(CFLAGS) -c ast_start_clause.cc

ast_pause_clause.o: ast_pause_clause.h ast_pause_clause.cc
	$(CXX) $(CFLAGS) -c ast_pause_clause.cc

ast_delay_clause.o: ast_delay_clause.h ast_delay_clause.cc
	$(CXX) $(CFLAGS) -c ast_delay_clause.cc

ast_resume_clause.o: ast_resume_clause.h ast_resume_clause.cc
	$(CXX) $(CFLAGS) -c ast_resume_clause.cc

ast_cancel_clause.o: ast_cancel_clause.h ast_cancel_clause.cc
	$(CXX) $(CFLAGS) -c ast_cancel_clause.cc

ast_stop_clause.o: ast_stop_clause.h ast_stop_clause.cc
	$(CXX) $(CFLAGS) -c ast_stop_clause.cc

ast_task_def.o: ast_task_def.h ast_task_def.cc
	$(CXX) $(CFLAGS) -c ast_task_def.cc

ast_module.o: ast_module.h ast_module.cc
	$(CXX) $(CFLAGS) -c ast_module.cc

ast_expr_list.o: ast_expr_list.h ast_expr_list.cc
	$(CXX) $(CFLAGS) -c ast_expr_list.cc

ast_unary_expr.o: ast_expr.h ast_unary_expr.h ast_unary_expr.cc
	$(CXX) $(CFLAGS) -c ast_unary_expr.cc

ast_negative_expr.o: ast_unary_expr.o ast_negative_expr.h ast_negative_expr.cc
	$(CXX) $(CFLAGS) -c ast_negative_expr.cc

ast_positive_expr.o: ast_positive_expr.o ast_positive_expr.h ast_positive_expr.cc
	$(CXX) $(CFLAGS) -c ast_positive_expr.cc

ast_not_expr.o: ast_unary_expr.o ast_not_expr.h ast_not_expr.cc
	$(CXX) $(CFLAGS) -c ast_not_expr.cc

ast_bitwise_not_expr.o: ast_unary_expr.o ast_bitwise_not_expr.h ast_bitwise_not_expr.cc
	$(CXX) $(CFLAGS) -c ast_bitwise_not_expr.cc

ast_inc_expr.o: ast_unary_expr.o ast_inc_expr.h ast_inc_expr.cc
	$(CXX) $(CFLAGS) -c ast_inc_expr.cc

ast_dec_expr.o: ast_unary_expr.o ast_dec_expr.h ast_dec_expr.cc
	$(CXX) $(CFLAGS) -c ast_dec_expr.cc

ast_exitential_expr.o: ast_unary_expr.o ast_existential_expr.h ast_existential_expr.cc
	$(CXX) $(CFLAGS) -c ast_existential_expr.cc

ast_binary_expr.o: ast_expr.h ast_binary_expr.h ast_binary_expr.cc
	$(CXX) $(CFLAGS) -c ast_binary_expr.cc

ast_commutative_binary_expr.o: ast_binary_expr.o ast_commutative_binary_expr.h ast_commutative_binary_expr.cc
	$(CXX) $(CFLAGS) -c ast_commutative_binary_expr.cc

ast_and_expr.o: ast_commutative_binary_expr.o ast_and_expr.h ast_and_expr.cc
	$(CXX) $(CFLAGS) -c ast_and_expr.cc

ast_or_expr.o: ast_commutative_binary_expr.o ast_or_expr.h ast_or_expr.cc
	$(CXX) $(CFLAGS) -c ast_or_expr.cc

ast_bitwise_and_expr.o: ast_commutative_binary_expr.o ast_bitwise_and_expr.h ast_bitwise_and_expr.cc
	$(CXX) $(CFLAGS) -c ast_bitwise_and_expr.cc

ast_bitwise_or_expr.o: ast_commutative_binary_expr.o ast_bitwise_or_expr.h ast_bitwise_or_expr.cc
	$(CXX) $(CFLAGS) -c ast_bitwise_or_expr.cc

ast_bitwise_xor_expr.o: ast_commutative_binary_expr.o ast_bitwise_xor_expr.h ast_bitwise_xor_expr.cc
	$(CXX) $(CFLAGS) -c ast_bitwise_xor_expr.cc

ast_bitwise_shift_left_expr.o: ast_binary_expr.o ast_bitwise_shift_left_expr.h ast_bitwise_shift_left_expr.cc
	$(CXX) $(CFLAGS) -c ast_bitwise_shift_left_expr.cc

ast_bitwise_shift_right_expr.o: ast_binary_expr.o ast_bitwise_shift_right_expr.h ast_bitwise_shift_right_expr.cc
	$(CXX) $(CFLAGS) -c ast_bitwise_shift_right_expr.cc

ast_power_expr.o: ast_binary_expr.o ast_power_expr.h ast_power_expr.cc
	$(CXX) $(CFLAGS) -c ast_power_expr.cc

ast_add_expr.o: ast_commutative_binary_expr.o ast_add_expr.h ast_add_expr.cc
	$(CXX) $(CFLAGS) -c ast_add_expr.cc

ast_minus_expr.o: ast_binary_expr.o ast_minus_expr.h ast_minus_expr.cc
	$(CXX) $(CFLAGS) -c ast_minus_expr.cc

ast_multiply_expr.o: ast_commutative_binary_expr.o ast_multiply_expr.h ast_multiply_expr.cc
	$(CXX) $(CFLAGS) -c ast_multiply_expr.cc

ast_divide_expr.o: ast_binary_expr.o ast_divide_expr.h ast_divide_expr.cc
	$(CXX) $(CFLAGS) -c ast_divide_expr.cc

ast_mod_expr.o: ast_binary_expr.o ast_mod_expr.h ast_mod_expr.cc
	$(CXX) $(CFLAGS) -c ast_mod_expr.cc

ast_eq_expr.o: ast_commutative_binary_expr.o ast_eq_expr.h ast_eq_expr.cc
	$(CXX) $(CFLAGS) -c ast_eq_expr.cc

ast_neq_expr.o: ast_commutative_binary_expr.o ast_neq_expr.h ast_neq_expr.cc
	$(CXX) $(CFLAGS) -c ast_neq_expr.cc

ast_is_expr.o: ast_commutative_binary_expr.o ast_is_expr.h ast_is_expr.cc
	$(CXX) $(CFLAGS) -c ast_is_expr.cc

ast_is_not_expr.o: ast_commutative_binary_expr.o ast_is_not_expr.h ast_is_not_expr.cc
	$(CXX) $(CFLAGS) -c ast_is_not_expr.cc

ast_lt_expr.o: ast_binary_expr.o ast_lt_expr.h ast_lt_expr.cc
	$(CXX) $(CFLAGS) -c ast_lt_expr.cc

ast_le_expr.o: ast_binary_expr.o ast_le_expr.h ast_le_expr.cc
	$(CXX) $(CFLAGS) -c ast_le_expr.cc

ast_gt_expr.o: ast_binary_expr.o ast_gt_expr.h ast_gt_expr.cc
	$(CXX) $(CFLAGS) -c ast_gt_expr.cc

ast_ge_expr.o: ast_binary_expr.o ast_ge_expr.h ast_ge_expr.cc
	$(CXX) $(CFLAGS) -c ast_ge_expr.cc

ast_in_expr.o: ast_binary_expr.o ast_in_expr.h ast_in_expr.cc
	$(CXX) $(CFLAGS) -c ast_in_expr.cc

ast_not_in_expr.o: ast_binary_expr.o ast_not_in_expr.h ast_not_in_expr.cc
	$(CXX) $(CFLAGS) -c ast_not_in_expr.cc

ast_in_range_expr.o: ast_binary_expr.o ast_in_range_expr.h ast_in_range_expr.cc
	$(CXX) $(CFLAGS) -c ast_in_range_expr.cc

ast_ex_range_expr.o: ast_binary_expr.o ast_ex_range_expr.h ast_ex_range_expr.cc
	$(CXX) $(CFLAGS) -c ast_ex_range_expr.cc

ast_conditional_expr.o: ast_binary_expr.o ast_conditional_expr.h ast_conditional_expr.cc
	$(CXX) $(CFLAGS) -c ast_conditional_expr.cc

ast_yield_expr.o: ast_expr.h ast_expr_list.o  ast_yield_expr.h ast_yield_expr.cc
	$(CXX) $(CFLAGS) -c ast_yield_expr.cc

ast_string_expr.o: ast_expr.h ast_expr_list.o ast_string_expr.h ast_string_expr.cc
	$(CXX) $(CFLAGS) -c ast_string_expr.cc

ast_paren_form.o: ast_paren_form.o ast_paren_form.cc
	$(CXX) $(CFLAGS) -c ast_paren_form.cc

ast_pseudo_assign_expr.o: ast_binary_expr.o ast_pseudo_assign_expr.h ast_pseudo_assign_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_expr.cc

ast_pseudo_assign_plus_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_plus_expr.h ast_pseudo_assign_plus_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_plus_expr.cc

ast_pseudo_assign_minus_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_minus_expr.h ast_pseudo_assign_minus_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_minus_expr.cc

ast_pseudo_assign_mul_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_mul_expr.h ast_pseudo_assign_mul_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_mul_expr.cc

ast_pseudo_assign_div_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_div_expr.h ast_pseudo_assign_div_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_div_expr.cc

ast_pseudo_assign_mod_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_mod_expr.h ast_pseudo_assign_mod_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_mod_expr.cc

ast_pseudo_assign_bitwise_and_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_and_expr.h ast_pseudo_assign_bitwise_and_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_bitwise_and_expr.cc

ast_pseudo_assign_bitwise_or_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_or_expr.h ast_pseudo_assign_bitwise_or_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_bitwise_or_expr.cc

ast_pseudo_assign_bitwise_xor_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_xor_expr.h ast_pseudo_assign_bitwise_xor_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_bitwise_xor_expr.cc

ast_pseudo_assign_bitwise_left_shift_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_left_shift_expr.h ast_pseudo_assign_bitwise_left_shift_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_bitwise_left_shift_expr.cc

ast_pseudo_assign_bitwise_right_shift_expr.o: ast_pseudo_assign_expr.o ast_pseudo_assign_bitwise_right_shift_expr.h ast_pseudo_assign_bitwise_right_shift_expr.cc
	$(CXX) $(CFLAGS) -c ast_pseudo_assign_bitwise_right_shift_expr.cc

ast_primary.o: ast_expr.h ast_primary.h ast_primary.cc
	$(CXX) $(CFLAGS) -c ast_primary.cc

ast_identifier.o: ast_primary.o ast_identifier.h ast_identifier.cc
	$(CXX) $(CFLAGS) -c ast_identifier.cc

ast_literal.o: ast_primary.o ast_literal.h ast_literal.cc
	$(CXX) $(CFLAGS) -c ast_literal.cc

ast_integer_literal.o: ast_unparsed.o ast_literal.o ast_integer_literal.h ast_integer_literal.cc
	$(CXX) $(CFLAGS) -c ast_integer_literal.cc

ast_float_literal.o: ast_unparsed.o ast_literal.o ast_float_literal.h ast_float_literal.cc
	$(CXX) $(CFLAGS) -c ast_float_literal.cc

ast_string_literal.o: ast_unparsed.o ast_literal.o ast_string_literal.h ast_string_literal.cc
	$(CXX) $(CFLAGS) -c ast_string_literal.cc

ast_slicing.o: ast_slicing.h ast_slicing.cc
	$(CXX) $(CFLAGS) -c ast_slicing.cc

ast_call.o: ast_primary.o ast_call.h ast_call.cc
	$(CXX) $(CFLAGS) -c ast_call.cc

ast_attribute_ref.o: ast_primary.o ast_attribute_ref.h ast_attribute_ref.cc
	$(CXX) $(CFLAGS) -c ast_attribute_ref.cc

ast_hex_program.o: ast_hex_program.h ast_hex_program.cc
	$(CXX) $(CFLAGS) -c ast_hex_program.cc

ast.h:
	$(PY) ../../tools/headergen.py --path='./' --dest='ast.h'

obj:ast.h \
	examiner.o	\
	ast_unparsed.o	\
	ast_list_obj.o	\
	ast_node.o	\
	ast_target_list.o	\
	ast_val_list.o	\
	ast_simple_param.o \
	ast_simple_param_list.o	\
	ast_keyword_param.o \
	ast_keyword_param_list.o \
	ast_keyword_val.o	\
	ast_keyword_val_list.o	\
	ast_parameter_list.o	\
	ast_arg_list.o	\
	ast_comprehension.o	\
	ast_list_form.o	\
	ast_field_def.o	\
	ast_field_def_list.o	\
	ast_key_value_pair.o \
	ast_key_value_pair_list.o \
	ast_dict_form.o	\
	ast_name.o	\
	ast_decorator.o	\
	ast_decorator_list.o	\
	ast_assignment_stmt.o	\
	ast_using_src.o	\
	ast_using_stmt.o	\
	ast_stmt_group.o	\
	ast_await_stmt.o	\
	ast_return_stmt.o	\
	ast_break_stmt.o	\
	ast_continue_stmt.o	\
	ast_raise_stmt.o	\
	ast_input_stmt.o	\
	ast_output_stmt.o	\
	ast_expr_list_stmt.o	\
	ast_stmt.o \
	ast_simple_stmt.o \
	ast_compound_stmt.o	\
	ast_for_stmt.o	\
	ast_with_stmt.o	\
	ast_lock_stmt.o	\
	ast_catch_stmt.o	\
	ast_catch_stmt_group.o	\
	ast_try_stmt.o	\
	ast_while_stmt.o	\
	ast_else_stmt.o	\
	ast_elif_stmt.o	\
	ast_elif_stmt_group.o	\
	ast_if_stmt.o	\
	ast_lambda.o	\
	ast_class_def.o	\
	ast_task_state.o	\
	ast_conditional_preposition.o	\
	ast_conditional_clause.o	\
	ast_task_clause.o	\
	ast_start_clause.o	\
	ast_stop_clause.o	\
	ast_cancel_clause.o	\
	ast_resume_clause.o	\
	ast_pause_clause.o	\
	ast_delay_clause.o	\
	ast_task_def.o 	\
	ast_module.o	\
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
	ast_negative_expr.o	\
	ast_positive_expr.o \
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
	ast_is_not_expr.o \
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
	ast_paren_form.o	\
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
	ast_hex_program.o


libast.a: obj
	$(AR) $(ARFLAGS) libast.a *.o


all: libast.a

.PHONY : clean
clean:
	rm ast.h *.gch *.o *.a *.out *.test *.a
