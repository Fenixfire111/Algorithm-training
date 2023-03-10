#include <iostream>
#include <vector>

int main() {
  int n;

  std::cin >> n;

  std::vector<int> dp(n + 1);
  std::vector<int> result(n + 1);
  std::vector<int> answer;

  dp[1] = 0;
  result[1] = 0;
  for (int kI = 2; kI < dp.size(); ++kI) {
    if (kI % 3 == 0) {
      dp[kI] = dp[kI / 3] + 1;
      result[kI] = kI / 3;
    }
    if (kI % 2 == 0) {
      if (dp[kI] == 0 || dp[kI] > dp[kI / 2] + 1) {
        dp[kI] = dp[kI / 2] + 1;
        result[kI] = kI / 2;
      }
    }
    if (dp[kI] == 0 || dp[kI] > dp[kI - 1] + 1) {
      dp[kI] = dp[kI - 1] + 1;
      result[kI] = kI - 1;
    }
  }

  int currNumber = n;
  while (currNumber > 0) {
    answer.push_back(currNumber);
    currNumber = result[currNumber];
  }

  std::cout << dp[n] << std::endl;
  for (int kI = answer.size() - 1; kI >= 0 ; --kI) {
    std::cout << answer[kI] << " ";
  }
  return 0;
}
