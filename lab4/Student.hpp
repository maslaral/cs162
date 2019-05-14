/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 30 2019
** Description: Header file for the Student class. Contains 
   only functions as the variables are set in the abstract
   person class. 
*************************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"
#include <string>

class Student : public Person
{
  private:
  public:
    // constructor
    Student();
    // destructor
    ~Student();

    // create student - both from file and from user input 
    static Student* create_student();
    static Student* create_student_file();

    // setter functions
    virtual void set_rating_gpa();
    virtual void set_age();
    virtual void do_work();
    virtual void print_rating_gpa();
    virtual int get_type();

    // setter functions - used to read from file
    virtual void set_rating_gpa_file(double);
    virtual void set_name(std::string);
    virtual void set_age_file(int);

};

#endif
