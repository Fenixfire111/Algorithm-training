#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  int m;
  int left;
  int right;
  int currCount = 0;
  int prevCount = 0;
  int result = 0;
  int lastStop = -1;

  std::cin >> n >> m;
  std::vector<std::pair<int, int>> events(2 * m);
  for (int kI = 0; kI < m; ++kI) {
    std::cin >> left >> right;
    events[kI].first = left;
    events[kI].second = -1;
    events[kI + m].first = right;
    events[kI + m].second = 1;
  }
  std::sort(events.begin(), events.end());

  for (auto event: events) {
    if (event.second == -1) {
      ++currCount;
    } else {
      --currCount;
    }

    if (currCount <= 1 && prevCount < 1) {
      result += event.first - lastStop - 1;
    }
    lastStop = event.first;
    prevCount = currCount;
  }
  if (currCount < 1) {
    result += n - lastStop - 1;
  }

  std::cout << result << std::endl;
  return 0;
}
