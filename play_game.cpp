/******************************************************************************
** Program name: testTools.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

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
    Tool* tool1;
    Tool* tool2;
    tool1 = new Scissors;
    tool2 = new Scissors;

    std::cout << tool1->fight(tool2) << std::endl;

    RPSGame game = RPSGame();
    game.gameSequence();

    delete tool1;
    delete tool2;
    return 0;
}
