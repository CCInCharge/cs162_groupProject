/******************************************************************************
** Program name: Rock.hpp
** Author: Zach Morrissey
** Date: 02/19/2017
** Description: Container class for the RockPaperScissors game.
******************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include <string>
#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"

class RPSGame {
private:
    int humanNumWins;
    int computerNumWins;
    int numTies;
    Tool *humanTool;
    Tool *computerTool;
    int getInput();
    int displayMenu();
    int computerPick();
public:
    RPSGame();
    void gameSequence();
    ~RPSGame();
};

#endif
