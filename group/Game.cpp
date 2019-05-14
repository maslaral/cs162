/*************************************************************
** Program name: Game.hpp
** Author: Group 1 
** Date: May 11 2019
** Description: Implementation of the Game class. The Game
   class represents a predator-prey simulation game. The
   predators are doodlebugs and the prey are ants. The doodlebugs
   and ants will move around a grid and the doodlebugs will
   try to eat the ants. Doodlebugs and ants can breed (spawning
   more doodlebugs/ants) if they survive long enough. Doodlebugs
   starve if too much time passes without them having eaten an
   ant. There are member variables for the number of doodlebugs
   and ants alive, for the number of rows and columns, the 
   number of steps in the game, and the grid itself which is
   a 2-d array of pointers to Critter objects. These pointers
   can point to Doodlebug or Ant objects since these classes are
   derived from Critter. Member functions include a default
   constructor which will initialize member variables with 
   default values, getters and setters for member variables, 
   a play function which starts and plays the game, a printGrid
   function which displays the grid with the ants and doodlebugs
   on it, a startMenu function which displays a menu and allows
   the user to specify starting options, and allocGrid which
   dynamically allocates memory for the grid and starting Ant
   and Doodlebug objects.
*************************************************************/
#include "Game.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*************************************************************
** Description: Default constructor used to initialize member
   variables with default values.
*************************************************************/
Game::Game() : numRows{20}, numCols{20}, numAnts{100}, numBugs{5}, numSteps{100}
{
}

/*************************************************************
** Description: Getter functions to return the number of rows,
   cols, ants, doodlebugs, steps, and the grid itself.
*************************************************************/
int Game::getNumRows()
{
  return numRows;
}

int Game::getNumCols()
{
  return numCols;
}

int Game::getNumAnts()
{
  return numAnts;
}

int Game::getNumBugs()
{
  return numBugs;
}

int Game::getNumSteps()
{
  return numSteps;
}

Critter ***Game::getGrid()
{
  return grid;
}

/*************************************************************
** Description: Setter functions to set the number of rows,
   columns, ants, doodlebugs, and steps.
*************************************************************/
void Game::setNumRows(int r)
{
  numRows = r;
}

void Game::setNumCols(int c)
{
  numCols = c;
}

void Game::setNumAnts(int a)
{
  numAnts = a;
}

void Game::setNumBugs(int b)
{
  numBugs = b;
}

void Game::setNumSteps(int s)
{
  numSteps = s;
}

/*************************************************************
** Description: Function first calls allocGrid() to allocate
   memory for the grid and the doodlebugs and ants on it. It
   then runs through the user-specified number of steps, first
   calling the move() function on doodlebugs on the grid, then
   calling the move() function on the ants on the grid, then
   calling the breed() function on the doodlebugs, and finally
   calling the breed() function on the ants. This completes
   a step, so the grid is printed.
*************************************************************/
void Game::play()
{ 
  printGrid(); // print the initial grid

  for (int i = 0; i < numSteps; i++) // run for the user-specified num of steps
  { 
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c])
        {
          grid[r][c]->setHasMoved(false); // set hasMoved to false to begin
        }
      }
    }

    // move the doodlebugs
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c])
        {
          if (grid[r][c]->kind() == DOODLEBUG && grid[r][c]->getHasMoved() == false)
          {
            grid[r][c]->move(r, c, numRows, numCols, grid);
          }
        }
      }
    }

    // increment steps survived for doodlebugs
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c] != nullptr)
        {
          if (grid[r][c]->kind() == DOODLEBUG)
          {
            grid[r][c]->setStepsSurvived(grid[r][c]->getStepsSurvived() + 1);
          }
        }
      }
    }

    // move the ants
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c] != nullptr)
        {
          if (grid[r][c]->kind() == ANT && grid[r][c]->getHasMoved() == false)
          {
            grid[r][c]->move(r, c, numRows, numCols, grid);
          }
        }
      }
    }

    // increment steps survived for ants
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c] != nullptr)
        {
          if (grid[r][c]->kind() == ANT)
          {
            grid[r][c]->setStepsSurvived(grid[r][c]->getStepsSurvived() + 1);
          }
        }
      }
    }

    // breed the doodlebugs
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c])
        {
          if (grid[r][c]->kind() == DOODLEBUG)
          {
            grid[r][c]->breed(r, c, numRows, numCols, grid);
          }
        }
      }
    }

    // breed the ants
    for (int r = 0; r < numRows; r++)
    {
      for (int c = 0; c < numCols; c++)
      {
        if (grid[r][c])
        {
          if (grid[r][c]->kind() == ANT)
          {
            grid[r][c]->breed(r, c, numRows, numCols, grid);
          }
        }
      }
    }

    // print the grid at the end of the step
    printGrid();
  }
}

