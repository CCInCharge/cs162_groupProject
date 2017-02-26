/******************************************************************************
** Program name: cpuRPSTest.cpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:
Test function for the computer's rolls of Rock/Paper/Scissors. Intended to
test if the computer's rolls are reasonably random.

To compile:
make test

To run:
./test
******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

int computerPick() {
    /*
    Description: Returns a random integer for the computer's choice of tool.
    */
    return (rand() % 3) + 1;
}

int main()
{
    std::srand(std::time(NULL));

    // Keeps track of frequency of each result
    int rolls[1000];
    int rockRolls = 0;
    int paperRolls = 0;
    int scissorRolls = 0;

    for (int i = 0; i < 1000; i++)
    {
        rolls[i] = computerPick();
        if (rolls[i] == 1)
        {
            rockRolls++;
        }
        else if (rolls[i] == 2)
        {
            paperRolls++;
        }
        else if (rolls[i] == 3)
        {
            scissorRolls++;
        }
    }

    // Prints out how frequently each result came up
    std::cout << "1000 rolls" << std::endl;
    std::cout << "Rock: " << rockRolls << " times" << std::endl;
    std::cout << "Paper: " << paperRolls << " times" << std::endl;
    std::cout << "Scissors: " << scissorRolls << " times" << std::endl;
    return 0;
}
