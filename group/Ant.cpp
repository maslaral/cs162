/*************************************************************
** Program name: Ant.cpp
** Author: Group 1 
** Date: May 11 2019
** Description: Function implementation for the Ant class. The
   class has three functions - move, breed, and kind. The move
   function moves the ant in a random direction, the breed 
   function creates a new ant in a random empty adjacent space
   if the ant is older than 3, and the kind function simply 
   returns the enum value ANT.
*************************************************************/
#include "Critter.hpp"
#include "Game.hpp"
#include "Ant.hpp"
#include <cstdlib>

/*************************************************************
** Description: Virtual destructor for the Ant class.
*************************************************************/
Ant::~Ant()
{
}

/*************************************************************
** Description: Takes the row, column, number of rows and
   columns, and the grid as parameters. The function then
   generates a random number between 1 and 4 representing a
   direction. If the adjacent space in the randomized direction
   has a Critter there already, the ant does not move.
*************************************************************/
void Ant::move(int row, int col, int numRows, int numCols, Critter ***grid)
{
  int direction = (rand() % 4) + 1;

  switch (direction)
  {
  case NORTH:
  {
    if (row - 1 >= 0) // check if in bounds
    {
      if (grid[row - 1][col] == nullptr)
      {
        // move ant - assign new loc the ant and set prev loc to nullptr
        grid[row - 1][col] = grid[row][col];
        grid[row - 1][col]->setHasMoved(true);
        grid[row][col] = nullptr;
      }
      else
      {
        // if space is not empty don't move
        grid[row][col]->setHasMoved(true);
      }
    }
    break;
  }
  case EAST:
    {
      if (col + 1 < numCols)
      {
        if (grid[row][col + 1] == nullptr)
        {
          grid[row][col + 1] = grid[row][col];
          grid[row][col + 1]->setHasMoved(true);
          grid[row][col] = nullptr;
        }
        else
        {
          grid[row][col]->setHasMoved(true);
        }
      }
      break;
    }
  case SOUTH:
    {
      if (row + 1 < numRows)
      {
        if (grid[row + 1][col] == nullptr)
        {
          grid[row + 1][col] = grid[row][col];
          grid[row + 1][col]->setHasMoved(true);
          grid[row][col] = nullptr;
        }
        else
        {
          grid[row][col]->setHasMoved(true);
        }
      }
      break;
    }
  case WEST:
  {
    if (col - 1 >= 0)
    {
      if (grid[row][col - 1] == nullptr)
      {
        grid[row][col - 1] = grid[row][col];
        grid[row][col - 1]->setHasMoved(true);
        grid[row][col] = nullptr;
      }
      else
      {
        grid[row][col]->setHasMoved(true);
      }
    }
    break;
  }
  }
}
/*************************************************************
 ** Description: Takes five parameters - the row and column,
    the number of rows and columns on the grid, and a pointer
    to the grid. The function first generates a random direction,
    and then initializes the two variables (numChecks and
    success) which are used to exit the following while loop.
    The while loop runs if the ant steps survived is greater
    than or equal to 3 (i.e. the ant has the ability to breed)
    and checks in each direction if the space is in bounds and
    empty. If all conditions are met, a new Ant is created at
    that space on the grid. 
 *************************************************************/
void Ant::breed(int row, int col, int numRows, int numCols, Critter ***grid)
{ 
  int randomDirection = (rand() % 4) + 1;
  
  int numChecks = 1;    // counter for num times direction checked
  bool success = false; // whether or not successfully bred

  if (stepsSurvived >= 3)
  {
    while (numChecks < 5 && success == false)
    {
      switch (randomDirection)
      {
      case NORTH:
      {
        if (row - 1 >= 0 && grid[row - 1][col] == nullptr)
        {
          grid[row - 1][col] = new Ant();      // new ant created
          grid[row][col]->setStepsSurvived(0); // resets steps survived
          success = true;
        }
      }
      break;
      case EAST:
      {
        if (col + 1 < numCols && grid[row][col + 1] == nullptr)
        {
          grid[row][col + 1] = new Ant();     
          grid[row][col]->setStepsSurvived(0); 
          success = true;
        }
      }
      break;
      case SOUTH:
      {
        if (row + 1 < numRows && grid[row + 1][col] == nullptr)
        {
          grid[row + 1][col] = new Ant();     
          grid[row][col]->setStepsSurvived(0);
          success = true;
        }
      }
      break;
      case WEST:
      {
        if (col - 1 >= 0 && grid[row][col - 1] == nullptr)
        {
          grid[row][col - 1] = new Ant();      
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
** Description: Kind function that returns the enum value ANT
   when called.
*************************************************************/
bugtype Ant::kind()
{
  return ANT;
}
