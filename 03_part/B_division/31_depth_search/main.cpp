#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<bool>& peaks, int currPeak, int& count) {
  peaks[currPeak] = true;
  ++count;

  for (auto peak: graph[currPeak]) {
    if (!peaks[peak]) {
      dfs(graph, peaks, peak, count);
    }
  }
}

int main() {
  int n;
  int m;
  int count = 0;
  std::pair<int, int> temp;

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

  dfs(graph, peaks, 1, count);

  std::cout << count << std::endl;
  for (int kI = 0; kI < peaks.size(); ++kI) {
    if (peaks[kI]) {
      std::cout << kI << " ";
    }
  }
  return 0;
}
