# Makefile for project 4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Menu.cpp Barbarian.cpp Game.cpp roll_die.cpp Vampire.cpp Blue_Men.cpp Medusa.cpp Harry_Potter.cpp Winner_Queue.cpp Character.cpp Loser_Stack.cpp

HEADERS = Menu.hpp Barbarian.hpp Character.hpp character_type.hpp Game.hpp roll_die.hpp Vampire.hpp Blue_Men.hpp Medusa.hpp Harry_Potter.hpp Winner_Queue.hpp Character.hpp Loser_Stack.hpp

OBJS = main.o Menu.o Barbarian.o Game.o roll_die.o Vampire.o Blue_Men.o Medusa.o Harry_Potter.o Winner_Queue.o Character.o Loser_Stack.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
