#include <iostream>
#include <set>
#include <vector>

int main() {
  std::set<std::string> set;
  std::set<std::string> setAll;
  std::set<std::string> extraSet;
  int n;
  int m;
  std::string temp;

  std::cin >> n;

  std::vector<std::set<std::string>> list(n, std::set<std::string>());
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> m;

    for (int kJ = 0; kJ < m; ++kJ) {
      std::cin >> temp;
      list[kI].insert(temp);
      set.insert(temp);
    }
  }

  for (const std::string& x: set) {
    for (int kI = 0; kI < n; ++kI) {
      if (!list[kI].count(x)) {
        extraSet.insert(x);
        break;
      }
    }
  }

  setAll = set;

  for (const auto& x: extraSet) {
    if (set.count(x)) {
      set.erase(x);
    }
  }

  std::cout << set.size() << std::endl;
  for (const std::string& x: set) {
    std::cout << x << std::endl;
  }

  std::cout << setAll.size() << std::endl;
  for (const std::string& x: setAll) {
    std::cout << x << std::endl;
  }
  return 0;
}
