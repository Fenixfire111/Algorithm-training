#include <iostream>
#include <algorithm>

bool check(const unsigned long long& n, const unsigned long long& a,
           const unsigned long long& b, const unsigned long long& w,
           const unsigned long long& h, const unsigned long long& m)  {

  return (w / (a + 2 * m)) * (h / (b + 2 * m)) >= n ||
      (w / (b + 2 * m)) * (h / (a + 2 * m)) >= n;
}

unsigned long long binarySearch(const unsigned long long& n, const unsigned long long& a,
                       const unsigned long long& b, const unsigned long long& w,
                       const unsigned long long& h) {
  unsigned long long m;
  unsigned long long l = 0;
  unsigned long long r = std::max(w, h);

  while (l < r) {
    m = (l + r + 1) / 2;
    if (check(n, a, b, w, h, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  return l;
}

int main() {
  unsigned long long a;
  unsigned long long b;
  unsigned long long w;
  unsigned long long h;
  unsigned long long n;

  std::cin >> n >> a >> b >> w >> h;

  std::cout << binarySearch(n, a, b, w, h) << std::endl;

  return 0;
}
