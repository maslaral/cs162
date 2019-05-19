/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 11 2019
** Description: Blue Men header file - includes no private 
   variables as all are handled in the abstract base Character 
   class. Has public access to the base class Character.
*************************************************************/
#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP
#include "Character.hpp"
#include <string>

class Blue_Men : public Character {
  public:
    // constructor
    Blue_Men();
    // destructor
    ~Blue_Men();

    // game play functions
    virtual int attack();
    virtual int defense();
    virtual void inflict_damage(int);
    virtual void special_ability();

    // getter functions
    virtual std::string get_type();
};

#endif
