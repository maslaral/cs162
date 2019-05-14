/*************************************************************
** Program name: Lab 5
** Author: Alex Maslar
** Date: May 02 2019
** Description: Reverse print function that takes a string
   and outputs it in reverse order. 
*************************************************************/
#include "print_reverse.hpp"
#include <iostream>
#include <string>

/*************************************************************
** Description: Recursive function that does the following:
   1. gets the length of the string passed to the function
   2. prints the last character from the string
   3. subtracts the last character from the string
   4. calls the function again (with the same string minus
      the last character)
   5. repeats this until the string has just one character
      remaining, at which point it prints that character
      and goes to a new line
*************************************************************/
void print_reverse(std::string string_to_reverse){

  // variable to set the string length
  int string_length = string_to_reverse.length();

  // base case - if one character remains, print out
  // that character and end line
  if (string_length == 1){
    std::cout << string_to_reverse[0] << std::endl;
  }
  // recursive case - print the last character of the 
  // string, remove that last character from the string,
  // call the function again
  else {
    std::cout << string_to_reverse[string_length - 1];
    string_to_reverse = string_to_reverse.substr(0, (string_length - 1));
    print_reverse(string_to_reverse);
  }
}

