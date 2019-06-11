/*************************************************************
** Program name: Lab 7
** Author: Alex Maslar
** Date: May 18 2019
** Description: Function implementation for the Inbox class. 
   Includes functions to add a node to the back of the queue,
   to get the front value in the queue, remove the front node
   from the queue, and to print the values of each node in the
   queue. The Inbox is a circular queue, meaning that the head
   previous node is the tail of the queue, and the tail of the
   queue next node is the head. 
*************************************************************/
#include "Inbox.hpp"
#include <iostream>

/*************************************************************
 ** Description: Constructor - sets head to nullptr to indicate
    an empty queue
*************************************************************/
Inbox::Inbox(){
  head = nullptr;
}

/*************************************************************
 ** Description: Destructor - deletes each node in the queue by
    traversing the queue until just the head remains
*************************************************************/
Inbox::~Inbox(){
  if (head == nullptr){
    return;
  }

  Email* garbage = head; 

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
bool Inbox::isEmpty() const {
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
void Inbox::outputEmpty(){
  std::cout << std::endl;
  std::cout << "Inbox is empty." << std::endl;
  std::cout << std::endl;
}

/*************************************************************
 ** Description: Function adds a node to the end of the queue
    with the value entered by the user. If it's the first node
    in the queue, it creates it as the head of the queue and
    sets it to point at itself.
*************************************************************/
void Inbox::addBack(std::string sender, std::string subject, std::string body){
  if (isEmpty()){
    // create new head node - prev and next both point to head
    head = new Email;
    head->sender = sender;
    head->subject = subject;
    head->body = body;
    head->next = head;
    head->prev = head;
  }
  else {
    // initialize the new node and the next node
    Email* new_email = new Email;
    new_email->sender = sender;
    new_email->subject = subject;
    new_email->body = body;
    Email* next_email = head->next;

    // traverse list until end of list 
    while (next_email->next != head){
      next_email = next_email->next;
    }

    // set the new node to the last and link it back to the 
    // start of the list
    next_email->next = new_email;
    new_email->prev = next_email;
    new_email->next = head;
    head->prev = new_email;
  }
}

/*************************************************************
 ** Description: Returns the value stored in the head node in
    the queue. If the queue is empty, throws an exception.
*************************************************************/
std::string Inbox::getFront(){
  if (isEmpty()){
    throw Inbox::Empty();
  }
  else {
    return head->sender;
  }
}

/*************************************************************
 ** Description: Function removes the first node in the queue
    by assigning the head to temp, reassigning the head node
    to the next node in the queue, and then deleting the temp
    variable.
*************************************************************/
void Inbox::removeFront(){
  if (isEmpty()){
    throw Inbox::Empty();
  }
  else {
    // check - head last? 
    if (head->next == head){
      head = nullptr;
    }
    else {
      Email* temp = head;

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
void Inbox::printInbox(){
  if (isEmpty()){
    throw Inbox::Empty();
  }
  else {
    // print out the value of head
    std::cout << std::endl;
    std::cout << head->sender << std::endl;
    std::cout << head->subject << std::endl;

    // check if there's a value after head
    if (head->next != head){
      // set var next_node to the node after head       
      Email* next_email = head->next;
      // print until next_node equals head
      while (next_email != head){
        std::cout << next_email->sender << std::endl;
        std::cout << next_email->subject << std::endl;
        next_email = next_email->next;
      }
    }
    std::cout << std::endl;
  }
}
