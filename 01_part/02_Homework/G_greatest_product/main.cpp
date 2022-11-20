#include <iostream>
#include <algorithm>

int main() {
  long long x1;
  long long x2;
  long long min1;
  long long min2;
  long long max1;
  long long max2;

  std::cin >> x1;
  std::cin >> x2;
  max1 = min2 = std::max(x1, x2);
  min1 = max2 = std::min(x1, x2);
  while (std::cin >> x2) {
    if (x2 > max1) {
      max2 = max1;
      max1 = x2;
    } else if (x2 > max2) {
      max2 = x2;
    }

    if (x2 < min1) {
      min2 = min1;
      min1 = x2;
    } else if (x2 < min2) {
      min2 = x2;
    }
  }

  if (max1 * max2 >= min1 * min2) {
    std::cout << max2 << " " << max1 << std::endl;
  } else {
    std::cout << min1 << " " << min2 << std::endl;
  }

  return 0;
}
