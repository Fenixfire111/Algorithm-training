#include <iostream>
#include <vector>

int main() {
  int indexMax;
  int number;
  int bestPlace = 1;
  int bestResult = -1;

  std::cin >> number;

  std::vector<int> array(number);
  for (int kI = 0; kI < number; ++kI) {
    std::cin >> array[kI];
  }

  indexMax = 0;
  for (int kI = 1; kI < number; ++kI) {
    if (array[kI] > array[indexMax]) {
      indexMax = kI;
    }
  }

  for (int kI = indexMax + 1; kI < number - 1; ++kI) {
    if (array[kI] % 10 == 5 && array[kI] > array[kI + 1] && array[kI] > bestResult) {
      bestResult = array[kI];
    }
  }

  if (bestResult == -1) {
    std::cout << 0 << std::endl;
  } else {
    for (int kI = 0; kI < number; ++kI) {
      if (array[kI] > bestResult) {
        ++bestPlace;
      }
    }
    std::cout << bestPlace << std::endl;
  }

  return 0;
}
