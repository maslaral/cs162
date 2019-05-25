/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
*************************************************************/
#include "Loser_Stack.hpp"

#include <iostream>

Loser_Stack::Loser_Stack(){
  top = nullptr;
}

Loser_Stack::~Loser_Stack(){
  if (is_empty()){
    return;
  }
  Character* temp = top;
  while (temp != nullptr){
    delete top;
    temp = temp->get_next();
    top = temp;
  }
  delete temp;
}

bool Loser_Stack::is_empty() const {
  if (top == nullptr){
    return true;
  }
  else {
    return false;
  }
}

void Loser_Stack::add_loser(Character* loser){
  // add player to top
  if (is_empty()){
    top = loser;
    top->set_next(nullptr);
  }
  else {
    loser->set_next(top);
    top = loser;
  }
}

void Loser_Stack::print_losers(){
  if (is_empty()){
    return;
  }

  Character* temp = top;

  while (temp != nullptr){
    std::cout << temp->get_name() << " - " << temp->get_type() << std::endl;
    temp = temp->get_next();
  }

  delete temp;
}
