#include <iostream>

int main() {
  int x1, x , x2;
  int number = 0;

  std::cin >> x1;
  std::cin >> x;
  while (std::cin >> x2) {
    if (x > x1 && x > x2) {
      ++number;
    }
    x1 = x;
    x = x2;
  }
  std::cout << number << std::endl;
  return 0;
}
