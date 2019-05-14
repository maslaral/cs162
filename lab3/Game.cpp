/*************************************************************
** Program name: Lab 3 - War Game
** Author: Alex Maslar
** Date: April 21 2019
** Description: The Game class represents the game, including
   the information about the score each round and the total 
   score. It contains functions to create the dice based on
   the user input in the main function, and to determine the
   winner of the war game.
*************************************************************/
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include<iostream>

/*************************************************************
** Description: Default constructor for the Game object, sets
   the player scores to 0.
*************************************************************/
Game::Game(){
  scorePlayerOneTotal = 0;
  scorePlayerTwoTotal = 0;
}

/*************************************************************
** Description: Destructor for the dice objects created in 
   the game class. Avoids memory leaks.
*************************************************************/
Game::~Game(){
  delete playerOneDie;
  delete playerTwoDie;
}

/*************************************************************
** Description: Creates the player 1 dice object based on the
   user input. Either a loaded die or a fair die is created.
*************************************************************/
void Game::createPlayerOneDie(int dieType, int numSides){
  if (dieType == 1){
    playerOneDie = new Die(numSides);
  }
  else {
    playerOneDie = new LoadedDie(numSides);
  }
}

/*************************************************************
** Description: Creates the player 2 dice object based on the
   user input. Either a loaded die or a fair die is created.
*************************************************************/
void Game::createPlayerTwoDie(int dieType, int numSides){
  if (dieType == 1){
    playerTwoDie = new Die(numSides);
  }
  else {
    playerTwoDie = new LoadedDie(numSides);
  } 
}

/*************************************************************
** Description: Calls the roll dice function from the Die
   or the LoadedDie classes. This is based on the dice type,
   as the roll function parent function is shadowed by the 
   LoadedDie child class.
*************************************************************/
void Game::playRound(){
  scorePlayerOneRound = playerOneDie->roll();
  scorePlayerTwoRound = playerTwoDie->roll();
}

/*************************************************************
** Description: Displays the stats for each round, including
   the number of sides for each dice and the value rolled.
*************************************************************/
void Game::displayRoundStats(){
  std::cout << "Player 1 Rolled: " << scorePlayerOneRound << std::endl;
  std::cout << "Player 1 Sides: " << playerOneDie->getNumberOfSides() << std::endl;
  std::cout << "Player 2 Rolled: " << scorePlayerTwoRound << std::endl;
  std::cout << "Player 2 Sides: " << playerTwoDie->getNumberOfSides() << std::endl;
}

/*************************************************************
** Description: Displays the results from each round.
*************************************************************/
void Game::displayRoundResult(){
  if (scorePlayerOneRound > scorePlayerTwoRound){
    displayPlayerOneWins();
  }
  else if (scorePlayerTwoRound > scorePlayerOneRound){
    displayPlayerTwoWins();
  }
  else {
    std::cout << "The round was a draw." << std::endl;
  }
}

/*************************************************************
** Description: Adds to the score for player 1.
*************************************************************/
void Game::displayPlayerOneWins(){
  scorePlayerOneTotal++;
  std::cout << "Player one wins this round!" << std::endl;
}

/*************************************************************
** Description: Adds to the score for player 2.
*************************************************************/
void Game::displayPlayerTwoWins(){
  scorePlayerTwoTotal++;
  std::cout << "Player two wins this round!" << std::endl;
}

/*************************************************************
** Description: Function that declares the winner of the 
   war game by comparing the totals. If the score is tied,
   it declares that it's a draw. The function also displays
   the scores for player 1 and 2.
*************************************************************/
void Game::declareWinner(){
  if (scorePlayerOneTotal > scorePlayerTwoTotal){
    std::cout << "Player 1 wins the war!" << std::endl;
  }
  else if (scorePlayerTwoTotal > scorePlayerOneTotal){
    std::cout << "Player 2 wins the war!" << std::endl;
  }
  else {
    std::cout << "It's a draw." << std::endl;
  }
  std::cout << "Player 1 Score: " << scorePlayerOneTotal << std::endl;
  std::cout << "Player 2 Score: " << scorePlayerTwoTotal << std::endl;
}
