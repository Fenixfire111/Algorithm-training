#include <iostream>
#include <map>
#include <fstream>

int main() {
  int maxCount = 0;
  std::string finalWord;
  std::string tempWord;

  std::map<std::string, int> map;

  std::fstream input("input.txt");
  if (input.is_open()) {
    while (input >> tempWord) {
      ++map[tempWord];
    }
  }

  for (const auto& pair: map) {
    if (maxCount < pair.second) {
      maxCount = pair.second;
      finalWord = pair.first;
    } else if (maxCount == pair.second && finalWord > pair.first) {
      finalWord = pair.first;
    }
  }
  std::cout << finalWord << std::endl;
  return 0;
}
