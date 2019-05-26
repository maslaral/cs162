/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 23 2019
** Description: Main function which creates the arrays to
   store the file values. It then coordinates the user menu
   and calls the necessary functions based on user input.
*************************************************************/ 
#include "get_size.hpp" 
#include "create_array.hpp"
#include "simple_search.hpp"
#include "sort_array.hpp"
#include "binary_search.hpp"
#include "Menu.hpp"

#include <iostream>

int main(){

  // get size of each array needed
  int size_beginning = get_size("beginning.txt");
  int size_middle = get_size("middle.txt");
  int size_end = get_size("end.txt");
  int size_original = get_size("original.txt");
  
  // create arrays from text files
  int* beginning = create_array("beginning.txt", size_beginning);
  int* middle = create_array("middle.txt", size_middle);
  int* end = create_array("end.txt", size_end);
  int* original = create_array("original.txt", size_original);

  // initialize file names for sorted
  std::string sorted_beginning;
  std::string sorted_middle;
  std::string sorted_end;
  std::string sorted_original;

  // initialize variables used in menus
  int input;
  bool sorted = false;

  Menu functions("Choose from the following options:");
  functions.addOptions("Simple search");
  functions.addOptions("Sort numbers");
  functions.addOptions("Binary search");
  functions.addOptions("Exit");

  Menu search_value("Enter a value to search for:");

  // continue reprompting with menu until user selects exit
  while (functions.getUserInput() != 4){

    functions.outputMenu();
    
    switch (functions.getUserInput()){
      case 1:  // simple search
      {
        search_value.outputMenu();
        input = search_value.getUserInput();

        std::cout << "Beginning file: " << simple_search(beginning, size_beginning, input) << std::endl;
        std::cout << "Middle file:    " << simple_search(middle, size_middle, input) << std::endl;
        std::cout << "End file:       " << simple_search(end, size_end, input) << std::endl;
        std::cout << "Original file:  " << simple_search(original, size_end, input) << std::endl;
        std::cout << std::endl;
      }
      break;
      case 2:  // sort array
      {
        sorted_beginning = sort_array(beginning, size_beginning);
        sorted_middle = sort_array(middle, size_middle); 
        sorted_end = sort_array(end, size_end);
        sorted_original = sort_array(original, size_original);
        sorted = true;
      }
      break;
      case 3:  // binary search
      {
        if (sorted){
          search_value.outputMenu();
          input = search_value.getUserInput();

          std::cout << "Beginning file: " << binary_search(sorted_beginning, size_beginning, input) << std::endl;
          std::cout << "Middle file:    " << binary_search(sorted_middle, size_middle, input) << std::endl;
          std::cout << "End file:       " << binary_search(sorted_end, size_end, input) << std::endl;
          std::cout << "Original file:  " << binary_search(sorted_original, size_original, input) << std::endl;
          std::cout << std::endl;
        }
        else {
          std::cout << "Sort numbers before performing a binary search" << std::endl;
          std::cout << std::endl;
        }
      }
      break;
    }
  }

  // delete the arrays
  delete [] beginning;
  delete [] middle;
  delete [] end;
  delete [] original;

  return 0;
}
