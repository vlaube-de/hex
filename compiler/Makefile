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
CFLAGS=-Wno-implicit

CXX=g++
LIBGTEST=/usr/lib/libgtest.a

LEX=lex
BISON=bison




lex.yy.c: lexer.l
	$(LEX) lexer.l

parser.tab.h: parser.y
	$(BISON) -y -d -t -v -g parser.y -o parser.tab.h -o parser.tab.c

hex_parser.o: parser.tab.h hex_parser.c lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c hex_parser.c parser.tab.h parser.tab.c

parser_stub.out: hex_parser.o lex.yy.c parser_stub.c
	$(CC) $(CFLAGS) lex.yy.c parser.tab.c parser_stub.c hex_parser.o -o parser_stub.out

all: lex.yy.c 			\
	 parser.tab.h   	\
	 hex_parser.o   	\
	 parser_stub.out


clean:
	rm *.gch *.out *.o *.swp .lexer.l.swp *.output *.vcg *.test parser.tab.c parser.tab.h