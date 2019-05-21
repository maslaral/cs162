/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
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

    // getter functions
    virtual std::string get_type();
};

#endif
