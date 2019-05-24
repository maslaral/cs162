/*************************************************************
** Program name:
** Author: Alex Maslar
** Date: May 24 2019
** Description: 
*************************************************************/
#include "binary_search.hpp"
#include "create_array.hpp"

#include <iostream>

std::string binary_search(std::string file_name, int size, int input){

  int* array = create_array(file_name, size);

  int first = 0,
      last = size - 1,
      position = -1,
      middle;

  std::string status;

  bool found = false;

  while (!found && first <= last){
    middle = (first + last) / 2;
    if (array[middle] == input){
      found = true;
      position = middle;
    }
    else if (array[middle] > input){
      last = middle - 1;
    }
    else {
      first = middle + 1;
    }
  }
  
  if (found){
    status = "Found";
  }
  else {
    status = "Not Found";
  }
  return status;
}
      


