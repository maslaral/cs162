#include "palindrome.hpp"

#include <string>
#include <iostream>

int main(){

  std::string input;

  std::cout << "Input a string: " << std::endl;
  std::cin >> input;

  palindrome(input);

  return 0;
}
