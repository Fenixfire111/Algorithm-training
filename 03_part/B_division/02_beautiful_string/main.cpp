#include <iostream>
#include <set>
#include <vector>

int main() {
  int k;
  int maxLen = 0;
  int second;
  int currLen;
  int currCount;
  std::string str;
  std::set<char> letters;

  std::cin >> k;
  std::cin >> str;

  for (auto symbol: str) {
    letters.insert(symbol);
  }

  currCount = k;
  currLen = 0;
  for (auto symbol: letters) {
    second = 0;
    currCount = k;
    currLen = 0;

    for (int first = 0; first < str.size(); ++first) {
      if (symbol == str[first]) {
        ++currLen;
      } else {
        if (currCount > 0) {
          --currCount;
          ++currLen;
        } else {
          //OK END STR!!!
          if (currLen > maxLen) {
            maxLen = currLen;
          }
          if (str[first - currLen] != symbol) {
            ++currCount;
          }
          --currLen;
          ++second;
          --first;
          //OK Second > size!!!
        }
      }
    }
    if (currLen > maxLen) {
      maxLen = currLen;
    }
  }



  std::cout << maxLen << std::endl;
  return 0;
}
