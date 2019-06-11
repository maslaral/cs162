/*************************************************************
** Program name: Final project
** Author: Alex Maslar
** Date: June 09 2019
** Description: Coordinates game play 
*************************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include "Office.hpp"
#include "Desk.hpp"
#include "Player.hpp"
#include "Break_Room.hpp"

#include <iostream>

int main(){
  int time = 100;

  // initializing objects
  Game office_survival;
  office_survival.begin_game();

  // each turn add to the time
  while (time < 500){
    time += office_survival.play_round();
    time += 30;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Time: " << time << " Status: Not Fired" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
  }

  return 0;
}
