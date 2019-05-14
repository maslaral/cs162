/*************************************************************
** Program name: Lab 2 - File I/O
** Author: Alex Maslar
** Date: April 14 2019
** Description: Function that outputs the count of letters to
   a file specified by the user.
*************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>

/*************************************************************
** Description: Function prompts the user for a file name and
   creates an output file stream with that file name. It loops
   from 0 to 26 to send each element in the array to the
   output file (the count of each letter) preceded with the 
   corresponding letter. It then closes the output stream. 
   This function is called from the count_letters function.
*************************************************************/
void output_letters(std::ofstream& ofs, int* letterArray)
{
  std::string fileName;
 
  // prompts the user to enter a file name for the output
  std::cout << "What would you like to call the file?" << std::endl;
  std::cin >> fileName;

  // opens the file name
  ofs.open(fileName);
  // loops through the array and prints the letter followed by
  // the count of that letter
  for (int i = 0; i < 26; ++i)
  {
    char letter = 97 + i;
    ofs << letter << ": " << letterArray[i] << std::endl;
  }
  // closes the ofstream
  ofs.close();
} 
