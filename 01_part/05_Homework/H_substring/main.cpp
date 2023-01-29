#include <iostream>
#include <vector>
#include <map>

int main() {
  int n;
  int k;
  int second = 0;
  int maxSize = 0;
  int maxFirst = 0;
  int size = 0;
  std::string str;
  std::map<char, int> map;

  std::cin >> n >> k;
  std::cin >> str;

  for (int first = 0; first < n; ++first) {
    while (map[str[second]] < k && second < n) {
      ++map[str[second]];
      ++second;
      ++size;
    }

    if (size > maxSize) {
      maxSize = size;
      maxFirst = first;
    }

    --map[str[first]];
    --size;
  }

  std::cout << maxSize << " " << maxFirst + 1 << std::endl;
  return 0;
}
