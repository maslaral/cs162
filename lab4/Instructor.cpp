/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 29 2019
** Description: Instructor class that contains functions for
   the instructor object. These include creating a new instructor
   object and returning it to the University class to be placed
   in the person array, setting the rating of the instructor
   and printing that out, setting the age randomly, and the
   function to do work. These are virtual functions, so
   are unique to the Instructor when calling with an instructor
   object.
*************************************************************/
#include "Instructor.hpp"
#include "University.hpp"
#include <iostream>
#include <iomanip>
#include <string>

/*************************************************************
** Description: Constructor - no values needed to be set as 
   set in the person class
*************************************************************/
Instructor::Instructor(){
}

/*************************************************************
** Description: Destructor - destroys the instructor object
   when out of scope
*************************************************************/
Instructor::~Instructor(){
}

/*************************************************************
** Description: Creates a new Instructor object and asks the
   user for the name of the instructor. It then calls the
   functions to set the rating and age of the instructor. 
   Finally, it returns the pointer to the Instructor object
   which is used in the University class to assign it to a 
   Person object pointer and put in the Person array.
*************************************************************/
Instructor* Instructor::create_instructor() {
  // var to hold the user input
  std::string n;

  // create a new instructor object add assign a pointer
  Instructor* i = new Instructor();

  // prompt user for a name
  std::cout << "Enter a name for the instructor: " << std::endl;
  
  std::getline(std::cin, n);
  i->name = n;
  
  // call functions to set gpa and age
  i->set_rating_gpa();
  i->set_age();

  // return the instructor pointer
  return i;
}

/*************************************************************
** Description: Acheives the same thing as the function above
   but doesn't prompt the user for the name of the instructor.
   This function is used solely in the read from file function.
*************************************************************/
Instructor* Instructor::create_instructor_file(){
  // var to hold the user input
  std::string n;

  // create a new instructor object add assign a pointer
  Instructor* i = new Instructor();
  
  // return the instructor pointer
  return i;
}

/*************************************************************
** Description: Setter function to set the name of the 
   instructor.
*************************************************************/
void Instructor::set_name(std::string name){
  this->name = name;
}

/*************************************************************
** Description: Setter function to set the rating from 
   the file.
*************************************************************/
void Instructor::set_rating_gpa_file(double rating_gpa){
  this->rating_gpa = rating_gpa;
}

/*************************************************************
** Description: Setter function to set the age from a file
*************************************************************/
void Instructor::set_age_file(int age){
  this->age = age;
}

/*************************************************************
** Description: Function that randomly sets the rating of the
   instructor between 5 and 0.
*************************************************************/
void Instructor::set_rating_gpa(){
  double r = 5.0 * ((double)rand() / (double)RAND_MAX);
  this->rating_gpa = r;
}

/*************************************************************
** Description: Function that sets the age as a random integer
   between 80 and 40.
*************************************************************/
void Instructor::set_age(){
  int a = rand() % (80 - 40 + 1) + 40; 
  this->age = a;
}

/*************************************************************
** Description: Function that outputs the number of hours
   the professor spends grading. This number is proporitional
   to their rating (using if-else statements) to be realistic.
*************************************************************/
void Instructor::do_work(){
  int hours_graded;

  if (this->rating_gpa > 4) {
    hours_graded = rand() % (10 - 6 + 1) + 6;
  }
  else if (this->rating_gpa > 2) {
    hours_graded = rand() % (6 -3 + 1) + 3;
  }
  else {
    hours_graded = rand() % (3 - 1 + 1) + 1;
  }

  std::cout << name << " graded papers for " << hours_graded << " hours." << std::endl;
}

/*************************************************************
** Description: Prints the rating of the professor. Called
   in the University class when printing the array of people.
*************************************************************/
void Instructor::print_rating_gpa(){
  std::cout << std::fixed;
  std::cout << "Rating: ";
  std::cout << std::setprecision(1) << get_rating_gpa() << std::endl;
}

/*************************************************************
** Description: Simple function that just returns 2 if the 
   person is an instructor. Same function returns 1 in the
   student class.
*************************************************************/
int Instructor::get_type(){
  return 2;
}
