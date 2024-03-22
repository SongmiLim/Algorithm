#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
int map[64][64] = { 0, };
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void rotate_map(int l) {
	int len = 1 << l;
	int temp[64][64] = { 0, };

	for (int i = 0; i < N; i += len) {
		for (int j = 0; j < N; j += len) {
			for (int y = 0; y < len; y++) {
				for (int x = 0; x < len; x++) {
					temp[x + i][len - 1 - y + j] = map[y + i][x + j];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}
}

void melt_ice() {
	queue <pair<int, int >> q;
	bool visited[64][64] = { false, };
	vector <pair<int, int >> melt_ice_list;

	q.push({ 0, 0 });

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int cnt = 0;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || nx >= N || ny >= N)
					continue;

				if (map[ny][nx] > 0) {
					cnt++;
				}
			}

			if (cnt < 3) {
				melt_ice_list.push_back({ y, x });
			}
		}
	}

	for (auto& a : melt_ice_list) {
		map[a.first][a.second]--;
		if (map[a.first][a.second] < 0)
			map[a.first][a.second] = 0;
	}
}

vector<pair<int, int>> bfs(int y, int x, bool visited[][64]) {
	vector<pair<int, int>> result;
	queue <pair<int, int >> q;
	int cnt = 0;
	int ice_sum = 0;

	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		ice_sum += map[y][x];
		cnt++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || nx >= N || ny >= N)
				continue;

			if (!visited[ny][nx] && map[ny][nx] > 0) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	result.push_back({ ice_sum, cnt });
	return result;
}

int main() {
	cin >> N >> Q;
	N = 1 << N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	for (int i = 0; i < Q; i++){
		int l;
		cin >> l;
		rotate_map(l);
		melt_ice();
	}

	bool visited[64][64] = { false, };
	int cnt = 0;
	int sum = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!visited[y][x] && map[y][x] > 0) {
				vector<pair<int, int>> result = bfs(y, x, visited);
				sum += result.front().first;
				cnt = max(cnt, result.front().second);
			}
		}
	}
	cout << sum<<endl;
	cout << cnt;

	return 0;
}