#include <iostream>
#include <vector>

struct times {
  int a;
  int b;
  int c;
};

int main() {
  int n;

  std::cin >> n;
  std::vector<times> table(n + 1);
  for (int kI = 1; kI < table.size(); ++kI) {
    std::cin >> table[kI].a >> table[kI].b >> table[kI].c;
  }

  std::vector<int> dp(n + 1);

  dp[1] = table[1].a;
  dp[2] = std::min(dp[1] + table[2].a, table[1].b);
//  dp[3] = std::min(dp[2] + table[3].a, std::min(dp[1] + table[2].b, table[1].c));

  for (int kI = 3; kI < dp.size(); ++kI) {
    dp[kI] = std::min(dp[kI - 1] + table[kI].a, std::min(dp[kI - 2] + table[kI - 1].b, dp[kI - 3] + table[kI - 2].c));
  }

  std::cout << dp[n] << std::endl;
  return 0;
}
