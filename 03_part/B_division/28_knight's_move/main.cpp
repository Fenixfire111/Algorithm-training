#include <iostream>
#include <vector>

int main() {
  int n;
  int m;

  std::cin >> n >> m;

  std::vector<std::vector<int>> dp (n + 1, std::vector<int> (m + 1));

  dp[1][1] = 1;
  if (n > 2 && m > 1) {
    dp[3][2] = 1;
  }
  if (m > 2 && n > 1) {
    dp[2][3] = 1;
  }

  for (int kI = 3; kI < n + 1; ++kI) {
    for (int kJ = 3; kJ < m + 1; ++kJ) {
      dp[kI][kJ] = dp[kI - 2][kJ - 1] + dp[kI - 1][kJ - 2];
    }
  }

  std::cout << dp[n][m] << std::endl;
  return 0;
}
