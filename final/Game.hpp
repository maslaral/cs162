/*************************************************************
** Program name: Final project
** Author: Alex Maslar
** Date: June 09 2019
** Description: Game object - coordinates game play and prompts
   the user for next steps.
*************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Office.hpp"
#include "Player.hpp"
#include "Desk.hpp"

class Game {
  private:
    int time;
    Player* player;
    Desk* desk;
  public:
    Game();
    ~Game();
    void begin_game();
		void play_round();
		void create_prompt();
};

#endif
