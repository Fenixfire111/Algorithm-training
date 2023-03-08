#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool check(const int& value, const std::vector<unsigned int>& array, const unsigned int& x) {
  return array[x] < value;
}

unsigned int binarySearch(const int& value, const std::vector<unsigned int>& array) {
  unsigned int l = 0;
  unsigned int r = array.size() - 1;
  unsigned int x;
  while (l < r) {
    x = (l + r + 1) / 2;
    if (check(value, array, x)) {
      l = x;
    } else {
      r = x - 1;
    }

  }

  return l;
}

int main() {
  int n;
  int k;
  unsigned int tempVal;
  unsigned int result;
  std::set<unsigned int> set;

  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> tempVal;
    set.insert(tempVal);
  }
  std::vector<unsigned int> array(set.size());
  int iter = 0;
  for (auto val: set) {
    array[iter] = val;
    ++iter;
  }

  std::cin >> k;
  std::vector<unsigned int> values(k);
  for (int kI = 0; kI < k; ++kI) {
    std::cin >> values[kI];
  }

  if (n == 0) {
    for (int kI = 0; kI < k; ++kI) {
      std::cout << 0 << std::endl;
    }

    return 0;
  }

  for (auto value: values) {
    result = binarySearch(value, array);
    if (array[result] >= value) {
      std::cout << result << std::endl;
    } else {
      std::cout << result + 1 << std::endl;
    }
  }

  return 0;
}
