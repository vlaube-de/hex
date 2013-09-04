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

ast_visitor.o: ast_visitor.h ast_visitor.cc
	$(CXX) -c ast_visitor.cc

all: ast_visitor.o

clean:
	rm *.gch *.out *.o *.swp *.a
