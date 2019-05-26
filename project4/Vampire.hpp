/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Vampire implementation - includes attack,
   defend, and inflict damage functions. In addition, the
   class contains the variables starting strength, strength,
   armor, and number of die.
*************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"
#include <string>

class Vampire : public Character {
  public:
    // constructor
    Vampire();
    // destructor
    ~Vampire();

    // game play functions
    virtual int attack();
    virtual int defense();
    virtual void inflict_damage(int);
    virtual void special_ability();
    
    // getter functions
    virtual std::string get_type();
};

#endif
