/*************************************************************
** Program name: Doodlebug.hpp
** Author: Group 1 
** Date: May 11 2019
** Description: Header file for the Doodlebug class. The class
   has four methods - move, eatAnt, breed, and kind. Move first
   calls the eatAnt function which checks if there is an Ant
   in adjacent space. If so, the Doodlebug moves to that space
   and replaces the ant. If there is not an Ant, then the 
   move function moves the Doodlebug in a random direction. 
   Breed creates a new Doodlebug in a random empty adjacent
   space if the Doodlebug is old enough to breed. The kind
   function simply returns the enum value DOODLEBUG.
*************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
public:
  virtual ~Doodlebug();
  virtual void move(int, int, int, int, Critter ***);
  bool eatAnt(int, int, int, int, Critter ***);
  virtual void breed(int, int, int, int, Critter ***);
  virtual bugtype kind();
};
#endif
