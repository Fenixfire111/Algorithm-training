#include <iostream>
#include <string>

int main() {
  int a, b, c;
  std::string result = "NO";

  std::cin >> a >> b >> c;

  if (a < b + c)
  {
    if (b < a + c)
    {
      if (c < b + a)
      {
        result = "YES";
      }
    }
  }

  std::cout << result << std::endl;
  return 0;
}
