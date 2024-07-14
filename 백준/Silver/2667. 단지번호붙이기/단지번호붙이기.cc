#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 26

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];

int total_home_num = 0;
std::vector<int> home_cnt_list;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int get_home_cnt(int y, int x) {
	int cnt = 0;
	std::queue<std::pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		cnt++;
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (!visited[ny][nx] && map[ny][nx] == 1) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	return cnt;
}

int main() {
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string line;
		std::cin >> line;
		for (int j = 0; j < n; j++) {
			map[i][j] = line[j] - '0';
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				total_home_num++;
				int home_cnt = get_home_cnt(i, j);
				home_cnt_list.push_back(home_cnt);
			}
		}
	}

	std::cout << total_home_num<<std::endl;

	sort(home_cnt_list.begin(), home_cnt_list.end());
	for (auto a : home_cnt_list) {
		std::cout << a << "\n";
	}

	return 0;
}