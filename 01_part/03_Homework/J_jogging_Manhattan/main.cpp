#include <iostream>
#include <vector>

int main() {
  int t;
  int d;
  int n;
  int x, y;

  std::cin >> t >> d >> n;

  int maxTxPlusY;
  int minTxPlusY;
  int maxTxMinusY;
  int minTxMinusY;

  int maxDxPlusY;
  int minDxPlusY;
  int maxDxMinusY;
  int minDxMinusY;

  maxTxPlusY = 0;
  minTxPlusY = 0;
  maxTxMinusY = 0;
  minTxMinusY = 0;

  for (int kI = 0; kI < n; ++kI) {
    std::cin >> x >> y;

    maxTxPlusY += t;
    minTxPlusY -= t;
    maxTxMinusY += t;
    minTxMinusY -= t;

    maxDxPlusY = x + y + d;
    minDxPlusY = x + y - d;
    maxDxMinusY = x - y + d;
    minDxMinusY = x - y - d;

    maxTxPlusY = std::min(maxDxPlusY, maxTxPlusY);
    minTxPlusY = std::max(minDxPlusY, minTxPlusY);

    maxTxMinusY = std::min(maxDxMinusY, maxTxMinusY);
    minTxMinusY = std::max(minDxMinusY, minTxMinusY);
  }

  std::pair<int, int> temp;
  std::vector<std::pair<int, int>> result;
  for (int plus = minTxPlusY; plus <= maxTxPlusY; ++plus) {
    for (int minus = minTxMinusY; minus <= maxTxMinusY; ++minus) {
      temp.first = plus + minus;
      if (temp.first % 2 == 0) {
        temp.first /= 2;
        temp.second = plus - temp.first;
        result.push_back(temp);
      }
    }
  }

  std::cout << result.size() << std::endl;
  for (auto dot: result) {
    std::cout << dot.first << " " << dot.second << std::endl;
  }

  return 0;
}