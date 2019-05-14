/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 28 2019
** Description: Implementation file for the Building class. 
   Defines functions to create a building, get information
   about that building, and set the name, address, and size.
*************************************************************/
#include "Building.hpp"
#include "University.hpp"
#include <iostream>
#include <string>

/*************************************************************
** Description: Building constructor - constructs the building
   object and initializes it's values.
*************************************************************/
Building::Building(){
  name = "";
  size = 0;
  address = "";
}

/*************************************************************
** Description: Building destructor - destroys the build objects
   when out of scope.
*************************************************************/
Building::~Building(){
}

/*************************************************************
** Description: Sets the building name, address, and size based
   on input from the user. This function is called from the
   University class when adding a new building to the buildings
   array.
*************************************************************/
void Building::create_building() {

  std::string name;
  std::string address;
  int size, maxSize = 100000, minSize = 1;

  std::cout << "Enter the building name: " << std::endl;
  std::getline(std::cin, name);

  this->name = name;

  std::cout << "Enter the building address: " << std::endl;
  std::getline(std::cin, address);

  this->address = address;

  std::cout << "Enter the size of the building: " << std::endl;
  std::cin >> size;

  while (std::cin.fail() || size > maxSize || size < minSize)
  {
    std::cout << "Invalid response. Please enter an integer from "
              << minSize << " to " << maxSize << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> size;
  }

  this->size = size;
  std::cin.ignore(256, '\n');
  std::cout << std::endl;
}

/*************************************************************
** Description: Getter function that returns the name of the
   building. Used in the University class function that prints out
   the building names in the buildings array.
*************************************************************/
std::string Building::get_building_name() {
  return name;
}

/*************************************************************
** Description: Getter function that returns the address of
   the building. Used in the University class that prints
   out the building addresses in the buildings array.
*************************************************************/
std::string Building::get_address() {
  return address;
}

/*************************************************************
** Description: Getter function that returns the size of the
   building. Used in the University class function that prints
   out the size of the buildings in the buildings array.
*************************************************************/
int Building::get_size() {
  return size;
}
