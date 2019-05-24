/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 23 2019
** Description: 
*************************************************************/
#include "simple_search.hpp"
#include "Menu.hpp"

#include <iostream>

std::string simple_search(int* array, int size, int input){
  int index = 0;        // subscript to search array
  int position = -1;    // record position of search
  bool found = false;   // flag to indicate when found
  std::string status;

  while (index < size && !found){
    if (array[index] == input){   // if value found
      found = true;               // set to true to exit
      position = index;           // set position
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
