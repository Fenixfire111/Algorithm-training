#include <iostream>
#include <set>
#include <cmath>

std::set<std::pair<int, int>> getNewDet(const std::set<std::pair<int, int>> &setLast,
                                        const int &t, const int &d, const int &x, const int &y) {
  std::pair<int, int> temp;
  std::set<std::pair<int, int>> setNew;
  int maxX = -100000;

  for (auto dot: setLast) {
    for (int kJ = t; kJ >= 0; --kJ) {
      temp.first = dot.first + kJ;
      temp.second = dot.second + (t - kJ);
      if (std::abs(temp.first - x) + std::abs(temp.second - y) <= d) {
        if (maxX < temp.first) {
          maxX = temp.first;
        }
        setNew.insert(temp);
      }
      temp.first = dot.first - kJ;
      temp.second = dot.second + (t - kJ);
      if (std::abs(temp.first - x) + std::abs(temp.second - y) <= d) {
        setNew.insert(temp);
      }
      temp.first = dot.first + kJ;
      temp.second = dot.second - (t - kJ);
      if (std::abs(temp.first - x) + std::abs(temp.second - y) <= d) {
        if (maxX < temp.first) {
          maxX = temp.first;
        }
        setNew.insert(temp);
      }
      temp.first = dot.first - kJ;
      temp.second = dot.second - (t - kJ);
      if (std::abs(temp.first - x) + std::abs(temp.second - y) <= d) {
        setNew.insert(temp);
      }
    }

    for (int kJ = d; kJ >= 0; --kJ) {
      temp.first = x + kJ;
      temp.second = y + (d - kJ);
      if (std::abs(temp.first - dot.first) + std::abs(temp.second - dot.second) <= t) {
        if (maxX < temp.first) {
          maxX = temp.first;
        }
        setNew.insert(temp);
      }
      temp.first = x - kJ;
      temp.second = y + (d - kJ);
      if (std::abs(temp.first - dot.first) + std::abs(temp.second - dot.second) <= t) {
        setNew.insert(temp);
      }
      temp.first = x + kJ;
      temp.second = y - (d - kJ);
      if (std::abs(temp.first - dot.first) + std::abs(temp.second - dot.second) <= t) {
        if (maxX < temp.first) {
          maxX = temp.first;
        }
        setNew.insert(temp);
      }
      temp.first = x - kJ;
      temp.second = y - (d - kJ);
      if (std::abs(temp.first - dot.first) + std::abs(temp.second - dot.second) <= t) {
        setNew.insert(temp);
      }
    }
  }
  bool firstDot = true;
  bool secondDot = false;
  int left;
  int right = maxX;

  for (auto dot: setNew) {
    if (firstDot) {
      firstDot = false;
      left = dot.first;
    } else {
      if (temp.first == dot.first) {
        if (!secondDot) {
          secondDot = true;
        } else {
          if (left != temp.first && right != temp.first) {
            setNew.erase(temp);
          }
        }
      } else {
        secondDot = false;
      }
    }

    temp = dot;
  }

  return setNew;
}
int main() {
  int t;
  int d;
  int n;
  int x, y;
  std::set<std::pair<int, int>> setLast;

  std::cin >> t >> d >> n;

  std::pair<int, int> temp(0,0);
  setLast.insert(temp);

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x >> y;
    setLast = getNewDet(setLast, t, d, x, y);
  }

  bool firstDot = true;
  std::pair<int, int> innerPoint;

  for (auto dot: setLast) {
    if (firstDot) {
      temp = dot;
      firstDot = false;
    } else {
      if (temp.first == dot.first) {
        for (int kI = temp.second + 1; kI <= dot.second; ++kI) {
          innerPoint.first = temp.first;
          innerPoint.second = kI;
          setLast.insert(innerPoint);
        }
      }

      temp = dot;
    }
  }

  std::cout << setLast.size()<< std::endl;
  for (auto dot: setLast) {
    std::cout << dot.first << " " << dot.second << std::endl;
  }

  return 0;
}
