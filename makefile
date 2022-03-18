# MakeFile #

#target: dependencies
#	action

CC = clang++
CPPFLAGS = -std=c++11 -stdlib=libc++ -Weverything

test: test.o hashtable.o
	$(CC) $(CPPFLAGS) test.o hashtable.o -o Test

test.o: test.cpp
	$(CC) $(CPPFLAGS) -c test.cpp

hashtable.o: hashtable.cpp hashtable.hpp
	$(CC) $(CPPFLAGS) -c hashtable.cpp

clean: 
	rm -f *.o Test
