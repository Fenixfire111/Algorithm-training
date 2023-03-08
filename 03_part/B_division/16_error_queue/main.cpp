#include <iostream>
#include <queue>

int main() {
  std::queue<int> queue;
  std::string command;
  int value;

  std::cin >> command;
  while (command != "exit") {
    if (command == "push") {
      std::cin >> value;
      queue.push(value);
      std::cout << "ok" << std::endl;
    } else if (command == "pop") {
      if (!queue.empty()) {
        std::cout << queue.front() << std::endl;
        queue.pop();
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "front") {
      if (!queue.empty()) {
        std::cout << queue.front() << std::endl;
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "size") {
      std::cout << queue.size() << std::endl;
    } else if (command == "clear") {
      queue = std::queue<int>();
      std::cout << "ok" << std::endl;
    }

    std::cin >> command;
  }

  std::cout << "bye" << std::endl;

  return 0;
}
