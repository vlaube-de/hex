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
CFLAGS=-Wno-implicit -w -g -arch x86_64

GTEST_INCLUDE=-I/usr/local/gtest-1.6.0/include
LIBGTEST=/usr/lib/libgtest.a
LIBBASE=../../base/libbase.a
LIBAST=../ast/libast.a

LIBRARIES=$(LIBGTEST) $(LIBAST) $(LIBBASE)

OBJECTS=../hex_parser.o \
		../ast/visitor/ast_visitor.o \
		../ast/visitor/ast_tostring_visitor.o \
		../ast/visitor/ast_to_xml_visitor.o


SOURCES=../lex.yy.c ../parser.tab.cc

parser_repr_test.test: parser_repr_test.cc
	$(CXX) $(CFLAGS) $(LIBRARIES) $(OBJECTS) $(SOURCES) parser_repr_test.cc -o parser_repr_test.test

parser_xml_test.test: parser_xml_test.cc
	$(CXX) $(CFLAGS) $(LIBRARIES) $(OBJECTS) $(SOURCES) parser_xml_test.cc -o parser_xml_test.test

all: parser_repr_test.test \
	 parser_xml_test.test

clean:
	rm *.gch *.o *.a *.out *.test