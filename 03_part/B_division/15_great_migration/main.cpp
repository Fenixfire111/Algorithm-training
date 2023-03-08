#include <iostream>
#include <stack>
#include <vector>

int main() {
  int n;
  std::stack<int> stack;

  std::cin >> n;
  std::vector<int> array(n);
  std::vector<int> result(n, -1);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> array[kI];
  }

  for (int kI = 0; kI < n; ++kI) {
    if (stack.empty()) {
      stack.push(kI);
    } else {
      while (array[stack.top()] > array[kI]) {
        result[stack.top()] = kI;
        stack.pop();

        if (stack.empty()) {
          break;
        }
      }
      stack.push(kI);
    }
  }

  for (int kI = 0; kI < n; ++kI) {
    std::cout << result[kI] << " ";
  }
  return 0;
}
