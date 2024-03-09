#include <iostream>
#include <queue>
#include <vector>

int map[50][50];
bool visited[50][50];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int cnt = 0;
bool flag = 0;

void play_game(int r, int c, int d) {

	while (1) {
		flag = 0;
		if (map[r][c] == 0) {
			map[r][c] = -1; //청소완료
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i];
			int ny = c + dy[i];

			if (map[nx][ny] == 0) {  //현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
				flag = 1;
				d - 1 >= 0 ? d = d - 1 : d = d - 1 + 4;  // 반시계 방향 90도로 회전

				int f_r = r + dx[(d + 2) % 4];
				int f_c = c + dy[(d + 2) % 4];

				if (map[f_r][f_c] == 0) {
					r = f_r;
					c = f_c;
					break;
				}
			}
		}

		if (flag == 0) {
			if (map[r + dx[d]][c + dy[d]] == 1) {
				return;
			}
			else {
				r = r + dx[d];
				c = c + dy[d];
			}
		}
	}
}


int main() {
	int N, M, r, c, d;

	std::cin >> N >> M;
	std::cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}
	play_game(r, c, d);
	std::cout << cnt;

	return 0;
}