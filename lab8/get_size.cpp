/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 23 2019
** Description: 
*************************************************************/
#include "get_size.hpp"

int get_size(std::string file_name){
  std::ifstream ifs;
  ifs.open(file_name);

  int input;
  int size = 0;

  while (ifs >> input){
    size += 1;   
  }

  return size;
}
