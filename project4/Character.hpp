/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Character implementation - includes attack,
   defend, and inflict damage functions. In addition, the
   class contains the variables starting strength, strength,
   armor, and number of die.
*************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "roll_die.hpp"
#include <string>

class Character {
  protected:
    int starting_strength;
    int strength;
    int armor;
    int num_die_attack;
    int num_sides_attack;
    int num_die_defend;
    int num_sides_defend;
    Character* next;
    std::string name;
  public:
    // constructor
    Character();
    // destructor
    virtual ~Character();

    // game play functions
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual void inflict_damage(int) = 0;
    virtual void special_ability() = 0;
    bool alive();
    void recover();
    
    // getter functions
    int get_armor();
    int get_strength();
    std::string get_name();
    virtual std::string get_type() = 0;
    Character* get_next();

    // setter functions
    void set_name(std::string);
    void set_next(Character* next);
};

#endif
