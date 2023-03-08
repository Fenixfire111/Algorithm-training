#include <iostream>
#include <deque>

int main() {
  std::deque<int> deque;
  std::string command;
  int value;

  std::cin >> command;
  while (command != "exit") {
    if (command == "push_front") {
      std::cin >> value;
      deque.push_front(value);
      std::cout << "ok" << std::endl;
    } else if (command == "push_back") {
      std::cin >> value;
      deque.push_back(value);
      std::cout << "ok" << std::endl;
    } else if (command == "pop_front") {
      if (!deque.empty()) {
        std::cout << deque.front() << std::endl;
        deque.pop_front();
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "pop_back") {
      if (!deque.empty()) {
        std::cout << deque.back() << std::endl;
        deque.pop_back();
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "front") {
      if (!deque.empty()) {
        std::cout << deque.front() << std::endl;
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "back") {
      if (!deque.empty()) {
        std::cout << deque.back() << std::endl;
      } else {
        std::cout << "error" << std::endl;
      }
    } else if (command == "size") {
      std::cout << deque.size() << std::endl;
    } else if (command == "clear") {
      deque = std::deque<int>();
      std::cout << "ok" << std::endl;
    }

    std::cin >> command;
  }

  std::cout << "bye" << std::endl;

  return 0;
}
