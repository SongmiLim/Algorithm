# 2468 안전 영역
"""
비가 오지 않을 때의 예외처리를 해줘야한다..
문제가 애매한듯 하다
"""
from collections import deque

def bfs(x, y):
  queue = deque()
  queue.append((x, y))
  visited[x][y] = 1
  
  while queue:
    x, y = queue.popleft()
    
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if nx<0 or ny<0 or nx>=n or ny>=n:
        continue
        
      if visited[nx][ny] == 0:
        queue.append((nx, ny))    
        visited[nx][ny] = 1


if __name__ == "__main__":
  n = int(input())
  graph = [list(map(int, input().split())) for _ in range(n) ]
  result = []
  dx = [0, 0, -1, 1]
  dy = [1, -1, 0, 0]

  height = 1
  while height<=100:
    if height == 1: # 비가 내리지 않았을 때
      result.append(1)
      
    visited = [[0 for _ in range(n)] for _  in range(n)]
    count = 0
    
    for i in range(n):
      for j in range(n):
        if graph[i][j] <= height:
          visited[i][j] = -1  # 물에 잠긴 지역

    # bfs 순회
    for i in range(n):
      for j in range(n):
        if visited[i][j] == 0:
          bfs(i, j)
          count += 1
    result.append(count)
    height+=1    
  
  print(max(result))