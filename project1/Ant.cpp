/*************************************************************
** Program name: Langton's Ant
** Author: Alex Maslar
** Date: April 13 2019
** Description: The Ant class represents the ant. It contains
   information about the ant, including the ant's position on
   the board, the direction it's facing, and rules for how
   the ant should move based on the color of the space. The
   ant class also contains a function to check if the ant is
   on the edge of the board and is about to step off. The
   ant essentially sees that it's in a dangerous situation, and
   pivots the opposite direction to avoid falling off the board
   to its death. Finally, the Ant class contains a function to 
   randomly set the ant location if the user chooses that option
   in the main function.
*************************************************************/
#include "Ant.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

/*************************************************************
** Description: Default constructor for the Ant object, sets
   the starting location to (0,0) and the direction to north.
*************************************************************/
Ant::Ant()
{
  antRow = 0;
  antColumn = 0;
  // initializes default values for the direction and board size
  antDirection = 1;
  boardRows = 5;
  boardColumns = 5;
}

/*************************************************************
** Description: Constructor for the Ant object, passes the
   number of rows and columns on the board - information used
   to determine if the ant is about to go out of bounds.
*************************************************************/
Ant::Ant(int r, int c)
{
  // subtract 1 because array starts at 0
  boardRows = r - 1;   
  boardColumns = c - 1;
  // intializes default values for the direction and board size
  antDirection = 1;
  boardRows = 5;
  boardColumns = 5;
}

/*************************************************************
** Description: Set function that sets the row and column
   location, and the direction of the Ant object. 
*************************************************************/
void Ant::setAntLocDir(int r, int c, int d)
{
  antRow = r - 1; // subtract 1 because array starts at 0
  antColumn = c - 1;
  antDirection = d;
}

/*************************************************************
** Description: Get function to pass the ant row location to
   the board object. Used to output the ant location on the
   board and to check and change the space color. 
*************************************************************/
int Ant::getAntRow()
{
  return antRow;
}

/*************************************************************
** Description: Get function to pass the ant column location 
   to the board object. Used to output the ant location on the
   board and to check and change the space color. 
*************************************************************/
int Ant::getAntColumn()
{
  return antColumn;
}

/*************************************************************
** Description: Function to check if the ant is on the edge of
   the board and facing the edge. If about to step off, the 
   ant pivots and changes to the opposite direction.
*************************************************************/
int Ant::antAvoidDeath(int tempDirection)
{
  // ant on right edge and facing west
  if (antColumn == 0 && tempDirection == 4)
  {
    return 2; // turn ant east
  }    
  // ant on left edge and facing east
  else if (antColumn == boardColumns && tempDirection == 2)
  {
    return 4; // turn ant west
  }
  // ant on top edge and facing north
  else if (antRow == 0 && tempDirection == 1)
  {
    return 3; // turn ant south
  }
  // ant on bottom edge and facing south
  else if (antRow == boardRows && tempDirection == 3)
  {
    return 1; // turn ant north
  } 
  // if not on and edge and facing out, just return the
  // original direction
  else
  {
    return tempDirection;
  }
}

/*************************************************************
** Description: Function that turns the ant based on the color
   of the space where the ant is located. If the ant is on a
   white space, the ant turns to the right (i.e. add one to
   the direction value until the direction is equal to 5,
   at which point it resets to 1). If the ant is on a black 
   space, the ant turns to the left (i.e. subtract one from
   the direction value until the direction is equal to 0,
   at which point it resets to 4). Calls the avoid death
   function to turn the ant around if the ant is on the edge 
   and now facing the edge of the board.
*************************************************************/
void Ant::antTurn(int** board)
{
  int tempDirection = antDirection;

  // checks if the ant is on a white space
  if (board[antRow][antColumn] == 0)
  {
    // if the direction + 1 is equal to 5, reset the 
    // direction to 1 (i.e. north)
    if (tempDirection + 1 == 5)
    {
      antDirection = 1;
      tempDirection = antDirection;
    }
    else
    {
      // adds 1 to direction indicating a right turn
      antDirection++;
      tempDirection = antDirection;
    }
  }
  
  else
  {
    // if the direction - 1 is equal to 0, reset the
    // direction to 4 (i.e. west) 
    if (tempDirection - 1 == 0)
    {
      antDirection = 4;
      tempDirection = antDirection;
    }
    else
    {
      // subtract 1 from direction indicating a left turn
      antDirection--;
      tempDirection = antDirection;
    }
  } 
  // checks if the ant is on the edge and facing out,
  // turns the ant around 
  antDirection = antAvoidDeath(tempDirection);
}

/*************************************************************
** Description: Function that moves the ant forward one space
   based on the direction the ant is facing. 
*************************************************************/
void Ant::antMove()
{
  if (antDirection == 1) // north
  {
    antRow--; // move ant up a space
  }
  else if (antDirection == 2) // east
  {
    antColumn++; // move ant a space to the right
  }
  else if (antDirection == 3) // south
  {
    antRow++; // move ant down a space 
  }
  else // west (by default)
  {
    antColumn--; // move ant a space to the left
  }
}

/*************************************************************
** Description: Function that returns a random number for
   the ant row location and the column location. The random
   number returned is between 1 and the number of columns or
   rows on the board.

   Solution derived from the following stack overflow post:
   https://stackoverflow.com/questions/40275512/how-to-
   generate-random-numbers-between-2-values-inclusive
*************************************************************/
void Ant::antRandomLocation()
{
  antColumn = rand() % boardColumns + 1; 
  antRow = rand() % boardRows + 1;
}
