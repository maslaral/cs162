# Makefile for lab 2 

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Menu.cpp print_reverse.cpp sum_array.cpp triangular_number.cpp 

HEADERS = Menu.hpp print_reverse.hpp sum_array.hpp triangular_number.hpp 

OBJS = main.o Menu.o print_reverse.o sum_array.o triangular_number.o 

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
