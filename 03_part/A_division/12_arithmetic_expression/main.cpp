#include <iostream>
#include <stack>
#include <map>
#include <sstream>

int main() {
  std::string expression;
  std::string postExpression;
  std::stack<char> stackChar;
  std::map<char, int> priority;
  bool lastDigit = true;
  bool lastSpace = false;
  bool lastOperation = false;
  bool lastBracket = true;

  priority['-'] = 1;
  priority['+'] = 1;
  priority['*'] = 2;
  priority['('] = 0;

  std::getline(std::cin, expression, '\n');
  ///BAD STR!!!

  for (auto symbol: expression) {
    if (std::isdigit(symbol)) {
      if (lastDigit) {
        if (lastSpace) {
          std::cout << "WRONG" << std::endl;
          return 0;
        } else {
          postExpression.push_back(symbol);
        }
      } else {
        postExpression.push_back(' ');
        postExpression.push_back(symbol);
      }
      lastDigit = true;
      lastSpace = false;
      lastOperation = false;
      lastBracket = false;
    } else if (symbol == ' ') {
      postExpression.push_back(symbol);
      lastSpace = true;
    } else if (symbol == '-' || symbol == '+' || symbol == '*') {

      if (lastBracket) {
        if (symbol == '-') {
          postExpression.push_back(' ');
          postExpression.push_back('0');
        } else {
          ///+++++
          std::cout << "WRONG" << std::endl;
          return 0;
        }
      }

      if (lastOperation) {
        std::cout << "WRONG" << std::endl;
        return 0;
      } else {
        if (stackChar.empty() || priority[symbol] > priority[stackChar.top()]) {
          stackChar.push(symbol);
        } else {
          while (priority[symbol] <= priority[stackChar.top()] || stackChar.top() != '(') {
            postExpression.push_back(' ');
            postExpression.push_back(stackChar.top());
            stackChar.pop();

            if (stackChar.empty()) {
              break;
            }
          }
          stackChar.push(symbol);
        }
      }
      lastDigit = false;
      lastSpace = false;
      lastOperation = true;
      lastBracket = false;
    } else if (symbol == '(') {
      stackChar.push(symbol);
      lastDigit = false;
      lastSpace = false;
      lastOperation = false;
      lastBracket = true;
    } else if (symbol == ')') {

      if (lastOperation) {
        std::cout << "WRONG" << std::endl;
        return 0;
      }

      if (stackChar.empty()) {
        std::cout << "WRONG" << std::endl;
        return 0;
      }
      while (stackChar.top() != '(') {
        postExpression.push_back(' ');
        postExpression.push_back(stackChar.top());
        stackChar.pop();

        if (stackChar.empty()) {
          std::cout << "WRONG" << std::endl;
          return 0;
        }
      }
      stackChar.pop();
      lastDigit = false;
      lastSpace = false;
      lastOperation = false;
      lastBracket = false;
    } else {
      std::cout << "WRONG" << std::endl;
      return 0;
    }
  }

  if (lastOperation) {
    std::cout << "WRONG" << std::endl;
    return 0;
  }
  while (!stackChar.empty()) {
    if (stackChar.top() == '(') {
      std::cout << "WRONG" << std::endl;
      return 0;
    }
    postExpression.push_back(' ');
    postExpression.push_back(stackChar.top());
    stackChar.pop();
  }

  std::stringstream postExprStream;
  postExprStream << postExpression;

  std::stack<int> stack;
  std::string symbol;
  int num1;
  int num2;

  while (postExprStream >> symbol) {
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
    } else {
      stack.push(std::stoi(symbol));
    }
  }

  if (stack.empty()) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << stack.top() << std::endl;
  }

  return 0;
}
