/*************************************************************
** Program name: Critter.hpp
** Author: Group 1 
** Date: May 11 2019
** Description: Header file for the Critter class. The Critter
   class has three variables: a bool that tracks whether it
   has moved during a round, an int that tracks the number
   of steps survived, and an int that tracks the number of 
   steps sinceeaten. The Critter class also has pure virtual
   functions for move, breed, and kind which are used by the
   derived classes (Doodlebug and Ant) and functions to get
   and set the protected variables.
*************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include "enum_direction.hpp"
#include "enum_kind.hpp"

class Critter
{
protected:
  bool hasMoved;       // tracks if a Critter has moved
  int stepsSurvived;   // tracks num of steps a Critter has survived
  int stepsSinceEaten; // tracks num of steps since a Critter has eaten
public:
  Critter();
  virtual ~Critter();
  virtual void move(int, int, int, int, Critter ***) = 0;
  virtual void breed(int, int, int, int, Critter ***) = 0;
  virtual bugtype kind() = 0;
  // getter functions
  int getStepsSurvived();
  int getStepsSinceEaten();
  bool getHasMoved() const;
  // setter functions
  void setStepsSurvived(int);
  void setStepsSinceEaten(int);
  void setHasMoved(bool);
};
#endif
