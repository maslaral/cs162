/*************************************************************
** Program name: Lab 9
** Author: Alex Maslar
** Date: June 02 2019
** Description: Palindrome function implementation which takes
   the user entered string and reverses its order through 
   STL container functions. 
*************************************************************/
#include "palindrome.hpp"

void palindrome(std::string user_input){
  std::stack<char> string_stack;
  int length = user_input.length();

  // storing user input to a stack
  for (int i = 0; i < length; i++){
    string_stack.push(user_input.at(i));
  }

  // print original user input
  std::cout << user_input;

  // print out each value in reverse and pop the stack
  for (int i = 0; i < length; i++){
    std::cout << user_input.at((length-1) - i);
    string_stack.pop();
  }
  std::cout << std::endl;
}
