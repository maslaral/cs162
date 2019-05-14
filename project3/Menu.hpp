/*************************************************************
** Program name: Lab 5
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Menu class. The Menu class
   has variables specific to the user menu, including the 
   prompt presented to the user, the options, min and max
   values, and user input. The Menu class also includes functions
   like addOptions (which is used to add an option to the user
   menu) and validation methods (which checks if the user input
   is within the min and max ranges set for the menu).
*************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

class Menu
{
  private:
    // menu prompt 
    std::string prompt;
    // vector that holds the options of the menu 
    std::vector<std::string> options;
    // number of options in the menu
    int numOptions;
    // min and max values used for integer validation
    int minValue;
    int maxValue;
  public:
    int userInput;
    // default constructor
    Menu();
    // create the menu with a prompt
    Menu(std::string);
    // add options to the menu
    void addOptions(std::string);
    // output the menu of choices
    void outputMenu();
    // set the min and max values
    void setLimits(int, int);
    // input validation methods
    void integerValidation();
    void choiceValidation();
    // get function that gets the user input
    int getUserInput();
    friend class Game;
};

#endif
