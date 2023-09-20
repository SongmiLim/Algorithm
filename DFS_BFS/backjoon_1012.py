# 1012 유기농 배추
from collections import deque

def bfs(graph, x, y):
  queue = deque()
  queue.append((x, y))
  graph[x][y] = 2   # visited 상태(2)로 만든다
  
  while queue:
    x,y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      # 범위를 벗어날 경우 continue
      if nx>=M or nx<0 or ny>=N or ny<0:  
        continue
      
      if graph[nx][ny] == 1: # 배추가 심어져 있을 경우(1)
        queue.append((nx, ny))  # 다음 방문해야 할 위치로 추가 
        graph[nx][ny] = 2   # visited 상태(2)로 만든다

if __name__ == "__main__":
  dx = [0, 0, -1, 1]
  dy = [1, -1, 0, 0]
  count_list = []

  T = int(input())
  
  for _ in range(T):
    M, N, K = map(int, input().split())
    graph = [[0 for _ in range(N+1)] for _ in range(M+1)]  

    for _ in range(K):
      count = 0
      x, y = map(int, input().split())
      graph[x][y] = 1
    
    for i in range(M):
      for j in range(N):
        if graph[i][j] == 1:
          bfs(graph, i, j) # 인접한 배추 있는지 찾기
          count += 1       # 지렁이 수 추가
    count_list.append(count)
  
  for i in count_list:
    print(i)