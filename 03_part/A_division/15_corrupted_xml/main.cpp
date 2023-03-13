#include <iostream>
#include <stack>

bool checkBrackets(std::string& tag, std::stack<std::string>& brackets, bool& endBracket) {
  if (endBracket) {
    endBracket = false;
    if (brackets.empty()) {
      return false;
    } else {
      std::string lastTag = brackets.top();
      std::string temp = "<";
      temp += tag.substr(2,tag.size());

      if (lastTag == temp) {
        brackets.pop();
        return true;
      } else {
        return false;
      }
    }
  } else {
    brackets.push(tag);
    return true;
  }

}

bool check(const std::string& xml) {
  std::stack<std::string> brackets;
  std::string tag;
  bool endBracket = false;
  for (auto symbol: xml) {

    if (tag.empty()) {
      if (symbol == '<') {
        tag.push_back(symbol);
      } else {
        return false;
      }
    } else {
      if (tag.back() == '<') {
        if (std::isalpha(symbol)) {
          tag.push_back(symbol);
        } else if (symbol == '/') {
          endBracket = true;
          tag.push_back(symbol);
        } else {
          return false;
        }
      } else if (std::isalpha(tag.back())) {
        if (std::isalpha(symbol)) {
          tag.push_back(symbol);
        } else if (symbol == '>') {
          tag.push_back(symbol);

          if (!checkBrackets(tag, brackets, endBracket)) {
            return false;
          }
          tag.clear();
        } else {
          return false;
        }
      } else if (tag.back() == '/') {
        if (std::isalpha(symbol)) {
          tag.push_back(symbol);
        } else {
          return false;
        }
      }
    }


  }

  if (brackets.empty()) {
    return true;
  } else {
    return false;
  }

}

int main() {
  std::string xml;
  std::string copyXml;

  std::cin >> xml;
  copyXml = xml;

  for (int kI = 0; kI < xml.size(); ++kI) {
    char lim = 'z' + 1;
    for (char sym = 'a'; sym < lim; ++sym) {
      xml = copyXml;
      xml[kI] = sym;
      if (check(xml)) {
        std::cout << xml;
        return 0;
      }
    }

    xml = copyXml;
    xml[kI] = '/';
    if (check(xml)) {
      std::cout << xml;
      return 0;
    }

    xml = copyXml;
    xml[kI] = '>';
    if (check(xml)) {
      std::cout << xml;
      return 0;
    }

    xml = copyXml;
    xml[kI] = '<';
    if (check(xml)) {
      std::cout << xml;
      return 0;
    }
  }

  return 0;
}
