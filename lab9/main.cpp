/*************************************************************
** Program name: Lab 9
** Author: Alex Maslar
** Date: June 02 2019
** Description: Main function that coordinates the program. 
   Includes creating a menu to ask the user if they want to
   test the buffer or to create a buffer - then calls the
   function.
*************************************************************/
#include "palindrome.hpp"
#include "buffer.hpp"

#include <string>
#include <iostream>
#include "Menu.hpp"

int main(){
  srand(time(NULL)); // seed rand number

  // initialize start menu objects
  Menu start("What do you want to do?");
  start.addOptions("Test the buffer");
  start.addOptions("Create a palindrome");
  start.addOptions("Exit the program");

  // reprompt the user until they exit
  while (start.getUserInput() != 3){
    start.outputMenu(); // output the menu

    switch (start.getUserInput()){
      case 1:           // test the buffer
        buffer();
        break;
      case 2:           // create a palindrome
        palindrome();
        break;
    }
  }
  return 0;
}
