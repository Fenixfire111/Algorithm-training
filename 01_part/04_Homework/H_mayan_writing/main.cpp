#include <iostream>
#include <map>

int main() {
  int g;
  int s;
  int result = 0;
  std::string word;
  std::string sequence;
  std::map<char, int> mapWord;
  std::map<char, int> mapTemp;

  std::cin >> g >> s;
  std::cin >> word;
  std::cin >> sequence;

  for (int kI = 0; kI < g; ++kI) {
    ++mapWord[word[kI]];
  }

  int count = 0;
  for (int kI = 0; kI < s; ++kI) {
    char symbol = sequence[kI];
    if (mapWord.count(symbol)) {
      ++mapTemp[symbol];
      ++count;
      if (count == g) {
        if (mapWord == mapTemp) {
          ++result;
          --count;
          --mapTemp[sequence[kI - count]];
        } else {
          --count;
          --mapTemp[sequence[kI - count]];
        }
      }
    } else {
      mapTemp.clear();
      count = 0;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
