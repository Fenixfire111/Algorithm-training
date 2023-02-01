#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

const int MAN_ENTERED = 1;
const int MAN_CAME_OUT = -1;

struct point {
  int x;
  int y;
  int event;

  bool operator< (point anotherPoint) const {
    if (x < anotherPoint.x) {
      return true;
    } else if (x == anotherPoint.x) {
      return event < anotherPoint.event;
    } else {
      return false;
    }
  }

  bool operator> (point anotherPoint) const {
    if (x > anotherPoint.x) {
      return true;
    } else if (x == anotherPoint.x) {
      return event > anotherPoint.event;
    } else {
      return false;
    }
  }

  bool operator== (point anotherPoint) const {
    return x == anotherPoint.x && y == anotherPoint.y &&
    event == anotherPoint.event;
  }

  bool operator!= (point anotherPoint) const {
    return x != anotherPoint.x || y != anotherPoint.y ||
        event != anotherPoint.event;
  }
};

int main() {
  int n;
  int x;
  int y;
  int maxX;
  int maxX2;
  std::set<point> currSet;
  std::set<point> maxSet;
  std::set<point> maxSet2;

  std::cin >> n;
  std::map<int, std::set<point>> values;
  std::vector<point> events(2 * n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x >> y;
    events[kI].x = x;
    events[kI].event = MAN_ENTERED;
    events[kI].y = y;

    events[kI + n].x = y;
    events[kI + n].event = MAN_CAME_OUT;
    events[kI + n].y = x;
  }

  std::sort(events.begin(), events.end());

  for (auto event: events) {
    if (event.event == MAN_ENTERED) {
      currSet.insert(event);

      for (auto point: currSet) {
        if (point.y - event.x >= 5) {
          values[event.x].insert(point);
        } else {
          currSet.erase(point);
        }

      }
    } else {
//      std::swap(event.x, event.y);
//      event.event = MAN_ENTERED;
//      currSet.erase(event);
    }
  }

  for (const auto& set: values) {
    if (set.second.size() > maxSet.size()) {
      maxSet = set.second;
      maxX = set.first;
      maxX2 = maxX + 10;
    }
  }

  for (auto& set: values) {
    for (const auto& point: maxSet) {
      if (set.second.count(point)) {
        set.second.erase(point);
      }
    }
  }

  for (const auto& set: values) {
    if (set.second.size() > maxSet2.size()) {
      maxSet2 = set.second;
      maxX2 = set.first;
    }
  }

  std::cout << maxSet.size() + maxSet2.size() << " " << maxX << " " << maxX2;
  return 0;
}
