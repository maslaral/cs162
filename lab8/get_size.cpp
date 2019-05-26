/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 23 2019
** Description: Function that gets the size of the array.
*************************************************************/
#include "get_size.hpp"

/*************************************************************
** Description: Gets the size of the array by counting the 
   values in the file and returning the total to the main 
   function.
*************************************************************/
int get_size(std::string file_name){
  std::ifstream ifs;
  ifs.open(file_name);

  int input;
  int size = 0;

  // add up every value in the file
  while (ifs >> input){
    size += 1;   
  }

  return size;
}
