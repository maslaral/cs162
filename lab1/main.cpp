/**********************************************************
** Program name: Lab 1 - Create Matrix and Find Determinant 
** Author: Alex Maslar
** Date: 4-6-2019
** Description: This program dynamically creates an array
   and then requests the user to enter either 4 or 9
   integers. It uses two functions: 1) readMatrix which
   gets the user input for the matrix, and 2) determinant
   which calculates the determinant of the matrix based on
   its size and returns it to the main function. The program
   outputs the filled array and the determinant of the 
   matrix. 
**********************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "calcDeterminant.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
  // intializes the arraySize and option variables
  int arraySize, option;

  // asks for the user input
  cout << "How large do you want the array? Enter 1 or 2"
          " to select from the options." << endl;
  cout << "Option 1: 2x2" << endl;
  cout << "Option 2: 3x3" << endl;
  cin >> option;

  // makes sure that the option entered is valid (i.e. 1 or 2)
  while (option != 1 && option !=2)
  {
    cout << "Please select either Option 1 or 2." << endl;
    cin >> option;
  } 

  // sets the array size based on user input
  if (option == 1)
  {
    arraySize = 4;
  }
  if (option == 2)
  {
    arraySize = 9;
  }

  // dynamically allocates an array based on user input
  int** matrix = new int*[arraySize];
  for(int i = 0; i < arraySize; ++i)
  {
    matrix[i] = new int[arraySize];
  }
  
  // calls function for user input
  readMatrix(matrix,arraySize);

  // prints out the array if it's a 2x2 matrix
  if (arraySize == 4)
  {
    for (int x = 0; x < 2; ++x)
    {
      for (int y = 0; y < 2; ++y) 
      {
        cout << " " << matrix[x][y];
      }
      cout << endl;
    }
  }

  // prints out the array if it's a 3x3 matrix
  if (arraySize == 9)
  {
    for (int x = 0; x < 3; ++x)
    {
      for (int y = 0; y < 3; ++y) 
      {
        cout << " " << matrix[x][y];
      }
      cout << endl;
    }
  }

  // calls the function to return the determinant and prints it
  cout << "The determinant of the array is ";
  cout << determinant(matrix, arraySize) << "." << endl;

  // delete the elements of the array
  for (int x = 0; x < arraySize; ++x)
  {
    delete [] matrix[x];
  }

  // delete the array itself
  delete [] matrix;

  // setting matrix to nullptr to avoid dangling pointers
  matrix = nullptr;

  return 0;
}
