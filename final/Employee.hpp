/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 10 2019
** Description: Employee class - used for Angela
*************************************************************/
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee {
  private:
    std::string name;
    int talkative_level;
  public:
    Employee();
    ~Employee();

    // gameplay
    void reduce_talkative_level(int);
   
    // getter functions
    int get_talkative_level();
    std::string get_name();

    // setter functions
    void set_talkative_level(int);
    void set_name(std::string);
};

#endif
