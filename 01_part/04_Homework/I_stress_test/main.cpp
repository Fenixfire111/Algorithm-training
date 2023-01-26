#include <iostream>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <fstream>

int main() {
  int n;
  int result = 0;
  std::string word;
  std::string copy;
  std::map<std::string, std::unordered_set<std::string>> dictionary;
  std::fstream input("input.txt");

  if (input.is_open()) {
  input >> n;

  for (int kI = 0; kI < n; ++kI) {
    input >> word;
    copy = word;
    std::transform(copy.begin(), copy.end(), copy.begin(), tolower);
    dictionary[copy].insert(word);
  }


    while (input >> word) {
      copy = word;
      std::transform(copy.begin(), copy.end(), copy.begin(), tolower);
      if (dictionary.count(copy)) {
        if (!dictionary[copy].count(word)) {
          ++result;
        }
      } else {
        int count = 0;
        for (char sym : word) {
          if ('A'<= sym && sym<='Z') {
            ++count;
          }
        }
        if (count != 1) {
          ++result;
        }
      }
    }

  }

  std::cout << result << std::endl;

  return 0;
}
