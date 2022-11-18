#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> minArea(const std::vector<int> &maxLaptop, const std::vector<int> &minLaptop) {
  std::vector<int> result(2);

  if (maxLaptop[0] >= minLaptop[1]) {
    result[0] = maxLaptop[1] + minLaptop[0];
    result[1] = maxLaptop[0];
  } else {
    int a = (maxLaptop[1] + minLaptop[0]) * std::max(minLaptop[1], maxLaptop[0]);
    int b = std::max(maxLaptop[0], minLaptop[0]) * (minLaptop[1] + maxLaptop[1]);
    int c = std::max(maxLaptop[1], minLaptop[1]) * (minLaptop[0] + maxLaptop[0]);
    int d = (minLaptop[1] + maxLaptop[0]) * std::max(maxLaptop[1], minLaptop[0]);


    if (a <= b && a <= c && a <= d) {
      result[0] = maxLaptop[1] + minLaptop[0];
      result[1] = std::max(maxLaptop[0], minLaptop[1]);
    } else if (b <= a && b <= c && b <= d) {
      result[0] = maxLaptop[1] + minLaptop[1];
      result[1] = std::max(maxLaptop[0], minLaptop[0]);
    } else if (c <= a && c <= b && c <= d) {
      result[0] = maxLaptop[1];
      result[1] = maxLaptop[0] + minLaptop[0];
    } else {
      result[0] = maxLaptop[1];
      result[1] = maxLaptop[0] + minLaptop[1];
    }
  }

  return result;
}

int main() {
  std::vector<int> laptop1(2);
  std::vector<int> laptop2(2);

  std::vector<int> result(2);

  std::cin >> laptop1[0] >> laptop1[1];
  std::cin >> laptop2[0] >> laptop2[1];

  std::sort(laptop1.begin(), laptop1.end());
  std::sort(laptop2.begin(), laptop2.end());

  if (laptop1[1] >= laptop2[1]) {
   result = minArea(laptop1, laptop2);
  } else {
   result = minArea(laptop2, laptop1);
  }

  std::cout << result[0] << " " << result[1];

  return 0;
}
