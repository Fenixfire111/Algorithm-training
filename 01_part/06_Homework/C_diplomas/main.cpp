#include <iostream>
#include <algorithm>

bool check(const long long& w, const long long& h, const long long& n,
           const long long& m) {

  return (m / w) * (m / h) >= n;
}

long long binarySearch(const long long& w, const long long& h, const long long& n) {
  long long m;
  long long l = 0;
  long long r = std::max(w, h) * n;

  while (l < r) {
    m = (l + r) / 2;
    if (check(w, h, n, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return l;
}

int main() {
  long long w;
  long long h;
  long long n;

  std::cin >> w >> h >> n;

  std::cout << binarySearch(w, h, n) << std::endl;

  return 0;
}
