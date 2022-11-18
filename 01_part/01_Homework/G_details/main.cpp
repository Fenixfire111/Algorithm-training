#include <iostream>

int main() {
  int number;
  int kg;
  int detail;

  int remainder = 0;
  int result = 0;
  std::cin >> number >> kg >> detail;

  if (kg < detail) {
    std::cout << 0 << std::endl;
    return 0;
  }

  do {
    remainder = number % kg;
    number /= kg;
    result += number * (kg / detail);
    remainder += number * (kg % detail);
    number = remainder;
  } while (number / kg != 0);

  std::cout << result << std::endl;
  return 0;
}
