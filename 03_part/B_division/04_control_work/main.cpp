#include <iostream>

int main() {
  int n;
  int k;
  int number;
  int side;
  int loc;
  int newLoc;
  int newNumber;
  int newSide;

  std::cin >> n;
  std::cin >> k;
  std::cin >> number;
  std::cin >> side;

  loc = (number - 1) * 2 + side;
//  if (loc > n) {
//    std::cout << -1 << std::endl;
//
//    return 0;
//  }
  if (loc + k > n) {
    if (loc - k > 0) {
      newLoc = loc - k;
    } else {
      std::cout << -1 << std::endl;

      return 0;
    }
  } else {
    newLoc = loc + k;
  }

  if (newLoc % 2 == 0) {
    newSide = 2;
    newNumber = newLoc / 2;
  } else {
    newSide = 1;
    newNumber = newLoc / 2 + 1;
  }

  std::cout << newNumber << " " << newSide;

  return 0;
}
