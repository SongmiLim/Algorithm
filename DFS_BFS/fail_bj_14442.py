# 14442 벽 부수고 이동하기 2
"""
왜 계속 k값을 +1 헤줘야 올바른 결과가 나왔는지는...
예외처리 때문이였다... 하
crush>=k 일 때 continue해줘서 계속 잘못된 결과가 나옴....
!!!! 제출 시 시간 초과 발생
아무래도 k가 인덱스 앞쪽에 위치해서 초기화할 때 시간 초과 발생하는 듯 하다

"""
from collections import deque
import sys

def bfs():
  queue = deque()
  queue.append((0, 0, 0))
  visited[0][0][0] = 1
  
  while queue:
    crush, x, y = queue.popleft()
    
    if x == n-1 and y == m-1:
      return visited[crush][x][y]
      
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if nx<0 or ny<0 or nx>=n or ny>=m or crush >=k :
        continue
      
      if visited[crush][nx][ny]==0 and graph[nx][ny] == 0:
        queue.append((crush, nx, ny))
        visited[crush][nx][ny] = visited[crush][x][y] + 1
        
      if visited[crush+1][nx][ny]==0 and graph[nx][ny] == 1 and crush<k:
        queue.append((crush+1, nx, ny))
        visited[crush+1][nx][ny] = visited[crush][x][y] + 1

  return -1
        

if __name__ == "__main__":
  dx = [0, 0, -1, 1]
  dy = [1, -1, 0, 0]
  
  n, m, k = map(int, sys.stdin.readline().split())
  graph = [list(map(int, sys.stdin.readline().strip())) for _ in range(n)]
  visited = [[[0]*m for _ in range(n)] for _ in range(k+1)]
  
  print(bfs())