#include <iostream>
#include <vector>

int main() {
  int k;
  int x;
  int y;
  int maxX;
  int maxY;
  int minX;
  int minY;

  std::cin >> k;

  std::cin >> x >> y;
  maxX = minX = x;
  maxY = minY = y;
  for (int kI = 1; kI < k; ++kI) {
    std::cin >> x >> y;

    if (x > maxX) {
      maxX = x;
    } else if (x < minX) {
      minX = x;
    }

    if (y > maxY) {
      maxY = y;
    } else if (y < minY) {
      minY = y;
    }
  }


  std::cout << minX << " " << minY << " " << maxX <<" " << maxY << std::endl;
  return 0;
}
