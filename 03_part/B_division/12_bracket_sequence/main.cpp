#include <iostream>
#include <stack>

int main() {
  std::string sequence;
  std::stack<char> stack;

  std::cin >> sequence;

  for (auto symbol: sequence) {
    if (symbol == '(' || symbol == '[' || symbol == '{') {
      stack.push(symbol);
    } else {
      if (stack.empty()) {
        std::cout << "no" << std::endl;
        return 0;
      } else {
        if (symbol == ')') {
          if (stack.top() == '(') {
            stack.pop();
          } else {
            std::cout << "no" << std::endl;
            return 0;
          }
        } else if (symbol == ']') {
          if (stack.top() == '[') {
            stack.pop();
          } else {
            std::cout << "no" << std::endl;
            return 0;
          }
        } else if (symbol == '}') {
          if (stack.top() == '{') {
            stack.pop();
          } else {
            std::cout << "no" << std::endl;
            return 0;
          }
        }
      }
    }

  }

  if (stack.empty()) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
  return 0;
}
