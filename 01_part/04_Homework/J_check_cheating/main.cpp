#include <iostream>
#include <map>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <vector>
int main() {
  int n;
  std::string c;
  std::string d;
  std::unordered_set<std::string> keyWords;
  std::map<std::string, long long> identifiers;
  std::string word;
  std::fstream input("input.txt");
  std::string line;
  long long max = 0;
  int place = 1;
  std::vector<std::string> maxWords;
  std::map<std::string, int> places;
  bool noLiter = false;

  if (input.is_open()) {
    input >> n >> c >> d;
    ///only all words
    if (c == "yes") {
      ///c yes
      if (d == "yes") {
        /// d yes
        for (int kI = 0; kI < n; ++kI) {
          input >> word;
          keyWords.insert(word);
        }

        word.clear();
        while (getline(input, line)) {
          for (char sym : line) {
            if ((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z') ||
                (sym >= '0' && sym <= '9') || (sym == '_')) {
              if (!(sym >= '0' && sym <= '9')){
                noLiter = true;
              }
              word += sym;
            } else {
              if (!keyWords.count(word)) {
                if (noLiter) {
                  ++identifiers[word];
                  if (!places.count(word)){
                    places[word] = place;
                    ++place;
                  }
                  if (max < identifiers[word] && (!word.empty())) {
                    max = identifiers[word];
                    maxWords.clear();
                    maxWords.push_back(word);
                  } else if (max == identifiers[word] && (!word.empty())) {
                    maxWords.push_back(word);
                  }
                }
              }
              word.clear();
              noLiter = false;
            }
          }
          if (!keyWords.count(word)) {
            if (noLiter) {
              ++identifiers[word];
              if (!places.count(word)){
                places[word] = place;
                ++place;
              }
              if (max < identifiers[word] && (!word.empty())) {
                max = identifiers[word];
                maxWords.clear();
                maxWords.push_back(word);
              } else if (max == identifiers[word] && (!word.empty())) {
                maxWords.push_back(word);
              }
            }
          }
          word.clear();
          noLiter = false;
        }
      } else {
        /// d no
        for (int kI = 0; kI < n; ++kI) {
          input >> word;
          keyWords.insert(word);
        }

        word.clear();
        while (getline(input, line)) {
          for (int kI = 0; kI < line.size(); ++kI) {
            char sym = line[kI];
            if ((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z') ||
                (sym >= '0' && sym <= '9') || (sym == '_')) {
              if (!(sym >= '0' && sym <= '9')) {
                word += sym;
              } else {
                if (!word.empty()) {
                  word += sym;
                } else {
                  int temp = kI + 1;
                  while ((line[temp] >= 'A' && line[temp] <= 'Z') ||
                  (line[temp] >= 'a' && line[temp] <= 'z') ||
                  (line[temp] >= '0' && line[temp] <= '9') || (line[temp] == '_')) {
                    ++temp;
                  }
                  kI = temp - 1;
                  continue;
                }
              }
            } else {
              if (!keyWords.count(word)) {
                ++identifiers[word];
                if (!places.count(word)){
                  places[word] = place;
                  ++place;
                }
                if (max < identifiers[word] && (!word.empty())) {
                  max = identifiers[word];
                  maxWords.clear();
                  maxWords.push_back(word);
                } else if (max == identifiers[word] && (!word.empty())) {
                  maxWords.push_back(word);
                }
              }
              word.clear();
            }
          }
          if (!keyWords.count(word)) {
            ++identifiers[word];
            if (!places.count(word)){
              places[word] = place;
              ++place;
            }
            if (max < identifiers[word] && (!word.empty())) {
              max = identifiers[word];
              maxWords.clear();
              maxWords.push_back(word);
            } else if (max == identifiers[word] && (!word.empty())) {
              maxWords.push_back(word);
            }
          }
          word.clear();
        }
      }

    } else {
      /// c no
      if (d == "yes") {
        /// d yes
        for (int kI = 0; kI < n; ++kI) {
          input >> word;
          std::transform(word.begin(), word.end(), word.begin(), tolower);
          keyWords.insert(word);
        }

        word.clear();
        while (getline(input, line)) {
          for (char sym : line) {
            sym = (char)tolower(sym);
            if ((sym >= 'a' && sym <= 'z') ||
                (sym >= '0' && sym <= '9') || (sym == '_')) {
              if (!(sym >= '0' && sym <= '9')){
                noLiter = true;
              }
              word += sym;
            } else {
              if (!keyWords.count(word)) {
                if (noLiter) {
                  ++identifiers[word];
                  if (!places.count(word)){
                    places[word] = place;
                    ++place;
                  }
                  if (max < identifiers[word] && (!word.empty())) {
                    max = identifiers[word];
                    maxWords.clear();
                    maxWords.push_back(word);
                  } else if (max == identifiers[word] && (!word.empty())) {
                    maxWords.push_back(word);
                  }
                }

              }
              noLiter = false;
              word.clear();
            }
          }
          if (!keyWords.count(word)) {
            if (!keyWords.count(word)) {
              ++identifiers[word];
              if (!places.count(word)){
                places[word] = place;
                ++place;
              }
              if (max < identifiers[word] && (!word.empty())) {
                max = identifiers[word];
                maxWords.clear();
                maxWords.push_back(word);
              } else if (max == identifiers[word] && (!word.empty())) {
                maxWords.push_back(word);
              }
            }
          }
          word.clear();
          noLiter = false;
        }
      } else {
        /// d no
        for (int kI = 0; kI < n; ++kI) {
          input >> word;
          std::transform(word.begin(), word.end(), word.begin(), tolower);
          keyWords.insert(word);
        }

        word.clear();
        while (getline(input, line)) {
          for (int kI = 0; kI < line.size(); ++kI) {
            char sym = line[kI];
            sym = (char)tolower(sym);
            if ((sym >= 'a' && sym <= 'z') ||
                (sym >= '0' && sym <= '9') || (sym == '_')) {
              if (!(sym >= '0' && sym <= '9')) {
                word += sym;
              } else {
                if (!word.empty()) {
                  word += sym;
                } else {
                  int temp = kI + 1;
                  while ((line[temp] >= 'A' && line[temp] <= 'Z') ||
                      (line[temp] >= 'a' && line[temp] <= 'z') ||
                      (line[temp] >= '0' && line[temp] <= '9') || (line[temp] == '_')) {
                    ++temp;
                  }
                  kI = temp - 1;
                  continue;
                }
              }
            } else {
              if (!keyWords.count(word)) {
                ++identifiers[word];
                if (!places.count(word)){
                  places[word] = place;
                  ++place;
                }
                if (max < identifiers[word] && (!word.empty())) {
                  max = identifiers[word];
                  maxWords.clear();
                  maxWords.push_back(word);
                } else if (max == identifiers[word] && (!word.empty())) {
                  maxWords.push_back(word);
                }
              }
              word.clear();
            }
          }
          if (!keyWords.count(word)) {
            ++identifiers[word];
            if (!places.count(word)){
              places[word] = place;
              ++place;
            }
            if (max < identifiers[word] && (!word.empty())) {
              max = identifiers[word];
              maxWords.clear();
              maxWords.push_back(word);
            } else if (max == identifiers[word] && (!word.empty())) {
              maxWords.push_back(word);
            }
          }
          word.clear();
        }
      }

    }


  }

  int ran = -1;
  std::string itog;
  for (const auto& wword: maxWords) {
    if (ran < 0 || ran > places[wword]) {
      ran = places[wword];
      itog = wword;
    }
  }
  std::cout << itog << std::endl;
  return 0;
}
