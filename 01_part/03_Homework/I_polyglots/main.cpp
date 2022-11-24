#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  std::unordered_set<std::string> set;
  std::unordered_set<std::string> extraSet;
  int n;
  int m;
  int maxIndex = 0;
  std::string temp;

  std::cin >> n;

  std::vector<std::unordered_set<std::string>> list(n, std::unordered_set<std::string>());
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> m;
    for (int kJ = 0; kJ < m; ++kJ) {
      std::cin >> temp;
      list[kI].insert(temp);
      set.insert(temp);
    }

    if (list[kI].size() > list[maxIndex].size()) {
      maxIndex = kI;
    }
  }

  for (std::string x: set) {
    for (int kI = 0; kI < n; ++kI) {
      if (!list[kI].count(x)) {
        extraSet.insert(x);
        break;
      }
    }
  }

  for (std::string x: extraSet) {
    if (set.count(x)) {
      set.erase(x);
    }
  }

  std::cout << set.size() << std::endl;
  for (std::string x: set) {
    std::cout << x << std::endl;
  }

  std::cout << list[maxIndex].size() << std::endl;
  for (std::string x: list[maxIndex]) {
    std::cout << x << std::endl;
  }
  return 0;
}
