#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

const int GUARD_CAME = -1;
const int  GUARD_IS_GONE = 1;

struct point {
  int time;
  int type;
  int number;
  int endTime;

  bool operator< (point anotherPoint) const {
    if (time < anotherPoint.time) {
      return true;
    } else if (time == anotherPoint.time) {
      if (type < anotherPoint.type) {
        return true;
      } else if (type == anotherPoint.type) {
        return number < anotherPoint.number;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

};

int main() {
  int k;
  int n;
  int a;
  int b;
  bool flag = true;
  point temp{};

  std::cin >> k;
  for (int kI = 0; kI < k; ++kI) {
    flag = true;
    std::cin >> n;
    std::set<point> set;
    std::vector<bool> result(n);
    std::vector<point> events;
    for (int kJ = 0; kJ < n; ++kJ) {
      std::cin >> a >> b;

      if (a < b) {
        temp.time = a + 1;
        temp.type = GUARD_CAME;
        temp.number = kJ;
        temp.endTime = b;
        events.push_back(temp);

        temp.time = b;
        temp.type = GUARD_IS_GONE;
        temp.endTime = a + 1;
        events.push_back(temp);
      } else {
        flag = false;
      }
    }

    std::sort(events.begin(), events.end());

    if (events[0].time != 1 || events[events.size() - 1].time != 10000) {
      flag = false;
    }

    for (int kJ = 0; kJ < events.size(); ++kJ) {
      if (events[kJ].type == GUARD_CAME) {
        set.insert(events[kJ]);
      } else {
        temp = events[kJ];
        temp.type = GUARD_CAME;
        std::swap(temp.time, temp.endTime);
        set.erase(temp);
      }


      if (set.size() == 1) {
        for (auto one: set) {
          if (kJ + 1 == events.size()) {
            result[one.number] = true;
          } else if (!(events[kJ + 1].time == events[kJ].time && events[kJ].type == GUARD_CAME &&
          events[kJ + 1].type == GUARD_CAME) &&
              !(events[kJ + 1].time == events[kJ].time + 1 && events[kJ].type == GUARD_IS_GONE &&
                  events[kJ + 1].type == GUARD_CAME)) {

            result[one.number] = true;
          } else if (events[kJ + 1].type != GUARD_CAME &&
          events[kJ + 1].type != events[kJ].type) {
            result[one.number] = true;
          }
        }
      } else if (set.empty() && kJ + 1 != events.size()) {
        if (events[kJ + 1].time != events[kJ].time + 1) {
          flag = false;
        }
      }

    }

    if (flag) {
      for (auto && kJ : result) {
        if (!kJ) {
          flag = false;
        }
      }
      if (flag) {
        std::cout << "Accepted" << std::endl;
      } else {
        std::cout << "Wrong Answer" << std::endl;
      }
    } else {
      std::cout << "Wrong Answer" << std::endl;
    }

  }
  return 0;
}
