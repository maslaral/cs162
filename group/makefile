# Program name: makefile
# Author: Group 1 
# Date: May 11 2019 
# Description: This is the makefile for the Group Project.

CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -pedantic-errors
LDFLAGS = -lboost_date_time
OBJS = ${SRCS:.cpp=.o}
SRCS =  Game.cpp Main.cpp Critter.cpp Ant.cpp Doodlebug.cpp 
HEADERS = Game.hpp Critter.hpp Ant.hpp Doodlebug.hpp enum_kind.hpp enum_direction.hpp

main:${OBJS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp} 

clean:
	rm *.o main

zip:
	zip -D Group_Project_Group_1.zip *.cpp *.hpp *.pdf makefile

val:
	valgrind main --leak-check=full./main
