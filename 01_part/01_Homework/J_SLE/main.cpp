#include <iostream>

bool result(double b, double d, double a, double c,
            double e, double f, int par) {
  if (b == 0 && d == 0) {
    if (a != 0 && c != 0) {
      if (e/a == f/c) {
        std::cout << par << " " << e/a << std::endl;
        return true;
      } else {
        std::cout << 0 << std::endl;
        return true;
      }
    } else {
      if (a == 0 && c ==0 && e == 0 && f == 0) {
        std::cout << 5 << std::endl;
        return true;
      } else if ((a == 0 && e == 0) || (c == 0 && f == 0)){
        if (a + c == 0){
          std::cout << 0 << std::endl;
          return true;
        } else {
          std::cout << par << " " << (f+e)/(a+c) << std::endl;
          return true;
        }
      } else {
        std::cout << 0 << std::endl;
        return true;
      }
    }
  }

  return false;
}

int main() {
  double a, b, c, d, e, f;

  std::cin >> a >> b >> c >> d >> e >> f;

  if(!result(b, d, a, c, e, f, 3) && !result(a, c, b, d, e, f, 4)) {
    if (a * d == b * c) {
      if (a * f == c * e) {
        if (b != 0) {
          std::cout << 1 << " " << -a/b << " " << e/b << std::endl;
        } else {
          std::cout << 1 << " " << -c/d << " " << f/d << std::endl;
        }
      } else {
        std::cout << 0 << std::endl;
      }
    } else {
      double zn = a * d - b * c;
      std::cout << 2 << " " << (e * d - b * f)/zn << " " << (a * f - c * e)/zn << std::endl;
    }
  }

  return 0;
}
