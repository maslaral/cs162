/*************************************************************
** Program name: Lab 9
** Author: Alex Maslar
** Date: June 02 2019
** Description: Buffer function implementation that takes
   the number of rounds, add percent, and subtract percent from
   the user as arguments. It generates a random number for
   each round to potentially add to the buffer, and then 
   generates a random percent chance for adding and subtracting
   which are compared to the user provided percentages. If less
   than either, it will add/subtract from the buffer. After
   each round, print out the buffer values and the size of the
   buffer.
*************************************************************/
#include "buffer.hpp"

void buffer(){

  // create menus
  Menu rounds("How many rounds?");
  rounds.outputMenu();

  Menu add_percent("What percentage needed to add?");
  add_percent.outputMenu();

  Menu sub_percent("What percentage needed to subtract?");
  sub_percent.outputMenu();

  // initialize buffer and average length
  std::queue<int> buffer;
  double avg_length = 0;

  for (int i = 1; i <= rounds.getUserInput(); i++){
    // print out the round
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Round " << i << std::endl;      
    std::cout << "---------------------------------------------" << std::endl;

    // generate random numbers
    int N = rand() % 1000;
    int rand_add = rand() % 100;
    int rand_sub = rand() % 100;

    // if less than add percent, add to buffer
    if (rand_add <= add_percent.getUserInput()){
      buffer.push(N);
    }

    // if less than sub percent, remove from buffer 
    if (rand_sub <= sub_percent.getUserInput() && !buffer.empty()){
      buffer.pop();
    }

    // create a copy of the buffer to print
    std::queue<int> copy = buffer;

    // print out the buffer
    while (!copy.empty()){
      std::cout << copy.front() << std::endl;
      copy.pop();
    }

    // return the buffer size
    std::cout << "Buffer length: " << buffer.size() << std::endl;

    // average length calculation
    double len_numerator = avg_length * (i - 1) + buffer.size();
    
    if (len_numerator == 0){
      avg_length = 0;
    }
    else {
      avg_length = len_numerator / i;
    }

    // return the average length
    std::cout << "Average length: " << avg_length << std::endl;
    std::cout << std::endl;
  }
}
