/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Vampire header file - includes no private
   variables as all are handled in the abstract base Character
   class. Has public access to the base class Character.
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
    virtual bool alive();
    
    // getter functions
    virtual int get_armor();
    virtual int get_strength();
    virtual std::string get_type();
};

#endif
