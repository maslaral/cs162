/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Implementation of the Animal super class. The
   Animal class is abstract, so the only functions defined here
   are those that don't need polymorphism. 
*************************************************************/
#include "Animal.hpp"

/*************************************************************
** Description: Constructor - sets the initial variables for
   the animal class and the base feed cost (which is used 
   throughout the program and doesn't change.
*************************************************************/
Animal::Animal(){
  age = 0;
  cost = 0;
  number_of_babies = 0;
  payoff = 0;
  base_feed_cost = 100;
}

/*************************************************************
** Description: Destructor - deletes the animal object when it
   goes out of scope.
*************************************************************/
Animal::~Animal(){
}

/*************************************************************
** Description: Adds one day to the age of the animal. Called
   when the end of day function is called.
*************************************************************/
void Animal::add_day(){
  age++;
}

/*************************************************************
** Description: Checks if the animal is an adult (i.e. greater
   than or equal to 3 days old), and return true. If not,
   returns false indicating that the animal is not able to
   have babies.
*************************************************************/
bool Animal::is_adult(){
  if (age >= 3){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Getter function that gets the base feed cost
   set in the Animal class.
*************************************************************/
int Animal::get_base_feed_cost(){
  return base_feed_cost;
}

/*************************************************************
** Description: Setter function to set the age of the animal.
*************************************************************/
void Animal::set_age(int age){
  this->age = age;
}
