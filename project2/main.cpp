/*************************************************************
** Program name: Project 2 - Zoo Tycoon
** Author: Alex Maslar
** Date: April 28 2019
** Description: Main function for implementing the zoo tycoon
   game. It creates menu objects to guide the user through
   the game and has a while loop that controls the number of
   days the user wants to play.
*************************************************************/
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Zoo.hpp"
#include "Menu.hpp"
#include "animal_enum.hpp"
#include "event_enum.hpp"

#include<iostream>

int main(){

  // seeds the random number generator
  srand(time(NULL));

  // initialize the zoo object
  Zoo zoo;

  // menu to start the program
  Menu start("Welcome to your very own Zoo, good luck!");
  start.addOptions("Start");
  start.addOptions("Quit");
  start.outputMenu();

  // if the user chooses start, play the game
  // if the user choose quit, then jump to the end of the program and quit
  if (start.getUserInput() == 1){

  // menu for inital purchase of tigers
  Menu purchaseTigers("Would you like to purchase one or two tigers?");
  purchaseTigers.setLimits(1,2);
  purchaseTigers.outputMenu();

  // calls the function to create the tiger objects and add
  // them to the tiger array
  zoo.animal_purchase(TIGER, purchaseTigers.getUserInput());

  // menu for initial purchase of penguins
  Menu purchasePenguins("Would you like to purchase one or two penguins?");
  purchasePenguins.setLimits(1,2);
  purchasePenguins.outputMenu();

  // calls the function to create the penguin objects and add
  // them to the penguin array
  zoo.animal_purchase(PENGUIN, purchasePenguins.getUserInput());

  // menu for initial purchase of turtles
  Menu purchaseTurtles("Would you like to purchase one or two turtles?");
  purchaseTurtles.setLimits(1,2);
  purchaseTurtles.outputMenu();

  // calls the function to create the turtle objects and add
  // them to the turtle array
  zoo.animal_purchase(TURTLE, purchaseTurtles.getUserInput()); 

  // prompts the user for the number of days to play
  Menu daysOpen("How many days would you like to play?");
  daysOpen.setLimits(1, 365);
  daysOpen.outputMenu();

  // begins the game - runs in a while loop until the number of days open are equal to the
  // number of days the user entered to play or if the bank balance falls below 0
  while (zoo.get_number_of_days_open() < daysOpen.getUserInput() && zoo.get_bank_balance() > 0){
    
    // calls the function to pay for feeding the animals
    zoo.pay_feed_cost();

    // calls the random event function
    zoo.random_event();

    // calls the end of the day function
    zoo.end_of_day();

    // menu for purchasing a new animal - first prompts if the user wants to buy one
    Menu purchaseNewAnimal("Would you like to purchase an adult animal?");
    purchaseNewAnimal.addOptions("Yes");
    purchaseNewAnimal.addOptions("No");
    purchaseNewAnimal.outputMenu();

    // if the user wants to buy a new animal, then it prompts the user for what kind
    // they would like to purchase
    if (purchaseNewAnimal.getUserInput() == 1){

      Menu typeOfNewAnimal("What kind of animal would you like to purchase?");
      typeOfNewAnimal.addOptions("Tiger");
      typeOfNewAnimal.addOptions("Penguin");
      typeOfNewAnimal.addOptions("Turtle");
      typeOfNewAnimal.outputMenu();

      // then creates the new animal based on the uesr input
      if (typeOfNewAnimal.getUserInput() == 1){
        zoo.animal_purchase(TIGER, 1);
      }
      else if (typeOfNewAnimal.getUserInput() == 2){
        zoo.animal_purchase(PENGUIN, 1);
      }
      else {
        zoo.animal_purchase(TURTLE, 1);
      }
    } 
  }

  // displays a game over message including the ending balance and
  // number of days played
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "GAME OVER" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "Thanks for playing! You were open for " << zoo.get_number_of_days_open() << " days!" << std::endl;
  std::cout << "Ending Balance: $" << zoo.get_bank_balance() << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  
  }
 
  return 0;
}
