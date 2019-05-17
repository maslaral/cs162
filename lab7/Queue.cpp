#include "Queue.hpp"
#include <iostream>


/*************************************************************
 ** Description: Constructor - sets head to nullptr to indicate
 an empty queue
 *************************************************************/
Queue::Queue(){
  head = nullptr;
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
  }
  else {
    // create the new node
    QueueNode* new_node = new QueueNode(num);

    if (head->get_next() == nullptr){
      head->set_next(new_node);
    }
    else {
      // create a temp to traverse the list
      QueueNode* next_node = head->get_next();

      // run until the next is a nullptr
      while (next_node->get_next() != nullptr){
        next_node = next_node->get_next();
      }
      // set the next_node to the new node and the new node prev to the
      // next_node
      next_node->set_next(new_node);
      new_node->set_prev(next_node);
    }
  }
}

/*************************************************************
 ** Description: Returns the value stored in the head node in
 the queue.
 *************************************************************/
int Queue::getFront(){
  if (isEmpty()){
    throw Queue::Empty();
  }
  else {
    return head->get_val();
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
    // if the head is the last in the queue
    if (head->get_next() == nullptr){
      head = nullptr;
    }
    else {
      QueueNode* temp = head;
      head = head->get_next();
      delete temp;
    }
  }
}

/*************************************************************
 ** Description: Function prints the value of each node in the
 queue.
 *************************************************************/
void Queue::printQueue(){
  if (isEmpty()){
    throw Queue::Empty();
  }
  else {
    // print out the value of head
    std::cout << std::endl;
    std::cout << head->get_val() << std::endl;

    // check if there's a value after head
    if (head->get_next() != nullptr){

      // set var next_node to the node after head
      QueueNode* next_node = head->get_next();

      // until the next node is a nullptr, print out the value
      // and move up one in the queue
      while (next_node != nullptr){
        std::cout << next_node->get_val() << std::endl;
        next_node = next_node->get_next();
      }
    }
    std::cout << std::endl;
  }
}
