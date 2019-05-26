/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: Implementation for the Winner Queue which stores
   the winners of the tournament. Includes functions to add 
   a winner, prints the winners, and clears the queue.
*************************************************************/
#ifndef WINNER_QUEUE_HPP
#define WINNER_QUEUE_HPP

#include "Character.hpp"

class Winner_Queue {
  private:
    Character* on_deck;
    Character* last;
  public:
    // constructor
    Winner_Queue();
    // destructor
    ~Winner_Queue();

    bool is_empty() const;
    void add_winner(Character*&);
    Character* get_on_deck();
    void remove_on_deck();
    void print_lineup();
    void clear();
};

#endif
