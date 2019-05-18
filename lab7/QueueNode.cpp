#include "QueueNode.hpp"

/*************************************************************
** Description: Default constructor - sets next and prev to
   nullptr.
*************************************************************/
QueueNode::QueueNode(){
  val = 0;
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
QueueNode* QueueNode::get_next(){
  return next;
}

QueueNode* QueueNode::get_prev(){
  return prev;
}

int QueueNode::get_val(){
  return val;
}


/*************************************************************
** Description: Setter functions to set the next and prev
   nodes.
*************************************************************/
void QueueNode::set_next(QueueNode* next){
  this->next = next;
}

void QueueNode::set_prev(QueueNode* prev){
  this->prev = prev;
}
