/*************************************************************
** Program name: Lab 4
** Author: Alex Maslar
** Date: April 28 2019
** Description: Main file for the OSU information system,
   provides prompts for the users and calls functions based
   on user inputs. 
*************************************************************/
#include "University.hpp"
#include "Menu.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>

enum type_of_person{STUDENT = 1, INSTRUCTOR = 2};

int main() {

  // seed the random number generator
  srand(time(NULL));

  // construct the university object
  University osu;

  std::cout << "---------------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::cout << "Welcome to the Oregon State University Information System" << std::endl;
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------" << std::endl;
  std::cout << "Begin by adding a student and instructor to the system." << std::endl;
  std::cout << "---------------------------------------------------------" << std::endl;

  // create a student and instructor
  osu.add_person(STUDENT);
  osu.add_person(INSTRUCTOR);

  std::cout << "---------------------------------------------------------" << std::endl;
  std::cout << "Now add two buildings to the system." << std::endl;
  std::cout << "---------------------------------------------------------" << std::endl;
  
  // create two buildings
  osu.add_building();
  osu.add_building();

  // creating the main program menu
  Menu main("Choose from the following options: ");
  main.addOptions("Print building information");
  main.addOptions("Print instructor and student information");
  main.addOptions("Choose a person to do work");
  main.addOptions("Add an instructor or student");
  main.addOptions("Save information to file");
  main.addOptions("Read information from file");
  main.addOptions("Exit the program");

  // while statement that reprompts the user until they choose
  // to exit the program
  while (main.getUserInput() != 7){
    
    // initializing menu prior to the switch statement
    Menu person_position("Would you like to add an instructor or student?");
    person_position.addOptions("Instructor");
    person_position.addOptions("Student");
   
    // output the menu
    main.outputMenu();

    // switch statements based on user input
    switch(main.getUserInput()){
    case 1: 
      osu.print_building_info();
      break;
    case 2:
      osu.print_people_info();
      break;
    case 3:
      osu.print_do_work_menu();
      break;
    case 4:
      person_position.outputMenu();

      std::cin.clear();
      std::cin.ignore(256,'\n');

      // add an instructor or student based on user input
      if (person_position.getUserInput() == 1){
        osu.add_person(INSTRUCTOR);
      }
      else {
        osu.add_person(STUDENT);
      }
      break;
    case 5:
      osu.save_to_file();
      break;
    case 6:
      osu.read_from_file();
      break;
    }
    
    std::cout << std::endl;
  }

  return 0;
}

