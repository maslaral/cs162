/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Instructor class, contains
   methods for setting variables, doing work, printing out the
   rating, and creating instructors.
*************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

class Instructor : public Person
{
  private:
  public:
    // constructor
    Instructor();
    
    // destructor
    ~Instructor();

    // create the instructor - static so no object needed to reference
    static Instructor* create_instructor();
    static Instructor* create_instructor_file();
    
    // function header for doing work
    virtual void do_work();
    
    // prints the rating of the professor
    virtual void print_rating_gpa();

    // get type
    virtual int get_type();

    // setter functions
    virtual void set_rating_gpa();
    virtual void set_age();

    // setter functions - used solely for reading from file
    virtual void set_rating_gpa_file(double);
    virtual void set_name(std::string);
    virtual void set_age_file(int);
};

#endif
