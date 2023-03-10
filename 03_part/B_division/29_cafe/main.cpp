#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> result;
  std::pair<int, int> min(0, 0);

  std::cin >> n;

  if (n == 0) {
    std::cout << 0 << std::endl;
    std::cout << 0 << " " << 0 << std::endl;
    return 0;
  }

  std::vector<int> prices(n + 1);
  for (int kI = 1; kI < n + 1; ++kI) {
    std::cin >> prices[kI];
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 3));

  for (int kI = 0; kI < n + 1; ++kI) {
    dp[kI][0] = 100000;
    dp[0][kI] = 100000;
    dp[1][kI] = 100000;
    dp[kI][n + 1] = 100000;
    dp[kI][n + 2] = 100000;
  }
  if (prices[1] > 100) {
    dp[1][2] = prices[1];
  } else {
    dp[1][1] = prices[1];
  }


  for (int kI = 2; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < n + 2; ++kJ) {
      if (prices[kI] > 100) {
        dp[kI][kJ] = std::min(dp[kI - 1][kJ - 1],
                              std::min(dp[kI - 1][kJ], dp[kI - 1][kJ + 1] - prices[kI])) + prices[kI];
      } else {
        dp[kI][kJ] =  std::min(dp[kI - 1][kJ], dp[kI - 1][kJ + 1] - prices[kI]) + prices[kI];
      }
    }
  }

  for (int kI = 1; kI < n + 2; ++kI) {
    if (dp[n][kI] <= dp[n][min.second]) {
      min.first = n;
      if (min.second < kI) {
        min.second = kI;
      }
    }
  }

  int iterator = min.second;
  for (int kI = n; kI > 0 ; --kI) {
    if (dp[kI][iterator] == dp[kI - 1][iterator + 1]) {
      result.push_back(kI);
      ++iterator;
    } else {
      if (prices[kI] > 100) {
        --iterator;
      }
    }
  }

  std::cout << dp[min.first][min.second] << std::endl;
  std::cout << min.second - 1 << " " << result.size() << std::endl;
  for (int kI = (int)result.size() - 1; kI >= 0 ; --kI) {
    std::cout << result[kI] << std::endl;
  }
  return 0;
}
