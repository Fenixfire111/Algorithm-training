#include <iostream>
#include <algorithm>
#include <cmath>

bool check(const long long& t, const long long& x,
           const long long& y, const long long& m)  {

  return x * 2 * m + (y - 2 * m) * 2 * m <= t;
}

long long binarySearch(const long long& t, const long long& x,
                       const long long& y) {
  long long m;
  long long l = 0;
  long long r = std::min(x, y) / 2;

  while (l < r) {
    m = (l + r + 1) / 2;
    if (check(t, x, y, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  return l;
}

int main() {
  long long x;
  long long y;
  long long t;

  std::cin >> x >> y;
  std::cin >> t;

  std::cout << binarySearch(t, x, y) << std::endl;

  return 0;
}
