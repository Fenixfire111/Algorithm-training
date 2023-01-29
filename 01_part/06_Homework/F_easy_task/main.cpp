#include <iostream>
#include <algorithm>
#include <cmath>

bool check(const long long& n, const long long& x,
           const long long& y, const long long& m)  {

  return m / x + (m - x) / y >= n;
}

long long binarySearch(const long long& n, const long long& x,
                                const long long& y) {
  long long m;
  long long l = 1;
  long long r = n * std::max(x, y);

  while (l < r) {
    m = (l + r) / 2;
    if (check(n, x, y, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return l;
}

int main() {
  long long  n;
  long long x;
  long long y;
  long long temp;

  std::cin >> n >> x >> y;

  temp = std::min(x, y);
  y = std::max(x, y);
  x = temp;

  std::cout << binarySearch(n, x, y) << std::endl;

  return 0;
}
