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

    while (pos > 0 && array[pos] < array[(pos - 1) / 2]) {
      std::swap(array[pos], array[(pos - 1) / 2]);

      pos = (pos - 1) / 2;
    }
  }

  int extract() {
    int result = array.front();
    array[0] = array[array.size() - 1];

    int pos = 0;
    while ((2 * pos + 2) < array.size()) {
      int minSon = 2 * pos + 1;
      if (array[minSon] > array[2 * pos + 2]) {
        minSon = 2 * pos + 2;
      }
      if (array[pos] > array[minSon]) {
        std::swap(array[pos], array[minSon]);
      } else {
        break;
      }

      pos = minSon;
    }

    array.pop_back();
    return result;
  }

};

int main() {
  int n;
  int tempVal;
  Heap myHeap;

  std::cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> tempVal;
    myHeap.insert(tempVal);
  }

  for (int kI = n - 1; kI >= 0; --kI) {
    std::cout << myHeap.extract() << " ";
  }
  return 0;
}
