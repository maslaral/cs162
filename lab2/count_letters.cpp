/*************************************************************
** Program name: Lab 2 - File I/O
** Author: Alex Maslar
** Date: April 14 2019
** Description: Function that counts the number of letters in 
   the input file. 
*************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include "output_letters.hpp"

/*************************************************************
** Description: This function takes an ifstream and an array
   initialized to 0 for each element as its arguments. It
   gets a line from the input file, evaluates each in a for
   loop to check if it is equal to a letter, and ends when
   it either reaches the end of the paragraph or file (reaches
   a newline character). The function then creates an ofstream
   and passes it to and calls the function output_letters. It
   then loops through again (if not EOF) and create another
   file for the next paragraph in the input file. This
   function is called from the main function.
*************************************************************/
void count_letters(std::ifstream& ifs, int* letterArray)
{
  std::string input;
  char v;

  // while loop that executes while the getline function gets
  // a line (i.e. until EOF)
  while (std::getline(ifs, input))
  {
    // initialize a string stream
    std::stringstream ss;
    // send the getline data to the stringstream
    ss << input;
    // while loop that sends each character in the line to v
    // until there are no more characters of it reaches the new 
    // line character 
    while (ss >> v && v != '\n')
    {
      for (int i = 0; i < 26; ++i)
      {
        // checks if the character is equal to either a lower
        // case or upper case character
        if (v == (i + 97) || v == (i + 65))
        {
          // counts the number of times the letter appears in
          // file and stores it in the array
          letterArray[i] += 1;
        }
      }
    }
    // initialize an ofstream object
    std::ofstream ofs;
    // call the output_letters function - send the ofstream
    // object and array
    output_letters(ofs, letterArray);
    for (int i = 0; i < 26; ++i)
    {
      letterArray[i] = 0;
    }
  }
}

