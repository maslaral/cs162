/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
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
#include "Loser_Stack.hpp"
#include "Menu.hpp"

#include <string>
#include <iostream>

class Game {
  private:
    Winner_Queue team_one_lineup;
    Winner_Queue team_two_lineup;
    Loser_Stack losers;
    int team_one_score;
    int team_two_score;
  public:
    // constructor
    Game();
    //destructor
    ~Game();

    // gameplay functions
    Character* create_player(character_type, std::string);
    void play_tournament();
    bool teams_alive();
    void play_matchup();
    void play_turn(Character*, Character*);
    void get_start_attributes(Character*, Character*);

    // add players to teams
    void add_team(int);
};

#endif
