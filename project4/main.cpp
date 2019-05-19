/*************************************************************
 ** Program name: Project 3
 ** Author: Alex Maslar
 ** Date: May 12 2019
 ** Description: Main function for the project which creates
 the menu objects and takes user input. The function also
 calls the game function and gives the user the ability to
 play again or exit the game.
 *************************************************************/
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "roll_die.hpp"
#include "character_type.hpp"

#include <iostream>

int main(){
  srand(time(NULL));      // seeds random number
  bool play_again = true; // by default true
  Game game;              // initialize the game

  // initialize menu objects
  Menu num_players_team_one("How many players on team one?");
  num_players_team_one.setLimits(1,100);

  Menu num_players_team_two("How many players on team two?");
  num_players_team_two.setLimits(1,100);

  Menu keep_playing("Do you want to play again?");
  keep_playing.addOptions("Play again");
  keep_playing.addOptions("Exit the game");

  // prompt user for number of players
  num_players_team_one.outputMenu();
  num_players_team_two.outputMenu();

  for (int i = 1; i <= num_players_team_one.getUserInput(); i++){
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "TEAM ONE - CREATE PLAYER " << i << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    game.add_team(1);
  }

  for (int i = 1; i <= num_players_team_two.getUserInput(); i++){
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "TEAM TWO - CREATE PLAYER " << i << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    game.add_team(1);
  }

  // begin game
  // game.play(player_one, player_two);

  // prompt user to play again or exit
  keep_playing.outputMenu();

  // based on user input, set the play_again variable
  if (keep_playing.getUserInput() == 1){
    play_again = true;
  }
  else {
    play_again = false;
  }

  return 0;
}
