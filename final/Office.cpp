/*************************************************************
** Program name: Final
** Author: Alex Maslar
** Date: June 10 2019
** Description: Class implemetation file for the Office abstract
   class. The constructor assigns the room name and 
   objective, as well as the adjacent rooms.
*************************************************************/
#include "Office.hpp"

/*************************************************************
** Description: Default constructor
*************************************************************/
Office::Office(){
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
Office::~Office(){
}

/*************************************************************
** Description: Setter functions
*************************************************************/
void Office::set_adjacent(Office* t, Office* b, Office* r, Office* l){
  top = t;
  bottom = b;
  right = r;
  left = l;
}

void Office::set_room_name(std::string room_name){
  this->room_name = room_name;
}

/*************************************************************
** Description: Getter functions
*************************************************************/
Office* Office::get_top(){
  return top;
}

Office* Office::get_bottom(){
  return bottom;
}

Office* Office::get_left(){
  return left;
}

Office* Office::get_right(){
  return right;
}

std::string Office::get_room_name(){
  return room_name;
}

