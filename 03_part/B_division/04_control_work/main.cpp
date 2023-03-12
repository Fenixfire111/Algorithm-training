#include <iostream>

int main() {
  int n;
  int k;
  int number;
  int side;
  int loc;
  int newLocFirst;
  int newLocSecond;
  int newNumberFirst;
  int newNumberSecond;
  int newSideFirst;
  int newSideSecond;

  std::cin >> n;
  std::cin >> k;
  std::cin >> number;
  std::cin >> side;

  loc = (number - 1) * 2 + side;

  newLocFirst = loc + k;
  newLocSecond = loc - k;

  if (newLocFirst % 2 == 0) {
    newSideFirst = 2;
    newNumberFirst = newLocFirst / 2;
  } else {
    newSideFirst = 1;
    newNumberFirst = newLocFirst / 2 + 1;
  }

  if (newLocSecond % 2 == 0) {
    newSideSecond = 2;
    newNumberSecond = newLocSecond / 2;
  } else {
    newSideSecond = 1;
    newNumberSecond = newLocSecond / 2 + 1;
  }


  if (newLocFirst > n) {
    if (newLocSecond <= 0) {
      std::cout << -1;
      return 0;
    } else {
      std::cout << newNumberSecond << " " << newSideSecond;
    }
  } else {
    if (newLocSecond < 0) {
      std::cout << newNumberFirst << " " << newSideFirst;
      return 0;
    } else {
      if (std::abs(number - newNumberFirst) > std::abs(number - newNumberSecond)) {
        std::cout << newNumberSecond << " " << newSideSecond;
      } else {
        std::cout << newNumberFirst << " " << newSideFirst;
      }
    }
  }



  return 0;
}
