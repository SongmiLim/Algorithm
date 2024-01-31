#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX 101


int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool water[MAX][MAX];
std::vector <int> result_list;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
  std::queue <std::pair<int, int>> q;
  q.push({ x, y });
  visited[x][y] = 1;

  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N)
        continue;

      if (!visited[nx][ny] && !water[nx][ny]) {
        q.push({ nx, ny });
        visited[nx][ny] = true;
      }
    }
  }
}

bool cmp(int &a, int &b) {
  return a > b;
}

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> map[i][j];
    }
  }
  for (int k = 0; k < MAX; k++) {
    memset(water, 0, sizeof(water));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (map[i][j] <= k) {
          water[i][j] = true;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!water[i][j] && !visited[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }
    result_list.push_back(cnt);
  }

  std::sort(result_list.begin(), result_list.end(), cmp);
  std::cout << result_list[0];
  // std::cout<<*std::max_element(result_list.begin(), result_list.end());

  return 0;
}