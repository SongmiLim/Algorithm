#include <iostream>
#include <queue>
#include <string.h>
#define MAX 100001

int N, K;
int visited[MAX*2];
int dx[] = { 1, -1, 2 };

void bfs(int n) {
  std::queue <int> q;
  q.push(n);

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (x == K) 
      return;

    for (int i : {x-1, x+1, 2*x}) {
      int nx = i;

      if (nx >= MAX || nx < 0)
        continue;

      if (visited[nx] == 0) {
        q.push(nx);
        visited[nx] = visited[x] + 1;
      }
    }
  }
}

int main() {
  std::cin >> N >> K;
  memset(visited, 0, sizeof(visited));

  bfs(N);

  std::cout << visited[K];

  return 0;
}