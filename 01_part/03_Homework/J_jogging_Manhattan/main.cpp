#include <iostream>
#include <set>
#include <cmath>
#include <random>
#include <time.h>

std::set<std::pair<int, int>> getNewDet(const std::set<std::pair<int, int>> &setLast,
                                        const int &t, const int &d, const int &x, const int &y) {
  std::pair<int, int> temp;
  std::set<std::pair<int, int>> setNew;

  for (auto dot: setLast) {
    for (int kJ = t; kJ >= 0; --kJ) {
      temp.first = dot.first + kJ;
      temp.second = dot.second + (t - kJ);
      if (std::abs(temp.first - x) + std::abs(temp.second - y) <= d) {
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

    for (auto dot: setNew) {
      if (firstDot) {
        firstDot = false;
      } else {
        if (temp.first == dot.first) {
          if (!secondDot) {
            secondDot = true;
          } else {
            setNew.erase(temp);
          }
        } else {
          secondDot = false;
        }
      }

      temp = dot;
    }

  return setNew;
}

std::set<std::pair<int, int>> getNewDetA(const std::set<std::pair<int, int>> &setLast,
                                        const int &t, const int &d, const int &x, const int &y) {
  std::pair<int, int> temp;
  std::set<std::pair<int, int>> setNew;

  for (auto dot: setLast) {
    for (int kJ = t; kJ >= 0; --kJ) {
      temp.first = dot.first + kJ;
      temp.second = dot.second + (t - kJ);
      if (std::abs(temp.first - x) + std::abs(temp.second - y) <= d) {
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
        setNew.insert(temp);
      }
      temp.first = x - kJ;
      temp.second = y - (d - kJ);
      if (std::abs(temp.first - dot.first) + std::abs(temp.second - dot.second) <= t) {
        setNew.insert(temp);
      }
    }
  }

  return setNew;
}

std::set<std::pair<int, int>> slowly(  int t,
int d,
int n,
std::vector<std::pair<int, int>> vec) {

  std::set<std::pair<int, int>> setLast;

//  std::cin >> t >> d >> n;

  std::pair<int, int> temp(0,0);
  setLast.insert(temp);

  for (int kI = 0; kI < n; ++kI) {
//    int x = rand() % 100;
//    int y = rand() % 100;
//    std::cout << x<< " " << y << std::endl;
//    std::cin >> x >> y;
    setLast = getNewDetA(setLast, t, d, vec[kI].first, vec[kI].second);
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

  return setLast;
}

std::set<std::pair<int, int>> quickly(  int t,
int d,
int n,
std::vector<std::pair<int, int>> vec) {

  std::set<std::pair<int, int>> setLast;

//  std::cin >> t >> d >> n;

  std::pair<int, int> temp(0,0);
  setLast.insert(temp);

  for (int kI = 0; kI < n; ++kI) {
//    int x = rand() % 100;
//    int y = rand() % 100;
//    std::cout << x<< " " << y << std::endl;
//    std::cin >> x >> y;
    setLast = getNewDet(setLast, t, d, vec[kI].first, vec[kI].second);
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

  return setLast;
}

int main() {
//  int t;
//  int d;
//  int n;
//  int x, y;
//  std::set<std::pair<int, int>> setLast;
//
//  std::cin >> t >> d >> n;
//
//  std::pair<int, int> temp(0,0);
//  setLast.insert(temp);
//
//  for (int kI = 0; kI < n; ++kI) {
//    std::cin >> x >> y;
//    setLast = getNewDet(setLast, t, d, x, y);
//    }
//
//  bool firstDot = true;
//  std::pair<int, int> innerPoint;
//
//  for (auto dot: setLast) {
//    if (firstDot) {
//      temp = dot;
//      firstDot = false;
//    } else {
//      if (temp.first == dot.first) {
//        for (int kI = temp.second + 1; kI <= dot.second; ++kI) {
//          innerPoint.first = temp.first;
//          innerPoint.second = kI;
//          setLast.insert(innerPoint);
//        }
//      }
//
//      temp = dot;
//    }
//  }



  for (int kI = 1; kI < 100; ++kI) {
    for (int kJ = 1; kJ < 100; ++kJ) {
      for (int k = 1; k <=1;  ++k) {
       
        #include <ctime>
        srand(time( 0 ) );

//        std::cin >> kI >> kJ >> k;

        std::vector<std::pair<int, int>> vec(k);
        for (int kL = 0; kL < k; ++kL) {
          int x = rand() % 200 - 100;
          int y = rand() % 200 - 100;
          std::pair<int, int> t(x,y);

//          std::cin >> t.first >> t.second;

          vec[kL] = t;
        }
        std::set<std::pair<int, int>> A = slowly(kI, kJ, k, vec);
        std::set<std::pair<int, int>> B = quickly(kI, kJ, k, vec);
        if (A != B) {
          std::cout << " Errr " << kI <<" "<< kJ <<" "<< k << std::endl;
          for (int kL = 0; kL < vec.size(); ++kL) {
            std::cout << vec[kJ].first <<" "<< vec[kL].second<< std::endl;
          }
          std::cout << std::endl;
          std::cout << A.size()<< std::endl;
          for (auto x: A) {
            std::cout << x.first << " " << x.second << std::endl;
          }

          std::cout << std::endl;
          std::cout << B.size()<< std::endl;
          for (auto x: B) {
            std::cout << x.first << " " << x.second << std::endl;
          }
          return 0;
        } else {
          std::cout << " good " << kI <<" "<< kJ <<" "<< k << std::endl;
        }
      }
    }
  }

//  std::cout << setLast.size()<< std::endl;
//  for (auto dot: setLast) {
//    std::cout << dot.first << " " << dot.second << std::endl;
//  }

  return 0;
}
