#include <iostream>
#include <vector>

int main() {
  int number;
  bool symSeq = true;
  std::cin >> number;

  std::vector<int> array(number);

  for (int kI = 0; kI < number; ++kI) {
    std::cin >> array[kI];
  }

  for (int kI = 0; kI < number; ++kI) {
    for (int kJ = 0; kJ + kI < number - kJ - 1; ++kJ) {
      if (array[kI + kJ] != array[number - kJ - 1]) {
        symSeq = false;
        break;
      }
    }

    if (symSeq) {
      std::cout << kI << std::endl;
      for (int kJ = 0; kJ < kI; ++kJ) {
        std::cout << array[kI - kJ - 1] << " ";
      }
      break;
    } else {
      symSeq = true;
    }
  }

  return 0;
}
