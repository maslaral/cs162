/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Vampire function used to attack, defend, and
   inflict damage in the Game. Includes methods to get Vampire
   variables like type and strength, and a function that checks
   if the Vampire is alive. In addition, the defense function
   for Vampires includes a special ability where the defense
   return is 100 - meaning no impact with the attack. This 
   is printed out to the user through logic in the Game
   class as if the attacker didn't attack.
*************************************************************/
#include "Vampire.hpp"
#include "roll_die.hpp"

#include <iostream>

/*************************************************************
** Description: Default constructor for the Vampire object
   that sets the attributes based on the project requirements.
*************************************************************/
Vampire::Vampire(){
  strength = 18;
  armor = 1;
  num_die_attack = 1;
  num_sides_attack = 12;
  num_die_defend = 1;
  num_sides_defend = 6;
}

/*************************************************************
** Description: Destructor for the Vampire object.
*************************************************************/
Vampire::~Vampire(){
}

/*************************************************************
** Description: Attack fuction calls the roll_die function
   which randomly generates a number based on the number of
   die and sides attack variables. The function returns the
   value to the Game class.
*************************************************************/
int Vampire::attack(){
  return roll_die(num_die_attack, num_sides_attack);
}

/*************************************************************
** Description: Defense function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides defense variables. The function returns the
   value to the Game class. For the Vampire, 50% of the time
   the charm function is called which means the function 
   returns 100. All other logic in relation to charm 
   is taken care of in the Game class.
*************************************************************/
int Vampire::defense(){
  int charm = 100; 

  if (roll_die(1,2) == 1){
    special_ability();
    return charm;
  }
  else {
    return roll_die(num_die_defend, num_sides_defend);
  }
}

/*************************************************************
** Description: Inflict damage function takes the damage from
   the Game class as it's argument and subtracts that value
   from the strength variable.
*************************************************************/
void Vampire::inflict_damage(int damage){
  strength -= damage;
}

/*************************************************************
** Description: Special ability function simply prints that
   the Vampire used charm.
*************************************************************/
void Vampire::special_ability(){
  std::cout << std::endl;
  std::cout << "Vampire used charm and persuaded the opponent " << std::endl;
  std::cout << "not to attack!" << std::endl;
  std::cout << std::endl;
}

/*************************************************************
** Description: Alive function checks whether or not the
   player is alive. Returns a boolean value true/false to the
   Game class to determine when to end the game.
*************************************************************/
bool Vampire::alive(){
  if (strength > 0){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Get armor function returns the armor of the
   Vampire.
*************************************************************/
int Vampire::get_armor(){
  return armor;
}

/*************************************************************
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Vampire::get_type(){
  return "Vampire";
}

/*************************************************************
** Description: Get strength function returns the strength. 
*************************************************************/
int Vampire::get_strength(){
  return strength;
}
