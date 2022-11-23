#include <iostream>
#include <unordered_set>
#include <fstream>

int main() {
  std::unordered_set<std::string> set;
  std::ifstream in("input.txt");
  if (in.is_open()) {
    std::string word;
    while (in >> word) {
      set.insert(word);
    }
  }

  std::ofstream out("output.txt");
  if (out.is_open()) {
    out << set.size() << std::endl;
  }

  return 0;
}
