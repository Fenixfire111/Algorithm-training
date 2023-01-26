#include <iostream>
#include <fstream>
#include <map>

int main() {
  std::fstream input("input.txt");
  std::string word;
  std::map<std::string, int> map;

  if (input.is_open()) {
    while (input >> word) {
      if (map.count(word)) {
        std::cout << map[word] << " ";
      } else {
        std::cout << 0 << " ";
      }

      map[word] += 1;
    }
  }

  return 0;
}
