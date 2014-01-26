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
CFLAGS=-Wno-implicit -w -g -std=c++11 -arch x86_64

AR=ar
ARFLAGS=rvs

ascii_box_generator.o: ascii_box_generator.cc
		$(CXX) $(CFLAGS) -c ascii_box_generator.cc

fixed_length_string_builder.o: fixed_length_string_builder.cc
		$(CXX) $(CFLAGS) -c fixed_length_string_builder.cc

quadruple_code_vector_generator.o: quadruple_code_vector_generator.cc
		$(CXX) $(CFLAGS) -c quadruple_code_vector_generator.cc

hex_object_block_generator.o: hex_object_block_generator.cc
		$(CXX) $(CFLAGS) -c hex_object_block_generator.cc

hex_compilation_unit_metadata.o: hex_compilation_unit_metadata.cc
		$(CXX) $(CFLAGS) -c hex_compilation_unit_metadata.cc

hex_bytecode_generator.o: hex_bytecode_generator.cc
		$(CXX) $(CFLAGS) -c hex_bytecode_generator.cc

_libcodegen.a:
		$(AR) $(ARFLAGS) _libcodegen.a *.o

all: ascii_box_generator.o \
		 fixed_length_string_builder.o \
		 quadruple_code_vector_generator.o \
		 hex_object_block_generator.o \
		 hex_compilation_unit_metadata.o \
		 hex_bytecode_generator.o \
		 _libcodegen.a


.PHONY : clean
clean:
	rm *.gch *.out *.o *.a