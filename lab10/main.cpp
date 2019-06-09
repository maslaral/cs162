/*************************************************************
** Program name: Lab 10
** Author: Alex Maslar
** Date: June 09 2019
** Description: Main function which gets the user input, calls
   the functions to calculate the Fibonacci numbers, and keeps
   track of the execution time for both the recursive and non-
   recursive functions.
*************************************************************/
#include "Fibonacci_NR.hpp"
#include "Fibonacci_R.hpp"
#include "Menu.hpp"

#include <iostream>
#include <chrono>
#include <unistd.h>

int main(){
  // initialize menu and prompt user
  Menu start_menu("What number in the sequence?");
  start_menu.outputMenu();

  int user_input = start_menu.getUserInput();

  // External source for chrono code: 
  // techiedelight.com/measure-elapsed-time-program-chrono-library
  auto start = std::chrono::steady_clock::now();  // start the clock
  Fibonacci_NR non_recursive(user_input);         // call function
  non_recursive.PrintFibonacci();                 // print result
  auto end = std::chrono::steady_clock::now();    // end the clock

  // print the time in microseconds
  std::cout << "Non-recursive execution time (ms): " 
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;

  start = std::chrono::steady_clock::now();       // start the clock
  Fibonacci_R recursive(user_input);              // call function
  recursive.PrintFibonacci();                     // print result
  end = std::chrono::steady_clock::now();         // end the clock

  // print the time in microseconds
  std::cout << "Recursive execution time (ms): " 
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;

  return 0;
}
