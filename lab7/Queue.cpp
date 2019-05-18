/*************************************************************
** Program name: Lab 7
** Author: Alex Maslar
** Date: May 18 2019
** Description: Function implementation for the Queue class. 
   Includes functions to add a node to the back of the queue,
   to get the front value in the queue, remove the front node
   from the queue, and to print the values of each node in the
   queue. The Queue is a circular queue, meaning that the head
   previous node is the tail of the queue, and the tail of the
   queue next node is the head. 
*************************************************************/
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
 ** Description: Destructor - deletes each node in the queue by
    traversing the queue until just the head remains
*************************************************************/
Queue::~Queue(){
  if (head == nullptr){
    return;
  }

  QueueNode* garbage = head; 

  while (garbage->next != head){
    head = head->next;
    garbage->prev->next = head;    
    head->prev = garbage->prev; // head prev to last node
    delete garbage;
    garbage = head;
  }
  delete garbage; // delete head
}

/*************************************************************
 ** Description: Function checks if the queue contains no
    elements and returns a boolean value. Used to avoid
    underflow by throwing an exception when this is the case -
    exception thrown in other functions.
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
 ** Description: Function that outputs that the queue is empty.
    Created to just reduce redundancy.
*************************************************************/
void Queue::outputEmpty(){
  std::cout << std::endl;
  std::cout << "Queue is empty." << std::endl;
  std::cout << std::endl;
}

/*************************************************************
 ** Description: Function adds a node to the end of the queue
    with the value entered by the user. If it's the first node
    in the queue, it creates it as the head of the queue and
    sets it to point at itself.
*************************************************************/
void Queue::addBack(int num){
  if (isEmpty()){
    // create new head node - prev and next both point to head
    head = new QueueNode;
    head->val = num;
    head->next = head;
    head->prev = head;
  }
  else {
    // initialize the new node and the next node
    QueueNode* new_node = new QueueNode;
    new_node->val = num;
    QueueNode* next_node = head->next;

    // traverse list until end of list 
    while (next_node->next != head){
      next_node = next_node->next;
    }

    // set the new node to the last and link it back to the 
    // start of the list
    next_node->next = new_node;
    new_node->prev = next_node;
    new_node->next = head;
    head->prev = new_node;
  }
}

/*************************************************************
 ** Description: Returns the value stored in the head node in
    the queue. If the queue is empty, throws an exception.
*************************************************************/
int Queue::getFront(){
  if (isEmpty()){
    throw Queue::Empty();
  }
  else {
    return head->val;
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
    if (head->next == head){
      head = nullptr;
    }
    else {
      QueueNode* temp = head;

      // link the new front back to the last element
      head = head->next;
      head->prev = temp->prev;
      head->prev->next = head;

      delete temp;
    }
  }
}

/*************************************************************
 ** Description: Function prints the value of each node in the
    queue. It prints each node by traversing the list until
    it gets to the node that points to the head of the queue.
*************************************************************/
void Queue::printQueue(){
  if (isEmpty()){
    throw Queue::Empty();
  }
  else {
    // print out the value of head
    std::cout << std::endl;
    std::cout << head->val << std::endl;

    // check if there's a value after head
    if (head->next != head){
      // set var next_node to the node after head       
      QueueNode* next_node = head->next;
      // print until next_node equals head
      while (next_node != head){
        std::cout << next_node->val << std::endl;
        next_node = next_node->next;
      }
    }
    std::cout << std::endl;
  }
}
