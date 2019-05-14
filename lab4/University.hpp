/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 29 2019
** Description: Header file for the University class which
   defines the variables and functions used in the class.
   These include pointers to Person and Building objects,
   vectors for holding those pointers, and methods for 
   adding Person/Building objects to those vectors.
*************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>
#include "Person.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

class University
{
  private:
    const std::string name;
    Person* p;
    Building* b;
    std::vector<Person*> people;
    std::vector<Building*> buildings;
  public:
    // constructor
    University();
    
    // destrucotr
    ~University();

    // functions to print out the vectors
    void print_building_info();
    void print_people_info();
    void print_do_work_menu();

    // functino to add objects
    void add_person(int);
    void add_building();
    
    // functions for interacting with files
    Person* add_person_file(int);
    void save_to_file();
    void read_from_file();
};

#endif
