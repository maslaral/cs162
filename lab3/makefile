# Makefile for lab 2 

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp LoadedDie.cpp Die.cpp Game.cpp Menu.cpp

HEADERS = LoadedDie.hpp Die.hpp Game.hpp Menu.hpp

OBJS = main.o LoadedDie.o Die.o Game.o Menu.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
