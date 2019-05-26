/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
*************************************************************/
#include "Medusa.hpp"
#include "roll_die.hpp"

#include <iostream>

/*************************************************************
** Description: Default constructor for the Medusa object
   that sets the attributes based on the project requirements. 
*************************************************************/
Medusa::Medusa(){
  starting_strength = 8;
  strength = starting_strength;
  armor = 3;
  num_die_attack = 2;
  num_sides_attack = 6;
  num_die_defend = 1;
  num_sides_defend = 6;
}

/*************************************************************
** Description: Destructor for the Medusa object.
*************************************************************/
Medusa::~Medusa(){
}

/*************************************************************
** Description: Attack function calls the roll_die function
   which randomly generates a number based on the number of 
   die and the sides of the die attack variables. In addition,  
   the function represents the medusa special ability in
   the attack function by returning 100 if the roll is
   twelve. This was an easy way to represent this as no
   character will be able to survive this (Harry Potter 
   being the exception if he has an extra life left).
*************************************************************/
int Medusa::attack(){
  int roll = roll_die(num_die_attack, num_sides_attack);

  if (roll == 12){
    special_ability();
    return 100;
  }
  else {
    return roll; 
  }
}

/*************************************************************
** Description: Defense function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides defense variables. The function returns the
   value to the Game class.
*************************************************************/
int Medusa::defense(){
  return roll_die(num_die_defend, num_sides_defend);
}

/*************************************************************
** Description: Inflict damage function takes the damage from
   the Game class as it's argument and subtracts that value
   from the strength variable. In addition, the inflict 
   damage function calls the special_ability function for 
   Harry Potter.
*************************************************************/
void Medusa::inflict_damage(int damage){
  strength -= damage;
}

/*************************************************************
** Description: Special ability function is called when the
   Medusa rolls a 12. The function simply outputs to the
   console that the Medusa used glare. The rest of the logic
   is handled in the attack function and in the Game play 
   function.
*************************************************************/
void Medusa::special_ability(){
  std::cout << std::endl;
  std::cout << "Medusa used glare on the opponent!" << std::endl;
  std::cout << std::endl;
}

/*************************************************************
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Medusa::get_type(){
  return "Medusa";
}
