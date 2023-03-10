#include <iostream>
#include <vector>

int main() {
  int n;
  int m;

  std::cin >> n;
  std::cin >> m;
  std::vector<std::vector<int>> table(n + 1, std::vector<int> (m + 1));
  for (int kI = 1; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < m + 1; ++kJ) {
      std::cin >> table[kI][kJ];
    }
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int> (m + 1));

  for (int kI = 0; kI < n + 1; ++kI) {
    dp[kI][0] = INT32_MAX;
  }
  for (int kI = 2; kI < m + 1; ++kI) {
    dp[0][kI] = INT32_MAX;
  }

  for (int kI = 1; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < m + 1; ++kJ) {
      dp[kI][kJ] = std::min(dp[kI - 1][kJ], dp[kI][kJ - 1]) + table[kI][kJ];
    }
  }


  std::cout << dp[n][m] << std::endl;
  return 0;
}
