#include <iostream>

int minTime(const int &interval, const int &number) {
  return 1 + (interval + 1) * (number - 1);
}

int maxTime(const int &interval, const int &number) {
  return 2 * interval + (1 + interval) * (number - 1) + 1;
}

int main() {
  int interval1, interval2, number1, number2;

  int minTime1, minTime2, maxTime1, maxTime2;

  std::cin >> interval1 >> interval2 >> number1 >> number2;

  maxTime1 = maxTime(interval1, number1);
  maxTime2 = maxTime(interval2, number2);
  minTime1 = minTime(interval1, number1);
  minTime2 = minTime(interval2, number2);

  if (minTime1 > maxTime2 || minTime2 > maxTime1) {
    std::cout << -1 << std::endl;
  } else if (maxTime1 <= maxTime2) {
    if (minTime1 >= minTime2) {
      std::cout << minTime1 << " " << maxTime1 << std::endl;
    } else {
      std::cout << minTime2 << " " << maxTime1 << std::endl;
    }
  } else {
    if (minTime1 >= minTime2) {
      std::cout << minTime1 << " " << maxTime2 << std::endl;
    } else {
      std::cout << minTime2 << " " << maxTime2 << std::endl;
    }
  }

  return 0;
}
