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
    int numHumanWins;
    int numComputerWins;
    int numTies;
    int roundNumber;
    Tool *humanTool;
    Tool *computerTool;
    int displayToolMenu();
    bool displayIsNonDefaultMenu();
    int displayStrengthMenu(std::string humanOrComputer);
    bool displayPlayAgainMenu();
    int computerPick();
    void createTool(std::string humanOrComputer, int menuChoice, int nonDefaultStrength);
    void playRound();
public:
    RPSGame();
    void gameSequence();
    int getNumTies();
    int getNumHumanWins();
    int getNumComputerWins();
    ~RPSGame();
};

#endif
