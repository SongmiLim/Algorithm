# 1697 숨바꼭질
from collections import deque
MAX_COUNT = 1000000

def bfs(m, s):
  queue = deque()
  queue.append(m)

  while queue:
    x = queue.popleft()
    
    if x == s:
      return visited[x]
    
    for nx in (x-1, x+1, x*2):
      if nx<0 or nx>=MAX_COUNT:
        continue
        
      if visited[nx] == 0:
        queue.append(nx)
        visited[nx] = visited[x] + 1

if __name__ == "__main__":
  n, k = map(int, input().split())
  visited = [0] * MAX_COUNT
  print(bfs(n, k))
  
  