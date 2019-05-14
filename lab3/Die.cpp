/*************************************************************
** Program name: Lab 3 - War Game
** Author: Alex Maslar
** Date: April 21 2019
** Description: The Die class is a parent class representing 
   a fair dice. It holds the number of sides of the dice. The
   methods of the class include a method to set the number of
   sides, a method to get the number of sides which is used in
   other classes, and a method to roll the dice. Since this
   is the fair dice, rolling the dice is simply based on 
   random number between 2 (lowest number of sides) and the 
   number of sides.
*************************************************************/
#include "Die.hpp"
#include<cstdlib>

/*************************************************************
** Description: Default constructor for the Die object, sets
   the number of sides to the traditional number of sides (6).
*************************************************************/
Die::Die(){
  N = 6;
}

/*************************************************************
** Description: Virtual destructor of the Die objects.
*************************************************************/
Die::~Die(){
}

/*************************************************************
** Description: Constructor for the Die object, passes the 
   number of sides.
*************************************************************/
Die::Die(int N){
  setNumberOfSides(N);
}

/*************************************************************
** Description: Set function that sets the number of sides of
   the dice.
*************************************************************/
void Die::setNumberOfSides(int N){
  this->N = N;
}

/*************************************************************
** Description: Get function to get the number of sides, used
   in the LoadedDie class.
*************************************************************/
int Die::getNumberOfSides(){
  return N;
}

/*************************************************************
** Description: Function to roll the die. It returns a random
   number between 1 (minimum of sides) and the number of sides.
*************************************************************/
int Die::roll(){
  int random = rand() % N + 2;
  if (random > N){
    return N;
  }
  else {
    return random;
  }
}
