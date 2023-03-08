#include <iostream>
#include <map>

int main() {
  std::string word;
  unsigned long long halfLen;
  std::map<char, unsigned long long> map;
//  bool firstHalf = true;

  std::cin >> word;
  unsigned long long len = word.size();

  if (word.size() % 2 == 0) {
    halfLen = len / 2;
  } else {
    halfLen = len / 2 + 1;
  }

  for (unsigned long long kI = 0; kI < len; ++kI) {
    if (kI < halfLen) {
      map[word[kI]] += (len + len - kI * 2) / 2 * (kI + 1);
    } else {
      map[word[kI]] += (len + len - (len - kI - 1) * 2) / 2 * (len - kI);
    }
  }

  for (auto pair: map) {
    std::cout << pair.first<< ":" << " " << pair.second << std::endl;
  }
  return 0;
}
