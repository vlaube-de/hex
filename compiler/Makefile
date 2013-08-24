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

CXX=g++
CFLAGS=-Wno-implicit -w -g -arch x86_64

LEX=lex
BISON=bison

ast:
	cd ast/ && make all

ast.h:
	cp ../tools/headergen.py ./ && python headergen.py --path='./ast/' --dest='ast.h' && rm headergen.py

lex.yy.c: lexer.l
	$(LEX) lexer.l

parser.tab.hh: parser.y
	$(BISON) -y -d -t -v -g parser.y -o parser.tab.cc

hex_parser.o: ast.h lex.yy.c parser.tab.hh hex_parser.cc
	$(CXX) $(CFLAGS) -c hex_parser.cc

parser_stub.out: ast hex_parser.o parser_stub.cc
	$(CXX) $(CFLAGS) ast/libast.a lex.yy.c parser.tab.cc parser_stub.cc hex_parser.o -o parser_stub.out

all: lex.yy.c       \
	 parser.tab.hh    \
	 ast.h            \
	 hex_parser.o     \
	 parser_stub.out


clean:
	rm *.gch *.out *.o *.swp .lexer.l.swp *.output *.vcg *.test parser.tab.cc parser.tab.hh ast.h
