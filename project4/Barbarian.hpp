/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 11 2019
** Description: Barbarian header file - includes no private 
   variables as all are handled in the abstract base Character 
   class. Has public access to the base class Character.
*************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"
#include <string>

class Barbarian : public Character {
  public:
    // constructor
    Barbarian();
    // destructor
    ~Barbarian();

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
