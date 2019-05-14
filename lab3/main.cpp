/*************************************************************
** Program name: Lab 3 - War Game
** Author: Alex Maslar
** Date: April 21 2019
** Description: Main function for the War Game program that 
   calls functions in the Menu class to collect user input,
   passes that input to the Game class, and calls functions
   from the Game class to display the results of each round 
   and the entire game.
*************************************************************/
#include<iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Menu.hpp"
#include "Game.hpp"

int main(){
  // seeds the random number generator
  srand(time(NULL));

  // menu for player to start the program or exit
  Menu start("Do you want to start the game?");
  start.addOptions("Play game");
  start.addOptions("Exit game");
  start.outputMenu();

  // if user selects start game, play the game
  if (start.userInput == 1)
  {
    // constructor for game
    Game game;

    // menu for number of rounds
    Menu numberOfRounds("How many rounds do you want to play?");
    numberOfRounds.setLimits(1, 10000);
    numberOfRounds.outputMenu();

    // menu for player one die type
    Menu playerOneDieType("Which die would you like to assign to player 1?");
    playerOneDieType.addOptions("Fair Die");
    playerOneDieType.addOptions("Loaded Die");
    playerOneDieType.outputMenu();

    // menu for player two die type
    Menu playerTwoDieType("Which die would you like to assign to player 2?");
    playerTwoDieType.addOptions("Fair Die");
    playerTwoDieType.addOptions("Loaded Die");
    playerTwoDieType.outputMenu();

    // menu for player one die sides
    Menu playerOneDieSides("How many sides would you like for the die assigned to player 1?");
    playerOneDieSides.setLimits(2, 1000);
    playerOneDieSides.outputMenu();

    // menu for player two die sides
    Menu playerTwoDieSides("How many sides would you like for the die assigned to player 2?");
    playerTwoDieSides.setLimits(2, 1000);
    playerTwoDieSides.outputMenu();  
    
    // create the player dice
    game.createPlayerOneDie(playerOneDieType.userInput, playerOneDieSides.userInput);
    game.createPlayerTwoDie(playerTwoDieType.userInput, playerTwoDieSides.userInput);

    // print out the round scores
    for (int i = 0; i < numberOfRounds.userInput; i++){
      std::cout << "----------------------------" << std::endl;
      std::cout << "Round " << i + 1 << std::endl;
      std::cout << "----------------------------" << std::endl;
      game.playRound();
      game.displayRoundStats();
      game.displayRoundResult();
    }

    // print out the final score
    std::cout << "----------------------------" << std::endl;
    std::cout << "|        GAME OVER!        |" << std::endl;
    std::cout << "----------------------------" << std::endl;
    game.declareWinner();
    std::cout << "----------------------------" << std::endl;
  }

  return 0;
} 
