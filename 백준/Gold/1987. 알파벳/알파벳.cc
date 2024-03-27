#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[20][20];
bool visited['Z'-'0'] = {false ,};
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int solution(int y, int x, int cnt) {
	visited[map[y][x] - '0'] = true;
	int max_cnt = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C)
			continue;
		if (visited[map[ny][nx] - '0'])
			continue;
		max_cnt = max(max_cnt, solution(ny, nx, cnt+1));
	}

	visited[map[y][x] - '0'] = false;

	return max_cnt;
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	cout<<solution(0, 0, 1);
	return 0;
}