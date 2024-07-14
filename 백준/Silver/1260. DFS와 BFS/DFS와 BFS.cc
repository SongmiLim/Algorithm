#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001

int n, m, v;
std::vector<std::vector<int>> graph;
std::vector<int> dfs_result;
std::vector<int> bfs_result;
bool dfs_visited[MAX] = { false };
bool bfs_visited[MAX] = { false };

void DFS(int node) {
	dfs_result.push_back(node);
	dfs_visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next_node = graph[node][i];
		if (!dfs_visited[next_node]) {
			DFS(next_node);
		}
	}
	return;
}

void BFS(int start_node) {
	std::queue<int> q;

	q.push(start_node);
	bfs_visited[start_node] = true;

	while (!q.empty()) {
		int node = q.front();
		bfs_result.push_back(node);
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];
			if (!bfs_visited[next_node]) {
				q.push(next_node);
				bfs_visited[next_node] = true;
			}
		}
	}
}

int main() {
	std::cin >> n >> m >> v;
	graph.resize(MAX, std::vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);
	BFS(v);

	for (auto a : dfs_result) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	for (auto a : bfs_result) {
		std::cout << a << " ";
	}

	return 0;
}