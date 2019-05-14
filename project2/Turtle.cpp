/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Implementation of the Turtle class functions.
   Includes functions for checking if the turtle is an adult,
   and getter and setter functions for private variables. 
*************************************************************/
#include "Turtle.hpp"

/*************************************************************
** Description: Constructor - sets the default values for the
   turtle object. The cost of a turtle is 100, and a turtle
   can has 10 babies at a time. Turtles pay .05 times the cost 
   and their feed cost is .5 times the base feed cost.
*************************************************************/
Turtle::Turtle(){
  cost = 100;
  number_of_babies = 10;
  payoff = .05 * cost;
  feed_cost = .5 * base_feed_cost;
  age = 0;
}

/*************************************************************
** Description: Destructor - deletes the turtle objects when
   they go out of scope.
*************************************************************/
Turtle::~Turtle(){
}

/*************************************************************
** Description: Boolean function that checks if the turtle
   is an adult (i.e. if the turtle is 3 days old or older) and
   returns true. Otherwise, the function returns false indicating
   that the penguin can't have babies.
*************************************************************/
bool Turtle::is_adult(){
  if (age >= 3){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Getter function to return the cost of purchasing
   a turtle.
*************************************************************/
int Turtle::get_cost(){
  return cost;
}

/*************************************************************
** Description: Getter function to return the number of babies
   the turtle has at a time.
*************************************************************/
int Turtle::get_number_of_babies(){
  return number_of_babies;
}

/*************************************************************
** Description: Getter function to return the payoff of each
   turtle.
*************************************************************/
int Turtle::get_payoff(){
  return payoff;
}

/*************************************************************
** Description: Getter function to return the feed cost of
   each turtle.
*************************************************************/
int Turtle::get_feed_cost(){
  return feed_cost;
}

/*************************************************************
** Description: Setter function to set the cost of purchasing
   a turtle.
*************************************************************/
void Turtle::set_cost(int cost){
  this->cost = cost;
}

/*************************************************************
** Description: Setter function to set the number of babies the
   turtle can have at a time.
*************************************************************/
void Turtle::set_number_of_babies(int number_of_babies){
  this->number_of_babies = number_of_babies;
}

/*************************************************************
** Description: Setter function to set the payoff for each
   turtle.
*************************************************************/
void Turtle::set_payoff(int payoff){
  this->payoff = payoff;
}
