/**********************************************************
** Description: This function gets input from the user and
   puts it into the array called matrix. The number
   of integers to get input from depends on the size of the
   array. A 3x3 array gets 9 integers from the user and a
   2x2 only gets 4. The arguments of function include
   the matrix (i.e. the matrix is derefenced so effectively
   the values in the matrix) and the arraySize. Note that
   the function directly modifies the array values, so as
   a result the function doesn't return anything.  
**********************************************************/

#include <iostream>
#include "readMatrix.hpp"

void readMatrix(int** matrix, int arraySize)
{        
  std::cout << "Enter " << arraySize << " integers to fill the array." << std::endl;
  
  // user input for a 3x3 array
  if (arraySize == 9)
  {
    for(int x = 0; x < 3; x++)
    {  
      for(int y = 0; y < 3; y++) 
      {
        std::cin >> matrix[x][y];
      }
    }
  }

  // user input for a 2x2 array
  else 
  {
    for(int x = 0; x < 2; x++)
    {
      for(int y = 0; y < 2; y++)
      {
        std::cin >> matrix[x][y];
      }
    }
  }
}
