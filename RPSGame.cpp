/******************************************************************************
** Program name: RPSGame.cpp
** Author: Zach Morrissey
** Date: 02/19/2017
** Description: Container class for the RockPaperScissors game.
******************************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>
#include "mainHeader.hpp"

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
    Description: Prompts the user to choose tools for human and CPU players
    */
    std::string strInput;
    bool isOk = false;
    int choice;

    // Display menu to the user.
    std::cout << "\n";
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
    bool isOk = false;

    std::cout << "\n";
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
            std::cout << "\n";
            std::cout << "Sorry - not a valid option." << std::endl;
            std::cout << "\n";
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
            std::cout << "\n";
            std::cout << "Choose " << humanOrComputer << "'s custom strength. Must be larger than 0." << std::endl;
            std::cout << "Enter: ";
            std::cin >> strInput;

            // convert string to int for choice.
            choice = std::stoi(strInput);

            if (choice >= 1) {
                isOk = true;
            } else {
                std::cout << "\n";
                std::cout << "Sorry! Needs to be higher than 1." << std::endl;
            }
        }
        catch (const std::invalid_argument& i) {
            std::cout << "\n";
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
    bool isOk = false;

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
    // if round = 1, do this                                    // Beau **
    // else use saved var for strength                          // Beau **
    int humanToolChoice, computerToolChoice, humanStrength, computerStrength; // Beau **
    int rememberHumanStrength = humanStrength;          // this will remember the strength   Beau **
    int rememberCompStrength = computerStrength;        // this will remember the strength   Beau **
    bool hasNonDefaultStrength;
    std::string outcome;

    if (roundNumber == 1) // Beau **
    {
        humanStrength = -1; // Beau **
        computerStrength = -1; // Beau **
    }

    // display tool selection menus.
    humanToolChoice = displayToolMenu();
    computerToolChoice = computerPick();

    // Ask the user if they want non-default strength and get values if yes.
    // do this for round 1, save results for later // Beau **
    if (roundNumber == 1)
    {
        hasNonDefaultStrength = displayIsNonDefaultMenu();
        if (hasNonDefaultStrength) {
            humanStrength = displayStrengthMenu("human");
            computerStrength = displayStrengthMenu("computer");
        }
        // Remember the strength choices from first round // Beau **
        rememberHumanStrength = humanStrength; // Beau **
        rememberCompStrength = computerStrength; // Beau **


        // Ask the user if they want to have non-default strength for any of the tools.
        createTool("human", humanToolChoice, humanStrength);
        createTool("computer", computerToolChoice, computerStrength);
    }
    else
    {
        createTool("human", humanToolChoice, rememberHumanStrength); // Beau **
        createTool("computer", computerToolChoice, rememberCompStrength); // Beau **
    }

    // Fight the tools.
    outcome = humanTool->fight(computerTool);

    // Print the results.
    std::cout << "You picked ";
    humanTool->printTool();

    std::cout << "Computer picked ";
    computerTool->printTool();
    std::cout << std::endl;

    // Allocate wins.
    std::cout << "\n";
    if (outcome == "win") {
        std::cout << "You won!" << std::endl;
        numHumanWins++;
    } else if (outcome == "loss") {
        std::cout << "The computer won." << std::endl;
        numComputerWins++;
    } else {
        std::cout << "It was a tie!" << std::endl;
        numTies++;
    }

    // Display the current stats.
    std::cout << "\nCurrent Score after " << roundNumber << " round(s):" << std::endl;
    std::cout << "You: " << numHumanWins << ", ";
    std::cout << "Computer: " << numComputerWins << ", ";
    std::cout << "Ties: " << numTies << std::endl;
    std::cout << "\n";

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
    bool playAgain = false;

    do {
        playRound();
        playAgain = displayPlayAgainMenu();
    } while (playAgain);
    std::cout << "\n";
    std::cout << "Thanks for playing! GoodBye!" << std::endl;
    std::cout << "\n";
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
