#include <iostream>
#include <map>

int main() {
  int n;
  int w;
  int h;
  long long result = 0;
  std::map<int, int> blocks;

  std::cin >> n;

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> w >> h;

    if (blocks[w] < h) {
      blocks[w] = h;
    }
  }

  for (auto block: blocks) {
    result += block.second;
  }

  std::cout << result << std::endl;
  return 0;
}
