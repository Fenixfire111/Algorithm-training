#include <iostream>
#include <vector>

int main() {
  int n;
  int m;
  std::vector<int> answer;

  std::cin >> n;
  std::vector<int> firstSeq(n + 1);
  for (int kI = 1; kI < n + 1; ++kI) {
    std::cin >> firstSeq[kI];
  }
  std::cin >> m;
  std::vector<int> secondSeq(m + 1);
  for (int kI = 1; kI < m + 1; ++kI) {
    std::cin >> secondSeq[kI];
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

  for (int kI = 1; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < m + 1; ++kJ) {
      if (firstSeq[kI] == secondSeq[kJ]) {
        dp[kI][kJ] = dp[kI - 1][kJ - 1] + 1;
      } else {
        if (dp[kI - 1][kJ] > dp[kI][kJ - 1]) {
          dp[kI][kJ] = dp[kI - 1][kJ];
        } else {
          dp[kI][kJ] = dp[kI][kJ - 1];
        }
      }

    }
  }

  int kI = n;
  int kJ = m;
  while (kI > 0 && kJ > 0) {
    if (dp[kI][kJ] == dp[kI - 1][kJ]) {
      --kI;
    } else if (dp[kI][kJ] == dp[kI][kJ - 1]) {
      --kJ;
    } else {
      answer.push_back(firstSeq[kI]);
      --kI;
      --kJ;
    }
  }

  for (int k = (int)answer.size() - 1; k >= 0; --k) {
    std::cout << answer[k] << " ";
  }
  return 0;
}
