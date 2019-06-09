/*************************************************************
** Program name: Lab 10 ** Author: Alex Maslar
** Date: June 09 2019
** Description: Implementation file of the recursive Fibonacci
   sequence. This function calls itself to find the last two
   values in the Fibonacci sequence and then adds them together.
   The class includes a function to print the result of the
   sequence.

   Source code adapted from: codeproject.com/tips/109443/fibonacci-
   recursive-and-non-recursive-c
*************************************************************/
#include "Fibonacci_R.hpp"
#include <iostream>

/*************************************************************
** Description: Default constructor
*************************************************************/
Fibonacci_R::Fibonacci_R(){
}

/*************************************************************
** Description: Constructor with the user entered value as 
   the argument
*************************************************************/
Fibonacci_R::Fibonacci_R(const int &n):n_(&n){
}

/*************************************************************
** Description: Virtual destructor
*************************************************************/
Fibonacci_R::~Fibonacci_R(){
}

/*************************************************************
** Description: Calculates the Fibonacci number by recursively
   calling itself to get the two last values and adds them
   together.
*************************************************************/
int Fibonacci_R::Fibonacci(const int &n){
  int num;

  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }

  for (int i = 0; i < 100; i++){
    num = Fibonacci(n - 1) + Fibonacci(n - 2);
    return num;
  }
}

/*************************************************************
** Description: Prints the Fibonacci number
*************************************************************/
void Fibonacci_R::PrintFibonacci(){
  const int result = Fibonacci(*n_);
  std::cout << *n_ << "th Fibonacci Number (recursive): " << result << std::endl;
}
