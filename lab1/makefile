# Makefile for the lab 1 assigment

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = main.cpp readMatrix.cpp calcDeterminant.cpp

HEADERS = readMatrix.hpp calcDeterminant.hpp

OBJS = main.o readMatrix.o calcDeterminant.o

main: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main
