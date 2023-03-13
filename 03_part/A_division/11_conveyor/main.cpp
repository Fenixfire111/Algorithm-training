#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int main() {
  int n;
  int k;

  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    bool flag = true;
    std::cin >> k;
    std::vector<double> sortArray(k);
    std::stack<double> stackF;
    std::stack<double> stock;

    for (int kJ = 0; kJ < k; ++kJ) {
      std::cin >> sortArray[kJ];
    }
    for (int kJ = (int)sortArray.size() - 1; kJ >= 0 ; --kJ) {
      stackF.push(sortArray[kJ]);
    }
    int iter = 0;
    std::sort(sortArray.begin(), sortArray.end());
    while (!stackF.empty()) {
      if (stackF.top() == sortArray[iter]) {
        stackF.pop();
        ++iter;
      } else if (!stock.empty()) {
        if (stock.top() == sortArray[iter]) {
          stock.pop();
          ++iter;
        } else {
          stock.push(stackF.top());
          stackF.pop();
        }
      } else {
        stock.push(stackF.top());
        stackF.pop();
      }
    }

    while (!stock.empty()) {
      if (stock.top() == sortArray[iter]) {
        stock.pop();
        ++iter;
      } else {
        flag = false;
        break;
      }
    }

    if (flag) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }

  }

  return 0;
}
