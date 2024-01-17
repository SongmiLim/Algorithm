#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, V;
std::vector<int> graph[1001];
bool visited_dfs[1001];
bool visited_bfs[1001];
std::vector<int> bfs_result;
std::vector<int> dfs_result;

void dfs(int start_node) {
  visited_dfs[start_node] = true;
  dfs_result.push_back(start_node);

    for (int adj_node : graph[start_node]) {
    if (!visited_dfs[adj_node]) {
      dfs(adj_node);
    }
  }
  return;
}

void bfs(int start_node) {
  std::queue <int> q;
  visited_bfs[start_node] = true;
  q.push(start_node);

  while (!q.empty()) {
    int n = q.front();
    bfs_result.push_back(n);
    q.pop();

    for (int i = 0; i < graph[n].size(); i++) {
      int adj_node = graph[n][i];

      if (!visited_bfs[adj_node]) {
        visited_bfs[adj_node] = true;
        q.push(adj_node);
      }
    }
  }
}

int main() {
  std::cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 0; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  bfs(V);
  dfs(V);

  for (int node:dfs_result) {
    std::cout << node << " ";
  }
  std::cout << std::endl;
  for (int node : bfs_result) {
    std::cout << node << " ";
  }
  return 0;
}