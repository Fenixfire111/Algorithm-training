#include <iostream>
#include <map>
#include <fstream>

int main() {
  std::fstream input("input.txt");
  std::string name;
  std::string product;
  long long count;
  std::map<std::string, std::map<std::string, long long>> database;

  if (input.is_open()) {
    while (input >> name >> product >> count) {
      database[name][product] += count;
    }
  }

//  std::ofstream output("output.txt");
//  if (output.is_open()) {
//    for (const auto& names: database) {
//      output << names.first << ":" << std::endl;
//      for (const auto& products: names.second) {
//        output << products.first << " " << products.second << std::endl;
//      }
//    }
//  }

  for (const auto& names: database) {
    std::cout << names.first << ":" << std::endl;
    for (const auto& products: names.second) {
      std::cout << products.first << " " << products.second << std::endl;
    }
  }

  return 0;
}
