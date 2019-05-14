/*************************************************************
** Program name: Critter.hpp
** Author: Group 1 
** Date: May 11 2019
** Description: Function definition for Critter class.The
   class has three variables: a bool that tracks whether it
   has moved during a round, an int that tracks the number
   of steps survived, and an int that tracks the number of 
   steps sinceeaten. The Critter class also has pure virtual
   functions for move, breed, and kind which are used by the
   derived classes (Doodlebug and Ant) and functions to get
   and set the protected variables.
*************************************************************/
#include "Critter.hpp"

/*************************************************************
** Description: Defualt constructor for the Critter class.
*************************************************************/
Critter::Critter() : hasMoved{false}, stepsSurvived{0}
{
}

/*************************************************************
** Description: Virtual destructor for the Critter class.
*************************************************************/
Critter::~Critter()
{
}

/*************************************************************
** Description: Setter functions to set the number of steps
   survived, the steps since eaten, and the boolean value 
   representing if the Critter object has moved.
*************************************************************/
void Critter::setStepsSurvived(int steps)
{
    stepsSurvived = steps;
}

void Critter::setStepsSinceEaten(int steps)
{
    stepsSinceEaten = steps;
}

void Critter::setHasMoved(bool moved)
{
    hasMoved = moved;
}

/*************************************************************
** Description: Getter functions to return the steps survived,
   the steps since eaten, and the boolean value representing
   if the Critter object has moved.
*************************************************************/
int Critter::getStepsSurvived()
{
    return stepsSurvived;
}

int Critter::getStepsSinceEaten()
{
    return stepsSinceEaten;
}

bool Critter::getHasMoved() const
{
    return hasMoved;
}
