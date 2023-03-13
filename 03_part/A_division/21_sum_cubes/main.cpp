#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> cubes(101);
  for (int kI = 1; kI < cubes.size(); ++kI) {
    cubes[kI] = kI * kI * kI;
  }

  std::cin >> n;
  std::vector<int> dp(n + 1);

  dp[1] = 1;
  for (int kI = 2; kI < n + 1; ++kI) {
    int a = 1;
    int min = INT32_MAX;
    while (kI - cubes[a] >= 0) {
      min = std::min(min, dp[kI - cubes[a]]  + 1);
      ++a;
    }

    dp[kI] = min;
  }

  std::cout << dp[n] << std::endl;
  return 0;
}
