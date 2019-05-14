/*************************************************************
** Program name: Lab 3 - War Program
** Author: Alex Maslar
** Date: April 21 2019
** Description: The LoadedDie class that sets the number of 
   sides for the loaded die and has a function to roll the
   dice with a bias.
*************************************************************/
#include "LoadedDie.hpp"
#include<cstdlib>

/*************************************************************
** Description: Constructor for the loaded die that takes the
   number of sides as it's only argument.
*************************************************************/
LoadedDie::LoadedDie(int sides){
  setNumberOfSides(sides);
}

/*************************************************************
** Description: Rolls the die with a bias. If the random number
   generated yields a result greater than the number of sides
   on the die, then set the result equal to the number of sides.
   Return the result, which is used in the Game class to
   determine the winner of each round of the war game.
*************************************************************/
int LoadedDie::roll(){
  int sides = getNumberOfSides();
  int result = rand() % (2 * sides) + 3;
  if (result > sides){
    result = sides;
  }
  return result;
} 
