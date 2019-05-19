/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Blue Men functions used to attack, defend, 
   and inflict damage in the Game. Includes methods to get
   Blue Men variables like type and strength, and a function
   that checks if the Blue Men are alive. In addition, there
   is a special ability function which is called when damage
   is inflicted which sets the die to 2 if strength is less
   than 8 and 1 if less than 4.
*************************************************************/
#include "Blue_Men.hpp"
#include "roll_die.hpp"
#include <iostream>

/*************************************************************
** Description: Default constructor for the Blue Men object
   that sets the attributes based on the project requirements.
*************************************************************/
Blue_Men::Blue_Men(){
  strength = 12;
  armor = 3;
  num_die_attack = 2;
  num_sides_attack = 10;
  num_die_defend = 3;
  num_sides_defend = 6;
}

/*************************************************************
** Description: Destructor for the Blue Men object.
*************************************************************/
Blue_Men::~Blue_Men(){
}

/*************************************************************
** Description: Attack fuction calls the roll_die function
   which randomly generates a number based on the number of
   die and sides attack variables. The function returns the
   value to the Game class.
*************************************************************/
int Blue_Men::attack(){
  return roll_die(num_die_attack, num_sides_attack);
}

/*************************************************************
** Description: Defense function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides defense variables. The function returns the
   value to the Game class.
*************************************************************/
int Blue_Men::defense(){
  return roll_die(num_die_defend, num_sides_defend);
}

/*************************************************************
** Description: Inflict damage function takes the damage from
   the Game class as it's argument and subtracts that value
   from the strength variable.
*************************************************************/
void Blue_Men::inflict_damage(int damage){
  strength -= damage;
  special_ability();
}

/*************************************************************
** Description: Special ability function reduces the die to
   2 if the strength is less than 8 and greater than 4. If 
   the strength is less than or equal to 4, the number of die
   is reduced to 1.
*************************************************************/
void Blue_Men::special_ability(){
  if (strength <= 8 && strength > 4){
    num_die_defend = 2;
  }
  else if (strength <= 4){
    num_die_defend = 1;
  }
}

/*************************************************************
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Blue_Men::get_type(){
  return "Blue Men";
}
