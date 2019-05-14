/*************************************************************
** Program name: Ant.hpp
** Author: Group 1
** Date: May 11 2019
** Description: Header file for the Ant class. The class has
   three methods - move, breed, and kind. Move moves the ant
   in a random direction if the space is open, breed creates a
   new ant in a random empty adjacent cell if the ant is older
   than 3, and the kind function simply returns the enum value
   ANT.
*************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
public:
  virtual ~Ant();
  virtual void move(int, int, int, int, Critter ***);
  virtual void breed(int, int, int, int, Critter ***);
  virtual bugtype kind();
};
#endif
