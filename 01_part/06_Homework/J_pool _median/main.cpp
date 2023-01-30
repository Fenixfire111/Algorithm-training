#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  int l;

  std::cin >> n >> l;
  std::vector<std::vector<int>> matrix(n, std::vector<int> (l));
  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < l; ++kJ) {
      std::cin >> matrix[kI][kJ];
    }
  }

  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = kI + 1; kJ < n; ++kJ) {
      std::vector<int> temp(2 * l);
      for (int k = 0; k < l; ++k) {
        temp[k] = matrix[kI][k];
        temp[k + l] = matrix[kJ][k];
      }

      std::sort(temp.begin(), temp.end());
      std::cout << temp[l - 1] << std::endl;
    }
  }


  return 0;
}
