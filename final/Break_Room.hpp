/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 10 2019
** Description:
*************************************************************/
#ifndef BREAK_ROOM_HPP
#define BREAK_ROOM_HPP

#include "Office.hpp"
#include "Employee.hpp"
#include <string>

class Break_Room : public Office {
  private:
    Employee* employee;
  public:
    Break_Room();
    ~Break_Room();
    int action();
    void set_employee_characteristics(std::string, int);
};

#endif
