/*************************************************************
** Program name: Langton's Ant
** Author: Alex Maslar
** Date: April 13 2019
** Description: Header file for the Ant class. The Ant class
   stores information about the ant, like the location on the
   board, the direction the ant is facing, and information the
   ant needs to know like the number of rows and columns on
   the board. The Ant class has functions to turn the ant, move
   the ant, and avoid death by turning the ant if it's about to
   step out of bounds.
*************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
  private:
    // stores the ant's locations on the board
    int antRow;
    int antColumn;
    // stores the direction the ant is currently facing
    int antDirection;
    // stores the number of rows and columns on the board
    int boardRows;
    int boardColumns;

  public:
    // ant constructors
    Ant();
    Ant(int, int);
    
    // getter functions to access the ant location
    int getAntRow();
    int getAntColumn();

    // setter function to set the ant intial location
    // and direction
    void setAntLocDir(int, int, int);

    // function to turn the ant
    void antTurn(int**);

    // function to change ant direction if about to
    // go out of bounds
    int antAvoidDeath(int);

    // function to move the ant 
    void antMove(); 

    // function to set a random location for the ant
    void antRandomLocation();
};

#endif
