#include <iostream>
#include <string>
int main() {
  int roomTemperature, conditionerTemperature;
  std::string mode;

  std::cin >> roomTemperature >> conditionerTemperature;
  std::cin >> mode;

  if (mode == "fan")
  {
    std::cout << roomTemperature << std::endl;
  }
  else if (mode == "auto")
  {
    std::cout << conditionerTemperature << std::endl;
  }
  else if (mode == "freeze")
  {
    if (roomTemperature <= conditionerTemperature)
    {
      std::cout << roomTemperature << std::endl;
    }
    else
    {
      std::cout << conditionerTemperature << std::endl;
    }
  }
  else if (mode == "heat")
  {
    if (roomTemperature <= conditionerTemperature)
    {
      std::cout << conditionerTemperature << std::endl;
    }
    else
    {
      std::cout << roomTemperature << std::endl;
    }
  }
  return 0;
}
