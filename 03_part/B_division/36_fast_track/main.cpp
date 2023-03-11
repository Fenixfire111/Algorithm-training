#include <iostream>
#include <vector>
#include <queue>

int bfs(const std::vector<std::vector<int>>& graph,
         std::vector<int>& visited, const int& startPeak, const int& lastPeak) {
  std::queue<int> queue;
  int count = 0;

  visited[startPeak] = -1;
  queue.push(startPeak);

  if (startPeak == lastPeak) {
    return 0;
  }
  while (!queue.empty()) {
    int currPeak = queue.front();
    queue.pop();
    if (currPeak == startPeak) {
      count = 1;
    } else {
      count = visited[currPeak] + 1;
    }

    for (auto peak: graph[currPeak]) {
      if (!visited[peak]) {
        visited[peak] = count;
        queue.push(peak);
        if (peak == lastPeak) {
          return visited[peak];
        }
      }
    }
  }

  return -1;
}

int main() {
  int n;
  int result;
  int temp;
  int startPeak;
  int lastPeak;

  std::cin >> n;
  std::vector<int> visited(n + 1);
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (int kI = 1; kI < n + 1; ++kI) {
    for (int kJ = 1; kJ < n + 1; ++kJ) {
      std::cin >> temp;
      if (temp) {
        graph[kI].push_back(kJ);
      }
    }
  }
  std::cin >> startPeak >> lastPeak;

  result = bfs(graph, visited, startPeak, lastPeak);

  std::cout << result;
  return 0;
}
