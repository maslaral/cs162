#include "Character.hpp"

Character::Character(){
	strength = 0;
	armor = 0;
	num_die_attack = 0;
	num_sides_attack = 0;
	num_die_defend = 0; num_sides_defend = 0;
	next = nullptr;
}

Character::~Character(){
}


/*************************************************************
** Description: Attack fuction calls the roll_die function
   which randomly generates a number based on the number of
   die and sides attack variables. The function returns the
   value to the Game class.
*************************************************************/
int Character::attack(){
  return roll_die(num_die_attack, num_sides_attack);
}

/*************************************************************
** Description: Defense function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides defense variables. The function returns the
   value to the Game class.
*************************************************************/
int Character::defense(){
  return roll_die(num_die_defend, num_sides_defend);
}


/*************************************************************
** Description: Inflict damage function takes the damage from
   the Game class as it's argument and subtracts that value
   from the strength variable.
*************************************************************/
void Character::inflict_damage(int damage){
  strength -= damage;
}

/*************************************************************
** Description: Special ability function reduces the die to
   2 if the strength is less than 8 and greater than 4. If 
   the strength is less than or equal to 4, the number of die
   is reduced to 1.
*************************************************************/
void Character::special_ability(){
}

/*************************************************************
** Description: Alive function checks whether or not the
   player is alive. Returns a boolean value true/false to the
   Game class to determine when to end the game.
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
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Character::get_type(){
}

/*************************************************************
** Description: Get strength function returns the strength. 
*************************************************************/
int Character::get_strength(){
  return strength;
}

/*************************************************************
** Description: Get armor function returns the armor of the
   Blue Men.
*************************************************************/
int Character::get_armor(){
  return armor;
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
