/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
*************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"

class Game
{
  private:
    // user specified number of rounds to play
    int numberOfRounds;
    // holds the total score for players
    int scorePlayerOneTotal;
    int scorePlayerTwoTotal;
    // holds the score for each round
    int scorePlayerOneRound;
    int scorePlayerTwoRound;
    // pointers to Die objects - used to allocate
    // either create a Die object or a LoadedDie object
    Die* playerOneDie;
    Die* playerTwoDie;

  public:
    // constructor function
    Game();
    // destructor function
    ~Game();
    // function header for creating dice
    void createPlayerTwoDie(int, int);
    void createPlayerOneDie(int, int);
    // sets the number of sides for each dice
    void setSides(int, int);
    // plays the round
    void playRound();
    // displays the stats from the round
    void displayRoundStats();
    // displays the winner of each round
    void displayRoundResult();
    // output if player wins
    void displayPlayerOneWins();
    void displayPlayerTwoWins();
    // declares the winner of war
    void declareWinner();
};

#endif
