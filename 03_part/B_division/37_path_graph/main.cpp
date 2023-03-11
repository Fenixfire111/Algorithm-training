#include <iostream>
#include <vector>
#include <queue>

int bfs(const std::vector<std::vector<int>>& graph,
        std::vector<int>& visited, const int& startPeak, const int& lastPeak,
        std::vector<int>& path) {
  std::queue<int> queue;
  int count;

  visited[startPeak] = 0;
  queue.push(startPeak);

  if (startPeak == lastPeak) {
    return 0;
  }
  while (!queue.empty()) {
    int currPeak = queue.front();
    queue.pop();
    count = visited[currPeak] + 1;

    for (auto peak: graph[currPeak]) {
      if (visited[peak] == -1) {
        visited[peak] = count;
        path[peak] = currPeak;
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
  std::vector<int> answer;

  std::cin >> n;
  std::vector<int> visited(n + 1, -1);
  std::vector<int> path(n + 1, -1);
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

  result = bfs(graph, visited, startPeak, lastPeak, path);

  if (result != -1 && result != 0) {
    int currPeak = lastPeak;
    while (currPeak > 0) {
      answer.push_back(currPeak);
      currPeak = path[currPeak];
    }
  }

  std::cout << result << std::endl;
  for (int kI = (int)answer.size() - 1; kI >= 0 ; --kI) {
    std::cout << answer[kI] << " ";
  }
  return 0;
}
