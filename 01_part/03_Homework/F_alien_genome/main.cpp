#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  std::vector<std::string> array;
  std::unordered_set<std::string> set;
  std::string genome;
  std::string temp1, temp2;
  int count = 0;

  std::cin >> genome;

  for (int kI = 0; kI < genome.size() - 1; ++kI) {
    temp1 = genome[kI];
    temp2 = genome[kI + 1];
    temp1 += temp2;
    array.push_back(temp1);
  }

  std::cin >> genome;

  for (int kI = 0; kI < genome.size() - 1; ++kI) {
    temp1 = genome[kI];
    temp2 = genome[kI + 1];
    temp1 += temp2;
    set.insert(temp1);
  }

  for (int kI = 0; kI < array.size(); ++kI) {
    if (set.count(array[kI])) {
      ++count;
    }
  }

  std::cout << count << std::endl;
  return 0;
}
