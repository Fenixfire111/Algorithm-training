#include <iostream>
#include <vector>
#include <queue>

void bfs(const std::vector<std::vector<int>>& graph,
        std::vector<int>& visited, const int& startPeak) {
  std::queue<int> queue;
  int count;

  visited[startPeak] = 0;
  queue.push(startPeak);

  while (!queue.empty()) {
    int currPeak = queue.front();
    queue.pop();
    count = visited[currPeak] + 1;

    for (auto peak: graph[currPeak]) {
      if (visited[peak] == -1) {
        visited[peak] = count;
        queue.push(peak);
      }
    }
  }

}

int main() {
  int n;
  int m;
  int s;
  int t;
  int q;
  int answer = 0;
  int currPeak;
  int lastPeak;

  std::cin >> n >> m;
  std::cin >> s >> t;
  std::cin >> q;
  std::vector<int> visited(n * m, -1);
  std::vector<std::pair<int, int>> fleas(q);
  for (int kI = 0; kI < q; ++kI) {
    std::cin >> fleas[kI].first >> fleas[kI].second;
  }
  std::vector<std::vector<int>> graph(n * m, std::vector<int>());
  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < m; ++kJ) {
      int iter = kI * m + kJ;
      if (kI - 1 >= 0) {
        if (kI - 2 >= 0) {
          if (kJ - 1 >= 0) {
            graph[iter].push_back((kI - 2) * m + (kJ - 1));
          }
          if (kJ + 1 < m) {
            graph[iter].push_back((kI - 2) * m + (kJ + 1));
          }
        }

        if (kJ - 2 >= 0) {
          graph[iter].push_back((kI - 1) * m + (kJ - 2));
        }
        if (kJ + 2 < m) {
          graph[iter].push_back((kI - 1) * m + (kJ + 2));
        }
      }

      if (kI + 1 < n) {
        if (kI + 2 < n) {
          if (kJ - 1 >= 0) {
            graph[iter].push_back((kI + 2) * m + (kJ - 1));
          }
          if (kJ + 1 < m) {
            graph[iter].push_back((kI + 2) * m + (kJ + 1));
          }
        }

        if (kJ - 2 >= 0) {
          graph[iter].push_back((kI + 1) * m + (kJ - 2));
        }
        if (kJ + 2 < m) {
          graph[iter].push_back((kI + 1) * m + (kJ + 2));
        }

      }
    }
  }

  lastPeak = (s - 1) * m + (t - 1);
  bfs(graph, visited, lastPeak);

  for (auto pair: fleas) {
    currPeak = (pair.first - 1) * m + (pair.second - 1);
    if (visited[currPeak] == -1) {
      std::cout << -1;
      return 0;
    }
    answer += visited[currPeak];
  }

  std::cout << answer;
  return 0;
}
