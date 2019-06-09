/*************************************************************
** Program name: Lab 10
** Author: Alex Maslar
** Date: June 09 2019
** Description: Header file of the recursive Fibonacci
   sequence. This function calls itself to find the last two
   values in the Fibonacci sequence and then adds them together.
   The class includes a function to print the result of the
   sequence.
*************************************************************/
#ifndef FIBONACCI_R_HPP
#define FIBONACCI_R_HPP

class Fibonacci_R {
  private:
    int Fibonacci(const int &n);
    const int* n_;
  public:
    Fibonacci_R();
    Fibonacci_R(const int &n);
    virtual ~Fibonacci_R();
    void PrintFibonacci();
};

#endif
