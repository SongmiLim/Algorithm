#include <iostream>
#include <string>
#include <queue>
#define MAX  101

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int cnt = 0;

void bfs(int x, int y) {
	std::queue <std::pair<int, int>> q;
	visited[x][y] = 1;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (visited[nx][ny]==0 && map[nx][ny] == 1) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::string line;
		std::cin >> line;
		
		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
		}
	}
	bfs(0, 0);

	std::cout << visited[N - 1][M - 1];

	return 0;
}