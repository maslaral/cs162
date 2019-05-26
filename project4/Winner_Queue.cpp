/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Implementation for the Winner Queue which stores
   the winners of the tournament. Includes functions to add 
   a winner, prints the winners, and clears the queue.
*************************************************************/
#include "Winner_Queue.hpp"
#include <iostream>

/*************************************************************
** Description: Constructor - sets on deck and last to nullptr
   to indicate an empty queue.
*************************************************************/
Winner_Queue::Winner_Queue(){
  on_deck = nullptr;
  last = nullptr;
}

/*************************************************************
** Description: Virtual destructor for the winner queue.
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
void Winner_Queue::add_winner(Character* &victor){
  victor->recover();

  if (is_empty()){
    on_deck = victor;
    last = victor;
    last->set_next(nullptr);
  }
  else {
    last->set_next(victor);
    last = last->get_next();
    last->set_next(nullptr);
  }
}

/*************************************************************
** Description: Function returns the player "on deck" or the
   next player to join the tournament.
*************************************************************/
Character* Winner_Queue::get_on_deck(){ 
  return on_deck;
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
    temp = nullptr;
    delete temp;
  }
}

/*************************************************************
** Description: Clears the queue if there are winners in it by
   deleting each successive Character in the queue.
*************************************************************/
void Winner_Queue::clear(){
  if (is_empty()){
    return;
  }
  else {
    Character* garbage = nullptr;

    while (on_deck != nullptr){
      garbage = on_deck;
      on_deck = on_deck->get_next();
      delete garbage;
    }
  }
}
