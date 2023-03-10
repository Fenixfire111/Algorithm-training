#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int n;

  std::cin >> n;
  std::vector<int> dp(n + 1);

  dp[1] = 2;
  dp[2] = 4;
  dp[3] = 7;
  for (int kI = 4; kI < dp.size(); ++kI) {
    dp[kI] = dp[kI - 1] + dp[kI - 2] + dp[kI - 3];
  }

  std::cout << dp[n] << std::endl;
  return 0;
}
