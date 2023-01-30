#include <iostream>
#include <algorithm>
#include <vector>

bool check(const long long& numBr, const long long& c,
           const std::vector<long long>& array,
           const std::vector<long long>& sortArray,
           const long long& m)  {
  long long countBr = 0;

  for (long long kI = 0; kI < array.size(); ++kI) {
    if (array[kI] <= sortArray[m]) {
      ++countBr;
      kI += c - 1;
    }
  }

  return countBr >= numBr;
}

long long binarySearch(const long long& numBr, const long long& c,
                       const std::vector<long long>& array,
                       const std::vector<long long>& sortArray) {
  long long m;
  long long l = 0;
  long long r = sortArray.size() - 1;

  while (l < r) {
    m = (l + r) / 2;
    if (check(numBr, c, array, sortArray, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return sortArray[l];
}

int main() {
  long long n;
  long long numBr;
  long long c;

  std::cin >> n >> numBr >> c;
  std::vector<long long> height(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> height[kI];
  }

  std::sort(height.begin(), height.end());

  std::vector<long long> array(n - c + 1);
  std::vector<long long> sortArray(n - c + 1);
  for (int kI = 0; kI < array.size(); ++kI) {
    array[kI] = height[kI + c - 1] - height[kI];
    sortArray[kI] = array[kI];
  }

  std::sort(sortArray.begin(), sortArray.end());

  std::cout << binarySearch(numBr, c, array, sortArray) << std::endl;

  return 0;
}