/*************************************************************
** Description: Function dynamically allocates memory for a 
   2D array of pointer to Critter objects. It then dynamically
   allocates memory for Doodlebug and Ant objects, which are
   initialized and placed on the grid in random locations.
*************************************************************/
void Game::allocGrid()
{
  int row;         // represents a row number in the grid
  int col;         // represents a column number in the grid
  int counter = 0; // tracks num of Doodlebugs/Ants placed

  // allocate memory for the rows of the grid
  grid = new Critter **[numRows];

  // allocates memory in each row for an array of pointers to Critter objects
  for (int r = 0; r < numRows; r++)
  {
    grid[r] = new Critter *[numCols];
    for (int c = 0; c < numCols; c++)
    {
      grid[r][c] = nullptr; // set all elements to nullptr
    }
  }

  // initialize Doodlebug objects in rand locations
  while (counter < numBugs)
  {
    row = rand() % numRows;
    col = rand() % numCols;

    if (!grid[row][col])
    {
      grid[row][col] = new Doodlebug();
      counter++;
    }
  }

  // initialize Ant objects in rand locations
  counter = 0;
  while (counter < numAnts)
  {
    row = rand() % numRows;
    col = rand() % numCols;

    if (!grid[row][col])
    {
      grid[row][col] = new Ant();
      counter++;
    }
  }
}

/*************************************************************
** Description: Function goes through every element in the grid
   and if a pointer is pointing to a Doodlebug or Ant object,
   memory for the object is deallocated. THen memory for the
   array in each row is deallocated, followed by the rows
   themselves.
*************************************************************/
void Game::deallocGrid()
{ 
  // deallocate Doodlebug/Ant objects
  for (int r = 0; r < numRows; r++)
  {
    for (int c = 0; c < numCols; c++)
    {
      if (grid[r][c])
      {
        delete grid[r][c];
        grid[r][c] = nullptr;
      }
    }
  }
  // deallocate array in each row
  for (int r = 0; r < numRows; r++)
  {
    delete[] grid[r];
  }
  // deallocate rows
  delete [] grid;
}

/*************************************************************
** Description: Function prints the grid for a 2D array of 
   pointers to Critter objects. Ants are represented by 'O's, 
   Doodlebugs are represented by 'X's, and empty grid locations
   are represented by ' ' spaces. Utilizes kind() function of
   the Critter class to determine which character should be 
   output.
*************************************************************/
void Game::printGrid()
{
  for (int c = 0; c < numCols + 2; c++)
  {
    cout << "="; // prints top border
  }
  cout << endl;

  // prints ' ' for empty, 'O' for ants, 'X' for doodlebugs
  for (int r = 0; r < numRows; r++)
  { 
    cout << '|'; // prints left border

    for (int c = 0; c < numCols; c++)
    {
      if (grid[r][c] != nullptr)
      {
        if (grid[r][c]->kind() == ANT)
        {
          cout << 'O';
        }
        else if (grid[r][c]->kind() == DOODLEBUG)
        {
          cout << 'X';
        }
      }
      else
      {
        cout << ' ';
      }
    }

    cout << '|'; // prints right border
    cout << endl;
  }

  for (int c = 0; c < numCols + 2; c++)
  {
    cout << "="; // prints bottom border
  }
  cout << endl;
}


/*************************************************************
** Description: Function displays the main menu. The user has
   the option of selecting choices 1-5. The choice is validated
   in the function menuChoice(). The choices include:
   1. starts the game by running play()
   2. sets the number of steps to run
   3. sets the number of rows and columns
   4. sets the number of ants and doodlebugs
   5. calls deallocGrid() and exits the program
*************************************************************/
void Game::displayMenu()
{
  cout << "Welcome to a Predator-Prey simulation!" << endl;
  cout << "There is ***EXTRA CREDIT*** implemented in this program." << endl;
  cout << "Please select from the following menu choices: " << endl;
  cout << "Enter '1' to start the program. " << endl;
  cout << "Enter '2' to change the number of steps to run. " << endl;
  cout << "Enter '3' to change the number of rows and columns (Extra Credit). " << endl;
  cout << "Enter '4' to change the number of ants and doodlebugs (Extra Credit). " << endl;
  cout << "Enter '5' to exit the program. " << endl;
}

