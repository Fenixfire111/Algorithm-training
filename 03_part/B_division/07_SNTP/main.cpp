#include <iostream>
#include <string>

int timeToSeconds(const std::string& time) {
  int result = std::stoi(time.substr(0,2)) * 3600;
  result += std::stoi(time.substr(3,5)) * 60;
  result += std::stoi(time.substr(6,8));

  return result;
}

std::string secondsToTime(int& seconds) {
  std::string time;

  int temp = seconds / 3600;
  if (temp > 23) {
    temp -= 24;
    seconds -= 24 * 3600;
  }
  if (temp < 10) {
    time += "0";
  }
  time += std::to_string(temp) + ":";
  seconds -= temp * 3600;

  temp = seconds / 60;
  if (temp < 10) {
    time += "0";
  }
  time += std::to_string(temp) + ":";
  seconds -= temp * 60;

  if (seconds < 10) {
    time += "0";
  }
  time += std::to_string(seconds);

  return time;
}

int main() {
  std::string firstClientTime;
  std::string serverTime;
  std::string secondClientTime;
//  std::string result;
  int firstSeconds;
  int secondSeconds;
  int serverSeconds;
  int interval;

  std::cin >> firstClientTime;
  std::cin >> serverTime;
  std::cin >> secondClientTime;

  firstSeconds = timeToSeconds(firstClientTime);
  secondSeconds = timeToSeconds(secondClientTime);
  if (secondSeconds < firstSeconds) {
    secondSeconds += 24 * 3600;
  }
  interval = secondSeconds - firstSeconds;
  if (interval % 2 == 0) {
    interval /= 2;
  } else {
    interval /= 2;
    ++interval;
  }

  serverSeconds = timeToSeconds(serverTime);
  serverSeconds += interval;


  std::cout << secondsToTime(serverSeconds) << std::endl;
  return 0;
}
