/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
*************************************************************/
#include "Character.hpp"

Character::Character(){
}

Character::~Character(){
}

/*************************************************************
** Description:
*************************************************************/
Character* Character::get_next(){
	return next;
}

/*************************************************************
** Description:
*************************************************************/
void Character::set_next(Character* next){
	this->next = next;	
}

void Character::set_name(std::string name){
  this->name = name;
}

std::string Character::get_name(){
  return name;
}

int Character::get_armor(){
  return armor;
}

int Character::get_strength(){
  return strength;
}

bool Character::alive(){
  if (strength > 0){
    return true;
  }
  else {
    return false;
  }
}

void Character::recover(){
  if (starting_strength != strength){
    int result = roll_die(1, 10);
    result *= 0.1;
    int new_strength = starting_strength * result;

    // if the new strength is greater than the current strength,
    // recover
    if (new_strength > strength){
      strength = new_strength;
    }
  }
}
