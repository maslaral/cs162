/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Implementation of Loser Stack which stores the
   losers of the tournament. Includes functions to add a loser,
   prints the losers, and clears the stack.
*************************************************************/
#include "Loser_Stack.hpp"

#include <iostream>

/*************************************************************
** Description: Default constructor that sets the top of the
   stack to nullptr.
*************************************************************/
Loser_Stack::Loser_Stack(){
  top = nullptr;
}

/*************************************************************
** Description: Virtual destructor for the loser stack.
*************************************************************/
Loser_Stack::~Loser_Stack(){
}

/*************************************************************
** Description: Function that returns true if the stack is
   empty and false if there are losers in it.
*************************************************************/
bool Loser_Stack::is_empty() const {
  if (top == nullptr){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Function that adds a loser to the loser stack.
   The function sets the top to the loser and next to nullptr
   if the stack is empty. If the stack is not empty, the
   function sets the new loser to the top of the stack and
   the next to the previous top.
*************************************************************/
void Loser_Stack::add_loser(Character* &loser){
  // add player to top
  if (is_empty()){
    top = loser;
    top->set_next(nullptr);
  }
  // add player to top, replace past player
  else {
    loser->set_next(nullptr);
    if (top->get_next() == nullptr){
      top->set_next(loser);
    }
    else {
      loser->set_next(top->get_next());
      top->set_next(loser);
    }
  }
}

/*************************************************************
** Description: Function prints out all of the losers in the
   stack.
*************************************************************/
void Loser_Stack::print_losers(){
  if (is_empty()){
    return;
  }

  Character* temp = top;
  
  // first print out the top value
  std::cout << temp->get_name() << " - " << temp->get_type() << std::endl;

  // print out each character until next is equal to nullptr
  while (temp->get_next() != nullptr){
    temp = temp->get_next();
    std::cout << temp->get_name() << " - " << temp->get_type() << std::endl;
  }
}

/*************************************************************
** Description: Clears the stack if there are losers in it by
   deleting each successive Character in the stack.
*************************************************************/
void Loser_Stack::clear(){
  if (is_empty()){
    return;
  }
  else {
    Character* garbage = nullptr;

    while (top != nullptr){
      garbage = top;
      top = top->get_next();
      delete garbage;
    }
  }
}
