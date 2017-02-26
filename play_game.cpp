/******************************************************************************
** Program name: play_game.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Sets up a rock paper scissors game, which can be be played against the
computer.

To compile:
make

To run:
./GroupProject

Also comes with test utilities to ensure that the computer's pick for rock,
paper, or scissors is random.

To compile these test utilities:
make test

To run these test utilities:
./test
******************************************************************************/

#include <iostream>
#include <string>
#include "mainHeader.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>



int main() {
    std::srand(std::time(NULL));
    RPSGame game = RPSGame();
    game.gameSequence();
    return 0;
}
