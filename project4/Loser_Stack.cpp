/*************************************************************
** Program name: Project 4
** Author: Alex Maslar 
** Date: May 21 2019
** Description: 
*************************************************************/
#include "Loser_Stack.hpp"

#include <iostream>

Loser_Stack::Loser_Stack(){ top = nullptr;
  last = nullptr;
}

Loser_Stack::~Loser_Stack(){
  if (is_empty()){
    return;
  }

  Character* temp = top;
  while (temp != last){
    temp = top->get_next();
    delete top;
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

/*************************************************************
** Description: Adds loser to the start of the stack - if 
   the stack is empty, top and last are set to loser. In the
   cases where the stack is not empty, the character is 
   assigned to the top, and the last in the queue is adjusted
   so the new top is next.
*************************************************************/
void Loser_Stack::add_loser(Character* &loser){
  // add player to top
  if (is_empty()){
    top = loser;
    last = loser;
    top->set_next(last);
    last->set_next(top);
  }
  else {
    Character* temp = top;
    top = loser;
    top->set_next(temp);
    last->set_next(top);
  }
}

/*************************************************************
** Description: Prints the loser stack if there are losers
   in the stack. It goes through the stack starting at the top
   until the next in the stack equals last. At this point, it
   prints the last loser in the stack.
*************************************************************/
void Loser_Stack::print_losers(){
  if (is_empty()){
    return;
  }

  Character* temp = top;

  while (temp != last){
    std::cout << temp->get_name() << " - " << temp->get_type() << std::endl;
    temp = temp->get_next();
  }

  std::cout << last->get_name() << " - " << last->get_type() << std::endl;
}
