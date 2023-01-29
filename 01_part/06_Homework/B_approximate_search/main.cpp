#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool check(const long long& x, const std::vector<long long>& array,
           const int& m, const int& l, const int& r) {
  return (array[m] - x <= 0);

}

int binarySearch(int l, int r, const long long& x, const std::vector<long long>& array) {
  int m;

  if (array[l] - x >= 0 && array[r] - x >= 0) {
    return array[l];
  } else if (array[l] - x <= 0 && array[r] - x <= 0) {
    return array[r];
  } else {
    while (l < r) {
      m = (l + r + 1) / 2;
      if (check(x, array, m, l, r)) {
        l = m;
      } else {
        r = m;
      }

      if (r - l <= 1) {
        if (std::abs(array[l] - x) > std::abs(array[r] - x)) {
          l = m;
        } else {
          r = m - 1;
        }
      }
    }

    return array[l];
  }
}

int main() {
  int n;
  int k;

  std::cin >> n >>k;
  std::vector<long long> nArray(n);
  std::vector<long long> kArray(k);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> nArray[kI];
  }
  for (int kI = 0; kI < k; ++kI) {
    std::cin >> kArray[kI];
  }

  std::sort(nArray.begin(), nArray.end());

  for (int kI = 0; kI < k; ++kI) {
    std::cout << binarySearch(0, nArray.size() - 1, kArray[kI], nArray) << std::endl;
  }

  return 0;
}
