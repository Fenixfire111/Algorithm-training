#include <iostream>
#include <string>

std::string cleanNumber(std::string fullNumber) {
    std::string code = "";
    std::string number = "";

    for (int kJ = fullNumber.size() - 1; kJ >= 0; --kJ) {
      if (fullNumber[kJ] != '-' && fullNumber[kJ] != '(' &&
          fullNumber[kJ] != ')') {
        if (number.size() < 7) {
          number += fullNumber[kJ];
        } else if (code.size() < 3) {
          code += fullNumber[kJ];
        }
      }
    }

    if (code.empty()) {
      code = "594";
    }

    return number + code;
}

int main() {
  std::string firstNumber;
  std::string secondNumber;

  std::string code = "";
  std::string number = "";

  std::string result;

  std::cin >> firstNumber;

  firstNumber = cleanNumber(firstNumber);

  for (int kI = 0; kI < 3; ++kI)
  {
    std::cin >> secondNumber;

    secondNumber = cleanNumber(secondNumber);

    if (firstNumber == secondNumber)
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
