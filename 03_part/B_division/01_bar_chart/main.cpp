#include <iostream>
#include <map>
#include <fstream>
#include <vector>

int main() {
  int maxLen = 0;
  std::map<char, int> map;
  std::string tempWord;
  std::ifstream input("input.txt");
  if (input.is_open()) {
    while (input >> tempWord) {
      for (auto symbol: tempWord) {
        ++map[symbol];
        if (map[symbol] > maxLen) {
          maxLen = map[symbol];
        }
      }
    }
  }

  while (maxLen > 0) {
    for (auto pair: map) {
      if (pair.second >= maxLen) {
        std::cout << "#";
      } else {
        std::cout << " ";
      }
    }
    std::cout << std::endl;

    --maxLen;
  }
  for (auto pair: map) {
    std::cout << pair.first;
  }

  return 0;
}
