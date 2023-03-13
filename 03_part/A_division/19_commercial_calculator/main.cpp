#include <iostream>
#include <queue>
#include <iomanip>

int main() {
  int n;
  double temp;
  double result = 0;
  std::priority_queue<double, std::vector<double>, std::greater<>> priority_queue;

  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> temp;
    priority_queue.push(temp);
  }

  while (priority_queue.size() > 1) {
    double sum = 0;
    sum += priority_queue.top();
    priority_queue.pop();
    sum += priority_queue.top();
    priority_queue.pop();

    result += sum * 0.05;
    priority_queue.push(sum);
  }

  std::cout << std::fixed << std::setprecision(2) << result << std::endl;
  return 0;
}