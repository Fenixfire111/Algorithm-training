#include <iostream>
#include <vector>
#include <set>

int main() {
  int temp;
  int number;
  int count = 0;
  std::set<int> set;

  for (int kI = 0; kI < 3; ++kI) {
    std::cin >> temp;
    set.insert(temp);
  }
  std::cin >> number;

  while (number != 0) {
    temp = number % 10;
    if (!set.count(temp)) {
      ++count;
      set.insert(temp);
    }
    number /= 10;
  }

  std::cout << count << std::endl;
  return 0;
}
