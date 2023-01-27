#include <iostream>
#include <vector>

int main() {
  long long n;
  long long r;
  long long second = 1;
  long long result = 0;

  std::cin >> n >> r;
  std::vector<long long> distances(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> distances[kI];
  }

  for (int first = 0; first < n; ++first) {
    while ((distances[second] - distances[first]) <= r && second < n) {
      ++second;
    }
    result += n - second;
  }

  std::cout << result << std::endl;
  return 0;
}
