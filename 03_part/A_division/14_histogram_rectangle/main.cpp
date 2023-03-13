#include <iostream>
#include <vector>
#include <stack>

struct newStruct {
  long long value = 0;
  long long minLeft = -1;
  long long minRight = -1;
};

int main() {
  long long n;
  std::stack<long long > stack;
  long long max = 0;

  std::cin >> n;
  std::vector<newStruct> histogram(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> histogram[kI].value;
  }

  for (long long kI = (long long)histogram.size() - 1; kI >= 0; --kI) {
    if (stack.empty()) {
      stack.push(kI);
    } else {
      if (histogram[kI].value >= histogram[stack.top()].value) {
        stack.push(kI);
      } else {
        while (histogram[kI].value < histogram[stack.top()].value) {
          histogram[stack.top()].minLeft = kI;
          stack.pop();

          if (stack.empty()) {
            break;
          }
        }
        stack.push(kI);
      }
    }
  }
  stack = std::stack<long long >();

  for (long long kI = 0; kI < histogram.size(); ++kI) {
    if (stack.empty()) {
      stack.push(kI);
    } else {
      if (histogram[kI].value >= histogram[stack.top()].value) {
        stack.push(kI);
      } else {
        while (histogram[kI].value < histogram[stack.top()].value) {
          histogram[stack.top()].minRight = kI;
          stack.pop();

          if (stack.empty()) {
            break;
          }
        }
        stack.push(kI);
      }
    }
  }

  for (long long kI = 0; kI < histogram.size(); ++kI) {
    if (histogram[kI].minRight == -1) {
      histogram[kI].minRight = n;
    }
    long long temp = (histogram[kI].minRight - 1 - histogram[kI].minLeft);
    if (histogram[kI].value * temp > max) {
      max = histogram[kI].value * temp;
    }
  }

  std::cout << max << std::endl;
  return 0;
}
