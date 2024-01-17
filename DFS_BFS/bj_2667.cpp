#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 25
int N;
int map[MAX][MAX];
bool visit[MAX][MAX];
int cnt;
std::vector<int> count_list;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
  std::queue<std::pair<int, int>> q;
  cnt = 1;
  q.push({ x, y });
  visit[x][y] = true;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
        continue;
      }
      if (!visit[nx][ny] && map[nx][ny] == 1) {
        visit[nx][ny] = true;
        q.push({ nx, ny });
        cnt++;
      }
    }
  }
  count_list.push_back(cnt);
}

int main() {

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < N; j++) {
      map[i][j] = str[j] - '0';  // str => int형으로 변환
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visit[i][j] && map[i][j] == 1) {
        bfs(i, j);
      }
    }
  }
  std::sort(count_list.begin(), count_list.end());
  std::cout << count_list.size() << std::endl;

  for (int i = 0; i < count_list.size(); i++) {
    std::cout << count_list[i] << std::endl;
  }
}