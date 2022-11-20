#include <iostream>
#include <vector>

int main() {
  std::vector<int> list;
  int number1, number2;
  std::string result = "YES";

  std::cin >> number1;
  while (std::cin >> number2) {
    if (number2 <= number1) {
      result = "NO";
      break;
    }
    number1 = number2;
  }

  std::cout << result << std::endl;

  return 0;
}
