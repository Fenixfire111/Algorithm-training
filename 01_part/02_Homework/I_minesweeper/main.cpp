#include <iostream>
#include <vector>

int main() {
  int n;
  int m;
  int k;
  int line, column;
  int startLine, startColumn;
  int endLine, endColumn;

  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> field(n, std::vector<int>(m));

  for (int kI = 0; kI < k; ++kI) {
    std::cin >> line >> column;
    field[line - 1][column - 1] = -1;
  }

  for (int kI = 0; kI < n; ++kI) {
    if (kI == 0) {
      startLine = 0;
    } else {
      startLine = -1;
    }

    if (kI == n - 1) {
      endLine = 1;
    } else {
      endLine = 2;
    }
    for (int kJ = 0; kJ < m; ++kJ) {
      if (kJ == 0) {
        startColumn = 0;
      } else {
        startColumn = -1;
      }

      if (kJ == m - 1) {
        endColumn = 1;
      } else {
        endColumn = 2;
      }

      if (field[kI][kJ] != -1) {
        for (int kL = startLine; kL < endLine; ++kL) {
          for (int kM = startColumn; kM < endColumn; ++kM) {
            if (field[kI + kL][kJ + kM] == -1) {
              ++field[kI][kJ];
            }
          }
        }
      }

    }
  }

  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < m; ++kJ) {
      if (field[kI][kJ] == -1) {
        std::cout << "* ";
      } else {
        std::cout << field[kI][kJ] << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
