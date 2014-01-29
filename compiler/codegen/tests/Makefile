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
CFLAGS=-Wno-implicit -w -g -std=c++11 -arch x86_64 -DGTEST_HAS_TR1_TUPLE=0
LIBGTEST=/usr/lib/libgtest.a
LIBBASE=../../../base/_libbase.a
LIBAST=../../ast/libast.a
LIBCODEGEN=../_libcodegen.a
LIBS= $(LIBGTEST) $(LIBBASE) $(LIBAST) $(LIBCODEGEN)

base:
		cd ../../../base && make all
		cd ../ && make all

fixed_length_string_builder_unittest.test: base fixed_length_string_builder_unittest.cc
		$(CXX) $(CFLAGS) $(LIBS) fixed_length_string_builder_unittest.cc -o fixed_length_string_builder_unittest.test

ascii_box_generator_unittest.test: base ascii_box_generator_unittest.cc
		$(CXX) $(CFLAGS) $(LIBS) ascii_box_generator_unittest.cc -o ascii_box_generator_unittest.test

quadruple_code_vector_generator_unittest.test: base quadruple_code_vector_generator_unittest.cc
		$(CXX) $(CFLAGS) $(LIBS) quadruple_code_vector_generator_unittest.cc -o quadruple_code_vector_generator_unittest.test

hex_object_block_generator_unittest.test: base hex_object_block_generator_unittest.cc
		$(CXX) $(CFLAGS) $(LIBS) hex_object_block_generator_unittest.cc -o hex_object_block_generator_unittest.test

hex_compilation_unit_metadata_unittest.test: hex_object_block_generator_unittest.cc
		$(CXX) $(CFLAGS) $(LIBS) hex_compilation_unit_metadata_unittest.cc -o hex_compilation_unit_metadata_unittest.test

hex_bytecode_generator_unittest.test: hex_bytecode_generator_unittest.cc
		$(CXX) $(CFLAGS) $(LIBS) hex_bytecode_generator_unittest.cc -o hex_bytecode_generator_unittest.test

all: fixed_length_string_builder_unittest.test \
		 ascii_box_generator_unittest.test \
		 quadruple_code_vector_generator_unittest.test \
		 hex_object_block_generator_unittest.test \
		 hex_compilation_unit_metadata_unittest.test \
		 hex_bytecode_generator_unittest.test


.PHONY : clean
clean:
		rm *.gch *.o *.a *.out *.test