#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> set;
  int n;
  int x, y;

  std::cin >> n;

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x >> y;
    set.insert(x);
  }

  std::cout << set.size() << std::endl;

  return 0;
}
