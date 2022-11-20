#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int number;
  int x;
  int minDiff;
  int index;
  std::cin >> number;

  std::vector<int> array(number);
  for (int kI = 0; kI < number; ++kI) {
    std::cin >> array[kI];
  }

  std::cin >> x;

  minDiff = std::abs(x - array[0]);
  index = 0;
  for (int kI = 1; kI < number; ++kI) {
    if (minDiff > std::abs(x - array[kI])) {
      minDiff = std::abs(x - array[kI]);
      index = kI;
    }
  }

  std::cout << array[index] << std::endl;
  return 0;
}
