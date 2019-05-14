# Makefile for project 1

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Zoo.cpp Tiger.cpp Menu.cpp Animal.cpp Penguin.cpp Turtle.cpp

HEADERS = Zoo.hpp Tiger.hpp Menu.hpp Animal.hpp Penguin.hpp Turtle.hpp

OBJS = main.o Zoo.o Tiger.o Menu.o Animal.o Penguin.o Turtle.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
