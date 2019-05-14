/*************************************************************
** Program name:
** Author: Alex Maslar
** Date: April 29 2019
** Description: University class functions that control adding
   elements to the person vectors, printing out people and
   building info, and printing the do work results. 
*************************************************************/
#include "University.hpp"
#include "Menu.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/*************************************************************
** Description: Constructor - creates the university object
   and sets the string name to Oregon State University - set
   as a constant
*************************************************************/
University::University(){
  const std::string name = "Oregon State University";
}

/*************************************************************
** Description: Destructor
*************************************************************/
University::~University(){
  for (std::size_t i = 0, size = people.size(); i < size; i++){
    delete people[i];
    people[i] = nullptr;
  }
  for (std::size_t i = 0, size = buildings.size(); i < size; i++){
    delete buildings[i];
    buildings[i] = nullptr;
  }
}

/*************************************************************
** Description: Adds a person pointer to the vector whenever
   the function is called. Also calls the create_student
   or create_instructor depending on what type is passed to
   the function.
*************************************************************/
void University::add_person(int type) {
  if (type == 1) { 
    Person* p = Student::create_student();
    people.push_back(p);
  }
  else {
    Person* p = Instructor::create_instructor();
    people.push_back(p);
  }
}

/*************************************************************
** Description: Adds a person pointer to the vector whenever
   the function is called. Also calls the create_student
   or create_instructor depending on what type is passed to
   the function. This function is the same as the function
   above except it doesn't return a pointer to the person object.
   The function is used solely for reading from file.
*************************************************************/
Person* University::add_person_file(int type) {

  Person* p;

  if (type == 1) { 
    p = Student::create_student_file();
    people.push_back(p);
  }
  else {
    p = Instructor::create_instructor_file();
    people.push_back(p);
  }

  return p;
}

/*************************************************************
** Description: Adds a building to the buildings vector
*************************************************************/
void University::add_building(){
  Building* b = new Building();
  buildings.push_back(b);
  b->create_building();
}

/*************************************************************
** Description: Prints the buildin information each time its
   called.
*************************************************************/
void University::print_building_info(){
  for (std::size_t i = 0, size = buildings.size(); i < size; i++){
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Name: " << buildings[i]->get_building_name() << std::endl;
    std::cout << "Address: " << buildings[i]->get_address() << std::endl;
    std::cout << "Size: " << buildings[i]->get_size() << std::endl;
  }
}

/*************************************************************
** Description: Prints the people information each time its called.
*************************************************************/
void University::print_people_info(){
  for (std::size_t i = 0, size = people.size(); i < size; i++){
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Name: " << people.at(i)->get_name() << std::endl;
    std::cout << "Age: " << people.at(i)->get_age() << std::endl;
    people.at(i)->print_rating_gpa();
  }
}

/*************************************************************
** Description: Prints a menu of workers to choose from
   and then calls the do_work function to print the amount
   of work they accomplished.
*************************************************************/
void University::print_do_work_menu(){
  // creates a menu to choose the person you'd like to do work
  Menu choose_worker("Choose from the following to do work: ");

  // for loop that creates options out of the naems of people in the
  // array
  for (std::size_t i = 0, size = people.size(); i < size; i++){
    choose_worker.addOptions(people.at(i)->get_name());
  }
  
  // outputs the menu
  choose_worker.outputMenu();

  // subtract one to account for the fact the vector starts at 0
  int user_input = choose_worker.getUserInput() - 1; 

  // calls the do_work function
  people[user_input]->do_work();
}

/*************************************************************
** Description: Opens a file and saves the information about
   the people to the file.
*************************************************************/
void University::save_to_file(){
  std::ofstream ofs;
  ofs.open("file.txt");
  
  for (std::size_t i = 0, size = people.size(); i < size; i++){
    ofs << people.at(i)->get_type() << std::endl;
    ofs << people.at(i)->get_name() << std::endl;
    ofs << people.at(i)->get_age() << std::endl;
    ofs << people.at(i)->get_rating_gpa() << std::endl;
  }
  
  // close the file
  ofs.close();
}


/*************************************************************
** Description: Gets the information saved in file.txt and
   creates Students/Instructor objects. It acheives this
   by looking at each block of four lines and first getting
   the type of person (which is passed to the add_person
   function), then the name, age and rating/gpa. 
*************************************************************/
void University::read_from_file(){
  
  // creating and opening the ifstream
  std::ifstream ifs;
  ifs.open("file.txt");
  
  // declaring the line number and the
  // string input variable
  int linenumber = 1;
  std::string input;

  // setting the pointer to a person object
  // to nullptr
  Person* p = nullptr;

  // while loop that gets the line
  while (std::getline(ifs, input)){

    // intializing the istring stream for getting
    // int values 
    std::istringstream ss(input);
    
    int n;     // stores integer values in the if statments
    double r;  // stores double values in the if statements

    // get the first line - this is a 1 for a student and a 
    // 2 for an instructor
    if (linenumber == 1){
      ss >> n;
      p = add_person_file(n);
      linenumber++;
    }

    // get the second line which is the name
    else if (linenumber == 2){
      p->set_name(input);
      linenumber++;
    }

    // get the third line which is the age
    else if (linenumber == 3){
      ss >> n;
      p->set_age_file(n);
      linenumber++;
    }

    // get the last line which is the gpa,
    // reset the line number counter back to
    // 1
    else {
      ss >> r;
      p->set_rating_gpa_file(r); 
      linenumber = 1;
      p = nullptr;
    }
  }

  // close the input file stream
  ifs.close();
}
