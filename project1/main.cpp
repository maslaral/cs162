/*************************************************************
** Program name: Langton's Ant
** Author: Alex Maslar
** Date: April 13 2019
** Description: Main function for the Langton's Ant program
   that calls functions in the Menu class to collect user input,
   passes that user input into the Board and Ant class, and
   ultimately prints the board the number of times specified
   by the user. 
*************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Board.hpp"
#include "Ant.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
  // setting prompt and options for the start menu
  Menu startMenu("Do you want to start the program?");
  startMenu.addOptions("Start the Simulation");
  startMenu.addOptions("Quit");

  // start program menu
  startMenu.outputMenu();

  // intialize the play again menu
  Menu playAgainMenu("Do you want to play again or quit?");
  playAgainMenu.addOptions("Play Again");
  playAgainMenu.addOptions("Quit");

  if (startMenu.getUserInput() == 1)
  {
    // executes the program until the user selects quit in the play again menu
    while (playAgainMenu.getUserInput() != 2)
    {
      // user prompt to specify the number of rows on the board
      Menu rowsMenu("Specify the number of board rows.");
      rowsMenu.setLimits(5, 250);
      rowsMenu.outputMenu();

      // user prompt to specify the number of columns on the board
      Menu columnsMenu("Specify the number of board columns.");
      columnsMenu.setLimits(5, 250);
      columnsMenu.outputMenu();

      // initialize the board
      Board antFarm(rowsMenu.getUserInput(), columnsMenu.getUserInput());

      // initialize and get output menu for the user to decide the ant location
      // or randomly generate
      Menu randomMenu("Do you want to set the ant's starting location?");
      randomMenu.addOptions("Yes, I want control.");
      randomMenu.addOptions("No, let the computer decide.");
      randomMenu.outputMenu();
 
      // initialize user prompt to decide the direction the ant is facing
      Menu antDirectionMenu("Set the direction the ant is facing.");
      antDirectionMenu.addOptions("North");
      antDirectionMenu.addOptions("East");
      antDirectionMenu.addOptions("South");
      antDirectionMenu.addOptions("West");

      // initializes the ant object (antMan) and passes the user input for the
      // number of columns and rows on the board - information the ant needs
      // to know when it's on the edge
      Ant antMan(rowsMenu.getUserInput(), columnsMenu.getUserInput());
    
      // if the user wants to decide the ant starting location
      if (randomMenu.getUserInput() == 1)
      {
        // prompt user for the ant row location
        Menu rowLocationMenu("Set the row where the ant is located.");
        rowLocationMenu.setLimits(1, rowsMenu.getUserInput());
        rowLocationMenu.outputMenu();

        // prompt user for the ant column location
        Menu columnLocationMenu("Set the column where the ant is located.");
        columnLocationMenu.setLimits(1, columnsMenu.getUserInput());
        columnLocationMenu.outputMenu();

        // output the ant direction menu
        antDirectionMenu.outputMenu();

        // create the ant with user defined starting location
        antMan.setAntLocDir(rowLocationMenu.getUserInput(), columnLocationMenu.getUserInput(), antDirectionMenu.getUserInput());
      }

      // if the user wants to randomly generate the starting location,
      // call the random location function and go to the next menu option
      else if (randomMenu.getUserInput() == 2)
      {
        // prompt the user for the ant direction
        antDirectionMenu.outputMenu();

        antMan.antRandomLocation();
      } 

      // prompts the user for the number of times to move the ant
      Menu numMovesMenu("Set the number of times the ant moves.");
      numMovesMenu.setLimits(1, 15606);
      numMovesMenu.outputMenu(); 

      // for loop that executes the ant movement and prints the board
      // as many times as specified by the user
      for (int i = 0; i < numMovesMenu.getUserInput(); i++)
      {
        // turn the ant based on the color of the space
        antMan.antTurn(antFarm.getBoard());
        // change the color of the space where the ant is located
        antFarm.flipColor(antMan.getAntRow(), antMan.getAntColumn());
        // move the ant forward one space in the direction its facing
        antMan.antMove();

        // print the board with the ant and the space colors
        antFarm.printBoard(antMan.getAntRow(), antMan.getAntColumn());
      } 
      // prompts the user if they want to play again - if yes, return to start
      // if no, then quit the program
      playAgainMenu.outputMenu();
    }  
  }
  return 0;
}
