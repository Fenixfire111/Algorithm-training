#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;

  std::cin >> n;
  std::vector<int> dist(n + 1);
  for (int kI = 1; kI < dist.size(); ++kI) {
    std::cin >> dist[kI];
  }
  std::sort(dist.begin(), dist.end());

  std::vector<int> dp(n + 1);
  dp[2] = dist[2] - dist[1];
  dp[3] = dp[2] + dist[3] - dist[2];
  for (int kI = 4; kI < dp.size(); ++kI) {
    dp[kI] = std::min(dist[kI] - dist[kI - 1] + dp[kI - 2], dist[kI] - dist[kI - 1] + dp[kI - 1]);
  }

  std::cout << dp[n] << std::endl;
  return 0;
}
