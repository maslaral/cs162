#include "Winner_Queue.hpp"
#include <iostream>

/*************************************************************
** Description: Constructor
*************************************************************/
Winner_Queue::Winner_Queue(){
  on_deck = nullptr;
  last = nullptr;
}

/*************************************************************
** Description: Destructor
*************************************************************/
Winner_Queue::~Winner_Queue(){
}

/*************************************************************
** Description: Fuction checks if the queue contains no
   elements and returns a boolean value. Used to avoid underflow
   by throwing an exception when this is the case.
*************************************************************/
bool Winner_Queue::is_empty() const {
  if (on_deck == nullptr){
    return true;
  }
  else {
    return false;
  }
}

/*************************************************************
** Description: Functions adds the character passed into the
   function (the victor of previous round) in the end of the
   winner queue.
*************************************************************/
void Winner_Queue::add_winner(Character* victor){
  if (is_empty()){
    on_deck = victor;
    last = victor;
  }
  else {
    last->set_next(victor);
    last = last->get_next();
  }
}

/*************************************************************
** Description: Function returns the player "on deck" or the
   next player to join the tournament.
*************************************************************/
Character* Winner_Queue::get_on_deck(){ 
  Character* temp = on_deck;
  remove_on_deck();
  return temp;
}

/*************************************************************
** Description: Function deletes the on deck player - this is
   called after the player enters the game.
*************************************************************/
void Winner_Queue::remove_on_deck(){
  if (is_empty()){
    return;
  }
  else if (on_deck == last){
    on_deck = nullptr;
    last = nullptr;
  }
  else {
    Character* temp = on_deck;
    on_deck = on_deck->get_next();
    delete temp;
  }
}
