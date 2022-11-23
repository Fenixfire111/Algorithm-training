#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> set;
  int x;

  while (std::cin >> x) {
    set.insert(x);
  }

  std::cout << set.size() << std::endl;
  return 0;
}
