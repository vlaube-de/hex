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
CXX=c++
CFLAGS=-Wno-implicit -Wall -arch x86_64 -DGTEST_HAS_TR1_TUPLE=0

GTEST_INCLUDE=-I/usr/local/gtest-1.6.0/include
LIBGTEST=/usr/lib/libgtest.a


base:
	cd ../ && make all

assert_unittest.test: base assert_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../unittest.o assert_unittest.cc -o assert_unittest.test

utils_unittest.test: base utils_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../unittest.o utils_unittest.cc -o utils_unittest.test

memory_unittest.test: base memory_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../memory.o ../unittest.o memory_unittest.cc -o memory_unittest.test

strutils_unittest.test: base strutils_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../unittest.o ../strutils.o strutils_unittest.cc -o strutils_unittest.test

cutils_unittest.test: base cutils_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../cutils.o ../unittest.o cutils_unittest.cc -o cutils_unittest.test

buffer_unittest.test: base buffer_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../buffer.o ../unittest.o buffer_unittest.cc -o buffer_unittest.test

uuid_unittest.test: base uuid_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../uuid.o ../hash.o ../unittest.o uuid_unittest.cc -o uuid_unittest.test

hash_unittest.test: base hash_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../hash.o ../unittest.o hash_unittest.cc -o hash_unittest.test

strbuf_unittest.test: base strbuf_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../strbuf.o ../unittest.o strbuf_unittest.cc -o strbuf_unittest.test

array_unittest.test: base array_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../array.o ../unittest.o array_unittest.cc -o array_unittest.test

hashmap_unittest.test: base hashmap_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../hash.o ../hashmap.o ../unittest.o hashmap_unittest.cc -o hashmap_unittest.test

dict_unittest.test: base dict_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../utils.o ../hash.o ../dict.o ../hashmap.o ../unittest.o dict_unittest.cc -o dict_unittest.test

stack_unittest.test: base stack_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../stack.o ../unittest.o stack_unittest.cc -o stack_unittest.test

queue_unittest.test: base queue_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../queue.o ../unittest.o queue_unittest.cc -o queue_unittest.test

bitmap_unittest.test: base bitmap_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../bitmap.o ../utils.o ../unittest.o bitmap_unittest.cc -o bitmap_unittest.test

bst_unittest.test: base bst_unittest.cc
	$(CXX) $(CFLAGS) $(LIBGTEST) ../bst.o ../unittest.o bst_unittest.cc -o bst_unittest.test

all: assert_unittest.test	\
	 utils_unittest.test	\
	 memory_unittest.test	\
	 strutils_unittest.test	\
	 cutils_unittest.test  	\
	 buffer_unittest.test 	\
	 uuid_unittest.test 	\
	 hash_unittest.test 	\
	 strbuf_unittest.test 	\
	 array_unittest.test 	\
	 hashmap_unittest.test 	\
	 dict_unittest.test 	\
	 stack_unittest.test 	\
	 queue_unittest.test 	\
	 bitmap_unittest.test 	\
	 bst_unittest.test


clean:
	rm *.gch *.o *.a *.out *.test
