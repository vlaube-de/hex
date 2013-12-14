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

ast_unparsed.o: ast_unparsed.h ast_unparsed.cc
	$(CXX) $(CFLAGS) -c ast_unparsed.cc

ast_literal.o: ast_literal.h ast_literal.cc
	$(CXX) $(CFLAGS) -c ast_literal.cc

ast_hex_program.o: ast_hex_program.h ast_hex_program.cc
	$(CXX) $(CFLAGS) -c ast_hex_program.cc

ast.h:
	$(PY) ../../tools/headergen.py --path='./' --dest='ast.h'

obj: ast.h 							\
		 ast_node.h 				\
		 ast_list_obj.h 		\
		 ast_unparsed.o			\
		 ast_hex_program.o

libast.a: obj
	$(AR) $(ARFLAGS) libast.a *.o

all: libast.a

.PHONY : clean
clean:
	rm ast.h *.gch *.o *.a *.out *.test *.a