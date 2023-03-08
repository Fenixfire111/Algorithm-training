#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

const int BIRTHDAY = 1;
const int DAY_OF_DEATH = -1;

struct point {
  int year;
  int month;
  int day;
  int event;
  int number;

  bool operator< (point anotherPoint) const {
    if (year < anotherPoint.year) {
      return true;
    } else if (year == anotherPoint.year) {
      if (month < anotherPoint.month) {
        return true;
      } else if (month == anotherPoint.month) {
        if (day < anotherPoint.day) {
          return true;
        } else if (day == anotherPoint.day) {
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
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

};

void addEvents(point& temp1, point& temp2, std::vector<point>& events, const int& kI) {
  temp1.event = BIRTHDAY;
  temp1.number = kI + 1;
  events.push_back(temp1);

  temp2.event = DAY_OF_DEATH;
  temp2.number = kI + 1;
  events.push_back(temp2);
}

void pension(const point& temp1, point& temp2) {
  temp2.year = temp1.year + 80;
  temp2.month = temp1.month;
  temp2.day = temp1.day;
}

int main() {
  int n;
  std::set<int> currPeople;
  bool newMan = false;
  point temp1{};
  point temp2{};

  std::cin >> n;
  std::vector<point> events;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> temp1.day >> temp1.month >> temp1.year;
    std::cin >> temp2.day >> temp2.month >> temp2.year;

    if (temp2.year - temp1.year > 80) {
      pension(temp1, temp2);
    } else if (temp2.year - temp1.year == 80) {
      if (temp1.month < temp2.month) {
        pension(temp1, temp2);
      } else if (temp1.month == temp2.month) {
        if (temp1.day < temp2.day) {
          pension(temp1, temp2);
        }
      }
    }
    temp1.year += 18;

    if (temp1.year < temp2.year) {
      addEvents(temp1, temp2, events, kI);
    } else if (temp1.year == temp2.year) {
      if (temp1.month < temp2.month) {
        addEvents(temp1, temp2, events, kI);
      } else if (temp1.month == temp2.month) {
        if (temp1.day < temp2.day) {
          addEvents(temp1, temp2, events, kI);
        }
      }
    }
  }

  std::sort(events.begin(), events.end());

  for (auto event: events) {
    if (event.event == BIRTHDAY) {
      currPeople.insert(event.number);
      newMan = true;
    } else {
      if (newMan) {
        for (auto man: currPeople) {
          std::cout << man << " ";
        }
        std::cout << std::endl;
      }

      currPeople.erase(event.number);
      newMan = false;
    }
  }

  if (events.empty()) {
    std::cout << 0;
  }
  return 0;
}
