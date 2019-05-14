/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Tiger function implementations, includes the
   constructor as well as a function to check if the tiger is
   an adult. Additionally, the class consists of some functions
   to set and get variables.
*************************************************************/
#include "Tiger.hpp"

/*************************************************************
** Description: Constructor - sets the defaults for a new 
   Tiger object to be a cost of 10000, the number of babies to
   one, the payoff to .2 times the cost, the feed to 5 times
   the base feed cost, and finally the age to 0.
*************************************************************/
Tiger::Tiger(){
  cost = 10000;
  number_of_babies = 1;
  payoff = .2 * cost;
  feed_cost = 5 * base_feed_cost;
  age = 0;
}

/*************************************************************
** Description: Destructor - destroys the tiger object when
   out of scope.
*************************************************************/
Tiger::~Tiger(){
}

/*************************************************************
** Description: Returns a boolean value of true if the tiger
   is an adult (i.e. is greater than three years old).
   Otherwise, it returns a boolean value of false indicating
   that the Tiger object is considered a baby. 
*************************************************************/
bool Tiger::is_adult(){
  if (age >= 3){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Getter function to return the cost of the tiger
   when purchased.
*************************************************************/
int Tiger::get_cost(){
  return cost;
}

/*************************************************************
** Description: Getter function to return the number of babies
   the tiger has at a time.
*************************************************************/
int Tiger::get_number_of_babies(){
  return number_of_babies;
}

/*************************************************************
** Description: Getter function to return the payoff each
   tiger gets.
*************************************************************/
int Tiger::get_payoff(){
  return payoff;
}

/*************************************************************
** Description: Getter function to return the feed cost of 
   the tiger.
*************************************************************/
int Tiger::get_feed_cost(){
  return feed_cost;
}

/*************************************************************
** Description: Setter function to set the cost of the tiger.
*************************************************************/
void Tiger::set_cost(int cost){
  this->cost = cost;
}

/*************************************************************
** Description: Setter function to set the number of babies
   for the tiger.
*************************************************************/
void Tiger::set_number_of_babies(int number_of_babies){
  this->number_of_babies = number_of_babies;
}

/*************************************************************
** Description: Setter function to set the payoff for the 
   tiger.
*************************************************************/
void Tiger::set_payoff(int payoff){
  this->payoff = payoff;
}
