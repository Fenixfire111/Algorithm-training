#include <iostream>
#include <vector>

int main() {
  long long k;
  long long prev = 0;
  long long result = 0;
  std::string str;

  std::cin >> k;
  std::cin >> str;

  for (long long kI = 0; kI < str.size() - k; ++kI) {
    if (str[kI] == str[kI + k]) {
      ++prev;
      result += prev;
    } else {
      prev = 0;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
