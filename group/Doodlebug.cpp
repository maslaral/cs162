/*************************************************************
** Program name: Doodlebug.cpp
** Author: Group 1
** Date: May 11 2019
** Description: Function implementation for Doodlebug class.
   Doodlebug inherits from Critter class and has an additional
   eatAnt() function which will eat an ant in an adjacent space
   prior to moving. In addition, the Doodlebug class has a 
   condition in the breed class where if the steps since eaten
   are greater than 3, the Doodlebug will starve.
*************************************************************/
#include "Critter.hpp"
#include "Game.hpp"
#include "Doodlebug.hpp"
#include <cstdlib>

/*************************************************************
** Description: Virtual destructor for the Doodlebug class.
*************************************************************/
Doodlebug::~Doodlebug()
{
}

/*************************************************************
 ** Description: Takes the row, column, number of rows and
    columns, and the grid as parameters. The function then
    calls the eatAnt() function. If there is an ant in an adjacent
    space, the doodlebug will move to eat them and the move
    function ends. If not, then the ant moves a random direction
    and moves to the space its facing if it's in bounds and empty.
    If those conditions are not met, then the doodlebug does not
    move.
 *************************************************************/
void Doodlebug::move(int row, int col, int numRows, int numCols, Critter ***grid)
{
  int direction = (rand() % 4) + 1;

  // checking if there is an ant to eat
  if (eatAnt(row, col, numRows, numCols, grid) == false)
  {
    switch (direction)
    {
    case NORTH:
    {
      // checking if space is in bounds and empty
      if (row - 1 >= 0 && grid[row - 1][col] == nullptr) // 
      {
        grid[row - 1][col] = grid[row][col];
        grid[row][col] = nullptr;
        grid[row - 1][col]->setHasMoved(true);
        grid[row - 1][col]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      else
      {
        // if space is not empty don't move and add one to steps since eaten
        grid[row][col]->setHasMoved(true);
        grid[row][col]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      break;
    }
    case EAST:
    {
      if (col + 1 < numCols && grid[row][col + 1] == nullptr)
      {
        grid[row][col + 1] = grid[row][col];
        grid[row][col] = nullptr;
        grid[row][col + 1]->setHasMoved(true);
        grid[row][col + 1]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      else
      {
        grid[row][col]->setHasMoved(true);
        grid[row][col]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      break;
    }
    case SOUTH:
    {
      if (row + 1 < numRows && grid[row + 1][col] == nullptr)
      {
        grid[row + 1][col] = grid[row][col];
        grid[row][col] = nullptr;
        grid[row + 1][col]->setHasMoved(true);
        grid[row + 1][col]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      else
      {
        grid[row][col]->setHasMoved(true);
        grid[row][col]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      break;
    }
    case WEST:
    {
      if (col - 1 >= 0 && grid[row][col - 1] == nullptr)
      {
        grid[row][col - 1] = grid[row][col];
        grid[row][col] = nullptr;
        grid[row][col - 1]->setHasMoved(true);
        grid[row][col - 1]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      else
      {
        grid[row][col]->setHasMoved(true);
        grid[row][col]->setStepsSinceEaten(getStepsSinceEaten() + 1);
      }
      break;
    }
    }
  }
}

/*************************************************************
** Description: Takes five parameters - the row and column,
   the number of rows and columns on the grid, and a pointer
   to the grid. The function checks each direction to see if
   the space is empty and then if the space contains an ant. 
   If the space contains an ant, the ant is deleted and the 
   doodlebug moves to the space previously occupied by the ant.
*************************************************************/
bool Doodlebug::eatAnt(int row, int col, int numRows, int numCols, Critter ***grid)
{
  // checks if adjacent space is in bounds and is kind ant
  if ((row - 1 >= 0 && grid[row - 1][col]) && grid[row - 1][col]->kind() == ANT)
  {
    delete grid[row - 1][col];                 // deletes ant
    grid[row - 1][col] = grid[row][col];       // moves doodlebug
    grid[row - 1][col]->setHasMoved(true);     // sets hasMoved to true
    grid[row - 1][col]->setStepsSinceEaten(0); // resets steps since eaten
    grid[row][col] = nullptr;                  // sets previous loc to nullptr
    return true;
  }
  else if ((col + 1 < numCols && grid[row][col + 1]) && grid[row][col + 1]->kind() == ANT)
  {
    delete grid[row][col + 1];
    grid[row][col + 1] = grid[row][col];       
    grid[row][col + 1]->setHasMoved(true);
    grid[row][col + 1]->setStepsSinceEaten(0);
    grid[row][col] = nullptr;
    return true;
  }
  else if ((row + 1 < numRows && grid[row + 1][col]) && grid[row + 1][col]->kind() == ANT)
  {
    delete grid[row + 1][col];
    grid[row + 1][col] = grid[row][col];
    grid[row + 1][col]->setHasMoved(true);
    grid[row + 1][col]->setStepsSinceEaten(0);
    grid[row][col] = nullptr;
    return true;
  }
  else if ((col - 1 >= 0 && grid[row][col - 1]) && grid[row][col - 1]->kind() == ANT)
  {
    delete grid[row][col - 1];
    grid[row][col - 1] = grid[row][col];
    grid[row][col - 1]->setHasMoved(true);
    grid[row][col - 1]->setStepsSinceEaten(0);
    grid[row][col] = nullptr;
    return true;
  }
  else
  {
    return false;
  }
}

/*************************************************************
** Description: Takes five parameters - the row and column,
   the number of rows and columns on the grid, and a pointer
   to the grid. The function first generates a random direction,
   and then initializes the two variables (numChecks and
   success) which are used to exit the susequent while loop. 
   The function then checks if the steps since eaten variable
   is greater than or equal to 3. If so, then the doodlebug
   starves and the function exits. If not, then  the while
   loop runs if the doodlebug steps survived is greater than
   or equal to 8 (i.e. the doodlebug has the ability to breed)
   and checks in each direction if the space is in bounds and 
   empty. If all conditions are met, a new Doodlebug is created
   at that space on the grid. 
*************************************************************/
void Doodlebug::breed(int row, int col, int numRows, int numCols, Critter ***grid)
{ 
  int randomDirection = (rand() % 4) + 1;

  int numChecks = 1;    // counter for num times direction checked
  bool success = false; // whether or not successfully bred

  // before breeding, starve if haven't eaten for 3 steps
  if (grid[row][col]->getStepsSinceEaten() >= 3)
  {
    delete grid[row][col];
    grid[row][col] = nullptr;
  }

  if (grid[row][col] != nullptr && grid[row][col]->getStepsSurvived() >= 8)
  {
    while (numChecks < 5 && success == false)
    {
      switch (randomDirection)
      {
      case NORTH:
      {
        if (row - 1 >= 0 && grid[row - 1][col] == nullptr)
        {
          grid[row - 1][col] = new Doodlebug(); // new doodlebug created
          grid[row][col]->setStepsSurvived(0);  // resets steps survived
          success = true;
        }
      }
      break;
      case EAST:
      {
        if (col + 1 < numCols && grid[row][col + 1] == nullptr)
        {
          grid[row][col + 1] = new Doodlebug();
          grid[row][col]->setStepsSurvived(0);
          success = true;
        }
      }
      break;
      case SOUTH:
      {
        if (row + 1 < numRows && grid[row + 1][col] == nullptr)
        {
          grid[row + 1][col] = new Doodlebug();
          grid[row][col]->setStepsSurvived(0);
          success = true;
        }
      }
      break;
      case WEST:
      {
        if (col - 1 >= 0 && grid[row][col - 1] == nullptr)
        {
          grid[row][col - 1] = new Doodlebug(); 
          grid[row][col]->setStepsSurvived(0); 
          success = true;
        }
      }
      break;
      }

      randomDirection++; // changes direction
      numChecks++;

      // handles when the direction is 5 - resets back to 1 (NORTH)
      if (randomDirection > 4)
      {
        randomDirection = 1;
      }
    }
  }
}

/*************************************************************
 ** Description: Kind function that returns the enum value 
    Critter when called.
 *************************************************************/
bugtype Doodlebug::kind()
{
  return DOODLEBUG;
}
