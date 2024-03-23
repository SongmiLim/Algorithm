#include <iostream>
#include <vector>
using namespace std;


int N, M;
int map[50][50] = { 0, };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
vector <pair<int, int>> cloud;
vector <pair<int, int>> move_cloud_list;

void move_cloud(int d, int s) {
	bool cloud_visited[50][50] = { false, };

	// move
	for (int i = 0; i < cloud.size(); i++) {
		// 최대 d=8, 최대 s=50
		cloud[i].first = (cloud[i].first + dy[d] * s + 50 * N) % N;
		cloud[i].second = (cloud[i].second + dx[d] * s + 50 * N) % N;
		cloud_visited[cloud[i].first][cloud[i].second] = true;
	}

	// rain
	for (int i = 0; i < cloud.size(); i++) {
		int y = cloud[i].first;
		int x = cloud[i].second;
		map[y][x]++;
	}

	// copy magic
	for (int i = 0; i < cloud.size(); i++) {
		int cnt = 0;
		for (int j = 1; j < 8; j += 2) {
			int ny = cloud[i].first + dy[j];
			int nx = cloud[i].second + dx[j];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (map[ny][nx] > 0)
				cnt++;
		}
		map[cloud[i].first][cloud[i].second] += cnt;
	}

	cloud.clear();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] >= 2) {
				if (!cloud_visited[y][x]) {
					map[y][x] -= 2;
					cloud.push_back({ y, x });
				}
			}
		}
	}
}

void game() {
	// make cloud
	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });

	// move cloud
	for (int i = 0; i < M; i++) {
		int d = move_cloud_list[i].first;
		int s = move_cloud_list[i].second;
		move_cloud(d, s);
	}
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		move_cloud_list.push_back({ d - 1, s });
	}
	game();

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += map[i][j];
		}
	}
	cout << answer;

	return 0;
}