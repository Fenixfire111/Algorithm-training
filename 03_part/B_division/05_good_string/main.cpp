#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long long n;
  long long result = 0;
  long long min;
  int len;
  int first;

  std::cin >> n;
  std::vector<int > array(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> array[kI];
  }
  do {
    len = 0;
    min = -1;
    first = -1;
    for (int kI = 0; kI < array.size(); ++kI) {
      if (array[kI] > 0) {
        ++len;
        if (first == -1 || min > array[kI]) {
          min = array[kI];
        }
        if (first == -1) {
          first = kI;
        }
      } else if (len != 0) {
        if (len == 1) {
          len = 0;
          min = -1;
          first = -1;
        } else {
          result += (len - 1) * min;

          for (int kJ = first; kJ < kI; ++kJ) {
            array[kJ] -= min;
          }
          len = 0;
          min = -1;
          first = -1;
          kI = -1;
        }
      }
    }

    if (len == 1) {
      len = 0;
      min = -1;
      first = -1;
    } else if (len > 1) {
      result += (len - 1) * min;

      for (int kJ = first; kJ < array.size(); ++kJ) {
        array[kJ] -= min;
      }
    }
  } while (len > 1);


  std::cout << result << std::endl;
  return 0;
}
