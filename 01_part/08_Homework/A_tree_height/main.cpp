#include <iostream>
#include <vector>

struct ver {
  long long value = 0;
  long long leftSon = -1;
  long long rightSon = -1;
};

class BiTree {
 private:
  long long firstFree;
  long long height;
  std::vector<ver> array;

 public:
  explicit BiTree(const unsigned long long& maxSize){
    firstFree = 0;
    height = 0;
    array.resize(maxSize);
//    for (int kI = 0; kI < array.size(); ++kI) {
//      array[kI].leftSon = kI + 1;
//    }
  }

  long long returnHeight() const {
    return height;
  }
  int createNewNode(const long long& value) {
    array[firstFree].value = value;
    ++firstFree;
    return firstFree - 1;
  }

  void addNode(const long long& value, const long long& root, long long& currLevel) {
    if (firstFree == 0) {
      createNewNode(value);
      ++height;
    } else {
      if (value < array[root].value) {
        if (array[root].leftSon == -1) {
          array[root].leftSon = createNewNode(value);
          if (currLevel + 1 > height) {
            height = currLevel + 1;
          }
        } else {
          ++currLevel;
          addNode(value, array[root].leftSon, currLevel);
        }
      } else if (value > array[root].value){
        if (array[root].rightSon == -1) {
          array[root].rightSon = createNewNode(value);
          if (currLevel + 1 > height) {
            height = currLevel + 1;
          }
        } else {
          ++currLevel;
          addNode(value, array[root].rightSon, currLevel);
        }
      }
    }
  }

};

//std::vector<ver> initMemory(const unsigned int& maxSize) {
//  std::vector<ver> tree(maxSize);
//  for (int kI = 0; kI < tree.size(); ++kI) {
//    tree[kI].leftSon = kI + 1;
//  }
//
//  return tree;
//}

int main() {
  long long num;
  std::vector<long long> numbers;

  std::cin >> num;
  while (num != 0) {
    numbers.push_back(num);
    std::cin >> num;
  }

  BiTree myTree(numbers.size());

  long long currLevel;
  for (auto newVal: numbers) {
    currLevel = 1;
    myTree.addNode(newVal, 0, currLevel);
  }

  std::cout << myTree.returnHeight() << std::endl;
  return 0;
}
