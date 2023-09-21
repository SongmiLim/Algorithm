# 7576 토마토
from collections import deque

def bfs(graph):
  queue = deque()
  
  for x in range(n):
    for y in range(m):
      if graph[x][y] == 1:
        queue.append((x, y))
  
  while queue:
    x, y = queue.popleft()
    
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx<0 or nx>=n or ny<0 or ny>=m:
        continue
        
      if graph[nx][ny] == 0 and graph[nx][ny] != -1:
        graph[nx][ny] = graph[x][y] + 1
        queue.append((nx, ny))  


def result():
  max = 0
  for x in range(n):
    for y in range(m):
      if graph[x][y] == 0:
        return -1
      elif (graph[x][y] -1) > max:
        max = (graph[x][y] -1)
  return max
        
if __name__ == "__main__":
  dx = [0, 0, -1, 1]
  dy = [1, -1, 0, 0]
  
  m, n = map(int, input().split())
  graph = [list(map(int, input().split())) for _ in range(n)]

  bfs(graph)
  print(result())