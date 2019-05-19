/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Character header file - the Character class is
   an abstract class (i.e. there can be a type of character
   but not just a Character). The class includes variables 
   relevant to all Character types likes strength, armor, and
   number of die and sides. In addition, it includes headers 
   for pure virtual functinos like attack, defense, inflict
   damage, etc. which are all overwritten in the Character
   sub-classes.
*************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

class Character {
  protected:
    int strength;
    int armor;
    int num_die_attack;
    int num_sides_attack;
    int num_die_defend;
    int num_sides_defend;
    Character* next;
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
    virtual bool alive() = 0;
    
    // getter functions
    virtual int get_armor() = 0;
    virtual std::string get_type() = 0;
    virtual int get_strength() = 0;

    // functions for queue
    Character* get_next();
    void set_next(Character* next);
};

#endif
