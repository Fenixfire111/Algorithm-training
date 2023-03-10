#include <iostream>
#include <vector>

std::string result = "YES";

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<int>& peaks, const int& currPeak) {
  if (peaks[currPeak] == 0) {
    peaks[currPeak] = 1;
  }

  for (const auto& peak: graph[currPeak]) {
    if (peaks[peak] == 0) {
      peaks[peak] -= peaks[currPeak];
      dfs(graph, peaks, peak);
    } else if (peaks[peak] == peaks[currPeak]) {
      result = "NO";
      return;
    }
  }
}

int main() {
  int n;
  int m;
  std::pair<int, int> temp;

  std::cin >> n >> m;
  std::vector<int> peaks(n + 1);
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (int kI = 0; kI < m; ++kI) {
    std::cin >> temp.first >> temp.second;
    if (temp.first != temp.second) {
      graph[temp.first].push_back(temp.second);
      graph[temp.second].push_back(temp.first);
    }
  }

  for (int kI = 1; kI < peaks.size(); ++kI) {
    dfs(graph, peaks, kI);
  }

  std::cout << result << std::endl;
  return 0;
}
