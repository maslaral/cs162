/*************************************************************
** Program name: Lab 10
** Author: Alex Maslar
** Date: June 09 2019
** Description: Implementation of the non-recursive Fibonacci
   sequence. Rather than recursion, this function uses a while
   with a counter that continues adding the last two values in the sequence until the counter reaches the number entered
   by the user.

   Source code adapted from: codeproject.com/tips/109443/fibonacci-
   recursive-and-non-recursive-c
*************************************************************/
#include "Fibonacci_NR.hpp"
#include <iostream>

/*************************************************************
** Description: Default constructor
*************************************************************/
Fibonacci_NR::Fibonacci_NR(){
}

/*************************************************************
** Description: Constructor given an argument of n
*************************************************************/
Fibonacci_NR::Fibonacci_NR(const int &n):n_(&n){
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
Fibonacci_NR::~Fibonacci_NR(){
}

/*************************************************************
** Description: Function calculates the last two numbers by
   using a while loop that continues until it reaches the
   number in the sequence. If n is 0, just return 0. Otherwise,
   add together those two numbers and return the result.
*************************************************************/
int Fibonacci_NR::Fibonacci(const int &n){
  // initialize first values of sequence and counter
  int first = 0;
  int second = 1;
  int counter = 2;

  for(int i = 0; i < 100; i++){
    while (counter < n){
      int temp = second;
      second += first;
      first = temp;
      counter++;
    }
  }
  if (n == 0){
    return 0;
  }
  else {
    return first + second;
  }
}

/*************************************************************
** Description: Prints the Fibonacci number
*************************************************************/
void Fibonacci_NR::PrintFibonacci(){
  const int result = Fibonacci(*n_);
  std::cout << *n_ << "th Fibonacci Number (non-recursive): " << result << std::endl;
}
