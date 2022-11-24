#include <iostream>
#include <set>

int main() {
  int t;
  int d;
  int n;
  int x, y;
  std::set<std::pair<int, int>> setLast;
  std::set<std::pair<int, int>> setNewT;
  std::set<std::pair<int, int>> setNewD;

  std::cin >> t >> d >> n;
  std::pair<int, int> temp(0,0);
  setLast.insert(temp);

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x >> y;
    for (auto dot: setLast) {
      for (int kJ = 0; kJ <= t; ++kJ) {
        for (int k = 0; k <= t - kJ; ++k) {
          temp.first = dot.first + kJ;
          temp.second = dot.second + k;
          setNewT.insert(temp);
          temp.first = dot.first - kJ;
          temp.second = dot.second + k;
          setNewT.insert(temp);
          temp.first = dot.first + kJ;
          temp.second = dot.second - k;
          setNewT.insert(temp);
          temp.first = dot.first - kJ;
          temp.second = dot.second - k;
          setNewT.insert(temp);
        }
      }
    }

    for (int kJ = 0; kJ <= d; ++kJ) {
      for (int k = 0; k <= d - kJ; ++k) {
        temp.first = x + kJ;
        temp.second = y + k;
        setNewD.insert(temp);
        temp.first = x - kJ;
        temp.second = y + k;
        setNewD.insert(temp);
        temp.first = x + kJ;
        temp.second = y - k;
        setNewD.insert(temp);
        temp.first = x - kJ;
        temp.second = y - k;
        setNewD.insert(temp);
      }
    }

    setLast.clear();
    for (auto dot: setNewD) {
      if (setNewT.count(dot)) {
        setLast.insert(dot);
      }
    }
    setNewT.clear();
    setNewD.clear();
  }

  std::cout << setLast.size()<< std::endl;
  for (auto dot: setLast) {
    std::cout << dot.first << " " << dot.second << std::endl;
  }
  return 0;
}
