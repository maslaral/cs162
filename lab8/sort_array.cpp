/*************************************************************
** Program name:
** Author: Alex Maslar
** Date: May 24 2019
** Description: 
*************************************************************/
#include "sort_array.hpp"
#include "Menu.hpp"

/*************************************************************
** Description:
*************************************************************/
std::string sort_array(int* array, int size){
  std::string file_name;

  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Specify the file name save sorted array:" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cin >> file_name; 
  std::cout << std::endl;

  int min_index;
  int min_value;

  for (int start_scan = 0; start_scan < (size - 1); start_scan++){
    min_index = start_scan;
    min_value = array[start_scan];

    for (int index = start_scan - 1; index < size; index++){
      if (array[index] < min_value){
        min_value = array[index];
        min_index = index;
      }
    }

    array[min_index] = array[start_scan];
    array[start_scan] = min_value;
  }

  std::ofstream ofs;
  ofs.open(file_name);

  for (int i = 0; i < size; i++){
    ofs << array[i] << std::endl;
    std::cout << array[i] << std::endl;
  }

  std::cout << std::endl;
  
  ofs.close();

  return file_name;
}



  


