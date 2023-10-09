# 9205 맥주 마시면서 걸어가기
from collections import deque

def drink_beer(graph):
    visited = [0 for _ in range(n+2)]
    
    queue = deque()
    queue.append(0)
    visited[0] = 1
  
    while queue:
      x = queue.popleft()
      
      if x == n+1:
        print("happy")
        return
        
      for nx in range(1, n+2):
        length = abs(graph[nx][0] - graph[x][0]) + abs(graph[nx][1] - graph[x][1])
        
        if length <= limit and visited[nx] == 0:
          visited[nx] = 1
          queue.append(nx)
    print("sad")

if __name__ == "__main__":
  t = int(input())
  limit = 20 * 50
  
  for _ in range(t):
    n = int(input())
    graph = [list(map(int, input().split())) for _ in range(n+2)]
  
    drink_beer(graph)

  