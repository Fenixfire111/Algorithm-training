#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

std::set<int> fullSet(std::ifstream &in, std::set<int> &set) {
  int x;
  std::string line;
  std::stringstream ss;
  getline(in, line);
  ss << line;
  while (ss >> x) {
    set.insert(x);
  }

  return set;
}

int main() {
  std::set<int> set1;
  std::set<int> set2;

  std::ifstream in("input.txt"); // окрываем файл для чтения
  if (in.is_open())
  {
    set1 = fullSet(in, set1);
    set2 = fullSet(in, set2);
  } else {
    std::cout << "Error" << std::endl;
  }
  in.close();

  std::ofstream out("output.txt");
  if (out.is_open()) {
    for (int x: set1) {
      if (set2.count(x)) {
        out << x << " ";
      }
    }
  }
  out.close();

  return 0;
}
