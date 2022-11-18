#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long long secondFlat;
  long long numberFloors;
  long long firstFlat;
  long long firstEntrance;
  long long firstFloor;

  long long secondEntrance, secondFloor;

  std::vector<long long> cc;

  std::cin >> secondFlat >> numberFloors >> firstFlat >> firstEntrance >> firstFloor;

  if (firstFloor > numberFloors) {
    secondEntrance = -1;
    secondFloor = -1;
  } else if (firstFloor == 1 && firstEntrance == 1) {
    if (secondFlat == firstFlat) {
      secondEntrance = firstEntrance;
      secondFloor = firstFloor;
    } else if (numberFloors == 1) {
      secondEntrance = 0;
      secondFloor = 1;
    } else {
      secondFloor = 0;
      if (secondFlat <= firstFlat * numberFloors) {
        secondEntrance = 1;
      } else {
        secondEntrance = 0;
      }
    }
  } else if (firstFlat < firstFloor + (firstEntrance - 1) * numberFloors) {
    secondEntrance = -1;
    secondFloor = -1;
  } else {
    int n = (firstFloor - 1) + (firstEntrance - 1) * numberFloors;
    int c = firstFlat / n;
    if (firstFlat % c == 0){
      --c;
    }

    if (c == 0) {
      cc.push_back(1);
    } else {
      while (firstFlat % c > 0 && firstFlat - c * n < c) {
        cc.push_back(c);
        --c;
      }
    }

    if (!cc.empty()) {
      int n2 = secondFlat / cc[0];

      if (secondFlat - n2 * cc[0] <= cc[0] &&
          secondFlat - n2 * cc[cc.size()-1] <= cc[cc.size()-1]) {
        if (secondFlat % cc[0] != 0) {
          secondEntrance = (n2 / numberFloors) + 1;
          secondFloor = (n2 % numberFloors) + 1;
        } else if (n2 % numberFloors == 0){
          secondEntrance = (n2 / numberFloors);
          secondFloor = numberFloors;
        } else {
          secondEntrance = (n2 / numberFloors) + 1;
          secondFloor = (n2 % numberFloors);
        }
      } else if (numberFloors == 1){
        secondEntrance = 0;
        secondFloor = 1;
      } else if ((secondFlat / cc[0] + 1) / numberFloors ==
          (secondFlat / cc[cc.size() - 1] + 1) / numberFloors){
        secondEntrance = (secondFlat / cc[0] + 1) / numberFloors + 1;
        secondFloor = 0;
      } else {
        secondEntrance = 0;
        secondFloor = 0;
      }
    } else {
      secondEntrance = -1;
      secondFloor = -1;
    }
  }

  std::cout << secondEntrance << " " << secondFloor << std::endl;

  return 0;
}
