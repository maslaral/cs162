/*************************************************************
** Program name: Project 4
** Author: Alex Maslar
** Date: May 21 2019
** Description: 
*************************************************************/
#ifndef LOSER_STACK_HPP
#define LOSER_STACK_HPP

#include "Character.hpp"

class Loser_Stack {
  private:
    Character* top;
    Character* last;
  public:
    // constructor
    Loser_Stack();
    // destructor
    ~Loser_Stack();

    bool is_empty() const;
    void add_loser(Character*&);
    void print_losers();
};

#endif
