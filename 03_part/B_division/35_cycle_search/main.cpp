#include <iostream>
#include <vector>
#include <deque>

bool flag = false;

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<int>& peaks, const int& currPeak, const int& prePeak, std::deque<int>& result) {
  if (peaks[currPeak] == 0) {
    peaks[currPeak] = 1;
    if (!flag) {
      result.push_back(currPeak);
    }
  }

  for (const auto& peak: graph[currPeak]) {
    if (peaks[peak] == 0) {
      dfs(graph, peaks, peak, currPeak, result);
    } else if (peaks[peak] == 1 && peak != prePeak && prePeak != 0 && !flag) {
      flag = true;
      while (peak != result.front()) {
        result.pop_front();
      }
      return;
    }
  }

  if (!flag) {
    result.pop_back();
  }

}

int main() {
  int n;
  int temp;

  std::cin >> n;
  std::vector<int> peaks(n + 1);
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (int kI = 1; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < n + 1; ++kJ) {
      std::cin >> temp;
      if (temp) {
        graph[kI].push_back(kJ);
      }
    }
  }

  for (int kI = 1; kI < peaks.size(); ++kI) {
    std::deque<int> cycle;
    dfs(graph, peaks, kI, 0, cycle);

    if (flag) {
      std::cout << "YES" << std::endl;
      std::cout << cycle.size() << std::endl;
      while (!cycle.empty()){
        std::cout << cycle.front() << " ";
        cycle.pop_front();
      }
      return 0;
    }
  }

  if (!flag) {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
