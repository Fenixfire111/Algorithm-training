#include <iostream>
#include <set>

int main() {
  int m;
  int n;
  std::set<std::pair<int, int>> array;
  std::set<std::pair<int, int>> deleteSet;
  std::pair<int, int> temp;

  std::cin >> m;
  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> temp.first >> temp.second;
    for (auto os: array) {
      if (!(temp.first > os.second || temp.second < os.first)) {
        deleteSet.insert(os);
      }
    }

    for (auto os: deleteSet) {
      array.erase(os);
    }
    array.insert(temp);
  }

  std::cout << array.size() << std::endl;
  return 0;
}
