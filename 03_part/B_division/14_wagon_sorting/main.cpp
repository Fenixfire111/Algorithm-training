#include <iostream>
#include <stack>

int main() {
  int n;
  int currNumber;
  int lastNumber = 1;
  std::stack<int> stack;

  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> currNumber;
    stack.push(currNumber);

    while (stack.top() == lastNumber) {
      stack.pop();
      ++lastNumber;

      if (stack.empty()) {
        break;
      }
    }
  }

  if (stack.empty()) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
