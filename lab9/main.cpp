#include "palindrome.hpp"
#include "buffer.hpp"

#include <string>
#include <iostream>
#include "Menu.hpp"

int main(){
  srand(time(NULL)); // seed rand num

  Menu start("What do you want to do?");
  start.addOptions("Test the buffer");
  start.addOptions("Create a palindrome");
  start.addOptions("Exit the program");

  while (start.getUserInput() != 3){
    start.outputMenu();

    switch (start.getUserInput()){
      case 1:
        buffer();
        break;
      case 2:
        palindrome();
        break;
    }

  }
  return 0;

}
