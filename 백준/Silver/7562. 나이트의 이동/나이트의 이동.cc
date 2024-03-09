#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 301

int T, L;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
std::vector <int> result_list;

void bfs(int cx, int cy, int mx, int my) {
	std::queue <std::pair<int, int>> q;
	q.push({ cx, cy });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == mx && y == my)
			return;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= L || ny >= L)
				continue;

			if (visited[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}

}

int main() {
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		int current_x, current_y, move_x, move_y;

		std::cin >> L;
		std::cin >> current_x >> current_y;
		std::cin >> move_x >> move_y;

		bfs(current_x, current_y, move_x, move_y);
		result_list.push_back(visited[move_x][move_y]);
	}
	for (int result : result_list) {
		std::cout << result << std::endl;
	}
	return 0;
}