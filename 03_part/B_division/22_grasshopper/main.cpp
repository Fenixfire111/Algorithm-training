#include <iostream>
#include <vector>

int main() {
  int n;
  int k;

  std::cin >> n;
  std::cin >> k;

  std::vector<int> dp(n + 1);

  if (k > n) {
    k = n;
  }
  dp[1] = 1;
  for (int kI = 2; kI <= k; ++kI) {
    for (int kJ = 1; kJ < kI; ++kJ) {
      dp[kI] += dp[kJ];
    }
  }

  for (int kI = k + 1; kI < dp.size(); ++kI) {
    for (int kJ = 1; kJ <= k; ++kJ) {
      dp[kI] += dp[kI - kJ];
    }
  }

  std::cout << dp[n] << std::endl;
  return 0;
}
