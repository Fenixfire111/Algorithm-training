#include <iostream>
#include <set>
#include <fstream>
#include <vector>

int main() {
  int n, m;
  int temp;
  std::set<int> setBora;
  std::set<int> setAna;
  std::vector<int> array;

  std::ifstream in("input.txt");
  if (in.is_open()) {
    in >> n;
    in >> m;
    for (int kI = 0; kI < n; ++kI) {
      in >> temp;
      setAna.insert(temp);
    }
    for (int kI = 0; kI < m; ++kI) {
      in >> temp;
      setBora.insert(temp);
    }
  }
  in.close();

  for (int x: setAna) {
    if (setBora.count(x)) {
      array.push_back(x);
      setBora.erase(x);
    }
  }
  for (int x: array) {
    setAna.erase(x);
  }

  std::ofstream out("output.txt");
  if (out.is_open()) {
    out << array.size() << std::endl;
    for (int x: array) {
      out << x << " ";
    }
    out << std::endl;

    out << setAna.size() << std::endl;
    for (int x: setAna) {
      out << x << " ";
    }
    out << std::endl;

    out << setBora.size() << std::endl;
    for (int x: setBora) {
      out << x << " ";
    }
    out << std::endl;
  }

  return 0;
}
