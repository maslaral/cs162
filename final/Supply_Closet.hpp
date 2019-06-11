/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 10 2019
** Description: 
*************************************************************/
#ifndef SUPPLY_CLOSET_HPP
#define SUPPLY_CLOSET_HPP

#include "Office.hpp"
#include <string>

class Supply_Closet : public Office {
  private:
  public:
    Supply_Closet();
    ~Supply_Closet();
    int action();
};

#endif
