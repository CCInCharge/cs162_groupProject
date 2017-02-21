/******************************************************************************
** Program name: testTools.cpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Tool.hpp"
#include "Paper.hpp"
#include "Rock.hpp"
#include "Scissors.hpp"
#include "RPSGame.hpp"

int main() {
    RPSGame game = RPSGame();
    game.gameSequence();

    return 0;
}
