/*************************************************************
** Program name: Langton's Ant
** Author: Alex Maslar
** Date: April 13 2019
** Description: The Board class represents the board that the
   ant interacts with. It contains information specific to the
   board, including the number of rows and columns and the 
   color of each space. The Board class has a function to
   dynamically allocate an array to the size specified by the
   user. It then destructs that array when the program ends. 
   In addition, it has a function to flip the color of the 
   space when the ant is positioned on it.
*************************************************************/
#include "Board.hpp"
#include <iostream>

/*************************************************************
** Description: Default constructor for the Board object, sets
   the board size to 0 rows and columns.
*************************************************************/
Board::Board()
{
  rows = 0; 
  columns = 0; 
}

/*************************************************************
** Description: Constructor for the Board object, passes the
   user input values for rows and columns. Intializes the
   board array to the size specified by the user and sets each
   space value to 0.
*************************************************************/
Board::Board(int r, int c)
{
  // set the row ant column numbers
  rows = r;
  columns = c;

  // create the board array
  board = new int*[rows];
  for (int i = 0; i < rows; i++)
  {
    board[i] = new int[columns];
  }
  
  // set the board so that each value is a 0 
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < columns; c++)
    {
      board[r][c] = 0;
    }
  }
}

/*************************************************************
** Description: Destructor for the board array to prevent 
   memory leaks. Deletes the board array and sets the board to
   nullptr. 
*************************************************************/
Board::~Board()
{
  for (int i = 0; i < rows; i++)
  {
    delete [] board[i];
  }
  
  delete [] board;
  board = nullptr;
}

/*************************************************************
** Description: Get function to pass the board to the ant 
   object. Used to check the ant location space color so the
   ant can know which direction to turn.
*************************************************************/
int** Board::getBoard()
{
  return board;
}

/*************************************************************
** Description: Get function to pass the board width to the 
   ant object. Used to check if the ant is on the edge of the
   board and generate a random number in an acceptable range.
*************************************************************/
int Board::getWidth()
{
  return columns;
}

/*************************************************************
** Description: Get function to pass the board height to the 
   ant object. Used to check if the ant is on the edge of the
   board and generate a random number in an acceptable range.
*************************************************************/
int Board::getHeight()
{
  return rows;
}

/*************************************************************
** Description: Function to flip the board color if the 
   ant is on the space. The ant row and column location are 
   passed to the function to know which space to change color.
*************************************************************/
void Board::flipColor(int antRow, int antColumn)
{
  if (board[antRow][antColumn] == 0)
  {
    board[antRow][antColumn] = 1;
  }
  else
  {
    board[antRow][antColumn] = 0;
  }
}

/*************************************************************
** Description: Function to print the board. The ant location
   is passed to the function to know where to print the ant.
   If the space is equal to 0, print a blank space. If the 
   space is equal to 1, print a #. If the ant is at the space,
   print a *.  
*************************************************************/
void Board::printBoard(int antRow, int antColumn)
{
  // print the top border of the board
  for (int c = 0; c < (columns + 2); c++)
  {
    std::cout << "-";
  }
  std::cout << std::endl;

  for (int r = 0; r < rows; r++)
  {
    // print the right border of the board
    std::cout << "|";
    // print the board
    for (int c = 0; c < columns; c++)
    {
      // set each space to blank by default
      char space = 32;
      // at the ant location, set space to *
      if (r == antRow && c == antColumn)
      {
        space = '*';
      }
      // if the space is equal to 1, set space to #
      else if (board[r][c] == 1)
      {
        space = '#';
      }
      // print out the spaces of the board
      std::cout << space;
    }
    // print the left border of the board
    std::cout << "|" << std::endl;
  }

  // print the bottom border of the board
  for (int c = 0; c < (columns + 2); c++)
  {
    std::cout << "-";
  }
  std::cout << std::endl;
}
