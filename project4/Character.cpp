/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Character implementation - includes attack,
   defend, and inflict damage functions. In addition, the
   class contains the variables starting strength, strength,
   armor, and number of die.
*************************************************************/
#include "Character.hpp"

/*************************************************************
** Description: Constructor
*************************************************************/
Character::Character(){
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
Character::~Character(){
}

/*************************************************************
** Description: Setter functions that include functions to
   set the next character in the queue, and set the name of
   the character.
*************************************************************/
void Character::set_next(Character* next){
	this->next = next;	
}

void Character::set_name(std::string name){
  this->name = name;
}

/*************************************************************
** Description: Getter functions that include functions to
   get the next player in the queue, the name of the character,
   the armor value, and the player's current strength.
*************************************************************/
Character* Character::get_next(){
	return next;
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

/*************************************************************
** Description: Function that checks if the character is still
   alive by checking if their strength value is greater than
   0. If not alive, return false. If alive, returns true.
*************************************************************/
bool Character::alive(){
  if (strength > 0){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Function to recover the strength of the 
   winner of the matchup. It does this by getting a random
   number between 1 and 10, multiplying that by .1 to get a 
   percentage, and then multiplying the starting strength by
   that number to get the new strength value.
*************************************************************/
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
