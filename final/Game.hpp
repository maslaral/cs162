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
#include "Break_Room.hpp"

class Game {
  private:
    int time;
    Player* player;
    Desk* players_desk;
    Desk* jerrys_desk;
    Break_Room* break_room_1;
    Break_Room* break_room_2;
  public:
    Game();
    ~Game();
    void begin_game();
		int play_round();
		void create_prompt();
};

#endif
