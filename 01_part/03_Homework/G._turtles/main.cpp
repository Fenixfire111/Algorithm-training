#include <iostream>
#include <set>

int main() {
  std::set<std::pair<int, int>> set;
  std::pair<int, int> temp;
  int n;

  std::cin >> n;

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> temp.first >> temp.second;
    if (temp.first + temp.second == n - 1 && temp.first >= 0 && temp.second >= 0) {
      set.insert(temp);
    }
  }

  std::cout << set.size() << std::endl;
  return 0;
}
