/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 23 2019
** Description: Create the array for each file and returns
   the pointer to the array created. Creates the array by 
   first finding out the size needed (counts the number of lines
   in the text file) and then setting the elements from the 
   text file.
*************************************************************/
#include "create_array.hpp"

/*************************************************************
** Description: Function creates the array from the file and
   and returns the array.
*************************************************************/
int* create_array(std::string file_name, int size){
  // initialize stream and open file
  std::ifstream ifs;
  ifs.open(file_name);

  // initialize variables used in loops
  int input; 
  int pos = 0;

  int* array = new int[size];

  while (ifs >> input){
    array[pos] = input;
    pos += 1;     
  }

  return array;
}
