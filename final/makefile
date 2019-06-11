# Makefile for lab 9

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Game.cpp Office.cpp Desk.cpp Inbox.cpp Player.cpp Employee.cpp Break_Room.cpp Menu.cpp

HEADERS = Game.hpp Office.hpp Desk.hpp Inbox.hpp Player.hpp Employee.hpp Break_Room.hpp Menu.hpp

OBJS = main.o Office.o Desk.o Game.o Inbox.o Player.o Employee.o Break_Room.o Menu.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
