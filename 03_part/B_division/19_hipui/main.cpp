#include <iostream>
#include <vector>

class Heap {
 private:
  std::vector<int> array;
 public:
  Heap() = default;

  void insert(const int value) {
    array.push_back(value);
    unsigned int pos = array.size() - 1;

    while (pos > 0 && array[pos] > array[(pos - 1) / 2]) {
      std::swap(array[pos], array[(pos - 1) / 2]);

      pos = (pos - 1) / 2;
    }
  }

  int extract() {
    int result = array.front();
    array[0] = array[array.size() - 1];

    int pos = 0;
    while ((2 * pos + 2) < array.size()) {
      int maxSon = 2 * pos + 1;
      if (array[maxSon] < array[2 * pos + 2]) {
        maxSon = 2 * pos + 2;
      }
      if (array[pos] < array[maxSon]) {
        std::swap(array[pos], array[maxSon]);
      } else {
        break;
      }

      pos = maxSon;
    }

    array.pop_back();
    return result;
  }

};

int main() {
  int n;
  int request;
  int number;
  Heap myHeap;

  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> request;

    if (request == 0) {
      std::cin >> number;
      myHeap.insert(number);
    } else {
      std::cout << myHeap.extract() << std::endl;
    }
  }

  return 0;
}
