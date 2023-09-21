# 7569 토마토
"""
해당 문제는 3차원 배열을 이용한 dfs 문제이다
3차원 배열 시 index에 주의하자
x축, y축, z축 순서로 생각하면 인덱스 에러를 마주한다
z, x, y순서에 유의해서 반복문에 적절한 범위를 주어야 한다
input() 대신 readline()을 사용하여 런타임 에러를 방지하자
본 문제에서는 input() 사용해도 에러는 나지 않았다
"""
from collections import deque
import sys

def bfs(graph):
  queue = deque()
  
  for i in range(h):
    for j in range(n):
      for k in range(m):
        if graph[i][j][k] == 1:
          queue.append((i, j, k))
          
  while queue:
    z, x, y = queue.popleft()

    for i in range(6):
      nx = x + dx[i]
      ny = y + dy[i]
      nz = z + dz[i]
    
      if nx< 0 or ny < 0 or nz <0 or nx>=n or ny>=m or nz>=h:
        continue
      
      if graph[nz][nx][ny] == 0:   # 주변 토마토 익지 않은 상태
        graph[nz][nx][ny] = graph[z][x][y] + 1      # 익은 상태로 변경  
        queue.append((nz, nx, ny))      # 다음에 방문헤야하므로 queue에 추가
        
def result():
  max = 0
  for i in range(h):
    for j in range(n):
      for k in range(m):
        if graph[i][j][k] == 0:   # 하나라도 익지 않았을 경우
          return -1
        elif (graph[i][j][k]-1) >= max:
          max = graph[i][j][k]-1
          
  return max

if __name__ == "__main__":

  dx = [0, 0, -1, 1, 0, 0]
  dy = [0, 0, 0, 0, -1, 1] 
  dz = [1, -1, 0, 0, 0, 0]
  
  m, n, h = map(int, input().split())
  graph = [[list(map(int, sys.stdin.readline().split())) for _ in range(n)] for _ in range(h)]   # 3차원 배열 생성
                  
  bfs(graph)
  print(result())