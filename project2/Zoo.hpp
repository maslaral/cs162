/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Header file for the Zoo class. Defines functions
   used to play the Zoo tycoon game and key variables such as
   the bank balance and the number of animals. In addition,
   the Zoo class also creates arrays that hold pointers to 
   each animal type objects.
*************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "animal_enum.hpp"
#include "event_enum.hpp"

class Zoo
{
  private:
    // general variables related to zoo
    int bank_balance;
    int profit;
    int bonus;
    int number_of_days_open;
    
    // tiger specific variables
    Tiger** tiger_cage;
    int number_of_tigers;
    int number_of_tiger_cages;

    // penguin specific variables
    Penguin** penguin_cage;
    int number_of_penguins;
    int number_of_penguin_cages;

    // turtle specific variables
    Turtle** turtle_cage;
    int number_of_turtles;
    int number_of_turtle_cages;

  public:
    Zoo();
    ~Zoo();
    
    // general
    void increase_age();
    int get_animal(animal_type);
    
    // random event functions
    void random_event();
    void random_event_birth();
    void random_event_death();
    void random_event_attend_boom();
    void random_event_nothing();

    // functions for birth
    bool check_adult(animal_type);
    void give_birth(animal_type);

    // functions for adding animals
    void animal_purchase(animal_type, int);
    bool open_capacity(animal_type);
    int get_open_cage(animal_type);
    
    // tiger specific
    void add_tiger(int);
    void add_tiger_capacity();

    // penguin specific
    void add_penguin(int);
    void add_penguin_capacity();

    // turtle specific
    void add_turtle(int);
    void add_turtle_capacity();

    // functions for removing animals
    void remove_animal(animal_type);
   
    // zoo administrative functions
    void end_of_day();
    void pay_feed_cost();
    int get_number_of_days_open();
    int get_bank_balance();
};

#endif
