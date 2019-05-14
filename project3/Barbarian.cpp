/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 11 2019
** Description: Barbarian functions used to attack, defend, 
   and inflict damage in the Game. Includes methods to get
   Barbarian variables like type and strength, and a function
   that checks if the Barbarian is still alive.
*************************************************************/
#include "Barbarian.hpp"
#include "roll_die.hpp"

/*************************************************************
** Description: Default constructor for the Barbarian object
   that sets the attributes based on the project requirements.
*************************************************************/
Barbarian::Barbarian(){
  strength = 12;
  armor = 0;
  num_die_attack = 2;
  num_sides_attack = 6;
  num_die_defend = 2;
  num_sides_defend = 6;
}

/*************************************************************
** Description: Destructor for the Barbarian object.
*************************************************************/
Barbarian::~Barbarian(){
}

/*************************************************************
** Description: Attack function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides attack variables. The function returns the
   value to the Game class. 
*************************************************************/
int Barbarian::attack(){
  return roll_die(num_die_attack, num_sides_attack);
}

/*************************************************************
** Description: Defense function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides defense variables. The function returns the
   value to the Game class.
*************************************************************/
int Barbarian::defense(){
  return roll_die(num_die_defend, num_sides_defend);
}

/*************************************************************
** Description: Inflict damage function takes the damage from
   the Game class as it's argument and subtracts that value
   from the strength variable.
*************************************************************/
void Barbarian::inflict_damage(int damage){
  strength -= damage;
}


/*************************************************************
** Description: Special ability function is blank for the 
   Barbarian as it has no special abilities. Used only because
   it's a pure virtual function so it needed to be overwritten
   in each derived class.
*************************************************************/
void Barbarian::special_ability(){
}

/*************************************************************
** Description: Alive function checks whether or not the
   player is alive. Returns a boolean value true/false to the
   Game class to determine when to end the game.
*************************************************************/
bool Barbarian::alive(){
  if (strength > 0){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Get armor function returns the armor of the
   Barbarian.
*************************************************************/
int Barbarian::get_armor(){
  return armor;
}

/*************************************************************
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Barbarian::get_type(){
  return "Barbarian";
}

/*************************************************************
** Description: Get strength function returns the strength of
   the Barbarian.
*************************************************************/
int Barbarian::get_strength(){
  return strength;
}
