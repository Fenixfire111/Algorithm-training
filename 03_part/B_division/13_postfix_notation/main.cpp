#include <iostream>
#include <stack>
#include <fstream>

int main() {
  std::ifstream input("input.txt");
  std::stack<int> stack;
  std::string symbol;
  int num1;
  int num2;

  if (input.is_open()) {
    while (input >> symbol) {
      if (symbol == "+") {
        num1 = stack.top();
        stack.pop();
        num2 = stack.top();
        stack.pop();
        stack.push(num1 + num2);
      } else if (symbol == "-") {
        num1 = stack.top();
        stack.pop();
        num2 = stack.top();
        stack.pop();
        stack.push(num2 - num1);
      } else if (symbol == "*") {
        num1 = stack.top();
        stack.pop();
        num2 = stack.top();
        stack.pop();
        stack.push(num1 * num2);
      } else if (symbol == "/") {
        num1 = stack.top();
        stack.pop();
        num2 = stack.top();
        stack.pop();
        stack.push(num1 / num2);
      } else {
        stack.push(std::stoi(symbol));
      }
    }
  }

  std::cout << stack.top() << std::endl;
  return 0;
}
