#include <iostream>
#include <queue>

int main() {
  int tempVal;
  std::queue<int> player1;
  std::queue<int> player2;

  for (int kI = 0; kI < 5; ++kI) {
    std::cin >> tempVal;
    player1.push(tempVal);
  }
  for (int kI = 0; kI < 5; ++kI) {
    std::cin >> tempVal;
    player2.push(tempVal);
  }

  for (int kI = 0; kI < 1000000; ++kI) {
    if ((player1.front() > player2.front() || (player1.front() == 0 && player2.front() == 9))
    && (player1.front() != 9 || player2.front() != 0)) {
      player1.push(player1.front());
      player1.pop();
      player1.push(player2.front());
      player2.pop();
    } else {
      player2.push(player1.front());
      player1.pop();
      player2.push(player2.front());
      player2.pop();
    }

    if (player1.empty()) {
      std::cout << "second " << kI + 1 << std::endl;
      return 0;
    } else if (player2.empty()){
      std::cout << "first " << kI + 1 << std::endl;
      return 0;
    }
  }

  std::cout << "botva" << std::endl;
  return 0;
}
