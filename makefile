# Group Project makefile
# Author: Charles Chen
# Date: 02/19/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Paper.o Rock.o Scissors.o Tool.o RPSGame.o play_game.o cpuRPSTest.o
SRCS = Paper.cpp Rock.cpp Scissors.cpp Tool.cpp RPSGame.cpp play_game.cpp cpuRPSTest.cpp
MAINOBJS = Paper.o Rock.o Scissors.o Tool.o RPSGame.o play_game.o
MAINSRCS = Paper.cpp Rock.cpp Scissors.cpp Tool.cpp RPSGame.cpp play_game.cpp
TESTOBJS = Paper.o Rock.o Scissors.o Tool.o RPSGame.o cpuRPSTest.o
TESTSRCS = Paper.cpp Rock.cpp Scissors.cpp Tool.cpp RPSGame.cpp cpuRPSTest.cpp

all: ${MAINOBJS}
	${CXX} ${MAINOBJS} -o GroupProject

test: ${TESTOBJS}
	${CXX} ${TESTOBJS} -o test

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} GroupProject test
