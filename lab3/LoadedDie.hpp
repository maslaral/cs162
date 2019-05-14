/*************************************************************
** Program name: Lab 3 - War Game
** Author: Alex Maslar
** Date: April 21 2019
** Description: Header file for the LoadedDie object. Contains
   a constructor for the LoadedDie and the roll function.
*************************************************************/
#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include "Die.hpp"

class LoadedDie : public Die
{
  public:
    // constructor
    LoadedDie(int);
    // roll the die with a bias
    int roll();
};

#endif
