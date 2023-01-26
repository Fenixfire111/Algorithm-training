#include <iostream>
#include <map>
#include <fstream>
#include <string>

int main() {
  std::fstream input("input.txt");\
  std::map<std::string, long long> bankAccounts;
  std::string operation;
  std::string name;
  std::string name2;
  int percent;
  long long money;

  if (input.is_open()) {
    while (input >> operation) {
      if (operation == "DEPOSIT") {
        input >> name >> money;
        bankAccounts[name] += money;
      } else if (operation == "WITHDRAW") {
        input >> name >> money;
        bankAccounts[name] -= money;
      } else if (operation == "BALANCE") {
        input >> name;
        if (bankAccounts.count(name)) {
          std::cout << bankAccounts[name] << std::endl;
        } else {
          std::cout << "ERROR" << std::endl;
        }
      } else if (operation == "TRANSFER") {
        input >> name >> name2 >> money;
        bankAccounts[name] -= money;
        bankAccounts[name2] += money;
      } else if (operation == "INCOME") {
        input >> percent;
        for (auto& client: bankAccounts) {
          if (client.second > 0) {
            client.second += client.second * percent / 100;
          }
        }
      }

    }
  }

  return 0;
}
