#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<long long> start(3);
  std::vector<long long> startAbs(3);
  long long x;
  long long min1;
  long long min2;
  long long max1;
  long long max2;
  long long max3;

  std::cin >> start[0];
  std::cin >> start[1];
  std::cin >> start[2];
  std::sort(start.begin(), start.end());
  min1 = max3 = start[0];
  min2 = max2 = start[1];
  max1 = start[2];

  while (std::cin >> x) {
    if (x > max1) {
      max3 = max2;
      max2 = max1;
      max1 = x;
    } else if (x > max2) {
      max3 = max2;
      max2 = x;
    } else if (x > max3) {
      max3 = x;
    }

    if (x < min1) {
      min2 = min1;
      min1 = x;
    } else if (x < min2) {
      min2 = x;
    }
  }

  if (max1 * max2 * max3 >= min1 * min2 * max1) {
    std::cout << max3 << " " << max2 << " " << max1 << std::endl;
  } else {
    std::cout << min2 << " " << min1 << " " << max1 << std::endl;
  }

  return 0;
}
