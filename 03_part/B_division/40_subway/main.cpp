#include <iostream>
#include <vector>
#include <set>
#include <queue>

int bfs(const std::vector<std::vector<int>>& graph,
        std::vector<int>& visited, const std::set<int>& startStation,
        const std::set<int>& lastStation) {
  std::queue<int> queue;
  int count;

  for (auto line: startStation) {
    visited[line] = 0;
    queue.push(line);
  }

  for (auto lineFinish: lastStation) {
    if (startStation.count(lineFinish)) {
      return 0;
    }
  }
  while (!queue.empty()) {
    int currPeak = queue.front();
    queue.pop();
    count = visited[currPeak] + 1;

    for (auto peak: graph[currPeak]) {
      if (visited[peak] == -1) {
        visited[peak] = count;
        queue.push(peak);

        if (lastStation.count(peak)) {
          return visited[peak];
        }
      }
    }
  }
  return -1;
}

int main() {
  int n;
  int m;
  int p;
  int a;
  int b;
  int answer;
  std::set<int> startStation;
  std::set<int> lastStation;

  std::cin >> n;
  std::cin >> m;

  std::vector<int> visited(m, -1);
  std::vector<std::set<int>> linesAndStation(m);
  std::vector<std::vector<int>> graph(m);

  for (int kI = 0; kI < m; ++kI) {
    std::cin >> p;
    int station;
    for (int kJ = 0; kJ < p; ++kJ) {
      std::cin >> station;
      linesAndStation[kI].insert(station);
    }
  }

  for (int kI = 0; kI < m; ++kI) {
    for (int kJ = kI + 1; kJ < m; ++kJ) {
      for (const auto& station: linesAndStation[kJ]) {
        if (linesAndStation[kI].count(station)) {
          graph[kI].push_back(kJ);
          graph[kJ].push_back(kI);
          break;
        }
      }
    }
  }

  std::cin >> a >> b;
  for (int kI = 0; kI < linesAndStation.size(); ++kI) {
    if (linesAndStation[kI].count(a)) {
      startStation.insert(kI);
    }
    if (linesAndStation[kI].count(b)) {
      lastStation.insert(kI);
    }
  }


  answer = bfs(graph, visited, startStation, lastStation);

  std::cout << answer;
  return 0;
}
