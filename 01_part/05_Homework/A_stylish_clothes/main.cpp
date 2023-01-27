#include <iostream>
#include <vector>
#include <cmath>

int main() {
  long long n;
  long long m;
  long long numberTShirt = 0;
  long long numberPants = 0;
  long long minDiff;
  long long previousDiff;
  long long currentDiff;
  long long minNumberTShirt = 0;
  long long minNumberPants = 0;
  bool transition = false;

  std::cin >> n;
  std::vector<long long> tShirts(n);
  for (long long kI = 0; kI < n; ++kI) {
    std::cin >> tShirts[kI];
  }

  std::cin >> m;
  std::vector<long long> pants(m);
  for (long long kI = 0; kI < m; ++kI) {
    std::cin >> pants[kI];
  }

  currentDiff = previousDiff = minDiff = std::abs(tShirts[0] - pants[0]);
  while ((numberPants < m - 1 || numberTShirt < n - 1) && minDiff != 0) {
    if ((transition || currentDiff <= previousDiff || numberTShirt >= n - 1) && numberPants < m - 1) {
      ++numberPants;
      transition = false;
    } else {
      transition = true;
      ++numberTShirt;
      if (numberPants > 0) {
        --numberPants;
      }
    }
    previousDiff = currentDiff;
    currentDiff = std::abs(tShirts[numberTShirt] - pants[numberPants]);

    if (currentDiff < minDiff) {
      minDiff = currentDiff;
      minNumberPants = numberPants;
      minNumberTShirt = numberTShirt;
    }

  }

  std::cout << tShirts[minNumberTShirt] << " " << pants[minNumberPants] << std::endl;
  return 0;
}
