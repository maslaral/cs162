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
  if (head == nullptr){
    return;
  }

  QueueNode* garbage = head;

  while (garbage->get_next() != head){
    head = head->get_next();
    garbage->get_prev()->set_next(head);
    head->set_prev(garbage->get_prev());
    delete garbage;
    garbage = head;
  }
  delete garbage;
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
    // create new head node - prev and next both point to head
    head = new QueueNode(num);
    head->set_next(head);
    head->set_prev(head);
  }
  else {
    // initialize the new node and the next node
    QueueNode* new_node = new QueueNode(num);
    QueueNode* next_node = head->get_next();

    // traverse list until end of list 
    while (next_node->get_next() != head){
      next_node = next_node->get_next();
    }

    // set the new node to the last and link it back to the 
    // start of the list
    next_node->set_next(new_node);
    new_node->set_prev(next_node);
    new_node->set_next(head);
    head->set_prev(new_node);
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
    throw Queue::Empty();
  }
  else {
    // check - head last? 
    if (head->get_next() == head){
      head = nullptr;
    }
    else {
      QueueNode* temp = head;

      // link the new front back to the last element
      head = head->get_next();
      head->set_prev(temp->get_prev());
      head->get_prev()->set_next(head);

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
      while (next_node != head){
        std::cout << next_node->get_val() << std::endl;
        next_node = next_node->get_next();
      }
    }
    std::cout << std::endl;
  }
}

/*************************************************************
 ** Description: Function that outputs that the queue is empty.
 *************************************************************/
void Queue::outputEmpty(){
  std::cout << std::endl;
  std::cout << "Queue is empty." << std::endl;
  std::cout << std::endl;
}
