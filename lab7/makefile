# Makefile for lab 7

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Queue.cpp Menu.cpp

HEADERS = Queue.hpp Menu.hpp

OBJS = main.o Queue.o Menu.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
