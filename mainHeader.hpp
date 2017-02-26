#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

#include <string>

class Tool
{
public:
    Tool();
    Tool(int strength);
    Tool(const Tool &RHS);
    Tool& operator=(const Tool &RHS);
    virtual ~Tool();
    void setStrength(int strength);
    int getStrength() const;
    char getType();
    virtual std::string fight(Tool* opponentTool) = 0;
    virtual void printTool() = 0;
protected:
    int strength;
    char type[2];
};



class Rock : public Tool
{
public:
    Rock();
    Rock(int strength);
    Rock(const Rock &RHS);
    Rock& operator=(const Rock &RHS);
    virtual ~Rock();
    virtual std::string fight(Tool* opponentTool);
    void printTool();
};

class Paper : public Tool
{
public:
    Paper();
    Paper(int strength);
    Paper(const Paper &RHS);
    Paper& operator=(const Paper &RHS);
    virtual ~Paper();
    virtual std::string fight(Tool* opponentTool);
    void printTool();
};

class Scissors : public Tool {
public:
    Scissors();
    Scissors(int strength);
    Scissors(const Scissors &RHS);
    Scissors& operator=(const Scissors &RHS);
    ~Scissors();
    virtual std::string fight(Tool* opponentTool);
    void printTool();
};


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
