#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

int T, N;
std::vector <std::string> result_list;
bool visited[102];
int src_x, src_y, dst_x, dst_y;


void bfs(std::vector<std::pair<int, int>> go_list) {
	std::queue <std::pair<int, int>> q;
	q.push({ src_x, src_y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == dst_x && y == dst_y) {
			result_list.push_back("happy");
			return;
		}

		for (int i = 0; i < go_list.size();i++) {
			// 두 좌표의 차이
			int nx, ny;
			go_list[i].first - x > 0 ? nx = go_list[i].first - x : nx = -(go_list[i].first - x);
			go_list[i].second - y > 0 ? ny = go_list[i].second - y : ny = -(go_list[i].second - y);
			
			if (nx + ny <= 1000 && !visited[i]) {
				visited[i] = true;
				q.push({ go_list[i].first, go_list[i].second });
			}
		}
	}
	result_list.push_back("sad");
	return;
}

int main() {
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		memset(visited, 0, sizeof(visited));
		std::vector <std::pair<int, int>> go_list;

		std::cin >> N;
		std::cin >> src_x >> src_y;


		for (int j = 0; j < N; j++) {
			int store_x, store_y;
			std::cin >> store_x >> store_y;
			go_list.push_back({ store_x, store_y });
		}
		std::cin >> dst_x >> dst_y;
		go_list.push_back({ dst_x, dst_y });


		bfs(go_list);
	}
	for (std::string result : result_list)
		std::cout << result << std::endl;
	return 0;
}