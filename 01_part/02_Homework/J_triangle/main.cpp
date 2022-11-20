#include <iostream>
#include <iomanip>

int main() {
  int number;
  double x1, x2;
  double bottomLine = 30;
  double upperLine = 4000;
  std::string status;

  std::cin >> number;

  std::cin >> x1;
  for (int kI = 1; kI < number; ++kI) {
    std::cin >> x2 >> status;

    if (x1 < x2) {
      if (status == "closer") {
        if ((x1 + x2) / 2 > bottomLine) {
          bottomLine = (x1 + x2) / 2;
        }
      } else {
        if ((x1 + x2) / 2 < upperLine) {
          upperLine = (x1 + x2) / 2;
        }
      }
    } else if (x1 > x2) {
      if (status == "closer") {
        if ((x1 + x2) / 2 < upperLine) {
          upperLine = (x1 + x2) / 2;
        }
      } else {
        if ((x1 + x2) / 2 > bottomLine) {
          bottomLine = (x1 + x2) / 2;
        }
      }
    }
    x1 = x2;
  }

  std::cout << std::setprecision(8) << bottomLine << " " << upperLine << std::endl;
  return 0;
}
