#include <iostream>
#include <vector>
using namespace std;

/*모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.
이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
파이어볼은 4개의 파이어볼로 나누어진다.
나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
질량이 0인 파이어볼은 소멸되어 없어진다.
마법사 상어가 이동을 K번 명령한 후, 남아있는 파이어볼 질량의 합을 구해보자.*/


struct Fireball {
	int y, x;
	int m, s, d;
};

int N, M, K;
vector <Fireball> fireball_list;
vector <int > map[51][51];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void move() {
	vector <int> new_map[51][51];

	for (int i = 0; i < fireball_list.size(); i++) {
		int dir = fireball_list[i].d;
		int speed = fireball_list[i].s % N;
		int ny = (fireball_list[i].y + dy[dir] * speed + N) % N;
		int nx = (fireball_list[i].x + dx[dir] * speed + N) % N;
		new_map[ny][nx].push_back(i);
		fireball_list[i].y = ny;
		fireball_list[i].x = nx;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
		}
	}
}

void collect() {
	vector <Fireball> new_fireball_list;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			if (map[y][x].empty())
				continue;

			else if (map[y][x].size() == 1) {
				new_fireball_list.push_back(fireball_list[map[y][x][0]]);
				continue;
			}

			int sum_m = 0; int sum_s = 0;
			bool odd = true; bool even = true;
			
			for (int i = 0; i < map[y][x].size(); i++) {
				int index = map[y][x][i];
				sum_m += fireball_list[index].m;
				sum_s += fireball_list[index].s;
				fireball_list[index].d % 2 == 0 ? odd = false : even = false;
			}

			int cur_m = sum_m / 5;
			int cur_s = sum_s / map[y][x].size();

			if (cur_m == 0)
				continue;

			for (int i = 0; i < 4; i++) {
				if (odd || even) {
					new_fireball_list.push_back({ y, x, cur_m, cur_s, i * 2 });
				}
				else {
					new_fireball_list.push_back({ y, x, cur_m, cur_s, i * 2 + 1 });
				}
			}

		}
	}
	fireball_list = new_fireball_list;
}

void game() {
	move();
	collect();
}

int main() {

	int answer = 0;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d;
		y--, x--;
		fireball_list.push_back({ y,x,m,s,d });
		map[y][x].push_back(i);
	}

	while (K--) {
		game();
	}

	for (int i = 0; i < fireball_list.size(); i++) {
		answer += fireball_list[i].m;
	}

	cout << answer;

	return 0;
}