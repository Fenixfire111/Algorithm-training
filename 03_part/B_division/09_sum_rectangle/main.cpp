#include <iostream>
#include <vector>

int main() {
  int k;
  int n;
  int m;
  long long tempVal;
  int x1;
  int y1;
  int x2;
  int y2;

  std::cin >> n >> m >> k;
  std::vector<std::vector<long long>> matrix(n, std::vector<long long >(m));
  std::vector<std::vector<long long>> sumLines(n + 1, std::vector<long long >(m + 1));

  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < m; ++kJ) {
      std::cin >> tempVal;
      matrix[kI][kJ] = tempVal;

      sumLines[kI + 1][kJ + 1] = sumLines[kI][kJ + 1] + sumLines[kI + 1][kJ]
          - sumLines[kI][kJ] + matrix[kI][kJ];
    }
  }

  for (int kI = 0; kI < k; ++kI) {
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << sumLines[x2][y2] - sumLines[x1 - 1][y2] - sumLines[x2][y1 - 1]
    + sumLines[x1 - 1][y1 - 1] << std::endl;
  }

  return 0;
}
