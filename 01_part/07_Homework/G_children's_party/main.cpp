#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  int m;
  int n;
  int t;
  int z;
  int y;
  int currCountBalls;
  int time;
  std::pair<int, int> temp;

  std::cin >> m >> n;
  std::vector<int> result(n);

  if (m == 0) {
    std::cout << 0 << std::endl;
    for (auto count: result) {
      std::cout << count << " ";
    }
    return 0;
  }

  std::vector<std::pair<int, int>> balls(n * m);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> t >> z >> y;
    currCountBalls = 0;
    time = 0;
    for (int kJ = 0; kJ < m; ++kJ) {
      if (currCountBalls < z) {
        ++currCountBalls;
        time += t;
      } else {
        currCountBalls = 1;
        time += (y + t);
      }

      temp.first = time;
      temp.second = kI;
      balls[kI * m + kJ] = temp;
    }
  }

  std::sort(balls.begin(), balls.end());

  for (int kI = 0; kI < m; ++kI) {
    ++result[balls[kI].second];
  }

  std::cout << balls[m - 1].first << std::endl;
  for (auto count: result) {
    std::cout << count << " ";
  }
  return 0;
}
