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
  std::string name;       // hold player name when creating

  // initialize choose player menu
  Menu choose_player("Who do you want to choose as player?");
  choose_player.addOptions("Barbarian");
  choose_player.addOptions("Vampire");
  choose_player.addOptions("Blue Men");
  choose_player.addOptions("Medusa");
  choose_player.addOptions("Harry Potter");

  // initialize number of players menu
  Menu num_players("How many players?");
  num_players.setLimits(1,100);
  
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Team 1" << std::endl; 
  num_players.outputMenu();
  
  for (int i = 0; i < num_players.getUserInput(); i++){
    choose_player.outputMenu();
    character_type type = static_cast<character_type>(choose_player.getUserInput());

    // TODO - getline function here
    std::cout << "Name player:" << std::endl;
    std::cin >> name;

    Character* player_one = game.create_player(type, name);
    game.add_team_one(player_one);
  }

  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Team 2" << std::endl; 
  num_players.outputMenu();

  for (int i = 0; i < num_players.getUserInput(); i++){
    choose_player.outputMenu();
    character_type type = static_cast<character_type>(choose_player.getUserInput());

    // TODO - getline function here
    std::cout << "Name player:" << std::endl;
    std::cin >> name;

    Character* player_two = game.create_player(type, name);
    game.add_team_two(player_two);
  }

  // begin game
  // game.play(player_one, player_two);

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

  return 0;
}
