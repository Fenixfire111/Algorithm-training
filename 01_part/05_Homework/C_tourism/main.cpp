#include <iostream>
#include <vector>

int main() {
  int n;
  int x;
  int m;

  std::cin >> n;
  std::vector<int> y(n);
  std::vector<int> pre(n + 1);
  std::vector<int> post(n + 1);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x >> y[kI];
  }

  std::cin >> m;
  std::vector<std::pair<int, int>> trails(m);
  for (int kI = 0; kI < m; ++kI) {
    std::cin >> trails[kI].first >> trails[kI].second;
  }

  for (int kI = 2; kI <= n; ++kI) {
    if (y[kI - 1] - y[kI - 2] < 0) {
      pre[kI] = pre[kI - 1];
      post[kI] = post[kI - 1] + y[kI - 2] - y[kI - 1];
    } else {
      pre[kI] = pre[kI - 1] + y[kI - 1] - y[kI - 2];
      post[kI] = post[kI - 1];
    }
  }

  for (int kI = 0; kI < m; ++kI) {
    if ((trails[kI].second - trails[kI].first) > 0) {
      std::cout << pre[trails[kI].second] - pre[trails[kI].first] << std::endl;
    } else {
      std::cout << post[trails[kI].first] - post[trails[kI].second] << std::endl;
    }
  }

  return 0;
}
