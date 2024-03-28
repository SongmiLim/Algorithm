#include <iostream>
#include <vector>
using namespace std;


struct Magic
{
	int d;
	int s;
};

int N, M;
int map[50][50];
// 상어 이동: d ↑, ↓, ←, →
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
// 칸 번호 인덱싱: 왼, 아, 오, 위
int rotate_y[4] = { 0, 1, 0, -1 };
int rotate_x[4] = { -1, 0, 1, 0 };
vector <int> result(4, 0);
int ball_num = 0;

void update_map(vector< int> group_list) {
	int new_map[50][50] = { 0, };
	bool visited[50][50] = { false, };
	int cy = N / 2;
	int cx = N / 2;
	int dir = -1;
	int cnt = 2;
	new_map[cy][cx] = 0;

	while (cy != 0 || cx != 0) {
		visited[cy][cx] = true;

		int nd = (dir + 1) % 4;
		int ny = cy + rotate_y[nd];
		int nx = cx + rotate_x[nd];

		if (visited[ny][nx]) {
			nd = dir;
			ny = cy + rotate_y[nd];
			nx = cx + rotate_x[nd];
		}

		new_map[ny][nx] = group_list[cnt];
		cy = ny; cx = nx; dir = nd;
		cnt++;

		if (cnt == group_list.size())
			break;
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = new_map[y][x];
		}
	}
}

void change_ball() {
	bool visited[50][50] = { false, };
	int cy = N / 2;
	int cx = N / 2;
	int dir = -1;
	int cnt = 1;
	vector<int> group_list;
	bool flag = false;

	//if (ball_num == 0)
	//	return;

	while (cy != 0 || cx != 0) {
		visited[cy][cx] = true;
		int nd = (dir + 1) % 4;
		int ny = cy + rotate_y[nd];
		int nx = cx + rotate_x[nd];

		if (visited[ny][nx]) {
			nd = dir;
			ny = cy + rotate_y[nd];
			nx = cx + rotate_x[nd];
		}

		if (map[cy][cx] == -1)
			break;

		// 다음 구슬과 번호가 같으면 explode_list에 해당 구슬 좌표 추가
		if (map[cy][cx] == map[ny][nx]) {
			cnt++;
		}

		else {
			if (map[cy][cx] == -1)
				break;
			group_list.push_back(cnt);
			group_list.push_back(map[cy][cx]);
			cnt = 1;
		}
		cy = ny; cx = nx; dir = nd;
	}
	update_map(group_list);
}


bool explode_ball() {
	bool visited[50][50] = { false, };
	int cy = N / 2;
	int cx = N / 2;
	int dir = -1;
	int cnt = 1;
	vector<pair<int, int>> explode_ball_list;
	bool flag = false;

	while (cy != 0 || cx != 0) {
		visited[cy][cx] = true;
		int nd = (dir + 1) % 4;
		int ny = cy + rotate_y[nd];
		int nx = cx + rotate_x[nd];

		if (visited[ny][nx]) {
			nd = dir;
			ny = cy + rotate_y[nd];
			nx = cx + rotate_x[nd];
		}

		// 다음 구슬과 번호가 같으면 explode_list에 해당 구슬 좌표 추가
		if (map[cy][cx] == map[ny][nx] && map[cy][cx] > 0) {
			cnt++;
			explode_ball_list.push_back({ cy, cx });
		}

		else {
			explode_ball_list.push_back({ cy, cx });
			if (cnt >= 4) {
				result[map[cy][cx]] += cnt;
				for (int i = 0; i < explode_ball_list.size(); i++) {
					map[explode_ball_list[i].first][explode_ball_list[i].second] = -1;
				}
				ball_num -= cnt;
				flag = true;
			}
			cnt = 1;
			explode_ball_list.clear();
		}

		//if (ball_num == 0) {
		//	flag = false;
		//	break;
		//}

		cy = ny; cx = nx; dir = nd;
	}
	return flag;
}

int move_ball() {
	bool visited[50][50] = { false, };
	int cy = N / 2;
	int cx = N / 2;
	int dir = -1;
	int cnt = 0;

	while (cy != 0 || cx != 0) {
		visited[cy][cx] = true;
		int nd = (dir + 1) % 4;
		int ny = cy + rotate_y[nd];
		int nx = cx + rotate_x[nd];

		if (visited[ny][nx]) {
			nd = dir;
			ny = cy + rotate_y[nd];
			nx = cx + rotate_x[nd];
		}

		//구슬 이동
		if (map[cy][cx] == -1) {
			if (map[ny][nx] == -1) {
				cy = ny; cx = nx; dir = nd;
				continue;
			}
			if (map[ny][nx] == 0)
				break;
			int tmp = map[cy][cx];
			map[cy][cx] = map[ny][nx];
			map[ny][nx] = tmp;
			cnt++;
		}
		cy = ny; cx = nx; dir = nd;
	}
	return cnt;
}

void game(int d, int s) {
	int shark_y = N / 2;
	int shark_x = N / 2;
	map[shark_y][shark_x] = 0;  // 상어 위치 초기화
	ball_num = 0;

	// ball 개수 세기
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] > 0)
				ball_num++;
		}
	}

	if (ball_num == 0)
		return;

	// 파편 던지기
	for (int i = 1; i <= s; i++) {
		int magic_y = shark_y + dy[d] * i;
		int magic_x = shark_x + dx[d] * i;
		if (map[magic_y][magic_x] > 0) {
			map[magic_y][magic_x] = -1;
			ball_num--;
		}
	}

	// 구슬이 이동하지 않을 때 까지 이동 반복 
	while (true)
	{
		if (!move_ball())
			break;
	}

	// 구슬이 이동하지 않을 때 까지 이동 반복 
	while (true)
	{	// 구슬 폭발
		if (!explode_ball()) {
			break;
		}

		// 구슬 이동
		while (true) {
			if (!move_ball())
				break;
		}
	}

	// 구슬 변화
	change_ball();
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	vector <Magic> magic_list;
	for (int i = 0; i < M; i++) {
		int d, s;
		Magic magic;
		cin >> magic.d >> magic.s;
		magic_list.push_back(magic);
	}


	for (int i = 0; i < M; i++) {
		game(magic_list[i].d - 1, magic_list[i].s);
	}

	int answer = 0;
	for (int i = 0; i < result.size(); i++) {
		answer += i * result[i];
	}

	cout << answer;
	return 0;
}