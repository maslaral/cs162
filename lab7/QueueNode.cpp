#include "QueueNode.hpp"

/*************************************************************
** Description: Default constructor - sets next and prev to
   nullptr.
*************************************************************/
QueueNode::QueueNode(){
  next = nullptr;
  prev = nullptr;
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
QueueNode::~QueueNode(){
}

/*************************************************************
** Description: Constructor that takes an int val as its 
   argument and sets that to val, also sets next and prev to
   nullptr to indicate it's a one element queue 
*************************************************************/
QueueNode::QueueNode(int val){
  this->val = val;
  next = nullptr;
  prev = nullptr;
}

/*************************************************************
** Description: Getter functions to return the values related
   to the node's position and value.
*************************************************************/
int QueueNode::get_next(){
  return next;
}

int QueueNode::get_prev(){
  return prev;
}

int QueueNode::get_val(){
  return val;
}
