/******************************************************************************
** Program name: Rock.hpp
** Author: Zach Morrissey
** Date: 02/19/2017
** Description: Container class for the RockPaperScissors game.
******************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include <string>

class RPSGame {
private:
    int humanNumWins;
    int computerNumWins;
    int numTies;
    Tool *humanTool;
    Tool *computerTool;
    int getInt(int min, int max);
    int displayMenu(std::string lines[], int numLines);
public:
    RPSGame();
    RPSGame(Tool *humanToolChoice, Tool *computerToolChoice);
    void gameSequence();
    int computerPick();
    ~RPSGame();
};

#endif
