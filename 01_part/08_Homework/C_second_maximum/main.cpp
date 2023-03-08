#include <iostream>
#include <vector>

struct ver {
  int value = 0;
  int leftSon = -1;
  int rightSon = -1;
};

class BiTree {
 private:
  int firstFree;
  std::vector<ver> array;

 public:
  explicit BiTree(const unsigned int& maxSize){
    firstFree = 0;
    array.resize(maxSize);
  }

  int createNewNode(const int& value) {
    array[firstFree].value = value;
    ++firstFree;
    return firstFree - 1;
  }

  void addNode(const int& value, const int& root) {
    if (firstFree == 0) {
      createNewNode(value);
    } else {
      if (value < array[root].value) {
        if (array[root].leftSon == -1) {
          array[root].leftSon = createNewNode(value);
        } else {
          addNode(value, array[root].leftSon);
        }
      } else if (value > array[root].value){
        if (array[root].rightSon == -1) {
          array[root].rightSon = createNewNode(value);
        } else {
          addNode(value, array[root].rightSon);
        }
      } else {

      }
    }

  }

  void secondMax(const int& node, const int& dad, int& secMax) {
    if (array[node].rightSon != -1) {
      secondMax(array[node].rightSon, node, secMax);
    } else if (array[node].leftSon != -1) {
      if (array[array[node].leftSon].rightSon == -1) {
        secMax = array[array[node].leftSon].value;
      } else {
        secondMax(array[node].rightSon, node, secMax);
      }
    } else {
      secMax = array[dad].value;
    }

  }

};

int main() {
  int num;
  int max = 0;
  int max2 = 0;
  std::vector<int> numbers;

  std::cin >> num;
  while (num != 0) {
    numbers.push_back(num);
    if (num > max) {
      max = num;
    }
    std::cin >> num;
  }

  for (int kI = 0; kI < numbers.size(); ++kI) {
    if (numbers[kI] > max2 && numbers[kI] != max) {
      max2 = numbers[kI];
    }
  }

  std::cout << max2 << std::endl;

  return 0;
}
