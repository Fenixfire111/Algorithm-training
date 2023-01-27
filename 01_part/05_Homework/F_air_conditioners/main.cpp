#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  int n;
  int m;
  int result = 0;
  int minPrice;
  int a;
  int b;
  std::map<int, int> conditioners;

  std::cin >> n;
  std::vector<int> rooms(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> rooms[kI];
  }

  std::cin >> m;

  for (int kI = 0; kI < m; ++kI) {
    std::cin >> a >> b;
    if (conditioners[a] > b || conditioners[a] == 0) {
      conditioners[a] = b;
    }
  }

  std::sort(rooms.begin(), rooms.end());

  for (int kI = 0; kI < n; ++kI) {
    minPrice = 1001;
    for (const auto& cond: conditioners) {
      if (rooms[kI] <= cond.first && minPrice > cond.second) {
        minPrice = cond.second;
      }
    }
    result += minPrice;
  }

  std::cout << result << std::endl;
  return 0;
}
