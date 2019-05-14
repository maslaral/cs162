/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Building class. Has variables
   such as name, size and address as well as methods to set
   and get those variables. 
*************************************************************/
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

class Building
{
  private:
    std::string name;
    int size;
    std::string address;
  public:
    // constructor
    Building();

    // destructor
    ~Building();

    // function that sets attributes from user input
    void create_building();

    // getter functions
    std::string get_building_name();
    int get_size();
    std::string get_address();
};

#endif
