#include <iostream>

int main() {
  bool constant = true;
  bool ascending = true;
  bool weaklyAscending = true;
  bool descending = true;
  bool weaklyDescending = true;

  int number1;
  int number2;

  std::cin >> number1;
  std::cin >> number2;
  while (number2 != -2000000000) {
    if (number2 == number1) {
      ascending = false;
      descending = false;
    } else if (number2 > number1) {
      descending = false;
      constant = false;
      weaklyDescending = false;
    } else {
      ascending = false;
      weaklyAscending = false;
      constant = false;
    }
    number1 = number2;
    std::cin >> number2;
  }

  if (ascending) {
    std::cout << "ASCENDING" << std::endl;
  } else if (descending) {
    std::cout << "DESCENDING" << std::endl;
  } else if (constant) {
    std::cout << "CONSTANT" << std::endl;
  } else if (weaklyAscending) {
    std::cout << "WEAKLY ASCENDING" << std::endl;
  } else if (weaklyDescending) {
    std::cout << "WEAKLY DESCENDING" << std::endl;
  } else {
    std::cout << "RANDOM" << std::endl;
  }

  return 0;
}
