#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> sides(3);
  std::vector<int> hole(2);

  std::cin >> sides[0] >> sides[1] >> sides[2] >> hole[0] >> hole[1];

  std::sort(sides.begin(), sides.end());
  std::sort(hole.begin(), hole.end());

  if (hole[0] >= sides[0] && hole[1] >= sides[1]) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
