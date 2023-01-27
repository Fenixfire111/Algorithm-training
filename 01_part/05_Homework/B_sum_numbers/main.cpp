#include <iostream>
#include <vector>

int main() {
  int n;
  int k;
  int second = 1;
  int result = 0;

  std::cin >> n >> k;
  std::vector<long long> numbers(n);
  std::vector<long long> sum(n + 1);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> numbers[kI];
  }

  for (int kI = 1; kI <= n; ++kI) {
    sum[kI] = sum[kI - 1] + numbers[kI - 1];
  }

  for (int first = 0; first <= n; ++first) {
    while ((sum[second] - sum[first]) < k && second <= n) {
      ++second;
    }
    if ((sum[second] - sum[first]) == k) {
      ++result;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
