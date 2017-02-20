/******************************************************************************
** Program name: Rock.hpp
** Author: Zach Morrissey
** Date: 02/19/2017
** Description: Container class for the RockPaperScissors game.
******************************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>
#include "RPSGame.hpp"
#include "Tool.hpp"
#include "Scissors.hpp"
#include "Rock.hpp"
#include "Paper.hpp"


RPSGame::RPSGame() {
    /*
    Description: Default constructor.
    */
    humanNumWins = 0;
    computerNumWins = 0;
    numTies = 0;
    Tool *humanTool = 0;
    Tool *computerTool = 0;
}


int RPSGame::displayMenu() {
    /*
    Description: Takes a list of list to display and prompts the user to choose a value for them.
    */  

    int choice;
    std::cout << "Please make your selection of tool:" << std::endl;
    std::cout << "1. Rock" << std::endl;
    std::cout << "2. Paper" << std::endl;
    std::cout << "3. Scissors" << std::endl;

    choice = getInput();

    return choice;
}


int RPSGame::getInput() {
    /*
    Description: Prompts the user to enter an integer between the max and min.
    Recycling the logic from Lab 5 piazza discussion.
    */  

    int choice;
    std::string strInput;
    bool isOk = false;

    while (!(isOk)) {
        try {
            std::cout << "Enter your choice: ";
            std::cin >> strInput;

            choice = std::stoi(strInput);

            if (choice >= 1 && choice <= 3) {
                isOk = true;
            } else {
                std::cout << "Sorry! Needs to be a choice of one of the tools available." << std::endl;
            }
        }
        catch (const std::invalid_argument& i) {
            std::cout << "Sorry. Looks like that wasn't a valid number." << std::endl;
        }
    }

    return choice;
}


int RPSGame::computerPick() {
    /*
    Description: Returns a random integer for the computer's choice of tool.
    TODO: If somebody wants to create a better, smarter version of this, they totally can.
    */
    return (rand() % 3) + 1;
}


void RPSGame::gameSequence() {
    /*
    Description: Goes through and plays the game itself.
    */
    int out = displayMenu();
    int compOut = computerPick();
    std::cout << "User chooses " << out << std::endl;
    std::cout << "computer chooses " << compOut << std::endl;
}


RPSGame::~RPSGame() {
    /*
    Description: Destructor. If the tools are set, deletes the tools.
    This the only dynamically allocated memory in the class.
    */

    if (humanTool != 0) {
        delete humanTool;
        humanTool = 0;
    }
    if (computerTool != 0) {
        delete computerTool;
        computerTool = 0;
    }
}
