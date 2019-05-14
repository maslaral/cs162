# Makefile for lab 2 

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp Building.cpp Instructor.cpp Person.cpp Student.cpp University.cpp Menu.cpp

HEADERS = Building.hpp Instructor.hpp Person.hpp Student.hpp University.hpp Menu.hpp

OBJS = main.o Building.o Instructor.o Person.o Student.o University.o Menu.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
