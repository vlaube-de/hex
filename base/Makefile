#
# HEX Programming Language
# Copyright (C) 2012  Yanzheng Li
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

GTEST_INCLUDE=-I/usr/local/gtest-1.6.0/include
LIBGTEST=/usr/lib/libgtest.a

unittest.o: unittest.h unittest.cc
	$(CXX) $(GTEST_INCLUDE) -c unittest.h unittest.cc

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c utils.h

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c memory.h

array.o: array.c array.h
	$(CC) $(CFLAGS) -c array.c array.h

all: unittest.o \
	 utils.o    \
	 memory.o   \
	 array.o

clean:
	rm *.gch *.o *.a *.out *.test