#include "Queue.hpp"
#include "QueueNode.hpp"
#include "Menu.hpp"

#include <iostream>

int main(){

  Queue main_queue;

  // initialize the start menu
  Menu start("Select from the following program options:");
  start.addOptions("Add a value to the back of the queue");
  start.addOptions("Display the front value");
  start.addOptions("Remove the front node");
  start.addOptions("Display the queue's content");
  start.addOptions("Exit");
  
  // initialize the add menu - limits don't really matter here
  Menu add("Enter an integer value to add to the back of the queue");
  add.setLimits(0, 100000);

  while (start.getUserInput() != 5){
    start.outputMenu();
    int user_input = start.getUserInput();

    switch (user_input){
      case 1: {
        add.outputMenu();
        main_queue.addBack(add.getUserInput());
      }
      break;
      case 2: {
        try {
          int front = main_queue.getFront();

          std::cout << std::endl;
          std::cout << front << std::endl;
          std::cout << std::endl;
        }
        catch (Queue::Empty){
          std::cout << std::endl;
          std::cout << "Queue is empty." << std::endl;
          std::cout << std::endl;
        }
      }
      break;
      case 3: {
        main_queue.removeFront();
      }
      break;
      case 4: {
        try {
          main_queue.printQueue();
        }
        catch (Queue::Empty){
          std::cout << std::endl;
          std::cout << "Queue is empty." << std::endl;
          std::cout << std::endl;
        }
      }
      break;
    }
  }    

  return 0;
}
