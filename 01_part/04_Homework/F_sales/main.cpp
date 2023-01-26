#include <iostream>
#include <map>
#include <fstream>

int main() {
  std::fstream input("input.txt");
  std::string name;
  std::string product;
  int count;
  std::map<std::string, std::map<std::string, int>> database;

  if (input.is_open()) {
    while (input >> name >> product >> count) {
      database[name][product] += count;
    }
  }

  for (const auto& names: database) {
    std::cout << names.first << ":" << std::endl;
    for (const auto& products: names.second) {
      std::cout << products.first << " " << products.second << std::endl;
    }
  }

  return 0;
}
