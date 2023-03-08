#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <random>
#include <ctime>
#include <cmath>

const int MAN_ENTERED = 1;
const int MAN_CAME_OUT = -1;

struct point {
  int x;
  int event;
  int y;
  int number;

  bool operator< (point anotherPoint) const {
    if (x < anotherPoint.x) {
      return true;
    } else if (x == anotherPoint.x) {
      if (event < anotherPoint.event) {
        return true;
      } else if (event == anotherPoint.event) {
        if (y < anotherPoint.y) {
          return true;
        } else if (y == anotherPoint.y) {
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
  }

};

int main() {
//  srand(time(nullptr));

  int n;
  int x;
  int y;
  int maxX = 1;
  int maxX2 = 100;
  std::set<point> currSet;
  std::set<point> maxSet;
  std::set<point> maxSet2;

  std::cin >> n;
//  for (int kI = 0; kI < 10; ++kI) {
//    n = rand() % 2000 + 1;
//    std::cout << n << std::endl;

    std::map<int, std::set<point>> values;
    std::vector<point> events(2 * n);
    //
    std::vector<int> vec(10000000);
    std::vector<std::pair<int, int>> vecP;
    //
    for (int kI = 0; kI < n; ++kI) {
//    srand(time(nullptr));
    std::cin >> x >> y;
//      x = rand() % 50;
//      y = x + rand() % 15 + 1;
      //
      if (y - x >= 5) {
        for (int kJ = x; kJ <= y - 5; ++kJ) {
          vec[kJ] += 1;
        }
        std::pair<int, int> t;
        t.first = x;
        t.second = y;
        vecP.push_back(t);
      }
      //
//      std::cout << x << " " << y << std::endl;
      //

      events[kI].x = x;
      events[kI].event = MAN_ENTERED;
      events[kI].y = y;
      events[kI].number = kI;

      events[kI + n].x = y;
      events[kI + n].event = MAN_CAME_OUT;
      events[kI + n].y = x;
      events[kI + n].number = kI;
    }

    std::sort(events.begin(), events.end());

    for (auto event: events) {
      if (event.event == MAN_ENTERED) {
        currSet.insert(event);

        for (auto point: currSet) {
          if (point.y - event.x >= 5) {
            values[event.x].insert(point);
          }
        }
      } else {
        std::swap(event.x, event.y);
        event.event = MAN_ENTERED;
        currSet.erase(event);
      }
    }

    for (const auto& set: values) {
      if (set.second.size() > maxSet.size()) {
        maxSet = set.second;
        maxX = set.first;
        maxX2 = maxX + 100;
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
      if (set.second.size() > maxSet2.size() && std::abs(set.first - maxX) >= 5) {
        maxSet2 = set.second;
        maxX2 = set.first;
      }
    }

    if (maxX > maxX2) {
      std::swap(maxX2, maxX);
    }

    //
    int MAX1 = 0;
    int IND1 = 1;
    int MAX2 = 0;
    int IND2 = 100;
    for (int kI = 0; kI < vec.size(); ++kI) {
      if (MAX1 < vec[kI]) {
        MAX1 = vec[kI];
        IND1 = kI;
        IND2 = kI + 100;
      }
    }

    for (int kI = 0; kI < vecP.size(); ++kI) {
      if (vecP[kI].first <= IND1 && vecP[kI].second >= IND1 + 5) {
        for (int kJ = vecP[kI].first; kJ <= vecP[kI].second - 5; ++kJ) {
          vec[kJ] -= 1;
        }
        vecP[kI].first = -1;
        vecP[kI].second = -1;
      }
    }

    for (int kI = 0; kI < vec.size(); ++kI) {
      if (MAX2 < vec[kI] && std::abs(IND1 - kI) >= 5) {
        MAX2 = vec[kI];
        IND2 = kI;
      }
    }

    if (IND1 > IND2) {
      std::swap(IND1, IND2);
    }

//    if (MAX2 + MAX1 != maxSet.size() + maxSet2.size() || IND1 != maxX || maxX2 != IND2) {
//      std::cout << " PIIIIIIIIIIIIIIIIIIZZZZZZZZZZZDDDDDDDDDDDAAAAAAAAAAAAAAAAAAA!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
//      std::cout << maxSet.size() + maxSet2.size() << " " << maxX << " " << maxX2 <<std::endl;
//      std::cout << MAX2 + MAX1 << " " << IND1 << " " << IND2 <<std::endl;
//      std::cout << kI <<" tochki "<< vecP.size()<< std::endl;
//      break;
//    } else {
//      std::cout << "ok" << std::endl;
//      std::cout << maxSet.size() + maxSet2.size() << " " << maxX << " " << maxX2 <<std::endl;;
//      std::cout << MAX2 + MAX1 << " " << IND1 << " " << IND2 <<std::endl;
//    }
    //
//  }

  std::cout << MAX2 + MAX1 << " " << IND1 << " " << IND2 <<std::endl;

//  std::cout << maxSet.size() + maxSet2.size() << " " << maxX << " " << maxX2;
  return 0;
}