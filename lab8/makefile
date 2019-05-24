# Makefile for lab 8

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp get_size.cpp create_array.cpp simple_search.cpp sort_array.cpp binary_search.cpp Menu.cpp

HEADERS = get_size.hpp create_array.hpp simple_search.hpp sort_array.hpp binary_search.hpp Menu.hpp

OBJS = main.o get_size.o create_array.o simple_search.o sort_array.o binary_search.o Menu.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
