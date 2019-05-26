/*************************************************************
** Program name: Lab 8
** Author: Alex Maslar
** Date: May 24 2019
** Description: Sort the array from the file. Save the sorted
   array to a file based on the user input.
*************************************************************/
#include "sort_array.hpp"
#include "Menu.hpp"

/*************************************************************
** Description: Function takes an array and the size of the
   array as arguments. The function scans through the array and 
   compares each successive value. If the first value is greater
   than the next, it switches their positions. It does this until
   it goes through the loop and doesn't change any positions.
*************************************************************/
std::string sort_array(int* array, int size){
  std::string file_name;

  // get the file name to save the sorted array
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Specify the file name save sorted array:" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cin >> file_name; 
  std::cout << std::endl;

  int min_index;
  int min_value;

  // loop through the array and sort each successive value
  for (int start_scan = 0; start_scan < (size - 1); start_scan++){
    min_index = start_scan;
    min_value = array[start_scan];

    for (int index = start_scan; index < size; index++){
      if (array[index] < min_value){
        min_value = array[index];
        min_index = index;
      }
    }

    array[min_index] = array[start_scan];
    array[start_scan] = min_value;
  }

  // print the values in the array to file
  std::ofstream ofs;
  ofs.open(file_name);

  for (int i = 0; i < size; i++){
    ofs << array[i] << std::endl;
    std::cout << array[i] << std::endl;
  }

  std::cout << std::endl;
  
  // close the file
  ofs.close();

  // return the file name
  return file_name;
}
