#include <iostream>
#include <algorithm>
#include <cmath>

bool check(const long double& a, const long double& b, const long double& c,
           const unsigned long long& m)  {
  auto fM = (long double)m;
  return ((2 * a + 3 * b + 4 * c + fM * 5) ) >= 3.5 * (a + b + c + fM);
}

unsigned long long binarySearch(const long double& a, const long double& b,
                                const long double& c) {
  unsigned long long m;
  unsigned long long l = 0;
  auto r = (unsigned long long)(a + b + c);

  while (l < r) {
    m = (l + r) / 2;
    if (check(a, b, c, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return l;
}

int main() {
  long double a;
  long double b;
  long double c;

  std::cin >> a >> b >> c;

  std::cout << binarySearch(a, b, c) << std::endl;

  return 0;
}
