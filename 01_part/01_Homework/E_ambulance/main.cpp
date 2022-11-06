#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int secondFlat;
  int numberFloors;
  int firstFlat;
  int firstEntrance;
  int firstFloor;

  int secondEntrance, secondFloor;

  std::vector<int> cc;

  std::cin >> secondFlat >> numberFloors >> firstFlat >> firstEntrance >> firstFloor;

  if (firstFloor == 1 && firstEntrance == 1){
    if (numberFloors == 1){
      secondEntrance = 0;
      secondFloor = 1;
    } else{
      secondEntrance = 0;
      secondFloor = 0;
    }
  } else if (firstFlat < firstFloor + (firstEntrance - 1) * numberFloors){
    secondEntrance = -1;
    secondFloor = -1;
  } else {
    int n = (firstFloor - 1) + (firstEntrance - 1) * numberFloors;
    int c = firstFlat / n;
    if (firstFlat % c == 0){
      --c;
    }

    while (firstFlat % c > 0 && firstFlat - c * n < c) {
      cc.push_back(c);
      --c;
    }

    if (!cc.empty()){
      int n2 = secondFlat / cc[0];

      if (secondFlat - n2 * cc[0] < cc[0] &&
          secondFlat - n2 * cc[cc.size()-1] < cc[cc.size()-1]){
        secondEntrance = (n2 / numberFloors) + 1;
        secondFloor = (n2 % numberFloors) + 1;
      } else{
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
