/*************************************************************
** Program name: Lab 3 - War Game
** Author: Alex Maslar
** Date: April 21 2019
** Description: Header file for the Die class. Stores
   the number of sides. It also has methods for rolling the 
   dice, setting the number of sides, and getting the number
   of sides.
*************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
  private:
    // stores the number of sides of the dice
    int N;
  public:
    // Die constructors
    Die();
    virtual ~Die();
    Die(int);
    // function to roll the die
    virtual int roll();
    // function to set the number of sides of the dice
    void setNumberOfSides(int);
    // function to get the number of sides of the dice
    int getNumberOfSides();
};

#endif
