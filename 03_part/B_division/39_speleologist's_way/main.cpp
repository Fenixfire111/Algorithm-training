#include <iostream>
#include <vector>
#include <queue>

int bfs(const std::vector<std::vector<int>>& graph,
         std::vector<int>& visited, const int& startPeak, const int& n) {
  std::queue<int> queue;
  int count;

  visited[startPeak] = 0;
  queue.push(startPeak);

  if (startPeak < n * n) {
    return 0;
  }
  while (!queue.empty()) {
    int currPeak = queue.front();
    queue.pop();
    count = visited[currPeak] + 1;

    for (auto peak: graph[currPeak]) {
      if (visited[peak] == -1) {
        visited[peak] = count;
        queue.push(peak);

        if (peak < n * n) {
          return visited[peak];
        }
      }
    }
  }
  return -1;
}

int main() {
  int n;
  int answer;
  int startPeak;

  std::cin >> n;

  std::vector<int> visited(n * n * n, -1);
  std::vector<std::vector<std::string>> cube(n, std::vector<std::string>(n));
  std::vector<std::vector<int>> graph(n * n * n, std::vector<int>());

  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < n; ++kJ) {
      std::cin >> cube[kI][kJ];
    }
  }

  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < n; ++kJ) {
      for (int k = 0; k < n; ++k) {
        int iter = kI * n * n + kJ * n + k;

        if (cube[kI][kJ][k] == 'S') {
          startPeak = iter;
        }
        if (cube[kI][kJ][k] == '.' || cube[kI][kJ][k] == 'S') {
          if (kI + 1 < n) {
            if (cube[kI + 1][kJ][k] == '.' || cube[kI + 1][kJ][k] == 'S') {
              graph[iter].push_back((kI + 1) * n * n + kJ * n + k);
              graph[(kI + 1) * n * n + kJ * n + k].push_back(iter);
            }
          }

          if (kJ + 1 < n) {
            if (cube[kI][kJ + 1][k] == '.' || cube[kI][kJ + 1][k] == 'S') {
              graph[iter].push_back(kI * n * n + (kJ + 1) * n + k);
              graph[kI * n * n + (kJ + 1) * n + k].push_back(iter);
            }
          }

          if (k + 1 < n) {
            if (cube[kI][kJ][k + 1] == '.' || cube[kI][kJ][k + 1] == 'S') {
              graph[iter].push_back(kI * n * n + kJ * n + k + 1);
              graph[kI * n * n + kJ * n + k + 1].push_back(iter);
            }
          }

        }

      }
    }
  }

  answer = bfs(graph, visited, startPeak, n);

  std::cout << answer;
  return 0;
}
