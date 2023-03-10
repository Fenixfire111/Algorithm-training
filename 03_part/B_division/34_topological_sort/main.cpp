#include <iostream>
#include <vector>

bool flag = true;

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<int>& peaks, const int& currPeak, const int& prePeak, std::vector<int>& result) {
  if (peaks[currPeak] == 0) {
    peaks[currPeak] = 1;
  } else if (peaks[currPeak] == -1) {
    return;
  }

  for (const auto& peak: graph[currPeak]) {
    if (peaks[peak] == 0) {
      dfs(graph, peaks, peak, currPeak, result);
    } else if (peaks[peak] == 1 && peak != prePeak) {
      flag = false;
      return;
    }
  }

  peaks[currPeak] = -1;
  result.push_back(currPeak);
}

int main() {
  int n;
  int m;
  std::pair<int, int> temp;
  std::vector<int> result;

  std::cin >> n >> m;
  std::vector<int> peaks(n + 1);
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (int kI = 0; kI < m; ++kI) {
    std::cin >> temp.first >> temp.second;
    graph[temp.first].push_back(temp.second);
  }

  for (int kI = 1; kI < peaks.size(); ++kI) {
    dfs(graph, peaks, kI, 0, result);
  }

  if (flag) {
    for (int kI = (int)result.size() - 1; kI >= 0; --kI) {
      std::cout << result[kI] << " ";
    }
  } else {
    std::cout << -1;
  }
  return 0;
}
