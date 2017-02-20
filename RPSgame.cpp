/******************************************************************************
** Program name: Rock.hpp
** Author: Zach Morrissey
** Date: 02/19/2017
** Description: Container class for the RockPaperScissors game.
******************************************************************************/

#include "RPSGame.hpp"
#include "Tool.hpp"
#include "Scissors.hpp"
#include "Rock.hpp"
#include "Paper.hpp"


RPSGame::RPSGame() {
    /*
    Description: Default constructor.
    */
}




int RPSGame::displayMenu(std::string lines[], int numLines) {
    /*
    Description: Takes a list of list to display and prompts the user to choose a value for them.
    */  

    int choice;

    // Loop indefinitely until the user enters a valid Id.
    for (int x = 0; x < numLines; x++) {
        std::cout << lines[x] << std::endl;
    }
    choice = getInt(1, numLines);

    return choice;
}