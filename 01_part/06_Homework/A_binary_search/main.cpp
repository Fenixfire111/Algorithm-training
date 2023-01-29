#include <iostream>
#include <vector>
#include <algorithm>

bool check(const int& x, const std::vector<int>& array, const int& m) {
  return array[m] <= x;
}

int binarySearch(int l, int r, const int& x, const std::vector<int>& array) {
  int m;

  while (l < r) {
    m = (l + r + 1) / 2;
    if (check(x, array, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  return array[l];
}

int main() {
  int n;
  int k;

  std::cin >> n >>k;
  std::vector<int> nArray(n);
  std::vector<int> kArray(k);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> nArray[kI];
  }
  for (int kI = 0; kI < k; ++kI) {
    std::cin >> kArray[kI];
  }

  std::sort(nArray.begin(), nArray.end());

  for (int kI = 0; kI < k; ++kI) {
    if (kArray[kI] == binarySearch(0, nArray.size() - 1, kArray[kI], nArray)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