void Game::menuChoice()
{
  int userChoice; // stores the user's menu choice

  do
  { 
    displayMenu(); // display the menu

    userChoice = validateInt(1); // gets user choice and validates

    // menu options for user, gets required user input, runs functions
    switch (userChoice)
    {
    case 1:
    {
      int choice; // represent user's choice to play again or exit

      allocGrid(); // allocate memory for the grid and Critters
      play();

      cout << "Would you like to play again using the grid as is? (1 = yes, 2 = no): ";
      choice = validateInt(5);
      while (choice == 1)
      {
        cout << "Please enter the number of steps you would like: " << endl;
        setNumSteps(validateInt(2));
        play();
        cout << "Would you like to play again using the grid as is? (1 = yes, 2 = no): ";
        choice = validateInt(5);
      }

      deallocGrid(); // deallocate grid and Critters
      break;
    }

    case 2:
    {
      cout << "Please enter the number of steps you would like: " << endl;
      setNumSteps(validateInt(2));
      break;
    }

    case 3:
    {
      cout << "Please enter the number of rows you would like: " << endl;
      setNumRows(validateInt(6));
      cout << "Please enter the number of columns you would like: " << endl;
      setNumCols(validateInt(6));
      while (numRows * numCols < numAnts + numBugs)
      {
        cout << "The grid is too small for the number of ants and doodlebugs you currently have." << endl;
        cout << "Please increase the size of the board." << endl;
        cout << "Please enter the number of rows you would like: " << endl;
        setNumRows(validateInt(6));
        cout << "Please enter the number of columns you would like: " << endl;
        setNumCols(validateInt(6));
      }
      break;
    }

    case 4:
    {
      cout << "Please enter the number of Ants you would like: " << endl;
      setNumAnts(validateInt(3));
      cout << "Please enter the number of Doodlebugs you would like: " << endl;
      setNumBugs(validateInt(4));
      break;
    }

    case 5:
    {
      cout << "Goodbye." << endl;
      return;
    }
    }
  } while (userChoice != 5); // keep looping until user enters 5 to quit
}

/*************************************************************
** Description: Function validates the integer inputs by the
   user for the main menu of the game - menuChoice(). It 
   accepts an integer input to select the range of valid inputs
   desired for the option being selected. It returns an integer
   to either set values in the Game class or select a choice
   in the switch statement of menuChoice().
*************************************************************/
int Game::validateInt(int range)
{
  // float validation adapted from: https://www.quora.com/How-do-I-check-if-a-number-is-float-on-C++
  double choice = 0.0;
  int floatTest = 0;

  int upperLim = 0;
  int lowerLim = 0;
  string message;

  // range for main menu choice, 1 - 5
  if (range == 1)
  {
    message = "Please enter a valid integer 1, 2, 3, 4, or 5.";
    upperLim = 5;
    lowerLim = 1;
  }
  // range for steps, 1 - 32767
  else if (range == 2)
  {
    message = "Please enter a valid integer > 1, < 32767. ";
    upperLim = 32767;
    lowerLim = 1;
  }
  // range for ants, 0 - rows*columns
  else if (range == 3)
  {
    message = "Please enter a valid integer in the range of 0 - " + std::to_string(getNumRows() * getNumCols()) + ": ";
    upperLim = (getNumRows() * getNumCols());
    lowerLim = 0;
  }
  // range for doodlebugs, 0 - rows*columns - numAnts
  else if (range == 4)
  {
    message = "Please enter a valid integer in the range of 0 - " + std::to_string((getNumRows() * getNumCols()) - getNumAnts()) + ": ";
    upperLim = (getNumRows() * getNumCols()) - getNumAnts();
    lowerLim = 0;
  }
  // range for menu choice, after playing a game
  else if (range == 5)
  {
    message = "Please enter a valid integer in the range of 1 - 2: ";
    upperLim = 2;
    lowerLim = 1;
  }
  // range for the number of rows and columns
  else if (range == 6)
  {
    message = "Please enter a valid integer in the range of 1 - 100: ";
    upperLim = 100;
    lowerLim = 1;
  }

  while (true)
  {
    // detects invalid string/char input and reprompts user
    while (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << message << endl;
    }
    // detects float input, out of range input
    floatTest = choice * 100000000.0;
    if (((floatTest % 100000000) > 0) || choice < lowerLim || choice > upperLim)
    {
      // clears extraction failure flag
      cin.clear();
      // ignores next 10000 inputs in the buffer until \n
      cin.ignore(10000, '\n');
      cout << message << endl;
    }
    // valid input, returns integer
    else
    {
      cin.ignore(10000, '\n');
      return choice;
    }
  }
}
