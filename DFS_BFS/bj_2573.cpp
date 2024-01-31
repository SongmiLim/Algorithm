#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 301

int N, M;
int map[MAX][MAX];
int new_map[MAX][MAX];
bool visited[MAX][MAX];
std::vector <int> result;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y, int map[][MAX]) {
  std::queue <std::pair<int, int>> q;
  visited[x][y] = 1;
  q.push({ x, y });

  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        continue;

      if (map[nx][ny] == 0)
        cnt++;

      if (map[nx][ny] != 0 && !visited[nx][ny]) {
        q.push({ nx, ny });
        visited[nx][ny] = 1;
      }
    }
    map[x][y] - cnt < 0 ? new_map[x][y] = 0 : new_map[x][y] = map[x][y] - cnt;
  }
}

int main() {
  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> map[i][j];
      new_map[i][j] = map[i][j];
    }
  }

  int year = -1;
  while (1) {
    year++;
    memset(visited, 0, sizeof(visited));
    memcpy(map, new_map, sizeof(map));

    int cluster = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (map[i][j] > 0 && !visited[i][j]) {
          bfs(i, j, map);
          cluster++;
        }
      }
    }

    if (cluster >= 2) {
      result.push_back(year);
      break;
    }

    if (cluster == 0) {
      result.push_back(0);
      break;
    }
  }

  std::cout << result[0];
  return 0;
}