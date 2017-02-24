# Group Project makefile
# Author: Charles Chen
# Date: 02/19/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Paper.o Rock.o Scissors.o Tool.o RPSGame.o play_game.o
SRCS = Paper.cpp Rock.cpp Scissors.cpp Tool.cpp RPSGame.cpp play_game.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o GroupProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} GroupProject
