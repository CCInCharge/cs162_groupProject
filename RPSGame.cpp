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
    Description: Default constructor. Initialize variables and set pointers to 0.
    */
    numHumanWins = 0;
    numComputerWins = 0;
    numTies = 0;
    roundNumber = 1;
    Tool *humanTool = 0;
    Tool *computerTool = 0;
}



int RPSGame::displayToolMenu() {
    /*
    Description: Takes a list of list to display and prompts the user to choose a value for them.
    */  
    std::string strInput;
    bool isOk = false;
    int choice;

    // Display menu to the user.
    std::cout << "Please make your selection of tool:" << std::endl;
    std::cout << "1. Rock" << std::endl;
    std::cout << "2. Paper" << std::endl;
    std::cout << "3. Scissors" << std::endl;

    while (!(isOk)) {
        try {
            std::cout << "Enter your choice (1, 2, or 3): ";
            std::cin >> strInput;

            // Try to convert string to int.
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


bool RPSGame::displayIsNonDefaultMenu() {
    /*
    Description: Gets whether the user wants default strength or not.
    */
    char charChoice;
    char goodChars[] = "YyNn";
    bool isOk;

    std::cout << "Do you want to choose non-default strengths for each tool?" << std::endl;
    while (!(isOk)) {
        std::cin.ignore();
        std::cout << "Enter your choice (y / n): ";
        std::cin >> charChoice;

        // Loop through all of the acceptable characters and check to see if it is one of those.
        for (int i = 0; i < 4; i++) {
            if (charChoice == goodChars[i]) {
                isOk = true;
            }
        }

        // Prompt the user for another entry if it's not OK.
        if (!(isOk)) {
            std::cout << "Sorry - not a valid option." << std::endl;
        }
    }

    // Return the truth value of whether they entered yes or not.
    return (charChoice == 'Y' || charChoice == 'y');
}



int RPSGame::displayStrengthMenu(std::string humanOrComputer) {
    /*
    Description: Prompts the user for the desired strength of their tools.
    */
    int choice;
    std::string strInput;
    bool isOk = false;

    while (!(isOk)) {
        try {
            std::cout << "Choose " << humanOrComputer << "'s custom strength. Must be larger than 0." << std::endl;
            std::cout << "Enter: ";
            std::cin >> strInput;

            // convert string to int for choice.
            choice = std::stoi(strInput);

            if (choice >= 1) {
                isOk = true;
            } else {
                std::cout << "Sorry! Needs to be higher than 1." << std::endl;
            }
        }
        catch (const std::invalid_argument& i) {
            std::cout << "Sorry. Looks like that wasn't a valid number." << std::endl;
        }
    }

    return choice;
}



bool RPSGame::displayPlayAgainMenu() {
    /*
    Description: Gets whether the user wants to play again or not.
    */
    /*
    Description: Gets whether the user wants default strength or not.
    */
    char charChoice;
    char goodChars[] = "YyNn";
    bool isOk;

    std::cout << "Do you want to play again?" << std::endl;
    while (!(isOk)) {
        std::cin.ignore();
        std::cout << "Enter your choice (y / n): ";
        std::cin >> charChoice;

        // Loop through all of the acceptable characters and check to see if it is one of those.
        for (int i = 0; i < 4; i++) {
            if (charChoice == goodChars[i]) {
                isOk = true;
            }
        }

        // Prompt the user for another entry if it's not OK.
        if (!(isOk)) {
            std::cout << "Sorry - not a valid option." << std::endl;
        }
    }

    // Return the truth value of whether they entered yes or not.
    return (charChoice == 'Y' || charChoice == 'y');
}



int RPSGame::computerPick() {
    /*
    Description: Returns a random integer for the computer's choice of tool.
    TODO: If somebody wants to create a better, smarter version of this, they totally can.
    */
    return (rand() % 3) + 1;
}



void RPSGame::createTool(std::string humanOrComputer, int menuChoice, int nonDefaultStrength) {
    /*
    Description: Takes the user's input from the displayMenu function
    and the strengthMenu and creates the tools accordingly.
    1 = Rock
    2 = Paper
    3 = Scissors
    */

    // For when the tools are default strength, nonDefault flag will equal -1.
    if (nonDefaultStrength == -1) {
        if (humanOrComputer == "human") {
            if (menuChoice == 1) {
                humanTool = new Rock();
            } else if (menuChoice == 2) {
                humanTool = new Paper();
            } else if (menuChoice == 3) {
                humanTool = new Scissors();
            }
        } else if (humanOrComputer == "computer") {
            if (menuChoice == 1) {
                computerTool = new Rock();
            } else if (menuChoice == 2) {
                computerTool = new Paper();
            } else if (menuChoice == 3) {
                computerTool = new Scissors();
            }
        }
    }
    else {
        if (humanOrComputer == "human") {
            if (menuChoice == 1) {
                humanTool = new Rock(nonDefaultStrength);
            } else if (menuChoice == 2) {
                humanTool = new Paper(nonDefaultStrength);
            } else if (menuChoice == 3) {
                humanTool = new Scissors(nonDefaultStrength);
            }
        } else if (humanOrComputer == "computer") {
            if (menuChoice == 1) {
                computerTool = new Rock(nonDefaultStrength);
            } else if (menuChoice == 2) {
                computerTool = new Paper(nonDefaultStrength);
            } else if (menuChoice == 3) {
                computerTool = new Scissors(nonDefaultStrength);
            }
        }
    }
}



void RPSGame::playRound() {
    /*
    Description: Displays menu, allocates weapons, and fights them.
    Deallocates weapons when done.
    */
    int humanToolChoice, computerToolChoice, humanStrength = -1, computerStrength = -1;
    bool hasNonDefaultStrength;
    std::string outcome;

    // display tool selection menus.
    humanToolChoice = displayToolMenu();
    computerToolChoice = computerPick();

    // Ask the user if they want non-default strength and get values if yes.
    hasNonDefaultStrength = displayIsNonDefaultMenu();
    if (hasNonDefaultStrength) {
        humanStrength = displayStrengthMenu("human");
        computerStrength = displayStrengthMenu("computer");
    }

    // Ask the user if they want to have non-default strength for any of the tools.
    createTool("human", humanToolChoice, humanStrength);
    createTool("computer", computerToolChoice, computerStrength);

    // Fight the tools.
    outcome = humanTool->fight(computerTool);

    // Allocate wins.
    if (outcome == "win") {
        numHumanWins++;
    } else if (outcome == "loss") {
        numComputerWins++;
    } else {
        numTies++;
    }

    // Clean up objects.
    if (humanTool != 0) {
        delete humanTool;
        humanTool = 0;
    }
    if (computerTool != 0) {
        delete computerTool;
        computerTool = 0;
    }

    // Increment round number.
    roundNumber++;
}



void RPSGame::gameSequence() {
    /*
    Description: Goes through and plays the game itself.
    */
    int humanStrength = 0, computerStrength = 0;
    int out = displayToolMenu();
    int compOut = computerPick();
    bool hasNonDefaultStrength, playAgain;

    hasNonDefaultStrength = displayIsNonDefaultMenu();
    if (hasNonDefaultStrength) {
        humanStrength = displayStrengthMenu("human");
        computerStrength = displayStrengthMenu("computer");
    }
    playAgain = displayPlayAgainMenu();

    std::cout << "User chooses " << out << std::endl;
    std::cout << "computer chooses " << compOut << std::endl;
    std::cout << "Non default strength? " << hasNonDefaultStrength << std::endl;
    std::cout << "Human strength: " << humanStrength << std::endl;
    std::cout << "Computer strength: " << computerStrength << std::endl;
    std::cout << "User wants to play again: " << playAgain << std::endl;
}



int RPSGame::getNumHumanWins() {
    /*
    Description: Getter for number of human wins.
    */
    return numHumanWins;
}


int RPSGame::getNumComputerWins() {
    /*
    Description: Getter for number of ties.
    */
    return numComputerWins;
}



int RPSGame::getNumTies() {
    /*
    Description: Getter for number of ties.
    */
    return numTies;
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
