#include <iostream>
#include <vector>

int main() {
  int n;
  int k;
  int key;

  std::cin >> n;

  std::vector<int> keyboard(n + 1);

  for (int kI = 1; kI <= n ; ++kI) {
    std::cin >> keyboard[kI];
  }

  std::cin >> k;

  for (int kI = 0; kI < k; ++kI) {
    std::cin >> key;
    --keyboard[key];
  }

  for (int kI = 1; kI <= n ; ++kI) {
    if (keyboard[kI] < 0) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
