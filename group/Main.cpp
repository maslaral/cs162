/*************************************************************
** Program name: Main.cpp
** Author: Group 1 
** Date: May 11 2019
** Description: Main function to intialize the Game object
   and begin the game by calling the menuChoice() function. 
*************************************************************/
#include "Game.hpp"
#include <iostream>

int main()
{
   // seeds the random number generator
   srand(time(NULL)); // seeds random num generator

   // intialize the game object
   Game match;

   // play game
   match.menuChoice();

   return 0;
}
