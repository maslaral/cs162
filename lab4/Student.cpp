/************************************************************* ** Program name: Lab 4
** Author: Alex Maslar
** Date: April 29 2019
** Description: Student class that contains functions for
   the Student object. These include creating a new Student
   object and returning it to the University class to be placed
   in the person array, setting the rating of the Student
   and printing that out, setting the age randomly, and the
   function to do work. These are virtual functions, so
   are unique to the Student when calling with an Student
   object.
*************************************************************/
#include "Student.hpp"
#include "University.hpp"
#include <iostream>
#include <string>
#include <iomanip>

/*************************************************************
** Description: Constructor - no values needed to be set as
   set in the person class
*************************************************************/
Student::Student(){
}

/*************************************************************
** Description: Destructor - destroys the Student object when
   out of scope
*************************************************************/
Student::~Student(){
}

/*************************************************************
** Description: Creates a new Student object and asks the user
   for the name of the Student. It then calls the functions to
   set the GPA and age of the student. Finally it returns a 
   pointer to the Student object which is used in the University
   class to assign it to a Person object in the person array.
*************************************************************/
Student* Student::create_student(){
  std::string n;

  Student* s = new Student();
  std::cout << "Enter a name for the student: " << std::endl;

  std::getline(std::cin, n);
  s->name = n;

  s->set_rating_gpa();
  s->set_age();

  return s;
}

/*************************************************************
** Description: Same as the function above, but doesn't prompt
   the user for entering the name for th student. Used solely
   for the read from file functions.
*************************************************************/
Student* Student::create_student_file(){

  Student* s = new Student();

  return s;
}


/*************************************************************
** Description: Setter function to set the name of the student
*************************************************************/
void Student::set_name(std::string name){
  this->name = name;
}

/*************************************************************
** Description: Setter function to set the gpa from file
*************************************************************/
void Student::set_rating_gpa_file(double rating_gpa){
  this->rating_gpa = rating_gpa;
}

/*************************************************************
** Description: Setter function to set the age from a file
*************************************************************/
void Student::set_age_file(int age){
  this->age = age;
}

/*************************************************************
** Description: Function that randomly sets the gpa of the 
   student between 0 and 4
*************************************************************/
void Student::set_rating_gpa(){
  double r = 4.0 * ((double)rand() / (double)RAND_MAX);
  this->rating_gpa = r;
}

/*************************************************************
** Description: Function that randomly sets the age of the 
   student
*************************************************************/
void Student::set_age(){
  int a = rand() % (28 - 18 + 1) + 18;
  this->age = a;
}

/*************************************************************
** Description: Function that outputs the number of hours the
   student spent studying. It's in proportion to their GPA.
*************************************************************/
void Student::do_work(){
  // temporarily stores the number of hours studied
  int hours_studied;

  // correlates gpa with number of hours studied
  if (this->rating_gpa > 3) {
    hours_studied = rand() % 10 + 6;
  }
  else if (this->rating_gpa > 2) {
    hours_studied = rand() % 6 + 3;
  }
  else {
    hours_studied = rand() % 3 + 1;
  }

  // print out the number of hours the student studied
  std::cout << name << " did " << hours_studied << " hours of homework." << std::endl;
}

/*************************************************************
** Description: Prints out the GPA of the student.
*************************************************************/
void Student::print_rating_gpa(){
  std::cout << std::fixed;
  std::cout << "GPA: ";
  std::cout << std::setprecision(1) << get_rating_gpa() << std::endl;
}

/*************************************************************
** Description: Simple function that just returns 1 if the 
   person is a student. Same function with Instructor class
   which returns a 2.
*************************************************************/
int Student::get_type(){
  return 1;
}
