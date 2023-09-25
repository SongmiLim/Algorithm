# 2206 벽 부수고 이동하기
from collections import deque

def bfs():
  queue = deque()
  queue.append((0, 0, 0))
  visited[0][0][0] = 1
  
  while queue:
    check_break_wall, x, y = queue.popleft()
    
    if x == n-1 and y == m-1:
      return (visited[check_break_wall][x][y])

      
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if nx<0 or ny<0 or nx>=n or ny>=m:
        continue
        
      if visited[check_break_wall][nx][ny] == 0:
        if graph[nx][ny] == 0:
          visited[check_break_wall][nx][ny] = visited[check_break_wall][x][y] + 1
          queue.append((check_break_wall, nx, ny))
        
        if graph[nx][ny] == 1 and check_break_wall == 0:
          queue.append((1, nx, ny))
          visited[1][nx][ny] = visited[check_break_wall][x][y] + 1
  return -1


if __name__ == "__main__":
  dx = [0, 0, -1, 1]
  dy = [1, -1, 0, 0]
  
  n, m = map(int, input().split())
  graph = [list(map(int, input())) for _ in range(n)]
  visited = [[[0]*m for _ in range(n)] for _ in range(2)]
  
  print(bfs())