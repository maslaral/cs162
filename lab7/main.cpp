#include "Queue.hpp"
#include "QueueNode.hpp"

#include <iostream>

int main(){

  Queue test;

  // testing the add function
  test.addBack(8);
  test.addBack(1000);
  test.addBack(10);
  test.addBack(10);
  test.printQueue();

  // testing the remove front function
  std::cout << "Removing front:" << std::endl;
  test.removeFront();
  test.removeFront();
  test.removeFront();
  test.removeFront();
  test.printQueue();

  // testing the get front functions
  std::cout << "Print front:" << std::endl;
  std::cout << test.getFront() << std::endl;
  return 0;
}
