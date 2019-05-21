/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
*************************************************************/
#include "Vampire.hpp"
#include "roll_die.hpp"

#include <iostream>

/*************************************************************
** Description: Default constructor for the Vampire object
   that sets the attributes based on the project requirements.
*************************************************************/
Vampire::Vampire(){
  starting_strength = 18;
  strength = starting_strength;
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
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Vampire::get_type(){
  return "Vampire";
}
