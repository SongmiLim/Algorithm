#include <iostream>
#include <vector>
#define MAX 101

int N, M, person_a, person_b;
std::vector <std::vector<int>> data(MAX);
bool visited[MAX];
int cnt = 0;
std::vector<int> result;

void dfs(int person) {
	visited[person] = true;
	cnt++;

	if (person == person_b) {
		result.push_back(cnt);
		return;
	}

	for (int i = 0; i < data[person].size(); i++) {
		if (!visited[data[person][i]])
			dfs(data[person][i]);
	}
	cnt--;
}

int main() {
	std::cin >> N;
	std::cin >> person_a >> person_b;
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;
		data[x].push_back(y);
		data[y].push_back(x);
	}

	dfs(person_a);

	result.size() == 0 ? (std::cout << -1) : std::cout << (result[0] - 1);
	return 0;
}