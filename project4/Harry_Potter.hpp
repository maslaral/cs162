/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Header file for the Harry Potter object - 
   includes a private variable for number of lives that is
   unique to the Harry Potter subclass. Has public access to
   the base class Character.
*************************************************************/
#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP
#include "Character.hpp"
#include <string>

class Harry_Potter : public Character {
  private:
    int lives;
  public:
    // constructor
    Harry_Potter();
    // destructor
    ~Harry_Potter();

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
