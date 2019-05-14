/*************************************************************
** Program name: Lab 6
** Author: Alex Maslar
** Date: May 12 2019
** Description: The menu class represents the user menu. It
   contains information about the menu that is presented to the
   user, including the prompt, the options presented, the
   minimum and maximum values allowed for entry, and finally
   the user input itself. In addition, the class contains
   methods that check that the user input is within the min and
   max range. The Menu class can be called without options and
   it then accepts integer values. With options, it presents
   options to the user and accepts an integer value related to
   one of those options.
*************************************************************/

#include <iostream>
#include "Menu.hpp"
#include <vector>
#include <string>

/*************************************************************
** Description: Default constructor for the Menu object, sets
   the prompt to a default value and the number of options to
   0. The limits of the menu are 0 and 100 by default.
*************************************************************/
Menu::Menu()
{
  prompt = "Enter an integer: ";
  numOptions = 0;
  setLimits(0, 100);
  userInput = 1;
}

/*************************************************************
** Description: Constructor for the Menu object, sets the
   menu prompt for user input.
*************************************************************/
Menu::Menu(std::string p)
{
  prompt = p;
  numOptions = 0;
  setLimits(0, 100);
  userInput = 1;
}

/*************************************************************
** Description: Get function used to access the user input 
   outside of the class. This is used to pass these values to 
   the Board and Ant class.
*************************************************************/
int Menu::getUserInput()
{
  return userInput;
}

/*************************************************************
** Description: Function to add options to the menu. Takes the
   option title as an argument, and expands the vector. It adds
   one to the number of options - variable is used to print the
   options.
*************************************************************/
void Menu::addOptions(std::string o)
{
  options.push_back(o);
  numOptions++;
}

/*************************************************************
** Description: Function that prints the user prompt and menu
   of options. If no options are added, it defaults to
   accepting an integer value. The function also calls the
   integer and choice validation functions to ensure an option
   is specified and the integer is within the min and max
   range.
*************************************************************/
void Menu::outputMenu()
{
  // print the prompt
  std::cout << "---------------------------------------------------------" << std::endl;
  std::cout << prompt << std::endl;      
  std::cout << "---------------------------------------------------------" << std::endl;

  // if there are options, print them and validate
  // and call the validation function to check the user input
  if (numOptions > 0)
  {
    for (int i = 0; i < numOptions; i++)
    {
      std::cout << "Option " << i + 1 << ": " 
                << options[i] << std::endl;
    }
    // calls the validation function
    choiceValidation();
  }
  // if there are no options, validate the integer is in the
  // acceptable range
  else
  {
    integerValidation();
  }
}

/*************************************************************
** Description: Function to set the minimum and maximum values
   the user can input. This data is used in the input validation
   functions.
*************************************************************/
void Menu::setLimits(int min, int max)
{
  minValue = min;
  maxValue = max;
}

/*************************************************************
** Description: Function to get the user integer input and 
   check if it is in the min and max range specified in the 
   main function.
*************************************************************/
void Menu::integerValidation()
{
  // gets the user input
  std::cin >> userInput;

  // checks if the value is an integer and if it is in the min and max
  // range specified in the main function - if not, ask user for input
  // again
  while (std::cin.fail() || userInput > maxValue || userInput < minValue)
  {
    std::cout << "Invalid response. Please enter an integer from "
         << minValue << " to " << maxValue << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> userInput;
  }
}

/*************************************************************
** Description: Function to get the user option selection and
   check that they choice an option. 
*************************************************************/
void Menu::choiceValidation()
{
  std::cin >> userInput;

  // checks if the user input is an integer and within the number of
  // options in the menu - if not, then it prompts the user to enter
  // again
  while (std::cin.fail() || userInput > numOptions || userInput < 1)
  {
    std::cout << "Invalid response. Please choose from options 1 to " << numOptions << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> userInput;
  }
}
