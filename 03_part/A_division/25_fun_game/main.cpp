#include <iostream>
#include <vector>

int main() {
  int n;
  int a;
  int b;

  std::cin >> n;
  std::cin >> a;
  std::cin >> b;

  std::vector<int> dp(n + 1);

  for (int kI = 2; kI < n + 1; ++kI) {
    int min = INT32_MAX;
    for (int kJ = 1; kJ < kI; ++kJ) {
      min = std::min(min, std::max(a + dp[kJ], b + dp[kI - kJ]));
    }
    dp[kI] = min;
  }

  std::cout << dp[n] << std::endl;
  return 0;
}
