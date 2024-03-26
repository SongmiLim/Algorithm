#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int M, S;
int shark_y, shark_x;
const int N = 4;
vector<vector<vector<int>>> map(N, vector<vector<int>>(N, vector<int>(0)));
int total_fish_num = 0;
int visited_fish[N][N] = { 0, };

void move_fish() {
	vector<vector<vector<int>>> new_map(N, vector<vector<int>>(N, vector<int>(0)));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int i = 0; i < map[y][x].size(); i++) {
				int d = map[y][x][i];
				int ny = y;
				int nx = x;
				int nd = d;
				bool flag = false;

				for (int j = 0; j < 8; j++) {
					ny = y + dy[(d - j + 8) % 8];
					nx = x + dx[(d - j + 8) % 8];
					nd = (d - j + 8) % 8;

					if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
						if (ny != shark_y || nx != shark_x) {
							if (visited_fish[ny][nx] == 0) {
								flag = true;
								break;
							}
						}
					}
				}
				// 이동한 좌표로 map에 추가
				if (flag == true) {
					new_map[ny][nx].push_back(nd);
				}
				else {
					ny = y; nx = x; nd = d;
					new_map[ny][nx].push_back(nd);
				}
			}
		}
	}
	map = new_map;
}

void move_shark() {
	int max = -1;
	set <pair<int, int>> shark_move_set;
	vector<vector<vector<int>>> temp_map;
	temp_map = map;
	int new_shark_y = shark_y;
	int new_shark_x = shark_x;

	for (auto& i : { 2, 0, 6, 4 }) {
		int ny1 = shark_y + dy[i];
		int nx1 = shark_x + dx[i];

		if (ny1 < 0 || nx1 < 0 || ny1 >= N || nx1 >= N)
			continue;
		
		for (auto& j : { 2, 0, 6, 4 }) {
			int ny2 = ny1 + dy[j];
			int nx2 = nx1 + dx[j];

			if (ny2 < 0 || nx2 < 0 || ny2 >= N || nx2 >= N)
				continue;

			for (auto& k : { 2, 0, 6, 4 }) {
				int ny3 = ny2 + dy[k];
				int nx3 = nx2 + dx[k];

				if (ny3 < 0 || nx3 < 0 || ny3 >= N || nx3 >= N)
					continue;

				set <pair<int, int>> temp_shark_move = { { ny1, nx1 } ,{ ny2, nx2 },{ ny3, nx3 } };
				int cnt = 0;
				for (auto& a : temp_shark_move) {
					cnt += map[a.first][a.second].size();
				}

				// 상어 이동
				if (max < cnt) {
					new_shark_y = ny3;
					new_shark_x = nx3;
					shark_move_set = temp_shark_move;
					max = cnt;
				}
			}
		}
	}

	// 상어 위치 업데이트
	shark_y = new_shark_y;
	shark_x = new_shark_x;

	// 물고기 격자에서 없애기
	int remove_cnt = 0;
	for (auto& a : shark_move_set) {
		int s_y = a.first;
		int s_x = a.second;

		// 해당 좌표에 물고기가 있는 경우
		if (map[s_y][s_x].size() > 0) {
			total_fish_num -= map[s_y][s_x].size();
			map[s_y][s_x].clear();
			visited_fish[s_y][s_x] = -3;
		}
	}

	// 물고기 냄새 없애주기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_fish[i][j] < 0)
				visited_fish[i][j]++;
		}
	}
}


void game(int s) {
	while (s--) {
		vector<vector<vector<int>>> copy_map;
		// 물고기 복제
		copy_map = map;

		// 물고기 이동
		move_fish();

		// 상어 이동
		move_shark();


		// 복제된 물고기 map에 나타남
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < copy_map[i][j].size(); k++) {
					map[i][j].push_back(copy_map[i][j][k]);
				}
				total_fish_num += copy_map[i][j].size();
			}
		}
	}
}

int main() {
	int answer = 0;
	cin >> M >> S;

	for (int i = 0; i < M; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		map[y - 1][x - 1].push_back(d - 1);
		total_fish_num++;
	}
	

	cin >> shark_y >> shark_x;
	shark_y--;
	shark_x--;

	game(S);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += map[i][j].size();
		}
	}
	cout << total_fish_num;

	return 0;
}