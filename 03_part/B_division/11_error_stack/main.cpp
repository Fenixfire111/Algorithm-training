#include <iostream>
#include <stack>

int main() {
  std::stack<int> stack;
  std::string command;
  int value;

  std::cin >> command;
  while (command != "exit") {
    if (command == "push") {
      std::cin >> value;
      stack.push(value);
      std::cout << "ok" << std::endl;
    } else if (command == "pop") {
      if (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "back") {
      if (!stack.empty()) {
        std::cout << stack.top() << std::endl;
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "size") {
      std::cout << stack.size() << std::endl;
    } else if (command == "clear") {
      stack = std::stack<int>();
      std::cout << "ok" << std::endl;
    }

    std::cin >> command;
  }

  std::cout << "bye" << std::endl;

  return 0;
}
