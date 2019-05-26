/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 24 2019
** Description: Implementation of the binary search function 
   which searches the sorted array.  
*************************************************************/
#include "binary_search.hpp"
#include "create_array.hpp"

#include <iostream>

/*************************************************************
** Description: Binary serach function takes the file name,
   size, and search value as arguments. It first creates an array
   from the sorted files. Then, gets the middle value in the
   array and checks if it is less than or greater the search
   value. If less than, the next time it searches it will get
   the middle value in the lower half of the array. If greater,
   it will get the upper value. This stops when the value
   has been found or if it does not exist in the array.
*************************************************************/
std::string binary_search(std::string file_name, int size, int input){

  // creates an array from the sorted file
  int* array = create_array(file_name, size);

  int first = 0,
      last = size - 1,
      middle;

  std::string status;

  // flag for whether the value is found
  bool found = false;

  // search the array until value found or determined
  // doesn't exist
  while (!found && first <= last){
    middle = (first + last) / 2;
    if (array[middle] == input){
      found = true;
    }
    else if (array[middle] > input){
      last = middle - 1;
    }
    else {
      first = middle + 1;
    }
  }
  
  // set the status to found or not found to return
  if (found){
    status = "Found";
  }
  else {
    status = "Not Found";
  }

  delete [] array;
  return status;

}
      


