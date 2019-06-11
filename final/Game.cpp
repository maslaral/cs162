/************************************************************* 
** Program name: Final project 
** Author: Alex Maslar 
** Date: June 09 2019 ** Description: Game object - coordinates game play and prompts the user for next steps.
*************************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include "Email.hpp"
#include "Player.hpp"

#include <iostream>

/*************************************************************
** Description: Constructor
*************************************************************/
Game::Game(){
  time = 0;                     // time is set to 0 to start game
  player = new Player;          // create player object
  desk = new Desk;              // create desk space

  player->set_location(desk);   // player initially starts at desk
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
Game::~Game(){
}

/*************************************************************
** Description: Opening prompt for the game
*************************************************************/
void Game::begin_game(){
  // opening prompts
  std::cout << "The printer next to your desk beeps, waking you\n";
  std::cout << "from your light, open-eyed slumber. Appearing awake\n";
  std::cout << "while sleeping is a skill you've honed over your\n";
  std::cout << "many years of service at Vandelay Industries - an\n";
  std::cout << "importer/exporter company. As an accountant, you're\n";
  std::cout << "responsible for tracking employee expenses. It's a\n";
  std::cout << "tedious job, with low pay and long hours. You've\n";
  std::cout << "barely shaken yourself awake when a hand grasps your\n";
  std::cout << "shoulder. It's your boss Dave.\n";

  // report status to your boss
  Menu report_status("Dave: Do you have that report?");
  report_status.addOptions("Lie - I'll get it to you by end of day.");
  report_status.addOptions("Tell the truth - What report?");
  report_status.outputMenu();

  if (report_status.getUserInput() == 1){
    std::cout << "Dave: Sounds great!" << std::endl;
    std::cout << std::endl;
    std::cout << "A cold sweat forms across your brow as Dave turns\n";
    std::cout << "and walks away. You really have no idea what he's\n";
    std::cout << "talking about...\n";
  }
  else {
    std::cout << "Dave: You're fired. Pack up your things and get out." << std::endl;
    player->set_employment_status(true);
  }
}

/*************************************************************
** Description: Coordinates playing a round in the game
*************************************************************/
void Game::play_round(){
  create_prompt();
}

/*************************************************************
** Description: Creates a prompt about where to go next based
   on the player's current location
*************************************************************/
void Game::create_prompt(){
  Office* player_location = player->get_location();

  // initialize a menu object
  Menu action_prompt("Where would you like to go?");

  if (player_location->get_top() != nullptr){
    action_prompt.addOptions(player_location->get_top()->get_room_name());
  }

  if (player_location->get_bottom() != nullptr){
    action_prompt.addOptions(player_location->get_bottom()->get_room_name());
  }

  if (player_location->get_right() != nullptr){
    action_prompt.addOptions(player_location->get_right()->get_room_name());
  }

  if (player_location->get_left() != nullptr){
    action_prompt.addOptions(player_location->get_left()->get_room_name());
  }

  action_prompt.outputMenu();
}
