#include "Fibonacci_NR.hpp"
#include "Fibonacci_R.hpp"
#include "Menu.hpp"

#include <iostream>
#include <ctime>

int main(){
  clock_t t;

  Menu start_menu("What number in the sequence?");
  start_menu.outputMenu();

  int user_input = start_menu.getUserInput();

  // run in a loop to calculate the time
  t = clock();
  Fibonacci_NR non_recursive(user_input);
  non_recursive.PrintFibonacci();
  t = clock() - t;

  printf("Non-recursive execution time: %f seconds.\n",t,((double)t)/CLOCKS_PER_SEC);

  // run in a loop to calculate the time
  t = clock();
  Fibonacci_R recursive(user_input);
  recursive.PrintFibonacci();
  t = clock() - t;

  printf("Recursive execution time: %f seconds.\n",t,((double)t)/CLOCKS_PER_SEC);

  return 0;
}
