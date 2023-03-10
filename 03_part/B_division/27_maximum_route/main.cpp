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
  std::vector<std::vector<char>> route(n + 1, std::vector<char> (m + 1));
  std::vector<char> answer(n + m - 2);

  for (int kI = 1; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < m + 1; ++kJ) {
      dp[kI][kJ] = std::max(dp[kI - 1][kJ], dp[kI][kJ - 1]) + table[kI][kJ];

      if (kI == 1 && kJ == 1) {
        route[kI][kJ] = 'F';
      } else if (dp[kI - 1][kJ] > dp[kI][kJ - 1] || kJ < 2) {
        dp[kI][kJ] = dp[kI - 1][kJ] + table[kI][kJ];
        route[kI][kJ] = 'D';
      } else {
        dp[kI][kJ] = dp[kI][kJ - 1] + table[kI][kJ];
        route[kI][kJ] = 'R';
      }
    }
  }

  int kI = n;
  int kJ  = m;
  while (route[kI][kJ] != 'F') {
    answer[kI + kJ - 3] = route[kI][kJ];

    if (route[kI][kJ] == 'D') {
      --kI;
    } else {
      --kJ;
    }
  }

  std::cout << dp[n][m] << std::endl;
  for (auto direction: answer) {
    std::cout << direction << " ";
  }
  return 0;
}
