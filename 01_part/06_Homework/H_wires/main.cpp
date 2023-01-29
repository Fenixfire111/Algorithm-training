#include <iostream>
#include <algorithm>
#include <vector>

bool check(const long long& k, const long long& maxLong,
           const std::vector<long long>& array, const long long& m)  {
  long long number = 0;

  for (long long kI : array) {
    number += kI / m;
  }
  return number >= k;
}

long long binarySearch(const long long& k, const long long& maxLong,
                       const std::vector<long long>& array) {
  long long m;
  long long l = 0;
  long long r = maxLong;

  while (l < r) {
    m = (l + r + 1) / 2;
    if (check(k, maxLong, array, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  return l;
}

int main() {
  long long n;
  long long k;
  long long maxLong = 0;

  std::cin >> n >> k;
  std::vector<long long> wires(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> wires[kI];
    if (maxLong < wires[kI]) {
      maxLong = wires[kI];
    }
  }
  std::cout << binarySearch(k, maxLong, wires) << std::endl;

  return 0;
}
