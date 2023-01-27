#include <iostream>
#include <vector>
#include <map>

int main() {
  long long n;
  long long k;
  std::map<long long, long long> types;
  long long last = 0;
  bool flag = false;
  std::pair<long long, long long> result;

  std::cin >> n >> k;
  std::vector<long long> trees(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> trees[kI];
  }

  ++types[trees[0]];
  result.first = 1;
  result.second = n;
  for (long long first = 0; first < n; ++first) {
    while (types.size() != k && last < n - 1) {
      ++last;
      ++types[trees[last]];
    }

    if (last - first < result.second - result.first && types.size() == k) {
      result.first = first + 1;
      result.second = last + 1;
    }

    --types[trees[first]];
    if (types[trees[first]] == 0) {
      types.erase(trees[first]);
    }
  }

  std::cout << result.first << " " << result.second << std::endl;
  return 0;
}
