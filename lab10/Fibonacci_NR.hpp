/*************************************************************
** Program name: Lab 10
** Author: Alex Maslar
** Date: June 09 2019
** Description: Header file of the non-recursive Fibonacci
   sequence. Rather than recursion, this function uses a while
   with a counter that continues adding the last two values
   in the sequence until the counter reaches the number entered
   by the user.
*************************************************************/
#ifndef FIBONACCI_NR_HPP
#define FIBONACCI_NR_HPP

class Fibonacci_NR {
  private:
    int Fibonacci(const int &n);
    const int* n_;
  public:
    Fibonacci_NR();
    Fibonacci_NR(const int &n);
    virtual ~Fibonacci_NR();
    void PrintFibonacci();
};

#endif
