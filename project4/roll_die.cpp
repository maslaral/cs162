/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Roll die function implementation that rolls
   the die based on each player type.
*************************************************************/
#include "roll_die.hpp"
#include <cstdlib>
#include <iostream>

/*************************************************************
** Description: Function that rolls the die for the player
   and returns the result. It's two arguments are the number
   of die, and the number of sides. 
*************************************************************/
int roll_die(int num_die, int num_sides){
  int total_result = 0;

  for (int i = 0; i < num_die; i++){
    int roll_result = rand() % num_sides;
    total_result += roll_result + 1;
  }

  return total_result;
}
