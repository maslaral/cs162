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
#ifndef CREATE_ARRAY_HPP
#define CREATE_ARRAY_HPP

#include <string>
#include <fstream>

int* create_array(std::string, int);

#endif
