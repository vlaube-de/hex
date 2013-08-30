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

CC=cc
CXX=c++
CFLAGS=-Wno-implicit -Wall -arch x86_64

GTEST_INCLUDE=-I/usr/local/gtest-1.6.0/include
LIBGTEST=/usr/lib/libgtest.a

unittest.o: unittest.h unittest.cc
	$(CXX) $(GTEST_INCLUDE) -c unittest.h unittest.cc

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c utils.h

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c memory.h

strutils.o: strutils.c strutils.h utils.h 
	$(CC) $(CFLAGS) -c strutils.c strutils.h

cutils.o: cutils.h cutils.c 
	$(CC) $(CFLAGS) -c cutils.c cutils.h

uuid.o: uuid.h uuid.c
	$(CC) $(CLAFGS) -c uuid.c uuid.h

buffer.o: buffer.c buffer.h
	$(CC) $(CFLAGS) -c buffer.c buffer.h

hash.o: hash.h hash.c utils.h
	$(CC) $(CFLAGS) -c hash.h hash.c

strbuf.o: strbuf.c strbuf.h
	$(CC) $(CFLAGS) -c strbuf.c strbuf.h

array.o: array.c array.h
	$(CC) $(CFLAGS) -c array.c array.h

hashmap.o: hashmap.c hashmap.h
	$(CC) $(CFLAGS) -c hashmap.c hashmap.h

dict.o: dict.c dict.h
	$(CC) $(CFLAGS) -c dict.c dict.h

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c stack.h

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c queue.h

bitmap.o: bitmap.h bitmap.c
	$(CC) $(CFLAGS) -c bitmap.h bitmap.c

bst.o: bst.h bst.c
	$(CC) $(CFLAGS) -c bst.h bst.c

all: unittest.o \
	 utils.o    \
	 memory.o   \
	 strutils.o \
	 cutils.o   \
	 buffer.o   \
	 uuid.o     \
	 hash.o     \
	 strbuf.o   \
	 array.o    \
	 hashmap.o  \
	 dict.o     \
	 stack.o    \
	 queue.o    \
	 bitmap.o   \
	 bst.o

clean:
	rm *.gch *.o *.a *.out *.test
