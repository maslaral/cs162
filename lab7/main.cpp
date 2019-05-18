/*************************************************************
** Program name: Lab 7
** Author: Alex Maslar
** Date: May 18 2019
** Description: Main function which initializes the menus 
   according to project specifications, and controls the 
   flow through the menu and calls each function based on
   user input. 
*************************************************************/
#include "Queue.hpp"
#include "Menu.hpp"

#include <iostream>

int main(){

  // initialize the queue
  Queue main_queue;

  // initialize the start menu
  Menu start("Select from the following program options:");
  start.addOptions("Add a value to the back of the queue");
  start.addOptions("Display the front value");
  start.addOptions("Remove the front node");
  start.addOptions("Display the queue's content");
  start.addOptions("Exit");
  
  // initialize the add menu
  Menu add("Enter an integer value to add to the back of the queue");
  add.setLimits(0, 1000000);

  // as long as user doesn't choose to exit, keep reprompting
  while (start.getUserInput() != 5){
    start.outputMenu();
    int user_input = start.getUserInput();

    switch (user_input){
      case 1: // add node to end of queue
      {
        add.outputMenu();
        main_queue.addBack(add.getUserInput());
      }
      break;
      case 2: // get value of head node
      {
        try {
          std::cout << std::endl;
          std::cout << main_queue.getFront() << std::endl;
          std::cout << std::endl;
        }
        catch (Queue::Empty){
          main_queue.outputEmpty(); // outputs the queue is empty
        }
      }
      break;
      case 3: // remove head node
      {
        try {
          main_queue.removeFront();
        }
        catch (Queue::Empty){
          main_queue.outputEmpty(); // outputs the queue is empty
        }
      }
      break;
      case 4: // print queue
      {
        try {
          main_queue.printQueue();
        }
        catch (Queue::Empty){
          main_queue.outputEmpty(); // outputs the queue is empty
        }
      }
      break;
    }
  }    

  return 0;
}
