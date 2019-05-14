/*************************************************************
** Program name: Langton's Ant
** Author: Alex Maslar
** Date: April 13 2019
** Description: Header file for the Board class. The Board
   class contains private variables representing characteristics
   of the board, including the number of columns and rows. 
   The class intializes a dynamic array called board that is
   used to save the board space colors and ant location.
*************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
  private:
    // stores the board size
    int columns;
    int rows;
    // the board 2-D array
    int** board;

  public:
    // constructors
    Board();
    Board(int, int);
    // destructor
    ~Board();
    // prints the board
    void printBoard(int, int);
    // gets information about the board size to pass to
    // the ant
    int** getBoard();
    int getWidth();
    int getHeight();
    // flips the color of the space based on its current
    // color
    void flipColor(int, int);
};

#endif
