#include "palindrome.hpp"

#include <string>
#include <iostream>

int main(){

  // stores user entered string
  std::string input;

  // get user input for string
  std::cout << "Input a string: " << std::endl;
  std::cin >> input;

  palindrome(input);

  return 0;
}
