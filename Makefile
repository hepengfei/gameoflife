# ====== header start =======

CPPFLAGS=-Wall -ggdb -I../gtest-1.7.0/include
LDFLAGS=-L../gtest-1.7.0/lib/.libs

CC=gcc
CXX=g++
AR=ar

%.o:%.c
	$(CC) -c -o $@ $(CPPFLAGS) $<

%.o:%.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $<

SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

.PHONY: test

# ====== header end ======

test:life_test.o life.o
	$(CXX) -o $@ $^ $(LDFLAGS) -lgtest -lgtest_main
	./test

