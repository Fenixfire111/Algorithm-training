#include <iostream>
#include <deque>

int main() {
  int n;
  int temp;
  std::string sign;
  std::deque<int> firstHalf;
  std::deque<int> secondHalf;

  std::cin >> n;

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> sign;
    if (sign == "-") {
      std::cout << firstHalf.front() << std::endl;
      firstHalf.pop_front();
    } else if (sign == "+") {
      std::cin >> temp;
      secondHalf.push_back(temp);
    } else if (sign == "*") {
      std::cin >> temp;
      firstHalf.push_back(temp);
    }

    if (firstHalf.size() < secondHalf.size()) {
      firstHalf.push_back(secondHalf.front());
      secondHalf.pop_front();
    } else if (firstHalf.size() > secondHalf.size() + 1) {
      secondHalf.push_front(firstHalf.back());
      firstHalf.pop_back();
    }
  }

  return 0;
}
