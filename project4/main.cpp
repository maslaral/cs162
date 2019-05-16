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

  // seeds the random number generator
  srand(time(NULL));

  // set play_again to true by default
  bool play_again = true;

  // create the game object
  Game game;

  // repeat as long as play again is equal to true
  while (play_again == true){
    Menu choose_player("Who do you want to choose as player one?");
    choose_player.addOptions("Barbarian");
    choose_player.addOptions("Vampire");
    choose_player.addOptions("Blue Men");
    choose_player.addOptions("Medusa");
    choose_player.addOptions("Harry Potter");
    choose_player.outputMenu();

    // creating player one
    character_type player_one = static_cast<character_type>(choose_player.getUserInput());

    // output choose player menu again
    choose_player.outputMenu();

    // creating player two
    character_type player_two = static_cast<character_type>(choose_player.getUserInput());

    // begin game
    game.play(player_one, player_two);

    // prompt user to play again or exit
    std::cout << std::endl;
    Menu keep_playing("Do you want to play again?");
    keep_playing.addOptions("Play again");
    keep_playing.addOptions("Exit the game");
    keep_playing.outputMenu();

    // based on user input, set the play_again variable
    if (keep_playing.getUserInput() == 1){
      play_again = true;
    }
    else {
      play_again = false;
    }

    std::cout << std::endl;
  }
  return 0;
}
