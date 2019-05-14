/*************************************************************
** Program name: Lab 5
** Author: Alex Maslar
** Date: May 02 2019
** Description: Function definition for adding up the values of
   an array and returning that value to the main function.
*************************************************************/
#include "sum_array.hpp"

/*************************************************************
** Description: Recursive function that performs the following
   steps to sum an array:
   1. subtracts one from the size passed into the function
   2. declares a new array one size less than the array passed
      into the function
   3. copies the values from the array passed to the function
      into the new array - except for the last element
   4. assign the last element the sum of the last two elements
      of the array passed to the function
   5. call the function again with the new array and the size
      minus one
   6. repeat until the size of the array is one, at which
      point return the element
*************************************************************/
int sum_array(int* array_to_be_summed, int size){

  // base function - checks if there is only one element
  // left in the array, if there is return that element
  if (size == 1){
    return array_to_be_summed[0];
    delete [] array_to_be_summed;
  }
  
  else {
    // takes the last two values of the array and adds them together, then assigns it to the
    // second to last element
    array_to_be_summed[size - 2] = array_to_be_summed[size - 2] + array_to_be_summed[size - 1];
    // reassigns the last value to 0
    array_to_be_summed[size - 1] = 0;

    // decrements the size before calling function again
    size--;
    // calls the function recursively
    sum_array(array_to_be_summed, size);

  }
}
