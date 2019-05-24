/*************************************************************
** Program name: Project 4 
** Author: Alex Maslar
** Date:
** Drbescription:
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
    // set menu prompt
    void setPrompt(std::string);
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
