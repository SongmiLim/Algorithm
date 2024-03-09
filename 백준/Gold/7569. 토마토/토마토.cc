#include <iostream>
#include <queue>
#define MAX 100

int M, N, H;
int map[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,1,-1};
int dz[6] = {1,-1,0,0,0,0};

void bfs() {
	std::queue <std::pair<std::pair<int, int>, int>>  q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j][k] == 1) {
					q.push({ { i, j }, k });
					visited[i][j][k] = 1;
				}
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H)
				continue;

			if (visited[nx][ny][nz] == 0 && map[nx][ny][nz] != -1) {
				visited[nx][ny][nz] = visited[x][y][z] + 1;
				map[nx][ny][nz] = 1;
				q.push({ {nx, ny}, nz });
			}
		}
	}
}

int result() {
	int max = 0;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j][k] == 0)
					return -1;

				if (visited[i][j][k] > max)
					max = visited[i][j][k];
			}
		}
	}
	return max - 1;
}

int main() {
	std::cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cin >> map[i][j][k];
			}
		}
	}

	bfs();
	std::cout << result();

	return 0;
}