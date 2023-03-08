#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

struct point {
  int time;
  int event;
  int number;

  bool operator< (point anotherPoint) const {
    if (time < anotherPoint.time) {
      return true;
    } else if (time == anotherPoint.time) {
      if (event < anotherPoint.event) {
        return true;
      } else if (event == anotherPoint.event) {
        return number < anotherPoint.number;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

};

const int CASH_DESK_OPENED = -1;
const int CASH_DESK_CLOSED = 1;

int main() {
  int n;
  int startFull = -1;
  int result = 0;
  int hours1;
  int minutes1;
  int hours2;
  int minutes2;
  std::set<int> currChekDesk;
  point temp{};

  std::cin >> n;
  std::vector<point> events;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> hours1 >> minutes1;
    std::cin >> hours2 >> minutes2;
    if (hours1 == hours2 && minutes1 == minutes2) {
      currChekDesk.insert(kI);
    } else {
      temp.time = 60 * hours1 + minutes1;
      temp.event = CASH_DESK_OPENED;
      temp.number = kI;
      events.push_back(temp);
      temp.time = 60 * hours2 + minutes2;
      temp.event = CASH_DESK_CLOSED;
      temp.number = kI;
      events.push_back(temp);
    }
  }

  std::sort(events.begin(), events.end());

  for (auto event: events) {
    if (event.event == CASH_DESK_OPENED) {
      currChekDesk.insert(event.number);
    } else {
      currChekDesk.erase(event.number);
    }
  }

  if (currChekDesk.size() == n) {
    startFull = 0;
  }
  for (auto event: events) {
    if (event.event == CASH_DESK_OPENED) {
      currChekDesk.insert(event.number);
      if (currChekDesk.size() == n) {
        startFull = event.time;
      }
    } else {
      currChekDesk.erase(event.number);
      if (startFull != -1) {
        result += (event.time - startFull);
        startFull = -1;
      }
    }
  }
  if (startFull != -1) {
    result += (24 * 60 - startFull);
    startFull = -1;
  }

  std::cout << result << std::endl;
  return 0;
}
