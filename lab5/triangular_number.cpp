/*************************************************************
** Program name: Lab 5
** Author: Alex Maslar
** Date: May 02 2019
** Description: Triangular number function that uses 
   recursion to calculate the triangular number of the value
   input by the user
*************************************************************/
#include "triangular_number.hpp"
/*************************************************************
** Description: Function that calculates the triangular number
   recursively by doing the following:
   1. Takes the number in the argument and adds it to 
      the number minus one 
   2. This repeats recursively until the number minus one is
      equal to one - at which point simply return one
*************************************************************/
int triangular_number(int N){
  // base case - if N is equal to 1, just return 1
  if (N == 1){
    return 1;
  }
  // recursive case - add N - 1 until n is equal to 1
  // and return it
  else {
    return N + triangular_number(N - 1);
  }
}
