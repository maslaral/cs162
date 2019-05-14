/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Implementation of the Penguin class functions.
   Includes functions for checking if the penguin is an adult,
   and getter and setter functions for private variables. 
*************************************************************/
#include "Penguin.hpp"

/*************************************************************
** Description: Constructor - sets the default values for the
   penguin object. The cost of a penguin is 1000, and a penguin
   can has 5 babies at a time. Penguins pay .1 times the cost 
   and their feed cost is simply equal to the base feed cost.
*************************************************************/
Penguin::Penguin(){
  cost = 1000;
  number_of_babies = 5;
  payoff = .1 * cost;
  feed_cost = base_feed_cost;
  age = 0;
}

/*************************************************************
** Description: Destructor - deletes the penguin objects when
   they go out of scope.
*************************************************************/
Penguin::~Penguin(){
}

/*************************************************************
** Description: Boolean function that checks if the penguin
   is an adult (i.e. if the penguin is 3 days old or older) and
   returns true. Otherwise, the function returns false indicating
   that the penguin can't have babies.
*************************************************************/
bool Penguin::is_adult(){
  if (age >= 3){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Getter function to return the cost of purchasing
   a penguin.
*************************************************************/
int Penguin::get_cost(){
  return cost;
}

/*************************************************************
** Description: Getter function to return the number of
   babies a penguin has at a time.
*************************************************************/
int Penguin::get_number_of_babies(){
  return number_of_babies;
}

/*************************************************************
** Description: Getter function to return the payoff for
   each penguin.
*************************************************************/
int Penguin::get_payoff(){
  return payoff;
}

/*************************************************************
** Description: Getter function to return the cost of feeding
   each penguin.
*************************************************************/
int Penguin::get_feed_cost(){
  return feed_cost;
}

/*************************************************************
** Description: Setter function to set the cost for puchasing
   a penguin.
*************************************************************/
void Penguin::set_cost(int cost){
  this->cost = cost;
}

/*************************************************************
** Description: Setter function to set the number of babies a 
   penguin has at a time.
*************************************************************/
void Penguin::set_number_of_babies(int number_of_babies){
  this->number_of_babies = number_of_babies;
}

/*************************************************************
** Description: Setter function to set the payoff for each 
   penguin.
*************************************************************/
void Penguin::set_payoff(int payoff){
  this->payoff = payoff;
}

