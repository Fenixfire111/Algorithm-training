#include <iostream>
#include <map>

int main() {
  std::map<std::string, std::string> map;
  int n;
  std::string word1;
  std::string word2;
  std::string friendWord;

  std::cin >> n;

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> word1 >> word2;
    map[word1] = word2;
    map[word2] = word1;
  }

  std::cin >> friendWord;

  std::cout << map[friendWord] << std::endl;

  return 0;
}
