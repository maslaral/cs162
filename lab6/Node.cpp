/*************************************************************
** Program name: Lab 6 
** Author: Alex Maslar
** Date: May 12 2019
** Description: Node implementation that includes a constructor
   that sets the value in the Node, as well as getter and
   setter functions. The getter and setter functions are
   used to access the values and next and prev variables in
   the List class.
*************************************************************/
#include "Node.hpp"

/*************************************************************
** Description: Default constructor for the Node object that
   sets the previous and next pointers to nullptr.
*************************************************************/
Node::Node(){
  next = nullptr;
  prev = nullptr;
}

/*************************************************************
** Description: Constructor for the Node object that takes
   a value as a parameter. This is used to initialize the 
   Node object in the list function.
*************************************************************/
Node::Node(int val){
  this->val = val;
}

/*************************************************************
** Description: Destructor for the Node object.
*************************************************************/
Node::~Node(){
}

/*************************************************************
** Description: Getter functions to get the value, the pointer
   to the next object, and the pointer to the previous object.
*************************************************************/
int Node::get_val(){
  return val;
}

Node* Node::get_next(){
  return next;
}

Node* Node::get_prev(){
  return prev;
}

/*************************************************************
** Description: Setter functions to set the value, the pointer
   to the next object, and the pointer to the previous object.
*************************************************************/
void Node::set_val(int val){
  this->val = val;
}

void Node::set_next(Node* next){
  this->next = next;
}

void Node::set_prev(Node* prev){
  this->prev = prev;
}
