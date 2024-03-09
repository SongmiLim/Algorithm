#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 51

int T, M, N, K;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int cnt;

void bfs(int x, int y) {
	std::queue <std::pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx < 0 || ny < 0 || nx > M || ny > N)
				continue;

			if (!visited[nx][ny] && map[nx][ny] == 1) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
		q.pop();
	}
}

int main() {
	std::cin >> T;

	std::vector <int> result_list;

	for (int r = 0; r < T; r++) {
		std::cin >> M >> N >> K;

		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		cnt = 0;

		for (int i = 0; i < K; i++) {
			int x, y;
			std::cin >> x >> y;
			map[x][y] = 1;
		}
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		result_list.push_back(cnt);
	}

	for (int result : result_list)
		std::cout << result << std::endl;

	return 0;
}