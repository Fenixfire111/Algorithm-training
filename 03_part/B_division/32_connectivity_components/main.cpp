#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<bool>& peaks, const int& currPeak,
         std::vector<int>& component) {
  if (!peaks[currPeak]) {
    component.push_back(currPeak);
  } else {
    return;
  }
  peaks[currPeak] = true;

  for (const auto& peak: graph[currPeak]) {
    if (!peaks[peak]) {
      dfs(graph, peaks, peak, component);
    }
  }
}

int main() {
  int n;
  int m;
//  int countPeaks = 0;
//  int numberComponents = 0;
  std::pair<int, int> temp;
  std::vector<std::vector<int>> components;

  std::cin >> n >> m;
  std::vector<bool> peaks(n + 1);
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (int kI = 0; kI < m; ++kI) {
    std::cin >> temp.first >> temp.second;
    if (temp.first != temp.second) {
      graph[temp.first].push_back(temp.second);
      graph[temp.second].push_back(temp.first);
    }
  }

  for (int kI = 1; kI < peaks.size(); ++kI) {
    std::vector<int> currComponent;
    dfs(graph, peaks, kI, currComponent);

    if (!currComponent.empty()) {
      components.push_back(currComponent);
    }
  }

  std::cout << components.size() << std::endl;
  for (const auto& currComponent: components) {
    std::cout << currComponent.size() << std::endl;
    for (const auto& peak: currComponent) {
      std::cout << peak << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
