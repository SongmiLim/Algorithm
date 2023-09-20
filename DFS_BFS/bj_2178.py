# 2178 미로탐색
from collections import deque

def bfs(graph, x, y):
  queue = deque()
  queue.append((x, y))
  
  while queue:
    x, y = queue.popleft()
  
    for i in range(4):     # 상하좌우 살펴본다
      nx = x + dx[i]
      ny = y + dy[i]
      if nx<0 or nx>=n or ny<0 or ny>=m:   # 그래프 범위를 벗어나면 건너뜀
        continue
      if graph[nx][ny] == 1: # 상하좌우 중 인접한 칸(1) 있으면
        graph[nx][ny] = graph[x][y]+1    # 이동 count ++
        queue.append((nx, ny)) # 다음 방문해야 할 칸 append
        
if __name__ == "__main__":
  dx = [0, 0, 1, -1]
  dy = [1, -1, 0, 0]
  
  n, m = map(int, input().split())
  graph = [list(map(int, input())) for _ in range(n)]
  bfs(graph, 0, 0)
  print(graph[n-1][m-1])
  