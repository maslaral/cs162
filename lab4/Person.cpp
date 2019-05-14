/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 28 2019
** Description: Abstract person class that contains functions
   just to get the name of the person, the gpa, and the age.
*************************************************************/
#include "Person.hpp"
#include <string>

/*************************************************************
** Description: Constructor with default values for all the
   Person variables.
*************************************************************/
Person::Person(){
  name = "";
  age = 0;
  rating_gpa = 0;
}

/*************************************************************
** Description: Destructor - deletes the person objects
   when out of scope
*************************************************************/
Person::~Person(){
}

/*************************************************************
** Description: Getter function to return the name of the person.
*************************************************************/
std::string Person::get_name(){
  return name;
}

/*************************************************************
** Description: Getter function to return the rating or gpa
   of the person.
*************************************************************/
double Person::get_rating_gpa(){
 return rating_gpa;
}

/*************************************************************
** Description: Getter function to return the age of the person.
*************************************************************/
int Person::get_age(){
  return age;
}
