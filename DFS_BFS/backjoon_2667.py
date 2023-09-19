### 2667 단지 번호 붙이기
from collections import deque

def bfs(graph, x, y):
  queue = deque()
  queue.append((x, y))
  graph[x][y] = 0    # 방문한 집은 visited(0)으로 set 
  count = 1
  
  while queue:
    x, y = queue.popleft()
  
    for i in range(4):     # 상하좌우 살펴본다
      nx = x + dx[i]
      ny = y + dy[i]
      if nx<0 or nx>=n or ny<0 or ny>=n:   # 그래프 범위를 벗어나면 건너뜀
        continue
      if graph[nx][ny] == 1: # 상하좌우 중 인접한 집(1) 있으면
        graph[nx][ny] = 0    # visited(0)으로 set
        queue.append((nx, ny)) # 다음 방문해야 할 집이므로 queue에 넣어줌
        count+=1   # 집의 개수 ++
  count_list.append(count)

if __name__ == "__main__":
  n = int(input())
  
  dx = [0, 0, 1, -1]
  dy = [1, -1, 0, 0]
  count_list = []
  graph = [list(map(int, input())) for _ in range (n)]

  for i in range(n):
    for j in range(n):
      if graph[i][j] == 1:
        bfs(graph, i, j)
  
  count_list.sort()
  print(len(count_list))
  for i in count_list:
    print(i)
          