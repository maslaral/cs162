/*************************************************************
** Program name: Lab 2 - File I/O
** Author: Alex Maslar
** Date: April 14 2019
** Description: Main function that initializes an array where
   each element is equal to 0, gets the input file name from
   the user (and re-prompts if an invalid name is provided), 
   and calls the count_letters function. It passes the array
   and input file stream to the function.
*************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "count_letters.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;


int main()
{
  string inputFileName;
  // initializes the 1-d array of 26 elements
  int letterArray[26] = {0};
  // boolean value for if a ifstream fails
  bool fileFailed;

  // prompt the user for the file name to get letter counts from 
  cout << "What file would you like read?" << endl;
  cin >> inputFileName;

  // create an ifstream to the file name specified by the user
  std::ifstream ifs(inputFileName);

  // check to see if the ifstream failed (i.e. file didn't exist) 
  fileFailed = ifs.fail();

  // while loop to reprompt the user if the file name was invalid
  while (fileFailed)
  {
    cout << "File name does not exist. Please enter a valid file name." << endl;
    cin >> inputFileName;
    std::ifstream ifs(inputFileName);
    fileFailed = ifs.fail();
    count_letters(ifs, letterArray);
  }

  // calls the function if the the ifstream didn't fail
  count_letters(ifs, letterArray);

  return 0;
}
