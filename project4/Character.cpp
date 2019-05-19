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
