/*************************************************************
** Program name: Project 3
** Author: Alex Maslar
** Date: May 12 2019
** Description: Harry Potter functions used to attack, defend,
   and inflict damage in the Game. Includes methods to get 
   Harry Potter variables like type and strength, and a function
   that checks if Harry Potter is still alive. In addition, 
   the Harry Potter special ability function gives Harry Potter
   an additional life if his strength falls below 0.
*************************************************************/
#include "Harry_Potter.hpp"
#include "roll_die.hpp"

#include <iostream>

/*************************************************************
** Description: Default constructor for the Harry Potter object
   that sets the attributes based on the project requirements. 
*************************************************************/
Harry_Potter::Harry_Potter(){
  strength = 10;
  lives = 2;
  armor = 0;
  num_die_attack = 2;
  num_sides_attack = 6;
  num_die_defend = 2;
  num_sides_defend = 6;
}

/*************************************************************
** Description: Destructor for the Harry Potter object.
*************************************************************/
Harry_Potter::~Harry_Potter(){
}

/*************************************************************
** Description: Attack function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides attack variables. The function returns the
   value to the Game class. 
*************************************************************/
int Harry_Potter::attack(){
  return roll_die(num_die_attack, num_sides_attack);
}

/*************************************************************
** Description: Defense function calls the roll_die function
   which randomly generates a number based on the number of
   die and sides defense variables. The function returns the
   value to the Game class.
*************************************************************/
int Harry_Potter::defense(){
  return roll_die(num_die_defend, num_sides_defend);
}

/*************************************************************
** Description: Inflict damage function takes the damage from
   the Game class as it's argument and subtracts that value
   from the strength variable. In addition, the inflict 
   damage function calls the special_ability function for 
   Harry Potter.
*************************************************************/
void Harry_Potter::inflict_damage(int damage){
  strength -= damage;
  special_ability();
}

/*************************************************************
** Description: Special ability function gives Harry Potter
   a new life if his strength falls below 0 and outputs
   the result to the console. His strenth is set at 20.
*************************************************************/
void Harry_Potter::special_ability(){
  if (strength <= 0 && lives == 2){
    strength = 20;
    lives--;
    std::cout << std::endl;
    std::cout << "Harry Potter used Hogwarts and came back to " << std::endl;
    std::cout << "life!" << std::endl;
    std::cout << std::endl;
  } 
}
/*************************************************************
** Description: Alive function checks whether or not the
   player is alive. Returns a boolean value true/false to the
   Game class to determine when to end the game.
*************************************************************/
bool Harry_Potter::alive(){
  if (strength > 0){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Get armor function returns the armor of Harry
   Potter.
*************************************************************/
int Harry_Potter::get_armor(){
  return armor;
}

/*************************************************************
** Description: Get type function returns the type - used only
   for displaying the winner.
*************************************************************/
std::string Harry_Potter::get_type(){
  return "Harry Potter";
}

/*************************************************************
** Description: Get strength function returns the strength of
   Harry Potter.
*************************************************************/
int Harry_Potter::get_strength(){
  return strength;
}
