/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Animal super class. Declares
   variables for the animal and pure virtual functions to make
   the class abstract.
*************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
  protected:
    int age;
    int cost;
    int number_of_babies;
    int payoff;
    int base_feed_cost;

  public:
    Animal();
    virtual ~Animal();

    // doesn't need to have polymorphism
    void add_day();
    int get_age();
    void set_age(int);

    // gets the base feed cost
    int get_base_feed_cost();

    // checks if the animal is an adult
    virtual bool is_adult() = 0;

    // getter functions
    virtual int get_cost() = 0;
    virtual int get_number_of_babies() = 0;
    virtual int get_payoff() = 0;
    virtual int get_feed_cost() = 0;

    // setter functions
    virtual void set_cost(int) = 0;
    virtual void set_number_of_babies(int) = 0;
    virtual void set_payoff(int) = 0;
};

#endif
