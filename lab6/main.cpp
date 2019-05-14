/*************************************************************
** Program name: Lab 6 
** Author: Alex Maslar
** Date: May 12 2019
** Description: Main function for the program which initializes
   the menu objects and controls the flow through the program
   with switch statements. Depending on the user input, the 
   function calls List class functions to edit the list or 
   display it.
*************************************************************/
#include "List.hpp"
#include "Node.hpp"
#include "Menu.hpp"

#include <iostream>

int main(){

  // initialize the list
  List list;
  
  // create the starting menu
  Menu start("Choose from the following options: ");
  start.addOptions("Add a new node to the head");
  start.addOptions("Add a new node to the tail");
  start.addOptions("Delete from the head");
  start.addOptions("Delete from the tail");
  start.addOptions("Traverse the list reversely");
  start.addOptions("Print the list head");
  start.addOptions("Print the list tail");
  start.addOptions("Read file");
  start.addOptions("Exit");
  
  // create the menu for entering an integer
  Menu get_number("Enter an integer");
  get_number.setLimits(0,100000);

  // print welcome message
  std::cout << "Welcome to my linked list!" << std::endl;
  std::cout << std::endl;

  // output the menu
  start.outputMenu();

  // continue to return to the menu until the user selects exit
  while (start.getUserInput() != 9){
    switch (start.getUserInput()){
      case 1: // add node to the head
      {
        get_number.outputMenu();
        list.add_head(get_number.getUserInput());
        list.display();
      }
      break;
      case 2: // add node to the tail
      {
        get_number.outputMenu();
        list.add_tail(get_number.getUserInput());
        list.display();
      }
      break;
      case 3: // delete head
      {
        list.delete_first();
        list.display();
      }
      break;
      case 4: // delete tail
      {
        list.delete_last();
        list.display();
      }
      break;
      case 5: // print in reverse
      {
        list.reverse_display();
      }
      break;
      case 6: // print the head
      {
        list.print_head();
      }
      break;
      case 7: // print the tail
      {
        list.print_tail();
      }
      break;
      case 8: // read from a file
      {
        list.read_file();
        list.display();
      }
      break;
    }

  std::cout << std::endl;
  // prompt with the menu again and then go back to beginning of loop
  start.outputMenu();
  }

  return 0;
}
