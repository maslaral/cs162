/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 23 2019
** Description: Implementation for function that seaches the 
   array for the user specified value.
*************************************************************/
#include "simple_search.hpp"
#include "Menu.hpp"

#include <iostream>

/*************************************************************
** Description: Simple search function that searches the array
   by looping through each value in the array until the value
   is found or the end of the array is reached.
*************************************************************/
std::string simple_search(int* array, int size, int input){
  int index = 0;        // subscript to search array
  bool found = false;   // flag to indicate when found
  std::string status;

  while (index < size && !found){
    if (array[index] == input){   // if value found
      found = true;               // set to true to exit
    }
    index++;
  }
  
  if (found == true){
    status = "Found";
  }
  else {
    status = "Not Found";
  }

  return status;
}
