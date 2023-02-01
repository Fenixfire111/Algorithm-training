#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct point {
  int first;
  int second;
  int third = -1;

//  bool operator< (const point1& anotherPoint) const{
//    if (first < anotherPoint.first) {
//      return true;
//    } else if (first == anotherPoint.first) {
//      return second > anotherPoint.second;
//    } else {
//      return false;
//    }
//  }
};

bool comp1(point a, point b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first == b.first) {
    return a.second > b.second;
  } else {
    return false;
  }
}

bool comp2(point a, point b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first == b.first) {
    return a.second < b.second;
  } else {
    return false;
  }
}

int main() {
  int n;
  int d;
  int x;
  int maxCount = 1;
  bool chet;
  std::queue<int> variants;
  std::queue<int> nextVariants;

  std::cin >> n >> d;
  std::vector<int> result(n);
  std::vector<point> students(2 * n);

  if (d % 2 == 0) {
    chet = true;
    d /= 2;
  } else {
    chet = false;
    d /= 2;
    ++d;
  }
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x;

    students[kI].first = x - d;
    students[kI].second = -1;
    students[kI].third = kI;
    students[kI + n].first = x + d;
    students[kI + n].second = 1;
    students[kI + n].third = kI;
  }

  if (chet) {
    std::sort(students.begin(), students.end(), comp2);
  } else {
    std::sort(students.begin(), students.end(), comp1);
  }

  for (auto event: students) {
    if (event.second == -1) {
      if (nextVariants.empty()) {
        variants.push(variants.size() + 1);
      } else {
        variants.push(nextVariants.front());
        nextVariants.pop();
      }
      result[event.third] = variants.back();

      if (maxCount < variants.size()) {
        maxCount = variants.size();
      }
    } else {
      if (!variants.empty()) {
        nextVariants.push(variants.front());
        variants.pop();
      }

    }
  }

  std::cout << maxCount << std::endl;
  for (int kI = 0; kI < n; ++kI) {
    std::cout << result[kI] << " ";
  }
  return 0;
}
