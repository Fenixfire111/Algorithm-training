#include <iostream>
#include <deque>
#include <vector>
#include <fstream>

int main() {
  int n;
  int k;
  int first;
  int iter;
  std::deque<int> deque;
  std::ifstream input("input.txt");

  input >> n >> k;
  std::vector<int> array(n);
  for (int kI = 0; kI < n; ++kI) {
    input >> array[kI];
  }

  for (int kI = 0; kI < array.size(); ++kI) {
    if (deque.empty()) {
      deque.push_back(array[kI]);
    } else {
      /// = ??
      while (deque.back() > array[kI]) {
        deque.pop_back();

        if (deque.empty()) {
          break;
        }
      }
      deque.push_back(array[kI]);
    }

    if (kI >= k - 1) {
      std::cout << deque.front() << std::endl;
      if (deque.front() == array[kI - k + 1]) {
        deque.pop_front();
      }
    }
  }

  return 0;
}
