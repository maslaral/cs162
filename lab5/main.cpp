/*************************************************************
** Program name: Lab 5
** Author: Alex Maslar
** Date: May 02 2019
** Description: Program that calls one of three functions based 
   on user input, including:
   1. reverse a string - takes string as an argument and returns
      the string in reverse order
   2. sum elements of an array - gets the user input for the size
      of the array, and then prompts the user for numbers to
      populate each element of the array
   3. calculate a triangular number - gets the user input for
      the number to calculate, and then calculates the 
      triangular number
   The user has the option to quit the program, or call another
   function. 
*************************************************************/
#include "print_reverse.hpp"
#include "sum_array.hpp"
#include "triangular_number.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>

int main(){
  
  // initialize variables
  std::string input;
  int* array;
  int element, array_size;

  // initialize menu objects, add options, and set limits
  Menu start("Select from the following functions:");
  start.addOptions("Print Reverse");
  start.addOptions("Sum Array");
  start.addOptions("Calculate Triangular Number");
  start.addOptions("Quit Program");
  Menu size_menu("Enter the size of the array:");
  size_menu.setLimits(1, 100);
  Menu triangle_menu("Enter an integer to find the triangular number:");
  triangle_menu.setLimits(1, 1000);
  Menu sum_array_menu;
  sum_array_menu.setLimits(0, 1000000);

  // continue to prompt the user until they select option
  // 4 - quit the program
  while (start.getUserInput() != 4){
    // start of program
    start.outputMenu();

    // switch statement that executes function based on user
    // input in menu
    switch(start.getUserInput()){
      // reverse string function
      case 1:
        // initialize the string input
        std::cout << "Enter a string to print in reverse:" << std::endl;

        std::cin.ignore(256, '\n');
        std::getline(std::cin, input);

        print_reverse(input);
        break;
        
       // sum array function
      case 2:
        // get array size user input
        size_menu.outputMenu();
        array_size = size_menu.getUserInput();

        // creates a new array based on user input
        array = new int[array_size];

        std::cout << "Enter integers to populate the array:" << std::endl;

        // user enters values until they've entered enough
        // to fill the array
        for (int i = 0; i < array_size; i++){
          std::cin >> element;

          // bool value to keep track if the user
          // entered incorrect numbers (i.e. not integers)
          bool repeat_attempt = false;

          // input validation
          while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid response - enter an integer" << std::endl;
            std::cin >> element;
            // subtracts one from i if the bool repeat_attempt is false
            // this is used to properly account for not entering an integer
            // and ensures multiple attempts don't add to the for loop
            // increment i 
            if (repeat_attempt != true){
              repeat_attempt = true;
              i--;
            }
          }
          
          // assigns the user entered value to the i position in the array
          array[i] = element;
        }

        // call the sum array function an d print the result
        std::cout << "The sum of the array = " << sum_array(array, array_size) << std::endl;
        
        // deallocate the array
        delete [] array;

        break;
        
      // triangular number function
      case 3:
        triangle_menu.outputMenu();

        // output result of function
        std::cout << "The triangular number of " << triangle_menu.getUserInput() << " = "
                  << triangular_number(triangle_menu.getUserInput()) << std::endl;
        break;
    }
  }
  return 0;
}
