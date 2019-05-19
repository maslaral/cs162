/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Game header file - includes pointers to 
   Character objects as private variables. In addition,
   declares methods for creating players, playing the game,
   playing each round, and getting round values. 
*************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "character_type.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "Winner_Queue.hpp"
#include "Menu.hpp"

#include <string>
#include <iostream>

class Game {
  private:
    Winner_Queue team_one_winners;
    Winner_Queue team_two_winners;
  public:
    // constructor
    Game();
    //destructor
    ~Game();

    // gameplay functions
    Character* create_player(character_type, std::string);
    void play(Character*, Character*);
    void play_round(Character*, Character*);
    void get_round_start_values(Character*, Character*);

    // add players to teams
    void add_team(int);
};

#endif
