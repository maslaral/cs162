#include "Queue.hpp"
#include <iostream>

/************************************************************* ** Description: Default constructor - sets the head and rear 
 to nullptr to indicate an empty queue.
 *************************************************************/
Queue::Queue(){
  head = nullptr;
  rear = nullptr;
}

/*************************************************************
 ** Description: Destructor - deletes each node in the queue
 and sets them to nullptr.
 *************************************************************/
Queue::~Queue(){
  QueueNode* garbage = head;
  while (garbage != nullptr){
    head = head->get_next();
    garbage->set_next(nullptr);
    delete garbage;
    garbage = head;
  }
}

/*************************************************************
 ** Description: Function checks if the queue contains no
 elements and returns a boolean value. Used to avoid
 underflow by throwing an exception when this is the case.
 *************************************************************/
bool Queue::isEmpty() const {
  if (head == nullptr){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
 ** Description: Function adds a node to the end of the queue
 with the value entered by the user.
 *************************************************************/
void Queue::addBack(int num){
  if (isEmpty()){
    head = new QueueNode(num);
    rear = head;
  }
  else {
    QueueNode* new_node = new QueueNode(num);
    rear->set_next(new_node);
    rear = rear->get_next();
  }
}

/*************************************************************
 ** Description: Returns the value stored in the head node in
 the queue.
 *************************************************************/
void Queue::getFront(){
  if (isEmpty()){
    std::cout << std::endl;
    std::cout << "Queue is empty." << std::endl;
    std::cout << std::endl;
  }
  else {
    std::cout << std::endl;
    std::cout << head->get_val() << std::endl;
    std::cout << std::endl;
  }
}

/*************************************************************
 ** Description: Function removes the first node in the queue
 by assigning the head to temp, reassigning the head node
 to the next node in the queue, and then deleting the temp
 variable.
 *************************************************************/
void Queue::removeFront(){
  if (isEmpty()){
    std::cout << std::endl;
    std::cout << "Queue is empty." << std::endl;
    std::cout << std::endl;
    return;
  }
  else {
    QueueNode* temp = head;
    head = head->get_next();
    delete temp;
  }
}

/*************************************************************
 ** Description: Function prints the value of each node in the
 queue.
 *************************************************************/
void Queue::printQueue(){
  if (isEmpty()){
    std::cout << std::endl;
    std::cout << "Queue is empty." << std::endl;
    std::cout << std::endl;
  }
  else {
    // print out the value of head
    std::cout << std::endl;
    std::cout << head->get_val() << std::endl;
    
    // check if there's a value after head
    if (head->get_next() == nullptr){
      return;
    }

    // set var next_node to the node after head
    QueueNode* next_node = head->get_next();

    // until the next node equals rear, print out the value
    // and move up one in the queue
    while (next_node != rear){
      std::cout << next_node->get_val() << std::endl;
      next_node = next_node->get_next();
    }
    std::cout << rear->get_val() << std::endl;
    std::cout << std::endl;
  }
}
