#include <iostream>
using namespace std;


int n;
int map[500][500] = { 0, };
bool visited[500][500];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0 , 1, 0 };

int windy[][9] = { 
	{-1, 1, -2, 2, 0, -1, 1, -1, 1 },
	{-1, -1, 0, 0, 2, 0, 0, 1, 1},
	{1, -1, 2, -2, 0, 1, -1, 1, -1},
	{1, 1, 0, 0, -2, 0, 0, -1, -1} };

int windx[][9] = { 
	{1, 1, 0, 0, -2, 0, 0, -1, -1 },
	{-1, 1, -2, 2, 0, -1, 1, -1, 1},
	{-1, -1, 0, 0, 2, 0, 0, 1, 1},
	{1, -1, 2, -2, 0, 1, -1, 1, -1} };

int rate[9] = {1, 1, 2, 2, 5, 7, 7, 10, 10};

int collect_sand(int cy, int cx, int dir) {
	int sand = map[cy][cx];
	int sum = 0;
	int ret = 0;

	for (int i = 0; i < 9; i++) {
		int ny = cy + windy[dir][i];
		int nx = cx + windx[dir][i];
		int wind_sand = (sand * rate[i]) / 100;
		sum += wind_sand;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			ret += wind_sand;
			continue;
		}
		map[ny][nx] += wind_sand;
	}

	int ny = cy + dy[dir];
	int nx = cx + dx[dir];
	int a = sand - sum;

	if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
		ret += a;
	}
	else {
		map[ny][nx] += a;
	}
	
	map[cy][cx] = 0;

	return ret;
}

int tornado_move() {
	int cy = n / 2;
	int cx = n / 2;
	int dir = -1;
	int total_sand = 0;

	while ((cy != 0) || (cx != 0)) {
		visited[cy][cx] = true;
		int nd = (dir + 1) % 4;
		int ny = cy + dy[nd];
		int nx = cx + dx[nd];

		if (visited[ny][nx]) {
			nd = dir;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}
		total_sand+=collect_sand(ny, nx, nd);
		cy = ny; cx = nx; dir = nd;
	}

	return total_sand;
}

int solve() {
	int answer = 0;
	answer = tornado_move();

	return answer;
}

int main() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	cout << solve();

	return 0;
}