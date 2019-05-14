/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the penguin class that declares
   the private variable function and the methods used by the
   Penguin objects.
*************************************************************/
#ifndef PENGUIN_HPP 
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal
{
  private: 
    int feed_cost;
  public:
    // constructor
    Penguin();
    
    // destructor
    virtual ~Penguin();

    // checks if the penguin is an adult
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
