#include <iostream>
#include <vector>
#include <algorithm>

struct point {
  int first;
  int second;
  int third = 0;

  bool operator< (const point& anotherPoint) const{
    if (first < anotherPoint.first) {
      return true;
    } else if (first == anotherPoint.first) {
      if (second < anotherPoint.second) {
        return true;
      } else if (second == anotherPoint.second) {
        return third < anotherPoint.third;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
};

int main() {
  int n;
  int m;
  int left;
  int right;
  int currCount = 0;

  std::cin >> n >> m;
  std::vector<int> result(m);
  std::vector<point> events(2 * n + m);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> left >> right;
    if (left > right) {
      std::swap(left, right);
    }
    events[kI].first = left;
    events[kI].second = -1;
    events[kI + n].first = right;
    events[kI + n].second = 1;
  }

  for (int kI = 0; kI < m; ++kI) {
    std::cin >> left;
    events[kI + 2 * n].first = left;
    events[kI + 2 * n].second = 0;
    events[kI + 2 * n].third = kI;
  }
  std::sort(events.begin(), events.end());

  for (auto event: events) {
    if (event.second == -1) {
      ++currCount;
    } else if (event.second == 0) {
      result[event.third] = currCount;
    } else {
      --currCount;
    }
  }

  for (int kI = 0; kI < m; ++kI) {
    std::cout << result[kI] << " ";
  }
  return 0;
}
