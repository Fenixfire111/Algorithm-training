#include <iostream>
#include <set>
#include <algorithm>

int main() {
  std::set<int> arr;
  int n;

  std::cin >> n;
  while (n != 0) {
    arr.insert(n);
    std::cin >> n;
  }

  for (auto el: arr) {
    std::cout << el << std::endl;
  }

  return 0;
}
