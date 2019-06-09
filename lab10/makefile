# Makefile for lab 10

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Fibonacci_NR.cpp Fibonacci_R.cpp Menu.cpp

HEADERS = Fibonacci_NR.hpp Fibonacci_R.hpp Menu.hpp

OBJS = main.o Fibonacci_NR.o Fibonacci_R.o Menu.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
