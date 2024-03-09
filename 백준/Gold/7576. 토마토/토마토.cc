#include <iostream>
#include <queue>
#include <string.h>
#define MAX 1001

int M, N;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int map[MAX][MAX];
int visited[MAX][MAX];

void bfs() {
	std::queue <std::pair<int, int>> q;

	for (int x = 0;x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (map[x][y] == 1) {
				q.push({ x, y });
				visited[x][y] = 1;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (visited[nx][ny] == 0 && map[nx][ny]!=-1) {
				map[nx][ny] = 1;
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int result() {
	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				return -1;
			}
			else if (visited[i][j] > max) {
				max = visited[i][j];
			}
		}
	}
	return max-1;
}

int main() {
	std::cin >> M >> N;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}

	bfs();

	std::cout << result();
	return 0;
}