/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Main function which includes menus for getting
   the number of players and adds players to the teams. Also
   calls the game function to play and asks the user if they
   want to play again.
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

  while (play_again){
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
      game.add_team(2);
    }

    // begin game
    game.play_tournament();

    // prompt user to play again or exit
    keep_playing.outputMenu();

    // based on user input, set the play_again variable
    if (keep_playing.getUserInput() == 1){
      play_again = true;
    }
    else {
      play_again = false;
    }
  }
  return 0;
}
