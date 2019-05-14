/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Zoo tycoon Menu class. 
   Declares the functions and variables used in the Menu
   objects.
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
    // stores the value entered by the user
    int userInput;
    // min and max values used for integer validation
    int minValue;
    int maxValue;
  public:
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
};

#endif
