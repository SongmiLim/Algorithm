# 2573 빙산
from collections import deque

def melt_graph(x, y):
  visited = [[0 for _ in range(m)]for _ in range(n)]
  queue = deque()
  queue.append((x, y))
  
  while queue:
    x, y = queue.popleft()
    count = 0
    
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if nx<0 or ny<0 or nx>=n or ny>=m:
        continue
      
      if graph[nx][ny] == 0:
        count +=1
      if graph[nx][ny] > 0 and visited[nx][ny] == 0:
        visited[nx][ny] = 1 # 방문 표시
        queue.append((nx, ny))
        
    melt[x][y] = graph[x][y] - count
    if melt[x][y]<0:
      melt[x][y] = 0
  print(melt)
  check_divide_cluster(melt_graph)
        
def check_divide_cluster(visited): 
  global cluster
  cluster += 1
  
  for i in range(n):
    for j in range(m):
      if visited[i][j] != 0:
        melt_graph(i, j)






if __name__ == "__main__":
  n, m = map(int, input().split())
  graph = [list(map(int, input().split())) for _ in range(n)]
  melt = [[0 for _ in range(m)]for _ in range(n)]
  
  dx = [0, 0, -1, 1]
  dy = [1, -1, 0, 0]
  cluster = 0

  
  for i in range(n):
    for j in range(m):
      if graph[i][j] != 0:
        melt_graph(i, j)
        break
  print(cluster)
  