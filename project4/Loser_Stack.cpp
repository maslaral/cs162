/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Implementation of Loser Stack which stores the
   losers of the tournament. Includes functions to 
*************************************************************/
#include "Loser_Stack.hpp"

#include <iostream>

/*************************************************************
** Description:
*************************************************************/
Loser_Stack::Loser_Stack(){
  top = nullptr;
}

/*************************************************************
** Description:
*************************************************************/
Loser_Stack::~Loser_Stack(){
  if (is_empty()){
    return;
  }

  Character* temp = top;
  while (temp != nullptr){
    temp = top->get_next();
    delete top;
    top = temp;
  }

  delete temp;
}

/*************************************************************
** Description:
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
** Description:
*************************************************************/
void Loser_Stack::add_loser(Character* &loser){
  // add player to top
  if (is_empty()){
    top = loser;
    top->set_next(nullptr);
  }
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
** Description:
*************************************************************/
void Loser_Stack::print_losers(){
  if (is_empty()){
    return;
  }

  Character* temp = top;

  std::cout << temp->get_name() << " - " << temp->get_type() << std::endl;

  while (temp->get_next() != nullptr){
    temp = temp->get_next();
    std::cout << temp->get_name() << " - " << temp->get_type() << std::endl;
  }
}

/*************************************************************
** Description:
*************************************************************/
void Loser_Stack::clear(){
  if (is_empty()){
    return;
  }

  Character* temp = top;
  while (temp != nullptr){
    temp = top->get_next();
    delete top;
    top = temp;
  }
}
