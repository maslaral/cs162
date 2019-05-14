/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Tiger class. Declares the
   private variable feed cost and the methods in the tiger
   class. 
*************************************************************/
#ifndef TIGER_HPP 
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{
  private: 
    int feed_cost;

  public:
    // constructor
    Tiger();
    
    // destructor
    virtual ~Tiger();

    // function that checks whether an adult
    virtual bool is_adult();
    
    // getter functions
    virtual int get_cost();
    virtual int get_number_of_babies();
    virtual int get_payoff();
    virtual int get_feed_cost();

    // setter functions
    virtual void set_cost(int);
    virtual void set_number_of_babies(int);
    virtual void set_payoff(int);
};

#endif
