#include <iostream>
#include <vector>

static std::vector<int> list[101];
static bool check[101];
static int cnt = 0;

void dfs(int start_node) {
	check[start_node] = true;
	for (int i = 0; i < list[start_node].size(); i++) {
		if (!check[list[start_node][i]]) {
			dfs(list[start_node][i]);
			cnt++;
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	dfs(1);

	std::cout << cnt << std::endl;

	return 0;
}