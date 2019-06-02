/*************************************************************
** Program name: Lab 9
** Author: Alex Maslar
** Date: June 02 2019
** Description: Buffer function header file that takes
   the number of rounds, add percent, and subtract percent from
   the user as arguments. It generates a random number for
   each round to potentially add to the buffer, and then 
   generates a random percent chance for adding and subtracting
   which are compared to the user provided percentages. If less
   than either, it will add/subtract from the buffer. After
   each round, print out the buffer values and the size of the
   buffer.
*************************************************************/
#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <queue>
#include "Menu.hpp"

void buffer();

#endif
