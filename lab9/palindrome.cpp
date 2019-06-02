/*************************************************************
** Program name: Lab 9
** Author: Alex Maslar
** Date: June 02 2019
** Description: Palindrome function implementation which takes
   the user entered string and reverses its order through 
   STL container functions. 
*************************************************************/
#include "palindrome.hpp"

void palindrome(){
 
  std::string user_input;
  
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Enter a word to reverse" << std::endl;      
  std::cout << "---------------------------------------------" << std::endl;

  std::cin >> user_input;

  std::stack<char> string_stack;

  // store user input in stack
  for (int i = 0; i < user_input.length(); i++){
    string_stack.push(user_input.at(i));
  }

  // print original user input
  std::cout << user_input;

  // print in reverse and pop
  while (!string_stack.empty()){
    std::cout << string_stack.top();
    string_stack.pop();
  }
  std::cout << std::endl;
}
