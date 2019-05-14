/**********************************************************
** Description: The function calculates the determinant of
   the matrix. The first argument of the function is the
   matrix. The matrix is dereferenced so accessing the
   values in the array and not just addresses. Additionally,
   the matrix has the const operator to ensure values are
   not changed in the matrix from this function as it's not
   necessary. The second argument is the arraySize, which
   is used to determine the formula for calculating the
   matrix determinant.
**********************************************************/

#include <iostream>
#include "calcDeterminant.hpp"

int determinant(int** const matrix, int arraySize)
{

  int detValue;

  // calculates the determinant if the array is 2x2
  if (arraySize == 4)
  {
    detValue = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); 
  }
 
  // calculates the determinant if the array is 3x3
  else
  {
    detValue = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])) -
               matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0])) +
               matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])); 
  }

  return detValue;
}

